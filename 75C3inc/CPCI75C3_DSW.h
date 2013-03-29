/*+++

Copyright (c) 2008 North Atlantic Industries,

File Name:

 CPCI75C3_DSW.h

Description:

 Include file to the CPCI75C3 - Discrete I/O Interface.
 
 This was written in ANSI 'C' for 32-bit integers.

Author: 
Date:  
History:

---*/

#ifndef _CPCI75C3_DSW_H
#define _CPCI75C3_DSW_H

#include "CPCI75C3_include.h"

#ifdef __cplusplus
extern "C" {
#endif 



/**************************/
/*  DSW Module Registers  */
/**************************/
#define CPCI75C3_REG_DSW_WRITE_OUTPUT                                  (0x000 << ADDR_SHIFT)
#define CPCI75C3_REG_DSW_READ_IO                                       (0x002 << ADDR_SHIFT)

#define CPCI75C3_REG_DSW_MAX_HIGH_THRESHOLD_ADD {\
 (0x004 << ADDR_SHIFT), (0x00E << ADDR_SHIFT), (0x018 << ADDR_SHIFT), (0x022 << ADDR_SHIFT),\
 (0x02C << ADDR_SHIFT), (0x036 << ADDR_SHIFT), (0x040 << ADDR_SHIFT), (0x04A << ADDR_SHIFT),\
 (0x054 << ADDR_SHIFT), (0x05E << ADDR_SHIFT), (0x068 << ADDR_SHIFT), (0x072 << ADDR_SHIFT),\
 (0x07C << ADDR_SHIFT), (0x086 << ADDR_SHIFT), (0x090 << ADDR_SHIFT), (0x09A << ADDR_SHIFT) \
}

#define CPCI75C3_REG_DSW_UPPER_THRESHOLD_ADD {\
 (0x006 << ADDR_SHIFT), (0x010 << ADDR_SHIFT), (0x01A << ADDR_SHIFT), (0x024 << ADDR_SHIFT),\
 (0x02E << ADDR_SHIFT), (0x038 << ADDR_SHIFT), (0x042 << ADDR_SHIFT), (0x04C << ADDR_SHIFT),\
 (0x056 << ADDR_SHIFT), (0x060 << ADDR_SHIFT), (0x06A << ADDR_SHIFT), (0x074 << ADDR_SHIFT),\
 (0x07E << ADDR_SHIFT), (0x088 << ADDR_SHIFT), (0x092 << ADDR_SHIFT), (0x09C << ADDR_SHIFT) \
}

#define CPCI75C3_REG_DSW_LOWER_THRESHOLD_ADD {\
 (0x008 << ADDR_SHIFT), (0x012 << ADDR_SHIFT), (0x01C << ADDR_SHIFT), (0x026 << ADDR_SHIFT),\
 (0x030 << ADDR_SHIFT), (0x03A << ADDR_SHIFT), (0x044 << ADDR_SHIFT), (0x04E << ADDR_SHIFT),\
 (0x058 << ADDR_SHIFT), (0x062 << ADDR_SHIFT), (0x06C << ADDR_SHIFT), (0x076 << ADDR_SHIFT),\
 (0x080 << ADDR_SHIFT), (0x08A << ADDR_SHIFT), (0x094 << ADDR_SHIFT), (0x09E << ADDR_SHIFT) \
}

#define CPCI75C3_REG_DSW_MIN_LOW_THRESHOLD_ADD {\
 (0x00A << ADDR_SHIFT), (0x014 << ADDR_SHIFT), (0x01E << ADDR_SHIFT), (0x028 << ADDR_SHIFT),\
 (0x032 << ADDR_SHIFT), (0x03C << ADDR_SHIFT), (0x046 << ADDR_SHIFT), (0x050 << ADDR_SHIFT),\
 (0x05A << ADDR_SHIFT), (0x064 << ADDR_SHIFT), (0x06E << ADDR_SHIFT), (0x078 << ADDR_SHIFT),\
 (0x082 << ADDR_SHIFT), (0x08C << ADDR_SHIFT), (0x096 << ADDR_SHIFT), (0x0A0 << ADDR_SHIFT) \
}

#define CPCI75C3_REG_DSW_DEBOUNCE_TIME_ADD {\
 (0x00C << ADDR_SHIFT), (0x016 << ADDR_SHIFT), (0x020 << ADDR_SHIFT), (0x02A << ADDR_SHIFT),\
 (0x034 << ADDR_SHIFT), (0x03E << ADDR_SHIFT), (0x048 << ADDR_SHIFT), (0x052 << ADDR_SHIFT),\
 (0x05C << ADDR_SHIFT), (0x066 << ADDR_SHIFT), (0x070 << ADDR_SHIFT), (0x07A << ADDR_SHIFT),\
 (0x084 << ADDR_SHIFT), (0x08E << ADDR_SHIFT), (0x098 << ADDR_SHIFT), (0x0A2 << ADDR_SHIFT) \
}
#define CPCI75C3_REG_DSW_RESET_OVER_CURRENT                            (0x0BC << ADDR_SHIFT)

/*Register offsets for new K7- These registers used for updating calibration factors for current measurements*/
#define CPCI75C3_REG_DSW_CAL_CHANNEL                                   (0x3A8 << ADDR_SHIFT)
#define CPCI75C3_REG_DSW_CAL_TYPE                                      (0x3AA << ADDR_SHIFT)/*0:Voltage 1:Current*/
#define CPCI75C3_REG_DSW_CAL_OFFSET                                    (0x3AE << ADDR_SHIFT)
#define CPCI75C3_REG_DSW_CAL_GAIN                                      (0x3B2 << ADDR_SHIFT)

/*Register offsets for K7- These registers will be the raw post cal voltage measurements across switch contacts*/
#define CPCI75C3_REG_DSW_VOLTAGERDG_ADD {\
(0x100 << ADDR_SHIFT), (0x102 << ADDR_SHIFT), (0x104 << ADDR_SHIFT), (0x106 << ADDR_SHIFT),\
(0x108 << ADDR_SHIFT), (0x10A << ADDR_SHIFT), (0x10C << ADDR_SHIFT), (0x10E << ADDR_SHIFT),\
(0x110 << ADDR_SHIFT), (0x112 << ADDR_SHIFT), (0x114 << ADDR_SHIFT), (0x116 << ADDR_SHIFT),\
(0x118 << ADDR_SHIFT), (0x11A << ADDR_SHIFT), (0x11C << ADDR_SHIFT), (0x11E << ADDR_SHIFT) \
}
/*Register offsets for new K7- These registers will be the raw post cal switch current measurements*/
#define CPCI75C3_REG_DSW_CURRENTRDG_ADD {\
(0x120 << ADDR_SHIFT), (0x122 << ADDR_SHIFT), (0x124 << ADDR_SHIFT), (0x126 << ADDR_SHIFT),\
(0x128 << ADDR_SHIFT), (0x12A << ADDR_SHIFT), (0x12C << ADDR_SHIFT), (0x12E << ADDR_SHIFT),\
(0x130 << ADDR_SHIFT), (0x132 << ADDR_SHIFT), (0x134 << ADDR_SHIFT), (0x136 << ADDR_SHIFT),\
(0x138 << ADDR_SHIFT), (0x13A << ADDR_SHIFT), (0x13C << ADDR_SHIFT), (0x13E << ADDR_SHIFT) \
}

/*Register offsets for K7- These registers will be the module filtered post cal voltage measurements across switch contacts*/
#define CPCI75C3_REG_DSW_VOLTAGE_FILT_RDG_ADD {\
(0x140 << ADDR_SHIFT), (0x142 << ADDR_SHIFT), (0x144 << ADDR_SHIFT), (0x146 << ADDR_SHIFT),\
(0x148 << ADDR_SHIFT), (0x14A << ADDR_SHIFT), (0x14C << ADDR_SHIFT), (0x14E << ADDR_SHIFT),\
(0x150 << ADDR_SHIFT), (0x152 << ADDR_SHIFT), (0x154 << ADDR_SHIFT), (0x156 << ADDR_SHIFT),\
(0x158 << ADDR_SHIFT), (0x15A << ADDR_SHIFT), (0x15C << ADDR_SHIFT), (0x15E << ADDR_SHIFT) \
}

/*Register offsets for K7- These registers will be the module filtered post cal switch current measurements*/
#define CPCI75C3_REG_DSW_CURRENT_FILT_RDG_ADD {\
(0x160 << ADDR_SHIFT), (0x162 << ADDR_SHIFT), (0x164 << ADDR_SHIFT), (0x166 << ADDR_SHIFT),\
(0x168 << ADDR_SHIFT), (0x16A << ADDR_SHIFT), (0x16C << ADDR_SHIFT), (0x16E << ADDR_SHIFT),\
(0x170 << ADDR_SHIFT), (0x172 << ADDR_SHIFT), (0x174 << ADDR_SHIFT), (0x176 << ADDR_SHIFT),\
(0x178 << ADDR_SHIFT), (0x17A << ADDR_SHIFT), (0x17C << ADDR_SHIFT), (0x17E << ADDR_SHIFT) \
}

#define CPCI75C3_REG_DSW_BIT_STATUS                                    (0x0D0 << ADDR_SHIFT)

#define CPCI75C3_REG_DSW_OVER_CURRENT_STATUS                           (0x0D4 << ADDR_SHIFT)
#define CPCI75C3_REG_DSW_MAX_HI_THRESHOLD_STATUS                       (0x0D6 << ADDR_SHIFT)
#define CPCI75C3_REG_DSW_MIN_LOW_THRESHOLD_STATUS                      (0x0D8 << ADDR_SHIFT)
#define CPCI75C3_REG_DSW_MID_RANGE_FAULT_STATUS                        (0x0DA << ADDR_SHIFT)
#define CPCI75C3_REG_DSW_LOW_HI_TRANSITION_STATUS                      (0x0DC << ADDR_SHIFT)
#define CPCI75C3_REG_DSW_HI_LOW_TRANSITION_STATUS                      (0x0DE << ADDR_SHIFT)

#define CPCI75C3_REG_DSW_BIT_INT_ENAB                                  (0x0E8 << ADDR_SHIFT)

#define CPCI75C3_REG_DSW_OVER_CURRENT_INT_ENAB                         (0x0EC << ADDR_SHIFT)
#define CPCI75C3_REG_DSW_MAX_HI_THRESHOLD_INT_ENAB                     (0x0EE << ADDR_SHIFT)
#define CPCI75C3_REG_DSW_MIN_LOW_THRESHOLD_INT_ENAB                    (0x0F0 << ADDR_SHIFT)
#define CPCI75C3_REG_DSW_MID_RANGE_FAULT_INT_ENAB                      (0x0F2 << ADDR_SHIFT)
#define CPCI75C3_REG_DSW_LOW_HI_TRANSITION_INT_ENAB                    (0x0F4 << ADDR_SHIFT)
#define CPCI75C3_REG_DSW_HI_LOW_TRANSITION_INT_ENAB                    (0x0F6 << ADDR_SHIFT)

#define CPCI75C3_REG_DSW_INT_VECTOR_BIT                                (0x3E0 << ADDR_SHIFT)
#define CPCI75C3_REG_DSW_INT_VECTOR_MAX_HI_THRESHOLD                   (0x3E2 << ADDR_SHIFT)
#define CPCI75C3_REG_DSW_INT_VECTOR_MIN_LOW_THRESHOLD                  (0x3E4 << ADDR_SHIFT)
#define CPCI75C3_REG_DSW_INT_VECTOR_MID_RANGE_THRESHOLD                (0x3E6 << ADDR_SHIFT)
#define CPCI75C3_REG_DSW_INT_VECTOR_OVERCURRENT                        (0x3C2 << ADDR_SHIFT)
#define CPCI75C3_REG_DSW_INT_VECTOR_LOW_HI_TRANSITION                  (0x3C4 << ADDR_SHIFT)
#define CPCI75C3_REG_DSW_INT_VECTOR_HI_LOW_TRANSITION                  (0x3C6 << ADDR_SHIFT)

#define CPCI75C3_DSW_DESIGN_VERSION                                    (0x3B4 << ADDR_SHIFT)
#define CPCI75C3_DSW_DESIGN_REVISION                                   (0x3B6 << ADDR_SHIFT)

/*Note: registers below are for modules currently in development; not listed in user memory map */
#define CPCI75C3_DSW_CURRENT_CHANNEL_REGISTER                          (0x168 << ADDR_SHIFT)
#define CPCI75C3_DSW_CURRENTGAIN_LO_SIDE_CAL_FACTOR                    (0x16A << ADDR_SHIFT)
#define CPCI75C3_DSW_CURRENTGAIN_HI_SIDE_CAL_FACTOR                    (0x16C << ADDR_SHIFT)
#define CPCI75C3_DSW_CURRENT_READ_REGISTER                             (0x16E << ADDR_SHIFT)                   

/******   Internal Functions to Access Registers (Do not export)  ******/
int CPCI75C3_GetIndexBase4( int Channel );

/******   DSW Specific Functions   ******/

/******   DSW Channel Count   ******/
_75C3FUNC int CPCI75C3_DSW_GetMaxChan( unsigned short ModuleID, int *MaxChan );

_75C3FUNC int CPCI75C3_DSW_SetOutputState( int Card, int Module, int Channel, unsigned short OutputState );
_75C3FUNC int CPCI75C3_DSW_GetOutputState( int Card, int Module, int Channel, unsigned short *OutputState );
_75C3FUNC int CPCI75C3_DSW_SetOutputStateWord( int Card, int Module, unsigned short OutputState );
_75C3FUNC int CPCI75C3_DSW_GetOutputStateWord( int Card, int Module, unsigned short *OutputState );
_75C3FUNC int CPCI75C3_DSW_GetInputState( int Card, int Module, int Channel, unsigned short *InputState );
_75C3FUNC int CPCI75C3_DSW_GetInputStateWord( int Card, int Module, unsigned short *InputState );
_75C3FUNC int CPCI75C3_DSW_SetMaxHiThreshold( int Card, int Module, int Channel, double MaxHiThreshold );
_75C3FUNC int CPCI75C3_DSW_GetMaxHiThreshold( int Card, int Module, int Channel, double *MaxHiThreshold );
_75C3FUNC int CPCI75C3_DSW_SetUpperThreshold( int Card, int Module, int Channel, double UpperThreshold );
_75C3FUNC int CPCI75C3_DSW_GetUpperThreshold( int Card, int Module, int Channel, double *UpperThreshold );
_75C3FUNC int CPCI75C3_DSW_SetLowerThreshold( int Card, int Module, int Channel, double LowerThreshold );
_75C3FUNC int CPCI75C3_DSW_GetLowerThreshold( int Card, int Module, int Channel, double *LowerThreshold );
_75C3FUNC int CPCI75C3_DSW_SetMinLowThreshold( int Card, int Module, int Channel, double MinLowThreshold );
_75C3FUNC int CPCI75C3_DSW_GetMinLowThreshold( int Card, int Module, int Channel, double *MinLowThreshold );
_75C3FUNC int CPCI75C3_DSW_SetDebounceTime( int Card, int Module, int Channel, double DebounceTime );
_75C3FUNC int CPCI75C3_DSW_GetDebounceTime( int Card, int Module, int Channel, double *DebounceTime );
_75C3FUNC int CPCI75C3_DSW_SetIOFormat( int Card, int Module, int Channel, unsigned short Format );
_75C3FUNC int CPCI75C3_DSW_GetIOFormat( int Card, int Module, int Channel, unsigned short *Format );
_75C3FUNC int CPCI75C3_DSW_SetSourceSinkCurrent( int Card, int Module, int Channel, double Current );
_75C3FUNC int CPCI75C3_DSW_SetSourceSinkCurrentBank( int Card, int Module, int Bank, double Current );
_75C3FUNC int CPCI75C3_DSW_GetSourceSinkCurrent( int Card, int Module, int Channel, double *Current );
_75C3FUNC int CPCI75C3_DSW_GetSourceSinkCurrentBank( int Card, int Module, int Bank, double *Current );
_75C3FUNC int CPCI75C3_DSW_SetPullUpDownConfig( int Card, int Module, int Channel, unsigned short Config );
_75C3FUNC int CPCI75C3_DSW_GetPullUpDownConfig( int Card, int Module, int Channel, unsigned short *Config );

_75C3FUNC int CPCI75C3_DSW_SetPullUpDownConfigWord( int Card, int Module, unsigned short ConfigWord );
_75C3FUNC int CPCI75C3_DSW_GetPullUpDownConfigWord( int Card, int Module, unsigned short *ConfigWord );
_75C3FUNC int CPCI75C3_DSW_GetBITStatus( int Card, int Module, int Channel, unsigned short *BITStatus );
_75C3FUNC int CPCI75C3_DSW_GetBITStatusWord( int Card, int Module, unsigned short *BITStatusWord );
_75C3FUNC int CPCI75C3_DSW_GetOverCurrentStatus( int Card, int Module, int Channel, unsigned short *OverCurrentStatus );
_75C3FUNC int CPCI75C3_DSW_GetOverCurrentStatusWord( int Card, int Module, unsigned short *OverCurrentStatusWord );
_75C3FUNC int CPCI75C3_DSW_GetMaxHiThresholdStatus( int Card, int Module, int Channel, unsigned short *MaxHiThresholdStatus );
_75C3FUNC int CPCI75C3_DSW_GetMaxHiThresholdStatusWord( int Card, int Module, unsigned short *MaxHiThresholdStatusWord );
_75C3FUNC int CPCI75C3_DSW_GetMinLowThresholdStatus( int Card, int Module, int Channel, unsigned short *MinLowThresholdStatus );
_75C3FUNC int CPCI75C3_DSW_GetMinLowThresholdStatusWord( int Card, int Module, unsigned short *MinLowThresholdStatusWord );
_75C3FUNC int CPCI75C3_DSW_GetMidRangeFaultStatus( int Card, int Module, int Channel, unsigned short *MidRangeFaultStatus );
_75C3FUNC int CPCI75C3_DSW_GetMidRangeFaultStatusWord( int Card, int Module, unsigned short *MidRangeFaultStatusWord );
_75C3FUNC int CPCI75C3_DSW_GetLowHiTransStatus( int Card, int Module, int Channel, unsigned short *LowHiTransStatus );
_75C3FUNC int CPCI75C3_DSW_GetLowHiTransStatusWord( int Card, int Module, unsigned short *LowHiTransStatusWord );
_75C3FUNC int CPCI75C3_DSW_GetHiLowTransStatus( int Card, int Module,  int Channel, unsigned short *HiLowTransStatus );
_75C3FUNC int CPCI75C3_DSW_GetHiLowTransStatusWord( int Card, int Module, unsigned short *HiLowTransStatusWord );
_75C3FUNC int CPCI75C3_DSW_SetBITIntEnable( int Card, int Module,  int Channel, unsigned short BITIntEnable );
_75C3FUNC int CPCI75C3_DSW_GetBITIntEnable( int Card, int Module,  int Channel, unsigned short *BITIntEnable );
_75C3FUNC int CPCI75C3_DSW_SetBITIntEnableWord( int Card, int Module, unsigned short BITIntEnableWord );
_75C3FUNC int CPCI75C3_DSW_GetBITIntEnableWord( int Card, int Module, unsigned short *BITIntEnableWord );
_75C3FUNC int CPCI75C3_DSW_SetOverCurrentIntEnable( int Card, int Module, int Channel, unsigned short OverCurrentIntEnable );
_75C3FUNC int CPCI75C3_DSW_GetOverCurrentIntEnable( int Card, int Module, int Channel, unsigned short *OverCurrentIntEnable );
_75C3FUNC int CPCI75C3_DSW_SetOverCurrentIntEnableWord( int Card, int Module, unsigned short OverCurrentIntEnableWord );
_75C3FUNC int CPCI75C3_DSW_GetOverCurrentIntEnableWord( int Card, int Module, unsigned short *OverCurrentIntEnableWord );
_75C3FUNC int CPCI75C3_DSW_SetMaxHiThresholdIntEnable( int Card, int Module, int Channel, unsigned short MaxHiThresholdIntEnable );
_75C3FUNC int CPCI75C3_DSW_GetMaxHiThresholdIntEnable( int Card, int Module, int Channel, unsigned short *MaxHiThresholdIntEnable );
_75C3FUNC int CPCI75C3_DSW_SetMaxHiThresholdIntEnableWord( int Card, int Module, unsigned short MaxHiThresholdIntEnableWord );
_75C3FUNC int CPCI75C3_DSW_GetMaxHiThresholdIntEnableWord( int Card, int Module, unsigned short *MaxHiThresholdIntEnableWord );
_75C3FUNC int CPCI75C3_DSW_SetMinLowThresholdIntEnable( int Card, int Module, int Channel, unsigned short MinLowThresholdIntEnable );
_75C3FUNC int CPCI75C3_DSW_GetMinLowThresholdIntEnable( int Card, int Module, int Channel, unsigned short *MinLowThresholdIntEnable );
_75C3FUNC int CPCI75C3_DSW_SetMinLowThresholdIntEnableWord( int Card, int Module, unsigned short MinLowThresholdIntEnableWord );
_75C3FUNC int CPCI75C3_DSW_GetMinLowThresholdIntEnableWord( int Card, int Module, unsigned short *MinLowThresholdIntEnableWord );
_75C3FUNC int CPCI75C3_DSW_SetMidRangeFaultIntEnable( int Card, int Module, int Channel, unsigned short MidRangeFaultIntEnable );
_75C3FUNC int CPCI75C3_DSW_GetMidRangeFaultIntEnable( int Card, int Module, int Channel, unsigned short *MidRangeFaultIntEnable );
_75C3FUNC int CPCI75C3_DSW_SetMidRangeFaultIntEnableWord( int Card, int Module, unsigned short MidRangeFaultIntEnableWord );
_75C3FUNC int CPCI75C3_DSW_GetMidRangeFaultIntEnableWord( int Card, int Module, unsigned short *MidRangeFaultIntEnableWord );
_75C3FUNC int CPCI75C3_DSW_SetLowHiTransIntEnable( int Card, int Module, int Channel, unsigned short LowHiTransIntEnable );
_75C3FUNC int CPCI75C3_DSW_GetLowHiTransIntEnable( int Card, int Module, int Channel, unsigned short *LowHiTransIntEnable );
_75C3FUNC int CPCI75C3_DSW_SetLowHiTransIntEnableWord( int Card, int Module, unsigned short LowHiTransIntEnableWord );
_75C3FUNC int CPCI75C3_DSW_GetLowHiTransIntEnableWord( int Card, int Module, unsigned short *LowHiTransIntEnableWord );
_75C3FUNC int CPCI75C3_DSW_SetHiLowTransIntEnable( int Card, int Module, int Channel, unsigned short HiLowTransIntEnable );
_75C3FUNC int CPCI75C3_DSW_GetHiLowTransIntEnable( int Card, int Module, int Channel, unsigned short *HiLowTransIntEnable );
_75C3FUNC int CPCI75C3_DSW_SetHiLowTransIntEnableWord( int Card, int Module, unsigned short HiLowTransIntEnableWord );
_75C3FUNC int CPCI75C3_DSW_GetHiLowTransIntEnableWord( int Card, int Module, unsigned short *HiLowTransIntEnableWord );
_75C3FUNC int CPCI75C3_DSW_GetVccVoltage( int Card, int Module, int Channel, double *Voltage );
_75C3FUNC int CPCI75C3_DSW_ResetOverCurrent( int Card,int Module );
_75C3FUNC int CPCI75C3_DSW_GetVoltageRdg( int Card, int Module, int Channel, double *Voltage );
_75C3FUNC int CPCI75C3_DSW_GetVoltageAvgRdg( int Card, int Module, int Channel, int AvgRdgs, double *Voltage );
_75C3FUNC int CPCI75C3_DSW_GetVoltageFiltRdg( int Card, int Module, int Channel, double *Voltage );
_75C3FUNC int CPCI75C3_DSW_GetCurrentRdg( int Card, int Module, int Channel, double *Current );
_75C3FUNC int CPCI75C3_DSW_GetCurrentAvgRdg( int Card, int Module, int Channel, int AvgRdgs, double *Current );
_75C3FUNC int CPCI75C3_DSW_GetCurrentFiltRdg( int Card, int Module, int Channel, double *Current );

_75C3FUNC int CPCI75C3_DSW_GetBITInterruptVector( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DSW_SetBITInterruptVector( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DSW_GetMaxHiThresholdInterruptVector( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DSW_SetMaxHiThresholdInterruptVector( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DSW_GetMinLoThresholdInterruptVector( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DSW_SetMinLoThresholdInterruptVector( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DSW_GetMidRangeInterruptVector( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DSW_SetMidRangeInterruptVector( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DSW_GetOverCurrentInterruptVector( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DSW_SetOverCurrentInterruptVector( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DSW_GetLoHiInterruptVector( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DSW_SetLoHiInterruptVector( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DSW_GetHiLoInterruptVector( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DSW_SetHiLoInterruptVector( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DSW_GetDesignVersion( int Card, int Module, unsigned short *Version );
_75C3FUNC int CPCI75C3_DSW_GetDesignRevision( int Card, int Module, unsigned short *Revision );

/*           INTERNAL USE ONLY                       */
int CPCI75C3_DSW_Init(int Card, int Module);

#ifdef __cplusplus
}
#endif

#endif

