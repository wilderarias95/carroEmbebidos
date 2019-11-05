/*
 * direccion.c
 *
 *  Created on: 1 nov. 2019
 *      Author: santiago
 *
 */
#include "direccion.h"


void InitSteering(void){
	/****** Inicializa el TPM ******/
		SIM->SCGC6 |= SIM_SCGC6_TPM0_MASK; //TPM0 clock gate control enable
		SIM->SOPT2 |= SIM_SOPT2_TPMSRC(1); //tpm clock source 0b01 IRC48M clock

		//select PWM out
		SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;   //PORTA Clock gate control enable
		PORTD->PCR[0] |= PORT_PCR_MUX(4);// PTA4 ALT3(TPM0_CH1)

		TPM0->SC |= TPM_SC_PS(6); // Prescale factor selection 0b110 Divide by 64
		//TPM1->SC |= TMP1_SC_TOIE_MASK; //TIMER OVERFLOW INTERRUPT ENABLE

		TPM0->MOD = 15000;

		TPM0->CONF |= TPM_CONF_DBGMODE_MASK;
		//TPM1->POL |= TPM_POL_POL0_MASK;

		TPM0->CONTROLS[0].CnSC |= TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK;  //Edge-aligned PWM.
		//TPM1->CONTROLS[0].CnSC |= TPM_CnSC_CHIE_MASK; //Channel Interrupt Enable

		TPM0->SC |= TPM_SC_CMOD(1); //CLOCK MODE SELECTION 0b01 TPM counter increments on every TPM counter clock
		//TPM0->CONTROLS[0].CnV = 8000;
}
void TurnRight (void){
	TPM0->CONTROLS[0].CnV = 750;
	int delay = 250000;
	while(delay)
	{
		delay--;
	}
}
void TurnLeft (void){
	TPM0->CONTROLS[0].CnV = 1500;
	int delay = 250000;
	while(delay)
	{
		delay--;
	}
}
void KeepFw (void){
	TPM0->CONTROLS[0].CnV = 1125;
	int delay = 250000;
	while(delay)
	{
		delay--;
	}
}
