/*filedoc==================================================================
**
** Copyright (c) 2010 North Atlantic Industries, Inc.  All Rights Reserved.
**
** Author: North Atlantic Industries, Inc.
**
** Project: Module Libraries
**
** SubSystem: S/D Modules
**
** FileName: CPCI75C3_SD.h
**
** Description: 
**
** $Archive: /SW Code Base/NAI_CPCI75C3/LibSrc/include/CPCI75C3_SD.h $
**
** $Revision: 8 $
**
** $Date: 7/18/11 1:42p $
**
** $NoKeywords: $
**========================================================================*/
#ifndef _CPCI75C3_SD_H
#define _CPCI75C3_SD_H

#include "CPCI75C3_include.h"

#ifdef __cplusplus
extern "C" {
#endif 

/* SD Definitions for Bandwidth Select parameter. */
#define CPCI75C3_SD_BWSelect_Manual              0
#define CPCI75C3_SD_BWSelect_Auto                1
/* SD Defintions for A&B Resolution Encoder Setting*/
#define CPCI75C3_ENCODER                         0
#define CPCI75C3_COMMUTATION                     1
#define ENC_16_RESOLUTION                       0x0000
#define ENC_15_RESOLUTION                       0x0001
#define ENC_14_RESOLUTION                       0x0002
#define ENC_13_RESOLUTION                       0x0003
#define ENC_12_RESOLUTION                       0x0004
#define POLE_4_COMMUTATION                      0x8000
#define POLE_6_COMMUTATION                      0x8001
#define POLE_8_COMMUTATION                      0x8002

/**************************/
/* SD Module Registers    */
/**************************/
#define CPCI75C3_REG_SD_ANGLE_DATA_LO                     {0x0000 << ADDR_SHIFT, 0x0004 << ADDR_SHIFT, 0x0008 << ADDR_SHIFT, 0x000C << ADDR_SHIFT}
#define CPCI75C3_REG_SD_ANGLE_DATA_HI                     {0x0002 << ADDR_SHIFT, 0x0006 << ADDR_SHIFT, 0x000A << ADDR_SHIFT, 0x000E << ADDR_SHIFT}
#define CPCI75C3_REG_SD_VELOCITY_LO                       {0x0010 << ADDR_SHIFT, 0x0014 << ADDR_SHIFT, 0x0018 << ADDR_SHIFT, 0x001C << ADDR_SHIFT}
#define CPCI75C3_REG_SD_VELOCITY_HI                       {0x0012 << ADDR_SHIFT, 0x0016 << ADDR_SHIFT, 0x001A << ADDR_SHIFT, 0x001E << ADDR_SHIFT}
#define CPCI75C3_REG_SD_BANDWIDTH                         {0x0020 << ADDR_SHIFT, 0x0022 << ADDR_SHIFT, 0x0024 << ADDR_SHIFT, 0x0026 << ADDR_SHIFT}
#define CPCI75C3_REG_SD_BANDWIDTH_SELECT                  (0x0028 << ADDR_SHIFT)
#define CPCI75C3_REG_SD_RATIO                             {0x002A << ADDR_SHIFT, 0x002C << ADDR_SHIFT}
#define CPCI75C3_REG_SD_ACTIVE_CHANNELS                   (0x002E << ADDR_SHIFT)
#define CPCI75C3_REG_SD_LATCH_CTL                         (0x0030 << ADDR_SHIFT)
#define CPCI75C3_REG_SD_D2TEST_VERIFY                     (0x0032 << ADDR_SHIFT)
#define CPCI75C3_REG_SD_TEST_ENABLE                       (0x0034 << ADDR_SHIFT)
#define CPCI75C3_REG_SD_TEST_ANGLE                        (0x0036 << ADDR_SHIFT)
#define CPCI75C3_REG_SD_SYNCHRO_RESOLVER_LVDT             (0x003C << ADDR_SHIFT)
#define CPCI75C3_REG_SD_SYNCHRO_RESOLVER                  (0x003E << ADDR_SHIFT)  /* FOR 64C1 COMPATIBLE MODE */
#define CPCI75C3_REG_SD_ANGLE_DELTA                       {0x0040 << ADDR_SHIFT, 0x0042 << ADDR_SHIFT, 0x0044 << ADDR_SHIFT, 0x0046 << ADDR_SHIFT}
#define CPCI75C3_REG_SD_ANGLE_DELTA_INIT                  (0x004E << ADDR_SHIFT)
#define CPCI75C3_REG_SD_FREQUENCY_LO                      {0x0050 << ADDR_SHIFT, 0x0054 << ADDR_SHIFT, 0x0058 << ADDR_SHIFT, 0x005C << ADDR_SHIFT}
#define CPCI75C3_REG_SD_FREQUENCY_HI                      {0x0052 << ADDR_SHIFT, 0x0056 << ADDR_SHIFT, 0x005A << ADDR_SHIFT, 0x005E << ADDR_SHIFT}
#define CPCI75C3_REG_SD_VLL                               {0x0060 << ADDR_SHIFT, 0x0062 << ADDR_SHIFT, 0x0064 << ADDR_SHIFT, 0x0066 << ADDR_SHIFT}
#define CPCI75C3_REG_SD_VREF                              {0x0068 << ADDR_SHIFT, 0x006A << ADDR_SHIFT, 0x006C << ADDR_SHIFT, 0x006E << ADDR_SHIFT}
#define CPCI75C3_REG_SD_AB_RES                            {0x0070 << ADDR_SHIFT, 0x0072 << ADDR_SHIFT, 0x0074 << ADDR_SHIFT, 0x0076 << ADDR_SHIFT}
#define CPCI75C3_REG_SD_SIG_LOSS_THRESHOLD                {0x0080 << ADDR_SHIFT, 0x0082 << ADDR_SHIFT, 0x0084 << ADDR_SHIFT, 0x0086 << ADDR_SHIFT}
#define CPCI75C3_REG_SD_REF_LOSS_THRESHOLD                {0x0088 << ADDR_SHIFT, 0x008A << ADDR_SHIFT, 0x008C << ADDR_SHIFT, 0x008E << ADDR_SHIFT}
#define CPCI75C3_REG_SD_VELOCITY_SCALE                    {0x00A8 << ADDR_SHIFT, 0x00AA << ADDR_SHIFT, 0x00AC << ADDR_SHIFT, 0x00AE << ADDR_SHIFT}

#define CPCI75C3_REG_SD_SIGNAL_STATUS                     (0x00E8 << ADDR_SHIFT)
#define CPCI75C3_REG_SD_REF_STATUS                        (0x00EA << ADDR_SHIFT)
#define CPCI75C3_REG_SD_BIT_STATUS                        (0x0380 << ADDR_SHIFT)
#define CPCI75C3_REG_SD_TWO_SPEED_LOCK_LOSS               (0x00EE << ADDR_SHIFT)
#define CPCI75C3_REG_SD_ANGLE_DELTA_ALERT                 (0x00F0 << ADDR_SHIFT)

#define CPCI75C3_REG_SD_SIGNAL_STATUS_INT_ENAB            (0x00F2 << ADDR_SHIFT)
#define CPCI75C3_REG_SD_REF_STATUS_INT_ENAB               (0x00F4 << ADDR_SHIFT)
#define CPCI75C3_REG_SD_BIT_STATUS_INT_ENAB               (0x00F6 << ADDR_SHIFT)
#define CPCI75C3_REG_SD_LOCK_STATUS_INT_ENAB              (0x00F8 << ADDR_SHIFT)
#define CPCI75C3_REG_SD_ANGLE_DELTA_ALERT_INT_ENAB        (0x00FA << ADDR_SHIFT)

#define CPCI75C3_REG_SD_BIT_STATUS_INT_VECTOR             (0x03E0 << ADDR_SHIFT)
#define CPCI75C3_REG_SD_SIGNAL_STATUS_INT_VECTOR          (0x03E2 << ADDR_SHIFT)
#define CPCI75C3_REG_SD_REF_STATUS_INT_VECTOR             (0x03E4 << ADDR_SHIFT)
#define CPCI75C3_REG_SD_LOCK_STATUS_INT_VECTOR            (0x03E6 << ADDR_SHIFT)
#define CPCI75C3_REG_SD_ANGLE_DELTA_ALERT_INT_VECTOR      (0x03E8 << ADDR_SHIFT)

#define CPCI75C3_REG_SD_DATA_BUFFER_WORD                  {0x0300 << ADDR_SHIFT, 0x0302 << ADDR_SHIFT, 0x0304 << ADDR_SHIFT, 0x0306 << ADDR_SHIFT}
#define CPCI75C3_REG_SD_DATA_BUFFER_COUNT                 {0x0308 << ADDR_SHIFT, 0x030A << ADDR_SHIFT, 0x030C << ADDR_SHIFT, 0x030E << ADDR_SHIFT}
#define CPCI75C3_REG_SD_DATA_BUFFER_STATUS                {0x0310 << ADDR_SHIFT, 0x0312 << ADDR_SHIFT, 0x0314 << ADDR_SHIFT, 0x0316 << ADDR_SHIFT}
#define CPCI75C3_REG_SD_DATA_BUFFER_HI_WATERMARK          {0x0320 << ADDR_SHIFT, 0x0330 << ADDR_SHIFT, 0x0340 << ADDR_SHIFT, 0x0350 << ADDR_SHIFT}
#define CPCI75C3_REG_SD_DATA_BUFFER_LO_WATERMARK          {0x0322 << ADDR_SHIFT, 0x0332 << ADDR_SHIFT, 0x0342 << ADDR_SHIFT, 0x0352 << ADDR_SHIFT}
#define CPCI75C3_REG_SD_DATA_BUFFER_SAMPLE_DELAY          {0x0324 << ADDR_SHIFT, 0x0334 << ADDR_SHIFT, 0x0344 << ADDR_SHIFT, 0x0354 << ADDR_SHIFT}
#define CPCI75C3_REG_SD_DATA_BUFFER_NUM_OF_SAMPLES        {0x0326 << ADDR_SHIFT, 0x0336 << ADDR_SHIFT, 0x0346 << ADDR_SHIFT, 0x0356 << ADDR_SHIFT}
#define CPCI75C3_REG_SD_DATA_BUFFER_SAMPLE_RATE           {0x0328 << ADDR_SHIFT, 0x0338 << ADDR_SHIFT, 0x0348 << ADDR_SHIFT, 0x0358 << ADDR_SHIFT}
#define CPCI75C3_REG_SD_DATA_BUFFER_CLEAR_FIFO            {0x032A << ADDR_SHIFT, 0x033A << ADDR_SHIFT, 0x034A << ADDR_SHIFT, 0x035A << ADDR_SHIFT}
#define CPCI75C3_REG_SD_DATA_BUFFER_DATA_TYPE             {0x032C << ADDR_SHIFT, 0x033C << ADDR_SHIFT, 0x034C << ADDR_SHIFT, 0x035C << ADDR_SHIFT}
#define CPCI75C3_REG_SD_DATA_BUFFER_TRIG_MODE             {0x032E << ADDR_SHIFT, 0x033E << ADDR_SHIFT, 0x034E << ADDR_SHIFT, 0x035E << ADDR_SHIFT}
#define CPCI75C3_REG_SD_DATA_BUFFER_SEND_SW_TRIG          (0x0360 << ADDR_SHIFT)

#define CPCI75C3_REG_SD_MODULE_DESIGN_VERSION             (0x03B4 << ADDR_SHIFT)
#define CPCI75C3_REG_SD_MODULE_DESIGN_REVISION            (0x03B6 << ADDR_SHIFT)
#define CPCI75C3_REG_SD_MODULE_DSP_REV                    (0x03B8 << ADDR_SHIFT)
#define CPCI75C3_REG_SD_MODULE_FPGA_REV                   (0x03BA << ADDR_SHIFT)

#define CPCI75C3_REG_SD_COMPILE_TIME_ADD                  (0x01E0 << ADDR_SHIFT)

/* ON BOARD OSCILLATOR REGISTERS */
#define CPCI75C3_REG_SD_REF_FREQUENCY_LO                  (0x0100 << ADDR_SHIFT)
#define CPCI75C3_REG_SD_REF_FREQUENCY_HI                  (0x0102 << ADDR_SHIFT)
#define CPCI75C3_REG_SD_REF_VOLTAGE_LO                    (0x0104 << ADDR_SHIFT)
#define CPCI75C3_REG_SD_REF_VOLTAGE_HI                    (0x0106 << ADDR_SHIFT)

/******    SD Specific Functions   ******/

/******   SD Channel Count   ******/
_75C3FUNC int CPCI75C3_SD_GetMaxChan( unsigned short ModuleID, int *MaxChan );

/******   Angle Data   ******/
_75C3FUNC int CPCI75C3_SD_GetAngle( int Card, int Module, int Channel, double *Angle );
_75C3FUNC int CPCI75C3_SD_GetAngleWord( int Card, int Module, int Channel, unsigned short *AngleWord );
_75C3FUNC int CPCI75C3_SD_GetAngleDoubleWord( int Card, int Module, int Channel, unsigned int *AngleWord );

/******   Velocity Data / Scale   ******/
_75C3FUNC int CPCI75C3_SD_GetVelocity( int Card, int Module, int Channel, double *Velocity );
_75C3FUNC int CPCI75C3_SD_GetVelocityWord( int Card, int Module, int Channel, signed short *VelocityWord );
_75C3FUNC int CPCI75C3_SD_GetVelocityDoubleWord( int Card, int Module, int Channel, signed int *VelocityWord );
_75C3FUNC int CPCI75C3_SD_SetVelScale( int Card, int Module, int Channel, unsigned short VelScale );
_75C3FUNC int CPCI75C3_SD_GetVelScale( int Card, int Module, int Channel, unsigned short *VelScale );

/******   Channel Modes (SYN,RSL,2Wire,4Wire ... Encoders/Commutation) ******/
_75C3FUNC int CPCI75C3_SD_SetChanMode( int Card, int Module, int Channel, unsigned short Mode );
_75C3FUNC int CPCI75C3_SD_GetChanMode( int Card, int Module, int Channel, unsigned short *Mode );
_75C3FUNC int CPCI75C3_SD_SetChanModeWord( int Card, int Module, unsigned short Mode );
_75C3FUNC int CPCI75C3_SD_GetChanModeWord( int Card, int Module, unsigned short *Mode );
_75C3FUNC int CPCI75C3_SD_SetEncoderABres( int Card, int Module, int Channel, unsigned short EncoderResolution );
_75C3FUNC int CPCI75C3_SD_GetEncoderABres( int Card, int Module, int Channel, unsigned short *EncoderABres );
_75C3FUNC int CPCI75C3_SD_SetCommutationRes( int Card, int Module, int Channel, unsigned short CommutationPoles );
_75C3FUNC int CPCI75C3_SD_GetCommutationRes( int Card, int Module, int Channel, unsigned short *CommutationPoles );
_75C3FUNC int CPCI75C3_SD_SetEncCommWord( int Card, int Module, int Channel, unsigned short EncCommWord );
_75C3FUNC int CPCI75C3_SD_GetEncCommWord( int Card, int Module, int Channel, unsigned short *EncCommWord );

/* The following SynRes APIs are should be called FOR 64C1 COMPATIBLE MODE where only 1 bit is used to
   differentiate the Synchro or Resolver mode */
_75C3FUNC int CPCI75C3_SD_SetSynRes( int Card, int Module, int channel, unsigned short SynRes );
_75C3FUNC int CPCI75C3_SD_GetSynRes( int Card, int Module, int Channel, unsigned short *SynRes );
_75C3FUNC int CPCI75C3_SD_SetSynResWord( int Card, int Module, unsigned short SynRes );
_75C3FUNC int CPCI75C3_SD_GetSynResWord( int Card, int Module, unsigned short *SynRes );

/****** Bandwidth ******/
_75C3FUNC int CPCI75C3_SD_SetBandwidth( int Card, int Module, int Channel, unsigned short Bandwidth );
_75C3FUNC int CPCI75C3_SD_GetBandwidth( int Card, int Module, int Channel, unsigned short* Bandwidth );
_75C3FUNC int CPCI75C3_SD_SetBandwidthSelect ( int Card, int Module, int Channel, unsigned short BWSelect);
_75C3FUNC int CPCI75C3_SD_GetBandwidthSelect ( int Card, int Module, int Channel, unsigned short *BWSelect);
_75C3FUNC int CPCI75C3_SD_SetBandwidthSelectWord( int Card, int Module, unsigned short BWSelect);
_75C3FUNC int CPCI75C3_SD_GetBandwidthSelectWord( int Card, int Module, unsigned short *BWSelect);

/******   Two Speed Setup   ******/
_75C3FUNC int CPCI75C3_SD_SetRatio( int Card, int Module, int Channel, unsigned short Ratio );
_75C3FUNC int CPCI75C3_SD_GetRatio( int Card, int Module, int Channel, unsigned short *Ratio );

/******   Latch   ******/
_75C3FUNC int CPCI75C3_SD_SetLatch( int Card, int Module, int Channel, unsigned short Latch );
_75C3FUNC int CPCI75C3_SD_GetLatch( int Card, int Module, int Channel, unsigned short* Latch );
_75C3FUNC int CPCI75C3_SD_SetLatchWord( int Card, int Module, unsigned short Latch );
_75C3FUNC int CPCI75C3_SD_GetLatchWord( int Card, int Module, unsigned short* Latch );

/******   Test Modes   ******/
_75C3FUNC int CPCI75C3_SD_SetTestAngle( int Card, int Module, double TestAngle );
_75C3FUNC int CPCI75C3_SD_GetTestAngle( int Card, int Module, double *TestAngle );
_75C3FUNC int CPCI75C3_SD_SetTestAngleWord( int Card, int Module, unsigned short TestAngle );
_75C3FUNC int CPCI75C3_SD_GetTestAngleWord( int Card, int Module, unsigned short *TestAngleWord );

/******   SD Test Enable  ******/
_75C3FUNC int CPCI75C3_SD_GetTestEnableWord( int Card, int Module, unsigned short *TestEnableWord );
_75C3FUNC int CPCI75C3_SD_SetTestEnableWord( int Card, int Module, unsigned short TestEnableWord );
_75C3FUNC int CPCI75C3_SD_SetD2TestVerifyValue( int Card, int Module, unsigned short Word );
_75C3FUNC int CPCI75C3_SD_GetD2TestVerifyValue( int Card, int Module, unsigned short *Word );

/******   Active Channel Setup  ******/
_75C3FUNC int CPCI75C3_SD_SetActiveChannel( int Card, int Module, int Channel, unsigned short Setting );
_75C3FUNC int CPCI75C3_SD_GetActiveChannel( int Card, int Module, int Channel, unsigned short *Setting );
_75C3FUNC int CPCI75C3_SD_SetActiveChannelWord( int Card, int Module, unsigned short ActiveChannelWord );
_75C3FUNC int CPCI75C3_SD_GetActiveChannelWord( int Card, int Module, unsigned short *ActiveChannelWord );

/******   Angle Change Alert   ******/
_75C3FUNC int CPCI75C3_SD_SetAngleDelta( int Card, int Module, int Channel, double AngleDelta );
_75C3FUNC int CPCI75C3_SD_GetAngleDelta( int Card, int Module, int Channel, double *AngleDelta );
_75C3FUNC int CPCI75C3_SD_SetAngleDeltaWord( int Card, int Module, int Channel, unsigned short AngleDelta );
_75C3FUNC int CPCI75C3_SD_GetAngleDeltaWord( int Card, int Module, int Channel, unsigned short *AngleDeltaWord );
_75C3FUNC int CPCI75C3_SD_SetAngleDeltaInit( int Card, int Module, int Channel, unsigned short Setting );
_75C3FUNC int CPCI75C3_SD_GetAngleDeltaInit( int Card, int Module, int Channel, unsigned short *Setting );
_75C3FUNC int CPCI75C3_SD_SetAngleDeltaInitWord( int Card, int Module, unsigned short Setting );
_75C3FUNC int CPCI75C3_SD_GetAngleDeltaInitWord( int Card, int Module, unsigned short *Setting);

/****** Chan Freq ******/
_75C3FUNC int CPCI75C3_SD_GetChanFrequency( int Card, int Module, int Channel, double* Frequency );
_75C3FUNC int CPCI75C3_SD_GetChanFrequencyWord( int Card, int Module, int Channel, int* Frequency );

/****** Chan VLL ******/
_75C3FUNC int CPCI75C3_SD_GetChanSigVLL( int Card, int Module, int Channel, double* SigVLL );
_75C3FUNC int CPCI75C3_SD_GetChanSigVLLWord( int Card, int Module, int Channel, unsigned short* SigVLL );
_75C3FUNC int CPCI75C3_SD_SetSigLossThreshold( int Card, int Module, int Channel, double  Threshold );
_75C3FUNC int CPCI75C3_SD_GetSigLossThreshold( int Card, int Module, int Channel, double* Threshold );
_75C3FUNC int CPCI75C3_SD_SetSigLossThresholdWord( int Card, int Module, int Channel, unsigned short Threshold );
_75C3FUNC int CPCI75C3_SD_GetSigLossThresholdWord( int Card, int Module, int Channel, unsigned short* Threshold );

/****** Chan Ref ******/
_75C3FUNC int CPCI75C3_SD_GetChanRefVolt( int Card, int Module, int Channel, double* RefVolt );
_75C3FUNC int CPCI75C3_SD_GetChanRefVoltWord( int Card, int Module, int Channel, unsigned short* RefVolt );
_75C3FUNC int CPCI75C3_SD_SetRefLossThreshold( int Card, int Module, int Channel, double  Threshold );
_75C3FUNC int CPCI75C3_SD_GetRefLossThreshold( int Card, int Module, int Channel, double* Threshold );
_75C3FUNC int CPCI75C3_SD_SetRefLossThresholdWord( int Card, int Module, int Channel, unsigned short Threshold );
_75C3FUNC int CPCI75C3_SD_GetRefLossThresholdWord( int Card, int Module, int Channel, unsigned short* Threshold );

/******   Status Registers   ******/
_75C3FUNC int CPCI75C3_SD_GetSignalStatus( int Card, int Module, int Channel, unsigned short *SigStatus );
_75C3FUNC int CPCI75C3_SD_GetSignalStatusWord( int Card, int Module, unsigned short *StatusWord );
_75C3FUNC int CPCI75C3_SD_GetRefStatus( int Card, int Module, int Channel, unsigned short *RefStatus );
_75C3FUNC int CPCI75C3_SD_GetRefStatusWord( int Card, int Module, unsigned short *StatusWord );
_75C3FUNC int CPCI75C3_SD_GetBITStatus( int Card, int Module, int Channel, unsigned short *BITStatus );
_75C3FUNC int CPCI75C3_SD_GetBITStatusWord( int Card, int Module, unsigned short *StatusWord );
_75C3FUNC int CPCI75C3_SD_GetTwoSpeedLockLoss( int Card, int Module, int Channel, unsigned short *TwoSpeedLockLoss );
_75C3FUNC int CPCI75C3_SD_GetTwoSpeedLockLossWord( int Card, int Module, unsigned short *TwoSpeedLockLossWord );
_75C3FUNC int CPCI75C3_SD_GetAngleDeltaAlert( int Card, int Module, int Channel, unsigned short *AngleDeltaAlert );
_75C3FUNC int CPCI75C3_SD_GetAngleDeltaAlertWord( int Card, int Module, unsigned short *StatusWord );

/******   S/D Interrupt Enable Setup   ******/
_75C3FUNC int CPCI75C3_SD_SetSignalStatusIntEnable( int Card, int Module, int Channel, unsigned short SignalStatusIntEnab );
_75C3FUNC int CPCI75C3_SD_GetSignalStatusIntEnable( int Card, int Module, int Channel, unsigned short *SignalStatusIntEnab );
_75C3FUNC int CPCI75C3_SD_SetSignalStatusIntEnableWord( int Card, int Module, unsigned short SignalStatusIntEnab );
_75C3FUNC int CPCI75C3_SD_GetSignalStatusIntEnableWord( int Card, int Module, unsigned short *SignalStatusIntEnab );
_75C3FUNC int CPCI75C3_SD_SetRefStatusIntEnable( int Card, int Module, int Channel, unsigned short RefStatusIntEnab );
_75C3FUNC int CPCI75C3_SD_GetRefStatusIntEnable( int Card, int Module, int Channel, unsigned short *RefStatusIntEnab );
_75C3FUNC int CPCI75C3_SD_SetRefStatusIntEnableWord( int Card, int Module, unsigned short RefStatusIntEnab );
_75C3FUNC int CPCI75C3_SD_GetRefStatusIntEnableWord( int Card, int Module, unsigned short *RefStatusIntEnab );
_75C3FUNC int CPCI75C3_SD_SetBITStatusIntEnable( int Card, int Module, int Channel, unsigned short BITStatusIntEnab );
_75C3FUNC int CPCI75C3_SD_GetBITStatusIntEnable( int Card, int Module, int Channel, unsigned short *BITStatusIntEnab );
_75C3FUNC int CPCI75C3_SD_SetBITStatusIntEnableWord( int Card, int Module, unsigned short BITStatusIntEnab );
_75C3FUNC int CPCI75C3_SD_GetBITStatusIntEnableWord( int Card, int Module, unsigned short *BITStatusIntEnab );
_75C3FUNC int CPCI75C3_SD_SetLockLossIntEnable( int Card, int Module, int Channel, unsigned short LockLossIntEnab );
_75C3FUNC int CPCI75C3_SD_GetLockLossIntEnable( int Card, int Module, int Channel, unsigned short *LockLossIntEnab );
_75C3FUNC int CPCI75C3_SD_SetLockLossIntEnableWord( int Card, int Module, unsigned short LockLossIntEnab );
_75C3FUNC int CPCI75C3_SD_GetLockLossIntEnableWord( int Card, int Module, unsigned short *LockLossIntEnab );
_75C3FUNC int CPCI75C3_SD_SetAngleDeltaAlertIntEnable( int Card, int Module, int Channel, unsigned short AngleDeltaAlertIntEnab );
_75C3FUNC int CPCI75C3_SD_GetAngleDeltaAlertIntEnable( int Card, int Module, int Channel, unsigned short *AngleDeltaAlertIntEnab );
_75C3FUNC int CPCI75C3_SD_SetAngleDeltaAlertIntEnableWord( int Card, int Module, unsigned short AngleDeltaAlertIntEnab );
_75C3FUNC int CPCI75C3_SD_GetAngleDeltaAlertIntEnableWord( int Card, int Module, unsigned short *AngleDeltaAlertIntEnab );

/******   S/D Interrupt Vector Setup   ******/
_75C3FUNC int CPCI75C3_SD_GetSignalStatusInterruptVector( int Card, int Module, unsigned short *InterruptVector );
_75C3FUNC int CPCI75C3_SD_SetSignalStatusInterruptVector( int Card, int Module, unsigned short InterruptVector );
_75C3FUNC int CPCI75C3_SD_GetRefStatusInterruptVector( int Card, int Module, unsigned short *InterruptVector );
_75C3FUNC int CPCI75C3_SD_SetRefStatusInterruptVector( int Card, int Module, unsigned short InterruptVector );
_75C3FUNC int CPCI75C3_SD_GetBITStatusInterruptVector( int Card, int Module, unsigned short *InterruptVector );
_75C3FUNC int CPCI75C3_SD_SetBITStatusInterruptVector( int Card, int Module, unsigned short InterruptVector );
_75C3FUNC int CPCI75C3_SD_GetLockLossInterruptVector( int Card, int Module, unsigned short *InterruptVector );
_75C3FUNC int CPCI75C3_SD_SetLockLossInterruptVector( int Card, int Module, unsigned short InterruptVector );
_75C3FUNC int CPCI75C3_SD_GetAngleDeltaAlertInterruptVector( int Card, int Module, unsigned short *InterruptVector );
_75C3FUNC int CPCI75C3_SD_SetAngleDeltaAlertInterruptVector( int Card, int Module, unsigned short InterruptVector );

/******   Data Buffers Setup   ******/
_75C3FUNC int CPCI75C3_SD_SetDataBufferHiWatermark( int Card, int Module, int Channel, unsigned short Watermark );
_75C3FUNC int CPCI75C3_SD_GetDataBufferHiWatermark( int Card, int Module, int Channel, unsigned short *Watermark );
_75C3FUNC int CPCI75C3_SD_SetDataBufferLoWatermark( int Card, int Module, int Channel, unsigned short Watermark );
_75C3FUNC int CPCI75C3_SD_GetDataBufferLoWatermark( int Card, int Module, int Channel, unsigned short *Watermark );
_75C3FUNC int CPCI75C3_SD_SetDataBufferSampleDelay( int Card, int Module, int Channel, unsigned short SampleDelay );
_75C3FUNC int CPCI75C3_SD_GetDataBufferSampleDelay( int Card, int Module, int Channel, unsigned short *SampleDelay );
_75C3FUNC int CPCI75C3_SD_SetDataBufferNumOfSamples( int Card, int Module, int Channel, unsigned short NumOfSamples );
_75C3FUNC int CPCI75C3_SD_GetDataBufferNumOfSamples( int Card, int Module, int Channel, unsigned short *NumOfSamples );
_75C3FUNC int CPCI75C3_SD_SetDataBufferSampleRateValue( int Card, int Module, int Channel, double SampleRate );
_75C3FUNC int CPCI75C3_SD_GetDataBufferSampleRateValue( int Card, int Module, int Channel, double *SampleRate );
_75C3FUNC int CPCI75C3_SD_SetDataBufferSampleRate( int Card, int Module, int Channel, unsigned short SampleRate );
_75C3FUNC int CPCI75C3_SD_GetDataBufferSampleRate( int Card, int Module, int Channel, unsigned short *SampleRate );
_75C3FUNC int CPCI75C3_SD_SetDataBufferDataType( int Card, int Module, int Channel, unsigned short DataType );
_75C3FUNC int CPCI75C3_SD_GetDataBufferDataType( int Card, int Module, int Channel, unsigned short *DataType );
_75C3FUNC int CPCI75C3_SD_SetDataBufferTrigMode( int Card, int Module, int Channel, unsigned short TrigMode );
_75C3FUNC int CPCI75C3_SD_GetDataBufferTrigMode( int Card, int Module, int Channel, unsigned short *TrigMode );

_75C3FUNC int CPCI75C3_SD_SetDataBufferClearFifo( int Card, int Module, int Channel);
_75C3FUNC int CPCI75C3_SD_SendDataBufferSoftwareTrig( int Card, int Module);

_75C3FUNC int CPCI75C3_SD_GetDataBufferFifoValue( int Card, int Module, int Channel, unsigned short *Value );
_75C3FUNC int CPCI75C3_SD_GetDataBufferStatus( int Card, int Module, int Channel, unsigned short *BufferStatus );
_75C3FUNC int CPCI75C3_SD_GetDataBufferCount( int Card, int Module, int Channel, unsigned short *Count );

/******   Optional Reference Supply Control   ******/
_75C3FUNC int CPCI75C3_SD_SetRefFreq( int Card, int Module, unsigned int Frequency );
_75C3FUNC int CPCI75C3_SD_GetRefFreq( int Card, int Module, unsigned int *RefFreq );
_75C3FUNC int CPCI75C3_SD_SetRefFreqWord( int Card, int Module, unsigned int Frequency );
_75C3FUNC int CPCI75C3_SD_GetRefFreqWord( int Card, int Module, unsigned int *RefFreq );
_75C3FUNC int CPCI75C3_SD_SetRefVoltage( int Card, int Module, double Voltage );
_75C3FUNC int CPCI75C3_SD_GetRefVoltage( int Card, int Module, double *RefVoltage );
_75C3FUNC int CPCI75C3_SD_SetRefVoltageWord( int Card, int Module, unsigned int Voltage );
_75C3FUNC int CPCI75C3_SD_GetRefVoltageWord( int Card, int Module, unsigned int *RefVoltage );

/******   Revisions   ******/
_75C3FUNC int CPCI75C3_SD_GetDesignVersion( int Card, int Module, unsigned short *Version );
_75C3FUNC int CPCI75C3_SD_GetDesignRevision( int Card, int Module, unsigned short *Revision );
_75C3FUNC int CPCI75C3_SD_GetDSPRevision( int Card, int Module, unsigned short *Revision );
_75C3FUNC int CPCI75C3_SD_GetFPGARevision( int Card, int Module, unsigned short *Revision );

/******      Compile Time            *****/
_75C3FUNC int CPCI75C3_SD_GetCompileTime( int Card, int Module, unsigned short *CompileTimeBuffer );

/* ################################################################################################# */
/* END S/D FUNCTIONS */
/* ################################################################################################# */

/* ################################################################################################# */
/*  For Internal Use Only                                                                            */
/*  Utility functions, do not need to export                                                         */
/* ################################################################################################# */
int CPCI75C3_SD_CheckCardModuleChannel(int Card, int Module, int Channel);

#define CPCI75C3_REG_SD_HYST_ADDR          (0x1FE << ADDR_SHIFT)  /*  for disabling when calibrating */
#define HYST_PARAM_ERROR 		            118
_75C3FUNC int CPCI75C3_GetHystValue(int Card, int* hystValue);
_75C3FUNC int CPCI75C3_SetHystValue(int Card, int hystValue);
/*  End For Internal use Only */



#ifdef __cplusplus
}
#endif

#endif

