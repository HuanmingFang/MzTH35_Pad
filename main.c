#include <head.h>


void main(void)
{

	
	LCD_RST	= 0;		 //����ģ�鸴λ

	Time_delay(20);

	LCD_RST = 1;

	Time_delay(20);
	
	UART_Initial();			//��ʼ�� UART

	clear_LCD(backcolor);	   //����

	set_backlight(200);		   //���⻺����300

	page_home();
}