#include "MCAL/GPIO.h"
#include "MCAL/UART.h"
#include "MCAL/ADC.h"
#include "MCAL/pwm.h"
#include "HAL/BlueLED.h"
#include "HAL/Motor.h"

uint8_t uart;
long ADC_Reading;
long temperature;
int main()
{
	ADC_Reading = 0;
	temperature = 0;
	port_init('D');
	pin_mode('D',0, OUTPUT, DIGITAL, AFSEL_R_NONE);
	pin_mode('D',1, OUTPUT, DIGITAL, AFSEL_R_NONE);
	pin_mode('D',2, OUTPUT, DIGITAL, AFSEL_R_NONE);
	pin_mode('D',3, OUTPUT, DIGITAL, AFSEL_R_NONE);
	UART5_Init();
	ADC_Init();
	BlueLED_Init();
	while (1)
	{
		if (getADC(&ADC_Reading))
		{
			if (temperature - (147 - (247 * ADC_Reading) / 4096) != 0	)
			{
					temperature = 147 - (247 * ADC_Reading) / 4096;
					UART5_Write(temperature);
			}
		}
		if (UART5_Available() == 1)
		{
			uart = UART5_Read();
			switch (uart)
			{
				
			case 0:
				for (int i = 0; i < 45; i++)
				{
					Motor_Turn(0);
				}
				if (UART5_Available() == 1)uart = UART5_Read();
				break;
			case 1:
				for (int i = 0; i < 45; i++)
				{
					Motor_Turn(1);
				}
				if (UART5_Available() == 1)uart = UART5_Read();
				break;
			default:
				BlueLED_SetDutyCycle((uart-2)*100/205);
				break;
			}
		}
	}
}
