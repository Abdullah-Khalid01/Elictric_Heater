/*
 * heating_element.h
 *
 * Created: 21/08/2021 02:21:00 AM
 *  Author: Salma
 */ 


#ifndef HEATING_ELEMENT_H_
#define HEATING_ELEMENT_H_

#include "STD-typdef1.h"
#include "DIO.h"
#include "port.h"

typedef enum
{
	heat_OFF,
	heat_ON
}	HEAT_STATE ;

/******************** PUBPLIC FUNCTIONS ********************/

/*Description : Initialize Heating Element
  Parameters  : void
  Return      : None */
void heating_Init(void) ;

/*Description : Set the state of the Heating Element
  Parameters  : The state of the Heating Element ON/OFF -> u8 state
  Return      : None */
void heating_set_state(uint8 state) ;

/*Description : Get the state of the Heating Element
  Parameters  : void
  Return      : The state of the Heating Element -> u8 */
uint8 heating_get_state (void) ;

#endif /* HEATING_ELEMENT_H_ */