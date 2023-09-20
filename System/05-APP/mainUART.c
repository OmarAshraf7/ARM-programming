/********************************************************************************/
/* Author		: Omar Ashraf							     					*/
/* Date 		: 08 SEP 2023								 					*/
/********************************************************************************/

#include "STD_TYPES.h"		
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "USART1_interface.h"




void main (void)
{
	u8 x = 0 ;
	/* RCC initilaization */
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_APB2 , RCC_GPIOA);
	MRCC_voidEnableClock(RCC_APB2 , RCC_USART1);
	
	/* IO pins setup */
	MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN0 , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN1 , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN2 , GPIO_OUTPUT_2M_PP);

	/* USART Tx & Rx pins setup */
	MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN9 , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN10, GPIO_INPUT_FLOATING);

	
	MUSART1_voidInit();
	
	while(1)
	{
		MUSART1_voidSendByte(10);
		x = MUSART1_u8ReceiveByte();
		if(x == 5)
		{
			MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN0 , GPIO_HIGH);
		}
		else if(x == 8)
		{
			MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN0 , GPIO_LOW);
		}
	}
}

