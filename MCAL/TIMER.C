#include "tm4c123gh6pm.h"
void SysTick_Init(void){
	NVIC_ST_CTRL_R = 0; // 1) disable SysTick during setup
	NVIC_ST_RELOAD_R = 0x00FFFFFF; // 2) maximum reload value
	NVIC_ST_CURRENT_R = 0; // 3) any write to current clears it
	NVIC_ST_CTRL_R = 0x00000005; // 4) enable SysTick with core clock
}
void delay_MS(unsigned long delay){
	int i;
	SysTick_Init();	// delay is in 12.5ns units
	for (i=0;i<delay;i++){
		NVIC_ST_RELOAD_R = (80*1000)-1; // number of counts to wait
		NVIC_ST_CURRENT_R = 0; // any value written to CURRENT clears
		while((NVIC_ST_CTRL_R&0x00010000)==0){ // wait for count flag
		}
	}
}
void delay_US(unsigned long delay){
SysTick_Init();	// delay is in 12.5ns units
NVIC_ST_RELOAD_R = (80*delay)-1; // number of counts to wait
NVIC_ST_CURRENT_R = 0; // any value written to CURRENT clears
while((NVIC_ST_CTRL_R&0x00010000)==0){ // wait for count flag
}
}
