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
 * FileName: CPCI75C3_LVDT.h
 *=========================================================================
 **/

#ifndef _CPCI75C3_LVDT_H
#define _CPCI75C3_LVDT_H

#include "CPCI75C3_include.h"

#ifdef __cplusplus
extern "C" {
#endif 

/* LVDT Definitions for Bandwidth Select parameter. */
#define CPCI75C3_LVDT_BWSelect_Manual              0
#define CPCI75C3_LVDT_BWSelect_Auto                1

/* common definitions for DLV and LVDT */
#define LVDT_POSITION_BIT16   50.0/0x7FFF         
#define LVDT_POSITION_BIT32   50.0/0x7FFFFFFF
#define D0_POS_SIGN           1/0x7FFF
#define POSITION_BIT16        0.0000305176                   /* 2/65536 */
#define Position_BIT16        0.0054931640625
#define POSITION_BIT17        0.0000152588                   /* 2/131072 */

/**************************/
/* LVDT Module Registers  */
/**************************/
#define CPCI75C3_REG_LVDT_POSITION_DATA_LO                     {0x0000 << ADDR_SHIFT, 0x0004 << ADDR_SHIFT, 0x0008 << ADDR_SHIFT, 0x000C << ADDR_SHIFT}
#define CPCI75C3_REG_LVDT_POSITION_DATA_HI                     {0x0002 << ADDR_SHIFT, 0x0006 << ADDR_SHIFT, 0x000A << ADDR_SHIFT, 0x000E << ADDR_SHIFT}
#define CPCI75C3_REG_LVDT_VELOCITY_LO                          {0x0010 << ADDR_SHIFT, 0x0014 << ADDR_SHIFT, 0x0018 << ADDR_SHIFT, 0x001C << ADDR_SHIFT}
#define CPCI75C3_REG_LVDT_VELOCITY_HI                          {0x0012 << ADDR_SHIFT, 0x0016 << ADDR_SHIFT, 0x001A << ADDR_SHIFT, 0x001E << ADDR_SHIFT}
#define CPCI75C3_REG_LVDT_BANDWIDTH                            {0x0020 << ADDR_SHIFT, 0x0022 << ADDR_SHIFT, 0x0024 << ADDR_SHIFT, 0x0026 << ADDR_SHIFT}
#define CPCI75C3_REG_LVDT_BANDWIDTH_SELECT                     (0x0028 << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_RATIO                                {0x002A << ADDR_SHIFT, 0x002A << ADDR_SHIFT, 0x002C << ADDR_SHIFT, 0x002C << ADDR_SHIFT}
#define CPCI75C3_REG_LVDT_ACTIVE_CHANNELS                      (0x002E << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_LATCH_CTL                            (0x0030 << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_D2TEST_VERIFY                        (0x0032 << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_TEST_ENABLE                          (0x0034 << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_TEST_POSITION                        (0x0038 << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_SYNCHRO_RESOLVER_LVDT                (0x003C << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_SYNCHRO_RESOLVER                     (0x003E << ADDR_SHIFT) 

#define CPCI75C3_REG_LVDT_POSITION_DELTA                       {0x0040 << ADDR_SHIFT, 0x0042 << ADDR_SHIFT, 0x0044 << ADDR_SHIFT, 0x0046 << ADDR_SHIFT}
#define CPCI75C3_REG_LVDT_POSITION_DELTA_INIT                  (0x004E << ADDR_SHIFT) 


#define CPCI75C3_REG_LVDT_FREQUENCY_LO                         {0x0050 << ADDR_SHIFT, 0x0054 << ADDR_SHIFT, 0x0058 << ADDR_SHIFT, 0x005C << ADDR_SHIFT}
#define CPCI75C3_REG_LVDT_FREQUENCY_HI                         {0x0052 << ADDR_SHIFT, 0x0056 << ADDR_SHIFT, 0x005A << ADDR_SHIFT, 0x005E << ADDR_SHIFT}
#define CPCI75C3_REG_LVDT_VLL                                  {0x0060 << ADDR_SHIFT, 0x0062 << ADDR_SHIFT, 0x0064 << ADDR_SHIFT, 0x0066 << ADDR_SHIFT}
#define CPCI75C3_REG_LVDT_VREF                                 {0x0068 << ADDR_SHIFT, 0x006A << ADDR_SHIFT, 0x006C << ADDR_SHIFT, 0x006E << ADDR_SHIFT}
#define CPCI75C3_REG_LVDT_AB_RES                               {0x0070 << ADDR_SHIFT, 0x0072 << ADDR_SHIFT, 0x0074 << ADDR_SHIFT, 0x0076 << ADDR_SHIFT}

#define CPCI75C3_REG_LVDT_SIG_LOSS_THRESHOLD                   {0x0080 << ADDR_SHIFT, 0x0082 << ADDR_SHIFT, 0x0084 << ADDR_SHIFT, 0x0086 << ADDR_SHIFT}
#define CPCI75C3_REG_LVDT_REF_LOSS_THRESHOLD                   {0x0088 << ADDR_SHIFT, 0x008A << ADDR_SHIFT, 0x008C << ADDR_SHIFT, 0x008E << ADDR_SHIFT}
#define CPCI75C3_REG_LVDT_SCALE                                {0x00A0 << ADDR_SHIFT, 0x00A2 << ADDR_SHIFT, 0x00A4 << ADDR_SHIFT, 0x00A6 << ADDR_SHIFT}
#define CPCI75C3_REG_LVDT_VELOCITY_SCALE                       {0x00A8 << ADDR_SHIFT, 0x00AA << ADDR_SHIFT, 0x00AC << ADDR_SHIFT, 0x00AE << ADDR_SHIFT}

#define CPCI75C3_REG_LVDT_SIGNAL_STATUS                        (0x00E8 << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_REF_STATUS                           (0x00EA << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_BIT_STATUS							      (0x0380 << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_TWO_SPEED_LOCK_LOSS                  (0x00EE << ADDR_SHIFT)

#define CPCI75C3_REG_LVDT_POSITION_DELTA_ALERT                 (0x00F0 << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_SIGNAL_STATUS_INT_ENAB               (0x00F2 << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_REF_STATUS_INT_ENAB                  (0x00F4 << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_BIT_STATUS_INT_ENAB                  (0x00F6 << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_LOCK_STATUS_INT_ENAB                 (0x00F8 << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_POSITION_DELTA_ALERT_INT_ENAB        (0x00FA << ADDR_SHIFT)

#define CPCI75C3_REG_LVDT_BIT_STATUS_INT_VECTOR                (0x03E0 << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_SIGNAL_STATUS_INT_VECTOR             (0x03E2 << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_REF_STATUS_INT_VECTOR                (0x03E4 << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_LOCK_STATUS_INT_VECTOR               (0x03E6 << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_ANGLE_DELTA_ALERT_INT_VECTOR         (0x03E8 << ADDR_SHIFT)

#define CPCI75C3_REG_LVDT_DATA_BUFFER_WORD                     {0x0300 << ADDR_SHIFT, 0x0302 << ADDR_SHIFT, 0x0304 << ADDR_SHIFT, 0x0306 << ADDR_SHIFT}
#define CPCI75C3_REG_LVDT_DATA_BUFFER_COUNT                    {0x0308 << ADDR_SHIFT, 0x030A << ADDR_SHIFT, 0x030C << ADDR_SHIFT, 0x030E << ADDR_SHIFT}
#define CPCI75C3_REG_LVDT_DATA_BUFFER_STATUS                   {0x0310 << ADDR_SHIFT, 0x0312 << ADDR_SHIFT, 0x0314 << ADDR_SHIFT, 0x0316 << ADDR_SHIFT}
#define CPCI75C3_REG_LVDT_DATA_BUFFER_HI_WATERMARK             {0x0320 << ADDR_SHIFT, 0x0330 << ADDR_SHIFT, 0x0340 << ADDR_SHIFT, 0x0350 << ADDR_SHIFT}
#define CPCI75C3_REG_LVDT_DATA_BUFFER_LO_WATERMARK             {0x0322 << ADDR_SHIFT, 0x0332 << ADDR_SHIFT, 0x0342 << ADDR_SHIFT, 0x0352 << ADDR_SHIFT}
#define CPCI75C3_REG_LVDT_DATA_BUFFER_SAMPLE_DELAY             {0x0324 << ADDR_SHIFT, 0x0334 << ADDR_SHIFT, 0x0344 << ADDR_SHIFT, 0x0354 << ADDR_SHIFT}
#define CPCI75C3_REG_LVDT_DATA_BUFFER_NUM_OF_SAMPLES           {0x0326 << ADDR_SHIFT, 0x0336 << ADDR_SHIFT, 0x0346 << ADDR_SHIFT, 0x0356 << ADDR_SHIFT}							
#define CPCI75C3_REG_LVDT_DATA_BUFFER_SAMPLE_RATE	            {0x0328 << ADDR_SHIFT, 0x0338 << ADDR_SHIFT, 0x0348 << ADDR_SHIFT, 0x0358 << ADDR_SHIFT}
#define CPCI75C3_REG_LVDT_DATA_BUFFER_CLEAR_FIFO               {0x032A << ADDR_SHIFT, 0x033A << ADDR_SHIFT, 0x034A << ADDR_SHIFT, 0x035A << ADDR_SHIFT}
#define CPCI75C3_REG_LVDT_DATA_BUFFER_DATA_TYPE                {0x032C << ADDR_SHIFT, 0x033C << ADDR_SHIFT, 0x034C << ADDR_SHIFT, 0x035C << ADDR_SHIFT}
#define CPCI75C3_REG_LVDT_DATA_BUFFER_TRIG_MODE                {0x032E << ADDR_SHIFT, 0x033E << ADDR_SHIFT, 0x034E << ADDR_SHIFT, 0x035E << ADDR_SHIFT}
#define CPCI75C3_REG_LVDT_DATA_BUFFER_SEND_SW_TRIG             (0x0360 << ADDR_SHIFT)

#define CPCI75C3_REG_LVDT_MODULE_DESIGN_VERSION                (0x03B4 << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_MODULE_DESIGN_REVISION               (0x03B6 << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_MODULE_DSP_REV                       (0x03B8 << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_MODULE_FPGA_REV                      (0x03BA << ADDR_SHIFT)

#define CPCI75C3_REG_LVDT_COMPILE_TIME_ADD                     (0x01E0 << ADDR_SHIFT)

/* ON BOARD OSCILLATOR REGISTERS */
#define CPCI75C3_REG_LVDT_REF_FREQUENCY_LO                     (0x0100 << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_REF_FREQUENCY_HI                     (0x0102 << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_REF_VOLTAGE_LO                       (0x0104 << ADDR_SHIFT)
#define CPCI75C3_REG_LVDT_REF_VOLTAGE_HI                       (0x0106 << ADDR_SHIFT)


/* ################################################################################################# */
/* START LVDT FUNCTIONS */
/* ################################################################################################# */
/******   LVDT Channel Count   ******/
_75C3FUNC int CPCI75C3_LVDT_GetMaxChan( unsigned short ModuleID, int *MaxChan );

/******   Position Data / Scale   ******/
_75C3FUNC int CPCI75C3_LVDT_GetPosition( int Card, int Module, int Channel, double *Position );
_75C3FUNC int CPCI75C3_LVDT_GetPositionWord( int Card, int Module, int Channel, unsigned short *PositionWord );
_75C3FUNC int CPCI75C3_LVDT_GetPositionDoubleWord( int Card, int Module, int Channel, unsigned int *PositionWord );
_75C3FUNC int CPCI75C3_LVDT_SetLVDTScale( int Card, int Module, int Channel, unsigned short LVDTScale );
_75C3FUNC int CPCI75C3_LVDT_GetLVDTScale( int Card, int Module, int Channel, unsigned short *LVDTScale );

/******   Velocity Data / Scale   ******/
_75C3FUNC int CPCI75C3_LVDT_GetVelocity( int Card, int Module, int Channel, double *Velocity );
_75C3FUNC int CPCI75C3_LVDT_GetVelocityWord( int Card, int Module, int Channel, signed short *VelocityWord );
_75C3FUNC int CPCI75C3_LVDT_GetVelocityDoubleWord( int Card, int Module, int Channel, signed int *VelocityWord );
_75C3FUNC int CPCI75C3_LVDT_SetVelScale( int Card, int Module, int Channel, unsigned short VelScale );
_75C3FUNC int CPCI75C3_LVDT_GetVelScale( int Card, int Module, int Channel, unsigned short *VelScale );

/******   Channel Modes (2Wire,4Wire) ******/
_75C3FUNC int CPCI75C3_LVDT_SetChanMode( int Card, int Module, int Channel, unsigned short Mode );
_75C3FUNC int CPCI75C3_LVDT_GetChanMode( int Card, int Module, int Channel, unsigned short *Mode );
_75C3FUNC int CPCI75C3_LVDT_SetChanModeWord( int Card, int Module, unsigned short Mode );
_75C3FUNC int CPCI75C3_LVDT_GetChanModeWord( int Card, int Module, unsigned short *Mode );

/****** Bandwidth ******/
_75C3FUNC int CPCI75C3_LVDT_SetBandwidth( int Card, int Module, int Channel, unsigned short Bandwidth );
_75C3FUNC int CPCI75C3_LVDT_GetBandwidth( int Card, int Module, int Channel, unsigned short* Bandwidth );
_75C3FUNC int CPCI75C3_LVDT_SetBandwidthSelect ( int Card, int Module, int Channel, unsigned short BWSelect);
_75C3FUNC int CPCI75C3_LVDT_GetBandwidthSelect ( int Card, int Module, int Channel, unsigned short *BWSelect);
_75C3FUNC int CPCI75C3_LVDT_SetBandwidthSelectWord( int Card, int Module, unsigned short BWSelect);
_75C3FUNC int CPCI75C3_LVDT_GetBandwidthSelectWord( int Card, int Module, unsigned short *BWSelect);

/******   Latch   ******/
_75C3FUNC int CPCI75C3_LVDT_SetLatch( int Card, int Module, int Channel, unsigned short Latch );
_75C3FUNC int CPCI75C3_LVDT_GetLatch( int Card, int Module, int Channel, unsigned short* Latch );
_75C3FUNC int CPCI75C3_LVDT_SetLatchWord( int Card, int Module, unsigned short Latch );
_75C3FUNC int CPCI75C3_LVDT_GetLatchWord( int Card, int Module, unsigned short* Latch );
/*  NOTE: The function implementation and prototype for CPCI75C3_LVDT_SetLatch() and CPCI75C3_LVDT_SetLatch() have been
 *        changed to accommodate for firmware changes.  Users who used the former function implementation can 
 *        use the function CPCI75C3_LVDT_SetLatchWord() and CPCI75C3_LVDT_SetLatchWord(). Please look at the Operations
 *        Manual for register definition as it has been changed. 
 */

/******   Test Modes   ******/
_75C3FUNC int CPCI75C3_LVDT_SetTestPosition( int Card, int Module, double TestPosition );
_75C3FUNC int CPCI75C3_LVDT_GetTestPosition( int Card, int Module, double *TestPosition );
_75C3FUNC int CPCI75C3_LVDT_SetTestPositionWord( int Card, int Module, unsigned short TestPosition );
_75C3FUNC int CPCI75C3_LVDT_GetTestPositionWord( int Card, int Module, unsigned short *TestPositionWord );

/******   LVDT Test Enable  ******/
_75C3FUNC int CPCI75C3_LVDT_GetTestEnableWord( int Card, int Module, unsigned short *TestEnableWord );
_75C3FUNC int CPCI75C3_LVDT_SetTestEnableWord( int Card, int Module, unsigned short TestEnableWord );
_75C3FUNC int CPCI75C3_LVDT_SetD2TestVerifyValue( int Card, int Module, unsigned short Word );
_75C3FUNC int CPCI75C3_LVDT_GetD2TestVerifyValue( int Card, int Module, unsigned short *Word );

/******   Active Channel Setup  ******/
_75C3FUNC int CPCI75C3_LVDT_SetActiveChannel( int Card, int Module, int Channel, unsigned short Setting );
_75C3FUNC int CPCI75C3_LVDT_GetActiveChannel( int Card, int Module, int Channel, unsigned short *Setting );
_75C3FUNC int CPCI75C3_LVDT_SetActiveChannelWord( int Card, int Module, unsigned short ActiveChannelWord );
_75C3FUNC int CPCI75C3_LVDT_GetActiveChannelWord( int Card, int Module, unsigned short *ActiveChannelWord );

/******   Position Change Alert   ******/
_75C3FUNC int CPCI75C3_LVDT_SetPositionDelta( int Card, int Module, int Channel, double PositionDelta );
_75C3FUNC int CPCI75C3_LVDT_GetPositionDelta( int Card, int Module, int Channel, double *PositionDelta );
_75C3FUNC int CPCI75C3_LVDT_SetPositionDeltaWord( int Card, int Module, int Channel, unsigned short PositionDelta );
_75C3FUNC int CPCI75C3_LVDT_GetPositionDeltaWord( int Card, int Module, int Channel, unsigned short *PositionDeltaWord );
_75C3FUNC int CPCI75C3_LVDT_SetPositionDeltaInit( int Card, int Module, unsigned short Setting );

/****** Chan Freq ******/
_75C3FUNC int CPCI75C3_LVDT_GetChanFrequency( int Card, int Module, int Channel, double* Frequency );
_75C3FUNC int CPCI75C3_LVDT_GetChanFrequencyWord( int Card, int Module, int Channel, int* Frequency );

/****** Chan VLL ******/
_75C3FUNC int CPCI75C3_LVDT_GetChanSigVLL( int Card, int Module, int Channel, double* SigVLL );
_75C3FUNC int CPCI75C3_LVDT_GetChanSigVLLWord( int Card, int Module, int Channel, unsigned short* SigVLL );
_75C3FUNC int CPCI75C3_LVDT_SetSigLossThreshold( int Card, int Module, int Channel, double  Threshold );
_75C3FUNC int CPCI75C3_LVDT_GetSigLossThreshold( int Card, int Module, int Channel, double* Threshold );
_75C3FUNC int CPCI75C3_LVDT_SetSigLossThresholdWord( int Card, int Module, int Channel, unsigned short Threshold );
_75C3FUNC int CPCI75C3_LVDT_GetSigLossThresholdWord( int Card, int Module, int Channel, unsigned short* Threshold );

/****** Chan Ref ******/
_75C3FUNC int CPCI75C3_LVDT_GetChanRefVolt( int Card, int Module, int Channel, double* RefVolt );
_75C3FUNC int CPCI75C3_LVDT_GetChanRefVoltWord( int Card, int Module, int Channel, unsigned short* RefVolt );
_75C3FUNC int CPCI75C3_LVDT_SetRefLossThreshold( int Card, int Module, int Channel, double  Threshold );
_75C3FUNC int CPCI75C3_LVDT_GetRefLossThreshold( int Card, int Module, int Channel, double* Threshold );
_75C3FUNC int CPCI75C3_LVDT_SetRefLossThresholdWord( int Card, int Module, int Channel, unsigned short Threshold );
_75C3FUNC int CPCI75C3_LVDT_GetRefLossThresholdWord( int Card, int Module, int Channel, unsigned short* Threshold );

/******   Status Registers   ******/
_75C3FUNC int CPCI75C3_LVDT_GetSignalStatus( int Card, int Module, int Channel, unsigned short *Status );
_75C3FUNC int CPCI75C3_LVDT_GetSignalStatusWord( int Card, int Module, unsigned short *StatusWord );
_75C3FUNC int CPCI75C3_LVDT_GetRefStatus( int Card, int Module, int Channel, unsigned short *Status );
_75C3FUNC int CPCI75C3_LVDT_GetRefStatusWord( int Card, int Module, unsigned short *StatusWord );
_75C3FUNC int CPCI75C3_LVDT_GetBITStatus( int Card, int Module, int Channel, unsigned short *Status );
_75C3FUNC int CPCI75C3_LVDT_GetBITStatusWord( int Card, int Module, unsigned short *StatusWord );
_75C3FUNC int CPCI75C3_LVDT_GetTwoSpeedLockLoss( int Card, int Module, int Channel, unsigned short *TwoSpeedLockLoss );
_75C3FUNC int CPCI75C3_LVDT_GetTwoSpeedLockLossWord( int Card, int Module, unsigned short *TwoSpeedLockLossWord );
_75C3FUNC int CPCI75C3_LVDT_GetPositionDeltaAlert( int Card, int Module, int Channel, unsigned short *PositionDeltaAlert );
_75C3FUNC int CPCI75C3_LVDT_GetPositionDeltaAlertWord( int Card, int Module, unsigned short *StatusWord );

/******   Interrupt Enable Setup   ******/
_75C3FUNC int CPCI75C3_LVDT_SetSignalStatusIntEnable( int Card, int Module, int Channel, unsigned short SignalStatusIntEnab );
_75C3FUNC int CPCI75C3_LVDT_GetSignalStatusIntEnable( int Card, int Module, int Channel, unsigned short *SignalStatusIntEnab );
_75C3FUNC int CPCI75C3_LVDT_SetSignalStatusIntEnableWord( int Card, int Module, unsigned short SignalStatusIntEnab );
_75C3FUNC int CPCI75C3_LVDT_GetSignalStatusIntEnableWord( int Card, int Module, unsigned short *SignalStatusIntEnab );
_75C3FUNC int CPCI75C3_LVDT_SetRefStatusIntEnable( int Card, int Module, int Channel, unsigned short RefStatusIntEnab );
_75C3FUNC int CPCI75C3_LVDT_GetRefStatusIntEnable( int Card, int Module, int Channel, unsigned short *RefStatusIntEnab );
_75C3FUNC int CPCI75C3_LVDT_SetRefStatusIntEnableWord( int Card, int Module, unsigned short RefStatusIntEnab );
_75C3FUNC int CPCI75C3_LVDT_GetRefStatusIntEnableWord( int Card, int Module, unsigned short *RefStatusIntEnab );
_75C3FUNC int CPCI75C3_LVDT_SetBITStatusIntEnable( int Card, int Module, int Channel, unsigned short BITStatusIntEnab );
_75C3FUNC int CPCI75C3_LVDT_GetBITStatusIntEnable( int Card, int Module, int Channel, unsigned short *BITStatusIntEnab );
_75C3FUNC int CPCI75C3_LVDT_SetBITStatusIntEnableWord( int Card, int Module, unsigned short BITStatusIntEnab );
_75C3FUNC int CPCI75C3_LVDT_GetBITStatusIntEnableWord( int Card, int Module, unsigned short *BITStatusIntEnab );
_75C3FUNC int CPCI75C3_LVDT_SetLockLossIntEnable( int Card, int Module, int Channel, unsigned short LockLossIntEnab );
_75C3FUNC int CPCI75C3_LVDT_GetLockLossIntEnable( int Card, int Module, int Channel, unsigned short *LockLossIntEnab );
_75C3FUNC int CPCI75C3_LVDT_SetLockLossIntEnableWord( int Card, int Module, unsigned short LockLossIntEnab );
_75C3FUNC int CPCI75C3_LVDT_GetLockLossIntEnableWord( int Card, int Module, unsigned short *LockLossIntEnab );
_75C3FUNC int CPCI75C3_LVDT_SetPositionDeltaAlertIntEnable( int Card, int Module, int Channel, unsigned short PositionDeltaAlertIntEnab );
_75C3FUNC int CPCI75C3_LVDT_GetPositionDeltaAlertIntEnable( int Card, int Module, int Channel, unsigned short *PositionDeltaAlertIntEnab );
_75C3FUNC int CPCI75C3_LVDT_SetPositionDeltaAlertIntEnableWord( int Card, int Module, unsigned short PositionDeltaAlertIntEnab );
_75C3FUNC int CPCI75C3_LVDT_GetPositionDeltaAlertIntEnableWord( int Card, int Module, unsigned short *PositionDeltaAlertIntEnab );


/******   LVDT Interrupt Vector Setup   ******/
_75C3FUNC int CPCI75C3_LVDT_GetSignalStatusInterruptVector( int Card, int Module, unsigned short *InterruptVector );
_75C3FUNC int CPCI75C3_LVDT_SetSignalStatusInterruptVector( int Card, int Module, unsigned short InterruptVector );
_75C3FUNC int CPCI75C3_LVDT_GetRefStatusInterruptVector( int Card, int Module, unsigned short *InterruptVector );
_75C3FUNC int CPCI75C3_LVDT_SetRefStatusInterruptVector( int Card, int Module, unsigned short InterruptVector );
_75C3FUNC int CPCI75C3_LVDT_GetBITStatusInterruptVector( int Card, int Module, unsigned short *InterruptVector );
_75C3FUNC int CPCI75C3_LVDT_SetBITStatusInterruptVector( int Card, int Module, unsigned short InterruptVector );

/******   Data Buffers Setup   ******/
_75C3FUNC int CPCI75C3_LVDT_SetDataBufferHiWatermark( int Card, int Module, int Channel, unsigned short Watermark );
_75C3FUNC int CPCI75C3_LVDT_GetDataBufferHiWatermark( int Card, int Module, int Channel, unsigned short *Watermark );
_75C3FUNC int CPCI75C3_LVDT_SetDataBufferLoWatermark( int Card, int Module, int Channel, unsigned short Watermark );
_75C3FUNC int CPCI75C3_LVDT_GetDataBufferLoWatermark( int Card, int Module, int Channel, unsigned short *Watermark );
_75C3FUNC int CPCI75C3_LVDT_SetDataBufferSampleDelay( int Card, int Module, int Channel, unsigned short SampleDelay );
_75C3FUNC int CPCI75C3_LVDT_GetDataBufferSampleDelay( int Card, int Module, int Channel, unsigned short *SampleDelay );
_75C3FUNC int CPCI75C3_LVDT_SetDataBufferNumOfSamples( int Card, int Module, int Channel, unsigned short NumOfSamples );
_75C3FUNC int CPCI75C3_LVDT_GetDataBufferNumOfSamples( int Card, int Module, int Channel, unsigned short *NumOfSamples );
_75C3FUNC int CPCI75C3_LVDT_SetDataBufferSampleRateValue( int Card, int Module, int Channel, double SampleRate );
_75C3FUNC int CPCI75C3_LVDT_GetDataBufferSampleRateValue( int Card, int Module, int Channel, double *SampleRate );
_75C3FUNC int CPCI75C3_LVDT_SetDataBufferSampleRate( int Card, int Module, int Channel, unsigned short SampleRate );
_75C3FUNC int CPCI75C3_LVDT_GetDataBufferSampleRate( int Card, int Module, int Channel, unsigned short *SampleRate );
_75C3FUNC int CPCI75C3_LVDT_SetDataBufferDataType( int Card, int Module, int Channel, unsigned short DataType );
_75C3FUNC int CPCI75C3_LVDT_GetDataBufferDataType( int Card, int Module, int Channel, unsigned short *DataType );
_75C3FUNC int CPCI75C3_LVDT_SetDataBufferTrigMode( int Card, int Module, int Channel, unsigned short TrigMode );
_75C3FUNC int CPCI75C3_LVDT_GetDataBufferTrigMode( int Card, int Module, int Channel, unsigned short *TrigMode );

_75C3FUNC int CPCI75C3_LVDT_SetDataBufferClearFifo( int Card, int Module, int Channel);
_75C3FUNC int CPCI75C3_LVDT_SendDataBufferSoftwareTrig( int Card, int Module);

_75C3FUNC int CPCI75C3_LVDT_GetDataBufferFifoValue( int Card, int Module, int Channel, unsigned short *Value );
_75C3FUNC int CPCI75C3_LVDT_GetDataBufferStatus( int Card, int Module, int Channel, unsigned short *BufferStatus );
_75C3FUNC int CPCI75C3_LVDT_GetDataBufferCount( int Card, int Module, int Channel, unsigned short *Count );

/******   Optional Reference Supply Control   ******/
_75C3FUNC int CPCI75C3_LVDT_SetRefFreq( int Card, int Module, unsigned int Frequency );
_75C3FUNC int CPCI75C3_LVDT_GetRefFreq( int Card, int Module, unsigned int *RefFreq );
_75C3FUNC int CPCI75C3_LVDT_SetRefFreqWord( int Card, int Module, unsigned int Frequency );
_75C3FUNC int CPCI75C3_LVDT_GetRefFreqWord( int Card, int Module, unsigned int *RefFreq );
_75C3FUNC int CPCI75C3_LVDT_SetRefVoltage( int Card, int Module, double Voltage );
_75C3FUNC int CPCI75C3_LVDT_GetRefVoltage( int Card, int Module, double *RefVoltage );
_75C3FUNC int CPCI75C3_LVDT_SetRefVoltageWord( int Card, int Module, unsigned int Voltage );
_75C3FUNC int CPCI75C3_LVDT_GetRefVoltageWord( int Card, int Module, unsigned int *RefVoltage );

/******   Revisions   ******/
_75C3FUNC int CPCI75C3_LVDT_GetDesignVersion( int Card, int Module, unsigned short *Version );
_75C3FUNC int CPCI75C3_LVDT_GetDesignRevision( int Card, int Module, unsigned short *Revision );
_75C3FUNC int CPCI75C3_LVDT_GetDSPRevision( int Card, int Module, unsigned short *Revision );
_75C3FUNC int CPCI75C3_LVDT_GetFPGARevision( int Card, int Module, unsigned short *Revision );

/******      Compile Time            *****/
_75C3FUNC int CPCI75C3_LVDT_GetCompileTime( int Card, int Module, unsigned short *CompileTimeBuffer );

/* ################################################################################################# */
/* END LVDT FUNCTIONS */
/* ################################################################################################# */

/* ################################################################################################# */
/*  For Internal Use Only                                                                            */
/*  Utility functions, do not need to export                                                         */
/* ################################################################################################# */
int CPCI75C3_LVDT_CheckCardModuleChannel(int Card, int Module, int Channel);


#ifdef __cplusplus
}
#endif

#endif

