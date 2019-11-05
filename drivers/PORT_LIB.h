/*
 * PORT_LIB.h
 *
 *  Created on: 7/09/2017
 *      Author: Ricardo Andrés Velásquez Vélez
 */

#ifndef PORT_LIB_H_
#define PORT_LIB_H_

typedef union {
	uint32_t WORD;		// Whole register access
	struct {
		uint32_t PS		:1;	  									// Pull Select
		uint32_t PE		:1;	  									// Pull Enable
		uint32_t SRE	:1;		  								// Slew Rate Enable
		uint32_t 		:1;	  									// reserved
		uint32_t PFE	:1;	  									// Passive Filter Enable
		uint32_t 		:1;	  									// reserved
		uint32_t DSE	:1;	  									// Driven Strength Enable
		uint32_t        :1;   									// reserved
		uint32_t MUX	:3;   									// Pin Mux Control
		uint32_t        :5;   									// reserved
		uint32_t IRQC   :4;   									// Interrupt configuration
		uint32_t        :4;   									// reserved
		uint32_t ISF    :1;   									// Interrupt Status Flag
		uint32_t        :7;   									// reserved
	} BITS;
} __port_pcr_t;

typedef union {
	uint32_t WORD;		    								// Whole register access
	struct {
		uint32_t GPWD		  :16;	    						// Global Pin Write Data
		uint32_t GPWE		  :16;	    						// Global Pin Write Enable
	} Short;
	struct {
		uint32_t BIT0_DATA  :1;	        						// Global Pin BIT0 Write Data
		uint32_t BIT1_DATA  :1;	        						// Global Pin BIT1 Write Data
		uint32_t BIT2_DATA  :1;	        						// Global Pin BIT2 Write Data
		uint32_t BIT3_DATA  :1;	        						// Global Pin BIT3 Write Data
		uint32_t BIT4_DATA  :1;	        						// Global Pin BIT4 Write Data
		uint32_t BIT5_DATA  :1;	        						// Global Pin BIT5 Write Data
		uint32_t BIT6_DATA  :1;	        						// Global Pin BIT5 Write Data
		uint32_t BIT7_DATA  :1;	        						// Global Pin BIT5 Write Data
		uint32_t BIT8_DATA  :1;	        						// Global Pin BIT5 Write Data
		uint32_t BIT9_DATA  :1;	        						// Global Pin BIT5 Write Data
		uint32_t BIT10_DATA :1;	        						// Global Pin BIT5 Write Data
		uint32_t BIT11_DATA :1;	        						// Global Pin BIT5 Write Data
		uint32_t BIT12_DATA :1;	        						// Global Pin BIT12 Write Data
		uint32_t BIT13_DATA :1;	        						// Global Pin BIT13 Write Data
		uint32_t BIT14_DATA :1;	        						// Global Pin BIT14 Write Data
		uint32_t BIT15_DATA :1;	        						// Global Pin BIT15 Write Data
		uint32_t BIT0_WE    :1;	        						// Global Pin BIT0 Write Enable
		uint32_t BIT1_WE    :1;	        						// Global Pin BIT1 Write Enable
		uint32_t BIT2_WE    :1;	        						// Global Pin BIT2 Write Enable
		uint32_t BIT3_WE    :1;	        						// Global Pin BIT3 Write Enable
		uint32_t BIT4_WE    :1;	        						// Global Pin BIT4 Write Enable
		uint32_t BIT5_WE    :1;	        						// Global Pin BIT5 Write Enable
		uint32_t BIT6_WE    :1;	        						// Global Pin BIT5 Write Enable
		uint32_t BIT7_WE    :1;	        						// Global Pin BIT5 Write Enable
		uint32_t BIT8_WE    :1;	        						// Global Pin BIT5 Write Enable
		uint32_t BIT9_WE    :1;	        						// Global Pin BIT5 Write Enable
		uint32_t BIT10_WE   :1;	        						// Global Pin BIT5 Write Enable
		uint32_t BIT11_WE   :1;	        						// Global Pin BIT5 Write Enable
		uint32_t BIT12_WE   :1;	        						// Global Pin BIT12 Write Enable
		uint32_t BIT13_WE   :1;	        						// Global Pin BIT13 Write Enable
		uint32_t BIT14_WE   :1;	        						// Global Pin BIT14 Write Enable
		uint32_t BIT15_WE   :1;	        						// Global Pin BIT15 Write Enable
	} BITS;
} __port_gpclr_t;

typedef union {
	uint32_t WORD;		                						// Whole register access
	struct {
		uint32_t GPWD		  :16;	    						// Global Pin Write Data
		uint32_t GPWE		  :16;	    						// Global Pin Write Enable
	} SHORT;
	struct {
		uint32_t BIT16_DATA :1;	    							// Global Pin BIT16 Write Data
		uint32_t BIT17_DATA :1;	    							// Global Pin BIT17 Write Data
		uint32_t BIT18_DATA :1;	    							// Global Pin BIT18 Write Data
		uint32_t BIT19_DATA :1;	    							// Global Pin BIT19 Write Data
		uint32_t BIT20_DATA :1;	    							// Global Pin BIT20 Write Data
		uint32_t BIT21_DATA :1;	    							// Global Pin BIT21 Write Data
		uint32_t BIT22_DATA :1;	    							// Global Pin BIT22 Write Data
		uint32_t BIT23_DATA :1;	    							// Global Pin BIT23 Write Data
		uint32_t BIT24_DATA :1;	    							// Global Pin BIT24 Write Data
		uint32_t BIT25_DATA :1;	    							// Global Pin BIT25 Write Data
		uint32_t BIT26_DATA :1;	    							// Global Pin BIT26 Write Data
		uint32_t BIT27_DATA :1;	    							// Global Pin BIT27 Write Data
		uint32_t BIT28_DATA :1;	    							// Global Pin BIT28 Write Data
		uint32_t BIT29_DATA :1;	    							// Global Pin BIT29 Write Data
		uint32_t BIT30_DATA :1;	    							// Global Pin BIT30 Write Data
		uint32_t BIT31_DATA :1;	    							// Global Pin BIT31 Write Data
		uint32_t BIT16_WE   :1;	    							// Global Pin BIT16 Write Enable
		uint32_t BIT17_WE   :1;	    							// Global Pin BIT17 Write Enable
		uint32_t BIT18_WE   :1;	    							// Global Pin BIT18 Write Enable
		uint32_t BIT19_WE   :1;	    							// Global Pin BIT19 Write Enable
		uint32_t BIT20_WE   :1;	    							// Global Pin BIT20 Write Enable
		uint32_t BIT21_WE   :1;	    							// Global Pin BIT21 Write Enable
		uint32_t BIT22_WE   :1;	    							// Global Pin BIT22 Write Enable
		uint32_t BIT23_WE   :1;	    							// Global Pin BIT23 Write Enable
		uint32_t BIT24_WE   :1;	    							// Global Pin BIT24 Write Enable
		uint32_t BIT25_WE   :1;	    							// Global Pin BIT25 Write Enable
		uint32_t BIT26_WE   :1;	    							// Global Pin BIT26 Write Enable
		uint32_t BIT27_WE   :1;	    							// Global Pin BIT27 Write Enable
		uint32_t BIT28_WE   :1;	    							// Global Pin BIT28 Write Enable
		uint32_t BIT29_WE   :1;	    							// Global Pin BIT29 Write Enable
		uint32_t BIT30_WE   :1;	    							// Global Pin BIT30 Write Enable
		uint32_t BIT31_WE   :1;	    							// Global Pin BIT31 Write Enable
	} BITS;
} __port_gpchr_t;

typedef union {
	uint32_t WORD;
	struct {
		uint32_t BIT0_ISR  :1;									// Pin BIT0 Interrupt Status Flag
		uint32_t BIT1_ISR  :1;									// Pin BIT1 Interrupt Status Flag
		uint32_t BIT2_ISR  :1;									// Pin BIT2 Interrupt Status Flag
		uint32_t BIT3_ISR  :1;									// Pin BIT3 Interrupt Status Flag
		uint32_t BIT4_ISR  :1;									// Pin BIT4 Interrupt Status Flag
		uint32_t BIT5_ISR  :1;									// Pin BIT5 Interrupt Status Flag
		uint32_t BIT6_ISR  :1;									// Pin BIT6 Interrupt Status Flag
		uint32_t BIT7_ISR  :1;									// Pin BIT7 Interrupt Status Flag
		uint32_t BIT8_ISR  :1;									// Pin BIT8 Interrupt Status Flag
		uint32_t BIT9_ISR  :1;									// Pin BIT9 Interrupt Status Flag
		uint32_t BIT10_ISR :1;									// Pin BIT10 Interrupt Status Flag
		uint32_t BIT11_ISR :1;									// Pin BIT11 Interrupt Status Flag
		uint32_t BIT12_ISR :1;									// Pin BIT12 Interrupt Status Flag
		uint32_t BIT13_ISR :1;									// Pin BIT13 Interrupt Status Flag
		uint32_t BIT14_ISR :1;									// Pin BIT14 Interrupt Status Flag
		uint32_t BIT15_ISR :1;									// Pin BIT15 Interrupt Status Flag
		uint32_t BIT16_ISR :1;	    							// Pin BIT16 Interrupt Status Flag
		uint32_t BIT17_ISR :1;	    							// Pin BIT17 Interrupt Status Flag
		uint32_t BIT18_ISR :1;	    							// Pin BIT18 Interrupt Status Flag
		uint32_t BIT19_ISR :1;	    							// Pin BIT19 Interrupt Status Flag
		uint32_t BIT20_ISR :1;	    							// Pin BIT20 Interrupt Status Flag
		uint32_t BIT21_ISR :1;	    							// Pin BIT21 Interrupt Status Flag
		uint32_t BIT22_ISR :1;	    							// Pin BIT22 Interrupt Status Flag
		uint32_t BIT23_ISR :1;	    							// Pin BIT23 Interrupt Status Flag
		uint32_t BIT24_ISR :1;	    							// Pin BIT24 Interrupt Status Flag
		uint32_t BIT25_ISR :1;	    							// Pin BIT25 Interrupt Status Flag
		uint32_t BIT26_ISR :1;	    							// Pin BIT26 Interrupt Status Flag
		uint32_t BIT27_ISR :1;	    							// Pin BIT27 Interrupt Status Flag
		uint32_t BIT28_ISR :1;	    							// Pin BIT28 Interrupt Status Flag
		uint32_t BIT29_ISR :1;	    							// Pin BIT29 Interrupt Status Flag
		uint32_t BIT30_ISR :1;	    							// Pin BIT30 Interrupt Status Flag
		uint32_t BIT31_ISR :1;	    							// Pin BIT31 Interrupt Status Flag
	} BITS;
}__port_isfr_t;

enum{
	kPORT_IRQC_DISABLED = 0x0000U,
	kPORT_IRQC_DMA_RISING_EDGE = 0x0001U,
	kPORT_IRQC_DMA_FALLING_EDGE = 0x0002U,
	kPORT_IRQC_DMA_EITHER_EDGE = 0x0003U,
	kPORT_IRQC_INTERRUPT_LOGIC_ZERO = 0x0008U,
	kPORT_IRQC_INTERRUPT_RISING_EDGE = 0x0009U,
	kPORT_IRQC_INTERRUPT_FALLING_EDGE = 0x000AU,
	kPORT_IRQC_INTERRUPT_EITHER_EDGE = 0x000BU,
	kPORT_IRQC_INTERRUPT_LOGIC_ONE = 0x000CU
};// __port_pcr_irq_t;

typedef struct{
	volatile __port_pcr_t PORT_PCR0; 							// 0X000
	volatile __port_pcr_t PORT_PCR1; 							// 0x004
	volatile __port_pcr_t PORT_PCR2; 							// 0x008
	volatile __port_pcr_t PORT_PCR3; 							// 0x00C
	volatile __port_pcr_t PORT_PCR4; 							// 0x010
	volatile __port_pcr_t PORT_PCR5; 							// 0x014
	volatile __port_pcr_t PORT_PCR6; 							// 0x018
	volatile __port_pcr_t PORT_PCR7; 							// 0x01C
	volatile __port_pcr_t PORT_PCR8; 							// 0x020
	volatile __port_pcr_t PORT_PCR9; 							// 0x024
	volatile __port_pcr_t PORT_PCR10; 							// 0x028
	volatile __port_pcr_t PORT_PCR11; 							// 0x02C
	volatile __port_pcr_t PORT_PCR12; 							// 0x030
	volatile __port_pcr_t PORT_PCR13; 							// 0x034
	volatile __port_pcr_t PORT_PCR14; 							// 0x038
	volatile __port_pcr_t PORT_PCR15; 							// 0x03C
	volatile __port_pcr_t PORT_PCR16; 							// 0x040
	volatile __port_pcr_t PORT_PCR17; 							// 0x044
	volatile __port_pcr_t PORT_PCR18; 							// 0x048
	volatile __port_pcr_t PORT_PCR19; 							// 0x04C
	volatile __port_pcr_t PORT_PCR20; 							// 0x050
	volatile __port_pcr_t PORT_PCR21; 							// 0x054
	volatile __port_pcr_t PORT_PCR22; 							// 0x058
	volatile __port_pcr_t PORT_PCR23; 							// 0x05C
	volatile __port_pcr_t PORT_PCR24; 							// 0x060
	volatile __port_pcr_t PORT_PCR25; 							// 0x064
	volatile __port_pcr_t PORT_PCR26; 							// 0x068
	volatile __port_pcr_t PORT_PCR27; 							// 0x06C
	volatile __port_pcr_t PORT_PCR28; 							// 0x070
	volatile __port_pcr_t PORT_PCR29; 							// 0x074
	volatile __port_pcr_t PORT_PCR30; 							// 0x078
	volatile __port_pcr_t PORT_PCR31; 							// 0x07C
	volatile __port_gpclr_t PORT_GPCLR; 						// 0x080
	volatile __port_gpchr_t PORT_GPCHR; 						// 0x084
	volatile    uint32_t RESERVED[6];							// 0x088 - 0x09C
	volatile __port_isfr_t PORT_ISFR;  						// 0x0A0
} __port_t;


////////////////////////////////////////////////////////////
// PORTA
///////////////////////////////////////////////////////////

#define sPORTA (*((__port_t *)(0x40049000)))					// PORTA global structure

#define rPTA_PCR0 sPORTA.PORT_PCR0.WORD
#define bPTA0_ISF sPORTA.PORT_PCR0.BITS.ISF					// Interrupt Status Flag
#define bPTA0_IRQC sPORTA.PORT_PCR0.BITS.IRQC					// Interrupt configuration
#define bPTA0_MUX sPORTA.PORT_PCR0.BITS.MUX					// Pin Mux Control
#define bPTA0_DSE sPORTA.PORT_PCR0.BITS.DSE					// Driven Strength Enable
#define bPTA0_PFE sPORTA.PORT_PCR0.BITS.PFE					// Passive Filter Enable
#define bPTA0_SRE sPORTA.PORT_PCR0.BITS.SRE					// Slew Rate Enable
#define bPTA0_PE sPORTA.PORT_PCR0.BITS.PE						// Pull Enable
#define bPTA0_PS sPORTA.PORT_PCR0.BITS.PS						// Pull Select

enum{
	kPTA0_MUX_GPIO = 1,
	kPTA0_MUX_TPM0_CH5 = 3,
	kPTA0_MUX_SWD_CLK = 7,
};// __porta_bit0_mux_t;

#define rPTA_PCR1 sPORTA.PORT_PCR1.WORD
#define bPTA1_ISF sPORTA.PORT_PCR1.BITS.ISF					// Interrupt Status Flag
#define bPTA1_IRQC sPORTA.PORT_PCR1.BITS.IRQC					// Interrupt configuration
#define bPTA1_MUX sPORTA.PORT_PCR1.BITS.MUX					// Pin Mux Control
#define bPTA1_DSE sPORTA.PORT_PCR1.BITS.DSE					// Driven Strength Enable
#define bPTA1_PFE sPORTA.PORT_PCR1.BITS.PFE					// Passive Filter Enable
#define bPTA1_SRE sPORTA.PORT_PCR1.BITS.SRE					// Slew Rate Enable
#define bPTA1_PE sPORTA.PORT_PCR1.BITS.PE						// Pull Enable
#define bPTA1_PS sPORTA.PORT_PCR1.BITS.PS						// Pull Select

 enum{
	kPTA1_MUX_GPIO = 1,
	kPTA1_MUX_LPUART0_RX = 2,
	kPTA1_MUX_TPM2_CH0 = 3
};// __porta_bit1_mux_t;

#define rPTA_PCR2 sPORTA.PORT_PCR2.WORD
#define bPTA2_ISF sPORTA.PORT_PCR2.BITS.ISF					// Interrupt Status Flag
#define bPTA2_IRQC sPORTA.PORT_PCR2.BITS.IRQC					// Interrupt configuration
#define bPTA2_MUX sPORTA.PORT_PCR2.BITS.MUX					// Pin Mux Control
#define bPTA2_DSE sPORTA.PORT_PCR2.BITS.DSE					// Driven Strength Enable
#define bPTA2_PFE sPORTA.PORT_PCR2.BITS.PFE					// Passive Filter Enable
#define bPTA2_SRE sPORTA.PORT_PCR2.BITS.SRE					// Slew Rate Enable
#define bPTA2_PE sPORTA.PORT_PCR2.BITS.PE						// Pull Enable
#define bPTA2_PS sPORTA.PORT_PCR2.BITS.PS						// Pull Select

enum{
	kPTA2_MUX_GPIO = 1,
	kPTA2_MUX_LPUART0_RX = 2,
	kPTA2_MUX_TPM2_CH0 = 3
};// __porta_bit2_mux_t;

#define rPTA_PCR3 sPORTA.PORT_PCR3.WORD
#define bPTA3_ISF sPORTA.PORT_PCR3.BITS.ISF					// Interrupt Status Flag
#define bPTA3_IRQC sPORTA.PORT_PCR3.BITS.IRQC					// Interrupt configuration
#define bPTA3_MUX sPORTA.PORT_PCR3.BITS.MUX					// Pin Mux Control
#define bPTA3_DSE sPORTA.PORT_PCR3.BITS.DSE					// Driven Strength Enable
#define bPTA3_PFE sPORTA.PORT_PCR3.BITS.PFE					// Passive Filter Enable
#define bPTA3_SRE sPORTA.PORT_PCR3.BITS.SRE					// Slew Rate Enable
#define bPTA3_PE sPORTA.PORT_PCR3.BITS.PE						// Pull Enable
#define bPTA3_PS sPORTA.PORT_PCR3.BITS.PS						// Pull Select

enum{
	kPTA3_MUX_GPIO = 1,
	kPTA3_MUX_I2C1_SCL = 2,
	kPTA3_MUX_TPM0_CH0 = 3,
	kPTA3_MUX_SWD_DIO = 7
};// __porta_bit3_mux_t;

#define rPTA_PCR4 sPORTA.PORT_PCR4.WORD
#define bPTA4_ISF sPORTA.PORT_PCR4.BITS.ISF					// Interrupt Status Flag
#define bPTA4_IRQC sPORTA.PORT_PCR4.BITS.IRQC					// Interrupt configuration
#define bPTA4_MUX sPORTA.PORT_PCR4.BITS.MUX					// Pin Mux Control
#define bPTA4_DSE sPORTA.PORT_PCR4.BITS.DSE					// Driven Strength Enable
#define bPTA4_PFE sPORTA.PORT_PCR4.BITS.PFE					// Passive Filter Enable
#define bPTA4_SRE sPORTA.PORT_PCR4.BITS.SRE					// Slew Rate Enable
#define bPTA4_PE sPORTA.PORT_PCR4.BITS.PE						// Pull Enable
#define bPTA4_PS sPORTA.PORT_PCR4.BITS.PS						// Pull Select

enum{
	kPTA4_MUX_GPIO = 1,
	kPTA4_MUX_I2C1_SDA = 2,
	kPTA4_MUX_TPM0_CH1 = 3,
	kPTA4_MUX_NMI_b = 7
};// __porta_bit4_mux_t;

#define rPTA_PCR5 sPORTA.PORT_PCR5.WORD
#define bPTA5_ISF sPORTA.PORT_PCR5.BITS.ISF					// Interrupt Status Flag
#define bPTA5_IRQC sPORTA.PORT_PCR5.BITS.IRQC					// Interrupt configuration
#define bPTA5_MUX sPORTA.PORT_PCR5.BITS.MUX					// Pin Mux Control
#define bPTA5_DSE sPORTA.PORT_PCR5.BITS.DSE					// Driven Strength Enable
#define bPTA5_PFE sPORTA.PORT_PCR5.BITS.PFE					// Passive Filter Enable
#define bPTA5_SRE sPORTA.PORT_PCR5.BITS.SRE					// Slew Rate Enable
#define bPTA5_PE sPORTA.PORT_PCR5.BITS.PE						// Pull Enable
#define bPTA5_PS sPORTA.PORT_PCR5.BITS.PS						// Pull Select

enum{
	kPTA5_MUX_GPIO = 1,
	kPTA5_MUX_USB_CLKIN = 2,
	kPTA5_MUX_TPM0_CH2 = 3
};// __porta_bit5_mux_t;

#define rPTA_PCR12 sPORTA.PORT_PCR12.WORD
#define bPTA12_ISF sPORTA.PORT_PCR12.BITS.ISF					// Interrupt Status Flag
#define bPTA12_IRQC sPORTA.PORT_PCR12.BITS.IRQC				// Interrupt configuration
#define bPTA12_MUX sPORTA.PORT_PCR12.BITS.MUX					// Pin Mux Control
#define bPTA12_DSE sPORTA.PORT_PCR12.BITS.DSE					// Driven Strength Enable
#define bPTA12_PFE sPORTA.PORT_PCR12.BITS.PFE					// Passive Filter Enable
#define bPTA12_SRE sPORTA.PORT_PCR12.BITS.SRE					// Slew Rate Enable
#define bPTA12_PE sPORTA.PORT_PCR12.BITS.PE					// Pull Enable
#define bPTA12_PS sPORTA.PORT_PCR12.BITS.PS					// Pull Select

enum{
	kPTA12_MUX_GPIO = 1,
	kPTA12_MUX_TPM1_CH0 = 3
};// __porta_bit12_mux_t;

#define rPTA_PCR13 sPORTA.PORT_PCR13.WORD
#define bPTA13_ISF sPORTA.PORT_PCR13.BITS.ISF					// Interrupt Status Flag
#define bPTA13_IRQC sPORTA.PORT_PCR13.BITS.IRQC				// Interrupt configuration
#define bPTA13_MUX sPORTA.PORT_PCR13.BITS.MUX					// Pin Mux Control
#define bPTA13_DSE sPORTA.PORT_PCR13.BITS.DSE					// Driven Strength Enable
#define bPTA13_PFE sPORTA.PORT_PCR13.BITS.PFE					// Passive Filter Enable
#define bPTA13_SRE sPORTA.PORT_PCR13.BITS.SRE					// Slew Rate Enable
#define bPTA13_PE sPORTA.PORT_PCR13.BITS.PE					// Pull Enable
#define bPTA13_PS sPORTA.PORT_PCR13.BITS.PS					// Pull Select

enum{
	kPTA13_MUX_GPIO = 1,
	kPTA13_MUX_TPM1_CH1 = 3
};// __porta_bit13_mux_t;

#define rPTA_PCR18 sPORTA.PORT_PCR18.WORD
#define bPTA18_ISF sPORTA.PORT_PCR18.BITS.ISF					// Interrupt Status Flag
#define bPTA18_IRQC sPORTA.PORT_PCR18.BITS.IRQC				// Interrupt configuration
#define bPTA18_MUX sPORTA.PORT_PCR18.BITS.MUX					// Pin Mux Control
#define bPTA18_DSE sPORTA.PORT_PCR18.BITS.DSE					// Driven Strength Enable
#define bPTA18_PFE sPORTA.PORT_PCR18.BITS.PFE					// Passive Filter Enable
#define bPTA18_SRE sPORTA.PORT_PCR18.BITS.SRE					// Slew Rate Enable
#define bPTA18_PE sPORTA.PORT_PCR18.BITS.PE					// Pull Enable
#define bPTA18_PS sPORTA.PORT_PCR18.BITS.PS					// Pull Select

enum{
	kPTA18_MUX_EXTAL0 = 0,
	kPTA18_MUX_GPIO = 1,
	kPTA18_MUX_LPUART1_RX = 3,
	kPTA18_MUX_TPM_CLKIN0 = 4
};// __porta_bit18_mux_t;

#define rPTA_PCR19 sPORTA.PORT_PCR19.WORD
#define bPTA19_ISF sPORTA.PORT_PCR19.BITS.ISF					// Interrupt Status Flag
#define bPTA19_IRQC sPORTA.PORT_PCR19.BITS.IRQC				// Interrupt configuration
#define bPTA19_MUX sPORTA.PORT_PCR19.BITS.MUX					// Pin Mux Control
#define bPTA19_DSE sPORTA.PORT_PCR19.BITS.DSE					// Driven Strength Enable
#define bPTA19_PFE sPORTA.PORT_PCR19.BITS.PFE					// Passive Filter Enable
#define bPTA19_SRE sPORTA.PORT_PCR19.BITS.SRE					// Slew Rate Enable
#define bPTA19_PE sPORTA.PORT_PCR19.BITS.PE					// Pull Enable
#define bPTA19_PS sPORTA.PORT_PCR19.BITS.PS					// Pull Select

enum{
	kPTA19_MUX_XTAL0 = 0,
	kPTA19_MUX_GPIO = 1,
	kPTA19_MUX_LPUART1_TX = 3,
	kPTA19_MUX_TPM_CLKIN1 = 4,
	kPTA19_MUX_LPTMR0_ALT1 = 6
};// __porta_bit19_mux_t;

#define rPTA_PCR20 sPORTA.PORT_PCR20.WORD
#define bPTA20_ISF sPORTA.PORT_PCR20.BITS.ISF					// Interrupt Status Flag
#define bPTA20_IRQC sPORTA.PORT_PCR20.BITS.IRQC				// Interrupt configuration
#define bPTA20_MUX sPORTA.PORT_PCR20.BITS.MUX					// Pin Mux Control
#define bPTA20_DSE sPORTA.PORT_PCR20.BITS.DSE					// Driven Strength Enable
#define bPTA20_PFE sPORTA.PORT_PCR20.BITS.PFE					// Passive Filter Enable
#define bPTA20_SRE sPORTA.PORT_PCR20.BITS.SRE					// Slew Rate Enable
#define bPTA20_PE sPORTA.PORT_PCR20.BITS.PE					// Pull Enable
#define bPTA20_PS sPORTA.PORT_PCR20.BITS.PS					// Pull Select

enum{
	kPTA20_MUX_GPIO = 1,
	kPTA20_MUX_RESET_b = 7
};// __porta_bit20_mux_t;

#define rPTA_GPCLR sPORTA.PORT_GPCLR.WORD
#define bPTA_GPCLR_GPWD sPORTA.PORT_GPCLR.SHORT.GPWD
#define bPTA_GPCLR_GPWE sPORTA.PORT_GPCLR.SHORT.GPWE

#define bPTA0_DATA  sPORTA.PORT_GPCLR.BITS.PTA0_DATA		    // Global Pin PTA0 Write Data
#define bPTA1_DATA  sPORTA.PORT_GPCLR.BITS.PTA1_DATA	    	// Global Pin PTA1 Write Data
#define bPTA2_DATA  sPORTA.PORT_GPCLR.BITS.PTA2_DATA	  	  	// Global Pin PTA2 Write Data
#define bPTA3_DATA  sPORTA.PORT_GPCLR.BITS.PTA3_DATA	   	 	// Global Pin PTA3 Write Data
#define bPTA4_DATA  sPORTA.PORT_GPCLR.BITS.PTA4_DATA	    	// Global Pin PTA4 Write Data
#define bPTA5_DATA  sPORTA.PORT_GPCLR.BITS.PTA5_DATA	    	// Global Pin PTA5 Write Data
#define bPTA12_DATA sPORTA.PORT_GPCLR.BITS.PTA12_DATA	    	// Global Pin PTA12 Write Data
#define bPTA13_DATA sPORTA.PORT_GPCLR.BITS.PTA13_DATA	    	// Global Pin PTA13 Write Data

#define bPTA0_WE    sPORTA.PORT_GPCLR.BITS.PTA0_WE	    	// Global Pin PTA0 Write Enable
#define bPTA1_WE    sPORTA.PORT_GPCLR.BITS.PTA1_WE	    	// Global Pin PTA1 Write Enable
#define bPTA2_WE    sPORTA.PORT_GPCLR.BITS.PTA2_WE	    	// Global Pin PTA2 Write Enable
#define bPTA3_WE    sPORTA.PORT_GPCLR.BITS.PTA3_WE	    	// Global Pin PTA3 Write Enable
#define bPTA4_WE    sPORTA.PORT_GPCLR.BITS.PTA4_WE	    	// Global Pin PTA4 Write Enable
#define bPTA5_WE    sPORTA.PORT_GPCLR.BITS.PTA5_WE	    	// Global Pin PTA5 Write Enable
#define bPTA12_WE   sPORTA.PORT_GPCLR.BITS.PTA12_WE	    	// Global Pin PTA12 Write Enable
#define bPTA13_WE   sPORTA.PORT_GPCLR.BITS.PTA13_WE	    	// Global Pin PTA13 Write Enable

// PORTA_GPCHR
#define rPTA_GPCHR sPORTA.PORT_GPCHR.WORD 					// Global Pin Control High Register
#define bPTA_GPCHR_GPWD sPORTA.PORT_GPCHR.Shorts.GPWD
#define bPTA_GPCHR_GPWE sPORTA.PORT_GPCHR.Shorts.GPWE

#define bPTA18_DATA sPORTA.PORT_GPCHR.BITS.PTA18_DATA	    	// Global Pin PTA18 Write Data
#define bPTA19_DATA sPORTA.PORT_GPCHR.BITS.PTA19_DATA    		// Global Pin PTA19 Write Data
#define bPTA20_DATA sPORTA.PORT_GPCHR.BITS.PTA20_DATA	    	// Global Pin PTA20 Write Data

#define bPTA18_WE   sPORTA.PORT_GPCHR.BITS.PTA18_WE	    	// Global Pin PTA18 Write Enable
#define bPTA19_WE   sPORTA.PORT_GPCHR.BITS.PTA19_WE	    	// Global Pin PTA19 Write Enable
#define bPTA20_WE   sPORTA.PORT_GPCHR.BITS.PTA20_WE	    	// Global Pin PTA20 Write Enable

// PORTA_ISFR
#define rPTA_ISFR sPORTA.PORT_ISFR.WORD 						// Interrupt Status Flag Register

#define bPTA0_ISFR  sPORTA.PORT_ISFR.BITS.PTA0_ISR				// Pin PTA0 Interrupt Status Flag
#define bPTA1_ISFR  sPORTA.PORT_ISFR.BITS.PTA1_ISR				// Pin PTA1 Interrupt Status Flag
#define bPTA2_ISFR  sPORTA.PORT_ISFR.BITS.PTA2_ISR				// Pin PTA2 Interrupt Status Flag
#define bPTA3_ISFR  sPORTA.PORT_ISFR.BITS.PTA3_ISR				// Pin PTA3 Interrupt Status Flag
#define bPTA4_ISFR  sPORTA.PORT_ISFR.BITS.PTA4_ISR				// Pin PTA4 Interrupt Status Flag
#define bPTA5_ISFR  sPORTA.PORT_ISFR.BITS.PTA5_ISR				// Pin PTA5 Interrupt Status Flag
#define bPTA12_ISFR sPORTA.PORT_ISFR.BITS.PTA12_ISR			// Pin PTA12 Interrupt Status Flag
#define bPTA13_ISFR sPORTA.PORT_ISFR.BITS.PTA13_ISR			// Pin PTA13 Interrupt Status Flag
#define bPTA18_ISFR sPORTA.PORT_ISFR.BITS.PTA18_ISR	    	// Pin PTA18 Interrupt Status Flag
#define bPTA19_ISFR sPORTA.PORT_ISFR.BITS.PTA19_ISR	    	// Pin PTA19 Interrupt Status Flag
#define bPTA20_ISFR sPORTA.PORT_ISFR.BITS.PTA20_ISR	    	// Pin PTA20Interrupt Status Flag

////////////////////////////////////////////////////////////
// PORTB
///////////////////////////////////////////////////////////

#define sPORTB (*((__port_t *)(0x4004A000)))					// PORTB global structure

#define rPTB_PCR0 sPORTB.PORT_PCR0.WORD
#define bPTB0_ISF sPORTB.PORT_PCR0.BITS.ISF					// Interrupt Status Flag
#define bPTB0_IRQC sPORTB.PORT_PCR0.BITS.IRQC					// Interrupt configuration
#define bPTB0_MUX sPORTB.PORT_PCR0.BITS.MUX					// Pin Mux Control
#define bPTB0_DSE sPORTB.PORT_PCR0.BITS.DSE					// Driven Strength Enable
#define bPTB0_PFE sPORTB.PORT_PCR0.BITS.PFE					// Passive Filter Enable
#define bPTB0_SRE sPORTB.PORT_PCR0.BITS.SRE					// Slew Rate Enable
#define bPTB0_PE sPORTB.PORT_PCR0.BITS.PE						// Pull Enable
#define bPTB0_PS sPORTB.PORT_PCR0.BITS.PS						// Pull Select

enum{
	kPTB0_MUX_ADC0_SE8 = 0,
	kPTB0_MUX_GPIO = 1,
	kPTB0_MUX_I2C0_SCL = 2,
	kPTB0_MUX_TPM1_CH0 = 3,
	kPTB0_MUX_SPI1_MOSI = 4,
	kPTB0_MUX_SPI1_MISO = 5
};// __porta_bit0_mux_t;

#define rPTB_PCR1 sPORTB.PORT_PCR1.WORD
#define bPTB1_ISF sPORTB.PORT_PCR1.BITS.ISF					// Interrupt Status Flag
#define bPTB1_IRQC sPORTB.PORT_PCR1.BITS.IRQC					// Interrupt configuration
#define bPTB1_MUX sPORTB.PORT_PCR1.BITS.MUX					// Pin Mux Control
#define bPTB1_DSE sPORTB.PORT_PCR1.BITS.DSE					// Driven Strength Enable
#define bPTB1_PFE sPORTB.PORT_PCR1.BITS.PFE					// Passive Filter Enable
#define bPTB1_SRE sPORTB.PORT_PCR1.BITS.SRE					// Slew Rate Enable
#define bPTB1_PE sPORTB.PORT_PCR1.BITS.PE						// Pull Enable
#define bPTB1_PS sPORTB.PORT_PCR1.BITS.PS						// Pull Select

enum{
	kPTB1_MUX_ADC0_SE9 = 0,
	kPTB1_MUX_GPIO = 1,
	kPTB1_MUX_I2C0_SDA = 2,
	kPTB1_MUX_TPM1_CH1 = 3,
	kPTB1_MUX_SPI1_MISO = 4,
	kPTB1_MUX_SPI1_MOSI = 5
};// __porta_bit1_mux_t;

#define rPTB_PCR2 sPORTB.PORT_PCR2.WORD
#define bPTB2_ISF sPORTB.PORT_PCR2.BITS.ISF					// Interrupt Status Flag
#define bPTB2_IRQC sPORTB.PORT_PCR2.BITS.IRQC					// Interrupt configuration
#define bPTB2_MUX sPORTB.PORT_PCR2.BITS.MUX					// Pin Mux Control
#define bPTB2_DSE sPORTB.PORT_PCR2.BITS.DSE					// Driven Strength Enable
#define bPTB2_PFE sPORTB.PORT_PCR2.BITS.PFE					// Passive Filter Enable
#define bPTB2_SRE sPORTB.PORT_PCR2.BITS.SRE					// Slew Rate Enable
#define bPTB2_PE sPORTB.PORT_PCR2.BITS.PE						// Pull Enable
#define bPTB2_PS sPORTB.PORT_PCR2.BITS.PS						// Pull Select

enum{
	kPTB2_MUX_ADC0_SE12 = 0,
	kPTB2_MUX_GPIO = 1,
	kPTB2_MUX_I2C0_SCL = 2,
	kPTB2_MUX_TPM2_CH0 = 3
};// __porta_bit2_mux_t;

#define rPTB_PCR3 sPORTB.PORT_PCR3.WORD
#define bPTB3_ISF sPORTB.PORT_PCR3.BITS.ISF					// Interrupt Status Flag
#define bPTB3_IRQC sPORTB.PORT_PCR3.BITS.IRQC					// Interrupt configuration
#define bPTB3_MUX sPORTB.PORT_PCR3.BITS.MUX					// Pin Mux Control
#define bPTB3_DSE sPORTB.PORT_PCR3.BITS.DSE					// Driven Strength Enable
#define bPTB3_PFE sPORTB.PORT_PCR3.BITS.PFE					// Passive Filter Enable
#define bPTB3_SRE sPORTB.PORT_PCR3.BITS.SRE					// Slew Rate Enable
#define bPTB3_PE sPORTB.PORT_PCR3.BITS.PE						// Pull Enable
#define bPTB3_PS sPORTB.PORT_PCR3.BITS.PS						// Pull Select

enum{
	kPTB3_MUX_ADC0_SE13 = 0,
	kPTB3_MUX_GPIO = 1,
	kPTB3_MUX_I2C0_SDA = 2,
	kPTB3_MUX_TPM2_CH1 = 3
};// __porta_bit3_mux_t;

#define rPTB_PCR16 sPORTB.PORT_PCR16.WORD
#define bPTB16_ISF sPORTB.PORT_PCR16.BITS.ISF					// Interrupt Status Flag
#define bPTB16_IRQC sPORTB.PORT_PCR16.BITS.IRQC				// Interrupt configuration
#define bPTB16_MUX sPORTB.PORT_PCR16.BITS.MUX					// Pin Mux Control
#define bPTB16_DSE sPORTB.PORT_PCR16.BITS.DSE					// Driven Strength Enable
#define bPTB16_PFE sPORTB.PORT_PCR16.BITS.PFE					// Passive Filter Enable
#define bPTB16_SRE sPORTB.PORT_PCR16.BITS.SRE					// Slew Rate Enable
#define bPTB16_PE sPORTB.PORT_PCR16.BITS.PE					// Pull Enable
#define bPTB16_PS sPORTB.PORT_PCR16.BITS.PS					// Pull Select

enum{
	kPTB16_MUX_GPIO = 1,
	kPTB16_MUX_SPI1_MOSI = 2,
	kPTB16_MUX_LPUART0_RX = 3,
	kPTB16_MUX_TPM_CLKIN0 = 4,
	kPTB16_MUX_SPI1_MISO = 5
};// __porta_bit16_mux_t;

#define rPTB_PCR17 sPORTB.PORT_PCR17.WORD
#define bPTB17_ISF sPORTB.PORT_PCR17.BITS.ISF					// Interrupt Status Flag
#define bPTB17_IRQC sPORTB.PORT_PCR17.BITS.IRQC				// Interrupt configuration
#define bPTB17_MUX sPORTB.PORT_PCR17.BITS.MUX					// Pin Mux Control
#define bPTB17_DSE sPORTB.PORT_PCR17.BITS.DSE					// Driven Strength Enable
#define bPTB17_PFE sPORTB.PORT_PCR17.BITS.PFE					// Passive Filter Enable
#define bPTB17_SRE sPORTB.PORT_PCR17.BITS.SRE					// Slew Rate Enable
#define bPTB17_PE sPORTB.PORT_PCR17.BITS.PE					// Pull Enable
#define bPTB17_PS sPORTB.PORT_PCR17.BITS.PS					// Pull Select

enum{
	kPTB17_MUX_GPIO = 1,
	kPTB17_MUX_SPI1_MISO = 2,
	kPTB17_MUX_LPUART0_TX = 3,
	kPTB17_MUX_TPM_CLKIN1 = 4,
	kPTB17_MUX_SPI1_MOSI = 5
};// __porta_bit17_mux_t;

#define rPTB_PCR18 sPORTB.PORT_PCR18.WORD
#define bPTB18_ISF sPORTB.PORT_PCR18.BITS.ISF					// Interrupt Status Flag
#define bPTB18_IRQC sPORTB.PORT_PCR18.BITS.IRQC				// Interrupt configuration
#define bPTB18_MUX sPORTB.PORT_PCR18.BITS.MUX					// Pin Mux Control
#define bPTB18_DSE sPORTB.PORT_PCR18.BITS.DSE					// Driven Strength Enable
#define bPTB18_PFE sPORTB.PORT_PCR18.BITS.PFE					// Passive Filter Enable
#define bPTB18_SRE sPORTB.PORT_PCR18.BITS.SRE					// Slew Rate Enable
#define bPTB18_PE sPORTB.PORT_PCR18.BITS.PE					// Pull Enable
#define bPTB18_PS sPORTB.PORT_PCR18.BITS.PS					// Pull Select

enum{
	kPTB18_MUX_GPIO = 1,
	kPTB18_MUX_TPM2_CH0 = 3
};// __porta_bit18_mux_t;

#define rPTB_PCR19 sPORTB.PORT_PCR19.WORD
#define bPTB19_ISF sPORTB.PORT_PCR19.BITS.ISF					// Interrupt Status Flag
#define bPTB19_IRQC sPORTB.PORT_PCR19.BITS.IRQC				// Interrupt configuration
#define bPTB19_MUX sPORTB.PORT_PCR19.BITS.MUX					// Pin Mux Control
#define bPTB19_DSE sPORTB.PORT_PCR19.BITS.DSE					// Driven Strength Enable
#define bPTB19_PFE sPORTB.PORT_PCR19.BITS.PFE					// Passive Filter Enable
#define bPTB19_SRE sPORTB.PORT_PCR19.BITS.SRE					// Slew Rate Enable
#define bPTB19_PE sPORTB.PORT_PCR19.BITS.PE					// Pull Enable
#define bPTB19_PS sPORTB.PORT_PCR19.BITS.PS					// Pull Select

enum{
	kPTB19_MUX_GPIO = 1,
	kPTB19_MUX_TPM2_CH1 = 3
};// __porta_bit19_mux_t;


#define rPTB_GPCLR sPORTB.PORT_GPCLR.WORD
#define bPTB_GPCLR_GPWD sPORTB.PORT_GPCLR.SHORT.GPWD
#define bPTB_GPCLR_GPWE sPORTB.PORT_GPCLR.SHORT.GPWE

#define bPTB0_DATA  sPORTB.PORT_GPCLR.BITS.ptb0_DATA	    	// Global Pin PTB0 Write Data
#define bPTB1_DATA  sPORTB.PORT_GPCLR.BITS.PTB1_DATA	    	// Global Pin PTB1 Write Data
#define bPTB2_DATA  sPORTB.PORT_GPCLR.BITS.PTB2_DATA	    	// Global Pin PTB2 Write Data
#define bPTB3_DATA  sPORTB.PORT_GPCLR.BITS.PTB3_DATA	    	// Global Pin PTB3 Write Data

#define bPTB0_WE    sPORTB.PORT_GPCLR.BITS.PTB0_WE	    		// Global Pin PTB0 Write Enable
#define bPTB1_WE    sPORTB.PORT_GPCLR.BITS.PTB1_WE	    		// Global Pin PTB1 Write Enable
#define bPTB2_WE    sPORTB.PORT_GPCLR.BITS.PTB2_WE	    		// Global Pin PTB2 Write Enable
#define bPTB3_WE    sPORTB.PORT_GPCLR.BITS.PTB3_WE	    		// Global Pin PTB3 Write Enable

// PORTB_GPCHR
#define rPTB_GPCHR sPORTB.PORT_GPCHR.WORD 						// Global Pin Control High Register
#define bPTB_GPCHR_GPWD sPORTB.PORT_GPCHR.Shorts.GPWD
#define bPTB_GPCHR_GPWE sPORTB.PORT_GPCHR.Shorts.GPWE

#define bPTB16_DATA sPORTB.PORT_GPCHR.BITS.PTB16_DATA	    	// Global Pin PTB18 Write Data
#define bPTB17_DATA sPORTB.PORT_GPCHR.BITS.PTB17_DATA	    	// Global Pin PTB18 Write Data
#define bPTB18_DATA sPORTB.PORT_GPCHR.BITS.PTB18_DATA	    	// Global Pin PTB18 Write Data
#define bPTB19_DATA sPORTB.PORT_GPCHR.BITS.PTB19_DATA    		// Global Pin PTB19 Write Data

#define bPTB16_WE   sPORTB.PORT_GPCHR.BITS.PTB16_WE	    	// Global Pin PTB20 Write Enable
#define bPTB17_WE   sPORTB.PORT_GPCHR.BITS.PTB17_WE	    	// Global Pin PTB20 Write Enable
#define bPTB18_WE   sPORTB.PORT_GPCHR.BITS.PTB18_WE	    	// Global Pin PTB18 Write Enable
#define bPTB19_WE   sPORTB.PORT_GPCHR.BITS.PTB19_WE	    	// Global Pin PTB19 Write Enable

// PORTB_ISFR
#define rPTB_ISFR sPORTB.PORT_ISFR.WORD 						// Interrupt Status Flag Register

#define bPTB0_ISFR  sPORTB.PORT_ISFR.BITS.PTB0_ISR				// Pin PTB0 Interrupt Status Flag
#define bPTB1_ISFR  sPORTB.PORT_ISFR.BITS.PTB1_ISR				// Pin PTB1 Interrupt Status Flag
#define bPTB2_ISFR  sPORTB.PORT_ISFR.BITS.PTB2_ISR				// Pin PTB2 Interrupt Status Flag
#define bPTB3_ISFR  sPORTB.PORT_ISFR.BITS.PTB3_ISR				// Pin PTB3 Interrupt Status Flag
#define bPTB16_ISFR sPORTB.PORT_ISFR.BITS.PTB16_ISR			// Pin PTB12 Interrupt Status Flag
#define bPTB17_ISFR sPORTB.PORT_ISFR.BITS.PTB17_ISR			// Pin PTB13 Interrupt Status Flag
#define bPTB18_ISFR sPORTB.PORT_ISFR.BITS.PTB18_ISR	    	// Pin PTB18 Interrupt Status Flag
#define bPTB19_ISFR sPORTB.PORT_ISFR.BITS.PTC19_ISR	    	// Pin PTC19 Interrupt Status Flag

///////////////////////////////////////////////////
// PORT C
///////////////////////////////////////////////////

#define sPORTC (*((__port_t *)(0x4004B000)))					// PORTA global structure

#define rPTC_PCR0 sPORTC.PORT_PCR0.WORD
#define bPTC0_ISF sPORTC.PORT_PCR0.BITS.ISF					// Interrupt Status Flag
#define bPTC0_IRQC sPORTC.PORT_PCR0.BITS.IRQC					// Interrupt configuration
#define bPTC0_MUX sPORTC.PORT_PCR0.BITS.MUX					// Pin Mux Control
#define bPTC0_DSE sPORTC.PORT_PCR0.BITS.DSE					// Driven Strength Enable
#define bPTC0_PFE sPORTC.PORT_PCR0.BITS.PFE					// Passive Filter Enable
#define bPTC0_SRE sPORTC.PORT_PCR0.BITS.SRE					// Slew Rate Enable
#define bPTC0_PE sPORTC.PORT_PCR0.BITS.PE						// Pull Enable
#define bPTC0_PS sPORTC.PORT_PCR0.BITS.PS						// Pull Select

enum{
	kPTC0_MUX_ADC0_SE14 = 0,
	kPTC0_MUX_GPIO = 1,
	kPTC0_MUX_EXTRG_IN = 3,
	kPTC0_MUX_audioUSB_SOF_OUT = 4,
	kPTC0_MUX_CMP0_OUT = 5
};// __portc_bit0_mux_t;

#define rPTC_PCR1 sPORTC.PORT_PCR1.WORD
#define bPTC1_ISF sPORTC.PORT_PCR1.BITS.ISF					// Interrupt Status Flag
#define bPTC1_IRQC sPORTC.PORT_PCR1.BITS.IRQC					// Interrupt configuration
#define bPTC1_MUX sPORTC.PORT_PCR1.BITS.MUX					// Pin Mux Control
#define bPTC1_DSE sPORTC.PORT_PCR1.BITS.DSE					// Driven Strength Enable
#define bPTC1_PFE sPORTC.PORT_PCR1.BITS.PFE					// Passive Filter Enable
#define bPTC1_SRE sPORTC.PORT_PCR1.BITS.SRE					// Slew Rate Enable
#define bPTC1_PE sPORTC.PORT_PCR1.BITS.PE						// Pull Enable
#define bPTC1_PS sPORTC.PORT_PCR1.BITS.PS						// Pull Select

enum{
	kPTC1_MUX_ADC0_SE15 = 0,
	kPTC1_MUX_GPIO = 1,
	kPTC1_MUX_LLWU_P6 = 1,
	kPTC1_MUX_RTC_CLKIN = 1,
	kPTC1_MUX_I2C1_SCL = 2,
	kPTC1_MUX_TPM0_CH0 = 4
};// __portc_bit1_mux_t;

#define rPTC_PCR2 sPORTC.PORT_PCR2.WORD
#define bPTC2_ISF sPORTC.PORT_PCR2.BITS.ISF					// Interrupt Status Flag
#define bPTC2_IRQC sPORTC.PORT_PCR2.BITS.IRQC					// Interrupt configuration
#define bPTC2_MUX sPORTC.PORT_PCR2.BITS.MUX					// Pin Mux Control
#define bPTC2_DSE sPORTC.PORT_PCR2.BITS.DSE					// Driven Strength Enable
#define bPTC2_PFE sPORTC.PORT_PCR2.BITS.PFE					// Passive Filter Enable
#define bPTC2_SRE sPORTC.PORT_PCR2.BITS.SRE					// Slew Rate Enable
#define bPTC2_PE sPORTC.PORT_PCR2.BITS.PE						// Pull Enable
#define bPTC2_PS sPORTC.PORT_PCR2.BITS.PS						// Pull Select

enum{
	kPTC2_MUX_ADC0_SE11 = 0,
	kPTC2_MUX_GPIO = 1,
	kPTC2_MUX_I2C1_SDA = 2,
	kPTC2_MUX_TPM0_CH1 = 4
};// __portc_bit2_mux_t;

#define rPTC_PCR3 sPORTC.PORT_PCR3.WORD
#define bPTC3_ISF sPORTC.PORT_PCR3.BITS.ISF					// Interrupt Status Flag
#define bPTC3_IRQC sPORTC.PORT_PCR3.BITS.IRQC					// Interrupt configuration
#define bPTC3_MUX sPORTC.PORT_PCR3.BITS.MUX					// Pin Mux Control
#define bPTC3_DSE sPORTC.PORT_PCR3.BITS.DSE					// Driven Strength Enable
#define bPTC3_PFE sPORTC.PORT_PCR3.BITS.PFE					// Passive Filter Enable
#define bPTC3_SRE sPORTC.PORT_PCR3.BITS.SRE					// Slew Rate Enable
#define bPTC3_PE sPORTC.PORT_PCR3.BITS.PE						// Pull Enable
#define bPTC3_PS sPORTC.PORT_PCR3.BITS.PS						// Pull Select

enum{
	kPTC3_MUX_GPIO = 1,
	kPTC3_MUX_LLWU_P7 = 1,
	kPTC3_MUX_SPI1_SCK = 2,
	kPTC3_MUX_LPUART1_RX = 3,
	kPTC3_MUX_TPM0_CH2 = 4,
	kPTC3_MUX_CLKOUT = 5
};// __portc_bit3_mux_t;

#define rPTC_PCR4 sPORTC.PORT_PCR4.WORD
#define bPTC4_ISF sPORTC.PORT_PCR4.BITS.ISF					// Interrupt Status Flag
#define bPTC4_IRQC sPORTC.PORT_PCR4.BITS.IRQC					// Interrupt configuration
#define bPTC4_MUX sPORTC.PORT_PCR4.BITS.MUX					// Pin Mux Control
#define bPTC4_DSE sPORTC.PORT_PCR4.BITS.DSE					// Driven Strength Enable
#define bPTC4_PFE sPORTC.PORT_PCR4.BITS.PFE					// Passive Filter Enable
#define bPTC4_SRE sPORTC.PORT_PCR4.BITS.SRE					// Slew Rate Enable
#define bPTC4_PE sPORTC.PORT_PCR4.BITS.PE						// Pull Enable
#define bPTC4_PS sPORTC.PORT_PCR4.BITS.PS						// Pull Select

enum{
	kPTC4_MUX_GPIO = 1,
	kPTC4_MUX_LLWU_P8 = 1,
	kPTC4_MUX_SPI0_PCS0 = 2,
	kPTC4_MUX_LPUART1_TX = 3,
	kPTC4_MUX_TPM0_CH3 = 4,
	kPTC4_MUX_SPI1_PCS0 = 5
};// __portc_bit4_mux_t;

#define rPTC_PCR5 sPORTC.PORT_PCR5.WORD
#define bPTC5_ISF sPORTC.PORT_PCR5.BITS.ISF					// Interrupt Status Flag
#define bPTC5_IRQC sPORTC.PORT_PCR5.BITS.IRQC					// Interrupt configuration
#define bPTC5_MUX sPORTC.PORT_PCR5.BITS.MUX					// Pin Mux Control
#define bPTC5_DSE sPORTC.PORT_PCR5.BITS.DSE					// Driven Strength Enable
#define bPTC5_PFE sPORTC.PORT_PCR5.BITS.PFE					// Passive Filter Enable
#define bPTC5_SRE sPORTC.PORT_PCR5.BITS.SRE					// Slew Rate Enable
#define bPTC5_PE sPORTC.PORT_PCR5.BITS.PE						// Pull Enable
#define bPTC5_PS sPORTC.PORT_PCR5.BITS.PS						// Pull Select

enum{
	kPTC5_MUX_GPIO = 1,
	kPTC5_MUX_LLWU_P9 = 1,
	kPTC5_MUX_SPI0_SCK = 2,
	kPTC5_MUX_LPTMR0_ALT2 = 3,
	kPTC5_MUX_CMP0_OUT = 6
};// __portc_bit5_mux_t;

#define rPTC_PCR6 sPORTC.PORT_PCR6.WORD
#define bPTC6_ISF sPORTC.PORT_PCR6.BITS.ISF					// Interrupt Status Flag
#define bPTC6_IRQC sPORTC.PORT_PCR6.BITS.IRQC					// Interrupt configuration
#define bPTC6_MUX sPORTC.PORT_PCR6.BITS.MUX					// Pin Mux Control
#define bPTC6_DSE sPORTC.PORT_PCR6.BITS.DSE					// Driven Strength Enable
#define bPTC6_PFE sPORTC.PORT_PCR6.BITS.PFE					// Passive Filter Enable
#define bPTC6_SRE sPORTC.PORT_PCR6.BITS.SRE					// Slew Rate Enable
#define bPTC6_PE sPORTC.PORT_PCR6.BITS.PE						// Pull Enable
#define bPTC6_PS sPORTC.PORT_PCR6.BITS.PS						// Pull Select

enum{
	kPTC6_CMP0_IN0 = 0,
	kPTC6_MUX_GPIO = 1,
	kPTC6_MUX_LLWU_P10 = 1,
	kPTC6_MUX_SPI0_MOSI = 2,
	kPTC6_MUX_EXTRG_IN = 3,
	kPTC6_MUX_SPI0_MISO = 5
};// __portc_bit6_mux_t;

#define rPTC_PCR7 sPORTC.PORT_PCR7.WORD
#define bPTC7_ISF sPORTC.PORT_PCR7.BITS.ISF					// Interrupt Status Flag
#define bPTC7_IRQC sPORTC.PORT_PCR7.BITS.IRQC					// Interrupt configuration
#define bPTC7_MUX sPORTC.PORT_PCR7.BITS.MUX					// Pin Mux Control
#define bPTC7_DSE sPORTC.PORT_PCR7.BITS.DSE					// Driven Strength Enable
#define bPTC7_PFE sPORTC.PORT_PCR7.BITS.PFE					// Passive Filter Enable
#define bPTC7_SRE sPORTC.PORT_PCR7.BITS.SRE					// Slew Rate Enable
#define bPTC7_PE sPORTC.PORT_PCR7.BITS.PE						// Pull Enable
#define bPTC7_PS sPORTC.PORT_PCR7.BITS.PS						// Pull Select

enum{
	kPTC7_CMP0_IN1 = 0,
	kPTC7_MUX_GPIO = 1,
	kPTC7_MUX_SPI0_MISO = 2,
	kPTC7_MUX_audioUSB_SOF_OUT = 3,
	kPTC7_MUX_SPI0_MOSI = 5
};// __portc_bit7_mux_t;

#define rPTC_PCR8 sPORTC.PORT_PCR8.WORD
#define bPTC8_ISF sPORTC.PORT_PCR8.BITS.ISF					// Interrupt Status Flag
#define bPTC8_IRQC sPORTC.PORT_PCR8.BITS.IRQC					// Interrupt configuration
#define bPTC8_MUX sPORTC.PORT_PCR8.BITS.MUX					// Pin Mux Control
#define bPTC8_DSE sPORTC.PORT_PCR8.BITS.DSE					// Driven Strength Enable
#define bPTC8_PFE sPORTC.PORT_PCR8.BITS.PFE					// Passive Filter Enable
#define bPTC8_SRE sPORTC.PORT_PCR8.BITS.SRE					// Slew Rate Enable
#define bPTC8_PE sPORTC.PORT_PCR8.BITS.PE						// Pull Enable
#define bPTC8_PS sPORTC.PORT_PCR8.BITS.PS						// Pull Select

enum{
	kPTC8_MUX_CMP0_IN2 = 0,
	kPTC8_MUX_GPIO = 1,
	kPTC8_MUX_I2C0_SCL = 2,
	kPTC8_MUX_TPM0_CH4 = 3
};// __portc_bit8_mux_t;

#define rPTC_PCR9 sPORTC.PORT_PCR9.WORD
#define bPTC9_ISF sPORTC.PORT_PCR9.BITS.ISF					// Interrupt Status Flag
#define bPTC9_IRQC sPORTC.PORT_PCR9.BITS.IRQC					// Interrupt configuration
#define bPTC9_MUX sPORTC.PORT_PCR9.BITS.MUX					// Pin Mux Control
#define bPTC9_DSE sPORTC.PORT_PCR9.BITS.DSE					// Driven Strength Enable
#define bPTC9_PFE sPORTC.PORT_PCR9.BITS.PFE					// Passive Filter Enable
#define bPTC9_SRE sPORTC.PORT_PCR9.BITS.SRE					// Slew Rate Enable
#define bPTC9_PE sPORTC.PORT_PCR9.BITS.PE						// Pull Enable
#define bPTC9_PS sPORTC.PORT_PCR9.BITS.PS						// Pull Select

enum{
	kPTC9_MUX_CMP0_IN3 = 0,
	kPTC9_MUX_GPIO = 1,
	kPTC9_MUX_I2C0_SDA = 2,
	kPTC9_MUX_TPM0_CH5 = 3
};// __portc_bit9_mux_t;

#define rPTC_PCR10 sPORTC.PORT_PCR10.WORD
#define bPTC10_ISF sPORTC.PORT_PCR10.BITS.ISF					// Interrupt Status Flag
#define bPTC10_IRQC sPORTC.PORT_PCR10.BITS.IRQC				// Interrupt configuration
#define bPTC10_MUX sPORTC.PORT_PCR10.BITS.MUX					// Pin Mux Control
#define bPTC10_DSE sPORTC.PORT_PCR10.BITS.DSE					// Driven Strength Enable
#define bPTC10_PFE sPORTC.PORT_PCR10.BITS.PFE					// Passive Filter Enable
#define bPTC10_SRE sPORTC.PORT_PCR10.BITS.SRE					// Slew Rate Enable
#define bPTC10_PE sPORTC.PORT_PCR10.BITS.PE					// Pull Enable
#define bPTC10_PS sPORTC.PORT_PCR10.BITS.PS					// Pull Select

enum{
	kPTC10_MUX_GPIO = 1,
	kPTC10_MUX_I2C1_SCL = 2
};// __portc_bit10_mux_t;

#define rPTC_PCR11 sPORTC.PORT_PCR11.WORD
#define bPTC11_ISF sPORTC.PORT_PCR11.BITS.ISF					// Interrupt Status Flag
#define bPTC11_IRQC sPORTC.PORT_PCR11.BITS.IRQC				// Interrupt configuration
#define bPTC11_MUX sPORTC.PORT_PCR11.BITS.MUX					// Pin Mux Control
#define bPTC11_DSE sPORTC.PORT_PCR11.BITS.DSE					// Driven Strength Enable
#define bPTC11_PFE sPORTC.PORT_PCR11.BITS.PFE					// Passive Filter Enable
#define bPTC11_SRE sPORTC.PORT_PCR11.BITS.SRE					// Slew Rate Enable
#define bPTC11_PE sPORTC.PORT_PCR11.BITS.PE					// Pull Enable
#define bPTC11_PS sPORTC.PORT_PCR11.BITS.PS					// Pull Select

enum{
	kPTC11_MUX_GPIO = 1,
	kPTC11_MUX_I2C1_SDA = 2
};// __portc_bit10_mux_t;

#define rPTC_GPCLR sPORTC.PORT_GPCLR.WORD
#define bPTC_GPCLR_GPWD sPORTC.PORT_GPCLR.SHORT.GPWD
#define bPTC_GPCLR_GPWE sPORTC.PORT_GPCLR.SHORT.GPWE

#define bPTC0_DATA  sPORTC.PORT_GPCLR.BITS.PTC0_DATA	    	// Global Pin PTC0 Write Data
#define bPTC1_DATA  sPORTC.PORT_GPCLR.BITS.PTC1_DATA	    	// Global Pin PTC1 Write Data
#define bPTC2_DATA  sPORTC.PORT_GPCLR.BITS.PTC2_DATA	    	// Global Pin PTC2 Write Data
#define bPTC3_DATA  sPORTC.PORT_GPCLR.BITS.PTC3_DATA	    	// Global Pin PTC3 Write Data
#define bPTC4_DATA  sPORTC.PORT_GPCLR.BITS.PTC4_DATA	    	// Global Pin PTC4 Write Data
#define bPTC5_DATA  sPORTC.PORT_GPCLR.BITS.PTC5_DATA	    	// Global Pin PTC5 Write Data
#define bPTC6_DATA  sPORTC.PORT_GPCLR.BITS.PTC6_DATA	    	// Global Pin PTC6 Write Data
#define bPTC7_DATA  sPORTC.PORT_GPCLR.BITS.PTC7_DATA	    	// Global Pin PTC7 Write Data
#define bPTC8_DATA  sPORTC.PORT_GPCLR.BITS.PTC8_DATA	    	// Global Pin PTC8 Write Data
#define bPTC9_DATA  sPORTC.PORT_GPCLR.BITS.PTC9_DATA	    	// Global Pin PTC9 Write Data
#define bPTC10_DATA sPORTC.PORT_GPCLR.BITS.PTC10_DATA	    	// Global Pin PTC10 Write Data
#define bPTC11_DATA sPORTC.PORT_GPCLR.BITS.PTC11_DATA	    	// Global Pin PTC11 Write Data

#define bPTC0_WE    sPORTC.PORT_GPCLR.BITS.PTC0_WE	    	// Global Pin PTC0 Write Enable
#define bPTC1_WE    sPORTC.PORT_GPCLR.BITS.PTC1_WE	    	// Global Pin PTC1 Write Enable
#define bPTC2_WE    sPORTC.PORT_GPCLR.BITS.PTC2_WE	    	// Global Pin PTC2 Write Enable
#define bPTC3_WE    sPORTC.PORT_GPCLR.BITS.PTC3_WE	    	// Global Pin PTC3 Write Enable
#define bPTC4_WE    sPORTC.PORT_GPCLR.BITS.PTC4_WE	    	// Global Pin PTC4 Write Enable
#define bPTC5_WE    sPORTC.PORT_GPCLR.BITS.PTC5_WE	    	// Global Pin PTC5 Write Enable
#define bPTC6_WE    sPORTC.PORT_GPCLR.BITS.PTC6_WE	    	// Global Pin PTC6 Write Enable
#define bPTC7_WE    sPORTC.PORT_GPCLR.BITS.PTC7_WE	    	// Global Pin PTC7 Write Enable
#define bPTC8_WE    sPORTC.PORT_GPCLR.BITS.PTC8_WE	    	// Global Pin PTC8 Write Enable
#define bPTC9_WE    sPORTC.PORT_GPCLR.BITS.PTC9_WE	    	// Global Pin PTC9 Write Enable
#define bPTC10_WE   sPORTC.PORT_GPCLR.BITS.PTC10_WE	    	// Global Pin PTC10 Write Enable
#define bPTC11_WE   sPORTC.PORT_GPCLR.BITS.PTC11_WE	    	// Global Pin PTC11 Write Enable

// PORTA_ISFR
#define rPTC_ISFR sPORTC.PORT_ISFR.WORD 						// Interrupt Status Flag Register

#define bPTC0_ISFR  sPORTC.PORT_ISFR.BITS.PTC0_ISR				// Pin PTC0 Interrupt Status Flag
#define bPTC1_ISFR  sPORTC.PORT_ISFR.BITS.PTC1_ISR				// Pin PTC1 Interrupt Status Flag
#define bPTC2_ISFR  sPORTC.PORT_ISFR.BITS.PTC2_ISR				// Pin PTC2 Interrupt Status Flag
#define bPTC3_ISFR  sPORTC.PORT_ISFR.BITS.PTC3_ISR				// Pin PTC3 Interrupt Status Flag
#define bPTC4_ISFR  sPORTC.PORT_ISFR.BITS.PTC4_ISR				// Pin PTC4 Interrupt Status Flag
#define bPTC5_ISFR  sPORTC.PORT_ISFR.BITS.PTC5_ISR				// Pin PTC5 Interrupt Status Flag
#define bPTC6_ISFR  sPORTC.PORT_ISFR.BITS.PTC6_ISR				// Pin PTC6 Interrupt Status Flag
#define bPTC7_ISFR  sPORTC.PORT_ISFR.BITS.PTC7_ISR				// Pin PTC7 Interrupt Status Flag
#define bPTC8_ISFR  sPORTC.PORT_ISFR.BITS.PTC8_ISR	    		// Pin PTC8 Interrupt Status Flag
#define bPTC9_ISFR  sPORTC.PORT_ISFR.BITS.PTC9_ISR	    		// Pin PTC9 Interrupt Status Flag
#define bPTC10_ISFR sPORTC.PORT_ISFR.BITS.PTC10_ISR	    	// Pin PTC10Interrupt Status Flag
#define bPTC11_ISFR sPORTC.PORT_ISFR.BITS.PTC11_ISR	    	// Pin PTC11Interrupt Status Flag

///////////////////////////////////////////////////
// PORT D
///////////////////////////////////////////////////

#define sPORTD (*((__port_t *)(0x4004C000)))					// PORTD global structure

#define rPTD_PCR0 sPORTD.PORT_PCR0.WORD
#define bPTD0_ISF sPORTD.PORT_PCR0.BITS.ISF					// Interrupt Status Flag
#define bPTD0_IRQC sPORTD.PORT_PCR0.BITS.IRQC					// Interrupt configuration
#define bPTD0_MUX sPORTD.PORT_PCR0.BITS.MUX					// Pin Mux Control
#define bPTD0_DSE sPORTD.PORT_PCR0.BITS.DSE					// Driven Strength Enable
#define bPTD0_PFE sPORTD.PORT_PCR0.BITS.PFE					// Passive Filter Enable
#define bPTD0_SRE sPORTD.PORT_PCR0.BITS.SRE					// Slew Rate Enable
#define bPTD0_PE sPORTD.PORT_PCR0.BITS.PE						// Pull Enable
#define bPTD0_PS sPORTD.PORT_PCR0.BITS.PS						// Pull Select

enum{
	kPTD0_MUX_GPIO = 1,
	kPTD0_MUX_SPI0_PCS0 = 2,
	kPTD0_MUX_TPM0_CH0 = 4,
	kPTD0_MUX_FXIO0_D0 = 6
};// __portd_bit0_mux_t;

#define rPTD_PCR1 sPORTD.PORT_PCR1.WORD
#define bPTD1_ISF sPORTD.PORT_PCR1.BITS.ISF					// Interrupt Status Flag
#define bPTD1_IRQC sPORTD.PORT_PCR1.BITS.IRQC					// Interrupt configuration
#define bPTD1_MUX sPORTD.PORT_PCR1.BITS.MUX					// Pin Mux Control
#define bPTD1_DSE sPORTD.PORT_PCR1.BITS.DSE					// Driven Strength Enable
#define bPTD1_PFE sPORTD.PORT_PCR1.BITS.PFE					// Passive Filter Enable
#define bPTD1_SRE sPORTD.PORT_PCR1.BITS.SRE					// Slew Rate Enable
#define bPTD1_PE sPORTD.PORT_PCR1.BITS.PE						// Pull Enable
#define bPTD1_PS sPORTD.PORT_PCR1.BITS.PS						// Pull Select

enum{
	kPTD1_MUX_ADC0_SE5b = 0,
	kPTD1_MUX_GPIO = 1,
	kPTD1_MUX_SPI0_SCK = 2,
	kPTD1_MUX_TPMO_CH1 = 4,
	kPTD1_MUX_FXIO0_D1 = 6
};// __portd_bit1_mux_t;

#define rPTD_PCR2 sPORTD.PORT_PCR2.WORD
#define bPTD2_ISF sPORTD.PORT_PCR2.BITS.ISF					// Interrupt Status Flag
#define bPTD2_IRQC sPORTD.PORT_PCR2.BITS.IRQC					// Interrupt configuration
#define bPTD2_MUX sPORTD.PORT_PCR2.BITS.MUX					// Pin Mux Control
#define bPTD2_DSE sPORTD.PORT_PCR2.BITS.DSE					// Driven Strength Enable
#define bPTD2_PFE sPORTD.PORT_PCR2.BITS.PFE					// Passive Filter Enable
#define bPTD2_SRE sPORTD.PORT_PCR2.BITS.SRE					// Slew Rate Enable
#define bPTD2_PE sPORTD.PORT_PCR2.BITS.PE						// Pull Enable
#define bPTD2_PS sPORTD.PORT_PCR2.BITS.PS						// Pull Select

enum{
	kPTD2_MUX_GPIO = 1,
	kPTD2_MUX_SPI0_MOSI = 2,
	kPTD2_MUX_UART2_RX = 3,
	kPTD2_MUX_TPM0_CH2 = 4,
	kPTD2_MUX_SPI0_MISO = 5,
	kPTD2_MUX_FXIO0_D2 = 6
};// __portd_bit2_mux_t;

#define rPTD_PCR3 sPORTD.PORT_PCR3.WORD
#define bPTD3_ISF sPORTD.PORT_PCR3.BITS.ISF					// Interrupt Status Flag
#define bPTD3_IRQC sPORTD.PORT_PCR3.BITS.IRQC					// Interrupt configuration
#define bPTD3_MUX sPORTD.PORT_PCR3.BITS.MUX					// Pin Mux Control
#define bPTD3_DSE sPORTD.PORT_PCR3.BITS.DSE					// Driven Strength Enable
#define bPTD3_PFE sPORTD.PORT_PCR3.BITS.PFE					// Passive Filter Enable
#define bPTD3_SRE sPORTD.PORT_PCR3.BITS.SRE					// Slew Rate Enable
#define bPTD3_PE sPORTD.PORT_PCR3.BITS.PE						// Pull Enable
#define bPTD3_PS sPORTD.PORT_PCR3.BITS.PS						// Pull Select

enum{
	kPTD3_MUX_GPIO = 1,
	kPTD3_MUX_SPI0_MISO = 2,
	kPTD3_MUX_UART2_TX = 3,
	kPTD3_MUX_TPM0_CH3 = 4,
	kPTD3_MUX_SPI0_MOSI = 5,
	kPTD3_MUX_FXIO0_D3 = 6
};// __portd_bit3_mux_t;

#define rPTD_PCR4 sPORTD.PORT_PCR4.WORD
#define bPTD4_ISF sPORTD.PORT_PCR4.BITS.ISF					// Interrupt Status Flag
#define bPTD4_IRQC sPORTD.PORT_PCR4.BITS.IRQC					// Interrupt configuration
#define bPTD4_MUX sPORTD.PORT_PCR4.BITS.MUX					// Pin Mux Control
#define bPTD4_DSE sPORTD.PORT_PCR4.BITS.DSE					// Driven Strength Enable
#define bPTD4_PFE sPORTD.PORT_PCR4.BITS.PFE					// Passive Filter Enable
#define bPTD4_SRE sPORTD.PORT_PCR4.BITS.SRE					// Slew Rate Enable
#define bPTD4_PE sPORTD.PORT_PCR4.BITS.PE						// Pull Enable
#define bPTD4_PS sPORTD.PORT_PCR4.BITS.PS						// Pull Select

enum{
	kPTD4_MUX_GPIO = 1,
	kPTD4_MUX_LLWU_P14 = 1,
	kPTD4_MUX_SPI1_PCS0 = 2,
	kPTD4_MUX_UART2_RX = 3,
	kPTD4_MUX_TPM0_CH4 = 4,
	kPTD4_MUX_FXIO0_D4 = 6
};// __portd_bit4_mux_t;

#define rPTD_PCR5 sPORTD.PORT_PCR5.WORD
#define bPTD5_ISF sPORTD.PORT_PCR5.BITS.ISF					// Interrupt Status Flag
#define bPTD5_IRQC sPORTD.PORT_PCR5.BITS.IRQC					// Interrupt configuration
#define bPTD5_MUX sPORTD.PORT_PCR5.BITS.MUX					// Pin Mux Control
#define bPTD5_DSE sPORTD.PORT_PCR5.BITS.DSE					// Driven Strength Enable
#define bPTD5_PFE sPORTD.PORT_PCR5.BITS.PFE					// Passive Filter Enable
#define bPTD5_SRE sPORTD.PORT_PCR5.BITS.SRE					// Slew Rate Enable
#define bPTD5_PE sPORTD.PORT_PCR5.BITS.PE						// Pull Enable
#define bPTD5_PS sPORTD.PORT_PCR5.BITS.PS						// Pull Select

enum{
	kPTD5_ADC0_SE6b = 0,
	kPTD5_MUX_GPIO = 1,
	kPTD5_MUX_SPI1_SCK = 2,
	kPTD5_MUX_UART2_TX = 3,
	kPTD5_MUX_TPM0_CH5 = 4,
	kPTD5_MUX_FXIO0_D5 = 6
};// __portd_bit5_mux_t;

#define rPTD_PCR6 sPORTD.PORT_PCR6.WORD
#define bPTD6_ISF sPORTD.PORT_PCR6.BITS.ISF					// Interrupt Status Flag
#define bPTD6_IRQC sPORTD.PORT_PCR6.BITS.IRQC					// Interrupt configuration
#define bPTD6_MUX sPORTD.PORT_PCR6.BITS.MUX					// Pin Mux Control
#define bPTD6_DSE sPORTD.PORT_PCR6.BITS.DSE					// Driven Strength Enable
#define bPTD6_PFE sPORTD.PORT_PCR6.BITS.PFE					// Passive Filter Enable
#define bPTD6_SRE sPORTD.PORT_PCR6.BITS.SRE					// Slew Rate Enable
#define bPTD6_PE sPORTD.PORT_PCR6.BITS.PE						// Pull Enable
#define bPTD6_PS sPORTD.PORT_PCR6.BITS.PS						// Pull Select

enum{
	kPTD6_ADC0_SE7b = 0,
	kPTD6_MUX_GPIO = 1,
	kPTD6_MUX_LLWU_P15 = 1,
	kPTD6_MUX_SPI1_MOSI = 2,
	kPTD6_MUX_LPUART0_RX = 3,
	kPTD6_MUX_I2C1_SDA = 4,
	kPTD6_MUX_SPI1_MISO = 5,
	kPTD6_MUX_FXIO0_D6 = 6
};// __portd_bit6_mux_t;

#define rPTD_PCR7 sPORTD.PORT_PCR7.WORD
#define bPTD7_ISF sPORTD.PORT_PCR7.BITS.ISF					// Interrupt Status Flag
#define bPTD7_IRQC sPORTD.PORT_PCR7.BITS.IRQC					// Interrupt configuration
#define bPTD7_MUX sPORTD.PORT_PCR7.BITS.MUX					// Pin Mux Control
#define bPTD7_DSE sPORTD.PORT_PCR7.BITS.DSE					// Driven Strength Enable
#define bPTD7_PFE sPORTD.PORT_PCR7.BITS.PFE					// Passive Filter Enable
#define bPTD7_SRE sPORTD.PORT_PCR7.BITS.SRE					// Slew Rate Enable
#define bPTD7_PE sPORTD.PORT_PCR7.BITS.PE						// Pull Enable
#define bPTD7_PS sPORTD.PORT_PCR7.BITS.PS						// Pull Select

enum{
	kPTD7_MUX_GPIO = 1,
	kPTD7_MUX_SPI1_MISO = 2,
	kPTD7_MUX_LPUART0_TX = 3,
	kPTD7_MUX_I2C1_SCL = 4,
	kPTD7_MUX_SPI1_MOSI = 5,
	kPTD7_MUX_FXIO0_D7 = 6
};// __portd_bit7_mux_t;

#define rPTD_GPCLR sPORTD.PORT_GPCLR.WORD
#define bPTD_GPCLR_GPWD sPORTD.PORTD_GPCLR.SHORT.GPWD
#define bPTD_GPCLR_GPWE sPORTD.PORTD_GPCLR.SHORT.GPWE

#define bPTD0_DATA  sPORTD.PORTD_GPCLR.BITS.PTD0_DATA	  		// Global Pin PTD0 Write Data
#define bPTD1_DATA  sPORTD.PORTD_GPCLR.BITS.PTD1_DATA	  		// Global Pin PTD1 Write Data
#define bPTD2_DATA  sPORTD.PORTD_GPCLR.BITS.PTD2_DATA	  		// Global Pin PTD2 Write Data
#define bPTD3_DATA  sPORTD.PORTD_GPCLR.BITS.PTD3_DATA	  		// Global Pin PTD3 Write Data
#define bPTD4_DATA  sPORTD.PORTD_GPCLR.BITS.PTD4_DATA	  		// Global Pin PTD4 Write Data
#define bPTD5_DATA  sPORTD.PORTD_GPCLR.BITS.PTD5_DATA	  		// Global Pin PTD5 Write Data
#define bPTD6_DATA  sPORTD.PORTD_GPCLR.BITS.PTD6_DATA	  		// Global Pin PTD6 Write Data
#define bPTD7_DATA  sPORTD.PORTD_GPCLR.BITS.PTD7_DATA	  		// Global Pin PTD7 Write Data

#define bPTD0_WE    sPORTD.PORTD_GPCLR.BITS.PTD0_WE	   	 	// Global Pin PTD0 Write Enable
#define bPTD1_WE    sPORTD.PORTD_GPCLR.BITS.PTD1_WE	   	 	// Global Pin PTD1 Write Enable
#define bPTD2_WE    sPORTD.PORTD_GPCLR.BITS.PTD2_WE	    	// Global Pin PTD2 Write Enable
#define bPTD3_WE    sPORTD.PORTD_GPCLR.BITS.PTD3_WE	    	// Global Pin PTD3 Write Enable
#define bPTD4_WE    sPORTD.PORTD_GPCLR.BITS.PTD4_WE	    	// Global Pin PTD4 Write Enable
#define bPTD5_WE    sPORTD.PORTD_GPCLR.BITS.PTD5_WE	    	// Global Pin PTD5 Write Enable
#define bPTD6_WE    sPORTD.PORTD_GPCLR.BITS.PTD6_WE	    	// Global Pin PTD6 Write Enable
#define bPTD7_WE    sPORTD.PORTD_GPCLR.BITS.PTD7_WE	    	// Global Pin PTD7 Write Enable

// PORTD_ISFR
#define rPTD_ISFR sPORTD.PORT_ISFR.WORD 		// Interrupt Status Flag Register

#define bPTD0_ISFR  sPORTD.PORT_ISFR.BITS.PTD0_ISR				// Pin PTD0 Interrupt Status Flag
#define bPTD1_ISFR  sPORTD.PORT_ISFR.BITS.PTD1_ISR				// Pin PTD1 Interrupt Status Flag
#define bPTD2_ISFR  sPORTD.PORT_ISFR.BITS.PTD2_ISR				// Pin PTD2 Interrupt Status Flag
#define bPTD3_ISFR  sPORTD.PORT_ISFR.BITS.PTD3_ISR				// Pin PTD3 Interrupt Status Flag
#define bPTD4_ISFR  sPORTD.PORT_ISFR.BITS.PTD4_ISR				// Pin PTD4 Interrupt Status Flag
#define bPTD5_ISFR  sPORTD.PORT_ISFR.BITS.PTD5_ISR				// Pin PTD5 Interrupt Status Flag
#define bPTD6_ISFR  sPORTD.PORT_ISFR.BITS.PTD6_ISR				// Pin PTD6 Interrupt Status Flag
#define bPTD7_ISFR  sPORTD.PORT_ISFR.BITS.PTD7_ISR				// Pin PTD7 Interrupt Status Flag

////////////////////////////////////////////////////////////
// PORTE
///////////////////////////////////////////////////////////

#define sPORTE (*((__port_t *)(0x4004D000)))					// PORTE global structure

#define rPTE_PCR0 sPORTE.PORT_PCR0.WORD
#define bPTE0_ISF sPORTE.PORT_PCR0.BITS.ISF					// Interrupt Status Flag
#define bPTE0_IRQC sPORTE.PORT_PCR0.BITS.IRQC					// Interrupt configuration
#define bPTE0_MUX sPORTE.PORT_PCR0.BITS.MUX					// Pin Mux Control
#define bPTE0_DSE sPORTE.PORT_PCR0.BITS.DSE					// Driven Strength Enable
#define bPTE0_PFE sPORTE.PORT_PCR0.BITS.PFE					// Passive Filter Enable
#define bPTE0_SRE sPORTE.PORT_PCR0.BITS.SRE					// Slew Rate Enable
#define bPTE0_PE sPORTE.PORT_PCR0.BITS.PE						// Pull Enable
#define bPTE0_PS sPORTE.PORT_PCR0.BITS.PS						// Pull Select

enum{
	kPTE0_MUX_GPIO = 1,
	kPTE0_MUX_CLKOUT32K = 1,
	kPTE0_MUX_SPI1_MISO = 2,
	kPTE0_MUX_LPUART1_TX = 3,
	kPTE0_MUX_RTC_CLKOUT = 4,
	kPTE0_MUX_CMP0_OUT = 5,
	kPTE0_MUX_I2C1_SDA = 6
};// __porte_bit0_mux_t;

#define rPTE_PCR1 sPORTE.PORT_PCR1.WORD
#define bPTE1_ISF sPORTE.PORT_PCR1.BITS.ISF					// Interrupt Status Flag
#define bPTE1_IRQC sPORTE.PORT_PCR1.BITS.IRQC					// Interrupt configuration
#define bPTE1_MUX sPORTE.PORT_PCR1.BITS.MUX					// Pin Mux Control
#define bPTE1_DSE sPORTE.PORT_PCR1.BITS.DSE					// Driven Strength Enable
#define bPTE1_PFE sPORTE.PORT_PCR1.BITS.PFE					// Passive Filter Enable
#define bPTE1_SRE sPORTE.PORT_PCR1.BITS.SRE					// Slew Rate Enable
#define bPTE1_PE sPORTE.PORT_PCR1.BITS.PE						// Pull Enable
#define bPTE1_PS sPORTE.PORT_PCR1.BITS.PS						// Pull Select

enum{
	kPTE1_MUX_GPIO = 1,
	kPTE1_MUX_SPI1_MOSI = 2,
	kPTE1_MUX_LPUART1_RX = 3,
	kPTE1_MUX_SPI1_MISO = 5,
	kPTE1_MUX_I2C1_SCL = 6
};// __porte_bit1_mux_t;

#define rPTE_PCR16 sPORTE.PORT_PCR16.WORD
#define bPTE16_ISF sPORTE.PORT_PCR16.BITS.ISF					// Interrupt Status Flag
#define bPTE16_IRQC sPORTE.PORT_PCR16.BITS.IRQC				// Interrupt configuration
#define bPTE16_MUX sPORTE.PORT_PCR16.BITS.MUX					// Pin Mux Control
#define bPTE16_DSE sPORTE.PORT_PCR16.BITS.DSE					// Driven Strength Enable
#define bPTE16_PFE sPORTE.PORT_PCR16.BITS.PFE					// Passive Filter Enable
#define bPTE16_SRE sPORTE.PORT_PCR16.BITS.SRE					// Slew Rate Enable
#define bPTE16_PE sPORTE.PORT_PCR16.BITS.PE					// Pull Enable
#define bPTE16_PS sPORTE.PORT_PCR16.BITS.PS					// Pull Select

enum{
	kPTE16_ADC0_DP1 = 0,
	kPTE16_ADC0_SE1 = 0,
	kPTE16_MUX_GPIO = 1,
	kPTE16_MUX_SPI0_PCS0 = 2,
	kPTE16_MUX_UART2_TX = 3,
	kPTE16_MUX_TPM_CLKIN0 = 4,
	kPTE16_MUX_FXIO0_D0 = 6
};// __porte_bit16_mux_t;

#define rPTE_PCR17 sPORTE.PORT_PCR17.WORD
#define bPTE17_ISF sPORTE.PORT_PCR17.BITS.ISF					// Interrupt Status Flag
#define bPTE17_IRQC sPORTE.PORT_PCR17.BITS.IRQC				// Interrupt configuration
#define bPTE17_MUX sPORTE.PORT_PCR17.BITS.MUX					// Pin Mux Control
#define bPTE17_DSE sPORTE.PORT_PCR17.BITS.DSE					// Driven Strength Enable
#define bPTE17_PFE sPORTE.PORT_PCR17.BITS.PFE					// Passive Filter Enable
#define bPTE17_SRE sPORTE.PORT_PCR17.BITS.SRE					// Slew Rate Enable
#define bPTE17_PE sPORTE.PORT_PCR17.BITS.PE					// Pull Enable
#define bPTE17_PS sPORTE.PORT_PCR17.BITS.PS					// Pull Select

enum{
	kPTE17_MUX_ADC0_DM1 = 0,
	kPTE17_MUX_ADC0_SE5a = 0,
	kPTE17_MUX_GPIO = 1,
	kPTE17_MUX_SPI0_SCK = 2,
	kPTE17_MUX_UART2_RX = 3,
	kPTE17_MUX_TPM_CLKIN1 = 4,
	kPTE17_MUX_LPTMR0_ALT3 = 5,
	kPTE17_MUX_FXIO0_D1 = 4
};// __porte_bit17_mux_t;

#define rPTE_PCR18 sPORTE.PORT_PCR18.WORD
#define bPTE18_ISF sPORTE.PORT_PCR18.BITS.ISF					// Interrupt Status Flag
#define bPTE18_IRQC sPORTE.PORT_PCR18.BITS.IRQC				// Interrupt configuration
#define bPTE18_MUX sPORTE.PORT_PCR18.BITS.MUX					// Pin Mux Control
#define bPTE18_DSE sPORTE.PORT_PCR18.BITS.DSE					// Driven Strength Enable
#define bPTE18_PFE sPORTE.PORT_PCR18.BITS.PFE					// Passive Filter Enable
#define bPTE18_SRE sPORTE.PORT_PCR18.BITS.SRE					// Slew Rate Enable
#define bPTE18_PE sPORTE.PORT_PCR18.BITS.PE					// Pull Enable
#define bPTE18_PS sPORTE.PORT_PCR18.BITS.PS					// Pull Select

enum{
	kPTE18_ADC0_DP2 = 0,
	kPTE18_ADC0_SE2 = 0,
	kPTE18_MUX_GPIO = 1,
	kPTE18_MUX_SPI0_MOSI = 2,
	kPTE18_MUX_I2C0_SDA = 4,
	kPTE18_MUX_SPI0_MISO = 5,
	kPTE18_MUX_SPI0_FXIO0_D2 = 5
};// __porte_bit18_mux_t;


#define rPTE_PCR20 sPORTE.PORT_PCR20.WORD
#define bPTE20_ISF sPORTE.PORT_PCR20.BITS.ISF					// Interrupt Status Flag
#define bPTE20_IRQC sPORTE.PORT_PCR20.BITS.IRQC				// Interrupt configuration
#define bPTE20_MUX sPORTE.PORT_PCR20.BITS.MUX					// Pin Mux Control
#define bPTE20_DSE sPORTE.PORT_PCR20.BITS.DSE					// Driven Strength Enable
#define bPTE20_PFE sPORTE.PORT_PCR20.BITS.PFE					// Passive Filter Enable
#define bPTE20_SRE sPORTE.PORT_PCR20.BITS.SRE					// Slew Rate Enable
#define bPTE20_PE sPORTE.PORT_PCR20.BITS.PE					// Pull Enable
#define bPTE20_PS sPORTE.PORT_PCR20.BITS.PS					// Pull Select

enum{
	kPTE20_ADC0_DP0 = 0,
	kPTE20_ADC0_SE0 = 0,
	kPTE20_MUX_GPIO = 1,
	kPTE20_MUX_TPM1_CH0 = 3,
	kPTE20_MUX_LPUART0_TX = 4,
	kPTE20_MUX_FXIO0_D4 = 6
};// __porte_bit20_mux_t;

#define rPTE_PCR21 sPORTE.PORT_PCR21.WORD
#define bPTE21_ISF sPORTE.PORT_PCR21.BITS.ISF					// Interrupt Status Flag
#define bPTE21_IRQC sPORTE.PORT_PCR21.BITS.IRQC				// Interrupt configuration
#define bPTE21_MUX sPORTE.PORT_PCR21.BITS.MUX					// Pin Mux Control
#define bPTE21_DSE sPORTE.PORT_PCR21.BITS.DSE					// Driven Strength Enable
#define bPTE21_PFE sPORTE.PORT_PCR21.BITS.PFE					// Passive Filter Enable
#define bPTE21_SRE sPORTE.PORT_PCR21.BITS.SRE					// Slew Rate Enable
#define bPTE21_PE sPORTE.PORT_PCR21.BITS.PE					// Pull Enable
#define bPTE21_PS sPORTE.PORT_PCR21.BITS.PS					// Pull Select

enum{
	kPTE21_ADC0_DM0 = 0,
	kPTE21_ADC0_SE4a = 0,
	kPTE21_MUX_GPIO = 1,
	kPTE21_MUX_TPM1_CH1 = 3,
	kPTE21_MUX_LPUART0_RX = 4,
	kPTE21_MUX_FXIO0_D5 = 6
};// __porte_bit21_mux_t;

#define rPTE_PCR22 sPORTE.PORT_PCR22.WORD
#define bPTE22_ISF sPORTE.PORT_PCR22.BITS.ISF					// Interrupt Status Flag
#define bPTE22_IRQC sPORTE.PORT_PCR22.BITS.IRQC				// Interrupt configuration
#define bPTE22_MUX sPORTE.PORT_PCR22.BITS.MUX					// Pin Mux Control
#define bPTE22_DSE sPORTE.PORT_PCR22.BITS.DSE					// Driven Strength Enable
#define bPTE22_PFE sPORTE.PORT_PCR22.BITS.PFE					// Passive Filter Enable
#define bPTE22_SRE sPORTE.PORT_PCR22.BITS.SRE					// Slew Rate Enable
#define bPTE22_PE sPORTE.PORT_PCR22.BITS.PE					// Pull Enable
#define bPTE22_PS sPORTE.PORT_PCR22.BITS.PS					// Pull Select

enum{
	kPTE22_ADC0_DP3 = 0,
	kPTE22_ADC0_SE3 = 0,
	kPTE22_MUX_GPIO = 1,
	kPTE22_MUX_TPM2_CH0 = 3,
	kPTE22_MUX_UART2_TX = 4,
	kPTE22_MUX_FXIO0_D6 = 6
};// __porte_bit22_mux_t;

#define rPTE_PCR23 sPORTE.PORT_PCR23.WORD
#define bPTE23_ISF sPORTE.PORT_PCR23.BITS.ISF					// Interrupt Status Flag
#define bPTE23_IRQC sPORTE.PORT_PCR23.BITS.IRQC				// Interrupt configuration
#define bPTE23_MUX sPORTE.PORT_PCR23.BITS.MUX					// Pin Mux Control
#define bPTE23_DSE sPORTE.PORT_PCR23.BITS.DSE					// Driven Strength Enable
#define bPTE23_PFE sPORTE.PORT_PCR23.BITS.PFE					// Passive Filter Enable
#define bPTE23_SRE sPORTE.PORT_PCR23.BITS.SRE					// Slew Rate Enable
#define bPTE23_PE sPORTE.PORT_PCR23.BITS.PE					// Pull Enable
#define bPTE23_PS sPORTE.PORT_PCR23.BITS.PS					// Pull Select

enum{
	kPTE23_ADC0_DM3 = 0,
	kPTE23_ADC0_SE7a = 0,
	kPTE23_MUX_GPIO = 1,
	kPTE23_MUX_TPM2_CH1 = 3,
	kPTE23_MUX_UART2_RX = 4,
	kPTE23_MUX_FXIO0_D7 = 6
};// __porte_bit23_mux_t;

#define rPTE_PCR24 sPORTE.PORT_PCR24.WORD
#define bPTE24_ISF sPORTE.PORT_PCR24.BITS.ISF					// Interrupt Status Flag
#define bPTE24_IRQC sPORTE.PORT_PCR24.BITS.IRQC				// Interrupt configuration
#define bPTE24_MUX sPORTE.PORT_PCR24.BITS.MUX					// Pin Mux Control
#define bPTE24_DSE sPORTE.PORT_PCR24.BITS.DSE					// Driven Strength Enable
#define bPTE24_PFE sPORTE.PORT_PCR24.BITS.PFE					// Passive Filter Enable
#define bPTE24_SRE sPORTE.PORT_PCR24.BITS.SRE					// Slew Rate Enable
#define bPTE24_PE sPORTE.PORT_PCR24.BITS.PE					// Pull Enable
#define bPTE24_PS sPORTE.PORT_PCR24.BITS.PS					// Pull Select

enum{
	kPTE24_MUX_GPIO = 1,
	kPTE24_MUX_TPM0_CH0 = 3,
	kPTE24_MUX_I2C0_SCL = 5
};// __porte_bit24_mux_t;

#define rPTE_PCR25 sPORTE.PORT_PCR25.WORD
#define bPTE25_ISF sPORTE.PORT_PCR25.BITS.ISF					// Interrupt Status Flag
#define bPTE25_IRQC sPORTE.PORT_PCR25.BITS.IRQC				// Interrupt configuration
#define bPTE25_MUX sPORTE.PORT_PCR25.BITS.MUX					// Pin Mux Control
#define bPTE25_DSE sPORTE.PORT_PCR25.BITS.DSE					// Driven Strength Enable
#define bPTE25_PFE sPORTE.PORT_PCR25.BITS.PFE					// Passive Filter Enable
#define bPTE25_SRE sPORTE.PORT_PCR25.BITS.SRE					// Slew Rate Enable
#define bPTE25_PE sPORTE.PORT_PCR25.BITS.PE					// Pull Enable
#define bPTE25_PS sPORTE.PORT_PCR25.BITS.PS					// Pull Select

enum{
	kPTE25_MUX_GPIO = 1,
	kPTE25_MUX_TPM0_CH1 = 3,
	kPTE25_MUX_I2C0_SDA = 5
};// __porte_bit24_mux_t;

#define rPTE_PCR29 sPORTE.PORT_PCR29.WORD
#define bPTE29_ISF sPORTE.PORT_PCR29.BITS.ISF					// Interrupt Status Flag
#define bPTE29_IRQC sPORTE.PORT_PCR29.BITS.IRQC				// Interrupt configuration
#define bPTE29_MUX sPORTE.PORT_PCR29.BITS.MUX					// Pin Mux Control
#define bPTE29_DSE sPORTE.PORT_PCR29.BITS.DSE					// Driven Strength Enable
#define bPTE29_PFE sPORTE.PORT_PCR29.BITS.PFE					// Passive Filter Enable
#define bPTE29_SRE sPORTE.PORT_PCR29.BITS.SRE					// Slew Rate Enable
#define bPTE29_PE sPORTE.PORT_PCR29.BITS.PE					// Pull Enable
#define bPTE29_PS sPORTE.PORT_PCR29.BITS.PS					// Pull Select

enum{
	kPTE29_MUX_GPIO = 1,
	kPTE29_MUX_TPM0_CH2 = 3,
	kPTE29_MUX_TPM_CLKIN0 = 4
};// __porte_bit29_mux_t;

#define rPTE_PCR30 sPORTE.PORT_PCR30.WORD
#define bPTE30_ISF sPORTE.PORT_PCR30.BITS.ISF					// Interrupt Status Flag
#define bPTE30_IRQC sPORTE.PORT_PCR30.BITS.IRQC				// Interrupt configuration
#define bPTE30_MUX sPORTE.PORT_PCR30.BITS.MUX					// Pin Mux Control
#define bPTE30_DSE sPORTE.PORT_PCR30.BITS.DSE					// Driven Strength Enable
#define bPTE30_PFE sPORTE.PORT_PCR30.BITS.PFE					// Passive Filter Enable
#define bPTE30_SRE sPORTE.PORT_PCR30.BITS.SRE					// Slew Rate Enable
#define bPTE30_PE sPORTE.PORT_PCR30.BITS.PE					// Pull Enable
#define bPTE30_PS sPORTE.PORT_PCR30.BITS.PS					// Pull Select

enum{
	kPTE30_MUX_GPIO = 1,
	kPTE30_MUX_TPM0_CH3 = 3,
	kPTE30_MUX_TPM_CLKIN0 = 4,
	kPTE30_MUX_LPUART1_TX = 5,
	kPTE30_MUX_LPTMR0_ALT1 = 6
};// __porte_bit30_mux_t;

#define rPTE_PCR31 sPORTE.PORT_PCR31.WORD
#define bPTE31_ISF sPORTE.PORT_PCR31.BITS.ISF					// Interrupt Status Flag
#define bPTE31_IRQC sPORTE.PORT_PCR31.BITS.IRQC				// Interrupt configuration
#define bPTE31_MUX sPORTE.PORT_PCR31.BITS.MUX					// Pin Mux Control
#define bPTE31_DSE sPORTE.PORT_PCR31.BITS.DSE					// Driven Strength Enable
#define bPTE31_PFE sPORTE.PORT_PCR31.BITS.PFE					// Passive Filter Enable
#define bPTE31_SRE sPORTE.PORT_PCR31.BITS.SRE					// Slew Rate Enable
#define bPTE31_PE sPORTE.PORT_PCR31.BITS.PE					// Pull Enable
#define bPTE31_PS sPORTE.PORT_PCR31.BITS.PS					// Pull Select

enum{
	kPTE31_MUX_GPIO = 1,
	kPTE31_MUX_RPM0_CH4 = 3
};// __porte_bit31_mux_t;

#define rPTE_GPCLR sPORTE.PORT_GPCLR.WORD
#define bPTE_GPCLR_GPWD sPORTE.PORT_GPCLR.SHORT.GPWD
#define bPTE_GPCLR_GPWE sPORTE.PORT_GPCLR.SHORT.GPWE

#define bPTE0_DATA  sPORTE.PORT_GPCLR.BITS.PTE0_DATA	    	// Global Pin PTE0 Write Data
#define bPTE1_DATA  sPORTE.PORT_GPCLR.BITS.PTE1_DATA	    	// Global Pin PTE1 Write Data

#define bPTE0_WE    sPORTE.PORT_GPCLR.BITS.PTE0_WE	    		// Global Pin PTE0 Write Enable
#define bPTE1_WE    sPORTE.PORT_GPCLR.BITS.PTE1_WE	    		// Global Pin PTE1 Write Enable

// PORTE_GPCHR
#define rPTE_GPCHR sPORTE.PORT_GPCHR.WORD 						// Global Pin Control High Register
#define bPTE_GPCHR_GPWD sPORTE.PORT_GPCHR.Shorts.GPWD
#define bPTE_GPCHR_GPWE sPORTE.PORT_GPCHR.Shorts.GPWE

#define bPTE16_DATA sPORTE.PORT_GPCHR.BITS.PTE16_DATA	    	// Global Pin PTE16 Write Data
#define bPTE17_DATA sPORTE.PORT_GPCHR.BITS.PTE17_DATA    		// Global Pin PTE17 Write Data
#define bPTE18_DATA sPORTE.PORT_GPCHR.BITS.PTE18_DATA	    	// Global Pin PTE18 Write Data
#define bPTE19_DATA sPORTE.PORT_GPCHR.BITS.PTE19_DATA    		// Global Pin PTE19 Write Data
#define bPTE20_DATA sPORTE.PORT_GPCHR.BITS.PTE20_DATA	    	// Global Pin PTE20 Write Data
#define bPTE21_DATA sPORTE.PORT_GPCHR.BITS.PTE21_DATA	    	// Global Pin PTE21 Write Data
#define bPTE22_DATA sPORTE.PORT_GPCHR.BITS.PTE22_DATA	    	// Global Pin PTE22 Write Data
#define bPTE23_DATA sPORTE.PORT_GPCHR.BITS.PTE23_DATA	    	// Global Pin PTE23 Write Data
#define bPTE24_DATA sPORTE.PORT_GPCHR.BITS.PTE24_DATA	    	// Global Pin PTE24 Write Data
#define bPTE25_DATA sPORTE.PORT_GPCHR.BITS.PTE25_DATA	    	// Global Pin PTE25 Write Data
#define bPTE29_DATA sPORTE.PORT_GPCHR.BITS.PTE29_DATA	    	// Global Pin PTE29 Write Data
#define bPTE30_DATA sPORTE.PORT_GPCHR.BITS.PTE30_DATA	    	// Global Pin PTE30 Write Data
#define bPTE31_DATA sPORTE.PORT_GPCHR.BITS.PTE31_DATA	    	// Global Pin PTE31 Write Data

#define bPTE16_WE   sPORTE.PORT_GPCHR.BITS.PTE16_WE	    	// Global Pin PTE16 Write Enable
#define bPTE17_WE   sPORTE.PORT_GPCHR.BITS.PTE17_WE	    	// Global Pin PTE17 Write Enable
#define bPTE18_WE   sPORTE.PORT_GPCHR.BITS.PTE18_WE	    	// Global Pin PTE18 Write Enable
#define bPTE19_WE   sPORTE.PORT_GPCHR.BITS.PTE19_WE	    	// Global Pin PTE19 Write Enable
#define bPTE20_WE   sPORTE.PORT_GPCHR.BITS.PTE20_WE	    	// Global Pin PTE20 Write Enable
#define bPTE21_WE   sPORTE.PORT_GPCHR.BITS.PTE21_WE	    	// Global Pin PTE21 Write Enable
#define bPTE22_WE   sPORTE.PORT_GPCHR.BITS.PTE22_WE	    	// Global Pin PTE22 Write Enable
#define bPTE23_WE   sPORTE.PORT_GPCHR.BITS.PTE23_WE	    	// Global Pin PTE23 Write Enable
#define bPTE24_WE   sPORTE.PORT_GPCHR.BITS.PTE24_WE	    	// Global Pin PTE24 Write Enable
#define bPTE25_WE   sPORTE.PORT_GPCHR.BITS.PTE25_WE	    	// Global Pin PTE25 Write Enable
#define bPTE29_WE   sPORTE.PORT_GPCHR.BITS.PTE29_WE	    	// Global Pin PTE29 Write Enable
#define bPTE30_WE   sPORTE.PORT_GPCHR.BITS.PTE30_WE	    	// Global Pin PTE30 Write Enable
#define bPTE31_WE   sPORTE.PORT_GPCHR.BITS.PTE31_WE	    	// Global Pin PTE31 Write Enable

// PORTE_ISFR
#define rPTE_ISFR sPORTE.PORT_ISFR.WORD 						// Interrupt Status Flag Register

#define bPTE0_ISFR  sPORTE.PORT_ISFR.BITS.PTE0_ISR				// Pin PTE0 Interrupt Status Flag
#define bPTE1_ISFR  sPORTE.PORT_ISFR.BITS.PTE1_ISR				// Pin PTE1 Interrupt Status Flag
#define bPTE16_ISFR sPORTE.PORT_ISFR.BITS.PTE16_ISR			// Pin PTE16 Interrupt Status Flag
#define bPTE17_ISFR sPORTE.PORT_ISFR.BITS.PTE17_ISR			// Pin PTE17 Interrupt Status Flag
#define bPTE18_ISFR sPORTE.PORT_ISFR.BITS.PTE18_ISR			// Pin PTE18 Interrupt Status Flag
#define bPTE19_ISFR sPORTE.PORT_ISFR.BITS.PTE19_ISR			// Pin PTE19 Interrupt Status Flag
#define bPTE20_ISFR sPORTE.PORT_ISFR.BITS.PTE20_ISR			// Pin PTE20 Interrupt Status Flag
#define bPTE21_ISFR sPORTE.PORT_ISFR.BITS.PTE21_ISR			// Pin PTE21 Interrupt Status Flag
#define bPTE22_ISFR sPORTE.PORT_ISFR.BITS.PTE22_ISR	    	// Pin PTE22 Interrupt Status Flag
#define bPTE23_ISFR sPORTE.PORT_ISFR.BITS.PTE23_ISR	    	// Pin PTE23 Interrupt Status Flag
#define bPTE24_ISFR sPORTE.PORT_ISFR.BITS.PTE24_ISR	    	// Pin PTE24 Interrupt Status Flag
#define bPTE25_ISFR sPORTE.PORT_ISFR.BITS.PTE25_ISR			// Pin PTE25 Interrupt Status Flag
#define bPTE29_ISFR sPORTE.PORT_ISFR.BITS.PTE29_ISR	    	// Pin PTE29 Interrupt Status Flag
#define bPTE30_ISFR sPORTE.PORT_ISFR.BITS.PTE30_ISR	    	// Pin PTE30 Interrupt Status Flag
#define bPTE31_ISFR sPORTE.PORT_ISFR.BITS.PTE31_ISR	    	// Pin PTE31 Interrupt Status Flag

#endif /* PORT_LIB_H_ */
