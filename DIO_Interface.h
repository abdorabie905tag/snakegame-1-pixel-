/**************************************************************************************************/
/**************		Auther	:	 Ahmed Amr         ************************************************/
/**************		File  	:	 Interface of DIO      ********************************************/
/**************		Date  	:	 9/3/2022             *********************************************/
/**************		Ver   	:	 V1                    ********************************************/
/**************		Desc  	:	                       ********************************************/
/**************************************************************************************************/

#include "STD_TYPES.h"
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/*Macros for Direction*/

#define  DIO_U8_OUTPUT   1
#define  DIO_U8_INPUT    0

/*Macros for Signals*/

#define 	 DIO_U8_HIGH      1
#define 	 DIO_U8_LOW       0

/*Macros for Port number*/

#define 	 DIO_U8_PORTA	  0
#define 	 DIO_U8_PORTB	  1
#define 	 DIO_U8_PORTC	  2
#define 	 DIO_U8_PORTD	  3

/*Macros for Port number*/

#define 	 DIO_U8_PIN1	  0
#define 	 DIO_U8_PIN2	  1
#define 	 DIO_U8_PIN3	  2
#define 	 DIO_U8_PIN4	  3
#define 	 DIO_U8_PIN5	  4
#define 	 DIO_U8_PIN6	  5
#define 	 DIO_U8_PIN7	  6
#define 	 DIO_U8_PIN8	  7


/*Functions*/

void DIO_VidSetPinDirection(u8 Copy_U8Port , u8 Copy_U8Pin , u8 Copy_U8Direction);

void DIO_VidSetPinValue(u8 Copy_U8Port , u8 Copy_U8Pin , u8 Copy_U8Value);

u8 DIO_U8GetPinValue(u8 Copy_U8Port , u8 Copy_U8Pin);

void DIO_VidTogglePinValue(u8 Copy_U8Port , u8 Copy_U8Pin);

void DIO_VidSetPortDirection(u8 Copy_U8Port , u8 Copy_U8Direction);

void DIO_VidSetPortValue(u8 Copy_U8Port , u8 Copy_U8Value);

u8 DIO_U8GetPortValue(u8 Copy_U8Port);


#endif
