/********************************************************************************/
/* Author		: Omar Ashraf							     					*/
/* Date 		: 22 AUG 2023								 					*/
/* Version		: V01										 					*/
/********************************************************************************/

#include "STD_TYPES.h"		
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

#define NULL						  (void*) 0

/* Array of tasks (Array of structures) */
static Task OS_Tasks[NUMBER_OF_TASKS] = {NULL};

volatile u16 TickCounts = 0; 

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void OS_voidCreateTask(u8 Copy_u8TaskID, u16 Copy_u16Periodicity, void (*ptr) (void) , u8 Copy_u8FirstDelay , u8 Copy_u8State )
{
	OS_Tasks[Copy_u8TaskID].Periodicity = Copy_u16Periodicity;
	OS_Tasks[Copy_u8TaskID].Fptr  	    = ptr;
	OS_Tasks[Copy_u8TaskID].FirstDelay  = Copy_u8FirstDelay;
	OS_Tasks[Copy_u8TaskID].State 	    = Copy_u8State;
}


void OS_voidStart(void)
{
	/* STK init */
	 MSTK_voidInit();
	 /* Tick time -> 1ms */
	 MSTK_voidSetIntervalPeriodic(1000,Scheduler);
}

void Scheduler (void)
{
	for(Local_u8Counter = 0 ; Local_u8Counter < NUMBER_OF_TASKS ; Local_u8Counter++)
	{
		if( (OS_Tasks[Local_u8Counter].Fptr != NULL) && (OS_Tasks[Local_u8Counter].State == TASK_READY) )
		{
			if(OS_Tasks[Local_u8Counter].FirstDelay == 0)
			{
				OS_Tasks[Local_u8Counter].FirstDelay = OS_Tasks[Local_u8Counter].Periodicity - 1;
				OS_Tasks[Local_u8Counter].Fptr();
			}
			else
			{
				OS_Tasks[Local_u8Counter].FirstDelay --;
			}
		}
	}
}


void OS_voidSuspendTask(u8 Copy_u8TaskID)
{
	OS_Tasks[Copy_u8TaskID].State = TASK_PAUSE;
}



void OS_voidResumeTask (u8 Copy_u8TaskID)
{
	OS_Tasks[Copy_u8TaskID].State = TASK_READY;
}


void OS_voidKillTask(u8 Copy_u8TaskID)
{
	OS_Tasks[Copy_u8TaskID].Periodicity = 0;
	OS_Tasks[Copy_u8TaskID].Fptr  	    = NULL;
	OS_Tasks[Copy_u8TaskID].FirstDelay  = 0;
	OS_Tasks[Copy_u8TaskID].State 	    = TASK_DELETE;
}