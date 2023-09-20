/********************************************************************************/
/* Author		: Omar Ashraf							     					*/
/* Date 		: 29 AUG 2023								 					*/
/********************************************************************************/

#include "STD_TYPES.h"		
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "DMA_interface.h"
#include "DMA_private.h" /**/


void main (void)
{
	u32 Arr1[1000] = {0};
	u32 Arr2[1000] ;

	u32 Arr3[1000] = {0};
	u32 Arr4[1000] ;
	
	/* RCC initilaization */
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_AHB , RCC_DMA1);

	MNVIC_voidEnableInterrupt(NVIC_DMA1_Channel1);

	MDMA_voidChannelInit();
	MDMA_voidChannelStart(Arr1 , Arr2 , 1000);
	
	for(u16 i = 0 ; i <1000 ; i++)
	{
		Arr4[i] = Arr3[i];
	}
	
	
	while(1)
	{
		
	}
}

void DMA1_Channel1_IRQHandler(void)
{
	/* Clear Flags :GIF , TC */
	DMA -> IFCR = 0x00000003;
}
