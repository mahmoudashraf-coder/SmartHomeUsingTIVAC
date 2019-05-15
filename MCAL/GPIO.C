#include "tm4c123gh6pm.h"
#include "GPIO.h"
void port_lock(char port)
{
	switch (port)
		{
			case 'A':
				GPIO_PORTA_LOCK_R  = GPIO_LOCK_KEY;
			case 'B':
				GPIO_PORTB_LOCK_R  = GPIO_LOCK_KEY;
			case 'C':
				GPIO_PORTC_LOCK_R  = GPIO_LOCK_KEY;
			case 'D':
				GPIO_PORTD_LOCK_R  = GPIO_LOCK_KEY;
			case 'E':
				GPIO_PORTE_LOCK_R  = GPIO_LOCK_KEY;
			case 'F':
			GPIO_PORTF_LOCK_R  = GPIO_LOCK_KEY;
		}
}
void port_init (char port)
{		
	SYSCTL_RCGCGPIO_R |=1<<(port - 65); 		//enable clock for port
	while ((SYSCTL_PRGPIO_R&(1<<(port - 65)))== 0);
}
void pin_mode (char port,uint8_t pin ,enum mode dirr,enum input_mode denr, enum set_mode afsel_mode)
{		
	
	volatile unsigned long * portDEN;
	volatile unsigned long * portAFSEL;
	volatile unsigned long * portDIR;
	volatile unsigned long * portCR;
	switch (port)
	{
		case 'A':
			portDIR = &GPIO_PORTA_DIR_R;
			portDEN = &GPIO_PORTA_DEN_R;
			portAFSEL = &GPIO_PORTA_AFSEL_R;
		  portCR = &GPIO_PORTA_CR_R;
		break;
		case 'B':
			portDIR = &GPIO_PORTB_DIR_R;
			portDEN = &GPIO_PORTB_DEN_R;
			portAFSEL = &GPIO_PORTB_AFSEL_R;
		  portCR = &GPIO_PORTB_CR_R;
			break;
		case 'C':
			portDIR = &GPIO_PORTC_DIR_R;
			portDEN = &GPIO_PORTC_DEN_R;
			portAFSEL = &GPIO_PORTC_AFSEL_R;
		  portCR = &GPIO_PORTC_CR_R;
			break;
		case 'D':
			portDIR = &GPIO_PORTD_DIR_R;
			portDEN = &GPIO_PORTD_DEN_R;
			portAFSEL = &GPIO_PORTD_AFSEL_R;
		  portCR = &GPIO_PORTD_CR_R;
			break;
		case 'E':
			portDIR = &GPIO_PORTE_DIR_R;
			portDEN = &GPIO_PORTE_DEN_R;
			portAFSEL = &GPIO_PORTE_AFSEL_R;
		  portCR = &GPIO_PORTE_CR_R;
			break;
		case 'F':
			portDIR = &GPIO_PORTF_DIR_R;
			portDEN = &GPIO_PORTF_DEN_R;
			portAFSEL = &GPIO_PORTF_AFSEL_R; 
		  portCR = &GPIO_PORTF_CR_R;
			break;
	}
//	port_init(port);
	*portCR |= 0x01<<(pin);
	if (dirr == INPUT) *portDIR  &= ~(0x01<<(pin));
	else if (dirr  == OUTPUT) *portDIR  |= (0x01<<(pin));
	if (denr == ANALOG) *portDEN &= ~(0x01<<(pin));
	else if (denr == DIGITAL) *portDEN |=  (0x01<<(pin));
	if (afsel_mode == SET) *portAFSEL |= (0x01<<(pin));
	else if (afsel_mode == UNSET) *portAFSEL &= ~(0x01<<(pin));
}
volatile unsigned long * getGPIOData(char port)
{
	volatile unsigned long * portGPIO;
	switch (port)
	{
		case 'A':
			portGPIO = &GPIO_PORTA_DATA_R;
		break;
		case 'B':
			portGPIO = &GPIO_PORTB_DATA_R;
			break;
		case 'C':
			portGPIO = &GPIO_PORTC_DATA_R;
			break;
		case 'D':
			portGPIO = &GPIO_PORTD_DATA_R;
			break;
		case 'E':
			portGPIO = &GPIO_PORTE_DATA_R;   
			break;
		case 'F':
			portGPIO = &GPIO_PORTF_DATA_R;   
			break;
	}
	
	return portGPIO;
}
void write_pin(char port ,uint8_t pin,uint8_t state)
{
	volatile unsigned long * portGPIO = getGPIOData(port);
	if (state==1)
		*portGPIO |=(1<<pin);
	else if (state==0)
		*portGPIO &=~(1<<pin);
}
void write_data(char port, uint8_t data)
{
	volatile unsigned long * portGPIO = getGPIOData(port);
	*portGPIO = data;
}
uint8_t read_data(char port)
{
	volatile unsigned long * portGPIO = getGPIOData(port);
	return *portGPIO;
}
uint8_t read_pin(char port,uint8_t pin)
{
	volatile unsigned long * portGPIO = getGPIOData(port);
	return (*portGPIO &(1 <<pin))>>pin;
}
