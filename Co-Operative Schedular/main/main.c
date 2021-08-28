/*
 * main.c
 *
 * Created: 03/01/43 01:26:29 م
 *  Author: ABDULLAH 01
 */ 

#include <avr/interrupt.h>
#include <avr/io.h>

#include "cooling_fan.h"
#include "heating_element.h"		
#include "schedular.h"
#include "EEPROM.h"
#include "LED.h"
#include "LCD.h"
#include "Temp_sensor.h"
#include "External_INT.h"
#include "7_segment.h"

#define EEPROM_Address 0x00

uint8 segment_blinking_speed=20;
 

int main(void)
{
	
	SCH_Init_T2();
	Timer0_Init();
	LED0_INIT();
	TempsSensor_INIT();
	cooling_Init();
	heating_Init();
	ExternalINT0_INIT();
	ExternalINT1_INIT();
	segment7_init();
	Button_UP_Init();
	Button_Down_Init();
	EEPROM_Init();
	
	/*if (EEPROM_Read(EEPROM_Address)!=60)
	{
		Set_Tempreature=EEPROM_Read(EEPROM_Address);
	}*/
	Sch_Add_Task(first_segment7_display,0,segment_blinking_speed);  //start display values on 7-segment
	Sch_Add_Task(Timer0_SetDelay,0,0);							   //Initialize timer0 to count for 5 seconds
	Sch_Add_Task(Timer0_Start,2000,0);							  //Start counting after 2 seconds
	//Sch_Add_Task(TempSensor_READ,0,100);
    while(1)
    {	
		SCH_Dispatch_Tasks();
    }
	
}