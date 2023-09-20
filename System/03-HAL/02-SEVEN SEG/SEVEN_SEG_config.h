/*************************************************************/
/* Author		: Omar Ashraf							     */
/* Date 		: 1 AUG 2023								 */
/* Version		: V01										 */
/*************************************************************/
#ifndef  SEVEN_SEG_CONFIG_H
#define  SEVEN_SEG_CONFIG_H


/* Options:    SEVEN_SEG_COM_CATHODE	
               SEVEN_SEG_COM_ANODE	
									*/

#define SEVEN_SEG_TYPE			SEVEN_SEG_COM_CATHODE

/* Please write pin pair for 7-SEG PORT,PIN */
#define SEVEN_SEG_PORT			 GPIO_PORTA
#define SEVEN_SEG_PIN_A			 GPIO_PIN0
#define SEVEN_SEG_PIN_B			 GPIO_PIN1
#define SEVEN_SEG_PIN_C          GPIO_PIN2
#define SEVEN_SEG_PIN_D          GPIO_PIN3
#define SEVEN_SEG_PIN_E          GPIO_PIN4
#define SEVEN_SEG_PIN_F          GPIO_PIN5
#define SEVEN_SEG_PIN_G          GPIO_PIN6



#endif