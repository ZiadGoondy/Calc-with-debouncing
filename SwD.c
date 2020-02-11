/*
 * SwD.c
 *
 *  Created on: Oct 16, 2019
 *      Author: Hardware
 */
#include "bitoperations.h"
#include "Std_types.h"
#include "Registers.h"
#include "DIO.h"
#include "SwD.h"
#include "lcd.h"



U8 ButtonPressed (U8  ButtonRow , U8  ButtonCol){

	U8 static  state[16]={0};
	U16 static count[16]={0};

	switch (state[ButtonNum]){
		case relased :
			if (DIO_GetPinValue(keypadPort,ButtonCol+4) == 0){
				state[ButtonNum] = intermidiate;
			}
			break;
		case intermidiate :

			while (DIO_GetPinValue(keypadPort,ButtonCol+4) == 0 ){
				++count[ButtonNum];
				if ((count[ButtonNum]) > MaxCount ){
					state[ButtonNum] = pressed;
					count[ButtonNum] =0;
					break;
				}
				else{
					state[ButtonNum] = pressed;
				}
			}
			count[ButtonNum] =0;
			break;

		case pressed :
			if (DIO_GetPinValue(keypadPort,ButtonCol+4) == 1 ){
				state[ButtonNum] = intermidiate;
			}
			/*if ((count[ButtonNum]) > MaxCount ){
				state[ButtonNum] = relased;
				count[ButtonNum] =0;
			}*/


			break;
	}
	return state[ButtonNum];


}


