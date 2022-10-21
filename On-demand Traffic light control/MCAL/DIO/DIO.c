/*
 * DIO.c
 *
 * Created: 9/29/2022 1:34:06 PM
 *  Author: Umars
 */ 

#include "DIO.h"


/**
* The function Dio_init() takes a pointer to a port, a pin number, and a direction (input or output) and
* sets the pin to the direction specified.
*  PORT The port you want to use.
*  pin_number The pin number you want to use.
*  dirc 1 for output, 0 for input
*/
void Dio_init(volatile uint8_t *PORT, uint8_t pin_number, uint8_t dirc)
{
	// DDRx = PORTx - 1
	if (dirc == output)
	{
		set_bit(*(PORT-1), pin_number);
	}
	else if (dirc == input)
	{
		clear_bit(*(PORT-1), pin_number);
	}

}

/**
* If data is true, set the bit, otherwise clear the bit.
*
* PORT The port you want to write to.
* pin_number The pin number you want to write to.
* data 1 or 0
*/
void DIO_write(volatile uint8_t *PORT, uint8_t pin_number, uint8_t data)
{
	if (data == 1)
	{
		set_bit(*PORT, pin_number);
	}
	else if (data == 0)
	{
		clear_bit(*PORT, pin_number);
	}
}

/**
* "Reads the value of a pin and stores it in a variable."
*
* The function takes three arguments:
*
* 1. The port the pin is on.
* 2. The number of the pin.
* 3. The variable to store the value in
*
* PORT The port you want to read from.
* pin_number The pin number you want to read from.
* dest The destination variable to store the read value in.
*/
void DIO_read(volatile uint8_t *PORT, uint8_t pin_number, uint8_t *dest)
{
	// PINx = PORTx -2
	*dest = (*(PORT - 2) & (1 << pin_number)) >> pin_number;
	
}