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