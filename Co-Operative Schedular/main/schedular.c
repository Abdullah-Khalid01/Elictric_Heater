/*
 * schedular.c
 *
 * Created: 03/01/43 01:26:57 م
 *  Author: ABDULLAH 01
 */ 

#include "schedular.h"
#include "Timer.h"
#include "LCD.h"

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

uint8 Sch_Add_Task (void(*Task_Name)(),const uint16 Initial_Delay,const uint16 Period)
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
	/*
	static uint16 counter=0;
	counter++;
	if (counter==1000)
	{
		
		LCD_WriteString("Hi");
	}
	
	if (counter==2000)
	{
		LCD_WriteString("Welcome");
		counter=0;
	}*/
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