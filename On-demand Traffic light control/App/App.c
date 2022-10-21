


#include "App.h"

int main(void)
{	
	initialize();

	while (1)
	{
		Appstart();
	}

}

void Appstart(void)
{
	case_director();
}
void initialize(void)
{
	Traffic_button_init();
	LEDS_init();
}

ISR(EXT_INT_0)
{
	INT_mode();
}

void case_director(void)
{
	while (1)
	{
		switch(NEXT_STATE)
		{
			case CAR_GREEN:
			CAR_GREEN_STATE();
			break;
			
			case COMMON_YELLOW:
			COMMON_YELLOW_STATE();
			break;
			
			case CAR_RED:
			CAR_RED_STATE();
			break;
			
			
			case PED_GREEN:
			PED_GREEN_STATE();
			break;
			
			case PED_YELLOW:
			PED_YELLOW_STATE();
			break;
			
			case PED_RED:
			PED_RED_STATE();
			break;

			
		}
	}
}

void INT_mode(void)
{
	if (returned_interrupt == 0) // ignore interrupt signal if the previous ISR didn't end yet
	{
		switch(NEXT_STATE)
		{
			case CAR_GREEN:
			PED_LED_RED(on);
			NEXT_STATE = COMMON_YELLOW;
			returned_interrupt = 1;
			break;
			
			case COMMON_YELLOW:
			CAR_LED_YELLOW(off); //helps for sync of both yellows
			returned_interrupt = 1;
			break;
			
			case CAR_RED:
			NEXT_STATE = PED_GREEN;
			stop_timer();//it'll reset the timer for giving the pedestrian more time to cross
			returned_interrupt = 1;
			break;
			
			case PED_RED:
			PED_LED_RED(on);
			NEXT_STATE = COMMON_YELLOW;
			returned_interrupt = 1;
			break;
			
			default:
			break;
			
		}
	}
	
}

/**
 * It turns on the green led for 5 seconds, then turns it off.
 */
void CAR_GREEN_STATE(void)
{
    ALL_LEDS_OFF(); // just for insurance purposes.

    CAR_LED_GREEN(on); // enabling the Green led for 5 sec
    delay_ms(5000, Freq);
    CAR_LED_GREEN(off);

    if (returned_interrupt == 0) // if there is no interrupt ,it'll direct the program to yellow state
    {
        PREVIOUS_STATE = CAR_GREEN; // common yellow state needs it to determine the next state
        NEXT_STATE = COMMON_YELLOW;
    }
}


/**
 * The function is called when the previous state was either CAR_GREEN or CAR_RED. 
 * The function turns off all LEDs, then blinks the yellow LED for 5 seconds. 
 * If there was an interrupt, the yellow LED blinks and the red LED is turned on. 
 * After 5 seconds, the yellow LED is turned off. 
 * If there was no interrupt, the next state is either CAR_GREEN or CAR_RED depends 
 * on the previous state . 
 * If there was an interrupt, the next state is PED_GREEN
 */
void COMMON_YELLOW_STATE(void)
{
    ALL_LEDS_OFF(); // just for insurance purposes.

    for (int i = 0; i < 20; i++)
    {
        CAR_LED_YELLOW_toggle(); /* normal mode blinks yellow*/

        if (returned_interrupt == 1)
        /* if there is interrupt, the both yellow blinks and PED red (on)*/
        {
            PED_LED_RED(on);
            PED_LED_YELLOW_toggle();
        }

        delay_ms(250, Freq); /*250 ms * 20= 5000 ms = 5sec*/
    }

    CAR_LED_YELLOW(off);
    PED_LED_YELLOW(off);

    if (returned_interrupt == 0) /*normal mode director*/
    {
        if (PREVIOUS_STATE == CAR_GREEN)
        /*if PREVIOUS_STATE is green then the next should be red*/
        {
            NEXT_STATE = CAR_RED;
        }
        else
        /*if PREVIOUS_STATE is red then the next should be green*/
        {
            NEXT_STATE = CAR_GREEN;
        }
    }
    else /* interrupt mode director*/
    {
        NEXT_STATE = PED_GREEN;
    }
}
/**
 * The function turns on the red LED for 5 seconds, then turns it off. If the interrupt is not
 * triggered, the next state is the common yellow state
 */
void CAR_RED_STATE(void)
{
    ALL_LEDS_OFF(); // just for insurance purposes.

    CAR_LED_RED(on);
    delay_ms(5000, Freq);
    CAR_LED_RED(off);

    if (returned_interrupt == 0)
    {
        PREVIOUS_STATE = CAR_RED; // common yellow state needs it to determine the next state
        NEXT_STATE = COMMON_YELLOW;
    }
}

/**
 * Turn off all LEDs, turn on the green pedestrian LED, turn on the red car LED, wait 5 seconds, set
 * the next state to PED_YELLOW.
 */
void PED_GREEN_STATE(void)
{
    ALL_LEDS_OFF();

    PED_LED_GREEN(on);
    CAR_LED_RED(on);
    delay_ms(5000, Freq);
	CAR_LED_RED(off);
    NEXT_STATE = PED_YELLOW;
}

/**
 * The function turns on the green pedestrian light and turns off the red car light. Then it toggles
 * the yellow car and pedestrian lights 20 times with a 250ms delay between each toggle. Then it turns
 * off the yellow pedestrian light and the green pedestrian light. Finally, it sets the next state to
 * PED_RED
 */
void PED_YELLOW_STATE(void)
{
    ALL_LEDS_OFF();
	
    PED_LED_GREEN(on);

    for (int i = 0; i < 20; i++)
    {
        CAR_LED_YELLOW_toggle();
        PED_LED_YELLOW_toggle();
        delay_ms(250, Freq);
    }
	
    PED_LED_YELLOW(off);
    PED_LED_GREEN(off);

    NEXT_STATE = PED_RED;
}

/**
 * Same as Car green state but the Pedestrian red is on.
 */
void PED_RED_STATE(void)
{
    ALL_LEDS_OFF();

    returned_interrupt = 0;
	 // it ends the ISR and back to normal mode and being ready for another input

    PED_LED_RED(on);
    CAR_LED_GREEN(on);
    delay_ms(5000, Freq);
    PED_LED_RED(off);
    CAR_LED_GREEN(off);

    if (returned_interrupt == 0)
    {
        PREVIOUS_STATE = CAR_GREEN; // helps yellow state to determine the direction
        NEXT_STATE = COMMON_YELLOW; // return to normal
    }
}
