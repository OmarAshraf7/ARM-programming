/********************************************************************************/
/* Author		: Omar Ashraf							     					*/
/* Date 		: 22 AUG 2023								 					*/
/* Version		: V01										 					*/
/********************************************************************************/

#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H


typedef struct
{
	u16 Periodicity;
	void (*Fptr) (void);
	u8  FirstDelay;
	u8  State;

}Task;


/*******************************************************************************
 *                      Private Functions Prototypes                           *
 *******************************************************************************/

void Scheduler (void);



#endif
