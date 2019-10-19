 /**
 * @file    CarControl.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "clock_config.h"
#include "pin_mux.h"
#include "ESC.h"

volatile int flagPit0 = 0, flagPit1=0;

void PIT_IRQHandler(void){
	if(PIT->CHANNEL[0].TFLG){
		PIT->CHANNEL[0].TFLG=PIT_TFLG_TIF_MASK;
		flagPit0=1;
	}
	if(PIT->CHANNEL[1].TFLG){
		PIT->CHANNEL[1].TFLG=PIT_TFLG_TIF_MASK;
		flagPit1++;
		printf("ch1");
	}
}

void Prueba1(void){
	InitPit();
	SetFordwardSpeed(20);
	while(flagPit1==0){
		if(flagPit0==1){
			flagPit0=0;
			printf("p1\n");
		}
	}
	ConfigTimePit(2);
	SetFordwardSpeed(100);
	while(flagPit1==1){
		if(flagPit0==1){
			flagPit0=0;
			printf("p2\n");
		}
	}
	ConfigTimePit(8);
	while(flagPit1==2){
		if(flagPit0==1){
			flagPit0=0;
			printf("p3\n");
		}
	}
	Stop();
	//SetFordwardSpeed(20);
}

void Prueba2(void){

}

void Prueba3(void){

}

int main(void) {
	//--------------Default Configuration ----------------------//
  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();
    PRINTF("Car control\n");
    //Programmer configuration
    float ratio= 3;
    int maxFw = GetForwardSpeed(ratio, 600); //562
	int minFw = GetForwardSpeed(ratio, 1120); //5
	int maxBw = GetBackwardSpeed(ratio, 1600);
	int minBw = GetBackwardSpeed(ratio, 1160);
    InitDriver(800, ratio, maxFw, minFw, maxBw, minBw);
    /* Enter an infinite loop, just incrementing a counter. */
    //while(1) {
    	Prueba1();
    //}
    return 0;
}
/*//TPM1->CONTROLS[0].CnV = 1100;
 * volatile int timeOver = 1000;
float sp=1100;
SetFordwardSpeed(sp);
int timeOver2 = timeOver*2000;
while(timeOver2){
	timeOver2--;
}
sp=1300;

SetBackwardSpeed(sp);

timeOver2 = timeOver*20000;
while(timeOver2){
  timeOver2--;
}
Stop();*/
