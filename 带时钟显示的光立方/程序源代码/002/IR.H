#ifndef __TR_H__
#define __IR_H__


#define uchar unsigned char
#define uint unsigned int

void Timer1Init(void);			//初始化定时器
void Int0Init(void);			//初始化外部中断
void ir(void);

extern uchar ircode[4];


#endif