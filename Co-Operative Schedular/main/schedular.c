/*
 * schedular.c
 *
 * Created: 03/01/43 01:26:57 م
 *  Author: ABDULLAH 01
 */ 

#include "schedular.h"
#include "Timer.h"
#include "LED.h"
#include "heating_element.h"
#include "cooling_fan.h"
#include "Temp_sensor.h"
extern uint16 Set_Tempreature;			//store the required temperature or the actual value.
extern uint8 Set_Tempreature_mask;		//used to choose the required temperature.
extern uint8 segment_blinking_speed;	//select the blinking speed
extern uint16 average;					//average of 10 ADC reads
extern uint8 CounterRegister_InitValue; //initialize timer0 with appropriate value to count 5 seconds
extern uint32 Number_OverFlows;			//store the number of overflows required to reach 5 seconds
uint8 TaskID=0;							//ID used to delete the task and stop it fro serving
#include <avr/interrupt.h>

uint8 Error_Code_G=0;

void SCH_Init_T2(void)
{
	uint8 i;
	for (i=0;i<SCH_MAX_TASKS;i++)
	{
	 SCH_Delete_Task(i);
	}
	
	Error_Code_G=0;
	
	Timer1_Init();
	
	
}

uint8 Sch_Add_Task (void(*Task_Name)(void),const uint16 Initial_Delay,const uint16 Period)
{
	uint8 index=0;
	
	// First find a gap in the array (if there is one)
	while ((SCH_Tasks_G[index].ptask != 0) && (index < SCH_MAX_TASKS))
	{
		index++;
	}
	if (index==SCH_MAX_TASKS)
	{
		//Task List is full
		LCD_WriteString("Too many Tasks");
		Error_Code_G=ERROR_SCH_TOO_MANY_TASKS;//set the global error variable
		//return an error code
		return SCH_MAX_TASKS;
	}
	//if there is a space for a new task
	SCH_Tasks_G[index].ptask=Task_Name;
	SCH_Tasks_G[index].delay=Initial_Delay;
	SCH_Tasks_G[index].period=Period;
	SCH_Tasks_G[index].Runme=0;
	return index; // return position of task (to allow later deletion)
}

void SCH_Dispatch_Tasks(void)
{
	uint8 index=0;
	// Dispatches (runs) the next task (if one is ready).
	for (index=0;index<SCH_MAX_TASKS;index++)
	{
		if (SCH_Tasks_G[index].Runme>0)
		{
			(*SCH_Tasks_G[index].ptask)();//run the task.
			SCH_Tasks_G[index].Runme-=1;
			if (SCH_Tasks_G[index].period==0)
			{
				SCH_Delete_Task(index);
			}
			
		}
	}
}
uint8 SCH_Delete_Task(const uint8 id)
{
	if (SCH_Tasks_G[id].ptask==0)
	{
		return 0;
	}
	SCH_Tasks_G[id].ptask=0x00;
	SCH_Tasks_G[id].period=0;
	SCH_Tasks_G[id].delay=0;
	SCH_Tasks_G[id].Runme=0;
}

														
//ISR of Timer1 used for scheduler
ISR(TIMER1_COMPA_vect)
{
	/*********************************** Heating Elements Control *******************************************/
	if (average<=Set_Tempreature_mask-5)
	{
		heating_set_state(heat_ON);
		cooling_set_state(cool_OFF);
	}
	if (average+5>Set_Tempreature_mask)
	{
		heating_set_state(heat_OFF);
		cooling_set_state(cool_ON);
	}
	/************************************** End of Elements control block**************************************/
	uint8 index=0;
	
	//calculations are in ticks not milliseconds.
	for (index=0;index<SCH_MAX_TASKS;index++)
	{
		//check if there is a task at this location.
		if (SCH_Tasks_G[index].ptask)
		{
			if (SCH_Tasks_G[index].delay==0)
			{
				//The task is due to run.
				SCH_Tasks_G[index].Runme+=1; // increase the tun me flag.
				if (SCH_Tasks_G[index].period)
				{
					//schedule periodic task to run again.
					SCH_Tasks_G[index].delay=SCH_Tasks_G[index].period;
				}
				
			}
			else
			{
				//not yet ready to run.
				SCH_Tasks_G[index].delay-=1;
			}
		}
		//Timer1_Manual_Reload();
	}
}

																							
//ISR of the button used to reduce the required value.
ISR(INT0_vect)
{		
		//scheduler delete task for tempreature sensor to display the required temperature
		SCH_Delete_Task(TaskID);
		//stop counting to re-initialize the timer
		Timer0_Stop();
		//re-initialize the timer by the appropriate value to count 5 seconds
		TCNT0=CounterRegister_InitValue;
		//start counting when button pressed
		Timer0_Start();
		//segment_blinking_speed=50;
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
		//scheduler delete task for tempreature sensor to display the required temperature
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
		segment_blinking_speed=20;
		//Start displaying the ADC(actual) tempreature value.
		TaskID=Sch_Add_Task(TempSensor_READ,0,100);
	}
	
}