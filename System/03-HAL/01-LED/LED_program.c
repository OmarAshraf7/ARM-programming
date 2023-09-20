/*************************************************************/
/* Author		: Omar Ashraf							     */
/* Date 		: 30 JUL 2023								 */
/* Version		: V01										 */
/*************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

void LED_voidON ( u8 copy_u8Port , u8 copy_u8Pin )
{
	MGPIO_voidSetPinValue	  ( copy_u8Port , copy_u8Pin , GPIO_HIGH);
}

void LED_voidOFF ( u8 copy_u8Port , u8 copy_u8Pin )
{
	MGPIO_voidSetPinValue	  ( copy_u8Port , copy_u8Pin , GPIO_LOW);
}

void LED_voidTOGGLE ( u8 copy_u8Port , u8 copy_u8Pin )
{
	u8 Local_u8 = 0;
	Local_u8 = MGPIO_u8GetPinValue(copy_u8Port , copy_u8Pin);
	MGPIO_voidSetPinValue (copy_u8Port , copy_u8Pin , TOG_BIT(Local_u8,0) );
}

