/*+++

Copyright (c) 2008 North Atlantic Industries,

File Name:

 CPCI75C3_DA.h

Description:

 Include file to the CPCI75C3 - Analog/Digital(AD) Converter Board Interface.
 
 This was written in ANSI 'C' for 32-bit integers.

Author: 
Date:  
History:

---*/


#ifndef _CPCI75C3_DA_MOD_H
#define _CPCI75C3_DA_MOD_H

#include "CPCI75C3_include.h"               

#define DA_OUTPUT_TRG_CONST_UPDATE     0x0002
#define DA_OUTPUT_TRG_DONT_UPDATE      0x0000
#define DA_OUTPUT_TRG_TRG1_POS_SLOPE   0x0020
#define DA_OUTPUT_TRG_TRG1_NEG_SLOPE   0x0030
#define DA_OUTPUT_TRG_TRG2_POS_SLOPE   0x0021
#define DA_OUTPUT_TRG_TRG2_NEG_SLOPE   0x0031

#define DA_FIFO_TRG_EXT1_POS_SLOPE     0x0021
#define DA_FIFO_TRG_EXT1_NEG_SLOPE     0x0031
#define DA_FIFO_TRG_EXT2_POS_SLOPE     0x0020
#define DA_FIFO_TRG_EXT2_NEG_SLOPE     0x0030
#define DA_FIFO_TRG_SOFTWARE           0x0022
#define DA_FIFO_TRG_DISABLE            0x0000

#define DA_FIFO_IRQ_ON_EMPTY           0x0001
#define DA_FIFO_IRQ_ON_LOW_LIMIT       0x0002
#define DA_FIFO_IRQ_ON_HIGH_LIMIT      0x0004
#define DA_FIFO_IRQ_ON_FULL            0x0008
#define DA_FIFO_IRQ_ON_SAMP_DONE       0x0010

#define DA_FIFO_BUF_DISABLE            0x0001
#define DA_FIFO_BUF_ONE_SHOT_MODE      0x0000
#define DA_FIFO_BUF_REPEAT_MODE        0x0002


/**************************/
/*  D/A Module Registers  */
/**************************/
#define CPCI75C3_REG_DA_DATA_ADD {\
 0x000 << ADDR_SHIFT, 0x002 << ADDR_SHIFT, 0x004 << ADDR_SHIFT,\
 0x006 << ADDR_SHIFT, 0x008 << ADDR_SHIFT, 0x00A << ADDR_SHIFT,\
 0x00C << ADDR_SHIFT, 0x00E << ADDR_SHIFT, 0x010 << ADDR_SHIFT,\
 0x012 << ADDR_SHIFT\
}

#define CPCI75C3_REG_DA_POLARITY_ADD {\
 0x014 << ADDR_SHIFT, 0x016 << ADDR_SHIFT, 0x018 << ADDR_SHIFT, 0x01A << ADDR_SHIFT,\
 0x01C << ADDR_SHIFT, 0x01E << ADDR_SHIFT, 0x020 << ADDR_SHIFT, 0x022 << ADDR_SHIFT,\
 0x024 << ADDR_SHIFT, 0x026 << ADDR_SHIFT\
}

#define CPCI75C3_REG_DA_WRAP_AROUND_ADD {\
 0x028 << ADDR_SHIFT, 0x02A << ADDR_SHIFT, 0x02C << ADDR_SHIFT, 0x02E << ADDR_SHIFT,\
 0x030 << ADDR_SHIFT, 0x032 << ADDR_SHIFT, 0x034 << ADDR_SHIFT, 0x036 << ADDR_SHIFT,\
 0x038 << ADDR_SHIFT, 0x03A << ADDR_SHIFT\
}

#define CPCI75C3_REG_DA_CURRENT_READING_ADD {\
 0x03C << ADDR_SHIFT, 0x03E << ADDR_SHIFT, 0x040 << ADDR_SHIFT, 0x042 << ADDR_SHIFT,\
 0x044 << ADDR_SHIFT, 0x046 << ADDR_SHIFT, 0x048 << ADDR_SHIFT, 0x04A << ADDR_SHIFT,\
 0x04C << ADDR_SHIFT, 0x04E << ADDR_SHIFT\
}

#define CPCI75C3_REG_DA_TRIGGER_ADD {\
 0x050 << ADDR_SHIFT, 0x052 << ADDR_SHIFT, 0x054 << ADDR_SHIFT, 0x056 << ADDR_SHIFT,\
 0x058 << ADDR_SHIFT, 0x05A << ADDR_SHIFT, 0x05C << ADDR_SHIFT, 0x05E << ADDR_SHIFT,\
 0x060 << ADDR_SHIFT, 0x062 << ADDR_SHIFT\
}

/*For J8*/
#define CPCI75C3_REG_DA_J8_CURRENT_READING_ADD {\
   0x01C << ADDR_SHIFT, 0x01E << ADDR_SHIFT, 0x020 << ADDR_SHIFT, 0x022 << ADDR_SHIFT\
}

/*  For J7 - High Voltage module */
#define CPCI75C3_REG_DA_J7_RANGE_ADD {\
 0x008 << ADDR_SHIFT, 0x00A << ADDR_SHIFT\
}
#define CPCI75C3_REG_DA_J7_POLARITY_ADD {\
 0x00C << ADDR_SHIFT, 0x00E << ADDR_SHIFT, 0x010 << ADDR_SHIFT, 0x012 << ADDR_SHIFT\
}
#define CPCI75C3_REG_DA_J7_WRAP_AROUND_ADD {\
 0x014 << ADDR_SHIFT, 0x016 << ADDR_SHIFT, 0x018 << ADDR_SHIFT, 0x01A << ADDR_SHIFT\
}

#define CPCI75C3_REG_DA_J7_HVPS_FEEDBACK_ADD {\
  0x040 << ADDR_SHIFT, 0x042 << ADDR_SHIFT\
}
/*  End for J7  */

#define CPCI75C3_REG_DA_TEMPERATURE_REG                               (0x02C << ADDR_SHIFT)
#define CPCI75C3_REG_DA_HVPS1_REG                                     (0x03C << ADDR_SHIFT)
#define CPCI75C3_REG_DA_HVPS2_REG                                     (0x03E << ADDR_SHIFT)
#define CPCI75C3_REG_DA_RESET_ALL_TO_ZERO                             (0x068 << ADDR_SHIFT)
#define CPCI75C3_REG_DA_RETRY_OVERLOAD                                (0x06A << ADDR_SHIFT)
#define CPCI75C3_REG_DA_RESET_OVERLOAD                                (0x06C << ADDR_SHIFT)
#define CPCI75C3_REG_DA_OVERRIDE                                      (0x06E << ADDR_SHIFT)
/* F5 Specific Register */
#define CPCI75C3_REG_DA_F5_PS_CH1CH2                                  (0x072 << ADDR_SHIFT)
#define CPCI75C3_REG_DA_F5_PS_CH3CH4                                  (0x074 << ADDR_SHIFT)
#define CPCI75C3_REG_DA_F5_LINECFG_CH1CH2                             (0x076 << ADDR_SHIFT)
#define CPCI75C3_REG_DA_F5_LINECFG_CH3CH4                             (0x078 << ADDR_SHIFT)
#define CPCI75C3_REG_DA_F5_VOLTRANGE_CH1CH2                           (0x07A << ADDR_SHIFT)
#define CPCI75C3_REG_DA_F5_VOLTRANGE_CH3CH4                           (0x07C << ADDR_SHIFT)
#define CPCI75C3_REG_DA_F5_CHAN_PWR_EN                                (0x07E << ADDR_SHIFT)
/*end of F5*/
#define CPCI75C3_REG_DA_FIFO_DA_DATA                                  (0x100 << ADDR_SHIFT)
#define CPCI75C3_REG_DA_FIFO_BUF_DATA_ADD {\
 0x100 << ADDR_SHIFT, 0x102 << ADDR_SHIFT, 0x104 << ADDR_SHIFT,\
 0x106 << ADDR_SHIFT, 0x108 << ADDR_SHIFT, 0x10A << ADDR_SHIFT,\
 0x10C << ADDR_SHIFT, 0x10E << ADDR_SHIFT, 0x110 << ADDR_SHIFT,\
 0x112 << ADDR_SHIFT\
}
#define CPCI75C3_REG_DA_FIFO_WDS_IN_BUFF                              (0x120 << ADDR_SHIFT)
#define CPCI75C3_REG_DA_FIFO_HI_THRESHOLD                             (0x140 << ADDR_SHIFT)
#define CPCI75C3_REG_DA_FIFO_LOW_THRESHOLD                            (0x160 << ADDR_SHIFT)
#define CPCI75C3_REG_DA_FIFO_DELAY                                    (0x180 << ADDR_SHIFT)
#define CPCI75C3_REG_DA_FIFO_SIZE                                     (0x1A0 << ADDR_SHIFT)
#define CPCI75C3_REG_DA_FIFO_RATE                                     (0x1C0 << ADDR_SHIFT)
#define CPCI75C3_REG_DA_FIFO_CLEAR                                    (0x1E0 << ADDR_SHIFT)
#define CPCI75C3_REG_DA_FIFO_BUFF_CTRL                                (0x200 << ADDR_SHIFT)
#define CPCI75C3_REG_DA_FIFO_TRIG_CTRL                                (0x220 << ADDR_SHIFT)
#define CPCI75C3_REG_DA_FIFO_STATUS                                   (0x240 << ADDR_SHIFT)
#define CPCI75C3_REG_DA_FIFO_INTERRUPT                                (0x260 << ADDR_SHIFT)
#define CPCI75C3_REG_DA_FIFO_SOFTWARE_TRIGGER                         (0x280 << ADDR_SHIFT)
#define CPCI75C3_REG_DA_TEST_ENABLE                                   (0x37C << ADDR_SHIFT)
#define CPCI75C3_REG_DA_TESTD2_VERIFY                                 (0x37E << ADDR_SHIFT)
#define CPCI75C3_REG_DA_BIT_STATUS                                    (0x380 << ADDR_SHIFT)
#define CPCI75C3_REG_DA_OVER_CURRENT_STATUS                           (0x382 << ADDR_SHIFT)
#define CPCI75C3_REG_DA_BIT_STATUS_INT_ENAB                           (0x384 << ADDR_SHIFT)
#define CPCI75C3_REG_DA_OVER_CURRENT_STATUS_INT_ENAB                  (0x386 << ADDR_SHIFT)
#define CPCI75C3_REG_DA_INT_VECTOR_BIT                                (0x3E0 << ADDR_SHIFT)
#define CPCI75C3_REG_DA_INT_VECTOR_OVER_CURRENT                       (0x3E2 << ADDR_SHIFT)
#define CPCI75C3_REG_DA_CAL_CHAN                                      (0x3A8 << ADDR_SHIFT)  
#define CPCI75C3_REG_DA_CAL_TYPE                                      (0x3AA << ADDR_SHIFT)
#define CPCI75C3_REG_DA_CAL_VALUE                                     (0x3AC << ADDR_SHIFT)
#define CPCI75C3_REG_DA_REF_FIFO_VECTOR                               (0x3C2 << ADDR_SHIFT)  /*needs to be added to the spec.*/

#define F5_BITVAL_PER_VOLT       (65535/25)
#define F5_VOLTVAL_PER_BIT       (25/65535)
#define F5_PS_REG_BIT_WORTH      0.182
#define F5_LINE_CFG_SINGLE_MODE  0  /*Single Mode*/
#define F5_LINE_CFG_DIF_MODE     0  /*Differential Mode*/
#define F5_PWD_ON                1
#define F5_PWD_OFF               0




#define DA_HV_MAX_RANGE  2  /*  J7 has two Range registers. */
#define F5_MIN_RANGE         0
#define F5_MAX_RANGE         25
#define J7_MIN_RANGE         0
#define J7_MAX_RANGE         100
#define J8_MIN_RANGE         0
#define J8_MAX_RANGE         100


#define DA_MAX_CHAN        10
#define DA_MAX_4CHAN        4 /*applies to module F2, F4, F5, J7, J8*/
#define DA_MAX_2CHAN        2 /*applies to module J6*/

#define DA_FIFO_TYPE        0
#define DA_OUTPUT_TYPE      1

#ifdef __cplusplus
extern "C" {
#endif 

/******   D/A Specific Functions   ******/
_75C3FUNC int CPCI75C3_DA_GetMaxChan(unsigned short ModuleID, int *MaxChan );
_75C3FUNC int CPCI75C3_DA_SetVoltage( int Card, int Module, int Channel, double Voltage );
_75C3FUNC int CPCI75C3_DA_GetVoltage( int Card, int Module, int Channel, double *Voltage );
_75C3FUNC int CPCI75C3_DA_SetVoltageWord( int Card, int Module, int Channel, unsigned short Word );
_75C3FUNC int CPCI75C3_DA_GetVoltageWord( int Card, int Module, int Channel, unsigned short *Word );
_75C3FUNC int CPCI75C3_DA_SetPolarity( int Card, int Module, int Channel, unsigned short Polarity );
_75C3FUNC int CPCI75C3_DA_GetPolarity( int Card, int Module, int Channel, unsigned short *Polarity );
_75C3FUNC int CPCI75C3_DA_GetWrapVoltage( int Card, int Module, int Channel, double *WrapVoltage );
_75C3FUNC int CPCI75C3_DA_GetWrapVoltageWord( int Card, int Module, int Channel, unsigned short *Word );
_75C3FUNC int CPCI75C3_DA_SetVoltageRange( int Card, int Module, int Channel, double Value );
_75C3FUNC int CPCI75C3_DA_GetVoltageRange( int Card, int Module, int Channel, double *Value );
_75C3FUNC int CPCI75C3_DA_GetCurrent(int Card, int Module, int Channel, double *pCurrent );
_75C3FUNC int CPCI75C3_DA_GetCurrentWord(int Card, int Module, int Channel, unsigned short *Word);
_75C3FUNC int CPCI75C3_DA_SetOutputTrigCtrl(int Card, int Module, int Channel, unsigned short trigCtrl);
_75C3FUNC int CPCI75C3_DA_GetOutputTrigCtrl(int Card, int Module, int Channel, unsigned short *trigCtrl);


_75C3FUNC int CPCI75C3_DA_GetTestEnableWord( int Card, int Module, unsigned short *TestEnableWord );
_75C3FUNC int CPCI75C3_DA_D2TestEnable( int Card, int Module );
_75C3FUNC int CPCI75C3_DA_D2TestDisable( int Card, int Module );
_75C3FUNC int CPCI75C3_DA_ClearD2TestVerify( int Card, int Module );
_75C3FUNC int CPCI75C3_DA_CheckD2TestVerify( int Card, int Module );
_75C3FUNC int CPCI75C3_DA_SetD2TestVerifyValue( int Card, int Module, unsigned short Word );
_75C3FUNC int CPCI75C3_DA_GetD2TestVerifyValue( int Card, int Module, unsigned short *Word );
_75C3FUNC int CPCI75C3_DA_D3TestEnable( int Card, int Module );
_75C3FUNC int CPCI75C3_DA_D3TestDisable( int Card, int Module );

_75C3FUNC int CPCI75C3_DA_ResetAllDAtoZero( int Card, int Module );
_75C3FUNC int CPCI75C3_DA_EnableRetryOverload( int Card, int Module );
_75C3FUNC int CPCI75C3_DA_DisableRetryOverload( int Card, int Module );
_75C3FUNC int CPCI75C3_DA_GetRetryOverload(int Card, int Module, unsigned short *Word);
_75C3FUNC int CPCI75C3_DA_ResetOverload( int Card, int Module );
_75C3FUNC int CPCI75C3_DA_EnableOverride( int Card, int Module );
_75C3FUNC int CPCI75C3_DA_DisableOverride( int Card, int Module );
_75C3FUNC int CPCI75C3_DA_GetOverride( int Card, int Module, unsigned short *Word);

_75C3FUNC int CPCI75C3_DA_GetBITStatus( int Card, int Module, int Channel, unsigned short *BITStatus );
_75C3FUNC int CPCI75C3_DA_GetBITStatusWord( int Card, int Module, unsigned short *BITStatus );
_75C3FUNC int CPCI75C3_DA_SetBITStatusIntEnable( int Card, int Module, int Channel, unsigned short BITStatusIntEnab );
_75C3FUNC int CPCI75C3_DA_GetBITStatusIntEnable( int Card, int Module, int Channel, unsigned short *BITStatusIntEnab );
_75C3FUNC int CPCI75C3_DA_SetBITStatusIntEnableWord( int Card, int Module, unsigned short BITStatusIntEnab );
_75C3FUNC int CPCI75C3_DA_GetBITStatusIntEnableWord( int Card, int Module, unsigned short *BITStatusIntEnab );
_75C3FUNC int CPCI75C3_DA_GetOverCurrentStatus( int Card, int Module, int Channel, unsigned short *OverCurrentStatus );
_75C3FUNC int CPCI75C3_DA_GetOverCurrentStatusWord( int Card, int Module, unsigned short *OverCurrentStatus );

_75C3FUNC int CPCI75C3_DA_SetOverCurrentStatusIntEnable( int Card, int Module, int Channel, unsigned short OverCurrentStatusIntEnab );
_75C3FUNC int CPCI75C3_DA_GetOverCurrentStatusIntEnable( int Card, int Module, int Channel, unsigned short *OverCurrentStatusIntEnab );
_75C3FUNC int CPCI75C3_DA_SetOverCurrentStatusIntEnableWord( int Card, int Module, unsigned short OverCurrentStatusIntEnab );
_75C3FUNC int CPCI75C3_DA_GetOverCurrentStatusIntEnableWord( int Card, int Module, unsigned short *OverCurrentStatusIntEnab );

_75C3FUNC int CPCI75C3_DA_GetBITInterruptVector( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DA_SetBITInterruptVector( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DA_GetOverCurrInterruptVector( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DA_SetOverCurrInterruptVector( int Card, int Module, int InterruptVector );

_75C3FUNC int CPCI75C3_DA_WriteFifoData(int Card, int Module, int Channel, unsigned short FifoData);
_75C3FUNC int CPCI75C3_DA_ReadWdsInFifo(int Card, int Module, int Channel, unsigned short *WdsInFifo);
_75C3FUNC int CPCI75C3_DA_SetFifoHiThreshold( int Card, int Module, int Channel, unsigned short FifoHiThreshold );
_75C3FUNC int CPCI75C3_DA_GetFifoHiThreshold( int Card, int Module, int Channel, unsigned short *FifoHiThreshold );
_75C3FUNC int CPCI75C3_DA_SetFifoLowThreshold( int Card, int Module, int Channel, unsigned short FifoLowThreshold );
_75C3FUNC int CPCI75C3_DA_GetFifoLowThreshold( int Card, int Module, int Channel, unsigned short *FifoLowThreshold );
_75C3FUNC int CPCI75C3_DA_SetFifoDelay( int Card, int Module, int Channel, unsigned short FifoDelay );
_75C3FUNC int CPCI75C3_DA_GetFifoDelay( int Card, int Module, int Channel, unsigned short *FifoDelay );
_75C3FUNC int CPCI75C3_DA_SetFifoSize( int Card, int Module, int Channel, unsigned short FifoSize );
_75C3FUNC int CPCI75C3_DA_GetFifoSize( int Card, int Module, int Channel, unsigned short *FifoSize );
_75C3FUNC int CPCI75C3_DA_SetFifoRate( int Card, int Module, int Channel, unsigned short FifoRate );
_75C3FUNC int CPCI75C3_DA_GetFifoRate( int Card, int Module, int Channel, unsigned short *FifoRate );
_75C3FUNC int CPCI75C3_DA_SetFifoClear( int Card, int Module, int Channel, unsigned short FifoClear );
_75C3FUNC int CPCI75C3_DA_GetFifoClear( int Card, int Module, int Channel, unsigned short *FifoClear );
_75C3FUNC int CPCI75C3_DA_SetFifoBufCtrl( int Card, int Module, int Channel, unsigned short FifoBufCtrl );
_75C3FUNC int CPCI75C3_DA_GetFifoBufCtrl( int Card, int Module, int Channel, unsigned short *FifoBufCtrl );
_75C3FUNC int CPCI75C3_DA_SetFifoTrigCtrl( int Card, int Module, int Channel, unsigned short FifoTrigCtrl );
_75C3FUNC int CPCI75C3_DA_GetFifoTrigCtrl( int Card, int Module, int Channel, unsigned short *FifoTrigCtrl );
_75C3FUNC int CPCI75C3_DA_ReadFifoStatus( int Card, int Module, int Channel, unsigned short *FifoStatus );
_75C3FUNC int CPCI75C3_DA_SetFifoInterrupt( int Card, int Module, int Channel, unsigned short FifoInterrupt );
_75C3FUNC int CPCI75C3_DA_GetFifoInterrupt( int Card, int Module, int Channel, unsigned short *FifoInterrupt );
_75C3FUNC int CPCI75C3_DA_SetFifoSoftwareTrig( int Card, int Module, unsigned short FifoSoftwareTrigger );
_75C3FUNC int CPCI75C3_DA_SetFifoVoltage( int Card, int Module, int Channel, double Voltage );
_75C3FUNC int CPCI75C3_DA_SetFifoVoltageWord( int Card, int Module, int Channel, unsigned short Word);
_75C3FUNC int CPCI75C3_DA_GetFifoVoltage( int Card, int Module, int Channel, double *Voltage );
_75C3FUNC int CPCI75C3_DA_GetFifoVoltageWord( int Card, int Module, int Channel, unsigned short *Word);
_75C3FUNC int CPCI75C3_DA_GetFifoIntVector(int Card, int Module, int Channel,unsigned short *vector);
_75C3FUNC int CPCI75C3_DA_SetFifoIntVector( int Card, int Module, int Channel, unsigned short vector);


/* For J7/J8 only */
_75C3FUNC int CPCI75C3_DA_GetHVPSVoltage( int Card, int Module, int PSNumber, double *Voltage );
_75C3FUNC int CPCI75C3_DA_GetTemperature( int Card, int Module,  double *Temperature ); 
_75C3FUNC int CPCI75C3_DA_GetTemperatureWord( int Card, int Module,  unsigned short *Temperature ); 
_75C3FUNC int CPCI75C3_DA_SetChanRangeValue( int Card, int Module,  int Channel, double Value );

/*For F5 only*/
_75C3FUNC int CPCI75C3_DA_SetLineConfig(int Card,int Module,int Channel,unsigned short SinDb);
_75C3FUNC int CPCI75C3_DA_GetLineConfig(int Card,int Module,int Channel,unsigned short *SinDb);
_75C3FUNC int CPCI75C3_DA_GetPsVoltage(int Card, int Module, int Channel, double *psVoltage); 

/*manufacture functions, not meant for customers*/
_75C3FUNC int CPCI75C3_DA_SetCalChan( int Card, int Module, unsigned short CalChannel );
_75C3FUNC int CPCI75C3_DA_SetCalType( int Card, int Module, unsigned short CalType );
_75C3FUNC int CPCI75C3_DA_SetCalValue( int Card, int Module, unsigned short CalValue );
_75C3FUNC int CPCI75C3_DA_SetF5ChanPwrSupp( int Card, int Module, int Channel,unsigned short State);

#ifdef __cplusplus
}
#endif

/*internal functions*/
int DA_SetVoltage( int Card, int Module, int Channel, double Voltage, int voltType);
int DA_GetVoltage( int Card, int Module, int Channel, double *Voltage, int voltType);
int DA_SetVoltageWord( int Card, int Module, int Channel, unsigned short Word, int voltType);
int DA_GetVoltageWord( int Card, int Module, int Channel, unsigned short *Word, int voltType);

#endif

