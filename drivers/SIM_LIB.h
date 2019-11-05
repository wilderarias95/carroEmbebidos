/*
 * SIM_LIB.h SYSTEM INTEGRATION MODULE
 *
 *  Created on: 7/09/2017
 *      Author: Ricardo Andrés Velásquez
 */

#ifndef SIM_LIB_H_
#define SIM_LIB_H_
#include <stdint.h>
enum {
	kSIM_OSCK32KSEL_OSC32KCLK=0,								// System oscillator (OSC32KCLK)
	kSIM_OSCK32KSEL_RTC_CLKIN=2,								// RTC_CLKIN
	kSIM_OSCK32KSEL_LPO_1KHZ=3									// LPO 1kHz
};

enum {
	kSIM_OSC32KOUT_ERCLK32K_NO_OUTPUT=0,						// ERCLK32K is not output.
	kSIM_OSC32KOUT_ERCLK32K_OUTPUT_PTE0=1						// ERCLK32K is output on PTE0.
};

#define mSIM_SOPT1_OSC32KOUT(X) ((X & 3) << 16)					// 32K oscillator clock output
#define mSIM_SOPT1_OSC32KSEL(X) ((X & 3) << 18)					// 32K Oscillator Clock Select

enum{
	mSIM_SOPT1_USBVSTBY = 0x20000000U,							// USB voltage regulator in standby mode during VLPR and VLPW modes
	mSIM_SOPT1_USBSSTBY = 0x40000000U,							// USB voltage regulator in standby mode during Stop, VLPS, LLS and VLLS modes
	mSIM_SOPT1_USBREGEN = 0x80000000U							// USB voltage regulator enable
};

typedef union{
	uint32_t WORD;
	struct{
		uint32_t  			: 16;								//
		uint32_t OSC32KOUT 	: 2;								// 32K oscillator clock output
		uint32_t OSC32KSEL 	: 2;								// 32K Oscillator Clock Select
		uint32_t          	: 9;								//
		uint32_t USBVSTBY  	: 1;								// USB voltage regulator in standby mode during VLPR and VLPW modes
		uint32_t USBSSTBY  	: 1;								// USB voltage regulator in standby mode during Stop, VLPS, LLS and VLLS modes
		uint32_t USBREGEN   : 1;								// USB voltage regulator enable
	}BITS;
}__sim_sopt1_t;

enum{
	mSIM_SOPT1CFG_URWE = 0x01000000U,							// USB voltage regulator enable write enable
	mSIM_SOPT1CFG_UVSWE = 0x02000000U,							// USB voltage regulator VLP standby write enable
	mSIM_SOPT1CFG_USSWE = 0x04000000U							// USB voltage regulator stop standby write enable
};

typedef union{
	uint32_t WORD;
	struct{
		uint32_t			: 24;								//
		uint32_t URWE		: 1;								// USB voltage regulator enable write enable
		uint32_t UVSWE		: 1;								// USB voltage regulator VLP standby write enable
		uint32_t USSWE		: 1;								// USB voltage regulator stop standby write enable
		uint32_t 			: 5;								//
	}BITS;
}__sim_sopt1cfg_t;

typedef struct{
	volatile __sim_sopt1_t SIM_SOPT1; 							// 0x00 System Options Register 1
	volatile __sim_sopt1cfg_t SIM_SOPT1CFG; 					// 0x04 SOPT1 Configuration Register
} __sim1_t;

#define sSIM1 (*((__sim1_t *)(0x40047000)))

#define rSIM_OPT1 sSIM1.SIM_OPT1.WORD							// System Options Register 1
#define bSIM_OSC32KOUT sSIM1.SIM_SOPT1.BITS.OSC32KOUT			// 32K oscillator clock output
#define bSIM_OSC32KSEL sSIM1.SIM_SOPT1.BITS.OSC32KSEL			// 32K Oscillator Clock Select
#define bSIM_USBVSTBY sSIM1.SIM_SOPT1.BITS.USBVSTBY				// USB voltage regulator in standby mode during VLPR and VLPW modes
#define bSIM_USBSSTBY sSIM1.SIM_SOPT1.BITS.USBSSTBY				// USB voltage regulator in standby mode during Stop, VLPS, LLS and VLLS modes
#define bSIM_USBREGEN sSIM1.SIM_SOPT1.BITS.USBREGEN				// USB voltage regulator enable

#define rSIM_SOPT1CFG sSIM1.SIM_SOPT1CFG.WORD					// SOPT1 Configuration Register
#define bSIM_URWE sSIM1.SIM_SOPT1CFG.BITS.URWE					// USB voltage regulator enable write enable
#define bSIM_UVSWE sSIM1.SIM_SOPT1CFG.BITS.UVSWE				// USB voltage regulator VLP standby write enable
#define bSIM_USSWE sSIM1.SIM_SOPT1CFG.BITS.USSWE				// USB voltage regulator stop standby write enable

enum {
	kSIM_LPUART1SRC_CLK_DISABLED=0,								// Clock disabled
	kSIM_LPUART1SRC_IRC48M=1,									// IRC48M clock
	kSIM_LPUART1SRC_OSCERCLK=2,									// OSCERCLK clock
	kSIM_LPUART1SRC_MCGIRCLK=3									// MCGIRCLK clock
};

enum {
	kSIM_LPUART0SRC_CLK_DISABLED=0,								// Clock disabled
	kSIM_LPUART0SRC_IRC48M=1,									// IRC48M clock
	kSIM_LPUART0SRC_OSCERCLK=2,									// OSCERCLK clock
	kSIM_LPUART0SRC_MCGIRCLK=3									// MCGIRCLK clock
};

enum {
	kSIM_TPMSRC_CLK_DISABLED=0,									// Clock disabled
	kSIM_TPMSRC_IRC48M=1,										// IRC48M clock
	kSIM_TPMSRC_OSCERCLK=2,										// OSCERCLK clock
	kSIM_TPMSRC_MCGIRCLK=3										// MCGIRCLK clock
};

enum {
	kSIM_FLEXIOSRC_CLK_DISABLED=0,								// Clock disabled
	kSIM_FLEXIOSRC_IRC48M=1,									// IRC48M clock
	kSIM_FLEXIOSRC_OSCERCLK=2,									// OSCERCLK clock
	kSIM_FLEXIOSRC_MCGIRCLK=3									// MCGIRCLK clock
};

enum {
	kSIM_CLKOUTSEL_BUS_CLK=2,									// Bus clock
	kSIM_CLKOUTSEL_LPO_CLK=3,									// LPO clock (1 kHz)
	kSIM_CLKOUTSEL_LIRC_CLK=4,									// LIRC_CLK
	kSIM_CLKOUTSEL_OSCERCLK=6,									// OSCERCLK
	kSIM_CLKOUTSEL_IRC48M=7										// IRC48M clock (IRC48M clock can be output to PAD only when chip VDD is 2.7-3.6 V)
};

#define mSIM_SOPT2_CLKOUTSEL(X) ((X & 7) << 5)					// CLKOUT select
#define mSIM_SOPT2_FLEXIOSRC(X) ((X & 3) << 22)					// FlexIO Module Clock Source Select
#define mSIM_SOPT2_TPMSRC(X) ((X & 3) << 24)					// TPM Clock Source Select
#define mSIM_SOPT2_LPUART0SRC(X) ((X & 3) << 26)				// LPUART0 Clock Source Select
#define mSIM_SOPT2_LPUART1SRC(X) ((X & 3) << 28)				// LPUART1 Clock Source Select

enum{
	mSIM_SOPT2_USBRC = 0x00040000U								// USB clock source select
};

typedef union{
	uint32_t WORD;
	struct{
		uint32_t				: 4;							// Reserved
		uint32_t RTCCLKOUTSEL	: 1;							// RTC Clock Out Select
		uint32_t CLKOUTSEL		: 3;							// CLKOUT select
		uint32_t 				: 10;							// Reserved
		uint32_t USBSRC			: 1;							// USB clock source select
		uint32_t 				: 3;							// Reserved
		uint32_t FLEXIOSRC		: 2;							// FlexIO Module Clock Source Select
		uint32_t TPMSRC			: 2;							// TPM Clock Source Select
		uint32_t LPUART0SRC		: 2;							// LPUART0 Clock Source Select
		uint32_t LPUART1SRC 	: 2;							// LPUART1 Clock Source Select
		uint32_t 				: 2;							// Reserved
	}BITS;
}__sim_sopt2_t;

enum {
	kSIM_TPM1CH0SRC_TPM1_CHO=0,									// TPM1_CH0 signal
	kSIM_TPM1CH0SRC_CMP0_OUTPUT=1,								// CMP0 output
	kSIM_TPM1CH0SRC_USB_START=3									// USB start of frame pulse
};

#define mSIM_SOPT4_TPM1CH0SRC(X) ((X & 3) << 18)				// TPM1 channel 0 input capture source select

enum{
	mSIM_SOPT4_TPM2CH0SRC = 0x00100000U, 						// TPM2 Channel 0 Input Capture Source Select
	mSIM_SOPT4_TPM0CLKSEL = 0x01000000U, 						// TPM0 External Clock Pin Select
	mSIM_SOPT4_TPM1CLKSEL = 0x02000000U, 						// TPM1 External Clock Pin Select
	mSIM_SOPT4_TPM2CLKSEL = 0x04000000U							// TPM2 External Clock Pin Select
};

typedef union{
	uint32_t WORD;
	struct{
		uint32_t				: 18;							//
		uint32_t TPM1CH0SRC		: 2;							// TPM1 channel 0 input capture source select
		uint32_t TPM2CH0SRC		: 1;							// TPM2 Channel 0 Input Capture Source Select
		uint32_t 				: 3;							//
		uint32_t TPM0CLKSEL		: 1;							// TPM0 External Clock Pin Select
		uint32_t TPM1CLKSEL		: 1;							// TPM1 External Clock Pin Select
		uint32_t TPM2CLKSEL		: 1;							// TPM2 External Clock Pin Select
		uint32_t 				: 5;							//
	}BITS;
}__sim_sopt4_t;


enum{
	kSIM_LPUART1TXSRC_LPUART1_TX=0,								// LPUART1_TX pin
	kSIM_LPUART1TXSRC_LPUART1_TX_TPM1CH0=1,						// LPUART1_TX pin modulated with TPM1 channel 0 output
	kSIM_LPUART1TXSRC_LPUART1_TX_TPM2CH0=2						// LPUART1_TX pin modulated with TPM2 channel 0 output
};

enum{
	kSIM_LPUART0TXSRC_LPUART0_TX=0,								// LPUART0_TX pin
	kSIM_LPUART0TXSRC_LPUART0_TX_TPM1CH0=1,						// LPUART0_TX pin modulated with TPM1 channel 0 output
	kSIM_LPUART0TXSRC_LPUART0_TX_TPM2CH0=2						// LPUART0_TX pin modulated with TPM2 channel 0 output
};

#define mSIM_SOPT5_LPUART0TXSRC(X) (X & 3) 						// LPUART0 Transmit Data Source Select
#define mSIM_SOPT5_LPUART1TXSRC(X) ((X & 3) << 4)				// LPUART1 Transmit Data Source Select

enum{
	mSIM_SOPT5_LPUART0RXSRC = 0x00000004U, 						// LPUART0 Receive Data Source Select
	mSIM_SOPT5_LPUART1RXSRC = 0x00000040U, 						// LPUART1 Receive Data Source Select
	mSIM_SOPT5_LPUART0ODE = 0x00010000U, 						// LPUART0 Open Drain Enable
	mSIM_SOPT5_LPUART1ODE = 0x00020000U, 						// LPUART1 Open Drain Enable
	mSIM_SOPT5_UART2ODE = 0x00040000U 							// UART2 Open Drain Enable
};

typedef union{
	uint32_t WORD;
	struct{
		uint32_t LPUART0TXSRC	: 2;							// LPUART0 Transmit Data Source Select
		uint32_t LPUART0RXSRC	: 1;							// LPUART0 Receive Data Source Select
		uint32_t 				: 1;							// Reserved
		uint32_t LPUART1TXSRC	: 2;							// LPUART1 Transmit Data Source Select
		uint32_t LPUART1RXSRC	: 1;							// LPUART1 Receive Data Source Select
		uint32_t 				: 9;							// Reserved
		uint32_t LPUART0ODE		: 1;							// LPUART0 Open Drain Enable
		uint32_t LPUART1ODE		: 1;							// LPUART1 Open Drain Enable
		uint32_t UART2ODE		: 1;							// UART2 Open Drain Enable
		uint32_t 				: 13;							// Reserved
	}BITS;
}__sim_sopt5_t;

enum {
	kSIM_ADC0TRGSEL_EXTRG_IN=0,									// External trigger pin input (EXTRG_IN)
	kSIM_ADC0TRGSEL_CMP0=1,										// CMP0 output
	kSIM_ADC0TRGSEL_PIT_CH0=4,									// PIT trigger 0
	kSIM_ADC0TRGSEL_PIT_CH1=5,									// PIT trigger 1
	kSIM_ADC0TRGSEL_TPM0_OVF=8,									// TPM0 overflow
	kSIM_ADC0TRGSEL_TPM1_OVF=9,									// TPM1 overflow
	kSIM_ADC0TRGSEL_TPM2_OVF=10,								// TPM2 overflow
	kSIM_ADC0TRGSEL_RTC_ALARM=12,								// RTC alarm
	kSIM_ADC0TRGSEL_RTC_SECONDS=13,								// RTC seconds
	kSIM_ADC0TRGSEL_LPTMR0=14									// LPTMR0 trigger
};

#define mSIM_SOPT7_ADC0TRGSEL(X) (X & 0x0000000FU)				// ADC0 Trigger Select

enum{
	mSIM_SOPT7_ADC0PRETRGSEL = 0x00000010,						// ADC0 Pretrigger Select
	mSIM_SOPT7_ADC0ALTTRGEN = 0x00000080						// ADC0 Alternate Trigger Enable
};

typedef union{
	uint32_t WORD;
	struct{
		uint32_t ADC0TRGSEL		: 4;							// ADC0 Trigger Select
		uint32_t ADC0PRETRGSEL	: 1;							// ADC0 Pretrigger Select
		uint32_t 				: 2;							// Reserved
		uint32_t ADC0ALTTRGEN	: 1;							// ADC0 Alternate Trigger Enable
		uint32_t 				: 24;							// Reserved
	}BITS;
}__sim_sopt7_t;

typedef union{
	uint32_t WORD;
	struct{
		uint32_t PINID			: 4;							// Pincount Identification
		uint32_t 				: 8;							// Reserved
		uint32_t REVID			: 4;							// Device Revision Number
		uint32_t SRAMSIZE		: 4;							// System SRAM Size
		uint32_t SERIESID		: 4;							// Kinetis Series ID
		uint32_t SUBFAMID		: 4;							// Kinetis Sub-Family ID
		uint32_t FAMID			: 4;							// Family ID
	}BITS;
}__sim_sdid_t;

enum {
	mSIM_SCGC4_I2C0_CG = 0x00000040, 							// I2C0 Clock Gate Control
	mSIM_SCGC4_I2C1_CG = 0x00000080, 							// I2C1 Clock Gate Control
	mSIM_SCGC4_UART2_CG = 0x00001000, 							// UART2 Clock Gate Control
	mSIM_SCGC4_USBFS_CG = 0x00040000, 							// USB Clock Gate Control
	mSIM_SCGC4_CMP0_CG = 0x00080000, 							// Comparator Clock Gate Control
	mSIM_SCGC4_VREF_CG = 0x00100000, 							// VREF Clock Gate Control
	mSIM_SCGC4_SPI0_CG = 0x00400000, 							// SPI0 Clock Gate Control
	mSIM_SCGC4_SPI1_CG = 0x00800000, 							// SPI1 Clock Gate Control
};
typedef union{
	uint32_t WORD;
	struct{
		uint32_t				: 6;							// Reserved
		uint32_t I2C0_CG		: 1;							// I2C0 Clock Gate Control
		uint32_t I2C1_CG		: 1;							// I2C1 Clock Gate Control
		uint32_t 				: 4;							// Reserved
		uint32_t UART2_CG		: 1;							// UART2 Clock Gate Control
		uint32_t 				: 5;							// Reserved
		uint32_t USBFS_CG		: 1;							// USB Clock Gate Control
		uint32_t CMP0_CG		: 1;							// Comparator Clock Gate Control
		uint32_t VREF_CG		: 1;							// VREF Clock Gate Control
		uint32_t 				: 1;							// Reserved
		uint32_t SPI0_CG		: 1;							// SPI0 Clock Gate Control
		uint32_t SPI1_CG		: 1;							// SPI1 Clock Gate Control
		uint32_t 				: 8;							// Reserved
	}BITS;
}__sim_scgc4_t;

enum{
	mSIM_SCGC5_LPTMR_CG = 0x00000001, 							// Low Power Timer Access Control
	mSIM_SCGC5_PORTA_CG = 0x00000200, 							// Port A Clock Gate Control
	mSIM_SCGC5_PORTB_CG = 0x00000400, 							// Port B Clock Gate Control
	mSIM_SCGC5_PORTC_CG = 0x00000800, 							// Port C Clock Gate Control
	mSIM_SCGC5_PORTD_CG = 0x00001000, 							// Port D Clock Gate Control
	mSIM_SCGC5_PORTE_CG = 0x00002000, 							// Port E Clock Gate Control
	mSIM_SCGC5_LPUART0_CG = 0x00100000, 						// LPUART0 Clock Gate Control
	mSIM_SCGC5_LPUART1_CG = 0x00200000, 						// LPUART1 Clock Gate Control
	mSIM_SCGC5_FLEXIO_CG = 0x80000000, 							// FlexIO Module Gate Control
};

typedef union{
	uint32_t WORD;
	struct{
		uint32_t LPTMR_CG		: 1;							// Low Power Timer Access Control
		uint32_t 				: 8;							// Reserved
		uint32_t PORTA_CG		: 1;							// Port A Clock Gate Control
		uint32_t PORTB_CG		: 1;							// Port B Clock Gate Control
		uint32_t PORTC_CG		: 1;							// Port C Clock Gate Control
		uint32_t PORTD_CG		: 1;							// Port D Clock Gate Control
		uint32_t PORTE_CG		: 1;							// Port E Clock Gate Control
		uint32_t 				: 6;							// Reserved
		uint32_t LPUART0_CG		: 1;							// LPUART0 Clock Gate Control
		uint32_t LPUART1_CG		: 1;							// LPUART1 Clock Gate Control
		uint32_t 				: 9;							// Reserved
		uint32_t FLEXIO_CG		: 1;							// FlexIO Module Gate Control
	}BITS;
}__sim_scgc5_t;

enum {
	mSIM_SCGC6_FTF_CG = 0x00000001,								// Flash Memory Clock Gate Control
	mSIM_SCGC6_DMAMUX_CG = 0x00000002,							// DMA Mux Clock Gate Control
	mSIM_SCGC6_CRC_CG = 0x00040000,								// CRC Clock Gate Control
	mSIM_SCGC6_PIT_CG = 0x00800000,								// PIT Clock Gate Control
	mSIM_SCGC6_TPM0_CG = 0x01000000,							// TPM0 Clock Gate Control
	mSIM_SCGC6_TPM1_CG = 0x02000000,							// TPM1 Clock Gate Control
	mSIM_SCGC6_TPM2_CG = 0x04000000,							// TPM2 Clock Gate Control
	mSIM_SCGC6_ADC0_CG = 0x08000000,							// ADC0 Clock Gate Control
	mSIM_SCGC6_RTC_CG = 0x20000000,								// RTC Access Control
};

typedef union{
	uint32_t WORD;
	struct{
		uint32_t FTF_CG			: 1;							// Flash Memory Clock Gate Control
		uint32_t DMAMUX_CG		: 1;							// DMA Mux Clock Gate Control
		uint32_t 				: 16;							// Reserved
		uint32_t CRC_CG			: 1;							// CRC Clock Gate Control
		uint32_t 				: 4;							// Reserved
		uint32_t PIT_CG			: 1;							// PIT Clock Gate Control
		uint32_t TPM0_CG		: 1;							// TPM0 Clock Gate Control
		uint32_t TPM1_CG		: 1;							// TPM1 Clock Gate Control
		uint32_t TPM2_CG		: 1;							// TPM2 Clock Gate Control
		uint32_t ADC0_CG		: 1;							// ADC0 Clock Gate Control
		uint32_t 				: 1;							// Reserved
		uint32_t RTC_CG			: 1;							// RTC Access Control
		uint32_t 				: 2;							// Reserved
	}BITS;
}__sim_scgc6_t;

enum {
	mSIM_SCGC7_DMA = 0x00000100									// DMA Clock Gate Control
};
typedef union{
	uint32_t WORD;
	struct{
		uint32_t				: 8;							// Reserved
		uint32_t DMA			: 1;							// DMA Clock Gate Control
		uint32_t 				: 23;							// Reserved
	}BITS;
}__sim_scgc7_t;

enum {
	kSIM_OUTDIV1_BY_1=0,
	kSIM_OUTDIV1_BY_2=1,
	kSIM_OUTDIV1_BY_3=2,
	kSIM_OUTDIV1_BY_4=3,
	kSIM_OUTDIV1_BY_5=4,
	kSIM_OUTDIV1_BY_6=5,
	kSIM_OUTDIV1_BY_7=6,
	kSIM_OUTDIV1_BY_8=7,
	kSIM_OUTDIV1_BY_9=8,
	kSIM_OUTDIV1_BY_10=9,
	kSIM_OUTDIV1_BY_11=10,
	kSIM_OUTDIV1_BY_12=11,
	kSIM_OUTDIV1_BY_13=12,
	kSIM_OUTDIV1_BY_14=13,
	kSIM_OUTDIV1_BY_15=14,
	kSIM_OUTDIV1_BY_16=15,
};

enum {
	kSIM_OUTDIV4_BY_1=0,
	kSIM_OUTDIV4_BY_2=1,
	kSIM_OUTDIV4_BY_3=2,
	kSIM_OUTDIV4_BY_4=3,
	kSIM_OUTDIV4_BY_5=4,
	kSIM_OUTDIV4_BY_6=5,
	kSIM_OUTDIV4_BY_7=6,
	kSIM_OUTDIV4_BY_8=7
};

#define mSIM_CLKDIV1_OUTDIV4(X) ((X & 7) << 16)
#define mSIM_CLKDIV1_OUTDIV1(X) ((X & 15) << 28)

typedef union{
	uint32_t WORD;
	struct{
		uint32_t				: 16;							// Reserved
		uint32_t OUTDIV4		: 3;							// Clock 4 Output Divider value
		uint32_t 				: 9;							// Reserved
		uint32_t OUTDIV1		: 4;							// Clock 1 Output Divider value
	}BITS;
}__sim_clkdiv1_t;

enum{
	mSIM_FCFG1_FLASHDIS = 0x00000001,							// Flash Disable
	mSIM_FCFG1_FLASHDOZE = 0x00000002							// Flash Doze
};

typedef union{
	uint32_t WORD;
	struct{
		uint32_t FLASHDIS		: 1;							// Flash Disable
		uint32_t FLASHDOZE		: 1;							// Flash Doze
		uint32_t 				: 22;							//
		uint32_t PFSIZE			: 4;							// Program Flash Size
		uint32_t 				: 4;							//
	}BITS;
}__sim_fcfg1_t;

typedef union{
	uint32_t WORD;
	struct{
		uint32_t				: 24;							//
		uint32_t MAXADDR0		: 7;							// Max Address lock
		uint32_t 				: 1;							//
	}BITS;
}__sim_fcfg2_t;

typedef union{
	uint32_t WORD;
	struct{
		uint32_t UID			: 16;							// Unique Identification
		uint32_t 				: 16;							//
	}BITS;
}__sim_uidmh_t;

typedef union{
	uint32_t WORD;
	struct{
		uint32_t UID			: 32;							// Unique Identification
	}BITS;
}__sim_uidml_t;

typedef union{
	uint32_t WORD;
	struct{
		uint32_t UID			: 32;							// Unique Identification
	}BITS;
}__sim_uidl_t;

enum {
	kSIM_COPCLKSEL_LPO_CLK=0,									// LPO clock (1 kHz)
	kSIM_COPCLKSEL_MCGIRCLK=1,									// MCGIRCLK
	kSIM_COPCLKSEL_OSCERCLK=2,									// OSCERCLK
	kSIM_COPCLKSEL_BUS_CLK=3									// Bus clock
};

enum {
	kSIM_COPT_COP_DISABLED=0,									// COP disabled
	kSIM_COPT_COP_TIMEOUT_SHORT_2_5_LONG_2_13=1,				// COP timeout after 25 cycles for short timeout or 213 cycles for long timeout
	kSIM_COPT_COP_TIMEOUT_SHORT_2_8_LONG_2_16=2,				// COP timeout after 28 cycles for short timeout or 216 cycles for long timeout
	kSIM_COPT_COP_TIMEOUT_SHORT_2_10_LONG_2_18=3				// COP timeout after 210 cycles for short timeout or 218 cycles for long timeout
};

#define mSIM_COPC_COPT(X) ((X & 3) << 2)						// COP Watchdog Timeout
#define mSIM_COPC_COPCLKSEL(X) ((X & 3) << 6)					// COP Clock Select

enum{
	mSIM_COPC_ = 0x00000001U, 									// COP Windowed Mode
	mSIM_COPCLKS_ = 0x00000002U, 								// COP Clock Select
	mSIM_COPSTPEN_ = 0x00000010U, 								// COP Stop Enable
	mSIM_COPDBGENC_ = 0x00000020U, 								// COP Debug Enable
};

typedef union{
	uint32_t WORD;
	struct{
		uint32_t COPW			: 1;							// COP Windowed Mode
		uint32_t COPCLKS		: 1;							// COP Clock Select
		uint32_t COPT			: 2;							// COP Watchdog Timeout
		uint32_t COPSTPEN		: 1;							// COP Stop Enable
		uint32_t COPDBGEN		: 1;							// COP Debug Enable
		uint32_t COPCLKSEL		: 2;							// COP Clock Select
		uint32_t 			    : 24;							// Reserved
	}BITS;
}__sim_copc_t;

enum {
	kSIM_SRVCOP_WRITE_1ST=0x55,									// Write 0x55 and then 0xAA
	kSIM_SRVCOP_WRITE_2ND=0xAA									// to reset the COP timeout counter
};

typedef union{
	uint32_t WORD;
	struct{
		uint32_t SRVCOP			: 8;							// Service COP Register
		uint32_t 				: 24;							// Reserved
	}BITS;
}__sim_srvcop_t;

typedef struct{
	volatile __sim_sopt2_t SOPT2; 								// 0x8004 System Options Register 2 (SIM_SOPT2)
	volatile uint32_t RESERVED0;								// 0x8008 RESERVED
	volatile __sim_sopt4_t SOPT4; 								// 0x800C System Options Register 4 (SIM_SOPT4)
	volatile __sim_sopt5_t SOPT5; 								// 0x8010 System Options Register 5 (SIM_SOPT5)
	volatile uint32_t RESERVED1;								// 0x8014 RESERVED
	volatile __sim_sopt7_t SOPT7; 								// 0x8018 System Options Register 7 (SIM_SOPT7)
	volatile uint32_t RESERVED2[2];								// 0x801C and 0x8020 RESERVED
	volatile __sim_sdid_t SDID;  								// 0x8024 System Device Identification Register (SIM_SDID)
	volatile uint32_t RESERVED3[3];								// 0x8028 - 0x8030 RESERVED
	volatile __sim_scgc4_t SCGC4; 								// 0x8034 System Clock Gating Control Register 4 (SIM_SCGC4)
	volatile __sim_scgc5_t SCGC5; 								// 0x8038 System Clock Gating Control Register 5 (SIM_SCGC5)
	volatile __sim_scgc6_t SCGC6; 								// 0x803C System Clock Gating Control Register 6 (SIM_SCGC6)
	volatile __sim_scgc7_t SCGC7; 								// 0x8040 System Clock Gating Control Register 7 (SIM_SCGC7)
	volatile __sim_clkdiv1_t CLKDIV1; 							// 0x8044 System Clock Divider Register 1 (SIM_CLKDIV1)
	volatile uint32_t RESERVED4;								// 0x8048 RESERVED
	volatile __sim_fcfg1_t FCFG1; 								// 0x804C Flash Configuration Register 1 (SIM_FCFG1)
	volatile __sim_fcfg2_t FCFG2; 								// 0x8050 Flash Configuration Register 2 (SIM_FCFG2)
	volatile uint32_t RESERVED5;								// 0x8054 RESERVED
	volatile __sim_uidmh_t UIDMH; 								// 0x8058 Unique Identification Register Mid-High (SIM_UIDMH)
	volatile __sim_uidml_t UIDML; 								// 0x805C Unique Identification Register Mid Low (SIM_UIDML)
	volatile __sim_uidl_t UIDL;  								// 0x8060Unique Identification Register Low (SIM_UIDL)
	volatile uint32_t RESERVED6[40];							// 0x8064 - 0x80FC RESERVED
	volatile __sim_copc_t COPC; 								// 0x8100 COP Control Register (SIM_COPC)
	volatile __sim_srvcop_t SRVCOP; 							// 0x8104 Service COP (SIM_SRVCOP)
} __sim2_t;

#define sSIM2 (*((__sim2_t *)(0x40048004)))						// SIM General Structure 2

#define rSIM_SOPT2 sSIM2.SIM_SOPT2.WORD							// System Options Register 2
#define bSIM_RTCCLKOUTSEL sSIM2.SOPT2.BITS.RTCCLKOUTSEL			// RTC Clock Out Select
#define bSIM_CLKOUTSEL sSIM2.SOPT2.BITS.CLKOUTSEL				// CLKOUT select
#define bSIM_USBSRC sSIM2.SOPT2.BITS.USBSRC						// USB clock source select
#define bSIM_FLEXIOSRC sSIM2.SOPT2.BITS.FLEXIOSRC				// FlexIO Module Clock Source Select
#define bSIM_TPMSRC sSIM2.SOPT2.BITS.TPMSRC						// TPM Clock Source Select
#define bSIM_LPUART0SRC sSIM2.SOPT2.BITS.LPUART0SRC				// LPUART0 Clock Source Select
#define bSIM_LPUART1SRC sSIM2.SOPT2.BITS.LPUART1SRC				// LPUART1 Clock Source Select

#define rSIM_SOPT4 sSIM2.SOPT4.WORD								// System Options Register 4
#define bSIM_TPM1CH0SRC sSIM2.SOPT4.BITS.TPM1CH0SRC				// TPM1 Channel 0 Input Capture Source Select
#define bSIM_TPM2CH0SRC sSIM2.SOPT4.BITS.TPM2CH0SRC				// TPM2 Channel 0 Input Capture Source Select
#define bSIM_TPM0CLKSEL sSIM2.SOPT4.BITS.TPM0CLKSEL				// TPM0 External Clock Pin Select
#define bSIM_TPM1CLKSEL sSIM2.SOPT4.BITS.TPM1CLKSEL				// TPM1 External Clock Pin Select
#define bSIM_TPM2CLKSEL sSIM2.SOPT4.BITS.TPM2CLKSEL				// TPM2 External Clock Pin Select

#define rSIM_SOPT5 sSIM2.SOPT5.WORD								// System Options Register 5
#define bSIM_LPUART0TXSRC sSIM2.SOPT5.BITS.LPUART0TXSRC			// LPUART0 Transmit Data Source Select
#define bSIM_LPUART0RXSRC sSIM2.SOPT5.BITS.LPUART0RXSRC			// LPUART0 Receive Data Source Select
#define bSIM_LPUART1TXSRC sSIM2.SOPT5.BITS.LPUART1TXSRC			// LPUART1 Transmit Data Source Select
#define bSIM_LPUART1RXSRC sSIM2.SOPT5.BITS.LPUART1RXSRC			// LPUART1 Receive Data Source Select
#define bSIM_LPUART0ODE sSIM2.SOPT5.BITS.LPUART0ODE				// LPUART0 Open Drain Enable
#define bSIM_LPUART1ODE sSIM2.SOPT5.BITS.LPUART1ODE				// LPUART1 Open Drain Enable
#define bSIM_UART2ODE sSIM2.SOPT5.BITS.UART2ODE					// UART2 Open Drain Enable

#define rSIM_SOPT7 sSIM2.SOPT7.WORD								// System Options Register 7
#define bSIM_ADC0TRGSEL sSIM2.SOPT7.BITS.ADC0TRGSEL				// ADC0 Trigger Select
#define bSIM_ADC0PRETRGSEL sSIM2.SOPT7.BITS.ADC0PRETRGSEL		// ADC0 Pretrigger Select
#define bSIM_ADC0ALTTRGEN sSIM2.SOPT7.BITS.ADC0ALTTRGEN			// ADC0 Alternate Trigger Enable

#define rSIM_SDID sSIM2.SDID.WORD								// System Device Identification Register
#define bSIM_PINID sSIM2.SDID.BITS.PINID						// Pincount Identification
#define bSIM_REVID sSIM2.SDID.BITS.REVID						// Device Revision Number
#define bSIM_SRAMSIZE sSIM2.SDID.BITS.SRAMSIZE					// System SRAM Size
#define bSIM_SERIESID sSIM2.SDID.BITS.SERIESID					// Kinetis Series ID
#define bSIM_SUBFAMID sSIM2.SDID.BITS.SUBFAMID					// Kinetis Sub-Family ID
#define bSIM_FAMID sSIM2.SDID.BITS.FAMID						// Family ID

#define rSIM_SCGC4 sSIM2.SCGC4.WORD								// System Clock Gating Control Register 4
#define bSIM_CG_I2C0 sSIM2.SCGC4.BITS.I2C0_CG					// I2C0 Clock Gate Control
#define bSIM_CG_I2C1 sSIM2.SCGC4.BITS.I2C1_CG					// I2C1 Clock Gate Control
#define bSIM_CG_UART2 sSIM2.SCGC4.BITS.UART2_CG					// UART2 Clock Gate Control
#define bSIM_CG_USBFS sSIM2.SCGC4.BITS.USBFS_CG					// USB Clock Gate Control
#define bSIM_CG_CMP0 sSIM2.SCGC4.BITS.CMP0_CG					// Comparator Clock Gate Control
#define bSIM_CG_VREF sSIM2.SCGC4.BITS.VREF_CG					// VREF Clock Gate Control
#define bSIM_CG_SPI0 sSIM2.SCGC4.BITS.SPI0_CG					// SPI0 Clock Gate Control
#define bSIM_CG_SPI1 sSIM2.SCGC4.BITS.SPI1_CG					// SPI1 Clock Gate Control

#define rSIM_SCGC5 sSIM2.SCGC5.WORD								// System Clock Gating Control Register 5
#define bSIM_CG_LPTMR sSIM2.SCGC5.BITS.LPTMR_CG					// Low Power Timer Access Control
#define bSIM_CG_PORTA sSIM2.SCGC5.BITS.PORTA_CG					// Port A Clock Gate Control
#define bSIM_CG_PORTB sSIM2.SCGC5.BITS.PORTB_CG					// Port B Clock Gate Control
#define bSIM_CG_PORTC sSIM2.SCGC5.BITS.PORTC_CG					// Port C Clock Gate Control
#define bSIM_CG_PORTD sSIM2.SCGC5.BITS.PORTD_CG					// Port D Clock Gate Control
#define bSIM_CG_PORTE sSIM2.SCGC5.BITS.PORTE_CG					// Port E Clock Gate Control
#define bSIM_CG_LPUART0 sSIM2.SCGC5.BITS.LPUART0_CG				// LPUART0 Clock Gate Control
#define bSIM_CG_LPUART1 sSIM2.SCGC5.BITS.LPUART1_CG				// LPUART1 Clock Gate Control
#define bSIM_CG_FLEXIO sSIM2.SCGC5.BITS.FLEXIO_CG				// FlexIO Module Clock Gate Control

#define rSIM_SCGC6 sSIM2.SCGC6.WORD								// System Clock Gating Control Register 6
#define bSIM_CG_FTF sSIM2.SCGC6.BITS.FTF_CG						// Flash Memory Clock Gate Control
#define bSIM_CG_DMAMUX sSIM2.SCGC6.BITS.DMAMUX_CG				// DMA Mux Clock Gate Control
#define bSIM_CG_CRC sSIM2.SCGC6.BITS.CRC_CG						// I2S Clock Gate Control
#define bSIM_CG_PIT sSIM2.SCGC6.BITS.PIT_CG						// PIT Clock Gate Control
#define bSIM_CG_TPM0 sSIM2.SCGC6.BITS.TPM0_CG					// TPM0 Clock Gate Control
#define bSIM_CG_TPM1 sSIM2.SCGC6.BITS.TPM1_CG					// TPM1 Clock Gate Control
#define bSIM_CG_TPM2 sSIM2.SCGC6.BITS.TPM2_CG					// TPM2 Clock Gate Control
#define bSIM_CG_ADC0 sSIM2.SCGC6.BITS.ADC0_CG					// ADC0 Clock Gate Control
#define bSIM_CG_RTC sSIM2.SCGC6.BITS.RTC_CG						// RTC Access Control

#define rSIM_SCGC7 sSIM2.SCGC7.WORD								// System Clock Gating Control Register 7
#define bSIM_DMA sSIM2.SCGC7.BITS.DMA							// DMA Clock Gate Control

#define rSIM_CLKDIV1 sSIM2.CLKDIV1.WORD							// System Clock Divider Register 1
#define bSIM_OUTDIV4 sSIM2.CLKDIV1.BITS.OUTDIV4					// Clock 4 Output Divider value
#define bSIM_OUTDIV1 sSIM2.CLKDIV1.BITS.OUTDIV1					// Clock 1 Output Divider value

#define rSIM_FCFG1 sSIM2.FCFG1.WORD								// Flash Configuration Register 1
#define bSIM_FLASHDIS sSIM2.FCFG1.BITS.FLASHDIS					// Flash Disable
#define bSIM_FLASHDOZE sSIM2.FCFG1.BITS.FLASHDOZE				// Flash Doze
#define bSIM_PFSIZE sSIM2.FCFG1.BITS.PFSIZE						// Program Flash Size

#define rSIM_FCFG2 sSIM2.FCFG2.WORD								// Flash Configuration Register 2
#define bSIM_MAXADDR0 sSIM2.FCFG2.BITS.MAXADDR0					// Max Address lock 0

#define rSIM_UIDMH sSIM2.UIDMH.WORD								// Unique Identification Register Mid-High
//#define bSIM_ sSIM2..BITS.

#define rSIM_UIDML sSIM2.UIDML.WORD								// Unique Identification Register Mid Low
//#define bSIM_ sSIM2.UIDML.BITS.

#define rSIM_UIDL sSIM2.UIDL.WORD								// Unique Identification Register Low
//#define bSIM_ sSIM2.UIDL.BITS.

#define rSIM_COPC sSIM2.COPC.WORD								// COP Control Register
#define bSIM_COPW sSIM2.COPC.BITS.COPW							// COP Windowed Mode
#define bSIM_COPCLKS sSIM2.COPC.BITS.COPCLKS					// COP Clock Select
#define bSIM_COPT sSIM2.COPC.BITS.COPT							// COP Watchdog Timeout
#define bSIM_COPSTPEN sSIM2.COPC.BITS.COPSTPEN					// COP Stop Enable
#define bSIM_COPDBGEN sSIM2.COPC.BITS.COPDBGEN					// COP Debug Enable
#define bSIM_COPCLKSEL sSIM2.COPC.BITS.COPCLKSEL				// COP Clock Select

#define rSIM_SRVCOP sSIM2.SRVCOP.WORD							// Service COP
#define bSIM_SRVCOP sSIM2.SRVCOP.BITS.SRVCOP					// Service COP Register

//#define __SIM_ sSIM2..WORD
//#define __SIM_ sSIM2..BITS.

#endif /* SIM_LIB_H_ */
