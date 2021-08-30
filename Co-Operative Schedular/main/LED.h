

#ifndef LED_H
#define LED_H

#define Button_Down_Port	DIO_PORTD
#define Button_Up_Port		DIO_PORTD
#define Button_Down_Pin		DIO_PIN2
#define Button_Up_Pin		DIO_PIN3

#define LED0_PORT			DIO_PORTD
#define LED0_PIN			DIO_PIN2

#define LED1_PORT			DIO_PORTC
#define LED1_PIN			DIO_PIN7

#include "DIO.h"

void LED0_ON(void);

void LED0_toggle(void);

void LED0_OFF(void);

void LED0_INIT(void);

void Button_UP_Init(void);
void Button_Down_Init(void);

uint8 Button_Down_GetVal(void);
uint8 Button_UP_GetVal(void);

void LED1_toggle(void);
void LED1_INIT(void);

void Button_INT2_Init(void);
uint8 Button_INT2_GetVal(void);


#endif