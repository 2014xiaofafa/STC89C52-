#include "reg52.h"
#include "move.h"

void CarInit()
{
	LENA = 0;
	LENB = 0;
	RENA = 0;
	RENB = 0;	
}

void LeftFrontMotor(uchar a)
{
	if(a == 1)		//keep forward
	{
		LENA = 1;
		LIN1 = 0;
		LIN2 = 1;
	}
	else					//back
	{
		LENA = 1;
		LIN1 = 1;
		LIN2 = 0;		
	}
}

void LeftBackMotor(uchar a)
{
	if(a == 1)		//keep forward
	{
		LENB = 1;
		LIN3 = 1;
		LIN4 = 0;
	}
	else					//back
	{
		LENB = 1;
		LIN3 = 0;
		LIN4 = 1;		
	}
}	

void RightFrontMotor(uchar a)
{
	if(a == 1)		//keep forward
	{
		RENA = 1;
		RIN1 = 0;
		RIN2 = 1;
	}
	else					//back
	{
		RENA = 1;
		RIN1 = 1;
		RIN2 = 0;		
	}
}	

void RightBackMotor(uchar a)
{
	if(a == 1)		//keep forward
	{
		RENB = 1;
		RIN3 = 0;
		RIN4 = 1;
	}
	else					//back
	{
		RENB = 1;
		RIN3 = 1;
		RIN4 = 0;		
	}
}	

void Forward()			//CAR KEEP FORWARD
{
	LeftFrontMotor(1);
	LeftBackMotor(1);
	RightFrontMotor(1);
	RightBackMotor(1);	
}	

void Back()
{
	LeftFrontMotor(0);
	LeftBackMotor(0);
	RightFrontMotor(0);
	RightBackMotor(0);
}	

void TurnLeft()
{
	LeftFrontMotor(0);
	LeftBackMotor(0);
	RightFrontMotor(1);
	RightBackMotor(1);	
}

void TurnRight()
{
	LeftFrontMotor(1);
	LeftBackMotor(1);
	RightFrontMotor(0);
	RightBackMotor(0);	
}

void Stop()
{
	CarInit();
}
