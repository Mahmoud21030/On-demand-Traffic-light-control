/*
 * Timer.c
 *
 * Created: 9/29/2022 1:37:33 PM
 *  Author: Umars
 */ 
#include "../DIO/DIO.h"
#include "delay.h"
/**
* The function takes a delay time in milliseconds and the CPU frequency in MHz as arguments and then
* calculates the number of ticks required to achieve the desired delay and then sets the timer
* accordingly
*
* delaytime The time you want to delay in milliseconds.
* FCPU The clock frequency of the microcontroller.
*/
void delay_ms( float delaytime, float FCPU) /* minimum 1 msec (in Proteus 2 msec minimum )*/
{
	float Ttick = (1024.0 / (FCPU * 1000)); // tick in misec
	float Tmax = 256 * Ttick;
	uint8_t Tinit = 0;
	

	if (delaytime <= Tmax && delaytime >1) // if the delay < 262 msec
	{
		Tinit = ((Tmax - delaytime) / Ttick);
		TCNT0 = (uint8_t)Tinit;
		TCCR0 = 0x05; // normal mode and 1024 prescaler
		while ((read_bit(TIFR, 0) == 0) && TCCR0 != 0x00);
		TCCR0 = 0x00;
		set_bit(TIFR, 0); // clearing the overflow flag
	}
	
	else if (delaytime == 1); //due to syntax time already 1 msec is passed
	
	else if(delaytime > Tmax)
	{
		volatile int N = ceil(delaytime / Tmax);
		Tinit = 256.0 - ((float)delaytime / Ttick) / N ; 
		TCCR0 = 0x05;        // normal mode and 1024 prescaler
		for (int i = 0; i < N; i++)
		{
			TCNT0 = Tinit;
			while ((read_bit(TIFR, 0) == 0) && TCCR0 != 0x00);
			set_bit(TIFR, 0);// clearing the overflow flag
		}
		TCCR0 = 0x00;
	}
	
}