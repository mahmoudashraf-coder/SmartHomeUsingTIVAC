#ifndef __ARMCORTEX_LCD__
#define __ARMCORTEX_LCD__

void lcd_pins(char Port ,int RS,int E,int D4,int D5,int D6,int D7);
void lcd_cmd(unsigned char command);
void lcd_init();
void lcd_char(unsigned char dat);
void lcd_clear();
void lcd_integer(int value);
#endif
