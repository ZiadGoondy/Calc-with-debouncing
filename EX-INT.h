/*
 * EX-INT.h
 *
 *  Created on: Sep 14, 2019
 *      Author: Hardware
 */

#ifndef EX_INT_H_
#define EX_INT_H_

#define FallingEdge 1


void ExINT0_SetISR(void (*ptr)(void));
void ExINT1_SetISR(void (*ptr)(void));
void ExINT2_SetISR(void (*ptr)(void));
void ExINT0_Init(void);
void ExINT1_Init(void);
void ExINT2_Init(void);

#endif /* EX_INT_H_ */
