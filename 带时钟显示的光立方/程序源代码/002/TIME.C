#include<stc12c5a60s2.h>//添加头文件
#include<intrins.h>
#include "IR.h"
#include "time.h"
#include "KEY.h"
#include "delay.h"
#include "ds1302.h"



						  
uchar code time_set_chinese[72]={0x04,0x44,0x54,0x7F,0x54,0xDC,0x24,0x04,//时间设置  年
								0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
								0x00,0x00,0x7F,0x55,0x54,0x7E,0x01,0x00,//月
								0x00,0x00,0x7F,0x49,0x49,0x7F,0x00,0x00,	//日
								0x20,0x7E,0x22,0x28,0x00,0x3E,0x2A,0x3E,//时
								0x10,0x20,0xDF,0x11,0x10,0x9C,0x52,0x21,//分
								0x30,0x04,0xFA,0x31,0x15,0x98,0x7F,0x54, //秒
								0x00, 0x3E, 0x04, 0x08, 0x10, 0x3E, 0x00, 0x00, 
								0x00, 0x20, 0x10, 0x0E, 0x10, 0x20, 0x00, 0x00,

								};//秒
	
uchar code shi1[80]={   0x00,0xE0,0xA0,0xA0,0xA0,0xE0,0x00,0x00,
				 		0x00,0x40,0x40,0x40,0x40,0x40,0x00,0x00, 
						0x00,0xE0,0x80,0xE0,0x20,0xE0,0x00,0x00,
						0x00, 0xE0, 0x20, 0xE0, 0x20, 0xE0, 0x00, 0x00, 
						0x00, 0x20, 0x20, 0xE0, 0xA0, 0xA0, 0x00, 0x00, 
						0x00, 0xE0, 0x20, 0xE0, 0x80, 0xE0, 0x00, 0x00, 
						0x00, 0xE0, 0xA0, 0xE0, 0x80, 0xE0, 0x00, 0x00, 
						0x00, 0x20, 0x20, 0x20, 0x20, 0xE0, 0x00, 0x00, 
						0x00, 0xE0, 0xA0, 0xE0, 0xA0, 0xE0, 0x00, 0x00, 
						0x00, 0xE0, 0x20, 0xE0, 0xA0, 0xE0, 0x00, 0x00,
					};


uchar code shi2[80]={	0x00, 0x0E, 0x0A, 0x0A, 0x0A, 0x0E, 0x00, 0x00, 
						0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, 
						0x00, 0x0E, 0x08, 0x0E, 0x02, 0x0E, 0x00, 0x00, 
						0x00, 0x0E, 0x02, 0x0E, 0x02, 0x0E, 0x00, 0x00, 
						0x00, 0x02, 0x02, 0x0E, 0x0A, 0x0A, 0x00, 0x00, 
						0x00, 0x0E, 0x02, 0x0E, 0x08, 0x0E, 0x00, 0x00, 
						0x00, 0x0E, 0x0A, 0x0E, 0x08, 0x0E, 0x00, 0x00, 
						0x00, 0x02, 0x02, 0x02, 0x02, 0x0E, 0x00, 0x00, 
						0x00, 0x0E, 0x0A, 0x0E, 0x0A, 0x0E, 0x00, 0x00, 
						0x00, 0x0E, 0x02, 0x0E, 0x0A, 0x0E, 0x00, 0x00, 
						};	
						
uchar code miao1[48]={	0x00, 0xE0, 0xA0, 0xA0, 0xA0, 0xE0, 0x00, 0x00, 
						0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00, 
						0x00, 0xE0, 0x20, 0xE0, 0x80, 0xE0, 0x00, 0x00, 
						0x00, 0xE0, 0x20, 0xE0, 0x20, 0xE0, 0x00, 0x00, 
						0x00, 0xA0, 0xA0, 0xE0, 0x20, 0x20, 0x00, 0x00, 
						0x00, 0xE0, 0x80, 0xE0, 0x20, 0xE0, 0x00, 0x00,  
						};												 
uchar code miao2[80]={						
						0x00, 0x0E, 0x0A, 0x0A, 0x0A, 0x0E, 0x00, 0x00, 
						0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, 
						0x00, 0x0E, 0x02, 0x0E, 0x08, 0x0E, 0x00, 0x00, 
						0x00, 0x0E, 0x02, 0x0E, 0x02, 0x0E, 0x00, 0x00, 
						0x00, 0x0A, 0x0A, 0x0E, 0x02, 0x02, 0x00, 0x00, 
						0x00, 0x0E, 0x08, 0x0E, 0x02, 0x0E, 0x00, 0x00, 
						0x00, 0x0E, 0x08, 0x0E, 0x0A, 0x0E, 0x00, 0x00, 
						0x00, 0x0E, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00,
						0x00, 0x0E, 0x0A, 0x0E, 0x0A, 0x0E, 0x00, 0x00, 
						0x00, 0x0E, 0x0A, 0x0E, 0x02, 0x0E, 0x00, 0x00, 
						}; 

uchar code fen1[48]={	0x00, 0x70, 0x50, 0x50, 0x50, 0x70, 0x00, 0x00, 
						0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 
						0x00, 0x70, 0x40, 0x70, 0x10, 0x70, 0x00, 0x00, 
						0x00, 0x70, 0x10, 0x70, 0x10, 0x70, 0x00, 0x00, 
						0x00, 0x10, 0x10, 0x70, 0x50, 0x50, 0x00, 0x00, 
						0x00, 0x70, 0x10, 0x70, 0x40, 0x70, 0x00, 0x00,   
						};												 
uchar code fen2[80]={						
						0x00, 0x07, 0x05, 0x05, 0x05, 0x07, 0x00, 0x00, 
						0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 
						0x00, 0x07, 0x04, 0x07, 0x01, 0x07, 0x00, 0x00, 
						0x00, 0x07, 0x01, 0x07, 0x01, 0x07, 0x00, 0x00, 
						0x00, 0x01, 0x01, 0x07, 0x05, 0x05, 0x00, 0x00, 
						0x00, 0x07, 0x01, 0x07, 0x04, 0x07, 0x00, 0x00, 
						0x00, 0x07, 0x05, 0x07, 0x04, 0x07, 0x00, 0x00, 
						0x00, 0x01, 0x01, 0x01, 0x01, 0x07, 0x00, 0x00, 
						0x00, 0x07, 0x05, 0x07, 0x05, 0x07, 0x00, 0x00,
						0x00, 0x07, 0x01, 0x07, 0x05, 0x07, 0x00, 0x00, 
						}; 




uchar code uln1[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};

void display_time();
void time();
void display_set(uchar t);
uchar irnum(uchar k,uchar j,uchar l);
void settime();




void time()
{
	read_rtc();
	display_time();
}



void settime()
{
	uchar i,j,k,t=0;
	k2=0;
	ircode[2]=0;
	read_rtc();
	for(i=0;i<7;i++)
	{
		time_set[i]=now[i];	
	}
	while(1)
	{
		
		if(t==0)		//年
		{
			j=time_set[0]%16;
			k=time_set[0]/16;
			num=k*10+j;
			key_num();
			ir();
			if(ircode[2]==0x07)num--;
			if(ircode[2]==0x15)num++;
			ircode[2]=0x00;
			if(num==255)num=99;
			if(num==100)num=0;
			j=num%10;
			k=num/10;
			time_set[0]=k*16+j;	
			display_set(0);
			ir();
			key_2();
			if(ircode[2]==0x45)t--;
			if(ircode[2]==0x47)t++;
			if(k2==1)t++;
			k2=0;
			if(t==7)t=0;
			if(t==255)t=6; 
		} 
		if(t==1)t++; //周
		if(t==2)		 //月
		{
			j=time_set[2]%16;
			k=time_set[2]/16;
			num=k*10+j;
			key_num();
			ir();
			if(ircode[2]==0x07)num--;
			if(ircode[2]==0x15)num++;
			ircode[2]=0x00;
			if(num==0)num=12;
			if(num==13)num=1;
			j=num%10;
			k=num/10;
			time_set[2]=k*16+j;	
			display_set(2);
			ir();
			key_2();
			if(ircode[2]==0x45)t--;
			if(ircode[2]==0x47)t++;
			if(k2==1)t++;
			k2=0;
			if(t==7)t=0;
			if(t==255)t=6; 
		} 
		if(t==3)		 //日
		{
			j=time_set[3]%16;
			k=time_set[3]/16;
			num=k*10+j;
			key_num();
			ir();
			if(ircode[2]==0x07)num--;
			if(ircode[2]==0x15)num++;
			ircode[2]=0x00;
			if(num==0)num=31;
			if(num==32)num=1;
			j=num%10;
			k=num/10;
			time_set[3]=k*16+j;	
			display_set(3);
			ir();
			key_2();
			if(ircode[2]==0x45)t--;
			if(ircode[2]==0x47)t++;
			if(k2==1)t++;
			k2=0;
			if(t==7)t=0;
			if(t==255)t=6; 
		} 
		if(t==4)				 //时
		{
			j=time_set[4]%16;
			k=time_set[4]/16;
			num=k*10+j;
			key_num();
			ir();
			if(ircode[2]==0x07)num--;
			if(ircode[2]==0x15)num++;
			ircode[2]=0x00;
			if(num==255)num=23;
			if(num==24)num=0;
			j=num%10;
			k=num/10;
			time_set[4]=k*16+j;	
			display_set(4);
			ir();
			key_2();
			if(ircode[2]==0x45)t--;
			if(ircode[2]==0x47)t++;
			if(k2==1)t++;
			k2=0;
			if(t==7)t=0;
			if(t==255)t=6; 
		} 
		if(t==5)				 //分
		{
			j=time_set[5]%16;
			k=time_set[5]/16;
			num=k*10+j;
			key_num();
			ir();
			if(ircode[2]==0x07)num--;
			if(ircode[2]==0x15)num++;
			ircode[2]=0x00;
			if(num==255)num=59;
			if(num==60)num=0;
			j=num%10;
			k=num/10;
			time_set[5]=k*16+j;	
			display_set(5);
			ir();
			key_2();
			if(ircode[2]==0x45)t--;
			if(ircode[2]==0x47)t++;
			if(k2==1)t++;
			k2=0;
			if(t==7)t=0;
			if(t==255)t=6; 
		} 
		if(t==6)			//	 秒
		{
			j=time_set[6]%16;
			k=time_set[6]/16;
			num=k*10+j;
			key_num();
			ir();
			if(ircode[2]==0x07)num--;
			if(ircode[2]==0x15)num++;
			ircode[2]=0x00;
			if(num==255)num=59;
			if(num==60)num=0;
			j=num%10;
			k=num/10;
			time_set[6]=k*16+j;	
			display_set(6);
			ir();
			key_2();
			if(ircode[2]==0x45)t--;
			if(ircode[2]==0x47)t++;
			if(k2==1)
			{
				k2=0;
				num=7;
				for(;num<10;)
				{
					t=8*num;
					for(i=0;i<8;i++)
					{
					P1=0x80;
					P2=uln1[i];
					P0=time_set_chinese[t];
					t++;
					}
					delay50us(30);
					P2=0xff;
					P0=0x00;
					P1=0x00;
					key_num();
					if(num==9)num=7;
					key_2();
					if(k2==1)
					{
					if(num==8)set_rtc();
					num=11;
					}
					
				}
				break;
				

			}
			if(t==7)t=0;
			if(t==255)t=6; 
		} 
		key_2();
		if(k2==1)break;
		ir();
		if(ircode[2]==0x0d)
		{
		set_rtc();
		break;
		}
		if(ircode[2]==0x46)
		{
		ircode[2]=0x00;
		break;
		}
	}
}




	






void display_set(uchar t)
{
			uchar i,js,ks,k;
		
			js=time_set[t]%16;
			ks=time_set[t]/16;
		
			js=js*8;
			ks=ks*8;
			k=t*8;
			for(i=0;i<7;i++)
				{
					P2=0xff;
					P0=0x00;
					_nop_();	_nop_();	_nop_();	_nop_();
					P1=uln1[i];
					P2=shi1[ks]|shi2[js];
					P0=0x01; _nop_();	_nop_();	_nop_();	_nop_();
					ks++;
					js++;
					P2=0x00;
					delay50us(30);
					P2=0xff;
					P0=0x00;
					P2=0x00;	_nop_();	_nop_();
				}
			for(i=0;i<8;i++)
				{
				P1=0x80;
				P2=uln1[i];
				P0=time_set_chinese[k];
				k++;
				}
				delay50us(30);
				P2=0xff;
				P0=0x00;
				P1=0x00;	
}

void display_time()
{
	uchar i,j,js,ks,jf,kf,jm,km;
	
	for(j=0;j<8;j++)
	{
		key_mod();
		ir();
		if(ircode[2]==0x43)
		{
		ircode[2]=0x00;
		P4=0x00;
		ET1=0;
		delayms(100);
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
		if(ircode[2]==0x09)
		{
		ircode[2]=0x00;
		mod++;
		}
		if(mod==2)mod=0;
		if(mod==0)
		{
			js=now[4]%16;
			ks=now[4]/16;
			jf=now[5]%16;
			kf=now[5]/16;
			jm=now[6]%16;
			km=now[6]/16;
			js=js*8;
			ks=ks*8;
			jf=jf*8;
			kf=kf*8;
			jm=jm*8;
			km=km*8;
			for(i=0;i<7;i++)
				{
					P2=0xff;
					P0=0x00;
					P2=0x00;_nop_();	_nop_();	_nop_();	_nop_();
					P1=uln1[i];
					P2=fen1[kf]|fen2[jf];
					P0=0x01;_nop_();	_nop_();	_nop_();	_nop_();
					_nop_();	_nop_();	_nop_();	_nop_();
					kf++;
					jf++;
					P2=0x80; _nop_();	_nop_();	_nop_();	_nop_();
					P0=shi1[ks]|shi2[js];
					ks++;
					js++;
					P2=0x00;
					delay50us(30);
					P2=0xff;
					P0=0x00;
					P2=0x00;	_nop_();	_nop_();
				}
			for(i=0;i<8;i++)
				{
				P1=0x80;
				P2=uln1[i];
				P0=miao1[km]|miao2[jm];
				jm++;
				km++;  
				}
				delay50us(30);
				P1=0x00;
		}
		if(mod==1)
		{
			js=now[2]%16;
			ks=now[2]/16;
			jf=now[3]%16;
			kf=now[3]/16;
			jm=now[0]%16;
			km=now[0]/16;
			js=js*8;
			ks=ks*8;
			jf=jf*8;
			kf=kf*8;
			jm=jm*8;
			km=km*8;
			for(i=0;i<7;i++)
				{
					P2=0xff;
					P0=0x00;
					P2=0x00;_nop_();	_nop_();	_nop_();	_nop_();
					P1=uln1[i];
					P2=fen1[kf]|fen2[jf];
					P0=0x01;_nop_();	_nop_();	_nop_();	_nop_();
					_nop_();	_nop_();	_nop_();	_nop_();
					kf++;
					jf++;
					P2=0x80; _nop_();	_nop_();	_nop_();	_nop_();
					P0=shi1[ks]|shi2[js];
					ks++;
					js++;
					P2=0x00;
					delay50us(30);
					P2=0xff;
					P0=0x00;
					P2=0x00;	_nop_();	_nop_();
				}
			for(i=0;i<8;i++)
				{
				P1=0x80;
				P2=uln1[i];
				P0=miao1[km]|miao2[jm];
				jm++;
				km++;  
				}
				delay50us(30);
				P1=0x00;
		}
	}
}