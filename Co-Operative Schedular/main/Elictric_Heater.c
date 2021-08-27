/*
 * Elictric_Heater.c
 *
 * Created: 11/01/43 01:04:10 ص
 *  Author: ABDULLAH 01
 */ 
/*
void Elements_Init(void)
{
	DIO_SetPINDIR(PORTA, DIO_PIN1, DIO_PIN_OUTPUT);//heating element
	DIO_SetPINDIR(PORTA, DIO_PIN2, DIO_PIN_OUTPUT);//cooling element
}

void Heating_Element_On(void)
{
	if (//ADC_read<set_tempreature-5)     //replace *ADC_read* & *set_tempreature* with appropriate variables' name
	{
		DIO_WritePIN(PORTA, DIO_PIN1, DIO_PIN_HIGH);
		//led blink every 1 second
		LED0_toggle();
	}
	else if (//ADC_read<set_tempreature+5)
	{
		DIO_WritePIN(PORTA, DIO_PIN1, DIO_PIN_LOW);
		LED0_OFF();
	}
}

void Cooling_Element_On(void)
{
	if (//ADC_read<set_tempreature-5)
	{
		DIO_WritePIN(PORTA, DIO_PIN1, DIO_PIN_LOW);
		LED0_OFF();
	}
	else if (//ADC_read<set_tempreature+5)
	{
		DIO_WritePIN(PORTA, DIO_PIN1, DIO_PIN_HIGH);
		//led on
		LED0_ON();
	}
}*/