/********************************************************************************/
/* Author		: Omar Ashraf							     					*/
/* Date 		: 28 JUL 2023								 					*/
/* Version		: V01										 					*/
/********************************************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H
 
/* Options:    RCC_HSE_CRYSTAL
               RCC_HSE_RC
               RCC_HSI
               RCC_PLL			   */
			   
#define RCC_CLOCK_TYPE    RCC_HSE_CRYSTAL



/* Note: Select value only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL

/* Options:     RCC_PLL_HSI_DIV_2	
                RCC_PLL_HSE_DIV_2	
				RCC_PLL_HSE		    */
				
#define RCC_PLL_INPUT     RCC_PLL_IN_HSE_DIV_2

/* Options: 2 to 16 */
#define RCC_PLL_MUL_VAL   4

#endif 



#endif