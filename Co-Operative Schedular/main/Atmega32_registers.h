

#ifndef  ATmega32_Registers
#define ATmega32_Registers
#include "STD-typdef1.h"

/*************************************** DIO REGISTERS ********************************************/

#define DDRC (*(volatile uint8*)(0x34))
#define PORTC (*(volatile uint8*)(0x35))
#define PINC (*(volatile uint8*)(0x33))

#define DDRB (*(volatile uint8*)(0x37))
#define PORTB (*(volatile uint8*)(0x38))
#define PINB (*(volatile uint8*)(0x36))

#define DDRD (*(volatile uint8*)(0x31))
#define PORTD (*(volatile uint8*)(0x32))
#define PIND (*(volatile uint8*)(0x30))

#define DDRA (*(volatile uint8*)(0x3A))
#define PORTA (*(volatile uint8*)(0x3B))
#define PINA (*(volatile uint8*)(0x39))

/*****************************************INT REGISTERS *************************************************/

#define SREG (*(volatile uint8*)(0x5F))

#define GICR (*(volatile uint8*)(0x5B))

#define MCUCR (*(volatile uint8*)(0x55))

#define MCUCSR (*(volatile uint8*)(0x54))

#define GIFR (*(volatile uint8*)(0x5A))

/***************************************** ADC REGISTERS *************************************************/

//#define ADMUX      (*(volatile uint8*)(0x27))
//#define ADCSRA     (*(volatile uint8*)(0x26))
//#define ADCH       (*(volatile uint8*)(0x25))
//#define ADCL       (*(volatile uint8*)(0x24))
#define ADC_ADJUST (*(volatile uint16*)(0x24))
#define SFIOR      (*(volatile uint8*)(0x50))

/****************************************** TIMER 0 ********************************************************/

#define OCR0      (*(volatile uint8*)(0x5C))
#define TIMSK      (*(volatile uint8*)(0x59))
#define TIFR      (*(volatile uint8*)(0x58))
#define TCNT0      (*(volatile uint8*)(0x52))
#define TCCR0      (*(volatile uint8*)(0x53))

/******************************************* TIMER 1 ********************************************************/
#define TCCR1A      (*(volatile uint8*)(0x4F))
#define TCCR1B      (*(volatile uint8*)(0x4E))
#define TCNT1      (*(volatile uint16*)(0x4C))
#define OCR1A      (*(volatile uint16*)(0x4A))

#endif