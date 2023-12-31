/*******************************************************************************/
/* Author		: Omar Ashraf							     				   */
/* Date 		: 28 AUG 2023								 				   */
/* Version		: V01										 				   */
/*******************************************************************************/

#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

/*******************************************************************************
 *                      Global variables Definitions                           *
 *******************************************************************************/



/**********************************************************	*********************
 *                      Registers Definitions                                  *
 *******************************************************************************/

typedef struct
{
	volatile u32 CCR  ;
	volatile u32 CNDTR;
	volatile u32 CPAR ;
	volatile u32 CMAR ;
	volatile u32 Reserved;
}DMA_Channel;


typedef struct 
{
	volatile u32 ISR;
	volatile u32 IFCR;
	DMA_Channel Channel[7];
}DMA_Type;

#define 	DMA 	((volatile DMA_Type*)0x40020000)


/*******************************************************************************
 *                      Hash Defines For Conguration                           *
 *******************************************************************************/


#endif
