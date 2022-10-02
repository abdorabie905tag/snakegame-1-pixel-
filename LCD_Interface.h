/**************************************************************************************************/
/**************		Auther	:	 Ahmed Amr         ************************************************/
/**************		File  	:	 Interface of LCD      ********************************************/
/**************		Date  	:	 9/10/2022             ********************************************/
/**************		Ver   	:	 V1                    ********************************************/
/**************		Desc  	:	                       ********************************************/
/**************************************************************************************************/

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*MACROS For LCD Line*/
#define 	LCD_U8_LINE1 			1
#define 	LCD_U8_LINE2 			2

/*Functions*/

void	 LCD_VidInit			();
void	 LCD_VidSendCommand 	(u8 Copy_U8Command);
void	 LCD_VidSendChar 		(u8 Copy_U8Data);
void	 LCD_VidSendString 		(u8 *Copy_U8String);
void 	 LCD_vidSendNumber		(u32 Copy_u32Number);
void 	 LCD_VidSetLocation 	(u8 Copy_U8LineNum , u8 Copy_U8CharNum);
void 	LCD_vidSetCharLocation	(u8 Copy_u8Location);
void	 LCD_vidClearDisplay	();
void 	 LCD_VidDrawSpecialChar (u8 Copy_U8CharAddress , u8 *Copy_U8SpecialChar) ;
void 	 LCD_VidSendSpecialChar	(u8 Copy_U8CharAddress , u8 Copy_U8LineNum , u8 Copy_U8CharNum) ;

#endif
