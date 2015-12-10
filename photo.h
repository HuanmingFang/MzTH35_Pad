#ifndef photo_h
#define photo_h

/***************************photo page**************************/

 	void page_photo(); //page
 
 	void set_area_roll(unsigned int X1,unsigned int Y1,unsigned int X2,unsigned int Y2); //设置滚动区域

	void autoroll(unsigned char time,unsigned char step,unsigned char direction,unsigned char reverse);

	void endautoroll(unsigned char mode);

	void roll_horizontal(unsigned int num);//手动水平滚动

#endif	 