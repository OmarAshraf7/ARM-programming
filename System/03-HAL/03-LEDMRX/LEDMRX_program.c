/********************************************************************************/
/* Author		: Omar Ashraf							     					*/
/* Date 		: 18 AUG 2023								 					*/
/* Version		: V01										 					*/
/********************************************************************************/

#include "STD_TYPES.h"		
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"

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
	while(1)
	{
		/* Column 0 */
		DisableAllColumns();
		SetRawValues(Copy_u8Data[0]);
		MGPIO_voidSetPinValue(LEDMRX_COL_PORT , LEDMRX_COL0_PIN , GPIO_LOW);
		MSTK_voidSetBusyWait(2500); /* 2.5ms delay */
		
		
		/* Column 1 */
		DisableAllColumns();
		SetRawValues(Copy_u8Data[1]);
		MGPIO_voidSetPinValue(LEDMRX_COL_PORT , LEDMRX_COL1_PIN , GPIO_LOW);
		MSTK_voidSetBusyWait(2500); /* 2.5ms delay */
		
		
		/* Column 2 */
		DisableAllColumns();
		SetRawValues(Copy_u8Data[2]);
		MGPIO_voidSetPinValue(LEDMRX_COL_PORT , LEDMRX_COL2_PIN , GPIO_LOW);
		MSTK_voidSetBusyWait(2500); /* 2.5ms delay */
		
		/* Column 3 */
		DisableAllColumns();
		SetRawValues(Copy_u8Data[3]);
		MGPIO_voidSetPinValue(LEDMRX_COL_PORT , LEDMRX_COL3_PIN , GPIO_LOW);
		MSTK_voidSetBusyWait(2500); /* 2.5ms delay */
		
		/* Column 4 */
		DisableAllColumns();
		SetRawValues(Copy_u8Data[4]);
		MGPIO_voidSetPinValue(LEDMRX_COL_PORT , LEDMRX_COL4_PIN , GPIO_LOW);
		MSTK_voidSetBusyWait(2500); /* 2.5ms delay */
	
		/* Column 5 */
		DisableAllColumns();
		SetRawValues(Copy_u8Data[5]);
		MGPIO_voidSetPinValue(LEDMRX_COL_PORT , LEDMRX_COL5_PIN , GPIO_LOW);
		MSTK_voidSetBusyWait(2500); /* 2.5ms delay */
	
		/* Column 6 */
		DisableAllColumns();
		SetRawValues(Copy_u8Data[6]);
		MGPIO_voidSetPinValue(LEDMRX_COL_PORT , LEDMRX_COL6_PIN , GPIO_LOW);
		MSTK_voidSetBusyWait(2500); /* 2.5ms delay */
	
		/* Column 7 */
		DisableAllColumns();
		SetRawValues(Copy_u8Data[7]);
		MGPIO_voidSetPinValue(LEDMRX_COL_PORT , LEDMRX_COL7_PIN , GPIO_LOW);
		MSTK_voidSetBusyWait(2500); /* 2.5ms delay */	
		
		
	}
	
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

static void SetRawValues(u8 Copy_u8Value)
{
	u8 Local_u8RowBit = 0;
	
	Local_u8RowBit = GET_BIT(Copy_u8Value , 0);
	MGPIO_voidSetPinValue(LEDMRX_ROW_PORT , LEDMRX_ROW0_PIN , Local_u8RowBit);

	Local_u8RowBit = GET_BIT(Copy_u8Value , 1);
	MGPIO_voidSetPinValue(LEDMRX_ROW_PORT , LEDMRX_ROW1_PIN , Local_u8RowBit);

	Local_u8RowBit = GET_BIT(Copy_u8Value , 2);
	MGPIO_voidSetPinValue(LEDMRX_ROW_PORT , LEDMRX_ROW2_PIN , Local_u8RowBit);

	Local_u8RowBit = GET_BIT(Copy_u8Value , 3);
	MGPIO_voidSetPinValue(LEDMRX_ROW_PORT , LEDMRX_ROW3_PIN , Local_u8RowBit);

	Local_u8RowBit = GET_BIT(Copy_u8Value , 4);
	MGPIO_voidSetPinValue(LEDMRX_ROW_PORT , LEDMRX_ROW4_PIN , Local_u8RowBit);

	Local_u8RowBit = GET_BIT(Copy_u8Value , 5);
	MGPIO_voidSetPinValue(LEDMRX_ROW_PORT , LEDMRX_ROW5_PIN , Local_u8RowBit);

	Local_u8RowBit = GET_BIT(Copy_u8Value , 6);
	MGPIO_voidSetPinValue(LEDMRX_ROW_PORT , LEDMRX_ROW6_PIN , Local_u8RowBit);

	Local_u8RowBit = GET_BIT(Copy_u8Value , 7);
	MGPIO_voidSetPinValue(LEDMRX_ROW_PORT , LEDMRX_ROW7_PIN , Local_u8RowBit);	
}

