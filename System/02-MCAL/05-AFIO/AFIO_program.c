/********************************************************************************/
/* Author		: Omar Ashraf							     					*/
/* Date 		: 18 AUG 2023								 					*/
/* Version		: V01										 					*/
/********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
 
void MAFIO_voidSetEXTI(u8 copy_u8Line , u8 copy_u8Port)
{
	u8 Local_u8RegIndex = copy_u8Line / 4 ;
	copy_u8Line %= 4 ;
	AFIO->EXTICR[Local_u8RegIndex] &= ~((0b1111) << (copy_u8Line * 4));
	AFIO->EXTICR[Local_u8RegIndex]  |= ((copy_u8Port) << (copy_u8Line * 4));
}
