#include <head.h>

	 unsigned char Send_Flag = 0;         //���ڱ�ʶUART����æ
	 
	 unsigned char Receive_Flag = 0;      //���ڱ�ʶUART����æ
	 
	 unsigned char Send_Check = 0;        //�����ݴ淢�����ݺ�У��ֵ
	 
	 unsigned char Receive_Check = 0;     //�����ݴ�������ݺ�У��ֵ

	 

/***********************���ܷ��ͳ�ʼ��***********************/

	void UART_Initial(void)   //UART��ʼ��
	{
	 
	    SCON = 0x50;          //UART ��ʽ1 �����Ե���
		
		TMOD = 0x21;          //T1����Ϊ��ʽ2
		
		TH1  = 0xfd;
		
		TL1  = 0xfd;          //11.0592MHz�ľ���ʱ��UART������Ϊ9600
		
		TR1  = 1;             //ʹ��Timer1��ΪUART�ṩʱ��
		
		ES   = 1;             //����UART�ж�
		
		EA   = 1;             //ʹ��ȫ���ж�

		IE = 0x92;
		
	}
	
	
	void UART(void) interrupt 4   //�жϷ����ӳ����ж�4
	{
	    if(RI)   //���ճɹ�
		{
		   RI = 0;
		   
		   Receive_Flag = 0;
		}
		else     //���ͳɹ�
		{
		   TI = 0;
		   
		   Send_Flag = 0;
		}
	}
	

	void UART_SendPacked_S(unsigned char Dat)
	{ 
	    while(Send_Flag);             //�ȴ��ϴη������
		
		Send_Flag = 1;                //��λ��ʶ��������ɺ󣬻����ж�����
		
		SBUF = Dat;                   //��������
	}
	
	void UART_SendPacked_D(unsigned char Dat)
	{
	    while(Send_Flag);             //�ȴ��ϴη������
		
		Send_Flag = 1;                //��λ��ʶ��������ɺ󣬻����ж�����
		
		SBUF = Dat;                   //��������
		
		Send_Check = Send_Check+Dat;  //�����͵������ۼӵ�У��ֵ���� 
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
	
	void Input_data(unsigned int X)			//����16λ���ݣ��ȸ߰�λ����Ͱ�λ
	{
		unsigned int X_High,X_Low;			
		
		X_High = X>>8;						//��λ����ȡ�߰�λ����
		
		X_Low = X%256;						//ȡ�࣬��ȡ�Ͱ�λ����				
		
		UART_SendPacked_D(X_High);						//����߰�λ
		
		UART_SendPacked_D(X_Low);						//����Ͱ�λ
	
	}

	void Input_position(unsigned int X,unsigned int Y)   //����������Ϣ
	{
	    Input_data(X);
		
		Input_data(Y);
		
	}