#ifndef __DS1302_H__
#define __DS1302_H__

sbit sck=P3^7;	 //λ����
sbit io=P3^6;
sbit rst=P3^5;

#define uchar unsigned char
#define uint unsigned int

//void write_ds1302_byte(uchar dat);		  //��������
//void write_ds1302(uchar add,uchar dat);
//uchar read_ds1302(uchar add);
void set_rtc(void);
void read_rtc(void);
void DS1302_Initial();

extern uchar time_set[7];
extern uchar now[7];



#endif