﻿/*
 * _7_segment.c
 *
 * Created: 14/01/43 12:48:28 ص
 *  Author: ABDULLAH 01
 */ 

#include "7_segment.h"
#include "DIO.h"
#include <util/delay.h>
#define F_CPU 8000000


void segment7_init(void)
{
	DIO_SetPINDIR(DIO_PORTB, DIO_PIN1, DIO_PIN_OUTPUT);
	DIO_SetPINDIR(DIO_PORTB, DIO_PIN2, DIO_PIN_OUTPUT);
	DIO_SetPortDIR(DIO_PORTA, DIO_PORT_OUTPUT);
	
}
void segment7_display(uint8 num, uint8 mode)
{
	
	uint8 temp=0;
	
	if (num >=10)
	{
		temp=num/10;
		num=num%10;
		
		if (mode==1)
		{
			DIO_WritePIN(DIO_PORTB, DIO_PIN3, DIO_PIN_LOW);
			
			PORTA=(temp <<4);
			DIO_WritePIN(DIO_PORTB, DIO_PIN2, DIO_PIN_HIGH);
			_delay_ms(1);
			DIO_WritePIN(DIO_PORTB, DIO_PIN2, DIO_PIN_LOW);
			
			
			PORTA=(num <<4);
			DIO_WritePIN(DIO_PORTB, DIO_PIN1, DIO_PIN_HIGH);
			_delay_ms(1);
			DIO_WritePIN(DIO_PORTB, DIO_PIN1, DIO_PIN_LOW);
		}
		
		if (mode==0)
		{
			
			DIO_WritePIN(DIO_PORTB, DIO_PIN3, DIO_PIN_LOW);
			
			PORTA=(temp <<4);
			DIO_WritePIN(DIO_PORTB, DIO_PIN2, DIO_PIN_HIGH);
			_delay_ms(250);
			DIO_WritePIN(DIO_PORTB, DIO_PIN2, DIO_PIN_LOW);
			
			
			PORTA=(num <<4);
			DIO_WritePIN(DIO_PORTB, DIO_PIN1, DIO_PIN_HIGH);
			_delay_ms(250);
			DIO_WritePIN(DIO_PORTB, DIO_PIN1, DIO_PIN_LOW);
			DIO_WritePIN(DIO_PORTB, DIO_PIN2, DIO_PIN_LOW);
			_delay_ms(1000);
		}
		
		
		
	}
	else if (num>=1 && num <10 ||num==0)
	{
		DIO_WritePIN(DIO_PORTB, DIO_PIN3, DIO_PIN_LOW);
		PORTA=(num<<4 );
		DIO_WritePIN(DIO_PORTB, DIO_PIN2, DIO_PIN_HIGH);
		

	}
	
}