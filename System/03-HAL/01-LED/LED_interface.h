/*************************************************************/
/* Author		: Omar Ashraf							     */
/* Date 		: 1 AUG 2023								 */
/* Version		: V01										 */
/*************************************************************/
#ifndef  LED_INTERFACE_H
#define  LED_INTERFACE_H

/* Ports Definnition */
#define LED_GPIOA		0
#define LED_GPIOB		1
#define LED_GPIOC		2

/* Pins Definnition */			
#define LED_PIN0		0
#define LED_PIN1		1
#define LED_PIN2		2
#define LED_PIN3		3
#define LED_PIN4		4
#define LED_PIN5		5
#define LED_PIN6		6
#define LED_PIN7		7
#define LED_PIN8		8
#define LED_PIN9		9
#define LED_PIN10		10
#define LED_PIN11		11
#define LED_PIN12		12
#define LED_PIN13		13
#define LED_PIN14		14
#define LED_PIN15		15

void LED_voidON		( u8 copy_u8Port , u8 copy_u8Pin );
void LED_voidOFF	( u8 copy_u8Port , u8 copy_u8Pin );
void LED_voidTOGGLE ( u8 copy_u8Port , u8 copy_u8Pin );


#endif