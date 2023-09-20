/********************************************************************************/
/* Author		: Omar Ashraf							     					*/
/* Date 		: 21 AUG 2023								 					*/
/* Version		: V01										 					*/
/********************************************************************************/

#include "STD_TYPES.h"		
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"


#include "IR_interface.h"
#include "IR_private.h"
#include "IR_config.h"

volatile u8  StartFlag_u8      =  0;
volatile u32 FrameData_u32[50] = {0};
volatile u8  EdgeCounter_u8    =  0;
volatile u8  Data_u8           =  0;

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void HIR_voidInit(void)
{	
	/* IO pin Initialization for the IR output pin */
	MGPIO_voidSetPinDirection(HIR_OUT_PORT, HIR_OUT_PIN , GPIO_INPUT_FLOATING);
	
	/* EXTI Initialization */
	MEXTI_voidSetCallBack(GetIRFrame);
	MEXTI_voidSetSignalLatch(EXTI_FALLING_EDGE, EXTI_LINE0);
	MAFIO_voidSetEXTI(HIR_OUT_PIN , HIR_OUT_PORT); 
	/* NOTE: Input arguments above has same Definitions of AFIO hashes */

	/* Enable EXTI0 from NVIC */
	MNVIC_voidEnableInterrupt(NVIC_EXTI0);

	/* Initialize STK */
	MSTK_voidInit();
}

static void GetIRFrame(void)
{
	if (StartFlag_u8 == 0)
	{
		MSTK_voidSetIntervalSingle(500000, TakeAction);
		StartFlag_u8 = 1;
	}
	else
	{
		FrameData_u32[EdgeCounter_u8] = MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(500000, TakeAction);
		EdgeCounter_u8++;
	}

}

static void TakeAction(void)
{
	u8 i;
	Data_u8  = 0;
	/* Check the Start Bit  */
	/* If the condition is true that means it's valid frame */
	if( (FrameData_u32[0] >= 9000) &&  (FrameData_u32[0] <= 15000) )
	{
		/* Count from 0 to 8 because the frame [17] (the beginning of data) is LSB */
		for (i=0 ; i<8 ; i++)
		{
			if( (FrameData_u32[17+i] >= 2000) && (FrameData_u32[17+i] <2600) )
			{
				SET_BIT(Data_u8 , i);
			}
			else
			{
				CLR_BIT(Data_u8 , i);
			}
		}
		Play();
	}
	else
	{
		/* Invalid Frame */
	}

	/* End of action for a button click */
	StartFlag_u8     = 0;
	FrameData_u32[0] = 0;
    EdgeCounter_u8   = 0;

    /* Ready to receive new IR from a new button  */
}


void Play(void)
{
	switch(Data_u8)
	{
		case HIR_DATA_VAL1: /* Write the action you want it done here */break; 
		case HIR_DATA_VAL2: 	break;
		case HIR_DATA_VAL3: 	break;
		case HIR_DATA_VAL4: 	break;
		case HIR_DATA_VAL5: 	break;
		case HIR_DATA_VAL6: 	break;

		default : break;
	}
} 


