/*
 * EXT_INT.h
 *
 * Created: 1/25/2021 2:23:01 AM
 *  Author: Salma
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_

	/********************** Registers Definition **********************/
	#define  MCUCSR_R		*( (volatile uint8 *) (0x54) )
	#define  MCUCR_R		*( (volatile uint8 *) (0x55) )
	#define  GISR_R			*( (volatile uint8 *) (0x5A) )
	#define  GICR_R			*( (volatile uint8 *) (0x5B) )
	/******************************************************************/

	/************************ Registers PINNS ************************/
	#define MCUCR_ISC00		0
	#define MCUCR_ISC01		1
	#define MCUCR_ISC10		2
	#define MCUCR_ISC11		3
	#define MCUCSR_ISC2		6
	/****************************************************************/

	typedef enum
	{
		EXT_INT_0 ,
		EXT_INT_1 ,
		EXT_INT_2 ,
	}t_EXT_INT  ;


	typedef enum
	{
		LOW_LEVEL ,
		ON_CHANGE  ,
		FALLIN_EDGE ,
		RISIN_EDGE  ,
	}t_TRIGGERING_CONDITION  ;


	// Note: initialize global interrupts in main before using .
	// Note: INT2 only works with rising and falling edges .
	// Note: EXT interrupts don't work in sleep mode. >>ONLY (low level) .

	void EXT_voidEnableExtInt(t_EXT_INT cpy_ext_int , t_TRIGGERING_CONDITION cpy_condition) ;
	void EXT_voidDisableExtInt(t_EXT_INT cpy_ext_int) ;


#endif /* EXT_INT_H_ */