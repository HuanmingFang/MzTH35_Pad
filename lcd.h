#ifndef LCD_h
#define LCD_h

/***************************LCD显示**************************/

void Display_BMP(unsigned int X,unsigned int Y,unsigned int No)  ;

void Display_BMP_default(unsigned int X,unsigned int Y,unsigned int No);//以缺省模式显示

void clear_LCD(unsigned char value);//清屏

void set_backlight(unsigned int value);

void Dispaly_NCharater(unsigned int X,unsigned int Y,unsigned char * start);
	
#endif	  