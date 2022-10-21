/*
 * CFile1.c
 *
 * Created: 9/29/2022 1:46:34 PM
 *  Author: Umars
 */ 

#include "interrupt.h"
/**
 * This function is used to initalize the interrupt registers.
 * INTx The interrupt pin you want to use.
 * controlling the sense
 */
void interrupt_reg(uint8_t INTx, uint8_t sense)
{
	
    sei(); // 1.enable global interrupt

    switch (INTx)
    {
    case INT0_num:
        switch (sense) // 2.choose how to sense
        {
        case lowlevel:
            clear_bit(MCUCR, 0);
            clear_bit(MCUCR, 1);
            break;
        case anychange:
            set_bit(MCUCR, 0);
            clear_bit(MCUCR, 1);
            break;
        case falling:
            clear_bit(MCUCR, 0);
            set_bit(MCUCR, 1);
            break;
        case rising:
            set_bit(MCUCR, 0);
            set_bit(MCUCR, 1);
            break;
        }

        set_bit(GICR, 6); // 3.Choose interrupt Port
        break;

    case INT1_num:
        switch (sense) // 2.choose how to sense
        {
        case lowlevel:
            clear_bit(MCUCR, 2);
            clear_bit(MCUCR, 3);
            break;
        case anychange:
            set_bit(MCUCR, 2);
            clear_bit(MCUCR, 3);
            break;
        case falling:
            clear_bit(MCUCR, 2);
            set_bit(MCUCR, 3);
            break;
        case rising:
            set_bit(MCUCR, 2);
            set_bit(MCUCR, 3);
            break;
        }
        set_bit(GICR, 7); // 3.Choose interrupt Port
        break;

    case INT2_num:
        switch (sense) // 2.choose how to sense
        {

        case falling:
            clear_bit(MCUCSR, 1);
            break;
        case rising:
            set_bit(MCUCSR, 1);
            break;
        }
        set_bit(GICR, 5); // 3.Choose interrupt Port
        break;
    }
}