#include <head.h>


//-------------------- photo-----------------
void page_photo()
{	int i,k,l;//i����������Ƭ��k��l˫��ѭ�����Ʊ����ƹ�	
	Enable_area(2);	   //ʹ����Ϊ2
	
	Display_BMP(0,0,35);	//����
	Time_delay(200);
  	
	//Display_BMP_default(0,0,6);//64*64

	Display_BMP_default(260,210,14); //go back pic

	Set_area(20,260,210,320,240,2,3); //back����������
	//void Set_area(unsigned char key_value, unsigned int X1, unsigned int Y1,
	//				unsigned int X2, unsigned int Y2, unsigned char group, unsigned char type)




	//set_area_roll(1,1,319,239);

	//endautoroll(1);////ֹͣ����ΪͼƬ�ĳ�ʼ״̬

	set_area_roll(1,1,319,239);
	//void set_area_roll(int X1,int Y1,int X2,int Y2)	
	//�趨����������

	autoroll(5,1,0,0);
	//�Զ�����
	//void  autoroll (unsigned char time,unsigned char step,
	//				unsigned char direction,unsigned char reverse)
	
	
	
	Time_delay(200);

	for(i=37;i<=40;i++)
	{
	 	for(k=200;k>=0;k--)	  //����
		{
			set_backlight(k);
		//	for(l=0;l<=500-k;l++);

		}
		
		Time_delay(200);
		Display_BMP(0,0,i);
	
		for(k=0;k<=200;k++)
		{	
			set_backlight(k);
			for(l=0;l<=700-k;l++);//������ͣ����Խ��ͣ����ʱ��Խ��
			
		}
		
		Time_delay(300);
	
	}
	for(k=200;k>=0;k--)
		{
			set_backlight(k);
		}
	
	endautoroll(0);
	Display_BMP(0,0,35);	//����
	
	for(k=0;k<=200;k++)
		{	
			set_backlight(k);
			for(l=0;l<=700-k;l++);//ͣ����Խ��ͣ����ʱ��Խ��
			
		}
	//Time_delay(50);

	page_home();

}




void LCD_Key20()  //back button
{	
	if(Receive_Memory[2]==1)//�ͷ�
	{
		endautoroll(0);//ֹͣ����ΪͼƬ�ĳ�ʼ״̬
		page_home();
	}
		//if (Receive_Memory[2]==2)//����
		//{
			//Display_BMP(0,0,7);
		//}
}



void set_area_roll(unsigned int X1,unsigned int Y1,
					unsigned int X2,unsigned int Y2)	
//�趨����������
{
		Send_Check = 0;				//��У��ֵ������
		
		UART_SendPacked_S(0x55);	//����֡ͷ
		
		UART_SendPacked_S(0x09);	//���ݰ�����
		
		UART_SendPacked_D(0x10);	//0x10ָ��
		
		Input_position(X1,Y1);
		
		Input_position(X2,Y2);
		
		UART_SendPacked_S(Send_Check);//������Ч���ݵ�У���	

		UART_SendPacked_S(0xAA);

}


	void  autoroll (unsigned char time,unsigned char step,
					unsigned char direction,unsigned char reverse)
	{
		
	 	Send_Check = 0;				//��У��ֵ������
		
		UART_SendPacked_S(0x55);	//����֡ͷ
		
		UART_SendPacked_S(0x05);	//���ݰ�����
				
		UART_SendPacked_D(0x13);	//0x13ָ��
		
		UART_SendPacked_D(time);
		
		UART_SendPacked_D(step);
		
		UART_SendPacked_D(direction);

		UART_SendPacked_D(reverse);
		
		UART_SendPacked_S(Send_Check);//������Ч���ݵ�У���
	
		UART_SendPacked_S(0xAA);
	}


void endautoroll(unsigned char mode)
{
		Send_Check = 0;				//��У��ֵ������
		
		UART_SendPacked_S(0x55);	//����֡ͷ
		
		UART_SendPacked_S(0x02);	//���ݰ�����
				
		UART_SendPacked_D(0x14);	//0x14ָ��
		
		UART_SendPacked_D(mode);

		UART_SendPacked_S(Send_Check);
		
		UART_SendPacked_S(0xAA);


}


/*void roll_horizontal(unsigned int num)	
//ˮƽ�ֶ�����
{
	  	Send_Check = 0;				//��У��ֵ������
		
		UART_SendPacked_S(0x55);	//����֡ͷ
		
		UART_SendPacked_S(0x03);	//���ݰ�����
				
		UART_SendPacked_D(0x11);	//0x11ָ��
		
		Input_data(num);
		
		UART_SendPacked_S(Send_Check);//������Ч���ݵ�У���

		UART_SendPacked_S(0xAA);

} */
