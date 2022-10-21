


#ifndef APP_H_
#define APP_H_

void CAR_GREEN_STATE(void);
void COMMON_YELLOW_STATE(void);
void CAR_RED_STATE(void);
void BOTH_YELLOW_STATE(void);
void PED_GREEN_STATE(void);
void PED_YELLOW_STATE(void);
void PED_RED_STATE(void);
void case_director(void);
void INT_mode(void);
void Appstart(void);
void initialize(void);

#include "../MCAL/MCAL.h"
#include "../ECUAL/ECUAL.h"

#define Freq 1 //MHz



Traffic_State NEXT_STATE = CAR_GREEN;
Traffic_State PREVIOUS_STATE = COMMON_YELLOW;

uint8_t returned_interrupt =0;


#endif /* APP_H_ */