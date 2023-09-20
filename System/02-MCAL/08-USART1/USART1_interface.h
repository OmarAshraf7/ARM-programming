/*******************************************************************************/
/* Author		: Omar Ashraf							     				   */
/* Date 		: 09 SEP 2023								 				   */
/* Version		: V02										 				   */
/*******************************************************************************/

#ifndef USART1_INTERFACE_H
#define USART1_INTERFACE_H


/*******************************************************************************
 *                    Configuration structure Options 		                   *
 *******************************************************************************/

typedef enum
{
	EIGHT, NINE
}USART_DataSize;

typedef enum
{
	DISABLED, ENABLED
}USART_ParityState;

typedef enum
{
	NOPARITY , EVEN = 0 , ODD
}USART_ParityType;

typedef enum
{
	ONE,HALF,TWO,ONEHALF
}USART_StopBit;


/*******************************************************************************
 *                      Configuration Structure                                *
 *******************************************************************************/

typedef struct
{
	USART_DataSize 	  data_size;
	USART_ParityState parity_state;
	USART_ParityType  parity_type;
	USART_StopBit 	  stop_bit;
}USART_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
 
void MUSART1_voidInit   	   (const USART_ConfigType *Config_Ptr);
void MUSART1_voidSendByte      (const u8 Copy_u8Data);
u8	 MUSART1_u8ReceiveByte 	   (void);
void MUSART1_voidSendString	   (const u8 *Copy_Str);
void MUSART1_voidReceiveString (u8 *Copy_Str);



#endif

