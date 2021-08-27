/*
 * cooling_fan.h
 *
 * Created: 21/08/2021 01:20:59 AM
 *  Author: Salma
 */ 


#ifndef COOLING_FAN_H_
#define COOLING_FAN_H_

#include "STD-typdef1.h"
#include "DIO.h"
#include "port.h"

typedef enum
{
	cool_OFF,
	cool_ON
	}	COOL_STATE ;


/******************** PUBPLIC FUNCTIONS ********************/

/*Description : Initialize Cooling Element
  Parameters  : void
  Return      : None */
void cooling_Init(void) ;

/*Description : Set the state of the Cooling Element
  Parameters  : The state of the Cooling Element ON/OFF -> u8 state
  Return      : None */
void cooling_set_state(uint8 state) ;

/*Description : Get the state of the Cooling Element
  Parameters  : void
  Return      : The state of the Cooling Element -> u8 */
uint8 cooling_get_state (void) ;

#endif /* COOLING_FAN_H_ */