#include "ESC.h"

/*
 Backward [1160, 1600]=[30.93%, 42.66%]
 Forward  [1120,600]=[29.86%, 16%]
 stop 1125=30%
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

void InitPit(void){
	/****Configurar el PIT ****/
	SIM->SCGC6 |= SIM_SCGC6_PIT_MASK;
	PIT->MCR = 0x00000000;

	//Timer 2 FREQUENCY 48MHz 20.83 ns
	PIT->CHANNEL[1].LDVAL = 6; //timer 2 genera interrupciones cada 8 del timer 1
	PIT->CHANNEL[1].TCTRL |= PIT_TCTRL_CHN_MASK | PIT_TCTRL_TIE_MASK | PIT_TCTRL_TEN_MASK;
	//Timer 1
	PIT->CHANNEL[0].LDVAL |= 0x016E35FF; //timer 1 genera interrupción cada segundo
	PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TIE_MASK | PIT_TCTRL_TEN_MASK;
	EnableIRQ(PIT_IRQn);
}

void ConfigTimePit(int time){
	PIT->CHANNEL[0].TCTRL = 0;
	PIT->CHANNEL[1].TCTRL = 0;
	PIT->CHANNEL[1].LDVAL = time-1; //timer 2 genera interrupciones cada 8 del timer 1
	PIT->CHANNEL[1].TCTRL |= PIT_TCTRL_CHN_MASK | PIT_TCTRL_TIE_MASK | PIT_TCTRL_TEN_MASK;
	PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TIE_MASK | PIT_TCTRL_TEN_MASK;
}

void SetDuty(int delay, int duty){
	TPM1->CONTROLS[0].CnV = duty;
	while(delay)
	{
		delay--;
	}
}

int SetBackwardSpeed(float Speed){ //Backward [1160, 1600]
	if(Speed >= minBwSpeed && Speed <= maxBwSpeed){
		SetDuty(delayValue, STOP_ENGINE);
		SetDuty(delayValue, 1300);
		SetDuty(delayValue, 1500);
		SetDuty(delayValue, 1300);
		SetDuty(delayValue, STOP_ENGINE);
		SetDuty(delayValue, GetBackwardDuty(wheelR, Speed));
		return 0;
	}else{
		return -1;
	}
}

int SetFordwardSpeed(float Speed){ //Forward  [1120,600]
	if(Speed >= minFwSpeed && Speed <= maxFwSpeed){
		SetDuty(1000, GetForwardDuty(wheelR, Speed));
		return 0;
	}else{
		return -1;
	}
}

void Stop(void){// stop 1125
	SetDuty(1000, STOP_ENGINE);
}

/**
 * min 10.72 cm/s , max 1126 cm/s
 * */
float GetForwardSpeed(float WheelR, float duty){
	return 0.35744*WheelR*(1125-duty);
}
/**
 * min 44.44 cm/s, 603 cm/s
 * */

float GetBackwardSpeed(float WheelR, float duty){
	return 0.21164*WheelR*(duty-1125);
}

int GetForwardDuty(float WheelR, float speed){
	return 1125-speed/(WheelR*0.35744);
}

int GetBackwardDuty(float WheelR, float speed){
	return 1125+speed/(WheelR*0.21164);
}
