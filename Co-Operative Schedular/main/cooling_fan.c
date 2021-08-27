/*
 * cooling_fan.c
 *
 * Created: 21/08/2021 01:20:38 AM
 *  Author: Salma
 */ 

#include "cooling_fan.h"

void cooling_Init(void)
{
	DIO_SetPINDIR(DIO_PORTC , DIO_PIN2 , DIO_PIN_OUTPUT) ;
}

void cooling_set_state(uint8 state)
{
	switch (state)
	{
		case cool_ON :
			DIO_WritePIN(DIO_PORTC , DIO_PIN2 , DIO_PIN_HIGH) ;
			break;
			
		case cool_OFF :
			DIO_WritePIN(DIO_PORTC , DIO_PIN2 ,DIO_PIN_LOW) ;
			break;
		
		default:
			break;
	}
}

uint8 cooling_get_state (void)
{
	uint8 st = 0;
	DIO_ReadPin(DIO_PORTC , DIO_PIN2,&st);
	
	return st ;
}