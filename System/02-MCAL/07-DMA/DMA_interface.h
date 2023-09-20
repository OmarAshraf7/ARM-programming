/*******************************************************************************/
/* Author		: Omar Ashraf							     				   */
/* Date 		: 28 AUG 2023								 				   */
/* Version		: V01										 				   */
/*******************************************************************************/

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void MDMA_voidChannelInit(void);

void MDMA_voidChannelStart(u32* Copy_Pu32SourceAddress , u32* Copy_Pu32DestinationAddress , u16 Copy_u16BlockLength);


#endif
