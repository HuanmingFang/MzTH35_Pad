#ifndef LCD_h
#define LCD_h

/***************************LCD��ʾ**************************/

void Display_BMP(unsigned int X,unsigned int Y,unsigned int No)  ;

void Display_BMP_default(unsigned int X,unsigned int Y,unsigned int No);//��ȱʡģʽ��ʾ

void clear_LCD(unsigned char value);//����

void set_backlight(unsigned int value);

void Dispaly_NCharater(unsigned int X,unsigned int Y,unsigned char * start);
	
#endif	  