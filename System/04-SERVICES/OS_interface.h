/********************************************************************************/
/* Author		: Omar Ashraf							     					*/
/* Date 		: 22 AUG 2023								 					*/
/* Version		: V01										 					*/
/********************************************************************************/

#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

/*******************************************************************************
 *                      Public Functions Prototypes                            *
 *******************************************************************************/

/* NOTE: Copy_u8TaskID refer to the task Priority */
void OS_voidCreateTask(u8 Copy_u8TaskID , u16 Copy_u16Periodicity , void (*ptr)(void) , u8 Copy_u8FirstDelay , u8 Copy_u8State );
void OS_voidStart(void);
void OS_voidSuspendTask(u8 Copy_u8TaskID);
void OS_voidResumeTask (u8 Copy_u8TaskID);
void OS_voidKillTask   (u8 Copy_u8TaskID);


/* Task States */
#define TASK_READY		0
#define TASK_PAUSE		1
#define TASK_DELETE		2


#endif