/*
 * External_INT.h
 *
 * Created: 19/11/41 01:10:16 م
 *  Author: ABDULLAH 01
 */ 


#ifndef EXTERNAL_INT_H_
#define EXTERNAL_INT_H_
#include "External_INT_Cfg.h"
#include "Bit_Math.h"
#include "Atmega32_registers.h"

#define GLOBAL_INTERRUPT_ENABLE  1
#define GLOBAL_INTERRUPT_DISABLE 0

/**************************************************** EXTERNAL INTERRUPTS /*******************************************************/

#define EXTERNAL_INT0 6
#define EXTERNAL_INT1 7
#define EXTERNAL_INT2 5

#define INT0_TRIGGER_LOW_LEVEL           0
#define INT0_TRIGGER_RISING_EDGE		 1
#define INT0_TRIGGER_FALLING_EDGE		 2
#define INT0_TRIGGER_ANY_LOGICAL_CHANGE  3

#define INT1_TRIGGER_LOW_LEVEL           0
#define INT1_TRIGGER_RISING_EDGE		 1
#define INT1_TRIGGER_FALLING_EDGE		 2
#define INT1_TRIGGER_ANY_LOGICAL_CHANGE  3

#define INT2_TRIGGER_RISING_EDGE		 0
#define INT2_TRIGGER_FALLING_EDGE		 1


/****************************************************APIS*****************************************************************************/

void Set_GlobalInterrupts(void);
void ExternalINT0_INIT(void);
void ExternalINT1_INIT(void);
void ExternalINT2_INIT(void);



#endif /* EXTERNAL_INT_H_ */