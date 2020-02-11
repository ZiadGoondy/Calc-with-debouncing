/*
 * ADC.c
 *
 *  Created on: Oct 15, 2019
 *      Author: Hardware
 */
#include "bitoperations.h"
#include "Std_types.h"
#include "Registers.h"
#include "ADC.h"
#include "avr/interrupt.h"

#if (ADC_Reso == _10bit)
static U16 ADC_Result = 0;
static U16* ptrx = (U16*)&ADCL;
#elif (ADC_Reso == _8bit)
static U8 ADC_Result = 0;
static U16* ptrx = (U16*)&ADCH;
#endif


void ADC_Init (void){
	//ADC Enable//
	SET_BIT(ADCSRA,7);
	// set external Referdence //
	SET_BIT(ADMUX , 6);
	CLR_BIT( ADMUX , 7);
	//Adjusted left if 8bit resolution activated//
	#if (ADC_Reso == _8bit)
		SET_BIT(ADMUX , 6);
	#endif
	//ADC Pre_scaler Selections --> (1mega / 8 )//
		SET_BIT(ADCSRA,0);
		SET_BIT(ADCSRA,1);
		CLR_BIT(ADCSRA,2);
	// ADC completed Interrupt Enable
		/*SET_BIT(SREG ,7 );
		SET_BIT(ADCSRA,3);*/

	#if (ADC_Mode == SingleMode)
		CLR_BIT(ADCSRA,5);

	#elif (ADC_Mode == FreeRunning)
		SET_BIT(ADCSRA,5);
		//select source of auto triggering --> free running
		CLR_BIT(SFIOR,5);
		CLR_BIT(SFIOR,6);
		CLR_BIT(SFIOR,7);

	#elif (ADC_Mode == EXT_INT)
		SET_BIT(ADCSRA,5);
		//select source of auto triggering --> external interrupt
		CLR_BIT(SFIOR,5);
		SET_BIT(SFIOR,6);
		CLR_BIT(SFIOR,7);
	#endif
}

#if (ADC_Reso == _8bit)
	U8 ADC_Read (U8 channel){
		U8 ret=0;

#elif (ADC_Reso == _10bit)
	U16 ADC_Read (U8 channel){
		U16 ret=0;
#endif
		switch (channel){

		case ch0 :
			CLR_BIT(ADMUX , 0);
			CLR_BIT(ADMUX , 1);
			CLR_BIT(ADMUX , 2);
			break;
		case ch1 :
			SET_BIT(ADMUX , 0);
			CLR_BIT(ADMUX , 1);
			CLR_BIT(ADMUX , 2);
			break;
		case ch2 :
			CLR_BIT(ADMUX , 0);
			SET_BIT(ADMUX , 1);
			CLR_BIT(ADMUX , 2);
			break;
		case ch3 :
			SET_BIT(ADMUX , 0);
			SET_BIT(ADMUX , 1);
			CLR_BIT(ADMUX , 2);
			break;
		case ch4 :
			CLR_BIT(ADMUX , 0);
			CLR_BIT(ADMUX , 1);
			SET_BIT(ADMUX , 2);
			break;
		case ch5 :
			SET_BIT(ADMUX , 0);
			CLR_BIT(ADMUX , 1);
			SET_BIT(ADMUX , 2);
			break;
		case ch6 :
			CLR_BIT(ADMUX , 0);
			SET_BIT(ADMUX , 1);
			SET_BIT(ADMUX , 2);
			break;
		case ch7 :
			SET_BIT(ADMUX , 0);
			SET_BIT(ADMUX , 1);
			SET_BIT(ADMUX , 2);
			break;
		}

	#if ((ADC_Mode == SingleMode)||(ADC_Mode == FreeRunning))
		SET_BIT(ADCSRA,6);
		while (GET_BIT(ADCSRA,6));

		#if (ADC_Reso == _8bit)
			ret = ADCH;
			SET_BIT(ADCSRA,4);
		#elif (ADC_Reso == _10bit)
			ret = *ptrx;
			SET_BIT(ADCSRA,4);
		#endif
	#elif (ADC_Mode == EXT_INT)
			ret = (ADC_Result & (0x03FF));
	#endif
			return ret;
	}


ISR(ADC_vect){
	ADC_Result = *ptrx;

	SET_BIT(GIFR,6);
}
