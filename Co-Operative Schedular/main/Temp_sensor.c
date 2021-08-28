/*
 * Temp_sensor.c
 *
 * Created: 25/11/41 08:30:49 ص
 *  Author: ABDULLAH 01
 */ 


#include "Temp_sensor.h"
#include "DIO.h"
extern uint16 read;
uint16 average=0;
extern uint16 Set_Tempreature;
void TempsSensor_INIT(void)
{
	ADC_INIT();
}
void TempSensor_READ(void)
{
	//Calculate average of 10 reads
	for (uint8 i=0;i<10;i++)
	{
		ADC_READ();
		average=average+read;
	}
	average=average/10;
	//store the result value in set tempreature variable to be displayed
	Set_Tempreature=average;
}