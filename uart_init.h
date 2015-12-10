	#ifndef UART_INIT_h
	#define UART_INIT_h
	
	extern unsigned char Send_Flag;			//用于标示UART发送忙
	
	extern unsigned char Receive_Flag;		//用于标示UART接受忙
	
	extern unsigned char Send_Check;		//用于暂存发送数据的和校验值
	
	extern unsigned char Receive_Check;		//用于暂存接受数据的和校验值
	
	
	/***************************接受发送初始化************/
	
	void UART_Initial(void);		//UART初始化
	
	void UART_SendPacked_S(unsigned char Dat);		//发送不参与校验的数据包
	
	void UART_SendPacked_D(unsigned char Dat);		//发送参与校验的数据包
	
	unsigned char game_ReceivePacked_D();	

	unsigned char UART_ReceivePacked_D();		//接受数据包
	
	void Time_delay(unsigned int Timer);		//时间延迟
	
	void Input_data(unsigned int X);		//输入16位数据，先高八位，后低八位
	
	void Input_position(unsigned int X,unsigned int Y);		//输入坐标信息
	
	#endif