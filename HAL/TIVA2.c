#include"GPIO.h"
uint8_t btn1waspst = 0;
uint8_t btn2waspst = 0;

void PushButtonsInit()
{
	pin_mode('F',0,INPUT,DIGITAL,AFSEL_R_NONE);
	pin_mode('F',4,INPUT,DIGITAL,AFSEL_R_NONE);
}

uint8_t PushButton1Pressed()
{
	
	if( read_pin('F',0) == 0) {
	if(btn1waspst == 0) {btn1waspst = 1;	return 1;}
	else {btn1waspst=1; return 0; }
	}
	btn1waspst=0;
	return 0;
}
uint8_t PushButton2Pressed()
{
	
	if( read_pin('F',4) == 0) {
	if(btn2waspst == 0) {btn2waspst = 1;	return 1;}
	else {btn2waspst=1; return 0; }
	}
	btn2waspst=0;
	return 0;
}
