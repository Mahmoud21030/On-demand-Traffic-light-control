
#include "LED.h"

void LEDS_init(void)
{
	/*Three LEDs for cars */
	Dio_init(&PORTA,PIN0,output);
	Dio_init(&PORTA,PIN1,output);
	Dio_init(&PORTA,PIN2,output);
	
	/*Three LEDs for pedestrians */
	Dio_init(&PORTB,PIN0,output);
	Dio_init(&PORTB,PIN1,output);
	Dio_init(&PORTB,PIN2,output);
}

void ALL_LEDS_OFF(void)
{
	CAR_LED_GREEN(off);
	CAR_LED_RED(off);
	CAR_LED_YELLOW(off);
	PED_LED_GREEN(off);
	PED_LED_RED(off);
	PED_LED_YELLOW(off);
}





