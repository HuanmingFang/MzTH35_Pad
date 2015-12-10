#include <head.h>


//-------------------- photo-----------------
void page_photo()
{	int i,k,l;//i用来计数照片，k，l双层循环控制背景灯光	
	Enable_area(2);	   //使能组为2
	
	Display_BMP(0,0,35);	//背景
	Time_delay(200);
  	
	//Display_BMP_default(0,0,6);//64*64

	Display_BMP_default(260,210,14); //go back pic

	Set_area(20,260,210,320,240,2,3); //back按键区域触摸
	//void Set_area(unsigned char key_value, unsigned int X1, unsigned int Y1,
	//				unsigned int X2, unsigned int Y2, unsigned char group, unsigned char type)




	//set_area_roll(1,1,319,239);

	//endautoroll(1);////停止并置为图片的初始状态

	set_area_roll(1,1,319,239);
	//void set_area_roll(int X1,int Y1,int X2,int Y2)	
	//设定滚动的区域

	autoroll(5,1,0,0);
	//自动滚屏
	//void  autoroll (unsigned char time,unsigned char step,
	//				unsigned char direction,unsigned char reverse)
	
	
	
	Time_delay(200);

	for(i=37;i<=40;i++)
	{
	 	for(k=200;k>=0;k--)	  //渐暗
		{
			set_backlight(k);
		//	for(l=0;l<=500-k;l++);

		}
		
		Time_delay(200);
		Display_BMP(0,0,i);
	
		for(k=0;k<=200;k++)
		{	
			set_backlight(k);
			for(l=0;l<=700-k;l++);//渐亮，停留，越暗停留的时间越长
			
		}
		
		Time_delay(300);
	
	}
	for(k=200;k>=0;k--)
		{
			set_backlight(k);
		}
	
	endautoroll(0);
	Display_BMP(0,0,35);	//背景
	
	for(k=0;k<=200;k++)
		{	
			set_backlight(k);
			for(l=0;l<=700-k;l++);//停留，越暗停留的时间越长
			
		}
	//Time_delay(50);

	page_home();

}




void LCD_Key20()  //back button
{	
	if(Receive_Memory[2]==1)//释放
	{
		endautoroll(0);//停止并置为图片的初始状态
		page_home();
	}
		//if (Receive_Memory[2]==2)//按下
		//{
			//Display_BMP(0,0,7);
		//}
}



void set_area_roll(unsigned int X1,unsigned int Y1,
					unsigned int X2,unsigned int Y2)	
//设定滚动的区域
{
		Send_Check = 0;				//将校验值先清零
		
		UART_SendPacked_S(0x55);	//发送帧头
		
		UART_SendPacked_S(0x09);	//数据包个数
		
		UART_SendPacked_D(0x10);	//0x10指令
		
		Input_position(X1,Y1);
		
		Input_position(X2,Y2);
		
		UART_SendPacked_S(Send_Check);//包中有效数据的校验和	

		UART_SendPacked_S(0xAA);

}


	void  autoroll (unsigned char time,unsigned char step,
					unsigned char direction,unsigned char reverse)
	{
		
	 	Send_Check = 0;				//将校验值先清零
		
		UART_SendPacked_S(0x55);	//发送帧头
		
		UART_SendPacked_S(0x05);	//数据包个数
				
		UART_SendPacked_D(0x13);	//0x13指令
		
		UART_SendPacked_D(time);
		
		UART_SendPacked_D(step);
		
		UART_SendPacked_D(direction);

		UART_SendPacked_D(reverse);
		
		UART_SendPacked_S(Send_Check);//包中有效数据的校验和
	
		UART_SendPacked_S(0xAA);
	}


void endautoroll(unsigned char mode)
{
		Send_Check = 0;				//将校验值先清零
		
		UART_SendPacked_S(0x55);	//发送帧头
		
		UART_SendPacked_S(0x02);	//数据包个数
				
		UART_SendPacked_D(0x14);	//0x14指令
		
		UART_SendPacked_D(mode);

		UART_SendPacked_S(Send_Check);
		
		UART_SendPacked_S(0xAA);


}


/*void roll_horizontal(unsigned int num)	
//水平手动滚动
{
	  	Send_Check = 0;				//将校验值先清零
		
		UART_SendPacked_S(0x55);	//发送帧头
		
		UART_SendPacked_S(0x03);	//数据包个数
				
		UART_SendPacked_D(0x11);	//0x11指令
		
		Input_data(num);
		
		UART_SendPacked_S(Send_Check);//包中有效数据的校验和

		UART_SendPacked_S(0xAA);

} */
