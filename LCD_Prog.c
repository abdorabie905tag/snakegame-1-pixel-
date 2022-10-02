/**************************************************************************************************/
/**************		Auther	:	 Ahmed Amr         ************************************************/
/**************		File  	:	 Interface of KPD      ********************************************/
/**************		Date  	:	 9/9/2022              ********************************************/
/**************		Ver   	:	 V1                    ********************************************/
/**************		Desc  	:	                       ********************************************/
/**************************************************************************************************/

/*Include LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*Include MCAL*/
#include "DIO_Interface.h"

/*Include HAL*/
#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "LCD_Config.h"

/*Include Function*/
#include <util/delay.h>




void LCD_VidSendCommand (u8 Copy_U8Command)
{
	DIO_VidSetPinValue	(LCD_CONTROL_PORT , RS , DIO_U8_LOW);
	DIO_VidSetPinValue	(LCD_CONTROL_PORT , RW , DIO_U8_LOW);
	DIO_VidSetPortValue	(LCD_DATA_PORT , Copy_U8Command);
	DIO_VidSetPinValue	(LCD_CONTROL_PORT , EN , DIO_U8_HIGH);
	_delay_ms(2);
	DIO_VidSetPinValue	(LCD_CONTROL_PORT , EN , DIO_U8_LOW);
}


void LCD_VidSendChar    (u8 Copy_U8Char)
{
	DIO_VidSetPinValue(LCD_CONTROL_PORT , RS , DIO_U8_HIGH);
	DIO_VidSetPinValue(LCD_CONTROL_PORT , RW , DIO_U8_LOW);
	DIO_VidSetPortValue(LCD_DATA_PORT , Copy_U8Char);
	DIO_VidSetPinValue(LCD_CONTROL_PORT , EN , DIO_U8_HIGH);
	_delay_ms(2);
	DIO_VidSetPinValue(LCD_CONTROL_PORT , EN , DIO_U8_LOW);
}

void LCD_VidSendString  (u8 *Copy_U8String)
{
	u8 Local_U8Counter ;
	for (Local_U8Counter = 0 ; Copy_U8String[Local_U8Counter] != '\0' ; Local_U8Counter++)
		LCD_VidSendChar(Copy_U8String[Local_U8Counter]);
}

void LCD_vidSendNumber(u32 Copy_u32Number)
{
	u32 Local_u32Counter=1 , Local_u32Digit=0;

	if (Copy_u32Number == 0)  LCD_VidSendChar('0');
	else
	{
		while (Copy_u32Number/Local_u32Counter != 0)
		{
			Local_u32Counter *= 10;
		}
		Local_u32Counter /=10;

		while (Local_u32Counter != 0)
		{
			Local_u32Digit = Copy_u32Number/Local_u32Counter;

			LCD_VidSendChar(Local_u32Digit + '0');

			Copy_u32Number = Copy_u32Number%Local_u32Counter;

			Local_u32Counter /= 10;
		}
	}
}


void LCD_VidSetLocation (u8 Copy_U8LineNum , u8 Copy_U8CharNum)
{
	switch (Copy_U8LineNum)
	{
		case LCD_U8_LINE1 : LCD_VidSendCommand (0x80+Copy_U8CharNum) ; break ;
		
		case LCD_U8_LINE2 : LCD_VidSendCommand (0xc0+Copy_U8CharNum) ; break ;
	}
}

void LCD_vidSetCharLocation(u8 Copy_u8Location)
{
	/* (40) Digit in Each line , Line1 >> 0:39   &&   Line2 >> 64 : 104 */
	if (Copy_u8Location <= 39)
		LCD_VidSendCommand(0x80 + Copy_u8Location);      /* (0x80) is the Start point of the first Digit in Line 1 */
	else if (Copy_u8Location >= 40)
		LCD_VidSendCommand(0xc0 + Copy_u8Location -40);  /* (0xc0) is the Start point of the first Digit in Line 2 */
}

void LCD_VidDrawSpecialChar (u8 Copy_U8CharAddress , u8 *Copy_U8SpecialChar)
{
	LCD_VidSendCommand(0b01000000+(Copy_U8CharAddress * 8));
	_delay_us(40);
	u8 LCD_U8Counter ;
	for (LCD_U8Counter=0 ; LCD_U8Counter<8 ; LCD_U8Counter++)
	{
		LCD_VidSendChar(Copy_U8SpecialChar[LCD_U8Counter]);
	}
}

void LCD_VidSendSpecialChar(u8 Copy_U8CharAddress , u8 Copy_U8LineNum , u8 Copy_U8CharNum)
{
	LCD_VidSetLocation(Copy_U8LineNum , Copy_U8CharNum);
	LCD_VidSendChar(Copy_U8CharAddress);
}

void LCD_VidInit (void )
{
	/*Set Data Port Output*/
	DIO_VidSetPortDirection(LCD_DATA_PORT , 0xff);
	
	/*Set Pins of Control Port Output*/
	DIO_VidSetPinDirection(LCD_CONTROL_PORT , RS , DIO_U8_OUTPUT);
	DIO_VidSetPinDirection(LCD_CONTROL_PORT , RW , DIO_U8_OUTPUT);
	DIO_VidSetPinDirection(LCD_CONTROL_PORT , EN , DIO_U8_OUTPUT);
	
	/*Waiting after VDD rises to 4.5V*/
	_delay_ms(35);

	/*Function  Set*/
	LCD_VidSendCommand (LCD_FUNC_SET) ;
	_delay_ms(1);
	
	/*ON/OFF Control*/
	LCD_VidSendCommand (LCD_ONOF);
	_delay_ms(1);

	/*Function Clear*/
	LCD_VidSendCommand (LCD_CLEAR);
	_delay_ms(1);

}

void LCD_vidClearDisplay ()
{
	LCD_VidSendCommand (LCD_CLEAR);
	_delay_ms(2) ;
}

