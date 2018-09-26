#include <reg52.h> 
#include "move.h"

#define uchar unsigned char
#define uint unsigned int

unsigned char rece;
bit UartBusy;
bit flag;

/************************/
/*********UARTINIT**********/
void UartInit()
{
	TMOD = 0x20;
	TH1 = 0XFD;
	TL1 = 0XFD;
	TR1 = 1;
	REN = 1;
	SM0 = 0;
	SM1 = 1;
	EA = 1;
	ES = 1;	
}

 void main()
 {
	 UartInit();
	 CarInit();
 
	 while(1)
	 {
		 switch(rece)
		 {
			 case '0': 
					Stop();
					break;			 
			 case '1':
					Forward();
					break;
			  case '2': 
					TurnRight();
					break;				 
				case '3': 
					Back();     break;
				case '4': 
					TurnLeft();     break;
				default: break;				
		 }			 
	 }
 }
 

/*----------------------------
UART interrupt service routine
----------------------------*/
void Uart() interrupt 4
{
	if(RI)
	{
		RI = 0;				//Clear receive interrupt flag
		rece = SBUF;
		flag = 1;		
	}
	if(TI)
	{
		TI = 0; 	 //Clear transmit interrupt flag
		UartBusy = 0;		//Clear transmit busy flag
	}
}
