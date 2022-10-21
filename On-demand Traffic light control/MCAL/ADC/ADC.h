/*
 * ADC.h
 *
 * Created: 9/29/2022 1:59:38 PM
 *  Author: Umars
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "../MCAL.h"

/************************************************************************/
/*								ADC                                     */
/************************************************************************/
#define ADC    *((volatile uint16_t *)0x24)
#define ADMUX  *((volatile uint8_t *)0x27)
#define ADCSRA *((volatile uint8_t *)0x26)

#define PS2 0x00
#define PS4 0x02
#define PS8 0x03
#define PS16 0x04
#define PS32 0x05
#define PS64 0x06
#define PS128 0x07

#define start_ADC()	set_bit(ADCSRA,6)
#define stop_ADC()	clear_bit(ADCSRA,6)
//#define EXT_ADC __vector_16
void ADC_init(uint8_t pin_number,uint8_t PS,uint8_t IE);

void ADC_read(volatile uint16_t * value);




#endif /* ADC_H_ */