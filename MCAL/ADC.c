#include "..\tm4c123gh6pm.h"
#include "GPIO.h"
void WTIMER_Init(uint16_t trigger)
{
	WTIMER0_CTL_R = 0;           /* disable WTimer before initialization */
    WTIMER0_CFG_R = 0x04;        /* 32-bit option */
    WTIMER0_TAMR_R = 0x02;       /* periodic mode and down-counter */
    WTIMER0_TAILR_R = 16000000;  /* WTimer A interval load value reg (1 s) */
    WTIMER0_CTL_R |= trigger;       /* timer triggers ADC */
    WTIMER0_CTL_R |= 0x01;       /* enable WTimer A after initialization */
}
void ADC_Init(void)
{
	SYSCTL_RCGCADC_R |= 1;       /* enable clock to ADC0 */
    SYSCTL_RCGCWTIMER_R |= 1;    /* enable clock to WTimer Block 0 */
 /* initialize ADC0 */
    ADC0_ACTSS_R &= ~8;          /* disable SS3 during configuration */
    ADC0_EMUX_R &= ~0xF000;
    ADC0_EMUX_R |= 0x5000;       /* timer trigger conversion seq 0 */
    ADC0_SSMUX3_R = 0;           /* get input from channel 0 */
    ADC0_SSCTL3_R |= 0x0E;       /* take chip temperature, set flag at 1st sample */
    ADC0_ACTSS_R |= 8;           /* enable ADC0 sequencer 3 */
 
    /* initialize wtimer 0 to trigger ADC at 1 sample/sec */
    WTIMER_Init(0x20);
 
}
char ADCAvailable(void)
{
	return ((ADC0_RIS_R & 8) != 0);
}

char getADC(long  * variable)
{
	if (ADCAvailable()){
		*variable = ADC0_SSFIFO3_R;
		ADC0_ISC_R = 8;
		return 1;
	}
	return 0;
}
