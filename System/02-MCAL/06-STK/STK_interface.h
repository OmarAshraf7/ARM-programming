/*******************************************************************************/
/* Author		: Omar Ashraf							     				   */
/* Date 		: 15 AUG 2023								 				   */
/* Version		: V01										 				   */
/*******************************************************************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
 
void MSTK_voidInit(void);
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks); 			
void MSTK_voidSetIntervalSingle  (u32 Copy_u32Ticks , void (*Copy_ptr)(void) );	
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*Copy_ptr)(void) );	
void MSTK_voidStopTimer(void);
u32  MSTK_u32GetElapsedTime(void);
u32  MSTK_u32GetRemainingTime(void);

#endif
