/*
 * SwD.h
 *
 *  Created on: Oct 16, 2019
 *      Author: Hardware
 */

#ifndef SWD_H_
#define SWD_H_

//enum state {relased ,pressed ,prepressed ,prerelased};

#define keypadPort PORT3

#define ButtonNum ((4*ButtonRow)+(ButtonCol))

#define relased 0
#define pressed 1
#define intermidiate 2
#define MaxCount 1000
U8 ButtonPressed (U8 ButtonRow , U8 ButtonCol);

#endif /* SWD_H_ */
