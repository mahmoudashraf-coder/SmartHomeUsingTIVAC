enum mode 
{INPUT=0 ,OUTPUT=1};
enum input_mode{ANALOG=0,DIGITAL=1,};
typedef unsigned char uint8;




void port_init (char port)
{			switch (port)
		{		case 'A':
			
					SYSCTL_RCGCGPIO_R |=1<<0; 		//enable clock for port A
					while ((SYSCTL_PRGPIO_R&(1<<0))==0);
					GPIO_PORTA_LOCK_R  = GPIO_LOCK_KEY;
				
				
			
				break;
				
				case 'B':
					SYSCTL_RCGCGPIO_R |=1<<1;
				while (SYSCTL_PRGPIO_R&(1<<1)==0);
				GPIO_PORTB_LOCK_R  = GPIO_LOCK_KEY;
				
				
				break;
				case 'C':
					SYSCTL_RCGCGPIO_R |=1<<2;
				while (SYSCTL_PRGPIO_R&(1<<2)==0);
				GPIO_PORTC_LOCK_R  = GPIO_LOCK_KEY;
				
				
				break;
				case 'D':
					SYSCTL_RCGCGPIO_R |=1<<3;
				while (SYSCTL_PRGPIO_R&(1<<3)==0);
				GPIO_PORTD_LOCK_R  = GPIO_LOCK_KEY;
					
				break;
				case 'E':
					SYSCTL_RCGCGPIO_R |=1<<4;
				while (SYSCTL_PRGPIO_R&(1<<4)==0);
				GPIO_PORTE_LOCK_R  = GPIO_LOCK_KEY;
					
					break;
					
				case 'F':
					SYSCTL_RCGCGPIO_R |=1<<5;
				while ((SYSCTL_PRGPIO_R & (1<<5))==0);
				GPIO_PORTF_LOCK_R  = GPIO_LOCK_KEY;
					
				break;
		
	
	
		}



}
