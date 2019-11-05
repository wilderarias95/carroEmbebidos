 /**
 * @file    CarControl.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "clock_config.h"
#include "pin_mux.h"
#include "math.h"

#include "ESC.h"
#include "i2c_data_lib.h"
#include "MPU9250.h"
#include "direccion.h"
#include <math.h>

volatile int flagPit0 = 0, flagPit1=0;
volatile int error=0;
volatile int16_t Hxadj, Hyadj, Hzadj, Hxmin, Hxmax, Hymin, Hymax;
uint8_t data = -1; //to read 1 byte from any register
uint8_t XL, XH, YL, YH, ZL, ZH, ST2;

void PIT_IRQHandler(void){
	if(PIT->CHANNEL[0].TFLG){
		PIT->CHANNEL[0].TFLG=PIT_TFLG_TIF_MASK;
		flagPit0=1;
	}
	if(PIT->CHANNEL[1].TFLG){
		PIT->CHANNEL[1].TFLG=PIT_TFLG_TIF_MASK;
		flagPit1++;
		//printf("ch1");
	}
}

int InitIMU(void){
    mag3110_init(MPU9250_ADDRESS << 1); //Magnetometro IMU
    i2c1_single_byte_write(2, INT_PIN_CFG); //bypass to change into magnetometer

  	mag3110_init(AK8963_ADDRESS << 1);
  	i2c1_single_byte_read(&data, WHO_AM_I_AK8963); //WhoAmI magetometer IMU
  	if (data != 0x48){
  		printf("Error Who am I?\n");
  		return -1;
  	}
  	i2c1_single_byte_write(0x12, AK8963_CNTL);
  	delay(50);
  	return 0;
}

void ReadMeasurentData(void){
	i2c1_single_byte_read(&data, AK8963_ST1);
	do{
		i2c1_single_byte_read(&data, AK8963_ST1);
	}while(!(data & 0x03));
	error  = i2c1_single_byte_read(&XL, AK8963_XOUT_L);
	error += i2c1_single_byte_read(&XH, AK8963_XOUT_H);
	error += i2c1_single_byte_read(&YL, AK8963_YOUT_L);
	error += i2c1_single_byte_read(&YH, AK8963_YOUT_H);
	//error += i2c1_single_byte_read(&ZL, AK8963_ZOUT_L);
	//error += i2c1_single_byte_read(&ZH, AK8963_ZOUT_H);
	error += i2c1_single_byte_read(&ST2, AK8963_ST2);

	XL = fabs(XL);
	XH = fabs(XH);
	YL = fabs(YL);
	YH = fabs(YH);
}

void ReadReferenceData(void){
	int c=0;
	while(c<10){
		ReadMeasurentData();
		if (!error){
			if(!(ST2 == 0x08)){
				++c;
				Hxadj = XH << 8 | XL;
				Hyadj = YH << 8 | YL;
				if(c != 1){
					if(Hxadj < Hxmin){
						Hxmin = Hxadj;
					}else if(Hxadj > Hxmax){
						Hxmax = Hxadj;
					}
					if(Hyadj < Hymin){
						Hymin = Hyadj;
					}else if(Hyadj > Hymax){
						Hymax = Hyadj;
					}
				}else{
					Hxmin = Hxadj;
					Hxmax = Hxadj;
					Hymin = Hyadj;
					Hymax = Hyadj;
				}
			}
		}
	}
	/*printf("Hxmin = %d", Hxmin);
	printf("\tHxmax = %d", Hxmax);
	printf("\tHymin = %d", Hymin);
	printf("\tHymax = %d\n", Hymax);*/
}

void CurrentDirection(void){
	int c = 0;
	Hxadj = 0;
	Hyadj = 0;
	while(c<5){
		ReadMeasurentData();
		if (!error){
			if(!(ST2 == 0x08)){
				c++;
				Hxadj += XH << 8 | XL;
				Hyadj += YH << 8 | YL;
			}
		}
	}
	Hxadj /= 5;
	Hyadj /= 5;
	/*printf("Hx = %d", Hxadj);
	printf("\tHy = %d\n", Hyadj);*/
}

void CorrecionWE(void){
	CurrentDirection();
	if((Hyadj > Hymax+8)){ //Izquierda (Hxadj > Hxmax+5)
		printf("izq\n");
		TurnRight();
	}else if((Hyadj < Hymin-8)){ //Derecha (Hxadj < Hxmin-5)
		printf("Der\n");
		TurnLeft();
	}else{
		printf("Recto\n");
		KeepFw();
	}
}

void CorrecionEW(){
	CurrentDirection();
	if((Hyadj < Hymax-8)){ //Izquierda (Hxadj > Hxmax+5)
		printf("izq\n");
		TurnRight();
	}else if((Hyadj > Hymin+8)){ //Derecha (Hxadj < Hxmin-5)
		printf("Der\n");
		TurnLeft();
	}else{
		printf("Recto\n");
		KeepFw();
	}
}

void Prueba1(void){
	ReadReferenceData();
	SetFordwardSpeed(50);
	InitPit();
	while(flagPit1==0){
		if(flagPit0==1){
			flagPit0=0;
			//printf("p1\n");
			CorrecionWE();
		}
	}
	SetFordwardSpeed(10);
	TurnLeft ();
	ConfigTimePit(4);
	//printf("giro");
	while(flagPit1==1){
		/*if(flagPit0==1){
			flagPit0=0;
		}*/
	}
	ReadReferenceData();
	SetFordwardSpeed(50);
	ConfigTimePit(8);
	while(flagPit1==2){
		if(flagPit0==1){
			flagPit0=0;
			CorrecionEW();
		}
	}
	Stop();
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
    int maxFw = GetForwardSpeed(ratio, 600); //
	int minFw = GetForwardSpeed(ratio, 1120); //
	int maxBw = GetBackwardSpeed(ratio, 1600); //
	int minBw = GetBackwardSpeed(ratio, 1160); //
	InitDriver(800, ratio, maxFw, minFw, maxBw, minBw);
	InitSteering();
    //MPU9250 CONTROL IMU
    InitI2C();
    error = InitIMU();
    if(error == -1){
    	return -1;
    }
    Prueba1();

    return 0;
}
