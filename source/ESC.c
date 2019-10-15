#include "ESC.h"

/*
 Backward [1160, 1600]
 Forward  [1120,600]
 stop 1125
 */

volatile int delayValue = 250000;
volatile static int STOP_ENGINE = 1125; //valor PWM para STOP
volatile float maxFwSpeed; //velocidad máxima hacía adelante
volatile float minFwSpeed; //velocidad mínima hacía adelante
volatile float maxBwSpeed; //velocidad máxima hacía atrás
volatile float minBwSpeed; //velocidad mínima hacía atrás
volatile float wheelR; //diametro de la rueda
volatile int motorKV; //Número de RPM que puede alcanzar el motor

void InitDriver(int MotorKV, float WheelR, float MaxFwSpeed, float MinFwSpeed, float MaxBwSpeed, float MinBwSpeed){
	/****** Inicializa el TPM ******/
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

	/***** inicializar parametros carro *****/
	motorKV = MotorKV;
	wheelR = WheelR;
	maxFwSpeed = MaxFwSpeed;
	minFwSpeed = MinFwSpeed;
	maxBwSpeed = MaxBwSpeed;
	minBwSpeed = MinBwSpeed;
}

void SetSpeed(int delay, float speed){
	TPM1->CONTROLS[0].CnV = speed;
	while(delay)
	{
		delay--;
	}
}

int SetBackwardSpeed(float Speed){ //Backward [1160, 1600]
	if(Speed >= minBwSpeed && Speed <= maxBwSpeed){
		SetSpeed(delayValue, STOP_ENGINE);
		SetSpeed(delayValue, 1300);
		SetSpeed(delayValue, 1500);
		SetSpeed(delayValue, 1300);
		SetSpeed(delayValue, STOP_ENGINE);
		SetSpeed(delayValue, Speed);
		return 0;
	}else{
		return -1;
	}
}

int SetFordwardSpeed(float Speed){ //Forward  [1120,600]
	if(Speed >= maxFwSpeed && Speed <= minFwSpeed){
		SetSpeed(1000, Speed);
		return 0;
	}else{
		return -1;
	}
}

void Stop(void){// stop 1125
	SetSpeed(1000, STOP_ENGINE);
}
