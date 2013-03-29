/*filedoc==================================================================
**
** Copyright (c) 2010 North Atlantic Industries, Inc.  All Rights Reserved.
**
** Author: North Atlantic Industries, Inc.
**
** Project: 75C3 Libraries
**
** SubSystem: 75C3 Power Modules (PS)
**
** FileName: CPCI75C3_PS.h
**
** Description: This file contains header definitions for CPCI75C3.c.
**
** $Archive: /SW Code Base/NAI_CPCI75C3/LibSrc/include/CPCI75C3_PS.h $
**
** $Revision: 5 $
**
** $Date: 2/28/12 1:07p $
**
** $NoKeywords: $
**========================================================================*/
#ifndef _CPCI75C3_PS_H
#define _CPCI75C3_PS_H

#include "CPCI75C3_include.h"

/**************************/
/* PS Module Registers   */
/**************************/
#define CPCI75C3_PS_REG_FAULT_RESET                 (0x002E << ADDR_SHIFT)
#define CPCI75C3_PS_REG_FAULTING_CHANNELS           (0x002C << ADDR_SHIFT)

#define CPCI75C3_PS_REG_CHANNEL_ENABLE              (0x0000 << ADDR_SHIFT)

#define CPCI75C3_PS_REG_FAULT_INDICATION \
   {0x0004 << ADDR_SHIFT, 0x0006 << ADDR_SHIFT}

#define CPCI75C3_PS_REG_USER_CURRENT_LIMIT \
   {0x0008 << ADDR_SHIFT, 0x000A << ADDR_SHIFT}

#define CPCI75C3_PS_REG_NEGATIVE_CURRENT \
   {0x000C << ADDR_SHIFT, 0x0024 << ADDR_SHIFT}

#define CPCI75C3_PS_REG_POSITIVE_CURRENT \
   {0x000E << ADDR_SHIFT, 0x0026 << ADDR_SHIFT}

#define CPCI75C3_PS_REG_NEGATIVE_VOLTAGE \
   {0x0012 << ADDR_SHIFT, 0x002A << ADDR_SHIFT}

#define CPCI75C3_PS_REG_POSITIVE_VOLTAGE \
   {0x0010 << ADDR_SHIFT, 0x0028 << ADDR_SHIFT}

/********************************************************/
/********************** CONSTANTS ***********************/
/********************************************************/
#define CPCI75C3_PS_CHANNEL_OUTPUT_ENABLE \
   {0x0001, 0x0002}

#define CPCI75C3_PS_NO_FAULT_INDICATION             0x0000

/*** PS-15 Specific ***/
#define CPCI75C3_PS_15_VOLTAGE_MAX                  16.0
#define CPCI75C3_PS_15_VOLTAGE_MIN                  -16.0
#define CPCI75C3_PS_15_CURRENT_MAX                  450.0    /* mAmp */
#define CPCI75C3_PS_15_CURRENT_MIN                  -450.0   /* mAmp */

/*** PS-V1 Specific ***/
#define CPCI75C3_PS_V1_NUM_CHANNELS                 1

/*** PS-V2 Specific ***/
#define CPCI75C3_PS_V2_NUM_CHANNELS                 2


/********************************************************/
/****************** EXPORTED FUNCTIONS ******************/
/********************************************************/
#ifdef __cplusplus
extern "C" {
#endif 

/* General use */
_75C3FUNC int CPCI75C3_PS_GetMaxChan( unsigned short uhModuleId, int *pnMaxChan );

/* Output Control */
_75C3FUNC int CPCI75C3_PS_SetOutputState( int nCard, int nModule, int nChannel, int nState );
_75C3FUNC int CPCI75C3_PS_GetOutputState( int nCard, int nModule, int nChannel, int *pnState );
_75C3FUNC int CPCI75C3_PS_GetOutputStateWord( int nCard, int nModule, unsigned short *puhOutputStateWord );
_75C3FUNC int CPCI75C3_PS_SetCurrentLimit( int nCard, int nModule, int nChannel, short hCurrentLimit );
_75C3FUNC int CPCI75C3_PS_GetCurrentLimit( int nCard, int nModule, int nChannel, short *phCurrentLimit );
_75C3FUNC int CPCI75C3_PS_ReadCurrent( int nCard, int nModule, int nChannel, short *phCurrentPositive, short *phCurrentNegative );
_75C3FUNC int CPCI75C3_PS_ReadVoltage( int nCard, int nModule, int nChannel, short *phVoltagePositive, short *phVoltagetNegative );

/* Fault Control */
_75C3FUNC int CPCI75C3_PS_GetFaultingChannels( int nCard, int nModule, short *phFaultingChannels );
_75C3FUNC int CPCI75C3_PS_GetFaultWord( int nCard, int nModule, int nChannel, short *phFaultWord );
_75C3FUNC int CPCI75C3_PS_ResetFault( int nCard, int nModule );

#ifdef __cplusplus
}
#endif

#endif  /* _CPCI75C3_PS_H */
