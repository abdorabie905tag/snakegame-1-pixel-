/**************************************************************************************************/
/**************		Auther	:	 Ahmed Amr         ************************************************/
/**************		File  	:	 Interface of DIO      ********************************************/
/**************		Date  	:	 9/3/2022             *********************************************/
/**************		Ver   	:	 V1                    ********************************************/
/**************		Desc  	:	                       ********************************************/
/**************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"

void DIO_VidSetPinDirection(u8 Copy_U8Port , u8 Copy_U8Pin , u8 Copy_U8Direction)
{
	if (DIO_U8_OUTPUT == Copy_U8Direction)
	{
		switch ( Copy_U8Port)
		{
			case DIO_U8_PORTA :	SET_BIT(DDRA_REG,Copy_U8Pin);  break ;
			case DIO_U8_PORTB :	SET_BIT(DDRB_REG,Copy_U8Pin);  break ;
			case DIO_U8_PORTC :	SET_BIT(DDRC_REG,Copy_U8Pin);  break ;
			case DIO_U8_PORTD :	SET_BIT(DDRD_REG,Copy_U8Pin);  break ;
		}
	}
	else if(DIO_U8_INPUT == Copy_U8Direction)
	{
		switch ( Copy_U8Port)
		{
			case DIO_U8_PORTA :	CLR_BIT(DDRA_REG,Copy_U8Pin);  break ;
			case DIO_U8_PORTB :	CLR_BIT(DDRB_REG,Copy_U8Pin);  break ;
			case DIO_U8_PORTC :	CLR_BIT(DDRC_REG,Copy_U8Pin);  break ;
			case DIO_U8_PORTD :	CLR_BIT(DDRD_REG,Copy_U8Pin);  break ;
		}
	}
}

void DIO_VidSetPinValue(u8 Copy_U8Port , u8 Copy_U8Pin , u8 Copy_U8Value)
{
	if (DIO_U8_HIGH == Copy_U8Value)
	{
		switch ( Copy_U8Port)
		{
			case DIO_U8_PORTA :	SET_BIT(PORTA_REG, Copy_U8Pin);  break ;
			case DIO_U8_PORTB :	SET_BIT(PORTB_REG, Copy_U8Pin);  break ;
			case DIO_U8_PORTC :	SET_BIT(PORTC_REG, Copy_U8Pin);  break ;
			case DIO_U8_PORTD :	SET_BIT(PORTD_REG, Copy_U8Pin);  break ;
		}
	}
	else if(DIO_U8_LOW == Copy_U8Value)
	{
		switch ( Copy_U8Port)
		{
			case DIO_U8_PORTA :	CLR_BIT(PORTA_REG,Copy_U8Pin);  break ;
			case DIO_U8_PORTB :	CLR_BIT(PORTB_REG,Copy_U8Pin);  break ;
			case DIO_U8_PORTC :	CLR_BIT(PORTC_REG,Copy_U8Pin);  break ;
			case DIO_U8_PORTD :	CLR_BIT(PORTD_REG,Copy_U8Pin);  break ;
		}
	}
}

u8 DIO_U8GetPinValue(u8 Copy_U8Port , u8 Copy_U8Pin)
{
	switch (Copy_U8Port)
	{
		case DIO_U8_PORTA :	return GET_BIT(PINA_REG,Copy_U8Pin) ;
		case DIO_U8_PORTB :	return GET_BIT(PINB_REG,Copy_U8Pin) ;
		case DIO_U8_PORTC :	return GET_BIT(PINC_REG,Copy_U8Pin) ;
		case DIO_U8_PORTD :	return GET_BIT(PIND_REG,Copy_U8Pin) ;
	}
}

void DIO_VidTogglePinValue(u8 Copy_U8Port , u8 Copy_U8Pin)
{
	switch (Copy_U8Port)
	{
		case DIO_U8_PORTA :   TOGGLE_BIT(PORTA_REG,Copy_U8Pin);  break ;
		case DIO_U8_PORTB :   TOGGLE_BIT(PORTB_REG,Copy_U8Pin);  break ;
		case DIO_U8_PORTC :   TOGGLE_BIT(PORTC_REG,Copy_U8Pin);  break ;
		case DIO_U8_PORTD :   TOGGLE_BIT(PORTD_REG,Copy_U8Pin);  break ;
	}
}

void DIO_VidSetPortDirection(u8 Copy_U8Port , u8 Copy_U8Direction)
{
		switch (Copy_U8Port)
		{
			case DIO_U8_PORTA : DDRA_REG = Copy_U8Direction ; break ;
			case DIO_U8_PORTB : DDRB_REG = Copy_U8Direction ; break ;
			case DIO_U8_PORTC : DDRC_REG = Copy_U8Direction ; break ;
			case DIO_U8_PORTD : DDRD_REG = Copy_U8Direction ; break ;
		}
	
}

void DIO_VidSetPortValue(u8 Copy_U8Port , u8 Copy_U8Value)
{
	switch (Copy_U8Port)
		{
			case DIO_U8_PORTA : PORTA_REG = Copy_U8Value ; break ;
			case DIO_U8_PORTB : PORTB_REG = Copy_U8Value ; break ;
			case DIO_U8_PORTC : PORTC_REG = Copy_U8Value ; break ;
			case DIO_U8_PORTD : PORTD_REG = Copy_U8Value ; break ;
		}
}

u8 DIO_U8GetPortValue(u8 Copy_U8Port)
{
	switch (Copy_U8Port)
		{
			case DIO_U8_PORTA :  return  PINA_REG ;
			case DIO_U8_PORTB :  return  PINB_REG ;
			case DIO_U8_PORTC :  return  PINC_REG ;
			case DIO_U8_PORTD :  return  PIND_REG ;
		}
}
