/*
 * Timer.c
 *
 * Created: 29/12/42 02:51:49 م
 *  Author: ABDULLAH 01
 */ 

#include "Timer.h"
#include <avr/interrupt.h>
//#include "LCD.h"
static void (*Time1_Call_Back_ptr)(void);
static void (*Time0_Call_Back_ptr)(void);
/*****************************************************************Timer 1********************************************************************/
void Timer1_Init(void)
{
	TIMSK  |=0x10; //Enable interrupt for timer over flow.
	SREG   |=0x80; //Enable the global interrupt.
	//Timer1_Manual_Reload();
	TCCR1A |=0x00; //OC1A state at compare match & mode of the timer.
	TCNT1 =0;
	OCR1A=16;
	TCCR1B =13;
	
	
}

void Set_Call_Back_Timer1(void(*ptr)(void))
{
	Time1_Call_Back_ptr = ptr;
}

/***************************************************************Timer 0**********************************************************/
void Timer0_Init(void)
{
	TIMSK |= 0x01;
	Timer0_Manual_Reload();
}

void Timer0_Manual_Reload(void)
{
	TCCR0 |=0x00;
	TCNT0 =0;
	TCCR0 |=0x05;
}

void Set_Call_Back_Timer0(void(*ptr)(uint8 *str))
{
	Time0_Call_Back_ptr=ptr;
}
