/**************************************************************************************************/
/**************		Auther	:	 Ahmed Amr         ************************************************/
/**************		File  	:	 Interface of DIO      ********************************************/
/**************		Date  	:	 9/3/2022             *********************************************/
/**************		Ver   	:	 V1                    ********************************************/
/**************		Desc  	:	                       ********************************************/
/**************************************************************************************************/

#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/*Group of DDR Registers*/

#define DDRA_REG      *((u8*)0x3A)
#define DDRB_REG      *((u8*)0x37)
#define DDRC_REG      *((u8*)0x34)
#define DDRD_REG      *((u8*)0x31)

/*Group of PORT Registers*/

#define PORTA_REG     *((u8*)0x3B)
#define PORTB_REG     *((u8*)0x38)
#define PORTC_REG     *((u8*)0x35)
#define PORTD_REG     *((u8*)0x32)

/*Group of PIN Registers*/

#define PINA_REG      *((volatile u8*)0x39)
#define PINB_REG      *((volatile u8*)0x36)
#define PINC_REG      *((volatile u8*)0x33)
#define PIND_REG      *((volatile u8*)0x30)


#endif
