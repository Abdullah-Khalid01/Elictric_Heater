/*
 * _7_segment.h
 *
 * Created: 14/01/43 12:48:38 ص
 *  Author: ABDULLAH 01
 */ 


#ifndef SEGMENT_H_
#define SEGMENT_H_

#include "DIO.h"
void segment7_init(void);
void first_segment7_display(void);
void mode_selection(void);
void segment7_Stop (void);
void segment7_Set_Number(uint16 num);

#endif /* 7_SEGMENT_H_ */