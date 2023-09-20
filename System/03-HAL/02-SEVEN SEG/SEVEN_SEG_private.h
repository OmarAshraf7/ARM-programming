/*************************************************************/
/* Author		: Omar Ashraf							     */
/* Date 		: 1 AUG 2023								 */
/* Version		: V01										 */
/*************************************************************/
#ifndef  SEVEN_SEG_PRIVATE_H
#define  SEVEN_SEG_PRIVATE_H

/* Seven Segments Type Options */
#define  SEVEN_SEG_COM_CATHODE			0
#define  SEVEN_SEG_COM_ANODE			1



#if		SEVEN_SEG_TYPE == SEVEN_SEG_COM_CATHODE
#define  SEVEN_SEG_HIGH					1
#define  SEVEN_SEG_LOW					0

#elif 	SEVEN_SEG_TYPE == SEVEN_SEG_COM_ANODE
#define  SEVEN_SEG_HIGH					0
#define  SEVEN_SEG_LOW					1

#endif


#endif