void write_pin(char port ,uint8 pin,int state)
	{switch (port)
		{		case 'A':
					if (state==1)
						GPIO_PORTA_DATA_R|=(1<<pin);
		
					else if (state==0)
						GPIO_PORTA_DATA_R&=~(1<<pin);

			
					
				
			
				break;
				
				case 'B':
					if (state==1)
						GPIO_PORTB_DATA_R|=(1<<pin);
		
					else if (state==0)
						GPIO_PORTB_DATA_R&=~(1<<pin);
				
				
				break;
				case 'C':
					if (state==1)
						GPIO_PORTC_DATA_R|=(1<<pin);
		
					else if (state==0)
						GPIO_PORTC_DATA_R&=~(1<<pin);
					
				
				
				break;
				case 'D':
					if (state==1)
						GPIO_PORTD_DATA_R|=(1<<pin);
		
					else if (state==0)
						GPIO_PORTD_DATA_R&=~(1<<pin);
				
				
					
				break;
				case 'E':
					if (state==1)
						GPIO_PORTE_DATA_R|=(1<<pin);
		
					else if (state==0)
						GPIO_PORTE_DATA_R&=~(1<<pin);
				
				
					
					break;
					
				case 'F':
					if (state==1)
						GPIO_PORTF_DATA_R|=(1<<pin);
		
					else if (state==0)
						GPIO_PORTF_DATA_R&=~(1<<pin);
	
				
				break;
		
	
	
		}

		
		
		



}
