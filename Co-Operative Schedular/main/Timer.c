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
uint8 CounterRegister_InitValue = 0;
uint32 Number_OverFlows = 0;

uint8  Num0_ComMatch=0;

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
/*
void Timer0_Init(void)
{
	TIMSK |= 0x02;
	Timer0_Manual_Reload();
}
*/
void Timer0_Init(void)
{
	#if TIMER0_MODE==NORMAL
	
	/*Initialize Timer 0  in Normal mode */
	
	TCCR0 |= 0x00 ;
	
	TIMSK |= 0x01;

	SREG |= 0x80;
	
	#elif TIMER0_MODE==CTC
	Clr_bit(TCCR0,6);
	Set_bit(TCCR0,3);
	SREG |=0x80;
	Set_bit(TIMSK,1);
	
	#endif
}

void Timer0_Start(void)
{
	
	/* start timer with prescaller   1024 */
	
	TCCR0 |= 0x05;
	
}
void Timer0_Stop(void)
{
	
	Clr_bit(TCCR0,0);
	Clr_bit(TCCR0,1);
	Clr_bit(TCCR0,2);
	
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

void Timer0_SetDelay(void)
{
	
	
	/* tick time in micro second */
	uint8 Tick_Time_us = (1024 / 16);
	
	uint32 Total_Ticks = (5000 * 1000) / Tick_Time_us;
	
	#if TIMER0_MODE==NORMAL
	
	Number_OverFlows = Total_Ticks / 256 ;
	
	CounterRegister_InitValue = 256 - (Total_Ticks % 256) ; //256 - ((  ((float) Total_Ticks / 256 ) - Number_OverFlows ) * 256 );
	
	
	TCNT0 = CounterRegister_InitValue ;
	
	Number_OverFlows ++;
	
	#elif TIMER0_MODE==CTC
	if(Delay_Ms < 16300)
	{
		OCR0 = Total_Ticks - 1;
		Num0_ComMatch=1;
	}
	
	
	#endif
}
