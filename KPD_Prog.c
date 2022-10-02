/**************************************************************************************************/
/**************		Auther	:	 Ahmed Amr         ************************************************/
/**************		File  	:	 Interface of KPD      ********************************************/
/**************		Date  	:	 9/9/2022              ********************************************/
/**************		Ver   	:	 V1                    ********************************************/
/**************		Desc  	:	                       ********************************************/
/**************************************************************************************************/

#include <util/delay.h>

/*Include LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*Include MCAL*/
#include "DIO_Interface.h"

/*Include HAL*/
#include "KPD_Interface.h"
#include "KPD_Config.h"
#include "KPD_Private.h"

u8 KPD_Au8Keys[4][4] = KPD_KEYS;

u8 KPD_Au8_RowPins[4] = {KPD_R1_PIN , KPD_R2_PIN , KPD_R3_PIN , KPD_R4_PIN};
u8 KPD_Au8_ColPins[4] = {KPD_C1_PIN , KPD_C2_PIN , KPD_C3_PIN , KPD_C4_PIN};


void KPD_vidInit()
{
	/* 4Pins Input And 4Pins Output */
	DIO_VidSetPortDirection(KPD_U8_PORT , KPD_U8_CONTROL);

	/* Set Port Values (4 Input Pins has a value=1 To Activate Pull Up Resistor && 4Pins values=1 (Initial Value for Output Pins )) */
	DIO_VidSetPortValue(KPD_U8_PORT , 0xff);
}


u8 KPD_U8GetPressedKey (void)
{
	u8 Local_u8RowCounter , Local_u8ColCounter , Local_u8Pressed ;
	u8 Local_u8ReturnedKey=KPD_U8_CHECK_KEY;   /* Initial Value For Key To Check if the Key Is Pressed */

	for (Local_u8RowCounter=0 ; Local_u8RowCounter<4 ; Local_u8RowCounter++)
	{
		/* Activate Each Row => For loop for pins of the rows */
		DIO_VidSetPinValue(KPD_U8_PORT , KPD_Au8_RowPins[Local_u8RowCounter] , DIO_U8_LOW);
		for (Local_u8ColCounter=0 ; Local_u8ColCounter<4 ; Local_u8ColCounter++)
		{
			/* Check Which Input Pin Has Zero (By Get Value of Each Pin in Columns) */
			Local_u8Pressed = DIO_U8GetPinValue(KPD_U8_PORT , KPD_Au8_ColPins[Local_u8ColCounter]);
			if (Local_u8Pressed == DIO_U8_LOW)
			{
				Local_u8ReturnedKey = KPD_Au8Keys[Local_u8RowCounter][Local_u8ColCounter] ;
				while(Local_u8Pressed == DIO_U8_LOW)
				{
					/* Update the value of the pin and Check if the Pin is still equal LOW  */
					Local_u8Pressed = DIO_U8GetPinValue(KPD_U8_PORT , KPD_Au8_ColPins[Local_u8ColCounter]);
				}
				_delay_ms(10);     /* Delay To Avoid Bouncing Problem */
			}
		}
		DIO_VidSetPinValue(KPD_U8_PORT , KPD_Au8_RowPins[Local_u8RowCounter] ,DIO_U8_HIGH);
	}

	return Local_u8ReturnedKey;
}
