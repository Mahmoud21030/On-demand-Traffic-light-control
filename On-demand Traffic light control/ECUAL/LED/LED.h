 


#ifndef LED_H_
#define LED_H_

#include "../ECUAL.h"

typedef enum
{
	CAR_GREEN,
	COMMON_YELLOW,
	CAR_RED,
	PED_YELLOW,
	PED_GREEN,
	PED_RED
}Traffic_State;


 /*Cars LEDS control*/
#define CAR_LED_GREEN(state) DIO_write(&PORTA,PIN0,state)
#define CAR_LED_YELLOW(state) DIO_write(&PORTA,PIN1,state)
#define CAR_LED_RED(state) DIO_write(&PORTA,PIN2,state)
#define CAR_LED_YELLOW_toggle()	toggle_bit(PORTA,PIN1)

 /*Pedestrian LEDS control*/
#define PED_LED_GREEN(state) DIO_write(&PORTB,PIN0,state)
#define PED_LED_YELLOW(state) DIO_write(&PORTB,PIN1,state)
#define PED_LED_RED(state) DIO_write(&PORTB,PIN2,state)
#define PED_LED_YELLOW_toggle()	toggle_bit(PORTB,PIN1)

void LEDS_init(void);
void ALL_LEDS_OFF(void);

#endif /* LED_H_ */