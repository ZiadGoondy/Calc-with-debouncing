/*
 * EX-INT.c
 *
 *  Created on: Sep 14, 2019
 *      Author: Hardware
 */
#include "Std_types.h"
#include "bitoperations.h"
#include "Registers.h"
#include <avr/interrupt.h>

static void (*Gptr0)(void);
static void (*Gptr1)(void);
static void (*Gptr2)(void);


void ExINT0_SetISR(void (*ptr)(void)){
	Gptr0 = ptr;
}

void ExINT1_SetISR(void (*ptr)(void)){
	Gptr1 = ptr;
}
void ExINT2_SetISR(void (*ptr)(void)){
	Gptr2 = ptr;
}

void ExINT0_Init(void){
	CLR_BIT(DDRD , 2 );
	SET_BIT(PORTD ,2 );

	SET_BIT(SREG ,7 );
	SET_BIT(GICR ,6 );

#if (FallingEdge == 1)

	SET_BIT(MCUCR ,1 );
	CLR_BIT(MCUCR , 0 );
#else
	SET_BIT(MCUCR ,1 );
	SET_BIT(MCUCR , 0 );
#endif

}
void ExINT1_Init(void){
	CLR_BIT(DDRD , 3 );
	SET_BIT(PORTD ,3 );

	SET_BIT(SREG ,7 );
	SET_BIT(GICR ,7 );
#if (FallingEdge == 1)

	SET_BIT(MCUCR ,3 );
	CLR_BIT(MCUCR , 2 );
#else
	SET_BIT(MCUCR ,3 );
	SET_BIT(MCUCR , 2 );
#endif

}
void ExINT2_Init(void){
	CLR_BIT(DDRB , 2 );
	SET_BIT(PORTB ,2 );

	SET_BIT(SREG ,7 );
	SET_BIT(GICR ,5 );

#if (FallingEdge == 1)
	CLR_BIT(MCUCSR ,6 );
#else
	SET_BIT(MCUCSR ,6 );
#endif


}
ISR(INT0_vect){
	Gptr0();
}

ISR(INT1_vect){
	Gptr1();
}
ISR(INT2_vect){
	Gptr2();
}
