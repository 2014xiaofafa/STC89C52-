#ifndef  MOVE_H
#define  MOVE_H

#include <reg52.h>

#define uchar unsigned char
#define uint unsigned int
	
/*********************/
/*定义小车的引脚*/
/*********************/
 sbit LENA = P1^0;
 sbit LIN1 = P1^1;
 sbit LIN2 = P1^2;
 sbit LIN3 = P1^3;
 sbit LIN4  = P1^4;
 sbit LENB  = P1^5;
 
 sbit RENB = P0^0;
 sbit RIN3 = P0^1;
 sbit RIN4 = P0^2;
 sbit RIN1 = P0^3;
 sbit RIN2  = P0^4;
 sbit RENA  = P0^5;

void CarInit();
void LeftFrontMotor(uchar a);
void LeftBackMotor(uchar a);
void RightFrontMotor(uchar a);
void RightBackMotor(uchar a);
void Forward();
void Back();
void TurnLeft();
void TurnRight();
void Stop();

#endif