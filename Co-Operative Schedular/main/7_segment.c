/*
 * _7_segment.c
 *
 * Created: 14/01/43 12:48:28 ص
 *  Author: ABDULLAH 01
 */ 

#include "7_segment.h"
#include "DIO.h"
#include <util/delay.h>
#define F_CPU 8000000



uint16 Set_Tempreature=60;				// store the required temperature or the actual value.
uint8 Set_Tempreature_mask=60;			//used to choose the required temperature.
uint8 k=1;

extern uint8 segment_blinking_speed;	//select the blinking speed
extern uint16 average;					//average of 10 ADC reads
//uint8 temp=0;							

static uint8 counter=0;
uint8 arr[]={0,1,2,3,4,5,6,7,8,9};		//Used to display numbers on 7-segment
uint8 j,x;								//To store each number of the value displayed

void segment7_init(void)
{
	//Define 7-semnents enable pins as output
	DIO_SetPINDIR(segment7_EN_PORT, Segment7_1_EN, DIO_PIN_OUTPUT);
	DIO_SetPINDIR(segment7_EN_PORT, Segment7_2_EN, DIO_PIN_OUTPUT);
	//Define Data Port as output
	DIO_SetPortDIR(segment7_DATA_PORT,DIO_PORT_OUTPUT);
	
	
}
void segment7_Set_Number(uint16 num)
{
	//split the value into 2 values to display each number on different 7-segment
	j=num%10;
	num=num/10;
	
	x=num%100;
}
void first_segment7_display(void)
{
		//Prepare the value for display
		segment7_Set_Number(Set_Tempreature);
		//Display the value
		segment7_DATA_PORT=((arr[x])<<4);
		DIO_WritePIN(segment7_EN_PORT, Segment7_2_EN, DIO_PIN_HIGH);
		_delay_ms(10);
		DIO_WritePIN(segment7_EN_PORT, Segment7_2_EN, DIO_PIN_LOW);
		segment7_DATA_PORT=((arr[j])<<4);
		DIO_WritePIN(segment7_EN_PORT, Segment7_1_EN, DIO_PIN_HIGH);
		_delay_ms(10);
		DIO_WritePIN(segment7_EN_PORT, Segment7_1_EN, DIO_PIN_LOW);
}
void segment7_Stop (void)
{
	DIO_WritePIN(segment7_EN_PORT, Segment7_1_EN, DIO_PIN_LOW);
	DIO_WritePIN(segment7_EN_PORT, Segment7_2_EN, DIO_PIN_LOW);
}




/* This function is working perfectly, but it's not appropriate for this scheduler application.
void segment7_display(uint8 num, uint8 mode)
{
	
	uint8 temp=0;
	
	if (num >=10)
	{
		temp=num/10;
		num=num%10;
		
		if (mode==1)
		{
			DIO_WritePIN(DIO_PORTB, DIO_PIN3, DIO_PIN_LOW);//disable (dot) sign for fraction numbers less than 1
			
			PORTA=(temp <<4);
			DIO_WritePIN(DIO_PORTB, DIO_PIN2, DIO_PIN_HIGH);// enable first 7-segment
			_delay_ms(1);
			DIO_WritePIN(DIO_PORTB, DIO_PIN2, DIO_PIN_LOW);// disable first 7-segment
			
			
			PORTA=(num <<4);
			DIO_WritePIN(DIO_PORTB, DIO_PIN1, DIO_PIN_HIGH);// enable first 7-segment
			_delay_ms(1);
			DIO_WritePIN(DIO_PORTB, DIO_PIN1, DIO_PIN_LOW);// disable first 7-segment
		}
		
		if (mode==0)
		{
			
			DIO_WritePIN(DIO_PORTB, DIO_PIN3, DIO_PIN_LOW);
			
			PORTA=(temp <<4);
			DIO_WritePIN(DIO_PORTB, DIO_PIN2, DIO_PIN_HIGH);
			_delay_ms(250);
			DIO_WritePIN(DIO_PORTB, DIO_PIN2, DIO_PIN_LOW);
			
			
			PORTA=(num <<4);
			DIO_WritePIN(DIO_PORTB, DIO_PIN1, DIO_PIN_HIGH);
			_delay_ms(250);
			DIO_WritePIN(DIO_PORTB, DIO_PIN1, DIO_PIN_LOW);//disable both 7-segments 
			DIO_WritePIN(DIO_PORTB, DIO_PIN2, DIO_PIN_LOW);//to make it blinking
			_delay_ms(1000);							   //delay amount
		}
		
		
		
	}
	else if (num>=1 && num <10 ||num==0)
	{
		DIO_WritePIN(DIO_PORTB, DIO_PIN3, DIO_PIN_LOW);
		PORTA=(num<<4 );
		DIO_WritePIN(DIO_PORTB, DIO_PIN2, DIO_PIN_HIGH);
		

	}
	
}
*/

void mode_selection(void)
{
	
	while ((!(Get_bit(GIFR,6)))&&(!(Get_bit(GIFR,7)))&&(k<5000))//if the buttons not pressed & counter less than 5 seconds
	{
		k++;											   //increase the counter
		if (k+1==5000)				                      //if counted 5s
		{
			segment_blinking_speed=20;			                     //change mode to normal mode
			Set_Tempreature=average;                        //display the adc(actual) value
		//	k-=1;					                     //reduce the counter by one to make loop.
		}
	}
	
	
}