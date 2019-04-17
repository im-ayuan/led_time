#include <stc12c5a60s2.h>//添加头文件
#include "ir.h"
#include "key.h"
#define uchar unsigned char
#define uint unsigned int


uchar irtime;	  //定时器中断次数   
uchar start;	  //红外接收开始标志位
uchar xdata irdata[33];	  //存储  红外中断时间
uchar ircode[4]={0x11,0x11,0x11,0x11};	  //存储按键码
uchar bitnum;							  //用于标记 irdata的第i个 元素
uchar irok;								  //红外接收完成标志
uchar irprosok;							  //红外转化完成标志

	 
void Timer1Init(void);			//初始化定时器
void Int0Init(void);			//初始化外部中断
void irpros(void);				//转化函数
void ir(void);


	

void Timer1Init(void)		//100微秒@22.1184MHz
{
	AUXR &= 0xBF;		//定时器时钟12T模式
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0x48;		//设置定时初值
	TH1 = 0x48;		//设置定时重载值
	TF1 = 0;		//清除TF1标志
	TR1 = 1;		//定时器1开始计时
	ET1=1;			 //启动定时器1中断
	EA=1;			 //打开总中断开关

}

void int0init(void)			//外部中断 初始化
{
	IT0=1;				 //下降沿触发
	EX0=1;				 //打开外部中断0
	EA=1;	
}



void ir(void)		   
{		
		EX0=1;		//打开外部中断
		if(irok==1)		   //判断是否接受完成
		{
			irpros();	   //若接收完成，执行转化函数
			irok=0;
		}
		if(irprosok==1)			  //判断转化是否完成
		{	
			irprosok=0;			//使用完按键码之后将转化完成标记清空，方便下次使用								//若不清空，后面的按键码都会被舍弃  因为不会执行转化函数
		}
}




void timer1 () interrupt 3
{
	irtime++;		 //定时器中断，中断一次就是100us
}




void irpros(void)
{
	uchar i,j,k,value;
	k=1;
	for(j=0;j<4;j++)		//循环4次，每次一个码
	{
		for(i=0;i<8;i++)
		{
			value=value>>1;
			if(irdata[k]>15)   //时间大于1500us  就是数据1，小于就是0  （0是1125us，1是2250us）
			{
				value=value | 0x80;	
			}
		
			k++;
		}
		ircode[j]=value;   //将按键码存入数组
	}
	irprosok=1;	//转化完成
	EX0=1;		//打开外部中断
}


void int0 () interrupt 0	 
{

		if(start==1)
		{
			if(irtime>80)	  //判断是否是	9MS的引导码 
	
			{
				bitnum=0;
			}
			irdata[bitnum]=irtime;	//将两次中断之间的时间间隔存入数组  
			irtime=0;		 //清零定时器中断次数
			bitnum++;
			if(bitnum==33)
			{
				bitnum=0;
				start=0;   //清除接收开始标志
				irok=1;	   //标记 接受完成
				EX0=0;	//关闭外部中断0  因为遥控器按下时是连续发送的，
						//这时已经接受完成。所以要关闭外部中断  防止在执行转化时受到干扰
			}
			
		}
		else
		{
			start=1;	//第一次进入中断 ，打开接收标记 并将定 时器中断次数 清零，
					   //下一次进入时  就执行上面个IF的函数
			irtime=0;
		}		
}



