#include "MCAL/MCAL.h"
#include "ECUAL/button/button.h"
#include "ECUAL/LED/LED.h"

void DIOtest(void);
void delaytest(void);
void int_test(void);

void main0()
{
	//DIOtest();
	//delaytest();
	int_test();
}

void DIOtest(void)
{
	/*driver dio test*/
	Dio_init(&PORTA,PIN0,output);
	Dio_init(&PORTA,PIN1,input);
	uint8_t data;
	/* write 1 on Port A PIN0 1 then write 0 */
	/*read from PIN1*/
	/*using debug*/
	DIO_write(&PORTA,PIN0,1);
	DIO_write(&PORTA,PIN0,0);
	DIO_read(&PORTA,PIN1,&data);
	////////////////////////////////////////
}

void delaytest(void)
{
	/*driver delay test*/
	//1 = Frequency of the cpu*/
	//delaying 20 ms
	delay_ms(20,1);
	delay_ms(20,1);
	//small error due to the instructions time
}

void int_test(void)
{
	/*interrupt driver test*/
	Dio_init(&PORTD,PIN3,input);
	interrupt_reg(INT1_num,rising);
	/* testing button and led*/
	while(1)
	delay_ms(20,1);
	
}

ISR(EXT_INT_1)
{
	delay_ms(20,1);
}