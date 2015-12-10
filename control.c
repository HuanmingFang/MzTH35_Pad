#include <head.h>

bit idata flag = 1;

bit choose_motor = 1;

bit choose_type = 1;

unsigned char hl_hb0;

unsigned char hl_lb0;

unsigned char ll_hb0;

unsigned char ll_lb0;

unsigned char hb1;

unsigned char lb1;
	
/************************电机控制*******************/
void page_control()
{
	Display_BMP(0,0,46);
	Time_delay(400);
	Display_BMP(0,0,3);//背景图片
	
	Enable_area(1);	   //使能组为1

	Display_BMP_default(260,210,14); //go back pic

	Display_BMP_default(0,0,10);  //灯泡

	Display_BMP_default(35,0,12); //DC motor pic

	Display_BMP_default(160,0,10);  //灯泡

	Display_BMP_default(190,0,13); //AC motor pic

	Display_BMP_default(5,64,19);//direction:  128*64

	Display_BMP_default(128,74,15);//anticlockwise_yes 40*37

	Display_BMP_default(200,74,18);//clockwise_no	   40*37

	Display_BMP_default(5,118,20);//Speed: 128*64

	Display_BMP_default(128,128,21);//bar1  120*64

	


	Set_area(10,260,210,320,240,1,3); //back按键区域触摸
	
	Set_area(11,0,0,160,54,1,3); //DC区域触摸

	Set_area(12,160,0,320,54,1,3); //AC区域触摸

	Set_area(13,128,74,168,100,1,3); //区域触摸anticlockwise

	Set_area(14,200,74,240,100,1,3); //区域触摸clockwise

	Set_area(15,128,128,152,192,1,3); //区域触摸bar1

	Set_area(16,128,128,176,192,1,3); //区域触摸bar2

	Set_area(17,128,128,200,192,1,3); //区域触摸bar3

	Set_area(18,128,128,224,192,1,3); //区域触摸bar4

	Set_area(19,128,128,248,192,1,3); //区域触摸bar5  //120,120~250,200
	//void Set_area(unsigned char key_value, unsigned int X1, unsigned int Y1,
	//				unsigned int X2, unsigned int Y2, unsigned char group, unsigned char type)

	//while(1)
	//{Command_Receive();}
	direct = 0;

	phase = 0;

	oe = 0;
	
	TR0 = 0; 
	
	gameormotor = 0;//初始化电机


}

void UART_motor(void)	interrupt 1
{
	if(gameormotor==0)
	{
	if(choose_motor == 1)
	{
		//LED0 = 0;

		TR0 = 0;

		flag = ~flag;

		if(flag)
		{
			direct2 = 0;

			direct1 = 0;

			TH0 = ll_hb0;

			TL0 = ll_lb0;

			TR0 = 1;

			return;
		}
		else
		{
		if(choose_type)
		{
			direct2 = 1;

			direct1 = 0;	
		}
		else
		{
			direct2 = 0;

			direct1 = 1;
		}
		TH0 = hl_hb0;

		TL0 = hl_lb0;
		
		TR0 = 1;
		
		return;		
		}
	}
	if(choose_motor == 0)
	{
		LED0 = 1;

		direct = choose_type;

		TR0 = 0;

		TH0 = hb1;

		TL0 = lb1;

		clk = ~clk;

		TR0 = 1;
	}
	}
	else
	{
		/*snake_begin();*/
	}
	
}

void LCD_key10()  //back button
{	
	if(Receive_Memory[2]==1)//释放
	{	
		direct1 = 0;

		direct2 = 0;

		TR0 = 0;
		
		page_home();
	
	}
		//if (Receive_Memory[2]==2)//按下
		//{
			//Display_BMP(0,0,7);
		//}
}

void LCD_key11()	//DC button
{	
	if(Receive_Memory[2]==1)//释放
		{
			;
		}
	if (Receive_Memory[2]==2)//按下
		{
			Display_BMP_default(0,0,11);//light up DC bulb
			Display_BMP_default(160,0,10);  //turn off AC bulb
		
			Display_BMP(120,120,26);//cover
			Display_BMP_default(128,128,21);//bar1

			choose_motor = 1;

			direct1 = 0;

			direct2 = 0;

			TR0 = 0;


		}
}

void LCD_key12()	 //AC button
{	
	if(Receive_Memory[2]==1)//释放
		{
			;
		}
	if (Receive_Memory[2]==2)//按下
		{
			Display_BMP_default(160,0,11);	//light up AC bulb
			Display_BMP_default(0,0,10);   //turn off DC bulb

			Display_BMP(120,120,26);//cover
			Display_BMP_default(128,128,21);//bar1

			choose_motor = 0;

			direct1 = 0;

			direct2 = 0;

			TR0 = 0;
		}
}

void LCD_key13()	 //anticlockwise
{	
	if(Receive_Memory[2]==1)//释放
		{
			;
		}
	if (Receive_Memory[2]==2)//按下
		{
			Display_BMP_default(128,74,15);//anticlockwise_yes 40*37

			Display_BMP_default(200,74,18);//clockwise_no	   40*37

			choose_type = 1;
		}
}

void LCD_key14()	 //clockwise
{	
	if(Receive_Memory[2]==1)//释放
		{
			;
		}
	if (Receive_Memory[2]==2)//按下
		{
			Display_BMP_default(128,74,16);//anticlockwise_no 40*37

			Display_BMP_default(200,74,17);//clockwise_yes	   40*37

			choose_type = 0;
		}
}

void LCD_key15()	 //bar1
{	
	if(Receive_Memory[2]==1)//释放
		{
			;
		}
	if (Receive_Memory[2]==2)//按下
		{
			Display_BMP(120,120,26);//cover

			Display_BMP_default(128,128,21);//bar1

			hl_hb0 = 0xe0;
			hl_lb0 = 0x00;
			ll_hb0 = 0xc0;
			ll_lb0 = 0x00;
			hb1 = 0xff;
			lb1 = 0x00;
			TR0 = 1;
			TF0 = 1;
		}
}

void LCD_key16()	 //bar2
{	
	if(Receive_Memory[2]==1)//释放
		{
			;
		}
	if (Receive_Memory[2]==2)//按下
		{
			Display_BMP(120,120,26);//cover

			Display_BMP_default(128,128,22);//bar2

			hl_hb0 = 0xc0;
			hl_lb0 = 0x00;
			ll_hb0 = 0xc0;
			ll_lb0 = 0x00;
			hb1 = 0xef;
			lb1 = 0x00;
			TR0 = 1;
			TF0 = 1;
		}
}

void LCD_key17()	 //bar3
{	
	if(Receive_Memory[2]==1)//释放
		{
			;
		}
	if (Receive_Memory[2]==2)//按下
		{
			Display_BMP(120,120,26);//cover

			Display_BMP_default(128,128,23);//bar3

			hl_hb0 = 0xa0;
			hl_lb0 = 0x00;
			ll_hb0 = 0xc0;
			ll_lb0 = 0x00;
			hb1 = 0xdf;
			lb1 = 0x00;
			TR0 = 1;
			TF0 = 1;
		}
}

void LCD_key18()	 //bar4
{	
	if(Receive_Memory[2]==1)//释放
		{
			;
		}
	if (Receive_Memory[2]==2)//按下
		{
			Display_BMP(120,120,26);//cover

			Display_BMP_default(128,128,24);//bar4

			hl_hb0 = 0x90;
			hl_lb0 = 0x00;
			ll_hb0 = 0xc0;
			ll_lb0 = 0x00;
			hb1 = 0xcf;
			lb1 = 0x00;
			TR0 = 1;
			TF0 = 1;
		}
}

void LCD_key19()	 //bar5
{	
	if(Receive_Memory[2]==1)//释放
		{
			;
		}
	if (Receive_Memory[2]==2)//按下
		{
			Display_BMP(120,120,26);//cover

			Display_BMP_default(128,128,25);//bar5

			hl_hb0 = 0x50;
			hl_lb0 = 0x00;
			ll_hb0 = 0xc0;
			ll_lb0 = 0x00;
			hb1 = 0xaf;
			lb1 = 0x00;
			TR0 = 1;
			TF0 = 1;
		}
}

