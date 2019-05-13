void write_data(char port, uint8_t data)
{
	volatile unsigned long * portGPIO = getGPIOData(port);
	*portGPIO = data;
}