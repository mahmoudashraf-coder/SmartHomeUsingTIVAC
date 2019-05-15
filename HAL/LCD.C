#include "GPIO.h"

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
	port=Port;
	rs=RS;
	e=E;
	d4=D4;
	d5=D5;
	d6=D6;
	d7=D7;

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

void lcd_init()
{		
	pin_mode (port,rs ,OUTPUT,DIGITAL,AFSEL_R_NONE);
	pin_mode (port,e ,OUTPUT,DIGITAL,AFSEL_R_NONE);
	pin_mode (port,d4 ,OUTPUT,DIGITAL,AFSEL_R_NONE);
	pin_mode (port,d5 ,OUTPUT,DIGITAL,AFSEL_R_NONE);
	pin_mode (port,d6 ,OUTPUT,DIGITAL,AFSEL_R_NONE);
	pin_mode (port,d7 ,OUTPUT,DIGITAL,AFSEL_R_NONE);
	
    
    lcd_cmd(0x02);  //send for initialization of LCD for nibble (4-bit) mode 
    lcd_cmd(0x28);  //use 2 line and initialize 5*8 matrix in (4-bit mode)
		lcd_cmd(0x01);  /*clear display screen*/
    lcd_cmd(0x0c);  /*display on cursor off*/
		lcd_cmd(0x06);  /*increment cursor (shift cursor to right)*/	   
}

void lcd_char(unsigned char dat)
{
	int nn =(dat & 0xf0)>>4;
	write_data (port,nn);
	write_pin(port,rs,1); // rs=1
	write_pin(port,e,1); // E=1
	delay_US(10);
	write_pin(port,e,0); //E=0
	delay_US(10);
	
	
	
	
	nn=(dat & 0x0f);
	write_data (port,nn);
	write_pin(port,rs,1); // rs=1
	write_pin(port,e,1); // E=1
	delay_US(10);
	write_pin(port,e,0); //E=0
	delay_US(50);
	
}
void lcd_clear()
{lcd_cmd(0x01);
delay_US(30);}

void lcd_string(const char *msg)
{
	while((*msg)!=0)
	{		
	  lcd_char(*msg);
	  msg++;	
    }
}


void lcd_integer(int value)
{char digits[5]={' ',' ',' ',' ',' '};
int i=0;
int j;
	
for (i=0;i<5;i++)
	{digits[4-i]=((value%10)+48);
    value=value/10;
		if (value==0) break;
		
	}
		for(j=0;j<=i;j++)
			lcd_char(digits[4-i+j]);
	
	
}

