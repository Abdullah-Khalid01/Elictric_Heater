

#ifndef LED_H
#define LED_H

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


#endif