	#ifndef UART_INIT_h
	#define UART_INIT_h
	
	extern unsigned char Send_Flag;			//���ڱ�ʾUART����æ
	
	extern unsigned char Receive_Flag;		//���ڱ�ʾUART����æ
	
	extern unsigned char Send_Check;		//�����ݴ淢�����ݵĺ�У��ֵ
	
	extern unsigned char Receive_Check;		//�����ݴ�������ݵĺ�У��ֵ
	
	
	/***************************���ܷ��ͳ�ʼ��************/
	
	void UART_Initial(void);		//UART��ʼ��
	
	void UART_SendPacked_S(unsigned char Dat);		//���Ͳ�����У������ݰ�
	
	void UART_SendPacked_D(unsigned char Dat);		//���Ͳ���У������ݰ�
	
	unsigned char game_ReceivePacked_D();	

	unsigned char UART_ReceivePacked_D();		//�������ݰ�
	
	void Time_delay(unsigned int Timer);		//ʱ���ӳ�
	
	void Input_data(unsigned int X);		//����16λ���ݣ��ȸ߰�λ����Ͱ�λ
	
	void Input_position(unsigned int X,unsigned int Y);		//����������Ϣ
	
	#endif