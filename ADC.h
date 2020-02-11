/*
 * ADC.h
 *
 *  Created on: Oct 15, 2019
 *      Author: Hardware
 */

#ifndef ADC_H_
#define ADC_H_


// ADCMode {SingleMode,FreeRunning,EXT_INT }
// Resolution { _8bit , _10bit}

enum Channel {ch0 ,ch1 ,ch2 ,ch3 ,ch4 ,ch5 ,ch6 ,ch7 };

#define _8bit 0
#define _10bit 1
#define SingleMode 0
#define FreeRunning 1
#define EXT_INT 2
/**********CONFIGRATION**************/

#define ADC_Mode SingleMode
#define ADC_Reso _8bit

/************************************/

void ADC_Init (void);

#if (ADC_Reso == _8bit)
	U8 ADC_Read (U8 channel);

#elif (ADC_Reso == _10bit)
	U16 ADC_Read (U8 channel);

#endif

#endif /* ADC_H_ */
