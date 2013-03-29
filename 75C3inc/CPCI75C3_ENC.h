/*+++

Copyright (c) 2010 North Atlantic Industries,

File Name:

 CPCI75C3_ENC.h

Description:

 Include file to the CPCI75C3 - Encoder Module Interface.
 
 This was written in ANSI 'C' for 32-bit integers.

Author: 
Date:  
History:

---*/

#ifndef _CPCI75C3_ENC_H
#define _CPCI75C3_ENC_H

#include "CPCI75C3_include.h"         

#ifdef __cplusplus
extern "C" {
#endif 


/*****************************/
/*** ENC Module Registers  ***/
/*****************************/

/*SSI Mode, Channels 1 to 4*/
#define CPCI75C3_REG_ENC_SSI_CTRL_0 {\
 (0x000 << ADDR_SHIFT), (0x040 << ADDR_SHIFT), (0x080 << ADDR_SHIFT), (0x0C0 << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_SSI_CTRL_1 {\
 (0x002 << ADDR_SHIFT), (0x042 << ADDR_SHIFT), (0x082 << ADDR_SHIFT), (0x0C2 << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_SSI_RCVDATA_HI {\
 (0x008 << ADDR_SHIFT), (0x048 << ADDR_SHIFT), (0x088 << ADDR_SHIFT), (0x0C8 << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_SSI_RCVDATA_LO {\
 (0x00A << ADDR_SHIFT), (0x04A << ADDR_SHIFT), (0x08A << ADDR_SHIFT), (0x0CA << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_SSI_RCVPARITY {\
 (0x00C << ADDR_SHIFT), (0x04C << ADDR_SHIFT), (0x08C << ADDR_SHIFT), (0x0CC << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_SSI_STATUS {\
 (0x00E << ADDR_SHIFT), (0x04E << ADDR_SHIFT), (0x08E << ADDR_SHIFT), (0x0CE << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_SSI_RCVDATA_GRAY_HI {\
 (0x01C << ADDR_SHIFT), (0x05C << ADDR_SHIFT), (0x09C << ADDR_SHIFT), (0x0DC << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_SSI_RCVDATA_GRAY_LO {\
 (0x01E << ADDR_SHIFT), (0x05E << ADDR_SHIFT), (0x09E << ADDR_SHIFT), (0x0DE << ADDR_SHIFT)\
}

/*Counter Mode, Channels 1 to 4*/
#define CPCI75C3_REG_ENC_CTR_MATCHDATA_HI {\
 (0x020 << ADDR_SHIFT), (0x060 << ADDR_SHIFT), (0x0A0 << ADDR_SHIFT), (0x0E0 << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_CTR_MATCHDATA_LO {\
 (0x022 << ADDR_SHIFT), (0x062 << ADDR_SHIFT), (0x0A2 << ADDR_SHIFT), (0x0E2 << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_CTR_PRELOAD_HI {\
 (0x024 << ADDR_SHIFT), (0x064 << ADDR_SHIFT), (0x0A4 << ADDR_SHIFT), (0x0E4 << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_CTR_PRELOAD_LO {\
 (0x026 << ADDR_SHIFT), (0x066 << ADDR_SHIFT), (0x0A6 << ADDR_SHIFT), (0x0E6 << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_CTR_CONTROL_REG {\
 (0x02A << ADDR_SHIFT), (0x06A << ADDR_SHIFT), (0x0AA << ADDR_SHIFT), (0x0EA << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_CTR_CMD_REG {\
 (0x02C << ADDR_SHIFT), (0x06C << ADDR_SHIFT), (0x0AC << ADDR_SHIFT), (0x0EC << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_CTR_STATUS {\
 (0x02E << ADDR_SHIFT), (0x06E << ADDR_SHIFT), (0x0AE << ADDR_SHIFT), (0x0EE << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_CTR_VALUE_HI {\
 (0x034 << ADDR_SHIFT), (0x074 << ADDR_SHIFT), (0x0B4 << ADDR_SHIFT), (0x0F4 << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_CTR_VALUE_LO {\
 (0x036 << ADDR_SHIFT), (0x076 << ADDR_SHIFT), (0x0B6 << ADDR_SHIFT), (0x0F6 << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_CTR_LATCH_HI {\
 (0x03C << ADDR_SHIFT), (0x07C << ADDR_SHIFT), (0x0BC << ADDR_SHIFT), (0x0FC << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_CTR_LATCH_LO {\
 (0x03E << ADDR_SHIFT), (0x07E << ADDR_SHIFT), (0x0BE << ADDR_SHIFT), (0x0FE << ADDR_SHIFT)\
}

/*CPLD Configuration, Channels 1 to 4 */
#define CPCI75C3_REG_ENC_CPLD_CONFIG_HI {\
 (0x1E0 << ADDR_SHIFT), (0x1E8 << ADDR_SHIFT), (0x1F0 << ADDR_SHIFT), (0x1F8 << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_CPLD_CONFIG_LO {\
 (0x1E2 << ADDR_SHIFT), (0x1EA << ADDR_SHIFT), (0x1F2 << ADDR_SHIFT), (0x1FA << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_CPLD_STATUS {\
 (0x1E4 << ADDR_SHIFT), (0x1EC << ADDR_SHIFT), (0x1F4 << ADDR_SHIFT), (0x1FC << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_CPLD_SINGLE_ENDED {\
 (0x1E6 << ADDR_SHIFT), (0x1EE << ADDR_SHIFT), (0x1F6 << ADDR_SHIFT), (0x1FE << ADDR_SHIFT)\
}

/*Debounce Configuration, Channels 1 to 4 */
#define CPCI75C3_REG_ENC_DEBOUNCE_A {\
 (0x160 << ADDR_SHIFT), (0x180 << ADDR_SHIFT), (0x1A0 << ADDR_SHIFT), (0x1C0 << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_DEBOUNCE_EN_A {\
 (0x162 << ADDR_SHIFT), (0x182 << ADDR_SHIFT), (0x1A2 << ADDR_SHIFT), (0x1C2 << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_DEBOUNCE_B {\
 (0x168 << ADDR_SHIFT), (0x188 << ADDR_SHIFT), (0x1A8 << ADDR_SHIFT), (0x1C8 << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_DEBOUNCE_EN_B {\
 (0x16A << ADDR_SHIFT), (0x18A << ADDR_SHIFT), (0x1AA << ADDR_SHIFT), (0x1CA << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_DEBOUNCE_IDX {\
 (0x170 << ADDR_SHIFT), (0x190 << ADDR_SHIFT), (0x1B0 << ADDR_SHIFT), (0x1D0 << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_DEBOUNCE_EN_IDX {\
 (0x172 << ADDR_SHIFT), (0x192 << ADDR_SHIFT), (0x1B2 << ADDR_SHIFT), (0x1D2 << ADDR_SHIFT)\
}

/*Interval Timer Configuration, Module*/
#define CPCI75C3_REG_ENC_INT_TIMER_PRELD {\
 (0x120 << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_INT_TIMER_CNTRL {\
 (0x122 << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_INT_TIMER_DATAREG {\
 (0x138 << ADDR_SHIFT)\
}
/*Prescale interval timer clock, Mask Interval Timer Control word with bits 0xFFF9 before setting*/
#define INT_TIMER_25MHZ       0x00 /*40ns*/
#define INT_TIMER_12_5MHZ     0x02 /*80ns*/
#define INT_TIMER_6_25MHZ     0x04 /*160ns*/
#define INT_TIMER_3_125MHZ    0x06 /*320ns*/
/*Interval timer enable, Mask Interval Timer Control word with bits 0xFFFE before setting*/
#define INT_TIMER_ENABLE       0x0001 /*Mask-OR with Int timer ctrl word to enable*/
#define INT_TIMER_DISABLE      0xFFFE /*Mask-AND with Int timer ctrl wd to disable*/

/*Global Register Configuration, Module*/
#define CPCI75C3_REG_ENC_GLOBAL_REG_HI {\
 (0x140 << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_GLOBAL_REG_LO {\
 (0x142 << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_GLOBAL_REG_INTR_ENAB {\
 (0x144 << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_GLOBAL_REG_INTR_STATUS {\
 (0x148 << ADDR_SHIFT)\
}
#define CPCI75C3_REG_ENC_GLOBAL_REG_TESTREG {\
 (0x15E << ADDR_SHIFT)\
}

/*Module Revision Reg  (note: defined per channel, but revision will be the same on all channels within module*/
#define CPCI75C3_REG_ENC_MODULE_REVISION {\
 (0x1E4 << ADDR_SHIFT), (0x1EC << ADDR_SHIFT), (0x1F4 << ADDR_SHIFT), (0x1FC << ADDR_SHIFT)\
}

/******   ENC bit definitions ******/

/* ENC_COUNTER_STATUS BIT POSITION DEFINITIONS, R/W capable (Write 1 to bit position to reset specific status bit */
#define CTR_STAT_OVERFLOWBIT     0x40
#define CTR_STAT_DATALATCHBIT    0x20
#define CTR_STAT_MATCH_BIT       0x04
#define CTR_STAT_CARRY_BIT       0x02
#define CTR_STAT_BORROW_BIT      0x01

#define CPLD_TESTMODE_MASK       0x1000 /*Wrap Port A input to Port Idx output*/

/*Output Mode selection parameters*/
#define RECEIVE_A    0
#define TRANSMIT_A   1
#define RECEIVE_B    0
#define TRANSMIT_B   1
#define RECEIVE_I    0
#define TRANSMIT_I   1

/*Bit Masks*/
#define CPLD_OUTPUTMODE_A_FIELD_MASK 0x0002 /*Field mask for Port A output driver enable*/
#define CPLD_TRANSMITMODE_A_MASK 0x0002 /*Turn on Port A output driver*/
#define CPLD_RECEIVEMODE_A_MASK  0x0000 /*Port A output driver disabled*/
#define CPLD_OUTPUTMODE_B_FIELD_MASK 0x0020 /*Field mask for Port B output driver enable*/
#define CPLD_TRANSMITMODE_B_MASK 0x0020 /*Turn on Port B output driver*/
#define CPLD_RECEIVEMODE_B_MASK  0x0000 /*Port B output driver disabled*/
#define CPLD_OUTPUTMODE_I_FIELD_MASK 0x0200 /*Field mask for Port Idx output driver enable*/
#define CPLD_TRANSMITMODE_I_MASK 0x0200 /*Turn on Port Idx output driver*/
#define CPLD_RECEIVEMODE_I_MASK  0x0000 /*Port Idx output driver disabled*/

#define CPLD_HIGHVOLT_A_MASK     0x000C /*Switch in 7.5k ohm series resistor for high voltage inputs*/
#define CPLD_HIGHVOLT_B_MASK     0x00C0
#define CPLD_HIGHVOLT_I_MASK     0x0C00
#define CPLD_TERMINATION_A_MASK  0x0001 /*Switch in 120 ohm termination resistor*/
#define CPLD_TERMINATION_B_MASK  0x0010
#define CPLD_TERMINATION_I_MASK  0x0100
#define CPLD_ENABLEOUTPUT_A_MASK 0x0002 /*Enable output driver for channel*/
#define CPLD_ENABLEOUTPUT_B_MASK 0x0020
#define CPLD_ENABLEOUTPUT_I_MASK 0x0200

/*IFC Selection parameters*/
#define IFC_CHAN_DISABLED    0
#define IFC_SSI_MODE         1
#define IFC_COUNTER_MODE     2

/*Bit Masks*/
#define IFC_FIELD_MASK              0x3
#define IFC_CHAN_DISABLE_MASK 0x0
#define IFC_SSI_MODE_MASK     0x1
#define IFC_COUNTER_MODE_MASK 0x2     

/*Test2 Selection parameters*/
#define TEST2_DISABLED     0
#define TEST2_ENABLED      1
/*Bit Masks*/
#define TEST2_FIELD_MASK            0x1000
#define TEST2_DISABLED_MASK   0x0000
#define TEST2_ENABLED_MASK    0x1000

/*Test2 Mode selection parameters*/
 #define TESTMODE_12_5MHZ        0
 #define TESTMODE_6_25MHZ        1
 #define TESTMODE_INTVL_TIMER    2
 #define TESTMODE_LOOPBACK       3
/*Bit Masks*/
#define TESTMODE_FIELD_MASK               0x0300
#define TESTMODE_12_5MHZ_MASK          0x0000
#define TESTMODE_6_25MHZ_MASK         0x0100
#define TESTMODE_INTVL_TIMER_MASK      0x0200
#define TESTMODE_LOOPBACK_MASK         0x0300

#define STD_VOLT_INPUT_A      0
#define STD_VOLT_INPUT_B      0
#define STD_VOLT_INPUT_IDX    0
#define HIGH_VOLT_INPUT_A     1
#define HIGH_VOLT_INPUT_B     1
#define HIGH_VOLT_INPUT_IDX   1
#define TERMINATION_A         1
#define TERMINATION_B         1
#define TERMINATION_IDX       1
#define NO_TERMINATION_A      0
#define NO_TERMINATION_B      0
#define NO_TERMINATION_IDX    0

/* Counter Mode Types (CounterInputMode)*/
#define COUNTERMODE_OFF          0
#define COUNTERMODE_TIMER_UP     1
#define COUNTERMODE_TIMER_DOWN   2
#define COUNTERMODE_DIRECTION    3
#define COUNTERMODE_UPDOWN       4
#define COUNTERMODE_QUAD_1X      5
#define COUNTERMODE_QUAD_2X      6
#define COUNTERMODE_QUAD_4X      7

#define CIM_FIELD_MASK           0x0007
#define CIM_COUNTERMODE_OFF_MASK 0x0000
#define CIM_TIMER_UP_MASK        0x0001
#define CIM_TIMER_DOWN_MASK      0x0002
#define CIM_DIRECTION_MASK       0x0003
#define CIM_UPDOWN_MASK          0x0004
#define CIM_QUAD_1X_MASK         0x0005
#define CIM_QUAD_2X_MASK         0x0006
#define CIM_QUAD_4X_MASK         0x0007

/*Index control mode parameters (IndexControlMode)*/
#define INDEXMODE_OFF            0
#define INDEXMODE_LOAD_ON_I      1
#define INDEXMODE_LATCH_ON_I     2
#define INDEXMODE_GATE_ON_I      3
#define INDEXMODE_RESET_ON_I     4

#define ICM_FIELD_MASK           0x1C00
#define ICM_IGNORE_MASK          0x0000
#define ICM_LOAD_MASK            0x0400
#define ICM_LATCH_MASK           0x0800
#define ICM_GATE_MASK            0x0C00
#define ICM_RESET_MASK           0x1000

/*Counter input polarity type parameters (Polarity_A, Polarity_B, Polarity_I)*/
/* Positive polarity is active high / rising edge / level high depending on context of use (operational mode)*/
/* Negative polarity is active low / falling edge / level low */
#define POL_POS   0
#define POL_NEG   1

#define POL_I_FIELD_MASK      0x0200
#define POL_I_POS_MASK        0x0000
#define POL_I_NEG_MASK        0x0200

#define POL_B_FIELD_MASK      0x0100
#define POL_B_POS_MASK        0x0000
#define POL_B_NEG_MASK        0x0100

#define POL_A_FIELD_MASK      0x0080
#define POL_A_POS_MASK        0x0000
#define POL_A_NEG_MASK        0x0080

/*Special count mode parameters (SpecialCountMode)*/
#define SPECNT_MODE_OFF    0
#define SPECNT_NDIVIDE     1
#define SPECNT_SINGLE      2

#define SCM_FIELD_MASK           0x0060
#define SCM_OFF_MASK             0x0000
#define SCM_NDIV_MASK            0x0020
#define SCM_SINGLE_MASK          0x0040

/*Clock Divider parameters (ClockDivide)*/
#define CLOCK_50MHZ        0
#define CLOCK_25MHZ        1
#define CLOCK_12_5MHZ      2
#define CLOCK_6_25MHZ      3

#define CLKDIV_FIELD_MASK        0x0018
#define CLKDIV_50MHZ_MASK        0x0000
#define CLKDIV_25MHZ_MASK        0x0008
#define CLKDIV_12_5MHZ_MASK      0x0010
#define CLKDIV_6_25MHZ_MASK      0x0018

#define CPCI75C3_ENC_MAX_DEBOUNCE_TIME          0.0013107 /* Units, Seconds (1.31ms) 0xFFFF x CPCI75C3_ENC_DEBOUNCE_TIME_LSB sec */
#define CPCI75C3_ENC_DEBOUNCE_TIME_LSB     20E-9	/* Units,Seconds (20ns) */
#define CPCI75C3_ENC_DAC_OFFSET_LSB     0.0147059 /*(5V / 2^8) with voltage divider reduction(7.5k/(2.49+7.5k))*/	/* Units,Seconds (20ns) */

/*==========================================================================================*/
#define CPCI75C3_ENC_MAX_CHAN       4


/******   ENC Utility   ******/
_75C3FUNC int CPCI75C3_ENC_GetMaxChan( unsigned short ModuleID, int *MaxChan );
_75C3FUNC int CPCI75C3_ENC_CheckCardModuleChannel(int Card, int Module, int Channel );
_75C3FUNC int CPCI75C3_ENC_GetDesignVersion( int Card, int Module, unsigned short *Version );
_75C3FUNC int CPCI75C3_ENC_GetDesignRevision( int Card, int Module, unsigned short *Revision );

/******   Global Controls   ******/
_75C3FUNC int CPCI75C3_ENC_SetGlobalControlRegHi( int Card, int Module, unsigned short GlobalControlRegHi );
_75C3FUNC int CPCI75C3_ENC_GetGlobalControlRegHi( int Card, int Module, unsigned short *GlobalControlRegHi );
_75C3FUNC int CPCI75C3_ENC_SetGlobalControlRegLo( int Card, int Module, unsigned short GlobalControlRegHi );
_75C3FUNC int CPCI75C3_ENC_GetGlobalControlRegLo( int Card, int Module, unsigned short *GlobalControlRegHi );
_75C3FUNC int CPCI75C3_ENC_SetGlobalControls( int Card, int Module, int Channel, short IFCMode, short Test2, short TestSel );
_75C3FUNC int CPCI75C3_ENC_GetGlobalControls( int Card, int Module, int Channel, short *IFCMode, short *Test2, short *TestSel );

/******   Test   ******/
_75C3FUNC int CPCI75C3_ENC_GetTestReg( int Card, int Module, unsigned short *TestReg );

/******   Interval Timer   ******/
_75C3FUNC int CPCI75C3_ENC_GetIntervalTimerData( int Card, int Module, unsigned short *IntervalTimerData );
_75C3FUNC int CPCI75C3_ENC_SetIntervalTimerControl( int Card, int Module, unsigned short IntervalTimerControl );
_75C3FUNC int CPCI75C3_ENC_GetIntervalTimerControl( int Card, int Module, unsigned short *IntervalTimerControl );
_75C3FUNC int CPCI75C3_ENC_SetIntervalTimerPreload( int Card, int Module, unsigned short IntervalTimerPreload );
_75C3FUNC int CPCI75C3_ENC_GetIntervalTimerPreload( int Card, int Module, unsigned short *IntervalTimerPreload );

/******   Counter   ******/
_75C3FUNC int CPCI75C3_ENC_SetCounterCommandReg(int nCard, int nModNum, int nChannelNum, unsigned short CommandData);
_75C3FUNC int CPCI75C3_ENC_SetCounterConfiguration(int nCard, int nModNum, int nChannelNum, unsigned int CounterPreload, unsigned short CounterCommandReg, unsigned short CounterControlReg ); /*combined command to set up counter parameters*/
_75C3FUNC int CPCI75C3_ENC_SetCounterControl(int Card, int Module, int Channel, short CounterInputMode, short IndexControlMode, short Polarity_A, short Polarity_B, short Polarity_I, short SpecialCountMode, short ClockDivide ) ;
_75C3FUNC int CPCI75C3_ENC_GetCounterControl(int Card, int Module, int Channel, short *CounterInputMode, short *IndexControlMode, short *Polarity_A, short *Polarity_B, short *Polarity_I, short *SpecialCountMode, short *ClockDivide ) ;
_75C3FUNC int CPCI75C3_ENC_SetCounterControlReg(int nCard, int nModNum, int nChannelNum, unsigned short ControlData);
_75C3FUNC int CPCI75C3_ENC_GetCounterControlReg(int nCard, int nModNum, int nChannelNum, unsigned short *ControlData);
_75C3FUNC int CPCI75C3_ENC_GetCounterValue(int nCard, int nModNum, int nChannelNum, unsigned int *CounterValue);
_75C3FUNC int CPCI75C3_ENC_SetCounterMatchData(int nCard, int nModNum, int nChannelNum, unsigned int MatchData);
_75C3FUNC int CPCI75C3_ENC_GetCounterMatchData(int nCard, int nModNum, int nChannelNum, unsigned int *MatchData);
_75C3FUNC int CPCI75C3_ENC_SetCounterPreload(int nCard, int nModNum, int nChannelNum, unsigned int PreloadData);
_75C3FUNC int CPCI75C3_ENC_GetCounterPreload(int nCard, int nModNum, int nChannelNum, unsigned int *PreloadData);
_75C3FUNC int CPCI75C3_ENC_GetCounterLatch(int nCard, int nModNum, int nChannelNum, unsigned int *CounterLatch);

/******   CPLD Configuration   ******/
_75C3FUNC int CPCI75C3_ENC_GetCPLDConfig(  int Card, int Module, int Channel, short *bTransmit_A, short *bTransmit_B, short *bTransmit_Idx, short *bHighVoltInput_A, short *bHighVoltInput_B, short *bHighVoltInput_Idx, short *bTermination_A, short *bTermination_B, short *bTermination_Idx );
_75C3FUNC int CPCI75C3_ENC_SetCPLDConfigRegister( int Card, int Module, int Channel, unsigned int ConfigWord );
_75C3FUNC int CPCI75C3_ENC_GetCPLDConfigRegister(int Card, int Module, int Channel, unsigned int *ConfigWord );
_75C3FUNC int CPCI75C3_ENC_SetCPLDConfigRegisterHi(int nCard, int nModNum, int nChannelNum, unsigned short uhHiConfigWord );
_75C3FUNC int CPCI75C3_ENC_GetCPLDConfigRegisterHi(int nCard, int nModNum, int nChannelNum, unsigned short *uhHiConfigWord );
_75C3FUNC int CPCI75C3_ENC_SetCPLDConfigRegisterLo(int nCard, int nModNum, int nChannelNum, unsigned short uhLoConfigWord );
_75C3FUNC int CPCI75C3_ENC_GetCPLDConfigRegisterLo(int nCard, int nModNum, int nChannelNum, unsigned short *uhLoConfigWord );
_75C3FUNC int CPCI75C3_ENC_SetCPLDConfig( int Card, int Module, int Channel, short bTransmit_A, short bTransmit_B, short bTransmit_Idx, short bHighVoltInput_A, short bHighVoltInput_B, short bHighVoltInput_Idx, short bTermination_A, short bTermination_B, short bTermination_Idx );
_75C3FUNC int CPCI75C3_ENC_SetCPLD_SingleEndedMode(int Card, int Module, int Channel, int SingleMode);
_75C3FUNC int CPCI75C3_ENC_GetCPLD_SingleEndedMode(int Card, int Module, int Channel, int *SingleMode);

/******   Debounce   ******/
_75C3FUNC int CPCI75C3_ENC_SetDebounceTime(int nCard, int nModNum, int nChannelNum, int nPort, double dDebounceTime );
_75C3FUNC int CPCI75C3_ENC_SetDebounceTimeWord(int Card, int Module, int Channel, int Port, unsigned short DebounceTimeWord );
_75C3FUNC int CPCI75C3_ENC_GetDebounceTime(int nCard, int nModNum, int nChannelNum, int Port, double *dDebounceTime );
_75C3FUNC int CPCI75C3_ENC_GetDebounceTimeWord(int Card, int Module, int Channel, int Port, unsigned short *DebounceTimeWord );

/******   Thresholds   ******/
_75C3FUNC int CPCI75C3_ENC_SetDACOffset(int nCard, int nModNum, int nChannelNum, double dDACOffset );
_75C3FUNC int CPCI75C3_ENC_SetDACOffsetWord(int Card, int Module, int Channel, unsigned short DACOffsetWord );
_75C3FUNC int CPCI75C3_ENC_GetDACOffset(int nCard, int nModNum, int nChannelNum, double *dDACOffset );
_75C3FUNC int CPCI75C3_ENC_GetDACOffsetWord(int Card, int Module, int Channel, unsigned short *DACOffsetWord );

/******   SSI   ******/
_75C3FUNC int CPCI75C3_ENC_GetSSIData(int nCard, int nModNum, int nChannelNum, unsigned int *SSIData);
_75C3FUNC int CPCI75C3_ENC_GetSSIDataGrayFormat(int nCard, int nModNum, int nChannelNum, unsigned int *SSIDataGrayFormat);
_75C3FUNC int CPCI75C3_ENC_SetSSIControlReg_0(int nCard, int nModNum, int nChannelNum, unsigned short ControlData);
_75C3FUNC int CPCI75C3_ENC_GetSSIControlReg_0(int nCard, int nModNum, int nChannelNum, unsigned short *ControlData);
_75C3FUNC int CPCI75C3_ENC_SetSSIControlReg_1(int nCard, int nModNum, int nChannelNum, unsigned short ControlData);
_75C3FUNC int CPCI75C3_ENC_GetSSIControlReg_1(int nCard, int nModNum, int nChannelNum, unsigned short *ControlData);
_75C3FUNC int CPCI75C3_ENC_SetSSIDataBits(int nCard, int nModNum, int nChannelNum, int DataBits);
_75C3FUNC int CPCI75C3_ENC_GetSSIDataBits(int nCard, int nModNum, int nChannelNum, int *DataBits);
_75C3FUNC int CPCI75C3_ENC_SetSSIClockRate(int nCard, int nModNum, int nChannelNum, int ClockRate);
_75C3FUNC int CPCI75C3_ENC_GetSSIClockRate(int nCard, int nModNum, int nChannelNum, int *ClockRate);
_75C3FUNC int CPCI75C3_ENC_SetSSIDwellTime(int nCard, int nModNum, int nChannelNum, int DwellTime);
_75C3FUNC int CPCI75C3_ENC_GetSSIDwellTime(int nCard, int nModNum, int nChannelNum, int *DwellTime);
_75C3FUNC int CPCI75C3_ENC_GetSSIParityWord(int nCard, int nModNum, int nChannelNum, unsigned short *SSIParityWord);
_75C3FUNC int CPCI75C3_ENC_GetSSIStatusWord(int nCard, int nModNum, int nChannelNum, unsigned short *SSIStatusWord);

/******   Status   ******/
_75C3FUNC int CPCI75C3_ENC_ClearCounterStatusBitsAll(int nCard, int nModNum, int nChannelNum);
_75C3FUNC int CPCI75C3_ENC_ClearCounterStatusBorrowBit(int nCard, int nModNum, int nChannelNum);
_75C3FUNC int CPCI75C3_ENC_ClearCounterStatusCarryBit(int nCard, int nModNum, int nChannelNum);
_75C3FUNC int CPCI75C3_ENC_ClearCounterStatusDataLatchBit (int nCard, int nModNum, int nChannelNum);
_75C3FUNC int CPCI75C3_ENC_ClearCounterStatusMatchBit(int nCard, int nModNum, int nChannelNum);
_75C3FUNC int CPCI75C3_ENC_ClearCounterStatusOverflowBit(int nCard, int nModNum, int nChannelNum);
_75C3FUNC int CPCI75C3_ENC_GetCounterStatusReg(int nCard, int nModNum, int nChannelNum, unsigned short *CounterStatusWord);
_75C3FUNC int CPCI75C3_ENC_GetCPLDStatusWord(int nCard, int nModNum, int nChannelNum, unsigned short *uhStatusWord );

/* ################################################################################################# */
/*  For Internal Use Only                                                                            */
/*  Utility functions, do not export                                                                 */
/* ################################################################################################# */
_75C3FUNC int CPCI75C3_ENC_GetModuleRev( int Card, int Module, int Channel, unsigned short *Revision ); /*Module hardware revision*/

#ifdef __cplusplus
}
#endif

#endif
