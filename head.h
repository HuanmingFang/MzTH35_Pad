#ifndef head_h
#define head_h
#define forecolor 0x55
#define backcolor 0xaa
	
	#include <reg51.h>
	#include <stdio.h>
	#include <intrins.h>
	#include <lcd.h>
	#include <uart_init.h>
	#include <touch.h>
	#include <control.h>
	#include <home.h>
	#include <game.h>
	#include <photo.h>
//	#include <draw.h>  
/************π‹Ω≈…Ë∂®***************/
		sbit LCD_RST=P3^2;

		sbit LCD_BUSY=P3^3;

		sbit LED0=P0^0;

		sbit LED1=P0^1;

		sbit LED2=P0^2;

		sbit LED3=P0^3;

		sbit LED4=P0^4;

		sbit LED5=P0^5;

		sbit LED6=P0^6;

		sbit LED7=P0^7;

		sbit direct1 = P2^0;

		sbit direct2 = P2^1;

		sbit oe = P2^4;

		sbit phase = P2^5;

		sbit direct = P2^6;

		sbit clk = P2^7;

		extern bit gameormotor; 

	//	void snake_begin();

#endif