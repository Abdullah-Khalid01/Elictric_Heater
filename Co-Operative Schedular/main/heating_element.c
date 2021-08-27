/*
 * heating_element.c
 *
 * Created: 21/08/2021 02:20:41 AM
 *  Author: Salma
 */ 

#include "heating_element.h"

void heating_Init(void)
{
	DIO_SetPINDIR(DIO_PORTC , DIO_PIN7 , DIO_PIN_OUTPUT) ;
}

void heating_set_state(uint8 state)
{
	switch (state)
	{
		case heat_ON :
		DIO_WritePIN(DIO_PORTC , DIO_PIN7 ,DIO_PIN_HIGH) ;
		break;
		
		case heat_OFF :
		DIO_WritePIN(DIO_PORTC , DIO_PIN7 , DIO_PIN_LOW) ;
		break;
		
		default:
		break;
	}
}

uint8 heating_get_state (void)
{
	 uint8 st =0;
	 DIO_ReadPin(DIO_PORTC , DIO_PIN7,&st) ;
	
	return st ;
}