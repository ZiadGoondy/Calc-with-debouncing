

#include "Std_types.h"
#include "bitoperations.h"
#include "KeyPad.h"
#include "DIO.h"
#include <util/delay.h>
#include "SwD.h"
char keypad[4][4]={
        {'1','2','3','+'},
        {'4','5','6','-'},
        {'7','8','9','*'},
        {'=','0','%','/'}
        };

void keypad_Init(void){
	DIO_SetPinDirection( keypadPort , COL0PIN , INPUT );
	DIO_SetPinDirection( keypadPort , COL1PIN , INPUT );
	DIO_SetPinDirection( keypadPort , COL2PIN , INPUT );
	DIO_SetPinDirection( keypadPort , COL3PIN , INPUT );

	DIO_SetPinDirection( keypadPort , ROW0PIN , OUTPUT );
	DIO_SetPinDirection( keypadPort , ROW1PIN , OUTPUT );
	DIO_SetPinDirection( keypadPort , ROW2PIN , OUTPUT );
	DIO_SetPinDirection( keypadPort , ROW3PIN , OUTPUT );

	DIO_SetPinPullUp(keypadPort , COL0PIN );
	DIO_SetPinPullUp(keypadPort , COL1PIN );
	DIO_SetPinPullUp(keypadPort , COL2PIN );
	DIO_SetPinPullUp(keypadPort , COL3PIN );

	DIO_SetPinValue(keypadPort , ROW0PIN , 1 );
	DIO_SetPinValue(keypadPort , ROW1PIN , 1 );
	DIO_SetPinValue(keypadPort , ROW2PIN , 1 );
	DIO_SetPinValue(keypadPort , ROW3PIN , 1 );

}

U8 keypad_scan(void){
	U8 ret=100;
	U8 i=0 , j=0;
	for(i=0 ; i<4 ; i++ ){
		DIO_SetPinValue(keypadPort , ROW0PIN , 1 );
		DIO_SetPinValue(keypadPort , ROW1PIN , 1 );
		DIO_SetPinValue(keypadPort , ROW2PIN , 1 );
		DIO_SetPinValue(keypadPort , ROW3PIN , 1 );

		DIO_SetPinValue(keypadPort , i , 0 );
		for (j=0 ; j<4 ; j++){

				//if (DIO_GetPinValue(keypadPort,j+4) == 0 ){
			if (ButtonPressed (i , j)== pressed ){
					ret=keypad[i][j];
					return ret;
				}
		}
	}
	return ret;

}
