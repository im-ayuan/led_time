/*****************************************

  ��������ѿ�Դ��Ŀ�������໥ѧϰ

  QQ��754432568

  ���䣺wojiushihuxq@126.com	    
																	  
  ������  �����������հ������������Ĵ���							  
  Ŀǰ�����˭�����ߡ����˶��������д��붼�Ǳ����ִ�					  
																	  
  ���кܶ���Ż��Ĳ��֣�������޸ĺ�Ҳ�ܷ�һ�ݸ��ң�
  �����ҵ�����
														


********************************************/



#include<stc12c5a60s2.h>//���ͷ�ļ�
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
	Timer1Init();			//��ʼ����ʱ��
	Int0Init();
	DS1302_Initial();
	ET0=0;
	TR0=0;
}



