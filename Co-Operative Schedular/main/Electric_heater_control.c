/*
 * Electric_heater_control.c
 *
 * Created: 17/08/2021 02:38:22 AM
 *  Author: Salma
 */ 
/*
#include "Electric_heater_control.h"

static uint8 set_temp ;
static uint8 current_mode ;
static uint8 current_state ;

//static u8 setting_mode_flag = 0 ;
static uint8 FIRST_CLICK = 0 ;

void Heater_Init(void)
{
	EEPROM_Init() ;
	
	SW_Init() ;
	
	cooling_Init() ;
	heating_Init() ;
	
	//LM35_Init() ;
	
	current_mode = NORMAL_MODE ;
	current_state = HEATER_OFF ;
	
	Save_Last_Temp() ;
}

void OFF_STATE(void)
{
	cooling_set_state(cool_OFF) ;
	heating_set_state(heat_OFF) ;
	//SCH_Go_To_Sleep() ;
}


void Update_heater(void)
{
	switch ( current_state )
	{	
		case HEATER_OFF :
			if ( GPIO_u8GetPortPinValue(ON_OFF_PORT , ON_OFF_PIN) == 0 )
			{
				current_state = HEATER_ON ;
			}
			else if ( GPIO_u8GetPortPinValue(ON_OFF_PORT , ON_OFF_PIN) == 1 )
			{
				EEPROM_Write(set_temp , ADDRESS) ;
				current_state = HEATER_OFF ;
				OFF_STATE() ;
			}
			break;
			
		case HEATER_ON :
			if ( GPIO_u8GetPortPinValue(ON_OFF_PORT , ON_OFF_PIN) == 0 )
			{
				current_state = HEATER_OFF ;
				OFF_STATE() ;
			}
			else if ( GPIO_u8GetPortPinValue(ON_OFF_PORT , ON_OFF_PIN) == 1 )
			{
				current_state = HEATER_ON ;

				if ( FIRST_CLICK == 0 )
				{
					if ( (GPIO_u8GetPortPinValue(UP_PORT , UP_PIN) == 0) || (GPIO_u8GetPortPinValue(DOWN_PORT , DOWN_PIN) == 0) )
					{
						current_mode = SETTING_MODE ;
						set_temp = EEPROM_Read(ADDRESS) ;
						FIRST_CLICK = 1 ;
					}
					else
					{
						current_mode = NORMAL_MODE ;
						FIRST_CLICK = 0 ;
					}
				}
			}
			break;
			
		default:
			break;
	}
	
	switch ( current_mode )
	{
		case NORMAL_MODE :
			FIRST_CLICK = 0 ;
			break;
			
		case SETTING_MODE :
		{
			if ( FIRST_CLICK == 1 )
			{
				if (GPIO_u8GetPortPinValue(UP_PORT , UP_PIN) == 0)
				{
					Setting_Mode(UP_SW) ;
				}
				else if (GPIO_u8GetPortPinValue(DOWN_PORT , DOWN_PIN) == 0)
				{
					Setting_Mode(DOWN_SW) ;
				}
			}
		}
			break;
		
		default:
			break;
	}
}

u8 Get_Current_Temp(void)
{
	return set_temp ;
}
*/