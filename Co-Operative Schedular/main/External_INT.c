/*
 * External_INT.c
 *
 * Created: 19/11/41 01:10:56 م
 *  Author: ABDULLAH 01
 */ 

#include "External_INT.h"

void Set_GlobalInterrupts(void)
{
	#if GLOBAL_INTERRUPT==GLOBAL_INTERRUPT_ENABLE
	Set_bit(SREG,7);
	#elif GLOBAL_INTERRUPT==GLOBAL_INTERRUPT_DISABLE
	Clr_bit(SREG,7);
	#endif
}
void ExternalINT0_INIT(void)
{
	Set_GlobalInterrupts();
	Set_bit(GICR,EXTERNAL_INT0);
	
	#if EXTERNAL_INT0_TRIGGER == INT0_TRIGGER_LOW_LEVEL
	
	Clr_bit(MCUCR,0);
	Clr_bit(MCUCR,1);
	
	#elif EXTERNAL_INT0_TRIGGER ==INT0_TRIGGER_ANY_LOGICAL_CHANGE
	
	Set_bit(MCUCR,0);
	Clr_bit(MCUCR,1);
	
	#elif EXTERNAL_INT0_TRIGGER ==INT0_TRIGGER_FALLING_EDGE
	Clr_bit(MCUCR,0);
	Set_bit(MCUCR,1);
	
	#elif EXTERNAL_INT0_TRIGGER ==INT0_TRIGGER_RISING_EDGE
	
	Set_bit(MCUCR,0);
	Set_bit(MCUCR,1);
	
	#endif
	
}
void ExternalINT1_INIT(void)
{
	Set_GlobalInterrupts();
	Set_bit(GICR,EXTERNAL_INT1);
	
	#if EXTERNAL_INT1_TRIGGER == INT1_TRIGGER_LOW_LEVEL
	
	Clr_bit(MCUCR,2);
	Clr_bit(MCUCR,3);
	
	#elif EXTERNAL_INT1_TRIGGER ==INT1_TRIGGER_ANY_LOGICAL_CHANGE
	
	Set_bit(MCUCR,2);
	Clr_bit(MCUCR,3);
	
	#elif EXTERNAL_INT1_TRIGGER ==INT1_TRIGGER_FALLING_EDGE
	Clr_bit(MCUCR,2);
	Set_bit(MCUCR,3);
	
	#elif EXTERNAL_INT1_TRIGGER ==INT1_TRIGGER_RISING_EDGE
	
	Set_bit(MCUCR,2);
	Set_bit(MCUCR,3);
	
	#endif
}
void ExternalINT2_INIT(void)
{
	Set_GlobalInterrupts();
	Set_bit(GICR,EXTERNAL_INT1);
	
	
	#if EXTERNAL_INT2_TRIGGER ==INT2_TRIGGER_FALLING_EDGE
	Clr_bit(MCUCSR,6);
	
	
	#elif EXTERNAL_INT2_TRIGGER ==INT2_TRIGGER_RISING_EDGE
	
	Set_bit(MCUCSR,6);
	
	#endif
}
