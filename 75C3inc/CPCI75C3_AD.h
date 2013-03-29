/*+++

Copyright (c) 2008 North Atlantic Industries,

File Name:

 CPCI75C3_AD.h

Description:

 Include file to the CPCI75C3 - Analog/Digital(AD) Converter Board Interface.
 This file includes the API interfaces for the C1-C4 Modules(10-channel) and 
 special KA (4-channel) A/D Modules.

 This was written in ANSI 'C' for 32-bit integers.

Author: 
Date:  
History:

---*/

#ifndef _CPCI75C3_AD_H
#define _CPCI75C3_AD_H

#include "CPCI75C3_include.h"

#ifdef __cplusplus
extern "C" {
#endif 

/*************************/
/* A/D Module Registers  */
/*************************/
#define CPCI75C3_REG_AD_DATA_ADD {\
 0x000 << ADDR_SHIFT, 0x002 << ADDR_SHIFT, 0x004 << ADDR_SHIFT,\
 0x006 << ADDR_SHIFT, 0x008 << ADDR_SHIFT, 0x00A << ADDR_SHIFT,\
 0x00C << ADDR_SHIFT, 0x00E << ADDR_SHIFT, 0x010 << ADDR_SHIFT,\
 0x012 << ADDR_SHIFT\
}

#define CPCI75C3_REG_AD_RANGE_ADD {\
 0x014 << ADDR_SHIFT, 0x016 << ADDR_SHIFT, 0x018 << ADDR_SHIFT,\
 0x01A << ADDR_SHIFT, 0x01C << ADDR_SHIFT, 0x01E << ADDR_SHIFT,\
 0x020 << ADDR_SHIFT, 0x022 << ADDR_SHIFT, 0x024 << ADDR_SHIFT,\
 0x026 << ADDR_SHIFT\
}

#define CPCI75C3_REG_AD_BREAK_FREQ_ADD {\
 0x028 << ADDR_SHIFT, 0x02A << ADDR_SHIFT, 0x02C << ADDR_SHIFT,\
 0x02E << ADDR_SHIFT, 0x030 << ADDR_SHIFT, 0x032 << ADDR_SHIFT,\
 0x034 << ADDR_SHIFT, 0x036 << ADDR_SHIFT, 0x038 << ADDR_SHIFT,\
 0x03A << ADDR_SHIFT\
}

#define CPCI75C3_REG_AD_LATCH                                         (0x0F0 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_D0_TEST_RANGE                                 (0x0F2 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_D0_TEST_VOLTAGE                               (0x0F4 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_D0_TEST_CURRENT                               (0x0F4 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_CAL_DELAY                                     (0x0F6 << ADDR_SHIFT)

/*Various Fifo Control Registers*/
#define CPCI75C3_REG_AD_FIFO_BREAK_FREQ                               (0x028 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_FIFO_AD_DATA                                  (0x100 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_FIFO_WDS_IN_BUFF                              (0x120 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_FIFO_HI_THRESHOLD                             (0x140 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_FIFO_LOW_THRESHOLD                            (0x160 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_FIFO_DELAY                                    (0x180 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_FIFO_SIZE                                     (0x1A0 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_FIFO_RATE                                     (0x1C0 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_FIFO_CLEAR                                    (0x1E0 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_FIFO_BUFF_CTRL                                (0x200 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_FIFO_TRIG_CTRL                                (0x220 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_FIFO_STATUS                                   (0x240 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_FIFO_INTERRUPT                                (0x260 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_FIFO_SOFTWARE_TRIGGER                         (0x280 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_CLK_RATE_ADDER_HI                             (0x282 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_CLK_RATE_ADDER_LOW                            (0x284 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_FIFO_RATE_MODE_CTRL                           (0x288 << ADDR_SHIFT)

#define CPCI75C3_REG_AD_CALCHAN                                       (0x360 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_PROBE2                                        (0x362 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_PROBE3                                        (0x364 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_CALSTATE_ADD {\
 0x03B0 << ADDR_SHIFT, 0x07B0 << ADDR_SHIFT, 0x0BB0 << ADDR_SHIFT,\
 0x0FB0 << ADDR_SHIFT, 0x13B0 << ADDR_SHIFT, 0x17B0 << ADDR_SHIFT\
}

#define CPCI75C3_REG_AD_TEST_ENABLE                                   (0x37C << ADDR_SHIFT)
#define CPCI75C3_REG_AD_TESTD2_VERIFY                                 (0x37E << ADDR_SHIFT)
                                                                                 
#define CPCI75C3_REG_AD_BIT_STATUS                                    (0x380 << ADDR_SHIFT)
/* 40 Volts Unit does not have the open status */
#define CPCI75C3_REG_AD_OPEN_STATUS                                   (0x382 << ADDR_SHIFT)
                                                                                 
#define CPCI75C3_REG_AD_BIT_STATUS_INT_ENAB                           (0x384 << ADDR_SHIFT)
/* 40 Volts Unit does not have the open status */                                
#define CPCI75C3_REG_AD_OPEN_STATUS_INT_ENAB                          (0x386 << ADDR_SHIFT)


#define CPCI75C3_REG_AD_CAL_RANGE                                     (0x3A8 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_CAL_RESULT_LOW_VALUE                          (0x3AA << ADDR_SHIFT)
#define CPCI75C3_REG_AD_CAL_RESULT_HI_VALUE                           (0x3AC << ADDR_SHIFT)
                                                                                 
#define CPCI75C3_REG_AD_FIFO_INT_VECT_ADD {\
 0x3C2 << ADDR_SHIFT, 0x3C4 << ADDR_SHIFT, 0x3C6 << ADDR_SHIFT,\
 0x3C8 << ADDR_SHIFT, 0x3CA << ADDR_SHIFT, 0x3CC << ADDR_SHIFT,\
 0x3CE << ADDR_SHIFT, 0x3D0 << ADDR_SHIFT, 0x3D2 << ADDR_SHIFT,\
 0x3D4 << ADDR_SHIFT\
}

#define CPCI75C3_REG_AD_INT_VECTOR_BIT                                (0x3E0 << ADDR_SHIFT)
#define CPCI75C3_REG_AD_INT_VECTOR_OPEN                               (0x3E2 << ADDR_SHIFT)

#define CPCI75C3_REG_AD_CHANID_ADD {\
 0x3C0 << ADDR_SHIFT, 0x3C2 << ADDR_SHIFT, 0x3C4 << ADDR_SHIFT,\
 0x3C6 << ADDR_SHIFT, 0x3C8 << ADDR_SHIFT, 0x3CA << ADDR_SHIFT,\
 0x3CC << ADDR_SHIFT, 0x3CE << ADDR_SHIFT, 0x3D0 << ADDR_SHIFT,\
 0x3D2 << ADDR_SHIFT\
}

/*  A/D CH1, CH2 128K Extended Buffer  */
#define CPCI75C3_REG_AD_EX_FIFO_AD_DATA {\
 0x0100 << ADDR_SHIFT, 0x0104 << ADDR_SHIFT\
}

#define CPCI75C3_REG_AD_EX_FIFO_WDS_IN_BUFF_LO_ADD {\
 0x0120 << ADDR_SHIFT, 0x0124 << ADDR_SHIFT\
}

#define CPCI75C3_REG_AD_EX_FIFO_WDS_IN_BUFF_HI_ADD {\
 0x0122 << ADDR_SHIFT, 0x0126 << ADDR_SHIFT\
}

#define CPCI75C3_REG_AD_EX_FIFO_HI_THRESHOLD_LO_ADD {\
 0x0140 << ADDR_SHIFT, 0x0144 << ADDR_SHIFT\
}
#define CPCI75C3_REG_AD_EX_FIFO_HI_THRESHOLD_HI_ADD {\
 0x0142 << ADDR_SHIFT, 0x0146 << ADDR_SHIFT\
}

#define CPCI75C3_REG_AD_EX_FIFO_LOW_THRESHOLD_LO_ADD {\
 0x0160 << ADDR_SHIFT, 0x0164 << ADDR_SHIFT\
}

#define CPCI75C3_REG_AD_EX_FIFO_LOW_THRESHOLD_HI_ADD {\
 0x0162 << ADDR_SHIFT, 0x0166 << ADDR_SHIFT\
}

#define CPCI75C3_REG_AD_EX_FIFO_DELAY {\
 0x0180 << ADDR_SHIFT, 0x0184 << ADDR_SHIFT\
}

#define CPCI75C3_REG_AD_EX_FIFO_SIZE_LO_ADD {\
 0x01A0 << ADDR_SHIFT, 0x01A4 << ADDR_SHIFT\
}

#define CPCI75C3_REG_AD_EX_FIFO_SIZE_HI_ADD {\
 0x01A2 << ADDR_SHIFT, 0x01A6 << ADDR_SHIFT\
}

#define CPCI75C3_REG_AD_EX_FIFO_RATE {\
 0x01C0 << ADDR_SHIFT, 0x01C4 << ADDR_SHIFT\
}

#define CPCI75C3_REG_AD_EX_FIFO_CLEAR {\
 0x01E0 << ADDR_SHIFT, 0x01E4 << ADDR_SHIFT\
}

#define CPCI75C3_REG_AD_EX_FIFO_BUFF_CTRL {\
 0x0200 << ADDR_SHIFT, 0x0204 << ADDR_SHIFT\
}

#define CPCI75C3_REG_AD_EX_FIFO_TRIG_CTRL {\
 0x0220 << ADDR_SHIFT, 0x0224 << ADDR_SHIFT\
}

#define CPCI75C3_REG_AD_EX_FIFO_STATUS {\
 0x0240 << ADDR_SHIFT, 0x0244 << ADDR_SHIFT\
}

#define CPCI75C3_REG_AD_EX_FIFO_INTERRUPT {\
 0x0260 << ADDR_SHIFT, 0x0264 << ADDR_SHIFT\
}

#define CPCI75C3_REG_AD_EX_FIFO_INT_VECT_ADD {\
 0x03C2 << ADDR_SHIFT, 0x03C6 << ADDR_SHIFT\
}

/************************************************/
/* A/D Module Registers (specific to KA module) */
/************************************************/
#define CPCI75C3_REG_AD_KA_DATA_ADD {\
 0x2CC, 0x2D0, 0x2D4, 0x2D8\
}

#define CPCI75C3_REG_AD_KA_RANGE_ADD {\
 0x2DC, 0x2E0, 0x2E4, 0x2E8\
}

#define CPCI75C3_REG_AD_KA_BIT_STATUS                               0x6F4
#define CPCI75C3_REG_AD_KA_BIT_STATUS_INT_ENAB                      0x39C
#define CPCI75C3_REG_AD_KA_INT_VECTOR_BIT                           0x7F4


/*Range Defined for A/D by Spec */
#define UNIPOLAR_RANGE_10V_12x5V   0
#define UNIPOLAR_RANGE_5V_6x25V    1
#define UNIPOLAR_RANGE_2_5V        2
#define UNIPOLAR_RANGE_1_25V       3
#define UNIPOLAR_RANGE_0_625V      4
#define UNIPOLAR_RANGE_0_312V      5
#define UNIPOLAR_RANGE_0_156V      6
#define UNIPOLAR_RANGE_0_078V      7
#define UNIPOLAR_RANGE_0_039V      8
#define UNIPOLAR_RANGE_20V_25V     9
#define UNIPOLAR_RANGE_40V_50V     10

#define BIPOLAR_RANGE_10V_12x5V   16
#define BIPOLAR_RANGE_5V_6x25V    17
#define BIPOLAR_RANGE_2_5V        18
#define BIPOLAR_RANGE_1_25V       19
#define BIPOLAR_RANGE_0_625V      20
#define BIPOLAR_RANGE_0_312V      21
#define BIPOLAR_RANGE_0_156V      22
#define BIPOLAR_RANGE_0_078V      23
#define BIPOLAR_RANGE_0_039V      24
#define BIPOLAR_RANGE_20V_25V     25
#define BIPOLAR_RANGE_40V_50V     26

/*Range Defined for A/D by Spec -- short name */
#define UNI_10V               0
#define UNI_5V                1
#define UNI_2_5V              2
#define UNI_1_25V             3
#define UNI_0_625V            4
#define UNI_0_312V            5
#define UNI_0_156V            6
#define UNI_0_078V            7
#define UNI_0_039V            8
#define UNI_20V               9
#define UNI_40V              10

#define BI_10V               16
#define BI_5V                17
#define BI_2_5V              18
#define BI_1_25V             19
#define BI_0_625V            20
#define BI_0_312V            21
#define BI_0_156V            22
#define BI_0_078V            23
#define BI_0_039V            24
#define BI_20V               25
#define BI_40V               26

/********************************************************/
/******   A/D Specific Functions  (All AD modules) ******/
/********************************************************/
_75C3FUNC int CPCI75C3_AD_GetMaxChan(unsigned short ModuleID, int *MaxChan );
_75C3FUNC int CPCI75C3_AD_GetChanID( int Card, int Module, int Channel, unsigned short *ChanID);

_75C3FUNC int CPCI75C3_AD_GetVoltage( int Card, int Module, int Channel, double *Voltage );
_75C3FUNC int CPCI75C3_AD_GetVoltageWord(int Card, int Module, int Channel, unsigned short *Voltage);
_75C3FUNC int CPCI75C3_AD_GetDataWord( int Card, int Module, int Channel, unsigned short *Word );
_75C3FUNC int CPCI75C3_AD_SetRange( int Card, int Module, int Channel, unsigned short Range );
_75C3FUNC int CPCI75C3_AD_GetRange( int Card, int Module, int Channel, unsigned short *Range );

_75C3FUNC int CPCI75C3_AD_GetBITStatus( int Card, int Module, int Channel, unsigned short *BITStatus );
_75C3FUNC int CPCI75C3_AD_GetBITStatusWord( int Card, int Module, unsigned short *BITStatus );
_75C3FUNC int CPCI75C3_AD_SetBITStatusIntEnable( int Card, int Module, int Channel, unsigned short BITStatusIntEnab );
_75C3FUNC int CPCI75C3_AD_GetBITStatusIntEnable( int Card, int Module, int Channel, unsigned short *BITStatusIntEnab );
_75C3FUNC int CPCI75C3_AD_SetBITStatusIntEnableWord( int Card, int Module, unsigned short BITStatusIntEnab );
_75C3FUNC int CPCI75C3_AD_GetBITStatusIntEnableWord( int Card, int Module, unsigned short *BITStatusIntEnab );
_75C3FUNC int CPCI75C3_AD_GetBITInterruptVector( int Card, int Module, int *InterruptVector);
_75C3FUNC int CPCI75C3_AD_SetBITInterruptVector( int Card, int Module, int InterruptVector);

/**********************************************************************/
/******   A/D Specific Functions  (Does not apply to KA modules) ******/
/**********************************************************************/
_75C3FUNC int CPCI75C3_AD_GetAmp( int Card, int Module, int Channel, double *Amp );
_75C3FUNC int CPCI75C3_AD_EnableLatch( int Card, int Module );
_75C3FUNC int CPCI75C3_AD_DisableLatch( int Card, int Module );
_75C3FUNC int CPCI75C3_AD_SetBreakFrequency( int Card, int Module, int Channel, unsigned short BreakFrequency );
_75C3FUNC int CPCI75C3_AD_GetBreakFrequency( int Card, int Module, int Channel, unsigned short *BreakFrequency );
_75C3FUNC int CPCI75C3_AD_GetOpenStatus( int Card, int Module, int Channel, unsigned short *OpenStatus );
_75C3FUNC int CPCI75C3_AD_GetOpenStatusWord( int Card, int Module, unsigned short *OpenStatus );
_75C3FUNC int CPCI75C3_AD_SetOpenStatusIntEnable( int Card, int Module, int Channel, unsigned short OpenStatusIntEnab );
_75C3FUNC int CPCI75C3_AD_GetOpenStatusIntEnable( int Card, int Module, int Channel, unsigned short *OpenStatusIntEnab );
_75C3FUNC int CPCI75C3_AD_SetOpenStatusIntEnableWord( int Card, int Module, unsigned short OpenStatusIntEnab );
_75C3FUNC int CPCI75C3_AD_GetOpenStatusIntEnableWord( int Card, int Module, unsigned short *OpenStatusIntEnab );
_75C3FUNC int CPCI75C3_AD_GetOpenInterruptVector( int Card, int Module, int *InterruptVector);
_75C3FUNC int CPCI75C3_AD_SetOpenInterruptVector( int Card, int Module, int InterruptVector);

/******  A/D SelfTest D0, D2, D3   ******/
#define CPCI75C3_AD_D0_TEST_ENABLE			0x0001
#define CPCI75C3_AD_D2_TEST_ENABLE			0x0004
#define CPCI75C3_AD_D3_TEST_ENABLE			0x0008

_75C3FUNC int CPCI75C3_AD_SetD0TestRange( int Card, int Module, unsigned short Range );
_75C3FUNC int CPCI75C3_AD_GetD0TestRange( int Card, int Module, unsigned short *Range );
_75C3FUNC int CPCI75C3_AD_SetD0TestVoltage( int Card, int Module, double Voltage );
_75C3FUNC int CPCI75C3_AD_GetD0TestVoltage( int Card, int Module, double *Voltage );

_75C3FUNC int CPCI75C3_AD_D0TestEnable( int Card, int Module );
_75C3FUNC int CPCI75C3_AD_D0TestDisable( int Card, int Module );
_75C3FUNC int CPCI75C3_AD_D2TestEnable( int Card, int Module );
_75C3FUNC int CPCI75C3_AD_D2TestDisable( int Card, int Module );
_75C3FUNC int CPCI75C3_AD_ClearD2TestVerify( int Card, int Module );
_75C3FUNC int CPCI75C3_AD_CheckD2TestVerify( int Card, int Module );
#ifdef JAN
_75C3FUNC int CPCI75C3_AD_SetD2TestVerifyValue( int Card, int Module, unsigned short Word );
_75C3FUNC int CPCI75C3_AD_GetD2TestVerifyValue( int Card, int Module, unsigned short *Word );
#endif
_75C3FUNC int CPCI75C3_AD_D3TestEnable( int Card, int Module );
_75C3FUNC int CPCI75C3_AD_D3TestDisable( int Card, int Module );

_75C3FUNC int CPCI75C3_AD_GetCalChanWord(int Card, int Module, unsigned short *CalChanWord);
_75C3FUNC int CPCI75C3_AD_GetCalStateWord(int Card, int Module, unsigned short *CalStateWord);
_75C3FUNC int CPCI75C3_AD_GetProbe2Word(int Card, int Module, unsigned short *Probe2Word);
_75C3FUNC int CPCI75C3_AD_GetProbe3Word(int Card, int Module, unsigned short *Probe3Word);
_75C3FUNC int CPCI75C3_AD_ReadFifoData( int Card, int Module, int Channel, unsigned short *FifoData );
_75C3FUNC int CPCI75C3_AD_ReadWdsInFifo( int Card, int Module, int Channel, unsigned short *WdsInFifo);
_75C3FUNC int CPCI75C3_AD_SetFifoHiThreshold( int Card, int Module, int Channel, unsigned short FifoHiThreshold );
_75C3FUNC int CPCI75C3_AD_GetFifoHiThreshold( int Card, int Module, int Channel, unsigned short *FifoHiThreshold );
_75C3FUNC int CPCI75C3_AD_SetFifoLowThreshold( int Card, int Module, int Channel, unsigned short FifoLowThreshold );
_75C3FUNC int CPCI75C3_AD_GetFifoLowThreshold( int Card, int Module, int Channel, unsigned short *FifoLowThreshold );
_75C3FUNC int CPCI75C3_AD_SetFifoDelay( int Card, int Module, int Channel, unsigned short FifoDelay );
_75C3FUNC int CPCI75C3_AD_GetFifoDelay( int Card, int Module, int Channel, unsigned short *FifoDelay );
_75C3FUNC int CPCI75C3_AD_SetFifoSize( int Card, int Module, int Channel, unsigned short FifoSize );
_75C3FUNC int CPCI75C3_AD_GetFifoSize( int Card, int Module, int Channel, unsigned short *FifoSize );
_75C3FUNC int CPCI75C3_AD_SetFifoRate( int Card, int Module, int Channel, unsigned short FifoRate );
_75C3FUNC int CPCI75C3_AD_GetFifoRate( int Card, int Module, int Channel, unsigned short *FifoRate );
_75C3FUNC int CPCI75C3_AD_SetFifoClear( int Card, int Module, int Channel, unsigned short FifoClear );
_75C3FUNC int CPCI75C3_AD_GetFifoClear( int Card, int Module, int Channel, unsigned short *FifoClear );
_75C3FUNC int CPCI75C3_AD_SetFifoBufCtrl( int Card, int Module, int Channel, unsigned short FifoBufCtrl );
_75C3FUNC int CPCI75C3_AD_GetFifoBufCtrl( int Card, int Module, int Channel, unsigned short *FifoBufCtrl );
_75C3FUNC int CPCI75C3_AD_SetFifoTrigCtrl( int Card, int Module, int Channel, unsigned short FifoTrigCtrl );
_75C3FUNC int CPCI75C3_AD_GetFifoTrigCtrl( int Card, int Module, int Channel, unsigned short *FifoTrigCtrl );
_75C3FUNC int CPCI75C3_AD_ReadFifoStatus( int Card, int Module, int Channel, unsigned short *FifoStatus );
_75C3FUNC int CPCI75C3_AD_SetFifoInterrupt( int Card, int Module, int Channel, unsigned short FifoInterrupt );
_75C3FUNC int CPCI75C3_AD_GetFifoInterrupt( int Card, int Module, int Channel, unsigned short *FifoInterrupt );
_75C3FUNC int CPCI75C3_AD_SetFifoSoftwareTrig( int Card, int Module, unsigned short FifoSoftwareTrigger );
_75C3FUNC int CPCI75C3_AD_GetFifoSoftwareTrig( int Card, int Module, unsigned short *FifoSoftwareTrigger );
_75C3FUNC int CPCI75C3_AD_SetFifoClkRateAdderInputHi( int Card, int Module, unsigned short FifoClkRateAdderInputHi );
_75C3FUNC int CPCI75C3_AD_GetFifoClkRateAdderInputHi( int Card, int Module, unsigned short *FifoClkRateAdderInputHi );
_75C3FUNC int CPCI75C3_AD_SetFifoClkRateAdderInputLow( int Card, int Module, unsigned short FifoClkRateAdderInputLow );
_75C3FUNC int CPCI75C3_AD_GetFifoClkRateAdderInputLow( int Card, int Module, unsigned short *FifoClkRateAdderInputLow );

_75C3FUNC int CPCI75C3_AD_SetSamplingRate( int Card, int Module, unsigned long SamplingRate );
_75C3FUNC int CPCI75C3_AD_GetSamplingRate( int Card, int Module, unsigned long *SamplingRate );

_75C3FUNC int CPCI75C3_AD_SetFifoRateModeCtrl( int Card, int Module,  unsigned short FifoRateModeCtrl );
_75C3FUNC int CPCI75C3_AD_GetFifoRateModeCtrl( int Card, int Module,  unsigned short *FifoRateModeCtrl );
_75C3FUNC int CPCI75C3_AD_GetTestEnableWord( int Card, int Module, unsigned short *TestEnableWord );
_75C3FUNC int CPCI75C3_AD_SetTestEnableWord( int Card, int Module, unsigned short TestEnableWord );
_75C3FUNC int CPCI75C3_AD_SetCalRange( int Card, int Module, unsigned short calRangeFlag );
_75C3FUNC int CPCI75C3_AD_GetCalRange( int Card, int Module, unsigned short *calRangeFlag);
_75C3FUNC int CPCI75C3_AD_GetCalResultLowValue( int Card, int Module, unsigned short *calResultLowValue);
_75C3FUNC int CPCI75C3_AD_GetCalResultHighValue( int Card, int Module, unsigned short *calResultHiValue);
_75C3FUNC int CPCI75C3_AD_SetCalDelay( int Card, int Module, unsigned short seconds );
_75C3FUNC int CPCI75C3_AD_GetCalDelay( int Card, int Module, unsigned short *seconds );

_75C3FUNC int CPCI75C3_AD_GetFifoInterruptVector( int Card, int Module, int channel, int *InterruptVector );
_75C3FUNC int CPCI75C3_AD_SetFifoInterruptVector( int Card, int Module, int channel, int InterruptVector );
_75C3FUNC int CPCI75C3_AD_SetFifoBreakFreq( int Card, int Module, int Channel, unsigned short FifoBreakFreq);
_75C3FUNC int CPCI75C3_AD_GetFifoBreakFreq( int Card, int Module, int Channel, unsigned short *FifoBreakFreq );

/*** Internal Functions ****/
int getADLSB(unsigned short modID, unsigned short Range, double *lsb);

#ifdef __cplusplus
}
#endif

#endif

