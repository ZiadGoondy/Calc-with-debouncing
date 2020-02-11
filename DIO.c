/*
 * DIO.c
 *
 *  Created on: Aug 31, 2019
 *      Author: Hardware
 */
#include "Std_types.h"
#include "Registers.h"
#include "bitoperations.h"
#include "DIO.h"


void DIO_SetPinDirection(U8 Port_number , U8 Pin_number , U8 Direction ){
	switch(Port_number)
	{

	case PORT0 :
		if (Direction){
			SET_BIT(DDRA ,Pin_number );
		}
		else {
			CLR_BIT(DDRA ,Pin_number);
		}
		break;

	case PORT1 :
		if (Direction){
			SET_BIT(DDRB ,Pin_number );
		}
		else {
			CLR_BIT(DDRB ,Pin_number);
		}
		break;

	case PORT2 :
		if (Direction){
			SET_BIT(DDRC ,Pin_number );
		}
		else {
			CLR_BIT(DDRC ,Pin_number);
		}
		break;

	case PORT3 :
		if (Direction){
			SET_BIT(DDRD ,Pin_number );
		}
		else {
			CLR_BIT(DDRD ,Pin_number);
		}
		break;
	}
}
void DIO_SetPinPullUp(U8 Port_number , U8 Pin_number ){
	switch(Port_number){

		case PORT0 :

			SET_BIT(PORTA ,Pin_number );

			break;

		case PORT1 :

			SET_BIT(PORTB ,Pin_number );

			break;

		case PORT2 :

			SET_BIT(PORTC ,Pin_number );

			break;

		case PORT3 :

			SET_BIT(PORTD ,Pin_number );

			break;
	}
}
void DIO_SetPinValue(U8 Port_number , U8 Pin_number , U8 Value ){
	switch(Port_number){


		case PORT0 :

		if (Value){
			SET_BIT(PORTA ,Pin_number );
		}
		else {
			CLR_BIT(PORTA ,Pin_number);
		}

		break;

	case PORT1 :

		if (Value){
			SET_BIT(PORTB ,Pin_number );
		}
		else {
			CLR_BIT(PORTB ,Pin_number);
		}

		break;

	case PORT2 :
		if (Value){
			SET_BIT(PORTC ,Pin_number );
		}
		else {
			CLR_BIT(PORTC ,Pin_number);
		}


		break;

	case PORT3 :

		if (Value){
			SET_BIT(PORTD ,Pin_number );
		}
		else {
			CLR_BIT(PORTD ,Pin_number);
		}

		break;
	}

}
U8 DIO_GetPinValue(U8 Port_number , U8 Pin_number ){
	U8 x ;
	switch(Port_number){

			case PORT0 :

				x = GET_BIT(PINA ,Pin_number );
				break;

			case PORT1 :

				x = GET_BIT(PINB ,Pin_number );


				break;

			case PORT2 :

				x = GET_BIT(PINC ,Pin_number );

				break;

			case PORT3 :

				x = GET_BIT(PIND ,Pin_number );
				break;
	}
					return x ;
}
void DIO_SetPortDirection(U8 Port_number , U8 Direction ){
	switch(Port_number)
		{

		case PORT0 :
			if (Direction){
				DDRA = 0xFF;
			}
			else {
				DDRA = 0x00;
			}
			break;
		case PORT1 :
			if (Direction){
				DDRB = 0xFF;
			}
			else {
				DDRB = 0x00;
			}
			break;

		case PORT2 :
			if (Direction){
				DDRC = 0xFF;
			}
			else {
				DDRC = 0x00;
			}
			break;

		case PORT3 :
			if (Direction){
				DDRD = 0xFF;
			}
			else {
				DDRD = 0x00;
			}
			break;
		}
}
void DIO_SetPortValue(U8 Port_number , U8 Value ){
	switch(Port_number)
			{

	case PORT0 :
		PORTA = Value ;
		break;
	case PORT1 :
		PORTB = Value ;
		break;

	case PORT2 :
		PORTC = Value ;
		break;

	case PORT3 :
		PORTD = Value ;
		break;
	}
}
void DIO_SetPortPullUp(U8 Port_number){
	switch(Port_number){

		case PORT0 :

			PORTA = 0xFF;

			break;

		case PORT1 :

			PORTB = 0xFF;

			break;

		case PORT2 :

			PORTC = 0xFF;

			break;

		case PORT3 :

			PORTD = 0xFF;

			break;
	}
}
