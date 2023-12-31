/********************************************************************************/
/* Author		: Omar Ashraf							     					*/
/* Date 		: 21 AUG 2023								 					*/
/* Version		: V02										 					*/
/********************************************************************************/

#include "STD_TYPES.h"		
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"

#define NULL		(void*)0
u8 *HLEDMAT_u8Frame = NULL;
volatile u8 HLEDMAT_u8CurrentIdx = 0;


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void HLEDMRX_voidInit(void)
{
	MGPIO_voidSetPinDirection(LEDMRX_ROW_PORT, LEDMRX_ROW0_PIN , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW_PORT, LEDMRX_ROW1_PIN , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW_PORT, LEDMRX_ROW2_PIN , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW_PORT, LEDMRX_ROW3_PIN , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW_PORT, LEDMRX_ROW4_PIN , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW_PORT, LEDMRX_ROW5_PIN , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW_PORT, LEDMRX_ROW6_PIN , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW_PORT, LEDMRX_ROW7_PIN , GPIO_OUTPUT_2M_PP);
	
	
	MGPIO_voidSetPinDirection(LEDMRX_COL_PORT, LEDMRX_COL0_PIN , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL_PORT, LEDMRX_COL1_PIN , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL_PORT, LEDMRX_COL2_PIN , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL_PORT, LEDMRX_COL3_PIN , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL_PORT, LEDMRX_COL4_PIN , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL_PORT, LEDMRX_COL5_PIN , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL_PORT, LEDMRX_COL6_PIN , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL_PORT, LEDMRX_COL7_PIN , GPIO_OUTPUT_2M_PP);
}


void HLEDMRX_voidDisplay(u8 *Copy_u8Data)
{
		/* Save the desired Frame */	
		HLEDMAT_u8Frame = Copy_u8Data;
		
		/* Reset the frame Start */
		HLEDMAT_u8CurrentIdx = 0;
		
		DisableAllColumns();
		SetRowValues(HLEDMAT_u8Frame[HLEDMAT_u8CurrentIdx]);
		Activate_Column(HLEDMAT_u8CurrentIdx);
		MSTK_voidSetIntervalPeriodic(2500,DisplayNextColumn); 

}

static void DisableAllColumns(void)
{
	MGPIO_voidSetPinValue(LEDMRX_COL_PORT , LEDMRX_COL0_PIN , GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL_PORT , LEDMRX_COL1_PIN , GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL_PORT , LEDMRX_COL2_PIN , GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL_PORT , LEDMRX_COL3_PIN , GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL_PORT , LEDMRX_COL4_PIN , GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL_PORT , LEDMRX_COL5_PIN , GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL_PORT , LEDMRX_COL6_PIN , GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL_PORT , LEDMRX_COL7_PIN , GPIO_HIGH);	
}

static void SetRowValues(u8 Copy_u8Value)
{
	u8 Local_u8RowBit[8] = {0};
	u8 Local_u8Counter = 0;
	for(Local_u8Counter=0 ; Local_u8Counter < 8 ; Local_u8Counter++)
	{
		Local_u8RowBit[Local_u8Counter] = GET_BIT(Copy_u8Value , Local_u8Counter);
	}

	MGPIO_voidSetPinValue(LEDMRX_ROW_PORT , LEDMRX_ROW0_PIN , Local_u8RowBit[0]);
	MGPIO_voidSetPinValue(LEDMRX_ROW_PORT , LEDMRX_ROW1_PIN , Local_u8RowBit[1]);
	MGPIO_voidSetPinValue(LEDMRX_ROW_PORT , LEDMRX_ROW2_PIN , Local_u8RowBit[2]);
	MGPIO_voidSetPinValue(LEDMRX_ROW_PORT , LEDMRX_ROW3_PIN , Local_u8RowBit[3]);
	MGPIO_voidSetPinValue(LEDMRX_ROW_PORT , LEDMRX_ROW4_PIN , Local_u8RowBit[4]);
	MGPIO_voidSetPinValue(LEDMRX_ROW_PORT , LEDMRX_ROW5_PIN , Local_u8RowBit[5]);
	MGPIO_voidSetPinValue(LEDMRX_ROW_PORT , LEDMRX_ROW6_PIN , Local_u8RowBit[6]);
	MGPIO_voidSetPinValue(LEDMRX_ROW_PORT , LEDMRX_ROW7_PIN , Local_u8RowBit[7]);	
}


static void Activate_Column(u8 Copy_u8Col)
{
	switch(Copy_u8Col)
	{
	case 0: MGPIO_voidSetPinValue(LEDMRX_COL_PORT , LEDMRX_COL0_PIN , GPIO_LOW);  break;
	case 1: MGPIO_voidSetPinValue(LEDMRX_COL_PORT , LEDMRX_COL1_PIN , GPIO_LOW);  break;
	case 2: MGPIO_voidSetPinValue(LEDMRX_COL_PORT , LEDMRX_COL2_PIN , GPIO_LOW);  break;
	case 3: MGPIO_voidSetPinValue(LEDMRX_COL_PORT , LEDMRX_COL3_PIN , GPIO_LOW);  break;
	case 4: MGPIO_voidSetPinValue(LEDMRX_COL_PORT , LEDMRX_COL4_PIN , GPIO_LOW);  break;
	case 5: MGPIO_voidSetPinValue(LEDMRX_COL_PORT , LEDMRX_COL5_PIN , GPIO_LOW);  break;
	case 6: MGPIO_voidSetPinValue(LEDMRX_COL_PORT , LEDMRX_COL6_PIN , GPIO_LOW);  break;
	case 7: MGPIO_voidSetPinValue(LEDMRX_COL_PORT , LEDMRX_COL7_PIN , GPIO_LOW);  break;
	}
}


static void DisplayNextColumn(void)
{
	HLEDMAT_u8CurrentIdx++;
	if (HLEDMAT_u8CurrentIdx == 8)
	{
		HLEDMAT_u8CurrentIdx = 0;
	}
	
	DisableAllColumns();
	SetRowValues(HLEDMAT_u8Frame[HLEDMAT_u8CurrentIdx]);
	Activate_Column(HLEDMAT_u8CurrentIdx); 

}


