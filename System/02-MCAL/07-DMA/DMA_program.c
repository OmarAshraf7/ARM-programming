/*******************************************************************************/
/* Author		: Omar Ashraf							     				   */
/* Date 		: 28 AUG 2023								 				   */
/* Version		: V01										 				   */
/*******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void MDMA_voidChannelInit(void)
{
	/*
		Memory to memory
		Priority very high
		Source, destination size=32bit
		MINC , PINC activated
		No circular 
		Direction: peripheral to memory
		Transfer complete interrupt enable
		Channel Disable (at first) until configuration is done 
	*/
	DMA -> Channel[CHANNEL_ID - 1].CCR = 0x00007AC2;
}



void MDMA_voidChannelStart(u32* Copy_Pu32SourceAddress , u32* Copy_Pu32DestinationAddress , u16 Copy_u16BlockLength)
{
	/* Make Sure Channel is Disabled */
	CLR_BIT(DMA -> Channel[CHANNEL_ID - 1].CCR , 0);
	
	DMA -> Channel[CHANNEL_ID - 1].CPAR  = Copy_Pu32SourceAddress;
	DMA -> Channel[CHANNEL_ID - 1].CMAR  = Copy_Pu32DestinationAddress;
	DMA -> Channel[CHANNEL_ID - 1].CNDTR = Copy_u16BlockLength;
	
	/* Enable Channel */
	SET_BIT(DMA -> Channel[CHANNEL_ID - 1].CCR, 0);
}                         
                          