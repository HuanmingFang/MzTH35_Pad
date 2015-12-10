#include <head.h>

unsigned char people_x;
unsigned char people_y;
unsigned char wall_x[9]={7,6,9,8,5,2,3,4,11},wall_y[9] = {2,3,3,8,7,4,8,5,7};//box的位置
bit gameormotor;
unsigned head; 




//--------------------game-----------------
void page_game()
{	
	int x=0,y=0;
	Enable_area(3);	   //使能组为3
	
	Display_BMP(0,0,45);	//背景
	Time_delay(200);

  	
	//Display_BMP_default(0,0,6);//64*64
	
	for(x=0;x<=319;x=x+16)		   //写满背景
	{
		for(y=0;y<=239;y=y+16)
		Display_BMP(x,y,31);//white
	}
	
	Display_BMP(0,0,27);  //up 
	Display_BMP(0,208,28);	//down
	Display_BMP(0,0,29);//left
	Display_BMP(288,0,30);//right
	Display_BMP(260,209,14); //go back pic	

	Set_area(30,260,210,320,240,3,1); //返回按键区域触摸

	Set_area(31,32,0,288,32,3,1);	   //up按键区域触摸

	Set_area(32,32,208,288,240,3,1);  //down按键区域触摸

	Set_area(33,0,32,32,208,3,1);  //left按键区域触摸

	Set_area(34,288,32,320,208,3,1);  //right按键区域触摸
	//void Set_area(unsigned char key_value, unsigned int X1, unsigned int Y1,
	//				unsigned int X2, unsigned int Y2, unsigned char group, unsigned char type)

	//初始化

	
	for(x=1;x<=16;x++)
	{
		Display_BMP(x*16+16,1*16+16,32);//wall
		Display_BMP(x*16+16,11*16+16,32);//wall	

	}
	for(y=1;y<=11;y++)
	{
		Display_BMP(1*16+16,y*16+16,32);//wall
		Display_BMP(16*16+16,y*16+16,32); //wall
	}

	Display_BMP(16*16+16,6*16+16,43); //destnation

	Display_BMP(7*16+16,2*16+16,32);//wall
	Display_BMP(6*16+16,3*16+16,32);//wall
	Display_BMP(9*16+16,3*16+16,32);//wall
	Display_BMP(8*16+16,8*16+16,32);//wall
	Display_BMP(5*16+16,7*16+16,32);//wall
	Display_BMP(2*16+16,4*16+16,32);//wall
	Display_BMP(3*16+16,8*16+16,32);//wall
	Display_BMP(4*16+16,5*16+16,32);//wall
	Display_BMP(11*16+16,7*16+16,32);//wall

	Display_BMP(7*16+16,4*16+16,33);//people_red
	people_x = 7;
	people_y = 4;
}

void LCD_key30()  //back button
{	
	if(Receive_Memory[2]==1)//释放
	{
	
	}
	if (Receive_Memory[2]==2)//按下
	{
		page_home();
	}
}

void LCD_key31()  //up
{	
	if(Receive_Memory[2]==1)//释放
	{
		
			
	}
	else if (Receive_Memory[2]==2)//按下
	{	unsigned char a;
		head = 1;
		a = compare();
		while(a==2)	//go on
		{
			Display_BMP(people_x*16+16,people_y*16+16,31);//white
			people_y--;
			Display_BMP(people_x*16+16,people_y*16+16,33);//people_red
			a = compare();

		}
		if(a==0) //win
		{	Display_BMP(people_x*16+16,people_y*16+16,31);//white
			people_y--;
			Display_BMP(people_x*16+16,people_y*16+16,33);
			Display_BMP_default(0,60,44);
			Time_delay(400);
			page_home();
		
		
		}
		else if(a==1) //stop
		{ ;
		}

		
	}
}


void LCD_key32()  //down
{	
	if(Receive_Memory[2]==1)//释放
	{
	//	page_home();
	}
	if (Receive_Memory[2]==2)//按下
	{	unsigned char a;
		head = 2;
		a = compare();
		while(a==2)	//go on
		{
			Display_BMP(people_x*16+16,people_y*16+16,31);//white
			people_y++;
			Display_BMP(people_x*16+16,people_y*16+16,33);//people_red
			a = compare();

		}
		if(a==0) //win
		{	Display_BMP(people_x*16+16,people_y*16+16,31);//white
			people_y++;
			Display_BMP(people_x*16+16,people_y*16+16,33);
			Display_BMP_default(0,60,44);
			Time_delay(500);
			page_home();
		
		
		}
		else if(a==1) //stop
		{ ;
		}
		
	}
}

void LCD_key33()  //left
{	
	if(Receive_Memory[2]==1)//释放
	{
	//	page_home();
	}
	if (Receive_Memory[2]==2)//按下
	{
		unsigned char a;
		head = 3;
		a = compare();
		while(a==2)	//go on
		{
			Display_BMP(people_x*16+16,people_y*16+16,31);//white
			people_x--;
			Display_BMP(people_x*16+16,people_y*16+16,33);//people_red
			a = compare();

		}
		if(a==0) //win
		{	Display_BMP(people_x*16+16,people_y*16+16,31);//white
			people_x--;
			Display_BMP(people_x*16+16,people_y*16+16,33);
			Display_BMP_default(0,60,44);
			Time_delay(400);
			page_home();
		
		
		}
		else if(a==1) //stop
		{ ;
		}
		
	}
}

void LCD_key34()  //right
{	
	if(Receive_Memory[2]==1)//释放
	{
	//	page_home();
	}
	if (Receive_Memory[2]==2)//按下
	{
		unsigned char a;
		head = 4;
		a = compare();
		while(a==2)	//go on
		{
			Display_BMP(people_x*16+16,people_y*16+16,31);//white
			people_x++;
			Display_BMP(people_x*16+16,people_y*16+16,33);//people_red
			a = compare();

		}
		if(a==0) //win
		{	Display_BMP(people_x*16+16,people_y*16+16,31);//white
			people_x++;
			Display_BMP(people_x*16+16,people_y*16+16,33);
			Display_BMP_default(0,60,44);
			Time_delay(500);
			page_home();
		
		}
		else if(a==1) //stop
		{ ;
		}
		
	}
}

unsigned char compare()
{
	if(head==4&&people_x+1==16&&people_y==6)
		return(0);
	else if(head==1)
		{
			if(people_y-1==1)
			{
				return(1);
			}
			else if(equal())
					{
						return(1);
					}
					else 
					{
						return(2);
					}
		}
		else if(head==2)
			{
				if(people_y+1==11)
				{
					return(1);
				}
				else if(equal())
					{
						return(1);
					}
					else 
					{
						return(2);
					}
			}
			else if(head==3)
				{
					if(people_x-1==1)
					return(1);
					else if(equal())
						{
							return(1);
						}
						 else
						 {
						  	return(2);
						 }
					
				}
				else if(head==4)
					{
						if(people_x+1==16)
						return(1);
						else if(equal())
							{
								return(1);
							}
							else
							{
								return(2);
							}
					}
				else return(1);
}
 unsigned char equal()
 {int i;
 	if(head==1)
	{for(i=0;i<=8;i++)
		{
			if(people_x==wall_x[i]&&people_y-1==wall_y[i])
			{
				return(1);
			}
		}
	return(0);
 	}
	else if(head==2)
	{for(i=0;i<=8;i++)
		{
			if(people_x==wall_x[i]&&people_y+1==wall_y[i])
			{
				return(1);
			}
		}
	return(0);
 	}
	else if(head==3)
	{for(i=0;i<=8;i++)
		{
			if(people_x-1==wall_x[i]&&people_y==wall_y[i])
			{
				return(1);
			}
		}
	return(0);
 	}
	else if(head==4)
	{for(i=0;i<=8;i++)
		{
			if(people_x+1==wall_x[i]&&people_y==wall_y[i])
			{
				return(1);
			}
		}
	return(0);
 	}

	else return(1);


}
