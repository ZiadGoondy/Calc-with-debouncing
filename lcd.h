/*
 * lcd.h
 *
 *  Created on: Sep 7, 2019
 *      Author: Hardware
 */

#ifndef LCD_H_
#define LCD_H_
/*.........configrations...........*/
#define LcdPort PORT2  //DATALINES PORT
#define RsPort PORT1
#define RwPort PORT1
#define LcdEn PORT1

#define EnablePIN PIN0
#define RwPIN PIN1
#define RsPIN PIN2



/*.........Command List....... */

#define INPUT 0
#define OUTPUT 1
#define LcdSet 0x38
#define LcdDesplayControl 0x0F
#define LcdEntry 0x06
#define ClrLcd 0x01
#define RHome 0x02
#define Lcdline2 0xC0

void Lcd_Init (void);
void Lcd_SendComand (U8 command);
void Lcd_SendData (char chaar);
void Lcd_PrintString (char *string);
void Lcd_PrintNumber(int number);
void Lcd_PrintFloatNumber(float number);

#endif /* LCD_H_ */
