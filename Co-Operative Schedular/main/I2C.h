/*
 * I2C.h
 *
 * Created: 12/04/2021 04:24:37 PM
 *  Author: Salma
 */ 

#include "STD-typdef1.h"

#ifndef I2C_H_
#define I2C_H_

#include "avr/io.h"

	/* Registers Definition */
/*	#define TWD_R	*((volatile u8*)0x23)
	#define TWA_R	*((volatile u8*)0x22)
	#define TWC_R	*((volatile u8*)0x56)
	#define TWS_R	*((volatile u8*)0x21)
	#define TWB_R	*((volatile u8*)0x20)
*/
	/* TWCR bits Macros */
	#define TWINT		7
	#define TWEA		6
	#define TWSTA		5
	#define TWSTO		4
	#define TWWC		3
	#define TWEN		2
	#define TWIE		0

	/* TWSR bits Macros */
	#define TWPS0		0
	#define TWPS1		1
	
	/* Acknowledge Macros */
	#define TW_MR_Data_Ack	0x50
	#define TW_MR_Sla_Ack	0x40

	/*********************** PRESCALER *************************/
	typedef enum
	{
		I2C_Prescaler_1,
		I2C_Prescaler_4,
		I2C_Prescaler_16,
		I2C_Prescaler_64
		} I2C_PRESCALER ;
	/***********************************************************/
	
	/******************** PUBPLIC FUNCTIONS ********************/
	/*Description : Initialize I2C in Master Mode
	  Parameters  : void
	  return type : void*/
	void i2c_voidInit(I2C_PRESCALER pre) ;
	
	/*Description : Send Start condition in Master Mode
	  Parameters  : void
	  return type : void*/
	void i2c_voidStart(void) ;
	
	/*Description : Send Stop condition in Master Mode
	  Parameters  : void
	  return type : void*/
	void i2c_voidStop(void) ;
	
	/*Description : Send data
	  Parameters  : 8-bit data
	  return type : void*/
	void i2c_voidSend_Data(uint8 data) ;
	
	/*Description : Read Acknowledge Bit
	  Parameters  : void
	  return type : 8-bit*/
	uint8	 i2c_u8Read_Ack(void) ;

	/*Description : Read NACK
	  Parameters  : void
	  return type : 8-bit*/
	uint8 i2c_u8Read_NACK(void) ;

	/*Description : Get status
	  Parameters  : void
	  return type : 8-bit*/
	uint8 i2c_u8get_Status(void) ;


#endif /* I2C_H_ */