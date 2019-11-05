/*
 * I2C_LIB.h
 *
 *  Created on: 24/07/2017
 *      Author: Nicolas Escallón Orrego
 */

#ifndef I2C_LIB_H_
#define I2C_LIB_H_

#include <stdint.h>

typedef union {
	uint8_t BYTE;										// Acceso a todo el registro
	struct {
		uint8_t			:1;	  							// Reserved
		uint8_t AD		:7;	  							// Slave Address
	} BITS;
} __i2c_a1_t;

enum{
	kI2C_MULT_BY_1,
	kI2C_MULT_BY_2,
	kI2C_MULT_BY_4
};

#define mI2C_F_ICR(X) (X & 0x3F)					// Clock Rate
#define mI2C_F_MULT(X) (X & 0x03)<<6				// Multiplier Factor

typedef union {
	uint8_t BYTE;		    							// Acceso a todo el registro
	struct {
		uint8_t ICR		  :6;	    					// Clock Rate
		uint8_t MULT	  :2;	    					// Multiplier Factor
	} BITS;
} __i2c_f_t;

enum{
	mI2C_C1_DMAEN = 0x01,								// DMA enable
	mI2C_C1_WUEN = 0x2,									// Wake Up Enable
	mI2C_C1_RSTA = 0x4,									// Repeat START
	mI2C_C1_TXAK = 0x8,									// Transmit Acknowledge Enable
	mI2C_C1_TX = 0x10,									// Transmit Mode Select
	mI2C_C1_MST = 0x20,									// Master Mode Select
	mI2C_C1_IICIE = 0x40,								// I2C Interrupt Enable
	mI2C_C1_IICEN = 0x80								// I2C Enable
};

typedef union {
	uint8_t BYTE;		    							// Acceso a todo el registro
	struct {
		uint8_t DMAEN	  :1;	    					// DMA enable
		uint8_t WUEN	  :1;	    					// Wake Up Enable
		uint8_t RSTA	  :1;	    					// Repeat START
		uint8_t TXAK	  :1;	    					// Transmit Acknowledge Enable
		uint8_t TX		  :1;	    					// Transmit Mode Select
		uint8_t MST		  :1;	    					// Master Mode Select
		uint8_t IICIE	  :1;	    					// I2C Interrupt Enable
		uint8_t IICEN	  :1;	    					// I2C Enable

	} BITS;
} __i2c_c1_t;

enum{
	mI2C_S_RXAK = 0x01,	    							// Receive Acknowledge
	mI2C_S_IICIF = 0x02,	    						// Interrupt Flag
	mI2C_S_SRW = 0x04,	    							// Slave Read/Write
	mI2C_S_RAM = 0x08,	    							// Range Address Match
	mI2C_S_ARBL = 0x10,	    							// Arbitration Lost
	mI2C_S_BUSY = 0x20,	    							// Bus busy
	mI2C_S_IAAS = 0x40,	    							// Addressed as a slave
	mI2C_S_TCF = 0x80	    							// Transfer Complete Flag
};

typedef union {
	uint8_t BYTE;		    							// Acceso a todo el registro
	struct {
		uint8_t RXAK	:1;	    						// Receive Acknowledge
		uint8_t IICIF	:1;	    						// Interrupt Flag
		uint8_t SRW	  	:1;	    						// Slave Read/Write
		uint8_t RAM	  	:1;	    						// Range Address Match
		uint8_t ARBL	:1;	    						// Arbitration Lost
		uint8_t BUSY	:1;	    						// Bus busy
		uint8_t IAAS 	:1;	    						// Addressed as a slave
		uint8_t TCF  	:1;	    						// Transfer Complete Flag
	} BITS;
} __i2c_s_t;

typedef uint8_t __i2c_d_t;

#define mI2C_C2_AD(X) (X & 0x07)	    				// Slave Address

enum{
	mI2C_C2_RMEN = 0x08,	    						// Range Address Matching Enable
	mI2C_C2_SBRC = 0x10,	    						// Slave Baud Rate Control
	mI2C_C2_HDRS = 0x20,	    						// High drive select
	mI2C_C2_ADEXT = 0x40,	    						// Address Extension
	mI2C_C2_GCAEN = 0x80	    						// General Call Address enable
};

typedef union {
	uint8_t BYTE;		    							// Acceso a todo el registro
	struct {
		uint8_t AD	  	  :3;	    					// Slave Address
		uint8_t RMEN	  :1;	    					// Range Address Matching Enable
		uint8_t SBRC	  :1;	    					// Slave Baud Rate Control
		uint8_t HDRS	  :1;	    					// High drive select
		uint8_t ADEXT	  :1;	    					// Address Extension
		uint8_t GCAEN	  :1;	    					// General Call Address enable
	} BITS;
} __i2c_c2_t;

#define mI2C_FLT_FLT(X) (X & 0x0F)						// Programmable Filter Factor
enum{
	mI2C_FLT_STARTF = 0x10,	    						// Bus Start detect flag
	mI2C_FLT_SSIE = 0x20,	    						// Bus stop or start interrupt enable
	mI2C_FLT_STOPF = 0x40,	    						// Bus stop detecting flag
	mI2C_FLT_SHEN = 0x80	    						// Stop Hold Enable
};

typedef union {
	uint8_t BYTE;		    							// Acceso a todo el registro
	struct {
		uint8_t FLT		:4;	    						// Programmable Filter Factor
		uint8_t STARTF	:1;	    						// Bus Start detect flag
		uint8_t SSIE	:1;	    						// Bus stop or start interrupt enable
		uint8_t STOPF	:1;	    						// Bus stop detecting flag
		uint8_t SHEN	:1;	    						// stop Hold Enable
	} BITS;
} __i2c_flt_t;

typedef union {
	uint8_t BYTE;		    							// Acceso a todo el registro
	struct {
		uint8_t 		:1;
		uint8_t RAD		:7;	    						// Range Slave Address
	} BITS;
} __i2c_ra_t;

enum{
	mI2C_SMB_SHTF2IE = 0x01,    						// SHTF2 interrupt Enable
	mI2C_SMB_SHTF2 = 0x02,	    						// SCL High Timeout Flag2
	mI2C_SMB_SHTF1 = 0x04,								// SCL High Timeout Flag1
	mI2C_SMB_SLTF = 0x08,	    						// SCL Low Timeout Flag
	mI2C_SMB_TCKSEL = 0x10,	    						// Timeout Counter Clock Select
	mI2C_SMB_SIICAEN = 0x20,    						// Second I2C address enable
	mI2C_SMB_ALERTEN = 0x40,    						// SMBus Alert Response Address Enable
	mI2C_SMB_FACK = 0x80	    						// Fast NACK/ACK Enable
};

typedef union {
	uint8_t BYTE;		    							// Acceso a todo el registro
	struct {
		uint8_t SHTF2IE	:1;	    						// SHTF2 interrupt Enable
		uint8_t SHTF2	:1;	    						// SCL High Timeout Flag2
		uint8_t SHTF1	:1;								// SCL High Timeout Flag1
		uint8_t SLTF  	:1;	    						// SCL Low Timeout Flag
		uint8_t TCKSEL 	:1;	    						// Timeout Counter Clock Select
		uint8_t SIICAEN	:1;	    						// Second I2C address enable
		uint8_t ALERTEN	:1;	    						// SMBus Alert Response Address Enable
		uint8_t FACK 	:1;	    						// Fast NACK/ACK Enable
	} BITS;
} __i2c_smb_t;

typedef union {
	uint8_t BYTE;		    							// Acceso a todo el registro
	struct {
		uint8_t 		:1;	    						// reserved
		uint8_t SAD		:7;	    						// SMBus Address
		
	} BITS;
} __i2c_a2_t;

typedef uint8_t __i2c_slth_t;		    				// Acceso a todo el registro

typedef uint8_t __i2c_sltl_t;

enum{
	mI2C_S2_EMPTY = 0x01,	    						// Empty Flag
	mI2C_S2_ERROR = 0x02	    						// Error Flag
};

typedef union {
	uint8_t BYTE;		    							// Acceso a todo el registro
	struct {
		uint8_t EMPTY	:1;	    						// Empty Flag
		uint8_t ERROR	:1;	    						// Error Flag
		uint8_t 		:6;								// Reserved
	} BITS;
} __i2c_s2_t;


typedef struct{
	volatile __i2c_a1_t A1; 							// 0X000 I2C Address Register 1 (I2C0_A1)
	volatile __i2c_f_t  F; 								// 0x001 I2C Frequency Divider register (I2C0_F)
	volatile __i2c_c1_t C1; 							// 0x002 I2C Control Register 1 (I2C0_C1)
	volatile __i2c_s_t S; 								// 0x003 I2C Status register (I2C0_S)
	volatile __i2c_d_t D; 								// 0x004 I2C Data I/O register (I2C0_D)
	volatile __i2c_c2_t C2; 							// 0x005 I2C Control Register 2 (I2C0_C2)
	volatile __i2c_flt_t FLT; 							// 0x006 I2C Programmable Input Glitch Filter Register (I2C0_FLT)
	volatile __i2c_ra_t RA; 							// 0x007 I2C Range Address register (I2C0_RA)
	volatile __i2c_smb_t SMB; 							// 0x008 I2C SMBus Control and Status register (I2C0_SMB)
	volatile __i2c_a2_t A2; 							// 0x009 I2C Address Register 2 (I2C0_A2)
	volatile __i2c_slth_t SLTH;							// 0x00A I2C SCL Low Timeout Register High (I2C0_SLTH)
	volatile __i2c_sltl_t SLTL; 						// 0x00B I2C SCL Low Timeout Register Low (I2C0_SLTL)
	volatile __i2c_s2_t S2; 							// 0x00C I2C Status register 2 (I2C0_S2) 8 R
} __i2c_t;


///////////////////////////////////////////////////////////////
////////////////////	I2C 0 ////////////////////////////////
/////////////////////////////////////////////////////////////

#define sI2C0 (*((__i2c_t *)(0x40066000)))				// I2C0  general register structure

#define rI2C0_A1 sI2C0.I2C_A1.BYTE 						// I2C Address Register 1 (I2C0_A1)
#define bI2C0_AD1 sI2C0.I2C_A1.BITS.AD 					// Address

#define rI2C0_F sI2C0.I2C_F.BYTE 						// I2C Frequency Divider register (I2C0_F)
#define bI2C0_ICR sI2C0.F.BITS.ICR 						// ClockRate
#define bI2C0_MULT sI2C0.F.BITS.MULT 					// Multiplier Factor

#define rI2C0_C1 sI2C0.C1.BYTE 							// I2C Control Register 1 (I2C0_C1)
#define bI2C0_DMAEN sI2C0.C1.BITS.DMAEN 				// DMA Enable
#define bI2C0_WUEN sI2C0.C1.BITS.WUEN 					// Wakeup Enable
#define bI2C0_RSTA sI2C0.C1.BITS.RSTA 					// Repeat START
#define bI2C0_TXAK sI2C0.C1.BITS.TXAK 					// Transmit Acknowledge Enable
#define bI2C0_TX sI2C0.C1.BITS.TX 						// Transmit Mode Select
#define bI2C0_MST sI2C0.C1.BITS.MST 					// Master Mode Select
#define bI2C0_IICIE sI2C0.C1.BITS.IICIE 				// I2C Interrupt Enable
#define bI2C0_IICEN sI2C0.C1.BITS.IICEN 				// I2C Enable

#define rI2C0_S sI2C0.S.BYTE 							// I2C Status register (I2C0_S)
#define bI2C0_RXAK sI2C0.S.BITS.RXAK 					// Receive Acknowledge
#define bI2C0_IICIF sI2C0.S.BITS.IICIF 					// Interrupt Flag
#define bI2C0_SRW sI2C0.S.BITS.SRW 						// Slave Read/Write
#define bI2C0_RAM sI2C0.S.BITS.RAM 						// Range Address Match
#define bI2C0_ARBL sI2C0.S.BITS.ARBL 					// Arbitration Lost
#define bI2C0_BUSY sI2C0.S.BITS.BUSY 					// Bus Busy
#define bI2C0_IAAS sI2C0.S.BITS.IAAS 					// Addressed As A Slave
#define bI2C0_TCF sI2C0.S.BITS.TCF 						// Transfer Complete Flag

#define rI2C0_D sI2C0.D 								// I2C Data I/O register (I2C0_D)
#define bI2C0_DATA sI2C0.D 								// Data

#define rI2C0_C2 sI2C0.C2.BYTE 							// I2C Control Register 2 (I2C0_C2)
#define bI2C0_AD2 sI2C0.C2.BITS.AD 						// Slave Address
#define bI2C0_RMEN sI2C0.C2.BITS.RMEN 					// Range Address Matching Enable
#define bI2C0_SBRC sI2C0.C2.BITS.SBRC 					// Slave Baud Rate Control
#define bI2C0_HDRS sI2C0.C2.BITS.HDRS 					// High Drive Select
#define bI2C0_ADEXT sI2C0.C2.BITS.ADEXT 				// Address Extension
#define bI2C0_GCAEN sI2C0.C2.BITS.GCAEN 				// General Call Address Enable

#define rI2C0_FLT sI2C0.FLT.BYTE 						// I2C Programmable Input Glitch Filter Register (I2C0_FLT)
#define bI2C0_FLT sI2C0.FLT.BITS.FLT					// I2C Programmable Filter Factor
#define bI2C0_STARTF sI2C0.FLT.BITS.STARTF 				// I2C Bus Start Detect Flag
#define bI2C0_SSIE sI2C0.FLT.BITS.SSIE 					// I2C Bus Stop or Start Interrupt Enable
#define bI2C0_STOPF sI2C0.FLT.BITS.STOPF 				// I2C Bus Stop Detect Flag
#define bI2C0_SHEN sI2C0.FLT.BITS.SHEN 					// Stop Hold Enable

#define rI2C0_RA sI2C0.RA.BYTE 							// I2C Range Address register (I2C0_RA)
#define bI2C0_RAD sI2C0.RA.BITS.RAD 					// Range Slave Address

#define rI2C0_SMB sI2C0.SMB.BYTE 						// I2C SMBus Control and Status register (I2C0_SMB)
#define bI2C0_SHTF2IE sI2C0.SMB.BITS.SHTF2IE 			// SHTF2 Interrupt Enable
#define bI2C0_SHTF2 sI2C0.SMB.BITS.SHTF2 				// SCL High Timeout Flag 2
#define bI2C0_SHTF1 sI2C0.SMB.BITS.SHTF1 				// SCL High Timeout Flag 1
#define bI2C0_SLTF sI2C0.SMB.BITS.SLTF 					// SCL Low Timeout Flag
#define bI2C0_TCKSEL sI2C0.SMB.BITS.TCKSEL 				// Timeout Counter Clock Select
#define bI2C0_SIICAEN sI2C0.SMB.BITS.SIICAEN 			// Second I2C Address Enable
#define bI2C0_ALERTEN sI2C0.SMB.BITS.ALERTEN 			// SMBus Alert Response Address Enable
#define bI2C0_FACK sI2C0.SMB.BITS.FACK 					// Fast NACK/ACK Enable

#define rI2C0_A2 sI2C0.A2.BYTE 							// I2C Address Register 2 (I2C0_A2)
#define bI2C0_SAD sI2C0.A2.BITS.SAD 					// SMBus Address

#define rI2C0_SLTH sI2C0.SLTH 							// I2C SCL Low Timeout Register High (I2C0_SLTH)
#define bI2C0_SSLTH sI2C0.SLTH 							// SSLT[15:8]
	
#define rI2C0_SSLTL sI2C0.SSLTL 						// I2C SCL Low Timeout Register Low (I2C0_SLTL)
#define bI2C0_SSLT sI2C0.SSLTL 							// SSLT[7:0]
	
#define rI2C0_S2 sI2C0.S2.BYTE 							// I2C Status register 2 (I2C0_S2)
#define bI2C0_EMPTY sI2C0.S2.BITS.EMPTY 				// Empty flag
#define bI2C0_ERROR sI2C0.S2.BITS.ERROR 				// Error flag

///////////////////////////////////////////////////////////////
////////////////////	I2C 1 ////////////////////////////////
/////////////////////////////////////////////////////////////

#define sI2C1 (*((__i2c_t *)(0x40067000)))				// I2C1  general register structure

#define rI2C1_A1 sI2C1.A1.BYTE 							// I2C Address Register 1 (I2C1_A1)
#define bI2C1_AD1 sI2C1.A1.BITS.AD 						// Address

#define rI2C1_F sI2C1.F.BYTE 							// I2C Frequency Divider register (I2C1_F)
#define bI2C1_ICR sI2C1.F.BITS.ICR 						// ClockRate
#define bI2C1_MULT sI2C1.F.BITS.MULT 					// Multiplier Factor

#define rI2C1_C1 sI2C1.C1.BYTE 							// I2C Control Register 1 (I2C1_C1)
#define bI2C1_DMAEN sI2C1.C1.BITS.DMAEN 				// DMA Enable
#define bI2C1_WUEN sI2C1.C1.BITS.WUEN 					// Wakeup Enable
#define bI2C1_RSTA sI2C1.C1.BITS.RSTA 					// Repeat START
#define bI2C1_TXAK sI2C1.C1.BITS.TXAK 					// Transmit Acknowledge Enable
#define bI2C1_TX sI2C1.C1.BITS.TX 						// Transmit Mode Select
#define bI2C1_MST sI2C1.C1.BITS.MST 					// Master Mode Select
#define bI2C1_IICIE sI2C1.C1.BITS.IICIE 				// I2C Interrupt Enable
#define bI2C1_IICEN sI2C1.C1.BITS.IICEN 				// I2C Enable


#define rI2C1_S sI2C1.S.BYTE 							// I2C Status register (I2C1_S)
#define bI2C1_RXAK sI2C1.S.BITS.RXAK 					// Receive Acknowledge
#define bI2C1_IICIF sI2C1.S.BITS.IICIF 					// Interrupt Flag
#define bI2C1_SRW sI2C1.S.BITS.SRW 						// Slave Read/Write
#define bI2C1_RAM sI2C1.S.BITS.RAM 						// Range Address Match
#define bI2C1_ARBL sI2C1.S.BITS.ARBL 					// Arbitration Lost
#define bI2C1_BUSY sI2C1.S.BITS.BUSY 					// Bus Busy
#define bI2C1_IAAS sI2C1.S.BITS.IAAS 					// Addressed As A Slave
#define bI2C1_TCF sI2C1.S.BITS.TCF 						// Transfer Complete Flag

#define rI2C1_D sI2C1.D 								// I2C Data I/O register (I2C1_D)
#define bI2C1_DATA sI2C1.D			 					// Data

#define rI2C1_C2 sI2C1.C2.BYTE 							// I2C Control Register 2 (I2C1_C2)
#define bI2C1_AD2 sI2C1.C2.BITS.AD 						// Slave Address
#define bI2C1_RMEN sI2C1.C2.BITS.RMEN 					// Range Address Matching Enable
#define bI2C1_SBRC sI2C1.C2.BITS.SBRC 					// Slave Baud Rate Control
#define bI2C1_HDRS sI2C1.C2.BITS.HDRS 					// High Drive Select
#define bI2C1_ADEXT sI2C1.C2.BITS.ADEXT 				// Address Extension
#define bI2C1_GCAEN sI2C1.C2.BITS.GCAEN 				// General Call Address Enable

#define rI2C1_FLT sI2C1.FLT.BYTE 						// I2C Programmable Input Glitch Filter Register (I2C1_FLT)
#define bI2C1_FLT sI2C1.FLT.BITS.FLT					// I2C Programmable Filter Factor
#define bI2C1_STARTF sI2C1.FLT.BITS.STARTF 				// I2C Bus Start Detect Flag
#define bI2C1_SSIE sI2C1.FLT.BITS.SSIE 					// I2C Bus Stop or Start Interrupt Enable
#define bI2C1_STOPF sI2C1.FLT.BITS.STOPF 				// I2C Bus Stop Detect Flag
#define bI2C1_SHEN sI2C1.FLT.BITS.SHEN 					// Stop Hold Enable

#define rI2C1_RA sI2C1.RA.BYTE 							// I2C Range Address register (I2C1_RA)
#define bI2C1_RAD sI2C1.RA.BITS.RAD 					// Range Slave Address

#define rI2C1_SMB sI2C1.SMB.BYTE 						// I2C SMBus Control and Status register (I2C1_SMB)
#define bI2C1_SHTF2IE sI2C1.SMB.BITS.SHTF2IE 			// SHTF2 Interrupt Enable
#define bI2C1_SHTF2 sI2C1.SMB.BITS.SHTF2 				// SCL High Timeout Flag 2
#define bI2C1_SHTF1 sI2C1.SMB.BITS.SHTF1 				// SCL High Timeout Flag 1
#define bI2C1_SLTF sI2C1.SMB.BITS.SLTF 					// SCL Low Timeout Flag
#define bI2C1_TCKSEL sI2C1.SMB.BITS.TCKSEL 				// Timeout Counter Clock Select
#define bI2C1_SIICAEN sI2C1.SMB.BITS.SIICAEN 			// Second I2C Address Enable
#define bI2C1_ALERTEN sI2C1.SMB.BITS.ALERTEN 			// SMBus Alert Response Address Enable
#define bI2C1_FACK sI2C1.SMB.BITS.FACK 					// Fast NACK/ACK Enable

#define rI2C1_A2 sI2C1.A2.BYTE 							// I2C Address Register 2 (I2C1_A2)
#define bI2C1_SAD sI2C1.A2.BITS.SAD 					// SMBus Address

#define rI2C1_SLTH sI2C1.SLTH 						    // I2C SCL Low Timeout Register High (I2C1_SLTH)
#define bI2C1_SSLTH sI2C1.SLTH 				            // SSLT[15:8]
	
#define rI2C1_SSLTL sI2C1.SSLTL 					    // I2C SCL Low Timeout Register Low (I2C1_SLTL)
#define bI2C1_SSLT sI2C1.SSLTL 				            // SSLT[7:0]

#define rI2C1_S2 sI2C1.S2.BYTE 							// I2C Status register 2 (I2C1_S2)
#define bI2C1_EMPTY sI2C1.S2.BITS.EMPTY 				// Empty flag
#define bI2C1_ERROR sI2C1.S2.BITS.ERROR 				// Error flag

#endif
