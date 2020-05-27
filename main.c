/*
* main.c
*/
#include <math.h>
#include "I2C.h"
#include "UART.h"
#include "Timers.h"
#include "Lights.h"
#include "LCD.H"
//Touch Screen Parameters
unsigned char *PA = (unsigned char *) 0x40004000;
unsigned char *PB = (unsigned char *) 0x40005000;
unsigned char *SYSCTL = (unsigned char *) 0x400FE000;
unsigned char *SSI0 = (unsigned char *) 0x40008000;
volatile unsigned int SSI0_SR __attribute__((at(0x4000800C)));
//Si7021 Temp. & Hum. Variables
uint16_t temperature = 0;
uint16_t humidity = 0;
const int i2c_slave = 0x40;
//Smoke Detector Variables
float Rs = 0;
bool smoke_alarm = false;
//Lighting Variables
bool motion_detect = true;
bool room1 = false;
bool room2 = false;
bool room3 = false;
bool room4 = false;
bool room5 = false;
//UART Variables
char uartRx_data[6];
char uartTx_data[10];
int counter = 0;
float readSmokeDetector(){
ADC0_PSSI_R = 1; //Initiate a sample conversion on ADC0
while(ADC0_ACTSS_R & ADC_ACTSS_BUSY){}
return ADC0_SSFIFO0_R;
}
float getReads(int samples){
int i;
float tmp, tmp2;
for(i = 0; i < samples; i++){
tmp2 = readSmokeDetector();
// tmp += (float)((float)(5 * (1023 - tmp2)) / (float)tmp2);
 tmp += ((tmp2/1023)*5);
}
tmp = tmp / samples;
// tmp = tmp / (float)9.83;
return tmp;
}
float calibrateSmokeDetector(){
return getReads(50);
}
void initialize(){
 //Use PLL and set SYSCLK to 80MHz
SYSCTL_RCC_R = 0x00001540;
SYSCTL_RCC2_R = 0xC1004000;
//Initialize system controls (Ports, Timers, etc.)
initialize_I2C();
initialize_SPI();
 initialize_UART3();
 initialize_Timers();
 initialize_Lights();
GPIO_PORTA_DATA_R |= 0x80;
 LCD_Init();
 //Aquire initial values from sensors
 temperature = get_Temperature(i2c_slave);
 humidity = get_Humidity(i2c_slave);
}
void updateLCD(void){
//Update Temperature and Humidity
int temp_High;
int temp_Low;
int humid_High;
int humid_Low;
temp_High = temperature / 10;
temp_Low = temperature % 10;
setArea(0, 15, 208, 223, white, temp_High);
setArea(0, 15, 224, 239, white, temp_Low);
humid_High = humidity / 10;
humid_Low = humidity % 10;
setArea(16, 31, 208, 223, white, humid_High);
setArea(16, 31, 224, 239, white, humid_Low);
//Update Smoke Status
if(smoke_alarm){
setArea(32, 47, 224, 239, red, 1);
//Spell Warning
setArea(192, 207, 64, 79, red, 39);
setArea(192, 207, 80, 95, red, 17);
setArea(192, 207, 96, 111, red, 34);
setArea(192, 207, 112, 127, red, 30);
setArea(192, 207, 128, 143, red, 25);
setArea(192, 207, 144, 159, red, 30);
setArea(192, 207, 160, 175, red, 23);
//Spell Smoke
setArea(208, 223, 80, 95, red, 35);
setArea(208, 223, 96, 111, red, 29);
setArea(208, 223, 112, 127, red, 31);
setArea(208, 223, 128, 143, red, 27);
setArea(208, 223, 144, 159, red, 21);
}
else {
setArea(32, 47, 224, 239, white, 0);
//Spell Warning
setArea(192, 207, 64, 79, black, 39);
setArea(192, 207, 80, 95, black, 17);
setArea(192, 207, 96, 111, black, 34);
setArea(192, 207, 112, 127, black, 30);
setArea(192, 207, 128, 143, black, 25);
setArea(192, 207, 144, 159, black, 30);
setArea(192, 207, 160, 175, black, 23);
//Spell Smoke
setArea(208, 223, 80, 95, black, 35);
setArea(208, 223, 96, 111, black, 29);
setArea(208, 223, 112, 127, black, 31);
setArea(208, 223, 128, 143, black, 27);
setArea(208, 223, 144, 159, black, 21);
}
//Update Motion sensor and LEDs
if(uartRx_data[0]) setArea(64, 79, 224, 239, white, 1);
else setArea(64, 79, 224, 239, white, 0);
//Room 1
if(GPIO_PORTB_DATA_R & 0x2){
setArea(80, 95, 224, 239, white, 0);
room1 = false;
}
else{
setArea(80, 95, 224, 239, white, 1);
room1 = true;
}
//Room 2
if(GPIO_PORTB_DATA_R & 0x4){
setArea(96, 111, 224, 239, white, 0);
room2 = false;
}
else {
setArea(96, 111, 224, 239, white, 1);
room2 = true;
}
//Room 3
if(GPIO_PORTB_DATA_R & 0x8) {
setArea(112, 127, 224, 239, white, 0);
room3 = false;
}
else {
setArea(112, 127, 224, 239, white, 1);
room3 = true;
}
//Room 4
if(GPIO_PORTB_DATA_R & 0x10) {
setArea(128, 143, 224, 239, white, 0);
room4 = false;
}
else {
setArea(128, 143, 224, 239, white, 1);
room4 = true;
}
//Room 5
if(GPIO_PORTB_DATA_R & 0x20) {
setArea(144, 159, 224, 239, white, 0);
room5 = false;
}
else {
setArea(144, 159, 224, 239, white, 1);
room5 = true;
}
}
void UART3_Handler(){
 while(!(UART3_FR_R & UART_FR_RXFE) && counter < 6)
{
uartRx_data[counter] = UART3_DR_R;
while((UART3_FR_R & UART_FR_BUSY)){}
counter++;
}
update_Lights(uartRx_data);
temperature = get_Temperature(i2c_slave);
 humidity = get_Humidity(i2c_slave);
 Rs = getReads(10);

 if(Rs > 13)
 smoke_alarm = true;
 else
 smoke_alarm = false;
updateLCD();

 UART3_DR_R = (temperature & 0xFF);
 UART3_DR_R = (humidity & 0xFF);
 UART3_DR_R = smoke_alarm;

 counter = 0;
UART3_ICR_R |= 0x10;
}
int main(void){
int i;
 initialize();
flash_screen(black);
LCDDisplay();
for(i = 0; i < 1000; i++){}
 while(1){
}
}
