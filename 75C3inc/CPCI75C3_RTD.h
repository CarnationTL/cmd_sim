/*+++

Copyright (c) 2004 North Atlantic Industries,

File Name:

 CPCI75C3_RTD.h

Description:

 Include file to the CPCI75C3 - Analog/Digital(AD) Converter Board Interface.
 
 This was written in ANSI 'C' for 32-bit integers.

Author: 
Date:  
History:

---*/

#ifndef _CPCI75C3_RTD_H
#define _CPCI75C3_RTD_H

#include "CPCI75C3_include.h"

#ifdef __cplusplus
extern "C" {
#endif 




/*************************/
/* RTD Module Registers  */
/*************************/
/*MOD-RTD-2 REVA module*/
#define RANGE_187_OHM          0
#define RANGE_375_OHM          1
#define RANGE_750_OHM          2
#define RANGE_1500_OHM         3
#define RANGE_3000_OHM         4
#define RANGE_6000_OHM         5
#define RANGE_12000_OHM        6
/*MOD-RTD-2 REVB module*/
#define RANGE_200_OHM          0
#define RANGE_400_OHM          1
#define RANGE_800_OHM          2
#define RANGE_2000_OHM         3
#define RANGE_4000_OHM         4
#define RANGE_8000_OHM         5

/**************************/
/* RTD Module Registers   */
/**************************/
#define CPCI75C3_REG_RTD_DATA_ADD {\
 (0x0000 << ADDR_SHIFT), (0x0002 << ADDR_SHIFT), (0x0004 << ADDR_SHIFT),\
 (0x0006 << ADDR_SHIFT), (0x0008 << ADDR_SHIFT), (0x000A << ADDR_SHIFT)\
}

#define CPCI75C3_REG_RTD_RANGE_ADD {\
 (0x000C << ADDR_SHIFT), (0x000E << ADDR_SHIFT), (0x0010 << ADDR_SHIFT),\
 (0x0012 << ADDR_SHIFT), (0x0014 << ADDR_SHIFT), (0x0016 << ADDR_SHIFT)\
}

#define CPCI75C3_REG_RTD_WireModeRegAddr {\
 (0x0018 << ADDR_SHIFT), (0x001A << ADDR_SHIFT), (0x001C << ADDR_SHIFT),\
 (0x001E << ADDR_SHIFT), (0x0020 << ADDR_SHIFT), (0x0022 << ADDR_SHIFT)\
}

#define CPCI75C3_REG_RTD_WIRE_MODE_ADD {\
 (0x0018 << ADDR_SHIFT), (0x001A << ADDR_SHIFT), (0x001C << ADDR_SHIFT),\
 (0x001E << ADDR_SHIFT), (0x0020 << ADDR_SHIFT), (0x0022 << ADDR_SHIFT)\
}

#define CPCI75C3_REG_RTD_2WIRE_COMPENSATION_RES_ADD {\
 (0x0024 << ADDR_SHIFT), (0x0026 << ADDR_SHIFT), (0x0028 << ADDR_SHIFT),\
 (0x002A << ADDR_SHIFT), (0x002C << ADDR_SHIFT), (0x002E << ADDR_SHIFT)\
}


#define CPCI75C3_REG_RTD_AUX_CAL_CHAN_HI_ADD {\
 (0x0030 << ADDR_SHIFT), (0x0034 << ADDR_SHIFT), (0x0038 << ADDR_SHIFT),\
 (0x003C << ADDR_SHIFT), (0x0040 << ADDR_SHIFT), (0x0044 << ADDR_SHIFT)\
}

#define CPCI75C3_REG_RTD_AUX_CAL_CHAN_LO_ADD {\
 (0x0032 << ADDR_SHIFT), (0x0036 << ADDR_SHIFT), (0x003A << ADDR_SHIFT),\
 (0x003E << ADDR_SHIFT), (0x0042 << ADDR_SHIFT), (0x0046 << ADDR_SHIFT)\
}


#define CPCI75C3_REG_RTD_BUSY                                         (0x00C0 << ADDR_SHIFT)
#define CPCI75C3_REG_RTD_BIT_OPEN_INTERVAL                            (0x00C2 << ADDR_SHIFT)
#define CPCI75C3_REG_RTD_CAL_INTERVAL                                 (0x00C4 << ADDR_SHIFT)

#define CPCI75C3_REG_RTD_BIT_STATUS                                   (0x00D0 << ADDR_SHIFT)
#define CPCI75C3_REG_RTD_OPEN_STATUS                                  (0x00D2 << ADDR_SHIFT)

#define CPCI75C3_REG_RTD_BIT_STATUS_INT_ENAB                          (0x00E8 << ADDR_SHIFT)
#define CPCI75C3_REG_RTD_OPEN_STATUS_INT_ENAB                         (0x00EA << ADDR_SHIFT)
#define CPCI75C3_REG_RTD_CAL_DONE                                     (0x00BE << ADDR_SHIFT)

#define CPCI75C3_REG_RTD_INT_VECTOR_BIT                               (0x03E0 << ADDR_SHIFT)
#define CPCI75C3_REG_RTD_INT_VECTOR_OPEN                              (0x03E2 << ADDR_SHIFT)

#define CPCI75C3_REG_RTD_MODULE_DESIGN_VERSION                        (0x03B4 << ADDR_SHIFT)
#define CPCI75C3_REG_RTD_MODULE_DESIGN_REVISION                       (0x03B6 << ADDR_SHIFT)
#define CPCI75C3_REG_RTD_MODULE_DSP_REV                               (0x03B8 << ADDR_SHIFT)
#define CPCI75C3_REG_RTD_MODULE_FPGA_REV                              (0x03BA << ADDR_SHIFT)
#define CPCI75C3_RTD_CAL_DONE_REG_ADDR                                (0x00BE << ADDR_SHIFT)

/*MOD-RTD-2 REVA module*/
#define CPCI75C3_REG_RTD_CAL_TYPE                                     (0x03AA << ADDR_SHIFT)
#define CPCI75C3_REG_RTD_CAL_CHAN                                     (0x03A8 << ADDR_SHIFT)
#define CPCI75C3_REG_RTD_CAL_RANGE                                    (0x03B0 << ADDR_SHIFT)
#define CPCI75C3_REG_RTD_CAL_VAL_LO                                   (0x03AE << ADDR_SHIFT)
#define CPCI75C3_REG_RTD_CAL_VAL_HI                                   (0x03AC << ADDR_SHIFT)
#define CPCI75C3_RTD_DESIGN_VERSION                                   (0x03B4 << ADDR_SHIFT)
#define CPCI75C3_RTD_DESIGN_REVISION                                  (0x03B6 << ADDR_SHIFT)

/************************************/
/****** RTD Specific Functions ******/
/************************************/
/******   RTD Channel Count   ******/
_75C3FUNC int CPCI75C3_RTD_GetMaxChan( unsigned short ModuleID, int *MaxChan );

_75C3FUNC int CPCI75C3_RTD_GetResistance( int Card, int Module, int Channel, double *Resistance );
_75C3FUNC int CPCI75C3_RTD_GetResistanceWord( int Card, int Module, int Channel, unsigned short *ResistanceWord );
_75C3FUNC int CPCI75C3_RTD_SetCompResistance( int Card, int Module, int Channel, double Resistance );
_75C3FUNC int CPCI75C3_RTD_SetCompResistanceWord( int Card, int Module, int Channel, unsigned short Resistance );
_75C3FUNC int CPCI75C3_RTD_GetCompResistance( int Card, int Module, int Channel, double *Resistance );
_75C3FUNC int CPCI75C3_RTD_GetCompResistanceWord( int Card, int Module, int Channel, unsigned short *Resistance );

_75C3FUNC int CPCI75C3_RTD_SetRange( int Card, int Module, int Channel, unsigned short Range );
_75C3FUNC int CPCI75C3_RTD_GetRange( int Card, int Module, int Channel, unsigned short *Range );
_75C3FUNC int CPCI75C3_RTD_SetWireMode( int Card, int Module, int Channel, unsigned short WireMode );
_75C3FUNC int CPCI75C3_RTD_GetWireMode( int Card, int Module, int Channel, unsigned short *WireMode );
_75C3FUNC int CPCI75C3_RTD_GetBusy( int Card, int Module, unsigned short *Busy );
_75C3FUNC int CPCI75C3_RTD_SetBitOpenInterval( int Card, int Module, unsigned short Bit_Open_Interval );
_75C3FUNC int CPCI75C3_RTD_GetBitOpenInterval( int Card, int Module, unsigned short *Bit_Open_Interval );
_75C3FUNC int CPCI75C3_RTD_SetCalInterval( int Card, int Module, unsigned short Cal_Interval );
_75C3FUNC int CPCI75C3_RTD_GetCalInterval( int Card, int Module, unsigned short *Cal_Interval );
_75C3FUNC int CPCI75C3_RTD_GetBITStatus( int Card, int Module, int Channel, unsigned short *BITStatus );
_75C3FUNC int CPCI75C3_RTD_GetBITStatusWord( int Card, int Module, unsigned short *BITStatus );
_75C3FUNC int CPCI75C3_RTD_SetBITStatusIntEnable( int Card, int Module, int Channel, unsigned short BITStatusIntEnab );
_75C3FUNC int CPCI75C3_RTD_GetBITStatusIntEnable( int Card, int Module, int Channel, unsigned short *BITStatusIntEnab );
_75C3FUNC int CPCI75C3_RTD_SetBITStatusIntEnableWord( int Card,int Module,unsigned short BITStatusIntEnab );
_75C3FUNC int CPCI75C3_RTD_GetBITStatusIntEnableWord( int Card,int Module,unsigned short *BITStatusIntEnab );
_75C3FUNC int CPCI75C3_RTD_GetOpenStatus( int Card, int Module, int Channel, unsigned short *OpenStatus );
_75C3FUNC int CPCI75C3_RTD_GetOpenStatusWord( int Card, int Module, unsigned short *OpenStatus );
_75C3FUNC int CPCI75C3_RTD_SetOpenStatusIntEnable( int Card, int Module, int Channel, unsigned short OpenStatusIntEnab );
_75C3FUNC int CPCI75C3_RTD_GetOpenStatusIntEnable( int Card, int Module, int Channel, unsigned short *OpenStatusIntEnab );
_75C3FUNC int CPCI75C3_RTD_SetOpenStatusIntEnableWord( int Card, int Module, unsigned short OpenStatusIntEnab );
_75C3FUNC int CPCI75C3_RTD_GetOpenStatusIntEnableWord( int Card, int Module, unsigned short *OpenStatusIntEnab );
_75C3FUNC int CPCI75C3_RTD_GetOpenStatusIntEnableWord( int Card, int Module, unsigned short *CalDoneStatus );
/* internal used RTD Cal functions */
_75C3FUNC int CPCI75C3_RTD_GetCalDoneStatus( int Card, int Module, unsigned short *CalDoneStatus );
_75C3FUNC int CPCI75C3_RTD_SetCalType( int Card, int Module, unsigned short CalType );
_75C3FUNC int CPCI75C3_RTD_SetCalChan( int Card, int Module, unsigned short CalChan );
_75C3FUNC int CPCI75C3_RTD_SetCalRange( int Card, int Module, unsigned short CalRange );
_75C3FUNC int CPCI75C3_RTD_WrtCalValHi( int Card, int Module, unsigned short CalValHi );
_75C3FUNC int CPCI75C3_RTD_RdAuxCalValHi( int Card, int Module, int Channel, unsigned short *AuxCalValHi);

/******   RTD Interrupt Vector  ******/
_75C3FUNC int CPCI75C3_RTD_GetBITInterruptVector( int Card, int Module, unsigned short *InterruptVector );
_75C3FUNC int CPCI75C3_RTD_SetBITInterruptVector( int Card, int Module, unsigned short InterruptVector );
_75C3FUNC int CPCI75C3_RTD_GetOpenInterruptVector( int Card, int Module, unsigned short *InterruptVector );
_75C3FUNC int CPCI75C3_RTD_SetOpenInterruptVector( int Card, int Module, unsigned short InterruptVector );

/******   Revisions   ******/
#ifdef JAN
_75C3FUNC int CPCI75C3_RTD_GetModuleDesignVersion( int Card, int Module, unsigned short *Version );
#endif
_75C3FUNC int CPCI75C3_RTD_GetModuleDesignRevision( int Card, int Module, unsigned short *Revision );


/* ################################################################################################# */
/*  For Internal Use Only                                                                            */
/*  Utility functions, do not need to export                                                         */
/* ################################################################################################# */
int CPCI75C3_RTD_CheckCardModuleChannel(int Card, int Module, int Channel);
/* internally used RTD Cal functions */
_75C3FUNC int CPCI75C3_RTD_SetCalType( int Card, int Module, unsigned short CalType );

#ifdef __cplusplus
}
#endif

#endif

