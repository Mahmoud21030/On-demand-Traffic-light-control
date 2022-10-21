/*
 * interrupt.h
 *
 * Created: 9/29/2022 1:46:52 PM
 *  Author: Umars
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../MCAL.h"


/************************************************************************/
/*						         Interrupt                               */
/************************************************************************/

#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

/* External Interrupt Request 0 */
#define EXT_INT_0 __vector_1
#define	INT0_num 0

/* External Interrupt Request 1 */
#define EXT_INT_1 __vector_2
#define	INT1_num 1
/* External Interrupt Request 2 */
#define EXT_INT_2 __vector_3
#define	INT2_num 2

# define sei()  __asm__ __volatile__ ("sei" ::: "memory")
# define cli()  __asm__ __volatile__ ("cli" ::: "memory")

#define MCUCR	*((volatile uint8_t *)0x55)
#define GICR	*((volatile uint8_t *)0x5B)
#define MCUCSR  *((volatile uint8_t *)0x54)
#define GIFR	*((volatile uint8_t *)0x5A)

#define lowlevel 0
#define anychange 1
#define falling 2
#define rising 3


void interrupt_reg(uint8_t INTx, uint8_t sense);


#endif /* INTERRUPT_H_ */