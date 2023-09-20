/********************************************************************************/
/* Author		: Omar Ashraf							     					*/
/* Date 		: 18 AUG 2023								 					*/
/* Version		: V01										 					*/
/********************************************************************************/

#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

/*******************************************************************************
 *                      Registers Definitions                                  *
 *******************************************************************************/
 
typedef struct
{
	u32 EVCR;
	u32 MAPR;
	u32 EXTICR[4];
	u32 MAPR2;
}AFIO_t;

#define AFIO 		((volatile AFIO_t* ) 0x40010000 )




#endif