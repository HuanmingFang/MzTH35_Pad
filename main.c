#include <head.h>


void main(void)
{

	
	LCD_RST	= 0;		 //控制模块复位

	Time_delay(20);

	LCD_RST = 1;

	Time_delay(20);
	
	UART_Initial();			//初始化 UART

	clear_LCD(backcolor);	   //清屏

	set_backlight(200);		   //背光缓亮到300

	page_home();
}