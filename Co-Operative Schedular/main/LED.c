
#include "LED.h"

void LED0_INIT()
{
	DIO_SetPINDIR(DIO_PORTD, DIO_PIN3 , DIO_PIN_OUTPUT);
}

void LED0_ON()
{
	DIO_WritePIN(DIO_PORTD , DIO_PIN3 , DIO_PIN_HIGH);
}

void LED0_OFF()
{
	DIO_WritePIN(DIO_PORTD , DIO_PIN3 , DIO_PIN_LOW);
}

void LED0_toggle()
{
	DIO_togglePin(DIO_PORTD , DIO_PIN3);
}

void Button_UP_Init(void)
{
	DIO_SetPINDIR(DIO_PORTB, DIO_PIN0, DIO_PIN_INPUT);
	DIO_WritePIN(DIO_PORTB, DIO_PIN0, DIO_PIN_HIGH);
}
uint8 Button_UP_GetVal(void)
{
	uint8 Button_value=0;
	DIO_ReadPin(DIO_PORTB, DIO_PIN0, &Button_value);
	return Button_value;
}
void Button_Down_Init(void)
{
	DIO_SetPINDIR(DIO_PORTD, DIO_PIN2, DIO_PIN_INPUT);
	DIO_WritePIN(DIO_PORTD, DIO_PIN2, DIO_PIN_HIGH);
}
uint8 Button_Down_GetVal(void)
{
	uint8 Button_value=0;
	DIO_ReadPin(DIO_PORTD, DIO_PIN2, &Button_value);
	return Button_value;
}