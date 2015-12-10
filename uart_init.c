#include <head.h>

	 unsigned char Send_Flag = 0;         //用于标识UART发送忙
	 
	 unsigned char Receive_Flag = 0;      //用于标识UART接收忙
	 
	 unsigned char Send_Check = 0;        //用于暂存发送数据和校验值
	 
	 unsigned char Receive_Check = 0;     //用于暂存接收数据和校验值

	 

/***********************接受发送初始化***********************/

	void UART_Initial(void)   //UART初始化
	{
	 
	    SCON = 0x50;          //UART 方式1 单机对单机
		
		TMOD = 0x21;          //T1工作为方式2
		
		TH1  = 0xfd;
		
		TL1  = 0xfd;          //11.0592MHz的晶振时，UART波特率为9600
		
		TR1  = 1;             //使能Timer1，为UART提供时钟
		
		ES   = 1;             //允许UART中断
		
		EA   = 1;             //使能全局中断

		IE = 0x92;
		
	}
	
	
	void UART(void) interrupt 4   //中断服务子程序，中断4
	{
	    if(RI)   //接收成功
		{
		   RI = 0;
		   
		   Receive_Flag = 0;
		}
		else     //发送成功
		{
		   TI = 0;
		   
		   Send_Flag = 0;
		}
	}
	

	void UART_SendPacked_S(unsigned char Dat)
	{ 
	    while(Send_Flag);             //等待上次发送完成
		
		Send_Flag = 1;                //置位标识，发送完成后，会在中断清零
		
		SBUF = Dat;                   //发送数据
	}
	
	void UART_SendPacked_D(unsigned char Dat)
	{
	    while(Send_Flag);             //等待上次发送完成
		
		Send_Flag = 1;                //置位标识，发送完成后，会在中断清零
		
		SBUF = Dat;                   //发送数据
		
		Send_Check = Send_Check+Dat;  //将发送的数据累加到校验值当中 
	}
	
	
/*	unsigned char game_ReceivePacked_D()
	{
		while(Receive_Flag)
		{  
		LED0 =0;
		
		snake_nextstate();
		snake_draw();
		Time_delay(200);
		}
	  	
		Receive_Flag = 1;
		LED1 =0;
		return(SBUF);
	
	} */

	
	
	unsigned char UART_ReceivePacked_D()
	{
	    
		while(Receive_Flag);
		
		Receive_Flag = 1;
		
		return(SBUF);

	}
	
	
	
	void Time_delay(unsigned int Timer)
	{
	    unsigned int i = 0;
		
		while(Timer)
		{
		   for(i=0;i<707;i++);
		   
		   Timer--;
		}
	}
	
	void Input_data(unsigned int X)			//输入16位数据，先高八位，后低八位
	{
		unsigned int X_High,X_Low;			
		
		X_High = X>>8;						//移位，获取高八位数据
		
		X_Low = X%256;						//取余，获取低八位数据				
		
		UART_SendPacked_D(X_High);						//送入高八位
		
		UART_SendPacked_D(X_Low);						//送入低八位
	
	}

	void Input_position(unsigned int X,unsigned int Y)   //输入坐标信息
	{
	    Input_data(X);
		
		Input_data(Y);
		
	}