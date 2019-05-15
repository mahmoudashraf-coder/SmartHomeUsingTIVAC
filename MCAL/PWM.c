#include "..\tm4c123gh6pm.h"
#include "TIMER.h"
void PWM_Set(long data)
{
	PWM1_3_CMPA_R = data;
}
void PWM_Init(long PWMENABLE){
	SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R1;
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
	delay_MS(100);
	SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
	SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_64; // PWM Clock = 1.25 MHz
	PWM1_3_CTL_R = 0x00000000;
	PWM1_3_GENA_R = 0x0000008C; // Drive PWM High at reload value and drive it to zero when it matches CMP
	PWM1_3_LOAD_R = 1250 - 1; // 1KHz
	PWM1_3_CTL_R = PWM_0_CTL_ENABLE;
	PWM1_ENABLE_R = PWMENABLE; // M1PWM6 (PF2)
	PWM_Set(1248); // 0% Duty Cycle
}
