/*
 * i2c_data_lib.h
 *
 *  Created on: 8/11/2017
 *      Author: Ricardo
 */

#ifndef I2C_DATA_LIB_H_
#define I2C_DATA_LIB_H_

int i2c1_single_byte_read(uint8_t * data, uint8_t reg_address);
int i2c1_multi_byte_read(uint8_t * data, uint8_t N, uint8_t reg_address);
int i2c1_single_byte_write(uint8_t data, uint8_t reg_address);
int i2c1_multiple_byte_write(uint8_t *data, uint8_t N, uint8_t reg_address);

void mma8451q_init(uint8_t address);
void mag3110_init(uint8_t address);
void delay(int number_of_seconds);

int8_t mma8451q_single_byte_read(uint8_t * data, uint8_t reg_address);
int8_t mma8451q_multiple_byte_read(uint8_t * data, uint8_t reg_address, uint8_t N);

int8_t mma8451q_single_byte_write(uint8_t * data, uint8_t reg_address);
int8_t mma8451q_multiple_byte_write(uint8_t * data, uint8_t reg_address, uint8_t N);


#endif /* I2C_DATA_LIB_H_ */
