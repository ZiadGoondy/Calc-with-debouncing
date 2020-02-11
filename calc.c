/*
 * main.c
 *
 *  Created on: Aug 30, 2019
 *      Author: Hardware
 */
#include "bitoperations.h"
#include "Std_types.h"
#include "Registers.h"
#include <util/delay.h>
#include "DIO.h"
#include "lcd.h"
#include "KeyPad.h"
#include "EX-INT.h"
#include "SwD.h"

int calc (void){
	//..................initializing....................//
	keypad_Init();
	DIO_SetPortDirection(PORT0 , 1 );
	Lcd_Init ();
	char *hello = "WELCOME :)";
	Lcd_SendComand(ClrLcd);
	Lcd_PrintString(hello);
	_delay_ms(1000);
	Lcd_SendComand(ClrLcd);
	//................................................//
	char volatile chaar[16]={0};
	int i=0;
	int scan = 0 ;
	char f =0 ,g =0;
	char z1 =0 , z2 =0 , z3 =0 ;
	int volatile num1=0 , num2 =0 ;
	float  result=0;
	/*hello*/
	while (1){

		while (scan != '='){
		scan = keypad_scan();
		while (scan == no_key_pressed){
			scan = keypad_scan();
			f=1;
		}
			if (f==1){
				chaar[i] = scan;
				i++;
				Lcd_SendData(scan);
				f=0;
				g=1;
			}

		}
		if (g==1){
			Lcd_SendComand(ClrLcd);
			Lcd_PrintString (chaar);
			for (i=0 ; i<16 ; i++){
				if ((chaar[i]== '+')||(chaar[i]== '*')||(chaar[i]== '-')||(chaar[i]== '/')){
					z1=i; //last char for first num
					z2=i+1; //first char for second num
				}
			}
			for(i=z2 ; i<16 ; i++){
				if (chaar[i]== '='){
					z3=i; //last char for second num
				}
			}
			num1 = StoI (chaar ,0 ,z1);
			num2 = StoI (chaar ,z2,z3);

			switch (chaar[z1]){

				case '+':
					result = num1 + num2;
					break;
				case '*':
					result = num1 * num2;
					break;
				case '-':
					result = num1 - num2;
					break;
				case '/':
					 result = (float) num1 / num2;
					break;
			}
			Lcd_PrintFloatNumber(result);
		g=0;
		}

}
}



void ItoS (char *array ,int num){
    int i=0 ;
    while (num!=0){
        array[i]= num%10;
        num =num/10;
        i++;
    }

}
int StoI (char *array ,int start ,int end){
    int n =0, i=0;
    for (i=start ; i<end ; i++){
        if (array[i]== '\0') {break;}
        n=n*10+array[i]-'0';
    }
    return n;
}
