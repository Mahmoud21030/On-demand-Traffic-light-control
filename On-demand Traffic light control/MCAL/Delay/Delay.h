/*
 * Delay.h
 *
 * Created: 9/29/2022 1:38:06 PM
 *  Author: Umars
 */ 


#ifndef DELAY_H_
#define DELAY_H_

#include "../MCAL.h"

/************************************************************************/
/*                           Timer0                                     */
/************************************************************************/

#define TCCR0 *((volatile uint8_t *)0x53)
#define TCNT0 *((volatile uint8_t *)0x52)
#define TIMSK *((volatile uint8_t *)0x59)
#define TIFR  *((volatile uint8_t *)0x58)
#define stop_timer() TCCR0 = 0x00;
void delay_ms(float delaytime,float  FCPU);


#endif /* DELAY_H_ */