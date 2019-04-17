#include<stc12c5a60s2.h>//添加头文件
#include<intrins.h>
#include "MEUN.h"
#include "KEY.h"
#include "delay.h"


uchar flag;
uchar mod;
uchar num;
uchar k2;


void key_meun(void);
void key_2(void);
void key_mod(void);
void key_num(void);

void key_meun(void)
{
	key1=1;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	if(key1==0)
    {
		display_meun(flag);
		if(key1==0)
		{ 
			while(!key1)
			{
				display_meun(flag);
			}
			flag++;
			flag=flag%4;
		}
	}
}

void key_2(void)
{

	key2=1;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	if(key2==0)
    {
		delayms(10);
		if(key2==0)
		{ 
			while(!key2);
			delayms(10);
			while(!key2);
			k2=1;
		}
	}	
}
void key_mod(void)
{
	key1=1;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	if(key1==0)
    {
		delayms(10);
		if(key1==0)
		{ 
			while(!key1);
			delayms(10);
			while(!key1);
			mod++;
			if(mod==2)mod=0;
		}
	}
}

void key_num(void)
{
	key1=1;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	if(key1==0)
    {
		delayms(10);
		if(key1==0)
		{ 
			while(!key1);
			delayms(5);
			while(!key1);
			num++;	
		}
	}
}