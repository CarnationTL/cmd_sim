/*+++

Copyright (c) 2004 North Atlantic Industries,

File Name:

 CPCI75C3_DIF.h

Description:

 Include file to the CPCI75C3 - TTL Digital I/O Interface.
 
 This was written in ANSI 'C' for 32-bit integers.

Author: 
Date:  
History:

---*/

#ifndef _CPCI75C3_DIF_H
#define _CPCI75C3_DIF_H

#include "CPCI75C3_include.h"               

#ifdef __cplusplus
extern "C" {
#endif 



/* Some API functions use a slew rate state parameter. */
#define CPCI75C3_SLEW_RATE_SLOW                   0
#define CPCI75C3_SLEW_RATE_FAST                   1
#define CPCI75C3_SLEW_RATE_BANK_SIZE              4

/**************************/
/* DIFF Module Registers  */
/**************************/
#define CPCI75C3_REG_DIF_WRITE_OUTPUT                                 (0x000 << ADDR_SHIFT)
#define CPCI75C3_REG_DIF_READ_IO                                      (0x002 << ADDR_SHIFT)
#define CPCI75C3_REG_DIF_SLEW_RATE                                    (0x09E << ADDR_SHIFT)

#define CPCI75C3_REG_DIF_DEBOUNCE_TIME_ADD {\
 (0x00C << ADDR_SHIFT), (0x016 << ADDR_SHIFT), (0x020 << ADDR_SHIFT), (0x02A << ADDR_SHIFT),\
 (0x034 << ADDR_SHIFT), (0x03E << ADDR_SHIFT), (0x048 << ADDR_SHIFT), (0x052 << ADDR_SHIFT),\
 (0x05C << ADDR_SHIFT), (0x066 << ADDR_SHIFT), (0x070 << ADDR_SHIFT)\
}

#define CPCI75C3_REG_DIF_INPUT_TERMINATION                            (0x0A2 << ADDR_SHIFT)

#define CPCI75C3_REG_DIF_INPUT_OUTPUT_FORMAT_ADD {\
 (0x0A4 << ADDR_SHIFT), (0x0A6 << ADDR_SHIFT)\
}

#define CPCI75C3_REG_DIF_DEBOUNCE_LSB                                 (0x0BA << ADDR_SHIFT)
#define CPCI75C3_REG_DIF_RESET_OVER_CURRENT                           (0x0BC << ADDR_SHIFT)

#define CPCI75C3_REG_DIF_BIT_STATUS                                   (0x0D0 << ADDR_SHIFT)
#define CPCI75C3_REG_DIF_OVER_CURRENT_STATUS                          (0x0D4 << ADDR_SHIFT)
#define CPCI75C3_REG_DIF_LOW_HI_TRANSITION_STATUS                     (0x0DC << ADDR_SHIFT)
#define CPCI75C3_REG_DIF_HI_LOW_TRANSITION_STATUS                     (0x0DE << ADDR_SHIFT)

#define CPCI75C3_REG_DIF_BIT_INT_ENAB                                 (0x0E8 << ADDR_SHIFT)
#define CPCI75C3_REG_DIF_OVER_CURRENT_INT_ENAB                        (0x0EC << ADDR_SHIFT)
#define CPCI75C3_REG_DIF_LOW_HI_TRANSITION_INT_ENAB                   (0x0F4 << ADDR_SHIFT)
#define CPCI75C3_REG_DIF_HI_LOW_TRANSITION_INT_ENAB                   (0x0F6 << ADDR_SHIFT)

#define CPCI75C3_REG_DIF_INT_VECTOR_LOW_HI_TRANSITION                 (0x3C4 << ADDR_SHIFT)
#define CPCI75C3_REG_DIF_INT_VECTOR_HI_LOW_TRANSITION                 (0x3C6 << ADDR_SHIFT)
#define CPCI75C3_REG_DIF_INT_VECTOR_BIT                               (0x3E0 << ADDR_SHIFT)
#define CPCI75C3_REG_DIF_INT_VECTOR_OVERCURRENT                       (0x3E2 << ADDR_SHIFT)

/* DIF Debounce Time with Programmable Debounce LSB (sec)  Calculated as 160E-9 sec x 2^index */ 
#define CPCI75C3_DIF_PGM_DEBOUNCE_TIME_LSB {\
0.00000016, \
0.00000032, \
0.00000064, \
0.00000128, \
0.00000256, \
0.00000512, \
0.00001024, \
0.00002048, \
0.00004096, \
0.00008192, \
0.00016384, \
0.00032768, \
0.00065536, \
0.00131072, \
0.00262144, \
0.00524288  \
}

/****************************************/
/******   DIF Specific Functions   ******/
/****************************************/
/******   DIF Channel Count   ******/
_75C3FUNC int CPCI75C3_DIF_GetMaxChan( unsigned short ModuleID, int *MaxChan );

_75C3FUNC int CPCI75C3_DIF_SetOutputState( int Card, int Module, int Channel, unsigned short OutputState );
_75C3FUNC int CPCI75C3_DIF_GetOutputState( int Card, int Module, int Channel, unsigned short *OutputState );
_75C3FUNC int CPCI75C3_DIF_SetOutputStateWord( int Card, int Module, unsigned short OutputState );
_75C3FUNC int CPCI75C3_DIF_GetOutputStateWord( int Card, int Module, unsigned short *OutputState );
_75C3FUNC int CPCI75C3_DIF_GetInputState( int Card, int Module, int Channel, unsigned short *InputState );
_75C3FUNC int CPCI75C3_DIF_GetInputStateWord( int Card, int Module, unsigned short *InputState );
_75C3FUNC int CPCI75C3_DIF_SetSlewRate( int Card, int Module, int Channel, unsigned short SlewRate );
_75C3FUNC int CPCI75C3_DIF_GetSlewRate( int Card, int Module, int Channel, unsigned short *SlewRate );

/******     DIF Debounce  ******/
_75C3FUNC int CPCI75C3_DIF_SetDebounceLSB( int Card, int Module, unsigned short DebounceLSBUnit );
_75C3FUNC int CPCI75C3_DIF_GetDebounceLSB( int Card, int Module, unsigned short *DebounceLSBUnit );
_75C3FUNC int CPCI75C3_DIF_GetDebounceLSBWeight( int Card, int Module, double *DebounceLSBWeight );
_75C3FUNC int CPCI75C3_DIF_SetDebounceTime( int Card, int Module, int Channel, double DebounceTime );
_75C3FUNC int CPCI75C3_DIF_GetDebounceTime( int Card, int Module, int Channel, double *DebounceTime );
_75C3FUNC int CPCI75C3_DIF_GetDebounceTimeWord( int Card, int Module, int Channel, unsigned short *DebounceTimeWord );

_75C3FUNC int CPCI75C3_DIF_SetInputTermination( int Card, int Module, int Channel, unsigned short InputTermination );
_75C3FUNC int CPCI75C3_DIF_GetInputTermination( int Card, int Module, int Channel, unsigned short *InputTermination );
_75C3FUNC int CPCI75C3_DIF_SetInputTerminationWord( int Card, int Module, unsigned short InputTermination );
_75C3FUNC int CPCI75C3_DIF_GetInputTerminationWord( int Card, int Module, unsigned short *InputTermination );
_75C3FUNC int CPCI75C3_DIF_SetIOFormat( int Card, int Module, int Channel, unsigned short Format );
_75C3FUNC int CPCI75C3_DIF_GetIOFormat( int Card, int Module, int Channel, unsigned short *Format );
_75C3FUNC int CPCI75C3_DIF_GetBITStatus( int Card, int Module, int Channel, unsigned short *BITStatus );
_75C3FUNC int CPCI75C3_DIF_GetBITStatusWord( int Card, int Module, unsigned short *BITStatusWord );
_75C3FUNC int CPCI75C3_DIF_GetOverCurrentStatus( int Card, int Module, int Channel, unsigned short *OverCurrentStatus );
_75C3FUNC int CPCI75C3_DIF_GetOverCurrentStatusWord( int Card, int Module, unsigned short *OverCurrentStatusWord );
_75C3FUNC int CPCI75C3_DIF_GetLowHiTransStatus( int Card, int Module, int Channel, unsigned short *LowHiTransStatus );
_75C3FUNC int CPCI75C3_DIF_GetLowHiTransStatusWord( int Card, int Module, unsigned short *LowHiTransStatusWord );
_75C3FUNC int CPCI75C3_DIF_GetHiLowTransStatus( int Card, int Module, int Channel, unsigned short *HiLowTransStatus );
_75C3FUNC int CPCI75C3_DIF_GetHiLowTransStatusWord( int Card, int Module, unsigned short *HiLowTransStatusWord );
_75C3FUNC int CPCI75C3_DIF_SetBITIntEnable( int Card, int Module, int Channel, unsigned short BITIntEnable );
_75C3FUNC int CPCI75C3_DIF_GetBITIntEnable( int Card, int Module, int Channel, unsigned short *BITIntEnable );
_75C3FUNC int CPCI75C3_DIF_SetBITIntEnableWord( int Card, int Module, unsigned short BITIntEnableWord );
_75C3FUNC int CPCI75C3_DIF_GetBITIntEnableWord( int Card, int Module, unsigned short *BITIntEnableWord );
_75C3FUNC int CPCI75C3_DIF_SetOverCurrentIntEnable( int Card, int Module, int Channel, unsigned short OverCurrentIntEnable );
_75C3FUNC int CPCI75C3_DIF_GetOverCurrentIntEnable( int Card, int Module, int Channel, unsigned short *OverCurrentIntEnable );
_75C3FUNC int CPCI75C3_DIF_SetOverCurrentIntEnableWord( int Card, int Module, unsigned short OverCurrentIntEnableWord );
_75C3FUNC int CPCI75C3_DIF_GetOverCurrentIntEnableWord( int Card, int Module, unsigned short *OverCurrentIntEnableWord );
_75C3FUNC int CPCI75C3_DIF_SetLowHiTransIntEnable( int Card, int Module, int Channel, unsigned short LowHiTransIntEnable );
_75C3FUNC int CPCI75C3_DIF_GetLowHiTransIntEnable( int Card, int Module, int Channel, unsigned short *LowHiTransIntEnable );
_75C3FUNC int CPCI75C3_DIF_SetLowHiTransIntEnableWord( int Card, int Module, unsigned short LowHiTransIntEnableWord );
_75C3FUNC int CPCI75C3_DIF_GetLowHiTransIntEnableWord( int Card, int Module, unsigned short *LowHiTransIntEnableWord );
_75C3FUNC int CPCI75C3_DIF_SetHiLowTransIntEnable( int Card, int Module, int Channel, unsigned short HiLowTransIntEnable );
_75C3FUNC int CPCI75C3_DIF_GetHiLowTransIntEnable( int Card, int Module, int Channel, unsigned short *HiLowTransIntEnable );
_75C3FUNC int CPCI75C3_DIF_SetHiLowTransIntEnableWord( int Card, int Module, unsigned short HiLowTransIntEnableWord );
_75C3FUNC int CPCI75C3_DIF_GetHiLowTransIntEnableWord( int Card, int Module, unsigned short *HiLowTransIntEnableWord );
_75C3FUNC int CPCI75C3_DIF_ResetOverCurrent( int Card, int Module );
_75C3FUNC int CPCI75C3_DIF_SetInputTermination( int Card, int Module, int Channel, unsigned short enab );
_75C3FUNC int CPCI75C3_DIF_GetInputTermination( int Card, int Module, int Channel, unsigned short *enab );

_75C3FUNC int CPCI75C3_DIF_SetBITInterruptVector( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DIF_GetBITInterruptVector( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DIF_SetFaultVector( int Card, int Module, int InterruptVectorFault );
_75C3FUNC int CPCI75C3_DIF_GetFaultVector( int Card, int Module, int *InterruptVectorFault );
_75C3FUNC int CPCI75C3_DIF_SetOverCurrVector( int Card, int Module, int InterruptVectorOverCurrent );
_75C3FUNC int CPCI75C3_DIF_GetOverCurrVector( int Card, int Module, int *InterruptVectorOverCurrent );
_75C3FUNC int CPCI75C3_DIF_SetLoHiTransitionVector( int Card, int Module, int InterruptVectorLoHiTrans );
_75C3FUNC int CPCI75C3_DIF_GetLoHiTransitionVector( int Card, int Module, int *InterruptVectorLoHiTrans );
_75C3FUNC int CPCI75C3_DIF_SetHiLoTransitionVector( int Card, int Module, int InterruptVectorHiLowTrans );
_75C3FUNC int CPCI75C3_DIF_GetHiLoTransitionVector( int Card, int Module, int *InterruptVectorHiLowTrans );
_75C3FUNC int CPCI75C3_DIF_GetOverCurrentInterruptVector( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DIF_SetOverCurrentInterruptVector( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DIF_GetLoHiInterruptVector( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DIF_SetLoHiInterruptVector( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DIF_GetHiLoInterruptVector( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DIF_SetHiLoInterruptVector( int Card, int Module, int InterruptVector );


#ifdef __cplusplus
}
#endif

#endif

