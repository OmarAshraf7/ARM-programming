/*******************************************************************************/
/* Author		: Omar Ashraf							     				   */
/* Date 		: 09 SEP 2023								 				   */
/* Version		: V02										 				   */
/*******************************************************************************/

#ifndef USART1_PRIVATE_H
#define USART1_PRIVATE_H

/*******************************************************************************
 *                      Registers Definitions                                  *
 *******************************************************************************/

typedef struct 
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;	
}USART_t;


#define USART1 ((volatile USART_t *) 0x40013800)



#endif
