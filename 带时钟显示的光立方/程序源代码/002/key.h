#ifndef __KEY_H__
#define __KEY_H__

#define uchar unsigned char
#define uint unsigned int

sbit key1=P3^3;
sbit key2=P3^4;


void key_meun(void);
void key_2(void);
void key_mod(void);
void key_num(void);




extern uchar k2;
extern uchar flag;
extern uchar mod;
extern uchar num;




#endif