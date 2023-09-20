/********************************************************************************/
/* Author		: Omar Ashraf							     					*/
/* Date 		: 22 AUG 2023								 					*/
/********************************************************************************/

#include "STD_TYPES.h"		
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "OS_interface.h"
#include "LED_interface.h"

void LED1 (void);
void LED2 (void);
void LED3 (void);


void main (void)
{
	/* RCC initilaization */
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_APB2 , RCC_GPIOA);
	
	/* IO pins setup */
	MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN0 , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN1 , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN2 , GPIO_OUTPUT_2M_PP);

	
	/* OS Init */
	OS_voidCreateTask(0 , 1000 , LED1);
	
	OS_voidCreateTask(1 , 2000 , LED2);

	OS_voidCreateTask(2 , 3000 , LED3);
	
	OS_voidStart();
	
	while(1)
	{
		
	}
}



void LED1 (void)
{
	LED_voidTOGGLE(LED_GPIOA, LED_PIN0);
}


void LED2 (void)
{
	LED_voidTOGGLE(LED_GPIOA, LED_PIN1);
}


void LED3 (void)
{
	LED_voidTOGGLE(LED_GPIOA, LED_PIN2);
}