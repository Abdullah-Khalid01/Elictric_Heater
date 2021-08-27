/*
 * EEPROM.h
 *
 * Created: 13/04/2021 01:33:11 AM
 *  Author: Salma
 */ 

#include "BIT_Math.h"

#ifndef EEPROM_H_
#define EEPROM_H_

#include "I2C.h"
#include "BIT_Math.h"

	#define ADDRESS		0x00 

	/******************** PUBPLIC FUNCTIONS ********************/
	/*Description : Initialize EEPROM
		  Parameters  : void
		  return type : None*/
	void EEPROM_Init(void) ;

	/*Description : Write EEPROM
	  Parameters  : 8-bits data, 8-bits address
	  return type : None*/
	void EEPROM_Write (uint8 data, uint8 address) ;
	
	/*Description : Read EEPROM
	  Parameters  : 8-bits address
	  return type : None*/
	uint8 EEPROM_Read (uint8 address) ;



#endif /* EEPROM_H_ */