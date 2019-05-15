#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "MCAL/GPIO.h"
#include "MCAL/TIMER.h"
#include "HAL/LCD.h"
#include "MCAL/UART.h"
#include "MCAL/ADC.h"
#include "HAL/TIVA2.h"

#define ADC_SENSE 2

void SystemInit()
{
	UART5_Init();
	ADC_Init();
	PushButtonsInit();
}

int  main(void)
{
	
	
	uint8_t poten_last_data = 0;
	uint8_t uart=48;
	uint8_t poten_data = 0 ;
	uint16_t adcval=0;
	lcd_init();
	
	lcd_string("  LAUNCHPAD 2 ");
	delay_MS(1000);
				lcd_clear();
	lcd_string("  WAITING... ");
	/*
	Launchpad 2 will be connected to two push buttons (one for rotating the motor shaft 30 degrees
clockwise and one for rotating it 30 degrees counter clockwise) and both buttons should take
actions on press only, LCD to show reading of temperature sensor on Launchpad 1, Potentiometer
to control the LED intensity on Launchpad 1.
	*/
	while(1)
		{	
			
			//UART READ LOGIC
			if(UART5_Available() == 1)
			{
				uart = UART5_Read();
				if (uart > 0)
				{
				lcd_clear(); lcd_integer(uart);
				lcd_string(" degrees");
				}
			}
				//UART WRITE LOGIC
				if(PushButton1Pressed()) UART5_Write(0);
				else if(PushButton2Pressed()) UART5_Write(1);
				getADC(&adcval);
				poten_data = (adcval/20)+2;
				if( (poten_data > (poten_last_data+ADC_SENSE) || poten_data < (poten_last_data-ADC_SENSE)  )  )
				{
					poten_last_data = poten_data;
					UART5_Write(poten_data);
						
				}
				
	

			
			
		}

}
