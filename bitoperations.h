#ifndef BITOPERATIONS
#define BITOPERATIONS
#define SET_BIT(X , BIT) (X |= (unsigned char)(1<<BIT))
#define CLR_BIT(X , BIT) (X &=~(unsigned char)(1<<BIT))
#define TOG_BIT(X , BIT) (X ^= (unsigned char)(1<<BIT))
#define GET_BIT(X , BIT) ((X>>BIT) & (unsigned char) 1)

#endif  