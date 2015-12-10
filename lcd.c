	#include <head.h>
	
	/************************LCD显示*******************/
	
	void Display_BMP(unsigned int X,unsigned int Y,unsigned int No)
	{
	
		Send_Check = 0;
		
		UART_SendPacked_S(0x55);
		
		UART_SendPacked_S(0x07);
		
		UART_SendPacked_D(0x09);
		
		Input_position(X,Y);
		
		Input_data(No);
		
		UART_SendPacked_S(Send_Check);		//校验值
		
		UART_SendPacked_S(0xAA); 			//帧尾
		
	}


	void Display_BMP_default(unsigned int X,unsigned int Y,unsigned int No)
	{
	
		Send_Check = 0;
		
		UART_SendPacked_S(0x55);
		
		UART_SendPacked_S(0x07);
		
		UART_SendPacked_D(0x0E);
		
		Input_position(X,Y);
		
		Input_data(No);
		
		UART_SendPacked_S(Send_Check);		//校验值
		
		UART_SendPacked_S(0xAA); 			//帧尾
		
	}

	
	void clear_LCD(unsigned char value)		//清屏
	{
		
		Send_Check = 0;		//校验值清零
		
		UART_SendPacked_S(0x55);			//发送帧头
		
		UART_SendPacked_S(0x02);			//数据包有效数据个数
		
		UART_SendPacked_D(0x80);			//0X80指令
		
		UART_SendPacked_D(value);			//指令数据
		
		UART_SendPacked_S(Send_Check);		//校验值
		
		UART_SendPacked_S(0xAA);			//帧尾
	
	}
	
	
	void set_backlight(unsigned int value)
	{
		
		Send_Check = 0;						//校验值清零
		
		UART_SendPacked_S(0x55);			//发送帧头
		
		UART_SendPacked_S(0x03);			//数据包有效数据为3
		
		UART_SendPacked_D(0x89);			//0x89指令
		
		Input_data(value);
		
		UART_SendPacked_S(Send_Check);			//有效数据的校验和
		
		UART_SendPacked_S(0xAA);
	
	}
	
	
	void Display_NCharater(unsigned int X,unsigned int Y,unsigned char * start)
	{
		
		unsigned int i;
		
		unsigned char Num;
		
		for(i=0;start[i]!='\0';i++)
		{
			
			_nop_();
		
		}
		
		Num = i;
		
		Send_Check = 0;				//校验值先清零
		
		UART_SendPacked_S(0x55);	//发送帧头
		
		UART_SendPacked_S(Num+5);	//数据包有效个数为Num+5
		
		UART_SendPacked_D(0x0c);	//0x0c指令
		
		Input_position(X,Y);		//输入位置
		
		for(i=0;i<Num;i++)
		{
		
			UART_SendPacked_D(start[i]);
		
		}
		
		UART_SendPacked_S(Send_Check);	//校验值
		
		UART_SendPacked_S(0xAA);	    //帧尾
		
	}
	
	
	
	
	
