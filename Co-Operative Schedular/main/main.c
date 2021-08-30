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

/**********************************************************************Essential Variables *******************************************************************************************/

extern uint16 Set_Tempreature;			//store the required temperature or the actual value.
extern uint8 Set_Tempreature_mask;		//used to choose the required temperature.
//extern uint8 segment_blinking_speed;	//select the blinking speed
extern uint16 average;					//average of 10 ADC reads
extern uint8 CounterRegister_InitValue; //initialize timer0 with appropriate value to count 5 seconds
extern uint32 Number_OverFlows;			//store the number of overflows required to reach 5 seconds
uint8 TaskID=0;							//ID used to delete the task and stop it.
uint8 segment7_ID=0;

/********************************************************************** End of Text -|- ***********************************************************************************************/

#define EEPROM_Address 0x00

uint8 segment_blinking_speed=50;
 

int main(void)
{
	
	SCH_Init_T2();
	Timer0_Init();
	//LED0_INIT();
	//LED1_INIT();
	TempsSensor_INIT();
	cooling_Init(); 
	heating_Init();
	Button_UP_Init();
	Button_Down_Init();
	ExternalINT0_INIT();
	ExternalINT1_INIT();
	segment7_init();
	
	//EEPROM_Init();
	
	
	/*if (EEPROM_Read(EEPROM_Address)!=60)
	{
		Set_Tempreature=EEPROM_Read(EEPROM_Address);
	}*/
	
	segment7_ID=Sch_Add_Task(first_segment7_display,0,50);  //start display values on 7-segment
	Sch_Add_Task(Timer0_SetDelay,0,0);							   //Initialize timer0 to count for 5 seconds
	Sch_Add_Task(Timer0_Start,0,0);							  //Start counting after 5 seconds in case the user doesn't want to change the temperature.
	
    while(1)
    {	
		SCH_Dispatch_Tasks();
    }
	
}

//ISR of the button used to reduce the required value.

ISR(INT0_vect)
{		
	
	//LED1_toggle();
		SCH_Delete_Task(segment7_ID);
		segment7_ID=Sch_Add_Task(first_segment7_display,0,50);
		//scheduler delete task for temperature sensor to display the required temperature
		SCH_Delete_Task(TaskID);
		//stop counting to re-initialize the timer
		Timer0_Stop();
		//re-initialize the timer by the appropriate value to count 5 seconds
		TCNT0=CounterRegister_InitValue;
		//start counting when button pressed
		Timer0_Start();
	//	segment_blinking_speed=50;
	if (Set_Tempreature_mask>35)
	{
		Set_Tempreature_mask=Set_Tempreature_mask-5;   //change the required temperature
		Set_Tempreature=Set_Tempreature_mask;		  //set_tempreature variable will store the required value to send it to the 7-segment
	}
	
	//EEPROM_Write(Set_Tempreature,EEPROM_Address);
}

//ISR of the button used to increase the required value.

ISR(INT1_vect)
{
	
	//LED1_toggle();
		SCH_Delete_Task(segment7_ID);
		segment7_ID=Sch_Add_Task(first_segment7_display,0,50);
		//scheduler delete task for temperature sensor to display the required temperature
		SCH_Delete_Task(TaskID);
		//stop counting to re-initialize the timer
		Timer0_Stop();
		//re-initialize the timer by the appropriate value to count 5 seconds
		TCNT0=CounterRegister_InitValue;
		//start counting when button pressed
		Timer0_Start();									 
	//segment_blinking_speed=50;					
	if (Set_Tempreature_mask<75)
	{	
		Set_Tempreature_mask+=5;					//change the required temperature
		Set_Tempreature=Set_Tempreature_mask;	   //set_tempreature variable will store the required value to send it to the 7-segment
	}
	
	//EEPROM_Write(Set_Tempreature,EEPROM_Address);
}

//ISR of timer0 to count 5seconds
ISR(TIMER0_OVF_vect)
{
	
	static uint32 counter=0;
	counter++;
	//if 5 seconds counted do:
	if (counter==Number_OverFlows)
	{
		//Stop the timer as no long needed.
		Timer0_Stop();
		//re-initialize the timer for next button press
		TCNT0=CounterRegister_InitValue;
		//re-initialize counter to start over in the next time
		counter=0;
		//stop blinking
		//segment_blinking_speed=20;
		//Start displaying the ADC(actual) temperature value.
		SCH_Delete_Task(segment7_ID);
		segment7_ID=Sch_Add_Task(first_segment7_display,0,20);
		TaskID=Sch_Add_Task(TempSensor_READ,0,100);
	}
	
}