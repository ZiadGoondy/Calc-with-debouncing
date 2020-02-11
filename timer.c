/*
 * timer.c
 *
 *  Created on: Oct 11, 2019
 *      Author: Hardware
 */
#include "bitoperations.h"
#include "Std_types.h"
#include "Registers.h"
#include "EX-INT.h"

void Timer_init(void){
#if (TimerMode == 0)
	CLR_BIT(TCCR0 ,3);
	CLR_BIT(TCCR0 ,6);
#endif
#if (Timerclk == 0)
	SET_BIT(TCCR0 ,0);
	CLR_BIT(TCCR0 ,1);
	SET_BIT(TCCR0 ,2);
#endif
	SET_BIT(SREG ,7 );
	SET_BIT( TIMSK , 0);
}
