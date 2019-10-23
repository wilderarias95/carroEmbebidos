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

volatile int flagPit0 = 0, flagPit1=0;
volatile int error=0;
volatile int16_t Hxadj, Hyadj, Hzadj, HxR, HyR, HzR;
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
		printf("ch1");
	}
}

void Prueba1(void){
	InitPit();
	SetFordwardSpeed(10);
	while(flagPit1==0){
		if(flagPit0==1){
			flagPit0=0;
			printf("p1\n");
		}
	}
	ConfigTimePit(2);
	SetBackwardSpeed(280);
	while(flagPit1==1){
		if(flagPit0==1){
			flagPit0=0;
			printf("p2\n");
		}
	}
	ConfigTimePit(8);
	SetFordwardSpeed(462);
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

int InitIMU(void){
    mag3110_init(MPU9250_ADDRESS << 1); //Magnetometro IMU
    i2c1_single_byte_write(2, INT_PIN_CFG); //bypass to change into magnetometer

  	mag3110_init(AK8963_ADDRESS << 1);
  	i2c1_single_byte_read(&data, WHO_AM_I_AK8963); //WhoAmI magetometer IMU
  	if (data != 0x48){
  		return -1;
  	}
  	i2c1_single_byte_write(0x16, AK8963_CNTL);
  	return 0;
}



void ReadMeasurentData(void){
	error  = i2c1_single_byte_read(&XL, AK8963_XOUT_L);
	error += i2c1_single_byte_read(&XH, AK8963_XOUT_H);
	error += i2c1_single_byte_read(&YL, AK8963_YOUT_L);
	error += i2c1_single_byte_read(&YH, AK8963_YOUT_H);
	error += i2c1_single_byte_read(&ZL, AK8963_ZOUT_L);
	error += i2c1_single_byte_read(&ZH, AK8963_ZOUT_H);
	error += i2c1_single_byte_read(&ST2, AK8963_ST2);
}

void ReadReferenceData(void){
	HxR = XH << 8 | XL;
	HyR = YH << 8 | YL;
	HzR = ZH << 8 | ZL;
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
    //MPU9250 CONTROL IMU
    InitI2C();
    error = InitIMU();
   /* if(error == -1){
    	return -1;
    }
  	while(1){
  		data = 0;
		while(!(data & 0x01)){
			i2c1_single_byte_read(&data, AK8963_ST1);
		}
		ReadMeasurentData();
		if (!error){
  			if(ST2 == 0x10){
  				Hxadj = XH << 8 | XL;
  				Hyadj = YH << 8 | YL;
  				Hzadj = ZH << 8 | ZL;
  				printf("Hx = %d", Hxadj);
				printf("\tHy = %d", Hyadj);
				printf("\tHz = %d\n", Hzadj);
  			}
  		}
  	}*/

    Prueba1();

    return 0;
}
