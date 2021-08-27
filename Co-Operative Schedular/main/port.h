/*
 * port.h
 *
 * Created: 21/08/2021 01:26:11 AM
 *  Author: Salma
 */ 


#ifndef PORT_H_
#define PORT_H_

/* PUSHBUTTONS */
#define UP_DIR			INPUT
#define UP_PORT			PORT_D
#define UP_PIN			PIN0

#define DOWN_DIR		INPUT
#define DOWN_PORT		PORT_D
#define DOWN_PIN		PIN1

#define ON_OFF_DIR		INPUT
#define ON_OFF_PORT		PORT_D
#define ON_OFF_PIN		PIN2

/* LM35 */
#define LM35_DIR		INPUT
#define LM35_PORT		PORT_A
#define LM35_PIN		PIN1

/* COOLING ELEMENT */
#define COOLING_DIR		OUTPUT
#define COOLING_PORT	PORT_C
#define COOLING_PIN		PIN7

/* HEATING ELEMENT */
#define HEATING_DIR		OUTPUT
#define HEATING_PORT	PORT_C
#define HEATING_PIN		PIN6


#endif /* PORT_H_ */