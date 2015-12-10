#ifndef TOUCH_h
#define TOUCH_h

extern unsigned char Receive_Memory[6]; //使能组的标志

/***********************touch.c*************************/

	void Set_area(unsigned char key_value, unsigned int x1, 
						unsigned int Y1,unsigned int X2, 
						unsigned int Y2, unsigned char group, 
						unsigned char type)	;
	
	void Enable_area(unsigned char group);

	void Set_BMP(unsigned char Key_value,
					unsigned int X,unsigned int Y,unsigned int Num1,unsigned int Num2,
					unsigned char group,unsigned char type);

	void Enable_BMP(unsigned char group);
	
	void Command_Process();
	
	void Command_Receive();

	void Game_Receive();

	void game_Process();

	void touch_regul(unsigned char touch_regul_value);//控制触摸屏触摸响应的原则
	
	void LCD_key00();
	
	void LCD_key01();
	
	void LCD_key02();
	
	void LCD_key03();
	
	void LCD_key04();
	
	void LCD_key05();
	
	void LCD_key06();
	
	void LCD_key07();
	
	void LCD_key08();
	
	void LCD_key09();
	
	void LCD_key10();
	
	void LCD_key11();
	
	void LCD_key12();
	
	void LCD_key13();
	
	void LCD_key14();
	
	void LCD_key15();
	
	void LCD_key16();
	
	void LCD_key17();
	
	void LCD_key18();
	
	void LCD_key19();
	
	void LCD_key20();
	
	void LCD_key21();
	
	void LCD_key22();
	
	void LCD_key23();
	
	void LCD_key24();
	
	void LCD_key25();
	
	void LCD_key26();
	
	void LCD_key27();
	
	void LCD_key28();
	
	void LCD_key29();
	
	void LCD_key30();
	
	void LCD_key31();
	
	void LCD_key32();
	
	void LCD_key33();
	
	void LCD_key34();
	
	void LCD_key35();
	
	void LCD_key36();
	
	void LCD_key37();
	
	void LCD_key38();
	
	void LCD_key39();


	
#endif
	