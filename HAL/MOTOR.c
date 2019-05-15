#include "MOTOR.h"
#include "..\MCAL\TIMER.h"
#include "..\MCAL\GPIO.h"
void Motor_Turn(char direction)
{
	if (direction == 0)
	{
		write_data('D', 10);
		delay_MS(MOTOR_DELAY);
		write_data('D', 6);
		delay_MS(MOTOR_DELAY);
		write_data('D', 5);
		delay_MS(MOTOR_DELAY);
		write_data('D', 9);
		delay_MS(MOTOR_DELAY);
	}
	else
	{
		
		write_data('D', 9);
		delay_MS(MOTOR_DELAY);
		write_data('D', 5);
		delay_MS(MOTOR_DELAY);
		write_data('D', 6);
		delay_MS(MOTOR_DELAY);
		write_data('D', 10);
		delay_MS(MOTOR_DELAY);
	}
}