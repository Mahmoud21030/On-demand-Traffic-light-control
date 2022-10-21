/*
 * ADC.c
 *
 * Created: 9/29/2022 1:59:30 PM
 *  Author: Umars
 */ 

#include "ADC.h"

void ADC_init(uint8_t pin_number,uint8_t PS,uint8_t IE)
{
	Dio_init(&PORTA,pin_number,input); //initalizing as input the port is always portA
	ADMUX = pin_number; // if pin number is 0 -- ADMUX => 0x00 so ADMUX = Pin_number
	ADCSRA= PS;
	set_bit(ADCSRA,7); //enabling the ADC
	DIO_write(&ADCSRA,3,IE);
	if (IE == 1)
	{
		sei();
	}
}

void ADC_read(volatile uint16_t * value)
{
	while(read_bit(ADCSRA,4)==0);
	*value=ADC;
}
