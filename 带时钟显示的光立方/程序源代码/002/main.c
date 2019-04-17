/*****************************************

  本程序免费开源，目的在于相互学习

  QQ：754432568

  邮箱：wojiushihuxq@126.com	    
																	  
  本程序  动画部分是照搬了网上流传的代码							  
  目前不清楚谁是作者。除了动画外所有代码都是本人手打					  
																	  
  还有很多待优化的部分，望大家修改后，也能发一份给我，
  发到我的邮箱
														


********************************************/



#include<stc12c5a60s2.h>//添加头文件
#include<intrins.h>
#include "ds1302.h"
#include "IR.h"
#include "MAIN.h"
#include "MEUN.h"
#include "KEY.h"
#include "delay.h"
#include "time.h"
#include "video.h"


void init(void);


void main()
{
	init();
	mod=0x00;
	P4=0xff;
	while(1)
	{
		k2=0;
		meun();
		k2=0;
		if(flag==0)
		{
			while(1)
			{	
				time();
				key_2();
				ir();
				if(ircode[2]==0x46)k2=1;
				ircode[2]=0;
				if(k2==1)break;	
			}
		}
		if(flag==1)settime();	


		if(flag==2)
		{
			while(1)
			{	
				video();
				ET0=0;
				TR0=0;
				key_2();
				ir();
				if(ircode[2]==0x46)k2=1;
				ircode[2]=0; 
				if(k2==1)break;			   		
			}
		}
		if(flag==3)
		{
		delayms(100);
		P4=0x00;
		ET1=0;
		PCON=0X02;
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();_nop_();_nop_();_nop_();
		delayms(100);
		P4=0xff;
		ET1=1;	
		}
		   
	}	   
}


void init()
{
	P0M0=0XFF;
	P1M0=0XFF;
	P2M0=0XFF;
//	P3M0=0XFF;
	P4M0=0XFF;
	Timer1Init();			//初始化定时器
	Int0Init();
	DS1302_Initial();
	ET0=0;
	TR0=0;
}



