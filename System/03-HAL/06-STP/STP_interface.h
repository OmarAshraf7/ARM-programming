/********************************************************************************/
/* Author		: Omar Ashraf							     					*/
/* Date 		: 31 AUG 2023								 					*/
/* Version		: V02										 					*/
/********************************************************************************/

#ifndef STP_INTERFACE_H
#define STP_INTERFACE_H

/*******************************************************************************
 *                      Puplic Functions Prototypes                            *
 *******************************************************************************/

/* Initialize IO pins directions */
void HSTP_voidInit(void);
void HSTP_voidSendSynchronous(u32 Copy_u8DataToSend);

#endif
