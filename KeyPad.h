/*
 * KeyPad.h
 *
 *  Created on: Sep 13, 2019
 *      Author: Hardware
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_
//.......configrations........//
#define keypadPort PORT3

#define ROW0PIN PIN0
#define ROW1PIN PIN1
#define ROW2PIN PIN2
#define ROW3PIN PIN3

#define ROW0DIR OUTPUT
#define ROW1DIR OUTPUT
#define ROW2DIR OUTPUT
#define ROW3DIR OUTPUT

#define COL0PIN PIN4
#define COL1PIN PIN5
#define COL2PIN PIN6
#define COL3PIN PIN7

#define COL0DIR INPUT
#define COL1DIR INPUT
#define COL2DIR INPUT
#define COL3DIR INPUT

void keypad_Init(void);
U8 keypad_scan(void);
#endif /* KEYPAD_H_ */
