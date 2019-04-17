	 /*	  
--------------------------------------------------------
2014年7月1日19:29:37
		程序功能：
				光立方读取ds1302时间程序

说明：本程序参考了天狼星51教程，ds1302部分，经过小部分修改

--------------------------------------------------------
*/
#include<stc12c5a60s2.h>//添加头文件
#include<intrins.h>
#include "ds1302.h"


				  //年周月日 时分秒
uchar time_set[7]={14,4,7,10,12,0,0};//设置初始时间

uchar now[7];

uchar code write_add[7]={0x8c,0x8a,0x88,0x86,0x84,0x82,0x80};
uchar code read_add[7]={0x8d,0x8b,0x89,0x87,0x85,0x83,0x81};

void write_ds1302_byte(uchar dat);
void write_ds1302(uchar add,uchar dat);
uchar read_ds1302(uchar add);
void set_rtc(void);
void read_rtc(void);



void delay1s(void);

void DS1302_Initial();


void delay10us(void);   //误差 -0.008318865741us
void delay6us(void);	 //10nop	
void delay4us(void);		 //5nop




void write_ds1302_byte(uchar dat)
{
	uchar i;
	for(i=0;i<8;i++)
	{
	 
  		delay4us();
		io=dat&0x01;
		dat=dat>>1;
		sck=1;
		delay4us();
		sck=0;
		delay4us();	
	}
}


void write_ds1302(uchar add,uchar dat)
{
	rst=0;
	delay6us();	
	sck=0;
	delay6us();
	rst=1;
	delay6us();
	write_ds1302_byte(add);
	write_ds1302_byte(dat);
	rst=0;
	delay6us();
	io=1;
	sck=1;
}



uchar read_ds1302(uchar add)
{
	uchar i,value=0x00;
	rst=0;
	delay6us();	
	sck=0;
	delay6us();
	rst=1;
	io=1;
	delay6us();
	write_ds1302_byte(add);
	for(i=0;i<8;i++)
	{
		value=value>>1;
		sck=0;
		
		if(io==1)value=value|0x80;
			else _nop_();
		sck=1;
		delay4us();
	}
	rst=0;
	delay6us();
	sck=0;
	delay6us();
	sck=1;
	io=1;
	return value;
}
   

void set_rtc()
{
	uchar i;
	write_ds1302(0x8e,0x00);//去除写保护
	for(i=0;i<7;i++)
	{
		write_ds1302(write_add[i],time_set[i]);	
	}

	write_ds1302(0x8e,0x80);

}		 

void read_rtc()
{
	uchar i;
	for(i=0;i<7;i++)
	{
	now[i]=read_ds1302(read_add[i]);	
	}

}

/**********************************************************************
延时函数


*********************************************************************/



void delay6us(void)   //误差 -0.032118055556us
{
   _nop_();
   _nop_();
   _nop_();
   _nop_();
   _nop_();
   _nop_();
   _nop_();
   _nop_();
}


void delay4us(void)   //误差 -0.021412037037us
{
   _nop_();
   _nop_();
   _nop_();
   _nop_();
   _nop_();
}


 /*

void delay1s(void)   //误差 -0.000000000125us
{
    unsigned char a,b,c,n;
    for(c=169;c>0;c--)
        for(b=228;b>0;b--)
            for(a=142;a>0;a--);
    for(n=5;n>0;n--);
    _nop_();  //if Keil,require use intrins.h
}
		 

void delay10us(void)   //误差 -0.008318865741us
{
    unsigned char a;
    for(a=52;a>0;a--);
    _nop_();  //if Keil,require use intrins.h
}		  */

/**********************************************************************
延时函数


*********************************************************************/

void DS1302_Initial()	 
{
    rst = 0;
    sck = 0;
	io=1;
 	delay6us();
}
	 