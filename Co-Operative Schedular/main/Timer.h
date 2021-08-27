/*
 * Timer.h
 *
 * Created: 29/12/42 02:52:00 م
 *  Author: ABDULLAH 01
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "DIO.h"
//////////////////////////////////////////Timer 0 Prototypes//////////////////////////////////////
#define TIMER0_MODE CTC
void Timer0_Init(void);
void Timer0_Manual_Reload(void);
void Set_Call_Back_Timer0(void(*ptr)(uint8 *str));
void Timer0_Start(void);

//////////////////////////////////////////Timer 1 Prototypes//////////////////////////////////////
void Timer1_Init(void);
void Timer1_Manual_Reload(void);
void Set_Call_Back_Timer1(void(*ptr)(void));
void Timer0_SetDelay(uint32 Delay_Ms);

#endif /* TIMER_H_ */