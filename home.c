#include <head.h>


//-------------------- 主页-----------------
void page_home()
{
	
	Display_BMP(0,0,2);

	Display_BMP_default(0,0,6);	//motor

	Display_BMP_default(0,64,8); //pic

	Display_BMP_default(0,128,4); //game

	Set_area(0,0,0,64,64,0,3); //区域触摸

	Set_area(1,0,0,64,128,0,3); //区域触摸 

	Set_area(2,0,128,64,172,0,3); //区域触摸

	Set_area(3,160,0,320,120,0,3);	//introduction


	//void Set_area(unsigned char key_value, unsigned int X1, unsigned int Y1,
	//				unsigned int X2, unsigned int Y2, unsigned char group, unsigned char type)

	Enable_area(0);//使能触摸区域
	//void Enable_area(unsigned char group)//使能触摸区域



	touch_regul(3);

	while(1)
	{Command_Receive();}

}

void LCD_Key00()
	{	
		if(Receive_Memory[2]==1)//释放
		{
			page_control();
		}
		if (Receive_Memory[2]==2)//按下
		{
			Display_BMP(0,0,7);
		}
	}


void LCD_Key01()
	{
		if (Receive_Memory[2]==1)  //释放
		{
			page_photo();
		}
	
		if(Receive_Memory[2]==2) //按下
		{
			Display_BMP(0,64,9);
		}  
	
	}

void LCD_Key02()
	{
		if (Receive_Memory[2]==1)  //释放
		{
			page_game();
		}
	
		if(Receive_Memory[2]==2) //按下
		{
			Display_BMP(0,128,5);
		}  
	
	}

void LCD_Key03()
{
	if (Receive_Memory[2]==1)  //释放
		{
			Display_BMP_default(0,0,47);
			Time_delay(800);
			page_home();	
		}


}