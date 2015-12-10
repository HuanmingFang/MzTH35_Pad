#include<head.h>


	

/**************************����**********************/

	unsigned char Receive_Memory[6];//�洢���ܵ�ָ���
	
	//��ʾ�������ã��������ݷֱ�Ϊ��ֵ�����Ͻ�xy���꣬���½�xy���꣬������Լ�����
	void Set_area(unsigned char key_value, unsigned int X1, unsigned int Y1,					
					unsigned int X2, unsigned int Y2, unsigned char group, unsigned char type)
	{
		
		Send_Check = 0;				//��У��ֵ������
		
		UART_SendPacked_S(0x55);	//����֡ͷ
		
		UART_SendPacked_S(0x0c);	//���ݰ�����Ϊ 11��
		
		UART_SendPacked_D(0x25);	//0x25ָ��
		
		UART_SendPacked_D(key_value);
		
		Input_position(X1,Y1);
		
		Input_position(X2,Y2);
		
		UART_SendPacked_D(group);
		
		UART_SendPacked_D(type);
		
		UART_SendPacked_S(Send_Check);//������Ч���ݵ�У���
		
		UART_SendPacked_S(0xAA);
	
	}
	
	void Enable_area(unsigned char group)//ʹ�ܴ�������
	{
		
		Send_Check = 0;					//У��ֵ����
		
		UART_SendPacked_S(0x55);		//֡ͷ
		
		UART_SendPacked_S(0x02);		//���ݰ�Ϊ1��
		
		UART_SendPacked_D(0x26);		//0x89ָ�� 
		
		UART_SendPacked_D(group);
		
		UART_SendPacked_S(Send_Check);	//������Ч���ݵ�У���
		
		UART_SendPacked_S(0xAA);
	
	}
	
	//λͼ������ָ��
	void Set_BMP(unsigned char Key_value,
					unsigned int Num1,unsigned int Num2,unsigned int X,unsigned int Y,
					unsigned char group,unsigned char type)
	{
	
		Send_Check = 0;
		
		UART_SendPacked_S(0x55);
		
		UART_SendPacked_S(0x0C);
		
		UART_SendPacked_D(0x21);

		UART_SendPacked_D(Key_value);
		
		Input_data(Num1);

		Input_data(Num2);
		
		Input_position(X,Y);

		UART_SendPacked_D(group);

		UART_SendPacked_D(type);
		
		UART_SendPacked_S(Send_Check);		//У��ֵ
		
		UART_SendPacked_S(0xAA); 			//֡β
		
	}

	
/*	void Enable_BMP(unsigned char group)//ʹ�ܴ�������
	{
		Send_Check = 0;					//У��ֵ����
		
		UART_SendPacked_S(0x55);		//֡ͷ
		
		UART_SendPacked_S(0x02);		//���ݰ�Ϊ1��
		
		UART_SendPacked_D(0x22);		//0x89ָ�� 
		
		UART_SendPacked_D(group);
		
		UART_SendPacked_S(Send_Check);	//������Ч���ݵ�У���
		
		UART_SendPacked_S(0xAA);
	
	}*/	



	void Command_Receive()
	{
	
	unsigned char num,tmp,i;
	
	for(i=0;i<6;i++)//���ָ���
		{
	
			Receive_Memory[i] = 0;
		
		}
	Receive_Check = 0;

	tmp = UART_ReceivePacked_D();

	if(tmp!=0x55)	return;
	
	num = UART_ReceivePacked_D();
	
	for(i=0;i<num;i++)
	
		{
		
			tmp = UART_ReceivePacked_D();
			
			Receive_Check+=tmp;
			
			Receive_Memory[i] = tmp;
			
		}
	
	tmp = UART_ReceivePacked_D();
	
	if(tmp!=Receive_Check)	return;
	
	tmp = UART_ReceivePacked_D();	

	if(tmp!=0xAA) 
	
	return;
	
	Command_Process();
	
	}





	void Command_Process()
	{
	
		if(Receive_Memory[0]==0x28)
		{
			switch(Receive_Memory[1])
				{
					case 0: LCD_key00();break;
					
					case 1: LCD_key01();break;
					
					case 2: LCD_key02();break;
			
					case 3: LCD_key03();break;
					
					case 4: LCD_key04();break;
					
					case 5: LCD_key05();break;
					
					case 6: LCD_key06();break;
					
					case 7: LCD_key07();break;
					
					case 8: LCD_key08();break;
					
					case 9: LCD_key09();break;
					
					case 10: LCD_key10();break;
					
					case 11: LCD_key11();break;
					
					case 12: LCD_key12();break;
					
					case 13: LCD_key13();break;
					
					case 14: LCD_key14();break;
					
					case 15: LCD_key15();break;
					
					case 16: LCD_key16();break;
					
					case 17: LCD_key17();break;
					
					case 18: LCD_key18();break;
					
					case 19: LCD_key19();break;

					case 20: LCD_key20();break;
					
					case 21: LCD_key21();break;
					
					case 22: LCD_key22();break;
					
					case 23: LCD_key23();break;
					
					case 24: LCD_key24();break;
					
					case 25: LCD_key25();break;
					
					case 26: LCD_key26();break;
					
					case 27: LCD_key27();break;
					
					case 28: LCD_key28();break;
					
					case 29: LCD_key29();break;

					case 30: LCD_key30();break;
					
					case 31: LCD_key31();break;
					
					case 32: LCD_key32();break;
					
					case 33: LCD_key33();break;
					
					case 34: LCD_key34();break;
					
					case 35: LCD_key35();break;
					
					case 36: LCD_key36();break;
					
					case 37: LCD_key37();break;
					
					case 38: LCD_key38();break;
					
					case 39: LCD_key39();break;
					
					default: break;				
				
				}
					
		}
	}
	

	

	void touch_regul(unsigned char regul_value)//���ô������㴥����Ϣ�ķ���ԭ��
	{
//
		Send_Check = 0;					//У��ֵ����
		
		UART_SendPacked_S(0x55);		//֡ͷ
		
		UART_SendPacked_S(0x02);		//���ݸ���
		
		UART_SendPacked_D(0x2D);		//0x2Dָ�� 
		
		UART_SendPacked_D(regul_value);
		
		UART_SendPacked_S(Send_Check);	//������Ч���ݵ�У���
		
		UART_SendPacked_S(0xAA);
	
	}