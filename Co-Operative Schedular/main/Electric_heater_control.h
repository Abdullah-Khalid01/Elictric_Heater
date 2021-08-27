/*
 * Electric_heater_control.h
 *
 * Created: 17/08/2021 02:38:39 AM
 *  Author: Salma
 */ 

/*
#ifndef ELECTRIC_HEATER_CONTROL_H_
#define ELECTRIC_HEATER_CONTROL_H_

#include "port.h"
#include "EEPROM.h"
#include "SW.h"
#include "LM35.h"
#include "cooling_fan.h"
#include "heating_element.h"
#include "GPIO.h"


typedef enum
{
	SETTING_MODE=0,
	NORMAL_MODE,
	}	SYSTEM_MODE ;

typedef	enum
{
	HEATER_OFF=0,
	HEATER_ON,
	}	HEATER_STATE ;

void Heater_Init(void) ;
void OFF_STATE(void) ;
void Setting_Mode(u8 button) ;
void Update_heater(void) ;
u8 Get_Current_Temp(void) ;
void Save_Last_Temp(void) ;


#endif /* ELECTRIC_HEATER_CONTROL_H_ */