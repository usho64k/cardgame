#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct RectAngle
{
	unsigned int width;
	unsigned int height;
	unsigned int hDiagonal;
}S_rect;
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

S_rect field;
S_effect effect;

unsigned int calcLen(S_point *p1,S_point *p2)
{
	unsigned int X,Y,ret;
	double d_ret;
	if(p1->x > p2->x)
	{
		X = p1->x - p2->x;
	}
	else
	{
		X = p2->x - p1->x;
	}
	
	if(p1->y > p2->y)
	{
		Y = p1->y - p2->y;
	}
	else
	{
		Y = p2->y - p1->y;
	}

	d_ret = sqrt(X * X + Y * Y);
	d_ret += 0.51;

	if(d_ret > 0)
	{
		ret = d_ret; //double -> uint (d_ret > 0)
	}
	else
	{
		return 0;  //d_ret < -0.49
	}
	return ret;
}
void square(void)
{
	double d_ret;
	unsigned int ret;
	d_ret = sqrt(field.width * field.height * 2);
	d_ret /= 2;
	d_ret += 0.51;

	if(d_ret < 0)
	{
		field.hDiagonal = 0;
		return;
	}
	field.hDiagonal = d_ret;
	return;
}
double calcMultip(void)
{
	double ret = 0;
	ret = effect.maxMultip - effect.minMultip;
	if(field.hDiagonal != 0)
	{
		ret /= (double)field.hDiagonal;
	}
	return ret;
}
unsigned int calcEffect(unsigned int Length,double multip)
{
	unsigned int ret = 0;
	if(field.hDiagonal < Length)
	{
		ret = effect.base * effect.minMultip;
	}
	else
	{
		ret = effect.base * (effect.minMultip + multip *(field.hDiagonal - Length));
	}
	return ret;

}

void main(int argc,char argv[])
{
	//touch point
	S_point player;
	S_point computer;
	unsigned int cpx, cpy, atk;
	cpx = 0; cpy = 0; atk = 100;
	computer.x = cpx;
	computer.y = cpy;

	//Field
	field.width = 150;
	field.height = 150;

	//Effect
	effect.base = atk;
	effect.minMultip = 0.85;
	effect.maxMultip = 1.15;

	//validate
	unsigned int L;
	double sMultipler;
	unsigned int Z;
	unsigned int xp,yp,a;

	printf("input xp:");
	scanf("%d",&xp);
	printf("input yp:");
	scanf("%d",&yp);
	player.x = xp;
	player.y = yp;
	printf("input a:");
	scanf("%d",&a);
	effect.base = a;
	printf("\r\n");

	//calculate Length;
	L = calcLen(&player,&computer);
	square();
	sMultipler = calcMultip();
	Z = calcEffect(L,sMultipler);

	printf("LAST RETURN:%d\r\n",Z);
}

