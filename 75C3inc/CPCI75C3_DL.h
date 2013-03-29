/**
 *=========================================================================
 *
 * Copyright (c) 2007 North Atlantic Industries, Inc.  All Rights Reserved.
 *
 * Author: North Atlantic Industries, Inc.
 *
 * Project: CPCI75C3Dll
 *
 * SubSystem: 
 *
 * FileName: CPCI75C3_DL.h
 *=========================================================================
 **/
#ifndef _CPCI75C3_DL_H
#define _CPCI75C3_DL_H

#include "CPCI75C3_include.h"

#ifdef __cplusplus
extern "C" {
#endif 


/**************************/
/*  DL Module Registers   */
/**************************/
/*  Note only using Hi-Word portion of the Angle Data, Wrap Data and Rotation Rate Data  */
/*DLV Wrap Position*/
#define CPCI75C3_REG_DL_WRAP_POSITION_LO_ADDR_A              {0x0000 << ADDR_SHIFT, 0x0004 << ADDR_SHIFT}
#define CPCI75C3_REG_DL_WRAP_POSITION_LO_ADDR_B              {0x0008 << ADDR_SHIFT, 0x000C << ADDR_SHIFT}
#define CPCI75C3_REG_DL_WRAP_POSITION_HI_ADDR_A              {0x0002 << ADDR_SHIFT, 0x0006 << ADDR_SHIFT}
#define CPCI75C3_REG_DL_WRAP_POSITION_HI_ADDR_B              {0x000A << ADDR_SHIFT, 0x000E << ADDR_SHIFT}
#define CPCI75C3_REG_DL_WRAP_POSITION_THREE_CHAN_MOD_LO_ADDR {0x0000 << ADDR_SHIFT, 0x0004 << ADDR_SHIFT, 0x0008 << ADDR_SHIFT}
#define CPCI75C3_REG_DL_WRAP_POSITION_THREE_CHAN_MOD_HI_ADDR {0x0002 << ADDR_SHIFT, 0x0006 << ADDR_SHIFT, 0x000A << ADDR_SHIFT}

#define CPCI75C3_REG_DL_WRAP_LO_ADD                          {0x0000 << ADDR_SHIFT, 0x0004 << ADDR_SHIFT}
#define CPCI75C3_REG_DL_WRAP_HI_ADD                          {0x0002 << ADDR_SHIFT, 0x0006 << ADDR_SHIFT}
#define CPCI75C3_REG_DL_WRAP_ADD                             {0x0002 << ADDR_SHIFT, 0x0006 << ADDR_SHIFT}
#define CPCI75C3_REG_DL_REF_VOLTAGE_IN_ADD                   {0x0032 << ADDR_SHIFT, 0x0034 << ADDR_SHIFT, 0x0036 << ADDR_SHIFT}
#define CPCI75C3_REG_DL_SIG_VOLTAGE_IN_ADD                   {0x0038 << ADDR_SHIFT, 0x003A << ADDR_SHIFT, 0x003C << ADDR_SHIFT}
#define CPCI75C3_REG_DL_SIG_LOSS_THRESHOLD_ADD               {0x0040 << ADDR_SHIFT, 0x0042 << ADDR_SHIFT, 0x0044 << ADDR_SHIFT} 
#define CPCI75C3_REG_DL_REF_LOSS_THRESHOLD_ADD               {0x0046 << ADDR_SHIFT, 0x0048 << ADDR_SHIFT, 0x004A << ADDR_SHIFT} 
#define CPCI75C3_REG_DL_REF_SOURCE_FREQ_ADD                  {0x004C << ADDR_SHIFT, 0x004E << ADDR_SHIFT, 0x0050 << ADDR_SHIFT}
#define CPCI75C3_REG_DL_SIGNAL_STATUS                        (0x0058 << ADDR_SHIFT)
#define CPCI75C3_REG_DL_ResponseFilterTime_ADD               {0x006C << ADDR_SHIFT, 0x006E << ADDR_SHIFT, 0x0070 << ADDR_SHIFT}
#define CPCI75C3_REG_DL_EXP_REF_VOLT_ADD                     {0x00A0 << ADDR_SHIFT, 0x00A4 << ADDR_SHIFT, 0x00A8 << ADDR_SHIFT}
#define CPCI75C3_REG_DL_EXP_VLL_VOLT_ADD                     {0x00B0 << ADDR_SHIFT, 0x00B4 << ADDR_SHIFT, 0x00B8 << ADDR_SHIFT}
#define CPCI75C3_REG_DL_TEST_ENABLE                          (0x00C0 << ADDR_SHIFT)
#define CPCI75C3_REG_DL_D2TEST_VERIFY                        (0x00C4 << ADDR_SHIFT) 
#define CPCI75C3_REG_DL_REFVLL_MODE                          (0x00C6 << ADDR_SHIFT)
#define CPCI75C3_REG_DL_WIRE_MODE                            (0x00CC << ADDR_SHIFT)
#define CPCI75C3_REG_DL_ACTIVE_CHAN                          (0x00E4 << ADDR_SHIFT)

#define CPCI75C3_REG_DL_OUTPUT_ENAB                          (0x00D8 << ADDR_SHIFT)
#define CPCI75C3_REG_DL_CURRENT_ADD                          {0x00DA << ADDR_SHIFT, 0x00DC << ADDR_SHIFT, 0x00DE << ADDR_SHIFT}
#define CPCI75C3_REG_DL_POWER_SUPPLY_DISABLE                 (0x00E0 << ADDR_SHIFT)
#define CPCI75C3_REG_DL_REF_STATUS                           (0x00E6 << ADDR_SHIFT)
#define CPCI75C3_REG_DL_PLL_STATUS                           (0x00E8 << ADDR_SHIFT)
#define CPCI75C3_REG_DL_PHASE_ADD                            {0x00F4 << ADDR_SHIFT, 0x00F6 << ADDR_SHIFT, 0x00F8 << ADDR_SHIFT}
#define CPCI75C3_REG_DL_CURRENT_THRESHOLD_ADD                {0x0100 << ADDR_SHIFT, 0x0102 << ADDR_SHIFT, 0x0104 << ADDR_SHIFT}
#define CPCI75C3_REG_DL_ACCUM_POS_LO_ADD                     {0x0114 << ADDR_SHIFT, 0x0118 << ADDR_SHIFT}
#define CPCI75C3_REG_DL_ACCUM_POS_HI_ADD                     {0x0116 << ADDR_SHIFT, 0x011A << ADDR_SHIFT}
#define CPCI75C3_REG_DL_COMPILE_TIME_ADD                     (0x0120 << ADDR_SHIFT)

/*DLV Position*/
#define CPCI75C3_REG_DL_POSITION_LO_ADDR_A                   {0x0180 << ADDR_SHIFT, 0x0188 << ADDR_SHIFT}
#define CPCI75C3_REG_DL_POSITION_LO_ADDR_B                   {0x0184 << ADDR_SHIFT, 0x018C << ADDR_SHIFT}
#define CPCI75C3_REG_DL_POSITION_HI_ADDR_A                   {0x0182 << ADDR_SHIFT, 0x018A << ADDR_SHIFT}
#define CPCI75C3_REG_DL_POSITION_HI_ADDR_B                   {0x0186 << ADDR_SHIFT, 0x018E << ADDR_SHIFT}
#define CPCI75C3_REG_DL_POSITION_THREE_CHAN_MOD_LO_ADDR      {0x0180 << ADDR_SHIFT, 0x0184 << ADDR_SHIFT, 0x0188 << ADDR_SHIFT}
#define CPCI75C3_REG_DL_POSITION_THREE_CHAN_MOD_HI_ADDR      {0x0182 << ADDR_SHIFT, 0x0186 << ADDR_SHIFT, 0x018A << ADDR_SHIFT}

#define CPCI75C3_REG_DL_BIT_STATUS                           (0x0380 << ADDR_SHIFT)
#define CPCI75C3_REG_DL_REF_STATUS_INT_ENAB                  (0x0382 << ADDR_SHIFT)
#define CPCI75C3_REG_DL_SIGNAL_STATUS_INT_ENAB               (0x0384 << ADDR_SHIFT)
#define CPCI75C3_REG_DL_BIT_STATUS_INT_ENAB                  (0x0386 << ADDR_SHIFT)
#define CPCI75C3_REG_DL_LOCK_STATUS_INT_ENAB                 (0x0388 << ADDR_SHIFT)
                            
#define CPCI75C3_REG_DL_VECTOR_BIT                           (0x03E0 << ADDR_SHIFT)
#define CPCI75C3_REG_DL_VECTOR_REF_LOSS                      (0x03E2 << ADDR_SHIFT)
#define CPCI75C3_REG_DL_VECTOR_SIG_LOSS                      (0x03E4 << ADDR_SHIFT)
#define CPCI75C3_REG_DL_VECTOR_LOCK_LOSS                     (0x03E6 << ADDR_SHIFT)

/******   DLV Specific Functions   ******/

/******   DLV Channel Count   ******/
_75C3FUNC int CPCI75C3_DL_GetMaxChan( unsigned short ModuleID, int *MaxChan );

/******   Position Data   ******/
_75C3FUNC int CPCI75C3_DL_SetPosition( int Card, int Module, int Channel, int SubChannel, double Position );
_75C3FUNC int CPCI75C3_DL_SetPositionWord( int Card, int Module, int Channel, int SubChannel, short PositionWord );
_75C3FUNC int CPCI75C3_DL_GetPosition( int Card, int Module, int Channel, int SubChannel, double *Position );
_75C3FUNC int CPCI75C3_DL_GetPositionWord( int Card, int Module, int Channel, int SubChannel, short *PositionWord );

/******   Position Wrap Data   ******/
_75C3FUNC int CPCI75C3_DL_GetWrapPosition( int Card, int Module, int Channel, int SubChannel, double *WrapPosition );
_75C3FUNC int CPCI75C3_DL_GetWrapPositionWord( int Card, int Module, int Channel, int SubChannel, int *WrapPosition );

/******   Active Channel Setup  ******/
_75C3FUNC int CPCI75C3_DL_SetActiveChannel( int Card, int Module, int Channel, unsigned short Setting );
_75C3FUNC int CPCI75C3_DL_GetActiveChannel( int Card, int Module, int Channel, unsigned short *Setting );
_75C3FUNC int CPCI75C3_DL_SetActiveChannelWord( int Card, int Module, unsigned short ActiveChannelWord );
_75C3FUNC int CPCI75C3_DL_GetActiveChannelWord( int Card, int Module, unsigned short *ActiveChannelWord );

/******   Channel Output   ******/
_75C3FUNC int CPCI75C3_DL_SetChanOutputState( int Card, int Module, int Channel, unsigned short Setting);
_75C3FUNC int CPCI75C3_DL_GetChanOutputState( int Card, int Module, int Channel, unsigned short *Setting);
_75C3FUNC int CPCI75C3_DL_SetOutputStateWord( int Card, int Module, unsigned short OutputStateWord);
_75C3FUNC int CPCI75C3_DL_GetOutputStateWord( int Card, int Module, unsigned short *OutputStateWord);

/******   DL Power Supply Setup   ******/
_75C3FUNC int CPCI75C3_DL_SetPowerSupplyState( int Card, int Module, int Channel, unsigned short Setting );
_75C3FUNC int CPCI75C3_DL_GetPowerSupplyState( int Card, int Module, int Channel, unsigned short* Setting );
_75C3FUNC int CPCI75C3_DL_SetPowerSupplyStateWord( int Card, int Module, unsigned short Setting );
_75C3FUNC int CPCI75C3_DL_GetPowerSupplyStateWord( int Card, int Module, unsigned short* Setting );

/******   Status Registers   ******/
_75C3FUNC int CPCI75C3_DL_GetSignalStatus( int Card, int Module, int Channel, unsigned short *Status );
_75C3FUNC int CPCI75C3_DL_GetSignalStatusWord( int Card, int Module, unsigned short *StatusWord );
_75C3FUNC int CPCI75C3_DL_GetRefStatus( int Card, int Module, int Channel, unsigned short *Status );
_75C3FUNC int CPCI75C3_DL_GetRefStatusWord( int Card, int Module, unsigned short *StatusWord );
_75C3FUNC int CPCI75C3_DL_GetPLLStatus( int Card, int Module, int Channel, unsigned short *Status );
_75C3FUNC int CPCI75C3_DL_GetPLLStatusWord( int Card, int Module, unsigned short *StatusWord );
_75C3FUNC int CPCI75C3_DL_GetBITStatus( int Card, int Module, int Channel, unsigned short *Status );
_75C3FUNC int CPCI75C3_DL_GetBITStatusWord( int Card, int Module, unsigned short *StatusWord );

/******   Phase Data   ******/
_75C3FUNC int CPCI75C3_DL_SetPhase( int Card, int Module, int Channel, double Phase );
_75C3FUNC int CPCI75C3_DL_SetPhaseWord( int Card, int Module, int Channel, unsigned short PhaseWord );
_75C3FUNC int CPCI75C3_DL_GetPhase( int Card, int Module, int Channel, double *Phase );
_75C3FUNC int CPCI75C3_DL_GetPhaseWord( int Card, int Module, int Channel, unsigned short *PhaseWord );

/******   Reference/Line-to-Line Voltage Setup  ******/
_75C3FUNC int CPCI75C3_DL_SetExpRefVoltInput( int Card, int Module, int Channel, double dSetting );
_75C3FUNC int CPCI75C3_DL_GetExpRefVoltInput( int Card, int Module, int Channel, double *Setting );
_75C3FUNC int CPCI75C3_DL_SetExpRefVoltInputWord( int Card, int Module, int Channel, unsigned short Setting );
_75C3FUNC int CPCI75C3_DL_GetExpRefVoltInputWord( int Card, int Module, int Channel, unsigned short *Setting );
_75C3FUNC int CPCI75C3_DL_SetExpVllVoltInput( int Card, int Module, int Channel, double dSetting );
_75C3FUNC int CPCI75C3_DL_GetExpVllVoltInput( int Card, int Module, int Channel, double *Setting );
_75C3FUNC int CPCI75C3_DL_SetExpVllVoltInputWord( int Card, int Module, int Channel, unsigned short Setting );
_75C3FUNC int CPCI75C3_DL_GetExpVllVoltInputWord( int Card, int Module, int Channel, unsigned short *Setting );

/******   Reference Loss Threshold Setup  ******/
_75C3FUNC int CPCI75C3_DL_SetRefLossThreshold( int Card, int Module, int Channel, double dSetting );
_75C3FUNC int CPCI75C3_DL_GetRefLossThreshold( int Card, int Module, int Channel, double *dSetting );
_75C3FUNC int CPCI75C3_DL_SetRefLossThresholdWord( int Card, int Module, int Channel, unsigned short dSetting );
_75C3FUNC int CPCI75C3_DL_GetRefLossThresholdWord( int Card, int Module, int Channel, unsigned short *dSetting );

/******   Signal Line-to-Line Loss Threshold Setup  ******/
_75C3FUNC int CPCI75C3_DL_SetSigLossThreshold( int Card, int Module, int Channel, double dSetting );
_75C3FUNC int CPCI75C3_DL_GetSigLossThreshold( int Card, int Module, int Channel, double *dSetting );
_75C3FUNC int CPCI75C3_DL_SetSigLossThresholdWord( int Card, int Module, int Channel, unsigned short dSetting );
_75C3FUNC int CPCI75C3_DL_GetSigLossThresholdWord( int Card, int Module, int Channel, unsigned short *dSetting );

/******  RefVll Mode (Ratio = 0; Fixed = 1)  ******/
_75C3FUNC int CPCI75C3_DL_SetVllOutputMode( int Card, int Module, int Channel, unsigned short Setting );
_75C3FUNC int CPCI75C3_DL_GetVllOutputMode( int Card, int Module, int Channel, unsigned short *Setting );
_75C3FUNC int CPCI75C3_DL_SetVllOutputModeWord( int Card, int Module, unsigned short Setting );
_75C3FUNC int CPCI75C3_DL_GetVllOutputModeWord( int Card, int Module, unsigned short *Setting );

/******   Channel Modes  4Wire,2Wire  ******/
_75C3FUNC int CPCI75C3_DL_SetWireMode( int Card, int Module, int Channel, unsigned short Mode );
_75C3FUNC int CPCI75C3_DL_GetWireMode( int Card, int Module, int Channel, unsigned short *Mode );
_75C3FUNC int CPCI75C3_DL_SetWireModeWord( int Card, int Module, unsigned short ModeWord );
_75C3FUNC int CPCI75C3_DL_GetWireModeWord( int Card, int Module, unsigned short *ModeWord );

/******   DLV Test Enable   ******/
_75C3FUNC int CPCI75C3_DL_SetTestEnableWord( int Card, int Module, unsigned short TestEnableWord );
_75C3FUNC int CPCI75C3_DL_GetTestEnableWord( int Card, int Module, unsigned short *TestEnableWord );
_75C3FUNC int CPCI75C3_DL_SetD2TestVerifyValue( int Card, int Module, unsigned short Word );
_75C3FUNC int CPCI75C3_DL_GetD2TestVerifyValue( int Card, int Module, unsigned short *Word );

/******     Measured Vref and Vll   *****/ 
_75C3FUNC int CPCI75C3_DL_GetAccumPosition( int Card, int Module, int Channel, double *Angle );
_75C3FUNC int CPCI75C3_DL_GetAccumPositionDoubleWord( int Card, int Module, int Channel, unsigned int *Angle );
_75C3FUNC int CPCI75C3_DL_GetRefReadBackFreq( int Card, int Module, int Channel, unsigned short *RefFreq );
_75C3FUNC int CPCI75C3_DL_GetRefReadBackVoltage( int Card, int Module, int Channel, double *RefInVolt );
_75C3FUNC int CPCI75C3_DL_GetRefReadBackVoltageWord( int Card, int Module, int Channel, unsigned short *RefInVoltWord );
_75C3FUNC int CPCI75C3_DL_GetSigReadBackVoltage( int Card, int Module, int Channel, double *SigInVolt );
_75C3FUNC int CPCI75C3_DL_GetSigReadBackVoltageWord( int Card, int Module, int Channel, unsigned short *SigInVoltWord );

/****** DLV Interrupt Enable  *****/
_75C3FUNC int CPCI75C3_DL_SetSignalStatusIntEnable( int Card, int Module, int Channel, unsigned short SignalStatusIntEnab);
_75C3FUNC int CPCI75C3_DL_GetSignalStatusIntEnable( int Card, int Module, int Channel, unsigned short *SignalStatusIntEnab);
_75C3FUNC int CPCI75C3_DL_SetSignalStatusIntEnableWord( int Card, int Module, unsigned short SignalStatusIntEnab);
_75C3FUNC int CPCI75C3_DL_GetSignalStatusIntEnableWord( int Card, int Module, unsigned short *SignalStatusIntEnab);

_75C3FUNC int CPCI75C3_DL_SetRefStatusIntEnable( int Card, int Module, int Channel, unsigned short RefStatusIntEnab);
_75C3FUNC int CPCI75C3_DL_GetRefStatusIntEnable( int Card, int Module, int Channel, unsigned short *RefStatusIntEnab);
_75C3FUNC int CPCI75C3_DL_SetRefStatusIntEnableWord( int Card, int Module, unsigned short RefStatusIntEnab);
_75C3FUNC int CPCI75C3_DL_GetRefStatusIntEnableWord( int Card, int Module, unsigned short *RefStatusIntEnab);

_75C3FUNC int CPCI75C3_DL_SetBITStatusIntEnable( int Card, int Module, int Channel, unsigned short BITStatusIntEnab);
_75C3FUNC int CPCI75C3_DL_GetBITStatusIntEnable( int Card, int Module, int Channel, unsigned short *BITStatusIntEnab);
_75C3FUNC int CPCI75C3_DL_SetBITStatusIntEnableWord( int Card, int Module, unsigned short BITStatusIntEnab);
_75C3FUNC int CPCI75C3_DL_GetBITStatusIntEnableWord( int Card, int Module, unsigned short *BITStatusIntEnab);

_75C3FUNC int CPCI75C3_DL_SetLockLossIntEnable( int Card, int Module, int Channel, unsigned short LockLossIntEnab);
_75C3FUNC int CPCI75C3_DL_GetLockLossIntEnable( int Card, int Module, int Channel, unsigned short *LockLossIntEnab);
_75C3FUNC int CPCI75C3_DL_SetLockLossIntEnableWord( int Card, int Module, unsigned short LockLossIntEnab);
_75C3FUNC int CPCI75C3_DL_GetLockLossIntEnableWord( int Card, int Module, unsigned short *LockLossIntEnab);

/****** DLV Interrupt Vectors  *****/ 
_75C3FUNC int CPCI75C3_DL_GetSignalLossVector( int Card, int Module, unsigned short *InterruptVector );
_75C3FUNC int CPCI75C3_DL_SetSignalLossVector( int Card, int Module, unsigned short InterruptVector );
_75C3FUNC int CPCI75C3_DL_GetRefLossVector( int Card, int Module, unsigned short *InterruptVector );
_75C3FUNC int CPCI75C3_DL_SetRefLossVector( int Card, int Module, unsigned short InterruptVector );
_75C3FUNC int CPCI75C3_DL_GetBitFailVector( int Card, int Module, unsigned short *InterruptVector );
_75C3FUNC int CPCI75C3_DL_SetBitFailVector( int Card, int Module, unsigned short InterruptVector );
_75C3FUNC int CPCI75C3_DL_GetLockLossVector( int Card, int Module, unsigned short *InterruptVector );
_75C3FUNC int CPCI75C3_DL_SetLockLossVector( int Card, int Module, unsigned short InterruptVector );

/******   Optional Reference Supply Control   ******/
_75C3FUNC int CPCI75C3_DL_SetOnBrdRefFreq( int Card, int Module, unsigned int Frequency );
_75C3FUNC int CPCI75C3_DL_GetOnBrdRefFreq( int Card, int Module, unsigned int *RefFreq );
_75C3FUNC int CPCI75C3_DL_SetOnBrdRefFreqWord( int Card, int Module, unsigned int Frequency );
_75C3FUNC int CPCI75C3_DL_GetOnBrdRefFreqWord( int Card, int Module, unsigned int *RefFreq );
_75C3FUNC int CPCI75C3_DL_SetOnBrdRefVoltage( int Card, int Module, double Voltage );
_75C3FUNC int CPCI75C3_DL_GetOnBrdRefVoltage( int Card, int Module, double *RefVoltage );
_75C3FUNC int CPCI75C3_DL_SetOnBrdRefVoltageWord( int Card, int Module, unsigned int Voltage );
_75C3FUNC int CPCI75C3_DL_GetOnBrdRefVoltageWord( int Card, int Module, unsigned int *RefVoltage );

/******      Compile Time            *****/
_75C3FUNC int CPCI75C3_DL_GetCompileTime( int Card, int Module, unsigned short *CompileTimeBuffer );

/******    Response Filter Time    *****/
_75C3FUNC int CPCI75C3_DL_SetResponseFilterTimeWord( int Card, int Module, int Channel, unsigned short responseFilterTime );
_75C3FUNC int CPCI75C3_DL_GetResponseFilterTimeWord( int Card, int Module, int Channel, unsigned short *responseFilterTime );

/* ################################################################################################# */
/*  For Internal Use Only                                                                            */
/*  Utility functions, do not need to export                                                         */
/* ################################################################################################# */
/******      Current Readings **Internal use only**   ******/
_75C3FUNC int CPCI75C3_DL_GetCurrentWord( int Card, int Module, int Channel, unsigned short *CurrentWord );
_75C3FUNC int CPCI75C3_DL_GetCurrentThresholdWord(int Card, int Module, int Channel, unsigned short *currentThreshold);
_75C3FUNC int CPCI75C3_DL_SetCurrentThresholdWord(int Card, int Module, int Channel, unsigned short currentThreshold);

int CPCI75C3_DLV_CheckCardModuleChannel(int Card, int Module, int Channel);

#ifdef __cplusplus
}
#endif

#endif
