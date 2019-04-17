#include<intrins.h>
#include "delay.h"

uchar i,j,k;
void delayms(uchar k)		//@22.1184MHz
{

	i = 22;
	j = 128;
	for(;k>0;k--)
	{
		do
		{
			while (--j);
		} while (--i);
	}
}

void delay50us(uchar i)		//@22.1184MHz
{

	j = 30;
	do
	{
		while (--j);
	} while (--i);
}
