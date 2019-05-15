#include "tm4c123gh6pm.h"
#include "PWM.h"
#include "GPIO.h"
void BlueLED_Init(void){
	PWM_Init(PWM_ENABLE_PWM6EN);
	pin_mode('F', 2, OUTPUT, DIGITAL, SET);
	GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0xFFFFFF0F) | (GPIO_PCTL_PF2_M1PWM6);
}
void BlueLED_SetDutyCycle(uint8_t duty_cycle){
	if(duty_cycle == 100){
		PWM_Set(1);
	} else if(duty_cycle == 0) {
		PWM_Set(1248);
	}else {
		PWM_Set((int)(1250 * (1 - (duty_cycle / 100.0)) - 1));
	}
}

