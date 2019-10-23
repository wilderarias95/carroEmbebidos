/*
 * i2c_data_lib.c
 *
 *  Created on: 8/11/2017
 *      Author: Ricardo
 */

#include "I2C_LIB.h"
#include "i2c_data_lib.h"
#include <time.h>

#define MMA8451_ADD_SA0_1 0x3A
#define MMA8451_ADD_SA0_0 0x38

typedef enum{
	ST_IDLE,
	ST_START,
	ST_REGISTER_ADDRESS,
	ST_REPEAT_START,
	ST_DATA_WRITE,
	ST_DATA_READ
}i2c_state_t;

volatile uint32_t i2c1_counter;
volatile i2c_state_t i2c1_state;
volatile uint8_t dev_address;
volatile uint32_t timeout;

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Stroing start time
    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds);
}

int i2c1_do_start()
{
	timeout = 0;
	while ((bI2C1_BUSY==1)&&(timeout++<1000));    // Wait while bus is busy or timeout expire (TODO:Please check the order)
	if (timeout>=1000)
		return -1;                                // Timeout expired, return error
	rI2C1_C1 |= mI2C_C1_TX;
	rI2C1_C1 |= mI2C_C1_MST;         // Setup transfer mode (TX=1), setup master mode (MST=1) and as consequence generate start signal

	while ((bI2C1_BUSY ==1)&&(timeout++<1000));    // Wait while bus is idle or timeout expire (TODO:Please check the order)
	if (timeout>=1000)
		return -1;
	return 0;
}

int i2c1_do_repeat_start()
{
	timeout = 0;
	rI2C1_C1 |= mI2C_C1_RSTA;					 // Repeat start condition, only when device is the bus master
	while ((bI2C1_BUSY==0)&&(timeout++<1000));   // Wait while bus is idle or timeout expire
	if (timeout>=1000)
		return -1;                               // Timeout expired, return error
	return 0;
}

int i2c1_do_stop()
{
	rI2C1_C1 &= ~mI2C_C1_MST;                    // Setup slave mode (MST=0), as consequence stop signal is generated
	timeout = 0;
	while ((bI2C1_BUSY==1)&&(timeout++<1000));   // Wait while bus is busy or timeout expire
	if (timeout>=1000)
		return -1;                               // Timeout expired, return error
	return 0;
}

int i2c1_write_address(uint8_t RW)
{
	timeout = 0;
	while ((bI2C1_TCF==0)&&(timeout++<1000)); // Wait for ongoing transfers to finish or timeout to expire
	if (timeout>=1000)                        //
		return -1;							  // Timeout expired, return error
	while(bI2C1_EMPTY==0);                    // Check if TX buffer is empty
	rI2C1_D = dev_address + (RW & 0x01);      // Transfer device address (7:1) + mode R/W (0)

	timeout = 0;
	while ((bI2C1_IICIF==0)&&(timeout++<1000)); // Wait for transmission complete or timeout to expire
	if (timeout>=1000)
		return -1;

	rI2C1_S |= mI2C_S_IICIF;                 // Clear interrupt flag

	if(bI2C1_RXAK==1)                        // Check if ACK was received
		return -4; 						     // No ACK received

	return 0;
}

int i2c1_write_data(uint8_t data)
{
	timeout = 0;
	while ((bI2C1_TCF==0)&&(timeout++<1000));   // Wait for ongoing transfers to finish or timeout to expire
	if (timeout>=1000)
		return -1;                              // Timeout expired, return error

	timeout = 0;
	while((bI2C1_EMPTY==0)&&(timeout++<1000));  // Check if TX buffer is empty
	if (timeout>=1000)
		return -1;                              // Timeout expired, return error

	rI2C1_D = data;                             // Transfer data
	timeout = 0;
	while ((bI2C1_IICIF==0)&&(timeout++<1000)); // Wait for transmission complete or timeout to expire
	if (timeout>=1000)
		return -1;                              // Timeout expired, return error
	rI2C1_S |= mI2C_S_IICIF;
	if(bI2C1_RXAK==1)                           // Check if ACK was received
		return -1;                              // Timeout expired, return error

	return 0;
}

int i2c1_read_data(uint8_t *data, uint8_t ack)               	// ack=1 do ack in reception,  ack=0 don't ack in reception
{
	timeout = 0;
	while ((bI2C1_TCF==0)&&(timeout++<1000));					// Wait for ongoing transfers to finish or timeout to expire
	if (timeout>=1000)
		return -1;                                           	// Timeout expired, return error
	if (ack)
		rI2C1_C1 = ((~(mI2C_C1_TX| mI2C_C1_TXAK))&rI2C1_C1);    // Setup reception mode (TX=0), and enable ACK generation (TXAK=0)
	else
		rI2C1_C1 = ((~mI2C_C1_TX)&rI2C1_C1) | mI2C_C1_TXAK;     // // Setup reception mode (TX=0), no ACK generation (TXAK=1)
	*data = rI2C1_D;

	timeout=0;
	while ((bI2C1_IICIF==0)&&(timeout++<1000));
	if (timeout>=1000)
		return -1;                          					// Timeout expired, return error
	rI2C1_S |= mI2C_S_IICIF;

	return 0;
}

int i2c1_single_byte_read(uint8_t * data, uint8_t reg_address)
{
	int error = 0;
	error = i2c1_do_start();
	error += i2c1_write_address(0);
	error += i2c1_write_data(reg_address);
	error += i2c1_do_repeat_start();
	error += i2c1_write_address(1);
	error += i2c1_read_data(data, 1); // dummy read for MMA851Q
	error += i2c1_read_data(data, 0); // real read
	error += i2c1_do_stop();
	return error;
}

int i2c1_multi_byte_read(uint8_t * data, uint8_t N, uint8_t reg_address)
{
	int error = 0;
	int i;
	error = i2c1_do_start();
	error += i2c1_write_address(0);
	error += i2c1_write_data(reg_address);
	error += i2c1_do_repeat_start();
	error += i2c1_write_address(1);
	error += i2c1_read_data(data, 1); // dummy read for MMA851Q
	for (i=0; i<N-1;i++){
		error += i2c1_read_data(&data[i], 1);
		error += i2c1_read_data(&data[i], 0); // real read
	}
	error += i2c1_do_stop();
	return error;
}

int i2c1_single_byte_write(uint8_t data, uint8_t reg_address)
{
	int error = 0;
	error = i2c1_do_start();
	error += i2c1_write_address(0);
	error += i2c1_write_data(reg_address);
	error += i2c1_write_data(data);
	error += i2c1_do_stop();
	return error;
}

int i2c1_multiple_byte_write(uint8_t *data, uint8_t N, uint8_t reg_address)
{
	int error = 0;
	int i;
	error = i2c1_do_start();
	error += i2c1_write_address(0);
	error += i2c1_write_data(reg_address);
	for (i=0;i<N; i++)
		error += i2c1_write_data(data[i]);
	error += i2c1_do_stop();
	return error;
}

void mma8451q_init(uint8_t address){

	bI2C1_ICR = 0x1F;	                 // Set the I2C baud rate
	bI2C1_MULT = kI2C_MULT_BY_2;         // Set the I2C baud rate
	bI2C1_FLT = 0;
	rI2C1_C1 |= mI2C_C1_IICEN;            // Enable I2C module
	bI2C1_FACK = 0;
	rI2C1_C2 = 0x00;

	dev_address = address;
	i2c1_counter = 0;
	i2c1_state = ST_IDLE;
}

void mag3110_init(uint8_t address){

	bI2C1_ICR = 0x1F;	                 // Set the I2C baud rate
	bI2C1_MULT = kI2C_MULT_BY_2;         // Set the I2C baud rate
	bI2C1_FLT = 0;
	rI2C1_C1 |= mI2C_C1_IICEN;            // Enable I2C module
	bI2C1_FACK = 0;
	rI2C1_C2 = 0x00;

	dev_address = address;
	i2c1_counter = 0;
	i2c1_state = ST_IDLE;
}

int8_t mma8451q_single_byte_read(uint8_t * data, uint8_t reg_address){
	// 1. START + DEVICE ADDRESS + WRITE MODE
	// 2. REGISTER ADDRESS
	// 3. REPEAT START + DEVICE ADDRESS + READ MODE
	// 4. READ BYTE
	// 5. NAK + STOP

	timeout = 0;

	rI2C1_C1 |= mI2C_C1_TX | mI2C_C1_MST;
	//bI2C1_TX = 1;
	// Start
	//bI2C1_MST = 1; // Generate Start
	while ((bI2C1_BUSY==1)&&(timeout++<1000));
	if (timeout>=1000)
		return -1;
	// Address device for writing
	timeout = 0;
	while ((bI2C1_TCF==0)&&(timeout++<1000));
	if (timeout>=1000)
		return -2;
	while(bI2C1_EMPTY==0);
	rI2C1_D = dev_address; // Transfer device address
	timeout = 0;
	while ((bI2C1_IICIF==0)&&(timeout++<1000));
	if (timeout>=1000)
		return -3;
	//bI2C1_IICIF = 1;
	rI2C1_S |= mI2C_S_IICIF;

	if(bI2C1_RXAK==1)
		return -4; // wait transfer ACK

	// Write Register Address
	timeout = 0;
	while ((bI2C1_TCF==0)&&(timeout++<1000));
	if (timeout>=1000)
		return -5;
	while(bI2C1_EMPTY==0);
	rI2C1_D = reg_address; // Transfer device address
	timeout = 0;
	while ((bI2C1_IICIF==0)&&(timeout++<1000));
	if (timeout>=1000)
		return -6;
	rI2C1_S |= mI2C_S_IICIF;
	if(bI2C1_RXAK==1)
		return -7; // wait transfer ACK

	//for(int i=1;i<10000;i++);

	// Repeat Start
	//bI2C1_RSTA = 1;
	rI2C1_C1 |= mI2C_C1_RSTA;
	timeout = 0;
	while ((bI2C1_BUSY==0)&&(timeout++<1000));
	if (timeout>=1000)
		return -8;

	if (bI2C1_ARBL==1)
		return -81;
	// Address devise for reading

	timeout = 0;
	while ((bI2C1_TCF==0)&&(timeout++<1000));
	if (timeout>=1000)
		return -9;
	while(bI2C1_EMPTY==0);
	rI2C1_D = dev_address+1; // Transfer device address
	timeout = 0;
	while ((bI2C1_IICIF==0)&&(timeout++<1000));
	if (timeout>=1000)
		return -10;
	rI2C1_S |= mI2C_S_IICIF;
//	if(bI2C1_RXAK==1)
//		return -11; // wait transfer ACK

	// Read Data 0
	timeout = 0;
	while ((bI2C1_TCF==0)&&(timeout++<1000));
	if (timeout>=1000)
		return -12;
	//bI2C1_TX = 0;
	//bI2C1_TXAK = 1;

	rI2C1_C1 = ((~(mI2C_C1_TX| mI2C_C1_TXAK))&rI2C1_C1) ;
	*data = rI2C1_D;
	while ((bI2C1_IICIF==0)&&(timeout++<1000));
	if (timeout>=1000)
		return -13;
	rI2C1_S |= mI2C_S_IICIF;

	// Read Data 1
	timeout = 0;
	while ((bI2C1_TCF==0)&&(timeout++<1000));
	if (timeout>=1000)
		return -22;
	//bI2C1_TX = 1;
	//bI2C1_TXAK = 1;
	rI2C1_C1 = ((~mI2C_C1_TX)&rI2C1_C1) | mI2C_C1_TXAK;
	*data = rI2C1_D;
	while ((bI2C1_IICIF==0)&&(timeout++<1000));
	if (timeout>=1000)
		return -23;
	rI2C1_S |= mI2C_S_IICIF;

	// Stop
	rI2C1_C1 &= ~mI2C_C1_MST;
	timeout = 0;
	while ((bI2C1_BUSY==1)&&(timeout++<1000));
	if (timeout>=1000)
		return -14;
	return 0;
}

int8_t mma8451q_multiple_byte_read(uint8_t * data, uint8_t reg_address, uint8_t N){
	return 0;
}

int8_t mma8451q_single_byte_write(uint8_t * data, uint8_t reg_address){
	return 0;
}

int8_t mma8451q_multiple_byte_write(uint8_t * data, uint8_t reg_address, uint8_t N){
	return 0;
}
