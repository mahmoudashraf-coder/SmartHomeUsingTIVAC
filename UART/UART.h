#ifndef __ARMCORTEX_UART__
#define __ARMCORTEX_UART__
#include <stdint.h>

void UART5_Init(void);
uint8_t UART5_Available(void);
uint8_t UART5_Read(void);
void UART5_Write(uint8_t data);
void UART_Out(char*pt);
#endif
