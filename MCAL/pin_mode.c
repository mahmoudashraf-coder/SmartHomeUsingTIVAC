void pin_mode (char port,uint8 pin ,enum mode mod,enum input_mode modd) //not complete missing analog read and analog write
	{			switch (port)
		{		case 'A':
			
					port_init('A');
					GPIO_PORTA_CR_R |=0x01<<(pin);
					switch (mod )
							{
								case INPUT:
										GPIO_PORTA_DIR_R  &= ~(0x01<<(pin));
										if (modd==ANALOG)
										{GPIO_PORTA_DEN_R &= ~(0x01<<(pin));}
											
										else if (modd==DIGITAL)
										{GPIO_PORTA_DEN_R |=0x01<<(pin);
										GPIO_PORTA_PUR_R |= 0x01<<(pin);}			//DEFAULT is pull ups
										
											break;
					
					
				
				
								case OUTPUT:
										GPIO_PORTA_DIR_R  |= (0x01<<(pin));
										
										if (modd==ANALOG)
										{GPIO_PORTA_DEN_R &= ~(0x01<<(pin));}
											
										else if (modd==DIGITAL)
										{GPIO_PORTA_DEN_R |=0x01<<(pin);}
										break;
				
								}
		
		
		
				
				
			
				break;
				
				case 'B':
				port_init('B');
				GPIO_PORTB_CR_R |=0x01<<(pin);
					switch (mod )
							{
								case INPUT:
										GPIO_PORTB_DIR_R  &= ~(0x01<<(pin));
										if (modd==ANALOG)
										{GPIO_PORTB_DEN_R &= ~(0x01<<(pin));}
											
										else if (modd  == DIGITAL)
										{GPIO_PORTB_DEN_R |=0x01<<(pin);
										GPIO_PORTB_PUR_R |= 0x01<<(pin);}
										
											break;
					
					
				
				
								case OUTPUT:
										GPIO_PORTB_DIR_R  |= (0x01<<(pin));
										
										if (modd==ANALOG)
										{GPIO_PORTB_DEN_R &= ~(0x01<<(pin));}
											
										else if (modd==DIGITAL)
										{GPIO_PORTB_DEN_R |=0x01<<(pin);}
										break;
				
								}
				
				break;
				case 'C':
					port_init('C');
				GPIO_PORTC_CR_R |=0x01<<(pin);
					switch (mod )
							{
								case INPUT:
										GPIO_PORTC_DIR_R  &= ~(0x01<<(pin));
										if (modd==ANALOG)
										{GPIO_PORTC_DEN_R &= ~(0x01<<(pin));}
											
										else if (modd==DIGITAL)
										{GPIO_PORTC_DEN_R |=0x01<<(pin);
										GPIO_PORTC_PUR_R |= 0x01<<(pin);}
										
											break;
					
					
				
				
								case OUTPUT:
										GPIO_PORTC_DIR_R  |= (0x01<<(pin));
										
										if (modd==ANALOG)
										{GPIO_PORTC_DEN_R &= ~(0x01<<(pin));}
											
										else if (modd==DIGITAL)
										{GPIO_PORTC_DEN_R |=0x01<<(pin);}
										break;
				
								}
				
				
				break;
				case 'D':
					port_init('D');
				GPIO_PORTD_CR_R |=0x01<<(pin);
					switch (mod )
							{
								case INPUT:
										GPIO_PORTD_DIR_R  &= ~(0x01<<(pin));
										if (modd==ANALOG)
										{GPIO_PORTD_DEN_R &= ~(0x01<<(pin));}
											
										else if (modd==DIGITAL)
										{GPIO_PORTD_DEN_R |=0x01<<(pin);
										GPIO_PORTD_PUR_R |= 0x01<<(pin);}
										
											break;
					
					
				
				
								case OUTPUT:
										GPIO_PORTD_DIR_R  |= (0x01<<(pin));
										
										if (modd==ANALOG)
										{GPIO_PORTD_DEN_R &= ~(0x01<<(pin));}
											
										else if (modd==DIGITAL)
										{GPIO_PORTD_DEN_R |=0x01<<(pin);}
										break;
				
								}
					
				break;
				case 'E':
					port_init('E');
				GPIO_PORTE_CR_R |=0x01<<(pin);
					switch (mod )
							{
								case INPUT:
										GPIO_PORTE_DIR_R  &= ~(0x01<<(pin));
										if (modd==ANALOG)
										{GPIO_PORTE_DEN_R &= ~(0x01<<(pin));}
											
										else if (modd==DIGITAL)
										{GPIO_PORTE_DEN_R |=0x01<<(pin);
										GPIO_PORTE_PUR_R |= 0x01<<(pin);}
										
											break;
					
					
				
				
								case OUTPUT:
										GPIO_PORTE_DIR_R  |= (0x01<<(pin));
										
										if (modd==ANALOG)
										{GPIO_PORTE_DEN_R &= ~(0x01<<(pin));}
											
										else if (modd==DIGITAL)
										{GPIO_PORTE_DEN_R |=0x01<<(pin);}
										break;
				
								}
					
					break;
					
				case 'F':
					port_init('F');
				GPIO_PORTF_CR_R |=0x01<<(pin);
					switch (mod )
							{
								case INPUT:
										GPIO_PORTF_DIR_R  &= ~(0x01<<(pin));
										if (modd==ANALOG)
										{GPIO_PORTF_DEN_R &= ~(0x01<<(pin));}
											
										else if (modd==DIGITAL)
										{GPIO_PORTF_DEN_R |=0x01<<(pin);
										GPIO_PORTF_PUR_R |= 0x01<<(pin);}
										
											break;
					
					
				
				
								case OUTPUT:
										GPIO_PORTF_DIR_R  |= (0x01<<(pin));
										
										if (modd==ANALOG)
										{GPIO_PORTF_DEN_R &= ~(0x01<<(pin));}
											
										else if (modd==DIGITAL)
										{GPIO_PORTF_DEN_R |=0x01<<(pin);}
										break;
				
								}
					
				break;
		
	
	
		}



}
