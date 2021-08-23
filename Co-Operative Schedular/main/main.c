/*
 * main.c
 *
 * Created: 03/01/43 01:26:29 م
 *  Author: ABDULLAH 01
 */ 


#include <avr/io.h>		
#include "schedular.h"
#include "LED.h"
#include "LCD.h"


int main(void)
{
	
	//Timer1_Init();
	/*SCH_Init_T2();
	LED0_INIT();
	LCD_INIT();
	Sch_Add_Task(LED0_toggle,0,1000);
	Sch_Add_Task(LCD_CLEAR,0,900);*/
	segment7_init();
	
    while(1)
    {
		segment7_display(44);
        //SCH_Dispatch_Tasks();
    }
}