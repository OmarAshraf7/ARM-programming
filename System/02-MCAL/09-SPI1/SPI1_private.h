/*******************************************************************************/
/* Author		: Omar Ashraf							     				   */
/* Date 		: 10 SEP 2023								 				   */
/* Version		: V01										 				   */
/*******************************************************************************/

#ifndef SPI1_PRIVATE_H
#define SPI1_PRIVATE_H

#define NULL	(void * )0

/*******************************************************************************
 *                      Global variables Definitions                           *
 *******************************************************************************/
 
static void (* SPI1_CallBack) (void) = NULL ;

/*******************************************************************************
 *                      Registers Definitions                                  *
 *******************************************************************************/

typedef struct 
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 CRCPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;	
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;
}SPI_t;


#define SPI1 ((volatile SPI_t *) 0x40013000)




#endif
