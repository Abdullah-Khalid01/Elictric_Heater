
#include "LED.h"

void LED0_INIT()
{
	DIO_SetPINDIR(LED0_PORT, LED0_PIN , DIO_PIN_OUTPUT);
}
void LED1_INIT()
{
	DIO_SetPINDIR(LED1_PORT, LED1_PIN , DIO_PIN_OUTPUT);
	
}
void LED1_toggle()
{
	DIO_togglePin(LED1_PORT , LED1_PIN);
}

void LED0_ON()
{
	DIO_WritePIN(LED0_PORT , LED0_PIN , DIO_PIN_HIGH);
}

void LED0_OFF()
{
	DIO_WritePIN(LED0_PORT , LED0_PIN , DIO_PIN_LOW);
}

void LED0_toggle()
{
	DIO_togglePin(LED0_PORT , LED0_PIN);
}

void Button_UP_Init(void)
{
	DIO_SetPINDIR(Button_Up_Port, Button_Up_Pin, DIO_PIN_INPUT);
	DIO_WritePIN(Button_Up_Port, Button_Up_Pin, DIO_PIN_HIGH);
}
uint8 Button_UP_GetVal(void)
{
	uint8 Button_value=0;
	DIO_ReadPin(Button_Up_Port, Button_Up_Pin, &Button_value);
	return Button_value;
}
void Button_Down_Init(void)
{
	DIO_SetPINDIR(Button_Down_Port, Button_Down_Pin, DIO_PIN_INPUT);
	DIO_WritePIN(Button_Down_Port, Button_Down_Pin, DIO_PIN_HIGH);
}
uint8 Button_Down_GetVal(void)
{
	uint8 Button_value=0;
	DIO_ReadPin(Button_Down_Port, Button_Down_Pin, &Button_value);
	return Button_value;
}

void Button_INT2_Init(void)
{
	DIO_SetPINDIR(DIO_PORTB,DIO_PIN4, DIO_PIN_INPUT);
	DIO_WritePIN(DIO_PORTB,DIO_PIN4, DIO_PIN_HIGH);
}
uint8 Button_INT2_GetVal(void)
{
	uint8 Button_value=0;
	DIO_ReadPin(DIO_PORTB, DIO_PIN4, &Button_value);
	return Button_value;
}