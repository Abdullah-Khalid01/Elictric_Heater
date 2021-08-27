/*
 * schedular.c
 *
 * Created: 03/01/43 01:26:57 م
 *  Author: ABDULLAH 01
 */ 

#include "schedular.h"
#include "Timer.h"
#include "LCD.h"
#include "LED.h"
#include "Temp_sensor.h"
#include "heating_element.h"
#include "cooling_fan.h"
extern uint8 Set_Tempreature;
extern uint8 Set_Tempreature_mask;
uint16 read=60;      // Store ADC value
uint8 Frist_Click=1;//To select the operating mode
static uint8 k=0;   //counter

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

														

ISR(TIMER1_COMPA_vect)
{
	//static uint8 i=0;
	
	/*uint16 average=0;
	i++;
	if (i==100) //ADC read every 100ms
	{
	//Taking average for 10 reads
		for (uint8 j=0;j<10;j++)
		{
			TempSensor_READ(&read);
			average=average+read;
		}
		average=average/10;
		i=0;
	}************** Hashed till finishing 7sement mode selection module*******************/
		TempSensor_READ(&read);
	
	if ((!(Get_bit(GIFR,6)))&&(!(Get_bit(GIFR,7)))&&k<5000)//if the buttons not pressed & counter less than 5 seconds
	{
		k++;											   //increase the counter
		 if (k+1==5000)				                      //if counted 5s
		{
			Frist_Click=1;			                     //change mode to normal mode
			Set_Tempreature=read;                        //display the adc(actual) value
			k-=1;					                     //reduce the counter by one to make loop.
		}
	}
	
	segment7_display(Set_Tempreature,Frist_Click);
	/*********************************** Heating Elements Control *******************************************/
	if (read<=Set_Tempreature_mask-5)
	{
		heating_set_state(heat_ON);
		cooling_set_state(cool_OFF);
	}
	if (read+5>Set_Tempreature_mask)
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

																							

ISR(INT0_vect)
{
	Frist_Click=0;										 //if button pressed change mode to setting mode
	k=0;												//re-initialize the counter
	if (Set_Tempreature_mask>35)
	{
		Set_Tempreature_mask=Set_Tempreature_mask-5;   //change the required temperature
		Set_Tempreature=Set_Tempreature_mask;		  //set_tempreature variable will store the required value to send it to the 7-segment
	}
	//EEPROM_Write(Set_Tempreature,EEPROM_Address);
}
ISR(INT1_vect)
{
	Frist_Click=0;									 //if button pressed change mode to setting mode
	k=0;											//re-initialize the counter
	if (Set_Tempreature_mask<75)
	{
		Set_Tempreature_mask+=5;					//change the required temperature
		Set_Tempreature=Set_Tempreature_mask;	   //set_tempreature variable will store the required value to send it to the 7-segment
	}
	//EEPROM_Write(Set_Tempreature,EEPROM_Address);
}