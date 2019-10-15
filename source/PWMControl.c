/**
 * @file    PWMControl.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "clock_config.h"
#include "pin_mux.h"
#include "ESC.h"

volatile int timeOver = 1000;

int main(void) {
	//--------------Default Configuration ----------------------//
  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();

    //Programmer configuration
    InitDriver(800, 6, 600, 1120, 1600, 1160);

    PRINTF("PWM Control\n");
    /* Force the counter to be placed into memory. */
    volatile static int i = 0 ;
    /* Enter an infinite loop, just incrementing a counter. */

	//TPM1->CONTROLS[0].CnV = 1100;
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
    Stop();
    while(1) {
        i++;
    }
    return 0;
}
