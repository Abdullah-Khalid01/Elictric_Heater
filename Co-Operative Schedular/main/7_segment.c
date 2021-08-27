/*
 * _7_segment.c
 *
 * Created: 14/01/43 12:48:28 ص
 *  Author: ABDULLAH 01
 */ 

#include "7_segment.h"
#include "DIO.h"
#include <util/delay.h>
#define F_CPU 8000000
extern uint8 Frist_Click;
extern uint8 Set_Tempreature;
extern uint8 Set_Tempreature_mask;
extern uint8 read;


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
/*
//uint8 k=0;
void mode_selection(void)
{
	
	while (!(Get_bit(GIFR,6))&&!Get_bit(GIFR,7)&&k<5000)
	{
		k++;
		if (k+1==5000)
		{
			Frist_Click=1;
			Set_Tempreature=read;
		}
		//segment7_display(read,Frist_Click);
		
	}
	while(k==5000)
	{
		Set_Tempreature=read;
		if ((Get_bit(GIFR,6))||(Get_bit(GIFR,7)))
	{
		Frist_Click=0;
		k=0;
		Set_Tempreature=Set_Tempreature_mask;
		//segment7_display(Set_Tempreature,Frist_Click);
	}
	}
	
}*/