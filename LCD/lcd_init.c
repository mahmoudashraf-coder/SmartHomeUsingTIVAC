
void lcd_init()
{		pin_mode (port,rs ,OUTPUT,DIGITAL);
	pin_mode (port,e ,OUTPUT,DIGITAL);
	pin_mode (port,d4 ,OUTPUT,DIGITAL);
	pin_mode (port,d5 ,OUTPUT,DIGITAL);
	pin_mode (port,d6 ,OUTPUT,DIGITAL);
	pin_mode (port,d7 ,OUTPUT,DIGITAL);
	
    
    lcd_cmd(0x02);  //send for initialization of LCD for nibble (4-bit) mode 
    lcd_cmd(0x28);  //use 2 line and initialize 5*8 matrix in (4-bit mode)
		lcd_cmd(0x01);  /*clear display screen*/
    lcd_cmd(0x0c);  /*display on cursor off*/
		lcd_cmd(0x06);  /*increment cursor (shift cursor to right)*/	   
}
