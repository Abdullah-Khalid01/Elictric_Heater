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

#define EEPROM_Address 0x00
uint8 Set_Tempreature=60; // select the required tempreature.
uint8 Frist_Click=1; //To select the operating mode
 

int main(void)
{
	
	SCH_Init_T2();
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
	
	if (EEPROM_Read(EEPROM_Address)!=60)
	{
		Set_Tempreature=EEPROM_Read(EEPROM_Address);
	}
	
    while(1)
    {	
		SCH_Dispatch_Tasks();
    }
	
}

ISR(INT0_vect)
{
		
		Frist_Click=0;
		if (Set_Tempreature>35)
		{
			while(Button_Down_GetVal());
			Set_Tempreature=Set_Tempreature-5;
		}
			  
	//EEPROM_Write(Set_Tempreature,EEPROM_Address);
}
ISR(INT1_vect)
{
	Frist_Click=0;
		
		if (Set_Tempreature<75)
		{
				while(Button_UP_GetVal());
				Set_Tempreature+=5;
			
		}
	
	//EEPROM_Write(Set_Tempreature,EEPROM_Address);
}

