	#include <head.h>
	
	/************************LCD��ʾ*******************/
	
	void Display_BMP(unsigned int X,unsigned int Y,unsigned int No)
	{
	
		Send_Check = 0;
		
		UART_SendPacked_S(0x55);
		
		UART_SendPacked_S(0x07);
		
		UART_SendPacked_D(0x09);
		
		Input_position(X,Y);
		
		Input_data(No);
		
		UART_SendPacked_S(Send_Check);		//У��ֵ
		
		UART_SendPacked_S(0xAA); 			//֡β
		
	}


	void Display_BMP_default(unsigned int X,unsigned int Y,unsigned int No)
	{
	
		Send_Check = 0;
		
		UART_SendPacked_S(0x55);
		
		UART_SendPacked_S(0x07);
		
		UART_SendPacked_D(0x0E);
		
		Input_position(X,Y);
		
		Input_data(No);
		
		UART_SendPacked_S(Send_Check);		//У��ֵ
		
		UART_SendPacked_S(0xAA); 			//֡β
		
	}

	
	void clear_LCD(unsigned char value)		//����
	{
		
		Send_Check = 0;		//У��ֵ����
		
		UART_SendPacked_S(0x55);			//����֡ͷ
		
		UART_SendPacked_S(0x02);			//���ݰ���Ч���ݸ���
		
		UART_SendPacked_D(0x80);			//0X80ָ��
		
		UART_SendPacked_D(value);			//ָ������
		
		UART_SendPacked_S(Send_Check);		//У��ֵ
		
		UART_SendPacked_S(0xAA);			//֡β
	
	}
	
	
	void set_backlight(unsigned int value)
	{
		
		Send_Check = 0;						//У��ֵ����
		
		UART_SendPacked_S(0x55);			//����֡ͷ
		
		UART_SendPacked_S(0x03);			//���ݰ���Ч����Ϊ3
		
		UART_SendPacked_D(0x89);			//0x89ָ��
		
		Input_data(value);
		
		UART_SendPacked_S(Send_Check);			//��Ч���ݵ�У���
		
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
		
		Send_Check = 0;				//У��ֵ������
		
		UART_SendPacked_S(0x55);	//����֡ͷ
		
		UART_SendPacked_S(Num+5);	//���ݰ���Ч����ΪNum+5
		
		UART_SendPacked_D(0x0c);	//0x0cָ��
		
		Input_position(X,Y);		//����λ��
		
		for(i=0;i<Num;i++)
		{
		
			UART_SendPacked_D(start[i]);
		
		}
		
		UART_SendPacked_S(Send_Check);	//У��ֵ
		
		UART_SendPacked_S(0xAA);	    //֡β
		
	}
	
	
	
	
	
