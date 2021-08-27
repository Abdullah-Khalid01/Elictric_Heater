/*
 * EXT_INT.c
 *
 * Created: 1/25/2021 2:22:44 AM
 *  Author: Salma
 */ 

#include <avr/interrupt.h>

#include "BIT_Math.h"
#include "STD-typdef1.h"

#include "DIO.h"
#include "EXT_INT.h"


void EXT_voidEnableExtInt(t_EXT_INT cpy_ext_int , t_TRIGGERING_CONDITION cpy_condition) 
{
	// Enable global interrupts
	sei() ;
	
	// Enable EXT INT
	switch (cpy_ext_int){
		case EXT_INT_0 :
			Set_bit(GICR_R , 6) ;
			break;
			
		case EXT_INT_1 :
			Set_bit(GICR_R , 7) ;
			break;
			
		case EXT_INT_2 :
			Set_bit(GICR_R , 5) ;
			break;
	}
	
	// Sensing level
	switch (cpy_condition){
		case LOW_LEVEL :
			if (cpy_ext_int == EXT_INT_0)
			{
				Clr_bit(MCUCR_R , ISC00) ;
				Clr_bit(MCUCR_R , ISC01) ;
			}
			if (cpy_ext_int == EXT_INT_1)
			{
				Clr_bit(MCUCR_R , ISC10) ;
				Clr_bit(MCUCR_R , ISC11) ;
			}
			break;
			
		case ON_CHANGE :
			if (cpy_ext_int == EXT_INT_0)
			{
				Set_bit(MCUCR_R , ISC00) ;
				Clr_bit(MCUCR_R , ISC01) ;
			}
			if (cpy_ext_int == EXT_INT_1)
			{
				Set_bit(MCUCR_R , ISC10) ;
				Clr_bit(MCUCR_R , ISC11) ;
			}
			break;
		
		case FALLIN_EDGE :
			if (cpy_ext_int == EXT_INT_0)
			{
				Clr_bit(MCUCR_R , ISC00) ;
				Set_bit(MCUCR_R , ISC01) ;
			}
			if (cpy_ext_int == EXT_INT_1)
			{
				Clr_bit(MCUCR_R , ISC10) ;
				Set_bit(MCUCR_R , ISC11) ;
			}
			if (cpy_ext_int == EXT_INT_2)
				Clr_bit(MCUCSR_R , MCUCSR_ISC2) ;
			break;
		
		case RISIN_EDGE :
			if (cpy_ext_int == EXT_INT_0)
			{
				Set_bit(MCUCR_R , ISC00) ;
				Set_bit(MCUCR_R , ISC01) ;
			}
			if (cpy_ext_int == EXT_INT_1)
			{
				Set_bit(MCUCR_R , ISC10) ;
				Set_bit(MCUCR_R , ISC11) ;
			}
			if (cpy_ext_int == EXT_INT_2)
				Set_bit(MCUCSR_R , MCUCSR_ISC2) ;
			break;
	}
	
}

void EXT_voidDisableExtInt(t_EXT_INT cpy_ext_int) 
{
	// Disable EXT INT 
	Clr_bit(cpy_ext_int , 5) ;
}


