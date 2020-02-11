/*
 * lcd.c
 *
 *  Created on: Sep 7, 2019
 *      Author: Hardware
 */

#include "Std_types.h"
#include "bitoperations.h"
#include "lcd.h"
#include "DIO.h"
#include <util/delay.h>
void Lcd_Init (void){
	DIO_SetPortDirection(LcdPort , OUTPUT);
	DIO_SetPinDirection(LcdEn , EnablePIN , OUTPUT);
	DIO_SetPinDirection(RwPort , RwPIN , OUTPUT);
	DIO_SetPinDirection(RsPort , RsPIN , OUTPUT);
	Lcd_SendComand (LcdSet);
	Lcd_SendComand (LcdDesplayControl);
	Lcd_SendComand (LcdEntry);
	Lcd_SendComand(RHome);
	Lcd_SendComand(ClrLcd);
}
void Lcd_SendComand (U8 command){
	DIO_SetPinValue(RsPort , RsPIN , 0 );
	DIO_SetPinValue(RwPort , RwPIN , 0 );
	_delay_ms(2);
	DIO_SetPinValue(LcdEn , EnablePIN , 1 );
	_delay_ms(2);
	DIO_SetPortValue(LcdPort , command );
	_delay_ms(2);
	DIO_SetPinValue(LcdEn , EnablePIN , 0 );
	_delay_ms(2);
}
void Lcd_SendData (char chaar){
	DIO_SetPinValue(RsPort , RsPIN , 1 );
	DIO_SetPinValue(RwPort , RwPIN , 0 );
	_delay_ms(2);
	DIO_SetPinValue(LcdEn , EnablePIN , 1 );
	_delay_ms(2);
	DIO_SetPortValue(LcdPort , chaar );
	_delay_ms(2);
	DIO_SetPinValue(LcdEn , EnablePIN , 0 );
	_delay_ms(2);
}
void Lcd_PrintString (char *string){
	int i =0 ;
	while (string[i] != '\0'){
		Lcd_SendData (string[i]);
		i++;
	}
}
void Lcd_PrintNumber(int number){
	char string[16] = {0};
	short int i = 0;
	char flag = 0;
	if(number == 0){
		Lcd_SendData('0');
		return;
	}
	else if(number < 0){
		number = number * -1;
		flag = 1;
	}

	while(number > 0){
		string[i] = (number%10) + '0';
		number = number / 10;
		i++;
	}

	i--;
	if(flag == 1) Lcd_SendData('-');
	while(i >= 0){
		Lcd_SendData(string[i]);
		i--;
	}
}
void Lcd_PrintFloatNumber(float number){
	Lcd_PrintNumber(number);
	number = (number - (int)number) * 100;
	Lcd_SendData('.');
	Lcd_PrintNumber(number);
}
