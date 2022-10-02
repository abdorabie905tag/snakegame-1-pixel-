/**************************************************************************************************/
/**************		Auther	:	 Ahmed Amr         ************************************************/
/**************		File  	:	 Interface of KPD      ********************************************/
/**************		Date  	:	 9/9/2022              ********************************************/
/**************		Ver   	:	 V1                    ********************************************/
/**************		Desc  	:	                       ********************************************/
/**************************************************************************************************/

/* File Guard */
#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H

/*Select KPD Port*/
#define 	KPD_U8_PORT 		DIO_U8_PORTA


/*******************************
 *                             *
 * Options :                   *
 * 1- KPD_INPUTROWS_OUTPUTCOL  *
 * 2- KPD_OUTPUTROWS_INPUTCOL  *
 *							   *
 *******************************/
 
#define    KPD_U8_CONTROL    KPD_OUTPUTROWS_INPUTCOL


/* Row Pins For KPD */
#define    KPD_R1_PIN        DIO_U8_PIN1
#define    KPD_R2_PIN        DIO_U8_PIN2
#define    KPD_R3_PIN        DIO_U8_PIN3
#define    KPD_R4_PIN        DIO_U8_PIN4

/* Column Pins For KPD */
#define    KPD_C1_PIN        DIO_U8_PIN5
#define    KPD_C2_PIN        DIO_U8_PIN6
#define    KPD_C3_PIN        DIO_U8_PIN7
#define    KPD_C4_PIN        DIO_U8_PIN8

/*Definition KPD Keys*/
#define    KPD_KEYS    		 {{'1','2','3','-'}, \
							  {'4','5','6','+'},  \
						   	  {'7','8','9','C'},  \
							  {'*','0','=','/'}}


#endif

