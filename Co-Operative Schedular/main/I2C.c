/*
 * I2C.c
 *
 * Created: 12/04/2021 04:24:20 PM
 *  Author: Salma
 */ 

#include "I2C.h"
#include "BIT_Math.h"

/* Initialize I2C */
void i2c_voidInit(I2C_PRESCALER pre)
{
	//Enable I2C
	Set_bit(TWCR , TWEN) ;			
	
	//Bit Rate
	TWBR = 72 ;		
				
	TWSR=0x00; ;	
	
	switch ( pre )
	{
		case I2C_Prescaler_1 :
			break;
		case I2C_Prescaler_4 :
			Set_bit(TWSR , TWPS0) ;
			break;
		case I2C_Prescaler_16 :
			Set_bit(TWSR , TWPS1) ;
			break;
		case I2C_Prescaler_64 :
			Set_bit(TWSR , TWPS0) ;
			Set_bit(TWSR , TWPS1) ;
			break;
		default:
			break;
	}
	
	//Enable Ack
	Set_bit(TWCR , TWEA) ;
	
}

/* Send Start condition */
void i2c_voidStart(void)
{
	Set_bit(TWCR , TWINT) ;				//Clear flag
	Set_bit(TWCR , TWSTA) ;				//Send start
	Set_bit(TWCR , TWEN)  ;				//Enable I2C
	
	while (!(TWCR & (1 << TWINT)))
	;
}

/* Send Stop condition */
void i2c_voidStop(void)
{
	Set_bit(TWCR , TWINT) ;				//Clear flag
	Set_bit(TWCR , TWSTO) ;				//Send stop
	Set_bit(TWCR , TWEN)  ;				//Enable I2C
	
	//while( !(TWC_R & (1<<TWINT) ) ){};		//Wait for TWINT Flag set
}

/* Send data */
void i2c_voidSend_Data(uint8 data)
{
	TWDR = data ;
	
	Set_bit(TWCR , TWINT) ;				//Clear flag
	Set_bit(TWCR , TWEN)  ;				//Enable I2C
		
	while (!(TWCR & (1 << TWINT)))
	;
}

/* Check Acknowledge Bit */
uint8 i2c_u8Read_Ack(void)
{
	Set_bit(TWCR , TWINT) ;				//Clear flag
	Set_bit(TWCR , TWEN)  ;				//Enable I2C
	Set_bit(TWCR , TWEA)  ;				//Enable Ack
		
	while (!(TWCR & (1 << TWINT)))
	;
		
	return TWDR ;
}

/* Read NACK */
uint8 i2c_u8Read_NACK(void)
{
	Set_bit(TWCR , TWINT) ;				//Clear flag
	Set_bit(TWCR , TWEN)  ;				//Enable I2C
	
	while (!(TWCR & (1 << TWINT)))
	;
	
	return TWDR ;
}

/* Get status */
uint8 i2c_u8get_Status(void)
{
	uint8 status;
	status = TWSR & 0xF8;
	return status;
}