#include<stc12c5a60s2.h>//添加头文件
#include<intrins.h>
#include "IR.h"
#include "MEUN.h"
#include "KEY.h"
#include "delay.h"




uchar code meuna[32]={
					0x3C, 0x42, 0x81, 0x9D, 0x91, 0x91, 0x42, 0x3C, //时钟
					0x70, 0x8A, 0xBA, 0xAA, 0x72, 0x07, 0x05, 0x00,//shi时间设置
		
					0x3c,0x18,0x7e,0x81,0x95,0xa9,0x81,0x7e, 			//动画
					0x3C,0x42,0x02,0x3C,0x40,0x42,0x3C,0x00,//S
					};		


uchar code uln[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};


void meun(void);
void display_meun(uchar flag);
		 				  
void meun(void)
{	
	while(1)
	{
		display_meun(flag);
		key_meun();
		key_2();
		ir();
		if(ircode[2]==0x47)flag++;
		if(ircode[2]==0x45)
		{
			if(flag==0)flag=3;
			else flag--;
		}
		flag=flag%4;
		if(ircode[2]==0x0c)flag=0;
		if(ircode[2]==0x18)flag=1;
		if(ircode[2]==0x5e)flag=2;
		if(ircode[2]==0x08)flag=3;
		if(ircode[2]==0x46)k2=1;
		ircode[2]=0x00;
		if(k2==1)break;
	}
}

void display_meun(uchar flag)
{
	uchar i,j;
	j=flag*8;
	for(i=0;i<8;i++)
	{
		P0=0x00;
		P1=uln[i];
		P2=meuna[j];
		P0=0x01;
		j++;
		delay50us(30);
		P0=0x00;
	}
		




}













