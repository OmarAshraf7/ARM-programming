/*******************************************************************************/
/* Author		: Omar Ashraf							     				   */
/* Date 		: 09 SEP 2023								 				   */
/* Version		: V02										 				   */
/*******************************************************************************/

#ifndef USART1_CONFIG_H
#define USART1_CONFIG_H


/* 
   for Init function argument : configuration structure address
   configuration structure is a Post-build Configuration (Configuration in Run Time)  
   
   DataSize Options:    EIGHT, NINE
   ParityState Options: DISABLED, ENABLED
   ParityType Options:  NOPARITY , EVEN , ODD
   StopBit Options:     ONE , HALF , TWO , ONEHALF

   Example:
   USART_ConfigType USART_config   = {EIGHT , DISABLED , NOPARITY , ONE };
   MUSART1_voidInit(&USART_config);
*/



#endif
