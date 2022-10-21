/*
 * DIO.h
 *
 * Created: 9/29/2022 1:34:24 PM
 *  Author: Umars
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../MCAL.h"

/* Defining the address of the registers PORTA. */
#define PINA  *((volatile uint8_t *)0x39)
#define DDRA  *((volatile uint8_t *)0x3A)
#define PORTA *((volatile uint8_t *)0x3B)

/* Defining the address of the registers PORTB. */
#define PINB  *((volatile uint8_t *)0x36)
#define DDRB  *((volatile uint8_t *)0x37)
#define PORTB *((volatile uint8_t *)0x38)

/* Defining the address of the registers PORTC. */
#define PINC  *((volatile uint8_t *)0x33)
#define DDRC  *((volatile uint8_t *)0x34)
#define PORTC *((volatile uint8_t *)0x35)

/* Defining the address of the registers PORTC. */
#define PIND  *((volatile uint8_t *)0x30)
#define DDRD  *((volatile uint8_t *)0x31)
#define PORTD *((volatile uint8_t *)0x32)

#define PIN0 0x00
#define PIN1 0x01
#define PIN2 0x02
#define PIN3 0x03
#define PIN4 0x04
#define PIN5 0x05
#define PIN6 0x06
#define PIN7 0x07


/* Adjusting Bits */
#define set_bit(reg,bit)	reg |= (1<<bit)
#define clear_bit(reg,bit)  reg &= ~(1<<bit)
#define toggle_bit(reg,bit) reg ^= (1<<bit)
#define read_bit(reg,bit)  ((reg & (1 << bit)) >> bit)

#define output 1
#define input 0

void DIO_read(volatile uint8_t *PORT, uint8_t Number_pin_number, uint8_t *dest);
void DIO_write(volatile uint8_t *PORT, uint8_t Number_pin_number, uint8_t data);
void Dio_init(volatile uint8_t *PORT, uint8_t Number_pin_number, uint8_t dirc);



#endif /* DIO_H_ */