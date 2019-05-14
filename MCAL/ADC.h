#ifndef __ARMCORTEX_ADC__
#define __ARMCORTEX_ADC__
#include <stdint.h>

void WTIMER_Init(uint16_t trigger);
void ADC_Init(void);
char ADCAvailable(void);
char getADC(long  * variable);

#endif
