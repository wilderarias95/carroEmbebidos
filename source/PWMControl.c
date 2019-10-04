/**
 * @file    PWMControl.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL27Z644.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 Backward [1160, 1600]
 Forward  [1120,600]
 stop 1125
 */
#define SetDutyTPM1CH0(x) TPM1->CONTROLS[0].CnV=(uint32_t)(x)
volatile int timeOver = 1000;
volatile int delayValue = 250000;
volatile static int STOP_ENGINE = 1125;

void PWMInit(void){
	SIM->SCGC6 |= SIM_SCGC6_TPM1_MASK; //TPM1 clock gate control enable
	SIM->SOPT2 |= SIM_SOPT2_TPMSRC(1); //tpm clock source 0b01 IRC48M clock

	//select PWM out
	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;   //PORTA Clock gate control enable
	PORTA->PCR[12] |= PORT_PCR_MUX(3);//PIN 28 PTA12 ALT3(TPM1_CH0)

	TPM1->SC |= TPM_SC_PS(6); // Prescale factor selection 0b110 Divide by 64
	//TPM1->SC |= TMP1_SC_TOIE_MASK; //TIMER OVERFLOW INTERRUPT ENABLE

	TPM1->MOD = 3750;

	TPM1->CONF |= TPM_CONF_DBGMODE_MASK;
	//TPM1->POL |= TPM_POL_POL0_MASK;

	TPM1->CONTROLS[0].CnSC |= TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK;  //Edge-aligned PWM.
	//TPM1->CONTROLS[0].CnSC |= TPM_CnSC_CHIE_MASK; //Channel Interrupt Enable

	TPM1->SC |= TPM_SC_CMOD(1); //CLOCK MODE SELECTION 0b01 TPM counter increments on every TPM counter clock
}

void SetSpeed(int delay, float speed){
	TPM1->CONTROLS[0].CnV = speed;
	while(delay)
	{
		delay--;
		//printf("\ndelay %d=",delay);
	}
	//printf("Aqui tambien entro");
}

void SetBackwardSpeed(float Speed){
	//printf("\nEntro a la funcion\n");
	SetSpeed(delayValue, STOP_ENGINE);
	SetSpeed(delayValue, 1300);
	SetSpeed(delayValue, 1500);
	SetSpeed(delayValue, 1300);
	SetSpeed(delayValue, STOP_ENGINE);
	SetSpeed(delayValue, Speed);
}

void SetFordwardSpeed(float Speed){
	SetSpeed(1000, Speed);
}

void Stop(void){
	SetSpeed(1000, STOP_ENGINE);
}



int main(void) {

	//--------------Default Configuration ----------------------//
  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();

    //Programmer configuration
    PWMInit();

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
        i++ ;
    }
    return 0 ;
}
