#ifndef __G_SYSTEM__
#define __G_SYSTEM__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Field
{
	unsigned int width;
	unsigned int height;
	unsigned int hDiagonal;
}S_field;
typedef struct Point
{
	unsigned int x;
	unsigned int y;
}S_point;
typedef struct Effect
{
	unsigned int base;
	double minMultip;
	double maxMultip;
}S_effect;

S_field field;
S_effect effect;

unsigned int calcLen(S_point *p1,S_point *p2);
void square(void);
double calcMultip(void);
unsigned int calcEffect(unsigned int Length,double multip);



#endif
