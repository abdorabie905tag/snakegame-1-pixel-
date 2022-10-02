/*
 * main.c
 *
 *  Created on: Oct 1, 2022
 *      Author: Abdelrahman Rabie 
 */
#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"DIO_Interface.h"
#include"KPD_Interface.h"
#include"LCD_Interface.h"
#include"avr/delay.h"
#include <stdio.h>
#include <stdlib.h>

//matrix
u8 Char[8];
/***************************************************
 * 
 * 
 * 
 * Funcation to drow on ram to print snake on LCD
 * 
 * 
 * 
 * 
 * 
 *******************************************************/
void Lcd_vidDisplay_Custom_Character_Array(char LCD_Matrix[16][80]);
/************
 * 
 * 
 * main function
 * 
 * 
 * ***********/
int main()
{
/******
 * 
 * keypad init
 * 
 * *******/
	KPD_vidInit();
	/********
	 * 
	 * 
	 * LCD init
	 * 
	 * *****/
	LCD_VidInit();
	/*********
	 * 
	 * 
	 * var to use in functions
	 * 
	 * 
	 * *************/
	u8 LCD_Matrix[16][80];
	s8 Snake1_Row = 2;
	s8 Snake1_Column = 2;
	u8 Snake2_Row = 1;
	u8 Snake2_Column = 1;
	u8 Snake3_Row = 0;
	u8 Snake3_Column = 0;
	u8 Button;
	u8 Direction= 'r'; //right
	u8 Length=2;
	u8 Status=0;
	/********
	 * 
	 * random function to print food for snake
	 * 
	 * *************/
	u8 APP_Row = rand() % 16;
	u8 APP_Column = rand() % 75;
	/******
	 * 
	 * init snake as 0
	 * 
	 * 
	 * **********/
	for (u8 i=0;i<16;i++)
	{
		for(u8 j=0;j<80;j++)
		{
			LCD_Matrix[i][j] = 0;
		}
	}


	while(1)
	{
		_delay_ms(500);
		LCD_VidSendCommand(0x01);
		_delay_ms(2);


	if(Snake1_Row>15 || Snake1_Row<0 || Snake1_Column>74 || Snake1_Column<0)
	{
		//GAMEOVER;
	}

	LCD_VidSetLocation(1 , 15);
	LCD_VidSendChar(Length + '0');
	LCD_Matrix[Snake1_Row][Snake1_Column] = 1;
	LCD_Matrix[Snake2_Row][Snake2_Column] = 1;
	LCD_Matrix[Snake3_Row][Snake3_Column] = 1;

	while(((APP_Row == Snake1_Row && APP_Column == Snake1_Column)||(APP_Row == Snake2_Row && APP_Column == Snake2_Column)||(APP_Row == Snake3_Row && APP_Column == Snake3_Column)) && Status == 0)
	{

		APP_Row = rand() % 16;
		APP_Column = rand() % 75;
	}

	Status = 1;
	LCD_Matrix[APP_Row][APP_Column] = 1;
	Lcd_vidDisplay_Custom_Character_Array(LCD_Matrix[16][80]);
	/*********
	 * 
	 * when eat apple scoor ++
	 * 
	 * **********/
	if(((APP_Row == Snake1_Row && APP_Column == Snake1_Column)) && Status == 1)
			{

				APP_Row = rand() % 16;
				APP_Column = rand() % 75;
				Length = Length + 1;
				Status = 0;
			}
			//------------------------------------------------- Move Character
			LCD_Matrix[Snake3_Row][Snake3_Column] = 0;
			Snake3_Column = Snake2_Column;
			Snake3_Row = Snake2_Row;
			Snake2_Column = Snake1_Column;
			Snake2_Row = Snake1_Row;
	// 
	//get kay 
	//

	/**
	 *   2
	 * 4   6
	 *   8
	 **/
			Button = KPD_U8GetPressedKey();
					if(Button == 2 || Button == 4 || Button == 6 || Button == 8 )
					{
						switch(Button)
						{
						case 2:
							if(Direction == 'r' || Direction == 'l' || Direction == 'u' )
							{
								Snake1_Row--;
								Direction = 'u'; //up
							}
							break;
						case 4:
							if(Direction == 'u' || Direction == 'd' || Direction == 'l' )
							{
								Snake1_Column--;
								Direction = 'l'; //left
							}
							break;
						case 6:
							if(Direction == 'u' || Direction == 'd' || Direction == 'r' )
							{
								Snake1_Column++;
								Direction = 'r';  //rigt
							}
							break;
						case 8:
							if(Direction == 'r' || Direction == 'l' || Direction == 'd' )
							{
								Snake1_Row++;
								Direction = 'd';  //down
							}
							break;
						}
					}
					else
					{
						switch(Direction)
						{
						case 'r': //rigt
							Snake1_Column++;
							break;
						case 'l': //left
							Snake1_Column--;
							break;
						case 'u':   //up
							Snake1_Row--;
							break;
						case 'd': //down
							Snake1_Row++;
							break;
						}
					}


				}
	return 0;
}
/**************
 * 
 * 
 * drow snake 
 * 
 * 
 * ************/
void Lcd_vidDisplay_Custom_Character_Array(char LCD_Matrix[16][80])
{
	u8 Flag_Char_Exist = 0;
	u8 Row;
	u8 Reg=0;
	u8 Character_order = 0;

	for(u8 i=0;i<80;i=i+5)
	{
		for(u8 j=0;j<16;j++)
		{
			for(u8 z=i;z<i+5;z++)
			{
				if(LCD_Matrix[j][z] == 1)
				{
					Flag_Char_Exist = 1;
					if(j>=8)
					{
						Row = 1;
					}
					break;
				}
			}
			if(Flag_Char_Exist == 1)
			{
				break;
			}
		}

		if(Flag_Char_Exist == 1)
		{
			for(u8 j=0;j<9;j++)
			{
				u8 Col = 4;
				for(u8 z=i;z<i+5;z++)
				{
					if(LCD_Matrix[j][z] == 1)
					{
						SET_BIT(Reg,Col);
					}
					Col--;
				}
				Char[j] = Reg;
				Reg = 0;
			}
			LCD_VidDrawSpecialChar(Character_order , Char);
			LCD_VidSetLocation(0 , i/5);
			LCD_VidSendChar(Character_order);
			Character_order++;
			for(u8 j=0;j<9;j++)
			{
				u8 Col = 4;
				for(u8 z=i;z<i+5;z++)
				{
					if(LCD_Matrix[j+8][z] == 1)
					{
						SET_BIT(Reg,Col);
					}
					Col--;
				}
				Char[j] = Reg;
				Reg = 0;
			}
			LCD_VidDrawSpecialChar(Character_order , Char);
			LCD_VidSetLocation(1 , i/5);
			LCD_VidSendChar(Character_order);
			Character_order++;
			Flag_Char_Exist = 0;
		}
	}
	Character_order = 0;
}

