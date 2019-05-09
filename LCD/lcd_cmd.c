/*to use lcd connect d7-d6-d5-d4 to B3-B2-B1-B0
	and coneect RS-E to B5-B4
	*/
	
	/*in main */
			/*
			to use lcd in main 
			lcd_init();
			then use lcd_char or lcd_string or lcd_integer or lcd_clear
			you dont have to initialize pins as digital output as its already done in lcd_init
			*/


char port='B';
int rs=5;
int e=4;
int d4=0;
int d5=1;
int d6=2;
int d7=3;

		
	



void lcd_pins(char Port ,int RS,int E,int D4,int D5,int D6,int D7)  //rs,e,d4->d7
{
	char port=Port;
	int rs=RS;
	int e=E;
	int d4=D4;
	int d5=D5;
	int d6=D6;
	int d7=D7;

}



void lcd_cmd(unsigned char command)
{	int n =(command & 0xf0)>>4;
	write_data (port,n);
	write_pin(port,rs,0); // rs=0
	write_pin(port,e,1); // E=1
	delay_US(15);
	write_pin(port,e,0); //E=0
	delay_US(10);
	
	
	
	
	n=(command & 0x0f);
	write_data (port,n);
	write_pin(port,e,1); // E=1
	delay_US(15);
	write_pin(port,e,0); //E=0
	delay_MS(5);
	



}

