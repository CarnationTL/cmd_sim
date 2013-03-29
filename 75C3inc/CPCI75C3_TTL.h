/*+++

Copyright (c) 2004 North Atlantic Industries,

File Name:

 CPCI75C3_TTL.h

Description:

 Include file to the CPCI75C3 - TTL Digital I/O Interface.
 
 This was written in ANSI 'C' for 32-bit integers.

Author: 
Date:  
History:

---*/

#ifndef _CPCI75C3_TTL_H
#define _CPCI75C3_TTL_H

#include "CPCI75C3_include.h"

#ifdef __cplusplus
extern "C" {
#endif 


/*************************/
/* TTL Module Registers  */
/*************************/
#define CPCI75C3_REG_TTL_WRITE_OUTPUT                                 (0x000 << ADDR_SHIFT)
#define CPCI75C3_REG_TTL_READ_IO                                      (0x002 << ADDR_SHIFT)

#define CPCI75C3_REG_TTL_DEBOUNCE_TIME_ADD {\
 0x00C << ADDR_SHIFT, 0x016 << ADDR_SHIFT, 0x020 << ADDR_SHIFT, 0x02A << ADDR_SHIFT,\
 0x034 << ADDR_SHIFT, 0x03E << ADDR_SHIFT, 0x048 << ADDR_SHIFT, 0x052 << ADDR_SHIFT,\
 0x05C << ADDR_SHIFT, 0x066 << ADDR_SHIFT, 0x070 << ADDR_SHIFT, 0x07A << ADDR_SHIFT,\
 0x084 << ADDR_SHIFT, 0x08E << ADDR_SHIFT, 0x098 << ADDR_SHIFT, 0x0A2 << ADDR_SHIFT \
}

#define CPCI75C3_REG_TTL_INPUT_OUTPUT_FORMAT_ADD                      {(0x0A4 << ADDR_SHIFT), (0x0A6 << ADDR_SHIFT)}
#define CPCI75C3_REG_TTL_DEBOUNCE_LSB                                 (0x0BA << ADDR_SHIFT)
#define CPCI75C3_REG_TTL_RESET_OVER_CURRENT                           (0x0BC << ADDR_SHIFT)

#define CPCI75C3_REG_TTL_BIT_STATUS                                   (0x0D0 << ADDR_SHIFT)

#define CPCI75C3_REG_TTL_OVER_CURRENT_STATUS                          (0x0D4 << ADDR_SHIFT)
#define CPCI75C3_REG_TTL_LOW_HI_TRANSITION_STATUS                     (0x0DC << ADDR_SHIFT)
#define CPCI75C3_REG_TTL_HI_LOW_TRANSITION_STATUS                     (0x0DE << ADDR_SHIFT)

#define CPCI75C3_REG_TTL_BIT_INT_ENAB                                 (0x0E8 << ADDR_SHIFT)
#define CPCI75C3_REG_TTL_OVER_CURRENT_INT_ENAB                        (0x0EC << ADDR_SHIFT)
#define CPCI75C3_REG_TTL_LOW_HI_TRANSITION_INT_ENAB                   (0x0F4 << ADDR_SHIFT)
#define CPCI75C3_REG_TTL_HI_LOW_TRANSITION_INT_ENAB                   (0x0F6 << ADDR_SHIFT)

#define CPCI75C3_REG_TTL_INT_VECTOR_LOW_HI_TRANSITION                 (0x3C4 << ADDR_SHIFT)
#define CPCI75C3_REG_TTL_INT_VECTOR_HI_LOW_TRANSITION                 (0x3C6 << ADDR_SHIFT)
#define CPCI75C3_REG_TTL_INT_VECTOR_BIT                               (0x3E0 << ADDR_SHIFT)
#define CPCI75C3_REG_TTL_INT_VECTOR_OVERCURRENT                       (0x3E2 << ADDR_SHIFT)

/* TTL Debounce Time with Programmable Debounce LSB (usec)  Calculated as 160ns x 2^index */ 
#define CPCI75C3_TTL_PGM_DEBOUNCE_TIME_LSB {\
 0.160, 0.320, 0.640, 1.28, 2.58, 5.12, 10.24, 20.48, \
 40.96, 81.92, 163.84, 327.68, 655.36, 1310.72, 2621.44, 5242.88\
}

   /****************************************/
/******   TTL Specific Functions   ******/
/****************************************/
/******   TTL Channel Count   ******/
_75C3FUNC int CPCI75C3_TTL_GetMaxChan( unsigned short ModuleID, int *MaxChan );

_75C3FUNC int CPCI75C3_TTL_SetOutputState( int Card, int Module, int Channel, unsigned short OutputState );
_75C3FUNC int CPCI75C3_TTL_GetOutputState( int Card, int Module, int Channel, unsigned short *OutputState );
_75C3FUNC int CPCI75C3_TTL_SetOutputStateWord( int Card, int Module, unsigned short OutputState );
_75C3FUNC int CPCI75C3_TTL_GetOutputStateWord( int Card, int Module, unsigned short *OutputState );
_75C3FUNC int CPCI75C3_TTL_GetInputState( int Card, int Module, int Channel, unsigned short *InputState );
_75C3FUNC int CPCI75C3_TTL_GetInputStateWord( int Card, int Module, unsigned short *InputState );
_75C3FUNC int CPCI75C3_TTL_SetDebounceLSB( int Card, int Module, unsigned short DebounceLSBUnit );
_75C3FUNC int CPCI75C3_TTL_GetDebounceLSB( int Card, int Module, unsigned short *DebounceLSBUnit );
_75C3FUNC int CPCI75C3_TTL_GetDebounceLSBWeight( int Card, int Module, double *DebounceLSBWeight );
_75C3FUNC int CPCI75C3_TTL_SetDebounceTime( int Card, int Module, int Channel, double DebounceTime );
_75C3FUNC int CPCI75C3_TTL_GetDebounceTime( int Card, int Module, int Channel, double *DebounceTime );
_75C3FUNC int CPCI75C3_TTL_SetIOFormat( int Card, int Module, int Channel, unsigned short Format );
_75C3FUNC int CPCI75C3_TTL_GetIOFormat( int Card, int Module, int Channel, unsigned short *Format );
_75C3FUNC int CPCI75C3_TTL_GetBITStatus( int Card, int Module, int Channel, unsigned short *BITStatus );
_75C3FUNC int CPCI75C3_TTL_GetBITStatusWord( int Card, int Module, unsigned short *BITStatusWord );
_75C3FUNC int CPCI75C3_TTL_GetOverCurrentStatus( int Card, int Module, int Channel, unsigned short *OverCurrentStatus );
_75C3FUNC int CPCI75C3_TTL_GetOverCurrentStatusWord( int Card, int Module, unsigned short *OverCurrentStatusWord );
_75C3FUNC int CPCI75C3_TTL_GetLowHiTransStatus( int Card, int Module, int Channel, unsigned short *LowHiTransStatus );
_75C3FUNC int CPCI75C3_TTL_GetLowHiTransStatusWord( int Card, int Module, unsigned short *LowHiTransStatusWord );
_75C3FUNC int CPCI75C3_TTL_GetHiLowTransStatus( int Card, int Module, int Channel, unsigned short *HiLowTransStatus );
_75C3FUNC int CPCI75C3_TTL_GetHiLowTransStatusWord( int Card, int Module, unsigned short *HiLowTransStatusWord );
_75C3FUNC int CPCI75C3_TTL_SetBITIntEnable( int Card, int Module, int Channel, unsigned short BITIntEnable );
_75C3FUNC int CPCI75C3_TTL_GetBITIntEnable( int Card, int Module, int Channel, unsigned short *BITIntEnable );
_75C3FUNC int CPCI75C3_TTL_SetBITIntEnableWord( int Card, int Module, unsigned short BITIntEnableWord );
_75C3FUNC int CPCI75C3_TTL_GetBITIntEnableWord( int Card, int Module, unsigned short *BITIntEnableWord );
_75C3FUNC int CPCI75C3_TTL_SetOverCurrentIntEnable( int Card, int Module, int Channel, unsigned short OverCurrentIntEnable );
_75C3FUNC int CPCI75C3_TTL_GetOverCurrentIntEnable( int Card, int Module, int Channel, unsigned short *OverCurrentIntEnable );
_75C3FUNC int CPCI75C3_TTL_SetOverCurrentIntEnableWord( int Card, int Module, unsigned short OverCurrentIntEnableWord );
_75C3FUNC int CPCI75C3_TTL_GetOverCurrentIntEnableWord( int Card, int Module, unsigned short *OverCurrentIntEnableWord );
_75C3FUNC int CPCI75C3_TTL_SetLowHiTransIntEnable( int Card, int Module, int Channel, unsigned short LowHiTransIntEnable );
_75C3FUNC int CPCI75C3_TTL_GetLowHiTransIntEnable( int Card, int Module, int Channel, unsigned short *LowHiTransIntEnable );
_75C3FUNC int CPCI75C3_TTL_SetLowHiTransIntEnableWord( int Card, int Module, unsigned short LowHiTransIntEnableWord );
_75C3FUNC int CPCI75C3_TTL_GetLowHiTransIntEnableWord( int Card, int Module, unsigned short *LowHiTransIntEnableWord );
_75C3FUNC int CPCI75C3_TTL_SetHiLowTransIntEnable( int Card, int Module, int Channel, unsigned short HiLowTransIntEnable );
_75C3FUNC int CPCI75C3_TTL_GetHiLowTransIntEnable( int Card, int Module, int Channel, unsigned short *HiLowTransIntEnable );
_75C3FUNC int CPCI75C3_TTL_SetHiLowTransIntEnableWord( int Card, int Module, unsigned short HiLowTransIntEnableWord );
_75C3FUNC int CPCI75C3_TTL_GetHiLowTransIntEnableWord( int Card, int Module, unsigned short *HiLowTransIntEnableWord );
_75C3FUNC int CPCI75C3_TTL_ResetOverCurrent( int Card, int Module );
#ifdef JAN
_75C3FUNC int CPCI75C3_TTL_SetInputTermination( int Card, int Module, int Channel, unsigned short enab );
_75C3FUNC int CPCI75C3_TTL_GetInputTermination( int Card, int Module, int Channel, unsigned short *enab );
#endif

_75C3FUNC int CPCI75C3_TTL_GetBITInterruptVector( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_TTL_SetBITInterruptVector( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_TTL_GetOverCurrentInterruptVector( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_TTL_SetOverCurrentInterruptVector( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_TTL_GetLoHiInterruptVector( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_TTL_SetLoHiInterruptVector( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_TTL_GetHiLoInterruptVector( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_TTL_SetHiLoInterruptVector( int Card, int Module, int InterruptVector );


#ifdef __cplusplus
}
#endif

#endif

