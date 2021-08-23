/*
 * schedular.h
 *
 * Created: 03/01/43 01:27:07 م
 *  Author: ABDULLAH 01
 */ 


#ifndef SCHEDULAR_H_
#define SCHEDULAR_H_
#include "Timer.h"


#define SCH_MAX_TASKS               3
#define ERROR_SCH_TOO_MANY_TASKS    1 //don't change its value 


typedef struct  
{
	//pointer to the task
	void(*ptask)(void);
	//Delay (ticks) until the function will (next) be run
	uint16 delay;
	//Interval (ticks) between subsequent runs
	uint16 period;
	// Incremented (by scheduler) when task is due to execute
	uint8 Runme;	
	
}sTask;

sTask SCH_Tasks_G[SCH_MAX_TASKS];

void SCH_Init_T2(void);

uint8 SCH_Delete_Task(const uint8 id);

uint8 Sch_Add_Task (void(*Task_Name)(),const uint16 Initial_Delay,const uint16 Period);

void SCH_Dispatch_Tasks(void);


#endif /* SCHEDULAR_H_ */