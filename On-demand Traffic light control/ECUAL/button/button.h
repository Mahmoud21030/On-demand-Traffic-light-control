/*
 * button.h
 *
 * Created: 9/28/2022 2:55:18 AM
 *  Author: Umars
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_


#include "../ECUAL.h"

#define up	 1
#define down 0

#define on 1
#define off 0

/*initializing the PIN 2 in PORTD and its interrupt INT0 */
/*initializing button pull-up*/
/*initializing falling edge and int0*/
void Traffic_button_init(void); 

/*initializing without Interrupts*/
void button_init(volatile uint8_t *PORT, uint8_t pin_number, uint8_t pull);


//  (Not needed in this project)
uint8_t button_read(volatile uint8_t *PORT, uint8_t pin_number);/*return value of the pin */
#endif /* BUTTON_H_ */