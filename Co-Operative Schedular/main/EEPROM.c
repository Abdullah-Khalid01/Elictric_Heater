/*
 * EEPROM.c
 *
 * Created: 13/04/2021 01:32:52 AM
 *  Author: Salma
 */ 

#include "EEPROM.h"

void EEPROM_Init(void)
{
	i2c_voidInit(I2C_Prescaler_1) ;
}

void EEPROM_Write (uint8 data, uint8 address)
{
	i2c_voidStart( ) ;
	
	i2c_voidSend_Data( 0xA0 ) ;				//Write Mode
	i2c_voidSend_Data( address ) ;
	i2c_voidSend_Data( data ) ;
	
	i2c_voidStop( ) ;
}


uint8 EEPROM_Read (uint8 address)
{
	uint8 res = 0 ;
	
	i2c_voidStart( ) ;
	
	i2c_voidSend_Data( 0xA0 ) ;				//Write Mode
	i2c_voidSend_Data( address ) ;
	
	i2c_voidStart( ) ;
	
	i2c_voidSend_Data( 0xA1 ) ;				//Read Mode
	
	res = i2c_u8Read_NACK() ;
	
	i2c_voidStop( ) ;

	return res ;
}