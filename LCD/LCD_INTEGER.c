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

