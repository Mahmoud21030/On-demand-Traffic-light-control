/*
 * button.c
 *
 * Created: 9/28/2022 2:55:02 AM
 *  Author: Umars
 */ 

#include "button.h"


/**
 * This function initializes a button by setting the pin as an input and setting the pull-up/pull-down
 * resistor.
 * PORT The port you want to use.
 * pin_number the pin number of the port you want to use.
 * pull up or down
 */
void button_init(volatile uint8_t *PORT, uint8_t pin_number, uint8_t pull)
{
    Dio_init(PORT, pin_number, input);
    if (pull == up)
    {
        set_bit(*PORT, pin_number);
    }
    else if (pull == down)
    {
        clear_bit(*PORT, pin_number);
    }
}
/* For reading we can just use DIO_read() function ..there is no difference here*/

void Traffic_button_init(void)
{
	button_init(&PORTD,PIN2,up); /*initializing button pull-up*/
	interrupt_reg(INT0_num,falling); /*initializing falling edge and int0*/
}

/*not needed in this project*/
uint8_t button_read(volatile uint8_t *PORT, uint8_t pin_number)
{
	uint8_t data=0;
	DIO_read(PORT,pin_number,&data);
	return data;
}



