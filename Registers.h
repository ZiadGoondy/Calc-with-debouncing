/*
 * Registers.h
 *
 *  Created on: Aug 30, 2019
 *      Author: Hardware
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_
#define PORTA (*((volatile U8 *)0X3B))
#define DDRA (*((volatile U8 *)0X3A))
#define PINA (*((volatile U8 *)0X39))

#define PORTB (*((volatile U8 *)0X38))
#define DDRB (*((volatile U8 *)0X37))
#define PINB (*((volatile U8 *)0X36))

#define PORTC (*((volatile U8 *)0X35))
#define DDRC (*((volatile U8 *)0X34))
#define PINC (*((volatile U8 *)0X33))

#define PORTD (*((volatile U8 *)0X32))
#define DDRD (*((volatile U8 *)0X31))
#define PIND (*((volatile U8 *)0X30))

#define SREG (*((volatile U8 *)0X5F))
#define SPH (*((volatile U8 *)0X5E))
#define SPL (*((volatile U8 *)0X5D))
#define OCR0 (*((volatile U8 *)0X5C))
#define GICR (*((volatile U8 *)0X5B))
#define GIFR (*((volatile U8 *)0X5A))
#define TIMSK (*((volatile U8 *)0X59))
#define TIFR (*((volatile U8 *)0X58))
#define SPMCR (*((volatile U8 *)0X57))
#define TWCR (*((volatile U8 *)0X56))
#define MCUCR (*((volatile U8 *)0X55))
#define MCUCSR (*((volatile U8 *)0X54))
#define TCCR0 (*((volatile U8 *)0X53))
#define TCNT0 (*((volatile U8 *)0X52))
#define OSCCAL (*((volatile U8 *)0X51))
#define SFIOR (*((volatile U8 *)0X50))

#define TCCR1A (*((volatile U8 *)0X4F))
#define TCCR1B (*((volatile U8 *)0X4E))
#define TCNT1H (*((volatile U8 *)0X4D))
#define TCNT1L (*((volatile U8 *)0X4C))
#define OCR1AH (*((volatile U8 *)0X4B))
#define OCR1AL (*((volatile U8 *)0X4A))
#define OCR1BH (*((volatile U8 *)0X49))
#define OCR1BL (*((volatile U8 *)0X48))
#define ICR1H (*((volatile U8 *)0X47))
#define ICR1L (*((volatile U8 *)0X46))
#define TCCR2 (*((volatile U8 *)0X45))
#define TCNT2 (*((volatile U8 *)0X44))
#define OCR2 (*((volatile U8 *)0X43))
#define ASSR (*((volatile U8 *)0X42))
#define WDTCR (*((volatile U8 *)0X41))
#define UBRRH (*((volatile U8 *)0X40))

#define EEARH (*((volatile U8 *)0X3F))
#define EEARL (*((volatile U8 *)0X3E))
#define EEDR (*((volatile U8 *)0X3D))
#define EECR (*((volatile U8 *)0X3C))

#define SPDR (*((volatile U8 *)0X2F))
#define SPSR (*((volatile U8 *)0X2E))
#define SPCR (*((volatile U8 *)0X2D))
#define UDR (*((volatile U8 *)0X2C))
#define UCSRA (*((volatile U8 *)0X2B))
#define UCSRB (*((volatile U8 *)0X2A))
#define UBRRL (*((volatile U8 *)0X29))
#define ACSR (*((volatile U8 *)0X28))
#define ADMUX (*((volatile U8 *)0X27))
#define ADCSRA (*((volatile U8 *)0X26))
#define ADCH (*((volatile U8 *)0X25))
#define ADCL (*((volatile U8 *)0X24))
#define TWDR (*((volatile U8 *)0X23))
#define TWAR (*((volatile U8 *)0X22))
#define TWSR (*((volatile U8 *)0X21))
#define TWBR (*((volatile U8 *)0X20))

#endif /* REGISTERS_H_ */
