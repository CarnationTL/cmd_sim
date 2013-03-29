/**
 *=========================================================================
 *
 * Copyright (c) 2008 North Atlantic Industries, Inc.  All Rights Reserved.
 *
 * Author: North Atlantic Industries, Inc.
 *
 * Project: CPCI75C3Dll
 *
 * SubSystem: 
 *
 * FileName: CPCI75C3_DS.h
 *=========================================================================
 **/
#ifndef _CPCI75C3_DS_H
#define _CPCI75C3_DS_H

#include "CPCI75C3_include.h"

#ifdef __cplusplus
extern "C" {
#endif 

/* DS Module */
#define MODULE_ID_10           0x3130  /* 2 ch Synchro output 11.8 Vll,  at 2.2.VA 400Hz */
#define MODULE_ID_11           0x3131  /* 2 ch Resolver output 2-28 Vrms, at 2.2.VA 400Hz */
#define MODULE_ID_12           0x3132  /* 2 ch Programmable S/R output 2-28 Vrms, at 2.2.VA 400Hz */
#define MODULE_ID_13           0x3133  /* 2 ch Synchro output 11.8 Vll, at 2.2.VA 47 to 440Hz */
#define MODULE_ID_14           0x3134  /* 2 ch Resolver output 2-28 Vrms, at 2.2.VA 47 to 440Hz */
#define MODULE_ID_15           0x3135  /* 2 ch Programmable S/R output 2-28 Vrms, at 2.2.VA 47 to 440Hz */
#define MODULE_ID_16           0x3136  /* 1st ch Synchro, 2nd ch Resolver */
#define MODULE_ID_17           0x3137  /* 1st ch Resolver,2nd ch Synchro  */

#define MODULE_ID_20           0x3230  /* 2 ch Synchro output 90.0 Vll,  at 2.2.VA 400Hz */
#define MODULE_ID_21           0x3231  /* 2 ch Resolver output 90.0 Vrms, at 2.2.VA 400Hz */
#define MODULE_ID_22           0x3232  /* 2 ch Programmable S/R output 90.0 Vrms, at 2.2.VA 400Hz */
#define MODULE_ID_23           0x3233  /* 2 ch Synchro output 90.0 Vll, at 2.2.VA 47 to 440Hz */
#define MODULE_ID_24           0x3234  /* 2 ch Resolver output 90.0 Vrms, at 2.2.VA 47 to 440Hz */
#define MODULE_ID_25           0x3235  /* 2 ch Programmable S/R output 90.0 Vrms, at 2.2.VA 47 to 440Hz */

#define MODULE_ID_30           0x3330  /* 1 ch Synchro output 11.8 Vll, at 5.0 VA 400 Hz */
#define MODULE_ID_31           0x3331  /* 1 ch Resolver output 2-28 Vrms, at 5.0 VA 400 Hz */
#define MODULE_ID_32           0x3332  /* 1 ch Synchro output 11.8 Vll, at 5.0 VA 47 to 440 Hz */
#define MODULE_ID_33           0x3333  /* 1 ch Resolver output 2-28 Vrms, at 5.0 VA 47 to 440 Hz */

#define MODULE_ID_40           0x3430  /* 1 ch Synchro output 90.0 Vll, at 5.0 VA 400 Hz */
#define MODULE_ID_41           0x3431  /* 1 ch Resolver output 90.0 Vrms, at 5.0 VA 400 Hz */
#define MODULE_ID_42           0x3432  /* 1 ch Synchro output 90.0 Vll, at 5.0 VA 47 to 440 Hz */
#define MODULE_ID_43           0x3433  /* 1 ch Resolver output 90.0 Vrms, at 5.0 VA 47 to 440 Hz */


/**************************/
/*  DS Module Registers   */
/**************************/
/*  Note only using Hi-Word portion of the Angle Data, Wrap Data and Rotation Rate Data  */
#define CPCI75C3_REG_DS_WRAP_LO_ADD                     {0x0000 << ADDR_SHIFT, 0x0004 << ADDR_SHIFT, 0x0008 << ADDR_SHIFT}
#define CPCI75C3_REG_DS_WRAP_HI_ADD                     {0x0002 << ADDR_SHIFT, 0x0006 << ADDR_SHIFT, 0x000A << ADDR_SHIFT}
#define CPCI75C3_REG_DS_WRAP_ADD                        {0x0002 << ADDR_SHIFT, 0x0006 << ADDR_SHIFT, 0x000A << ADDR_SHIFT}
														 
#define CPCI75C3_REG_DS_ROTATION_RATE_WRAP_ADD          {0x0010 << ADDR_SHIFT, 0x0012 << ADDR_SHIFT, 0x0014 << ADDR_SHIFT}
#define CPCI75C3_REG_DS_BW_ADJUST_ADD                   {0x0020 << ADDR_SHIFT, 0x0022 << ADDR_SHIFT, 0x0024 << ADDR_SHIFT}

#define CPCI75C3_REG_DS_TRACK_HOLD                      (0x0030 << ADDR_SHIFT)

#define CPCI75C3_REG_DS_REF_VOLTAGE_IN_ADD              {0x0032 << ADDR_SHIFT, 0x0034 << ADDR_SHIFT, 0x0036 << ADDR_SHIFT}
#define CPCI75C3_REG_DS_SIG_VOLTAGE_IN_ADD              {0x0038 << ADDR_SHIFT, 0x003A << ADDR_SHIFT, 0x003C << ADDR_SHIFT}

#define CPCI75C3_REG_DS_SIG_LOSS_THRESHOLD_ADD          {0x0040 << ADDR_SHIFT, 0x0042 << ADDR_SHIFT, 0x0044 << ADDR_SHIFT}
#define CPCI75C3_REG_DS_REF_LOSS_THRESHOLD_ADD          {0x0046 << ADDR_SHIFT, 0x0048 << ADDR_SHIFT, 0x004A << ADDR_SHIFT}

#define CPCI75C3_REG_DS_REF_SOURCE_FREQ_ADD             {0x004C << ADDR_SHIFT, 0x004E << ADDR_SHIFT, 0x0050 << ADDR_SHIFT}

#define CPCI75C3_REG_DS_SIGNAL_STATUS                   (0x0058 << ADDR_SHIFT)

#define CPCI75C3_REG_DS_ANGLE_LO_ADD                    {0x0060 << ADDR_SHIFT, 0x0064 << ADDR_SHIFT, 0x0068 << ADDR_SHIFT}
#define CPCI75C3_REG_DS_ANGLE_HI_ADD                    {0x0062 << ADDR_SHIFT, 0x0066 << ADDR_SHIFT, 0x006A << ADDR_SHIFT}
#define CPCI75C3_REG_DS_ANGLE_ADD                       {0x0062 << ADDR_SHIFT, 0x0066 << ADDR_SHIFT, 0x006A << ADDR_SHIFT}

#define CPCI75C3_REG_DS_RESPONSE_TIME_ADD               {0x006C << ADDR_SHIFT, 0x006E << ADDR_SHIFT, 0x0070 << ADDR_SHIFT}
#define CPCI75C3_REG_DS_STOP_ANGLE_ADD                  {0x0072 << ADDR_SHIFT, 0x0074 << ADDR_SHIFT, 0x0076 << ADDR_SHIFT}

#define CPCI75C3_REG_DS_ROTATION_RATE_LO_ADD            {0x0080 << ADDR_SHIFT, 0x0084 << ADDR_SHIFT, 0x0088 << ADDR_SHIFT}
#define CPCI75C3_REG_DS_ROTATION_RATE_HI_ADD            {0x0082 << ADDR_SHIFT, 0x0086 << ADDR_SHIFT, 0x008A << ADDR_SHIFT}
#define CPCI75C3_REG_DS_ROTATION_RATE_ADD               {0x0082 << ADDR_SHIFT, 0x0086 << ADDR_SHIFT, 0x008A << ADDR_SHIFT}

#define CPCI75C3_REG_DS_EXP_REF_FREQ_ADD                {0x0090 << ADDR_SHIFT, 0x0094 << ADDR_SHIFT, 0x0098 << ADDR_SHIFT}
#define CPCI75C3_REG_DS_EXP_REF_FREQ_LO_ADD             {0x0090 << ADDR_SHIFT, 0x0094 << ADDR_SHIFT, 0x0098 << ADDR_SHIFT}
#define CPCI75C3_REG_DS_EXP_REF_FREQ_HI_ADD             {0x0092 << ADDR_SHIFT, 0x0096 << ADDR_SHIFT, 0x009A << ADDR_SHIFT}

#define CPCI75C3_REG_DS_EXP_REF_VOLT_ADD                {0x00A0 << ADDR_SHIFT, 0x00A4 << ADDR_SHIFT, 0x00A8 << ADDR_SHIFT}
#define CPCI75C3_REG_DS_EXP_REF_VOLT_LO_ADD             {0x00A0 << ADDR_SHIFT, 0x00A4 << ADDR_SHIFT, 0x00A8 << ADDR_SHIFT}
#define CPCI75C3_REG_DS_EXP_REF_VOLT_HI_ADD             {0x00A2 << ADDR_SHIFT, 0x00A6 << ADDR_SHIFT, 0x00AA << ADDR_SHIFT}

#define CPCI75C3_REG_DS_EXP_VLL_VOLT_ADD                {0x00B0 << ADDR_SHIFT, 0x00B4 << ADDR_SHIFT, 0x00B8 << ADDR_SHIFT}
#define CPCI75C3_REG_DS_EXP_VLL_VOLT_LO_ADD             {0x00B0 << ADDR_SHIFT, 0x00B4 << ADDR_SHIFT, 0x00B8 << ADDR_SHIFT}
#define CPCI75C3_REG_DS_EXP_VLL_VOLT_HI_ADD             {0x00B2 << ADDR_SHIFT, 0x00B6 << ADDR_SHIFT, 0x00BA << ADDR_SHIFT}

#define CPCI75C3_REG_DS_TEST_ENABLE                     (0x00C0 << ADDR_SHIFT)
#define CPCI75C3_REG_DS_RATIO                           (0x00C2 << ADDR_SHIFT)
#define CPCI75C3_REG_DS_D2TEST_VERIFY                   (0x00C4 << ADDR_SHIFT) 
#define CPCI75C3_REG_DS_REFVLL_MODE                     (0x00C6 << ADDR_SHIFT)
#define CPCI75C3_REG_DS_ROTATION_MODE                   (0x00C8 << ADDR_SHIFT)

#define CPCI75C3_REG_DS_SYN_RES_2WIRE_4WIRE_SEL         (0x00CC << ADDR_SHIFT)
#define CPCI75C3_REG_DS_ROT_TRIGGER_ADD                 {0x00D0 << ADDR_SHIFT, 0x00D2 << ADDR_SHIFT, 0x00D4 << ADDR_SHIFT}

#define CPCI75C3_REG_DS_ROT_TRIGGER_SLOPE_ADD           (0x00D6 << ADDR_SHIFT)

#define CPCI75C3_REG_DS_OUTPUT_ENAB                     (0x00D8 << ADDR_SHIFT)
#define CPCI75C3_REG_DS_CURRENT_ADD                     {0x00DA << ADDR_SHIFT, 0x00DC << ADDR_SHIFT, 0x00DE << ADDR_SHIFT}
#define CPCI75C3_REG_DS_POWER_SUPPLY_DISABLE            (0x00E0 << ADDR_SHIFT)

#define CPCI75C3_REG_DS_ACTIVE_CHAN                     (0x00E4 << ADDR_SHIFT)
#define CPCI75C3_REG_DS_TORQUE_RX_ADD                   (0x00CE << ADDR_SHIFT)

#define CPCI75C3_REG_DS_REF_STATUS                      (0x00E6 << ADDR_SHIFT)
#define CPCI75C3_REG_DS_PLL_STATUS                      (0x00E8 << ADDR_SHIFT)

#define CPCI75C3_REG_DS_PHASE_ADD                       {0x00F4 << ADDR_SHIFT, 0x00F6 << ADDR_SHIFT, 0x00F8 << ADDR_SHIFT}
#define CPCI75C3_REG_DS_ROTATION_STATUS                 (0x00FA << ADDR_SHIFT)
/*
#define CPCI75C3_REG_DLV_POS_MODE                       (0x00FC << ADDR_SHIFT)
#define CPCI75C3_REG_DLV_AB_PHASE                       (0x00FE << ADDR_SHIFT)
*/
#define CPCI75C3_REG_DS_CURRENT_THRESHOLD_ADD           {0x0100 << ADDR_SHIFT, 0x0102 << ADDR_SHIFT, 0x0104 << ADDR_SHIFT}

#define CPCI75C3_REG_DS_MODULE_TEMPERATURE_ADD          (0x010E << ADDR_SHIFT)

#define CPCI75C3_REG_DS_ACCUM_ANGLE_LO_ADD              {0x0114 << ADDR_SHIFT, 0x0118 << ADDR_SHIFT, 0x011C << ADDR_SHIFT}
#define CPCI75C3_REG_DS_ACCUM_ANGLE_HI_ADD              {0x0116 << ADDR_SHIFT, 0x011A << ADDR_SHIFT, 0x011E << ADDR_SHIFT}

#define CPCI75C3_REG_DS_COMPILE_TIME_ADD                (0x0120 << ADDR_SHIFT)

#define CPCI75C3_REG_DS_BACK_GROUND_CAL_ENABLE_ADD      (0x01A8 << ADDR_SHIFT)
#define CPCI75C3_REG_DS_ROTATION_INIT_ADD               {0x01D0 << ADDR_SHIFT, 0x01D2 << ADDR_SHIFT, 0x01D4 << ADDR_SHIFT}     
#define CPCI75C3_REG_DS_ROTATION_STOP_ADD               {0x01D8 << ADDR_SHIFT, 0x01DA << ADDR_SHIFT, 0x01DC << ADDR_SHIFT}

#define CPCI75C3_REG_DS_CAL_DWELL_TIME_ADD              {0x01F4 << ADDR_SHIFT, 0x01F6 << ADDR_SHIFT, 0x01F8 << ADDR_SHIFT} 

/*#define CPCI75C3_REG_DS_ROTATION_INIT_ADD             (0x01D0 << ADDR_SHIFT) */
/*#define CPCI75C3_REG_DS_ROTATION_STOP_ADD             (0x01D2 << ADDR_SHIFT) */

#define CPCI75C3_REG_DS_THREE_CHAN_ROT_INIT_ADD         (0x01D0 << ADDR_SHIFT)
#define CPCI75C3_REG_DS_THREE_CHAN_ROT_STOP_ADD         (0x01D2 << ADDR_SHIFT)   

#define CPCI75C3_REG_DS_BIT_STATUS                      (0x0380 << ADDR_SHIFT)
#define CPCI75C3_REG_DS_REF_STATUS_INT_ENAB             (0x0382 << ADDR_SHIFT)
#define CPCI75C3_REG_DS_SIGNAL_STATUS_INT_ENAB          (0x0384 << ADDR_SHIFT)
#define CPCI75C3_REG_DS_BIT_STATUS_INT_ENAB             (0x0386 << ADDR_SHIFT)
#define CPCI75C3_REG_DS_LOCK_STATUS_INT_ENAB            (0x0388 << ADDR_SHIFT)

#define CPCI75C3_REG_DS_VECTOR_BIT                      (0x03E0 << ADDR_SHIFT)
#define CPCI75C3_REG_DS_VECTOR_REF_LOSS                 (0x03E2 << ADDR_SHIFT)
#define CPCI75C3_REG_DS_VECTOR_SIG_LOSS                 (0x03E4 << ADDR_SHIFT)
#define CPCI75C3_REG_DS_VECTOR_LOCK_LOSS                (0x03E6 << ADDR_SHIFT)


#define ANGLE_BIT16            0.0054931640625
#define ANGLE_BIT32            0.0000000838190317
#define VELOCITY_SCALE         190.73486328125 * 4095.0 / 32768.0

#define ANGLE_BIT16            0.0054931640625 
#define ANGLE_BIT17            0.00274658203125
#define ANGLE_BIT24            0.0000214576721191
#define ANGLE_BIT25            0.00001072883606
#define RATE_LSB               0.015
#define RATE_LSB_2             0.075

#define CPCI75C3_START_STOP_ROT    1
#define CPCI75C3_CONTINUOUS_ROT    0
#define PHASE_OFFSET_BIT_RES       0.1
#define THREE_CHAN_MODULE          3

/******   DS Specific Functions   ******/

/******   DS Channel Count   ******/
_75C3FUNC int CPCI75C3_DS_GetMaxChan( unsigned short ModuleID, int *MaxChan );

/******   Angle Data   ******/
_75C3FUNC int CPCI75C3_DS_SetAngle( int Card, int Module, int Channel, double Angle );
_75C3FUNC int CPCI75C3_DS_SetAngleWord( int Card, int Module, int Channel, unsigned short AngleWord );
_75C3FUNC int CPCI75C3_DS_SetAngleDoubleWord( int Card, int Module, int Channel, unsigned int AngleDoubleWord );
_75C3FUNC int CPCI75C3_DS_GetAngle( int Card, int Module, int Channel, double *Angle );
_75C3FUNC int CPCI75C3_DS_GetAngleWord( int Card, int Module, int Channel, unsigned short *AngleWord );
_75C3FUNC int CPCI75C3_DS_GetAngleDoubleWord( int Card, int Module, int Channel, unsigned int *AngleDoubleWord );
_75C3FUNC int CPCI75C3_DS_SetTwoSpeedAngle( int Card, int Module, int Channel, double Angle );
_75C3FUNC int CPCI75C3_DS_GetTwoSpeedAngle( int Card, int Module, int Channel, double *TwoSpeedAngle );
_75C3FUNC int CPCI75C3_DS_SetTwoSpeedBinAngle( int Card, int Module, int Channel, unsigned int TwoSpeedBinAngle );
_75C3FUNC int CPCI75C3_DS_GetTwoSpeedBinAngle( int Card, int Module, int Channel, unsigned int *TwoSpeedBinAngle );

/******   Angle Wrap Data   ******/
_75C3FUNC int CPCI75C3_DS_GetWrapAngle( int Card, int Module, int Channel, double *WrapAngle );
_75C3FUNC int CPCI75C3_DS_GetWrapAngleWord( int Card, int Module, int Channel, unsigned short *WrapAngle );

/******   Wrap S/D BandWidth Adjust   *****/
_75C3FUNC int CPCI75C3_DS_GetWrapSDBandWidth( int Card, int Module, int Channel, unsigned short *WrapSDBandWidth);
_75C3FUNC int CPCI75C3_DS_SetWrapSDBandWidth( int Card, int Module, int Channel, unsigned short WrapSDBandWidth);

/******   Velocity Data   ******/
_75C3FUNC int CPCI75C3_DS_GetVelocity( int Card, int Module, int Channel, double *Velocity );
_75C3FUNC int CPCI75C3_DS_GetVelocityWord( int Card, int Module, int Channel, signed short *Velocity );
_75C3FUNC int CPCI75C3_DS_SetVelocity( int Card, int Module, int Channel, double Velocity );
_75C3FUNC int CPCI75C3_DS_SetVelocityWord( int Card, int Module, int Channel, signed short Velocity );

/******   Active Channel Setup  ******/
_75C3FUNC int CPCI75C3_DS_SetActiveChannel( int Card, int Module, int Channel, unsigned short Setting );
_75C3FUNC int CPCI75C3_DS_GetActiveChannel( int Card, int Module, int Channel, unsigned short *Setting );
_75C3FUNC int CPCI75C3_DS_SetActiveChannelWord( int Card, int Module, unsigned short ActiveChannelWord );
_75C3FUNC int CPCI75C3_DS_GetActiveChannelWord( int Card, int Module, unsigned short *ActiveChannelWord );

/******   Channel Output   ******/
_75C3FUNC int CPCI75C3_DS_SetChanOutputState( int Card, int Module, int Channel, unsigned short Setting);
_75C3FUNC int CPCI75C3_DS_GetChanOutputState( int Card, int Module, int Channel, unsigned short *Setting);
_75C3FUNC int CPCI75C3_DS_SetOutputStateWord( int Card, int Module, unsigned short OutputStateWord);
_75C3FUNC int CPCI75C3_DS_GetOutputStateWord( int Card, int Module, unsigned short *OutputStateWord);

/******   DS Power Supply Setup   ******/
_75C3FUNC int CPCI75C3_DS_SetPowerSupplyState( int Card, int Module, int Channel, unsigned short Setting );
_75C3FUNC int CPCI75C3_DS_GetPowerSupplyState( int Card, int Module, int Channel, unsigned short* Setting );
_75C3FUNC int CPCI75C3_DS_SetPowerSupplyStateWord( int Card, int Module, unsigned short Setting );
_75C3FUNC int CPCI75C3_DS_GetPowerSupplyStateWord( int Card, int Module, unsigned short* Setting );

/******   Status Registers   ******/
_75C3FUNC int CPCI75C3_DS_GetSignalStatus( int Card, int Module, int Channel, unsigned short *Status );
_75C3FUNC int CPCI75C3_DS_GetSignalStatusWord( int Card, int Module, unsigned short *StatusWord );
_75C3FUNC int CPCI75C3_DS_GetRefStatus( int Card, int Module, int Channel, unsigned short *Status );
_75C3FUNC int CPCI75C3_DS_GetRefStatusWord( int Card, int Module, unsigned short *StatusWord );
_75C3FUNC int CPCI75C3_DS_GetPLLStatus( int Card, int Module, int Channel, unsigned short *Status );
_75C3FUNC int CPCI75C3_DS_GetPLLStatusWord( int Card, int Module, unsigned short *StatusWord );
_75C3FUNC int CPCI75C3_DS_GetBITStatus( int Card, int Module, int Channel, unsigned short *Status );
_75C3FUNC int CPCI75C3_DS_GetBITStatusWord( int Card, int Module, unsigned short *StatusWord );
_75C3FUNC int CPCI75C3_DS_GetRotationStatus( int Card, int Module, int Channel, unsigned short *RotationStatus );


/******     DS Rotation Control    *******/
_75C3FUNC int CPCI75C3_DS_SetStopAngle( int Card, int Module, int Channel, double Angle );
_75C3FUNC int CPCI75C3_DS_GetStopAngle( int Card, int Module, int Channel, double *Angle );
_75C3FUNC int CPCI75C3_DS_SetStopAngleWord( int Card, int Module, int Channel, unsigned short AngleWord );
_75C3FUNC int CPCI75C3_DS_GetStopAngleWord( int Card, int Module, int Channel, unsigned short *AngleWord );
_75C3FUNC int CPCI75C3_DS_SetRotationRate( int Card, int Module, int Channel, double DegeesPerSecond );
_75C3FUNC int CPCI75C3_DS_GetRotationRate( int Card, int Module, int Channel, double *RotationRate );
_75C3FUNC int CPCI75C3_DS_SetRotationRateWord( int Card, int Module, int Channel, int DegreesPerSecond );
_75C3FUNC int CPCI75C3_DS_GetRotationRateWord( int Card, int Module, int Channel, int *RotationRate );
_75C3FUNC int CPCI75C3_DS_SetInitRotation( int Card, int Module, int Channel );
_75C3FUNC int CPCI75C3_DS_SetStopRotation( int Card, int Module, int Channel );
_75C3FUNC int CPCI75C3_DS_SetRotModeStartStop( int Card, int Module, int Channel );
_75C3FUNC int CPCI75C3_DS_SetRotModeCont( int Card, int Module, int Channel );
_75C3FUNC int CPCI75C3_DS_SetRotMode( int Card, int Module, int Channel, unsigned short RotMode );
_75C3FUNC int CPCI75C3_DS_GetRotModeSetting( int Card, int Module, int Channel, unsigned short *RotModeSetting );
_75C3FUNC int CPCI75C3_DS_SetRotationModeWord( int Card, int Module, unsigned short RotationModeWord );
_75C3FUNC int CPCI75C3_DS_GetRotationModeWord( int Card, int Module, unsigned short *RotationModeWord );
_75C3FUNC int CPCI75C3_DS_SetRotationTriggerMode( int Card, int Module, int Channel, unsigned short RotTriggerMode );
_75C3FUNC int CPCI75C3_DS_GetRotationTriggerMode( int Card, int Module, int Channel, unsigned short *RotTriggerMode );
_75C3FUNC int CPCI75C3_DS_SetRotationTriggerSlope( int Card, int Module, unsigned short RotTriggerSlope );
_75C3FUNC int CPCI75C3_DS_GetRotationTriggerSlope( int Card, int Module, unsigned short *RotTriggerSlope );

/******      DS Ratio      *******/
_75C3FUNC int CPCI75C3_DS_SetRatio( int Card, int Module, int Channel, unsigned short Ratio );
_75C3FUNC int CPCI75C3_DS_GetRatio( int Card, int Module, int Channel, unsigned short *Ratio );

/******   Phase Data   ******/
_75C3FUNC int CPCI75C3_DS_SetPhase( int Card, int Module, int Channel, double Phase );
_75C3FUNC int CPCI75C3_DS_SetPhaseWord( int Card, int Module, int Channel, unsigned short PhaseWord );
_75C3FUNC int CPCI75C3_DS_GetPhase( int Card, int Module, int Channel, double *Phase );
_75C3FUNC int CPCI75C3_DS_GetPhaseWord( int Card, int Module, int Channel, unsigned short *PhaseWord );

/******   Reference And Line-to-Line Voltage Setup  ******/
_75C3FUNC int CPCI75C3_DS_SetExpRefVoltInput( int Card, int Module, int Channel, double dSetting );
_75C3FUNC int CPCI75C3_DS_GetExpRefVoltInput( int Card, int Module, int Channel, double *Setting );
_75C3FUNC int CPCI75C3_DS_SetExpRefVoltInputWord( int Card, int Module, int Channel, unsigned short Setting );
_75C3FUNC int CPCI75C3_DS_GetExpRefVoltInputWord( int Card, int Module, int Channel, unsigned short *Setting );
_75C3FUNC int CPCI75C3_DS_SetExpVllVoltInput( int Card, int Module, int Channel, double dSetting );
_75C3FUNC int CPCI75C3_DS_GetExpVllVoltInput( int Card, int Module, int Channel, double *Setting );
_75C3FUNC int CPCI75C3_DS_SetExpVllVoltInputWord( int Card, int Module, int Channel, unsigned short Setting );
_75C3FUNC int CPCI75C3_DS_GetExpVllVoltInputWord( int Card, int Module, int Channel, unsigned short *Setting );

/******   Reference Loss Threshold Setup  ******/
_75C3FUNC int CPCI75C3_DS_SetRefLossThreshold( int Card, int Module, int Channel, double dSetting );
_75C3FUNC int CPCI75C3_DS_GetRefLossThreshold( int Card, int Module, int Channel, double *dSetting );
_75C3FUNC int CPCI75C3_DS_SetRefLossThresholdWord( int Card, int Module, int Channel, unsigned short dSetting );
_75C3FUNC int CPCI75C3_DS_GetRefLossThresholdWord( int Card, int Module, int Channel, unsigned short *dSetting );

/******   Signal Loss Threshold Setup  ******/
_75C3FUNC int CPCI75C3_DS_SetSigLossThreshold( int Card, int Module, int Channel, double dSetting );
_75C3FUNC int CPCI75C3_DS_GetSigLossThreshold( int Card, int Module, int Channel, double *dSetting );
_75C3FUNC int CPCI75C3_DS_SetSigLossThresholdWord( int Card, int Module, int Channel, unsigned short dSetting );
_75C3FUNC int CPCI75C3_DS_GetSigLossThresholdWord( int Card, int Module, int Channel, unsigned short *dSetting );

/* RefVll Mode (Ratio = 0; Fixed = 1)  */
/******  RefVll Mode (Ratio = 0; Fixed = 1)  ******/
_75C3FUNC int CPCI75C3_DS_SetVllOutputMode( int Card, int Module, int Channel, unsigned short Setting );
_75C3FUNC int CPCI75C3_DS_GetVllOutputMode( int Card, int Module, int Channel, unsigned short *Setting );
_75C3FUNC int CPCI75C3_DS_SetVllOutputModeWord( int Card, int Module, unsigned short Setting );
_75C3FUNC int CPCI75C3_DS_GetVllOutputModeWord( int Card, int Module, unsigned short *Setting );
/*  NOTE: These API exists to support previous releases of the 75C3 DS module APIs.  
          User should call 
          CPCI75C3_DS_SetVllOutputMode() directly instead of CPCI75C3_DS_SetRefVllMode()
          CPCI75C3_DS_GetVllOutputMode() directly instead of CPCI75C3_DS_GetRefVllMode()
          CPCI75C3_DS_SetVllOutputModeWord() directly instead of CPCI75C3_DS_SetRefVllModeWord()
          CPCI75C3_DS_GetVllOutputModeWord() directly instead of CPCI75C3_DS_GetRefVllModeWord()
*/
_75C3FUNC int CPCI75C3_DS_SetRefVllMode( int Card, int Module, int Channel, unsigned short Setting );
_75C3FUNC int CPCI75C3_DS_GetRefVllMode( int Card, int Module, int Channel, unsigned short *Setting );
_75C3FUNC int CPCI75C3_DS_SetRefVllModeWord( int Card, int Module, unsigned short Setting );
_75C3FUNC int CPCI75C3_DS_GetRefVllModeWord( int Card, int Module, unsigned short *Setting );

/******   Channel Modes  SYN,RSL,2Wire,4Wire  ******/
_75C3FUNC int CPCI75C3_DS_SetSynRes( int Card, int Module, int Channel, unsigned short SynRes );
_75C3FUNC int CPCI75C3_DS_GetSynRes( int Card, int Module, int Channel, unsigned short *SynRes	);
_75C3FUNC int CPCI75C3_DS_SetSynResWord( int Card, int Module, unsigned short SynRes );
_75C3FUNC int CPCI75C3_DS_GetSynResWord( int Card, int Module, unsigned short *SynRes );
_75C3FUNC int CPCI75C3_DS_SetChanMode( int Card, int Module, int Channel, unsigned short Mode );
_75C3FUNC int CPCI75C3_DS_GetChanMode( int Card, int Module, int Channel, unsigned short *Mode );

/******   DS Test Enable   ******/
_75C3FUNC int CPCI75C3_DS_SetTestEnableWord( int Card, int Module, unsigned short TestEnableWord );
_75C3FUNC int CPCI75C3_DS_GetTestEnableWord( int Card, int Module, unsigned short *TestEnableWord );
_75C3FUNC int CPCI75C3_DS_SetD2TestVerifyValue( int Card, int Module, unsigned short Word );
_75C3FUNC int CPCI75C3_DS_GetD2TestVerifyValue( int Card, int Module, unsigned short *Word );

/******     Measured Vref and Vll   *****/ 
_75C3FUNC int CPCI75C3_DS_GetAccumAngle( int Card, int Module, int Channel, double *Angle );
_75C3FUNC int CPCI75C3_DS_GetAccumAngleDoubleWord( int Card, int Module, int Channel, unsigned int *Angle );
_75C3FUNC int CPCI75C3_DS_GetRefReadBackFreq( int Card, int Module, int Channel, unsigned short *RefFreq );
_75C3FUNC int CPCI75C3_DS_GetRefReadBackVoltage( int Card, int Module, int Channel, double *RefInVolt );
_75C3FUNC int CPCI75C3_DS_GetRefReadBackVoltageWord( int Card, int Module, int Channel, unsigned short *RefInVoltWord );
_75C3FUNC int CPCI75C3_DS_GetSigReadBackVoltage( int Card, int Module, int Channel, double *SigInVolt );
_75C3FUNC int CPCI75C3_DS_GetSigReadBackVoltageWord( int Card, int Module, int Channel, unsigned short *SigInVoltWord );

/* Interrupts */
_75C3FUNC int CPCI75C3_DS_SetSignalStatusIntEnable( int Card, int Module, int Channel, unsigned short SignalStatusIntEnab);
_75C3FUNC int CPCI75C3_DS_GetSignalStatusIntEnable( int Card, int Module, int Channel, unsigned short *SignalStatusIntEnab);
_75C3FUNC int CPCI75C3_DS_SetSignalStatusIntEnableWord( int Card, int Module, unsigned short SignalStatusIntEnab);
_75C3FUNC int CPCI75C3_DS_GetSignalStatusIntEnableWord( int Card, int Module, unsigned short *SignalStatusIntEnab);

_75C3FUNC int CPCI75C3_DS_SetRefStatusIntEnable( int Card, int Module, int Channel, unsigned short RefStatusIntEnab);
_75C3FUNC int CPCI75C3_DS_GetRefStatusIntEnable( int Card, int Module, int Channel, unsigned short *RefStatusIntEnab);
_75C3FUNC int CPCI75C3_DS_SetRefStatusIntEnableWord( int Card, int Module, unsigned short RefStatusIntEnab);
_75C3FUNC int CPCI75C3_DS_GetRefStatusIntEnableWord( int Card, int Module, unsigned short *RefStatusIntEnab);

_75C3FUNC int CPCI75C3_DS_SetBITStatusIntEnable( int Card, int Module, int Channel, unsigned short BITStatusIntEnab);
_75C3FUNC int CPCI75C3_DS_GetBITStatusIntEnable( int Card, int Module, int Channel, unsigned short *BITStatusIntEnab);
_75C3FUNC int CPCI75C3_DS_SetBITStatusIntEnableWord( int Card, int Module, unsigned short BITStatusIntEnab);
_75C3FUNC int CPCI75C3_DS_GetBITStatusIntEnableWord( int Card, int Module, unsigned short *BITStatusIntEnab);

_75C3FUNC int CPCI75C3_DS_SetLockLossIntEnable( int Card, int Module, int Channel, unsigned short LockLossIntEnab);
_75C3FUNC int CPCI75C3_DS_GetLockLossIntEnable( int Card, int Module, int Channel, unsigned short *LockLossIntEnab);
_75C3FUNC int CPCI75C3_DS_SetLockLossIntEnableWord( int Card, int Module, unsigned short LockLossIntEnab);
_75C3FUNC int CPCI75C3_DS_GetLockLossIntEnableWord( int Card, int Module, unsigned short *LockLossIntEnab);

/*Setup SD Interrupt Vectors*/
_75C3FUNC int CPCI75C3_DS_GetSignalLossVector( int Card, int Module, unsigned short *InterruptVector );
_75C3FUNC int CPCI75C3_DS_SetSignalLossVector( int Card, int Module, unsigned short InterruptVector );
_75C3FUNC int CPCI75C3_DS_GetRefLossVector( int Card, int Module, unsigned short *InterruptVector );
_75C3FUNC int CPCI75C3_DS_SetRefLossVector( int Card, int Module, unsigned short InterruptVector );
_75C3FUNC int CPCI75C3_DS_GetBitFailVector( int Card, int Module, unsigned short *InterruptVector );
_75C3FUNC int CPCI75C3_DS_SetBitFailVector( int Card, int Module, unsigned short InterruptVector );
_75C3FUNC int CPCI75C3_DS_GetLockLossVector( int Card, int Module, unsigned short *InterruptVector );
_75C3FUNC int CPCI75C3_DS_SetLockLossVector( int Card, int Module, unsigned short InterruptVector );

/******   Torque Rx Mode   ******/
_75C3FUNC int CPCI75C3_DS_GetTorqueRxModeWord( int Card, int Module, unsigned short *TorqueRxMode);
_75C3FUNC int CPCI75C3_DS_SetTorqueRxModeWord( int Card, int Module, unsigned short TorqueRxMode);

/******   Optional Reference Supply Control   ******/
_75C3FUNC int CPCI75C3_DS_SetOnBrdRefFreq( int Card, int Module, unsigned int Frequency );
_75C3FUNC int CPCI75C3_DS_GetOnBrdRefFreq( int Card, int Module, unsigned int *RefFreq );
_75C3FUNC int CPCI75C3_DS_SetOnBrdRefFreqWord( int Card, int Module, unsigned int Frequency );
_75C3FUNC int CPCI75C3_DS_GetOnBrdRefFreqWord( int Card, int Module, unsigned int *RefFreq );
_75C3FUNC int CPCI75C3_DS_SetOnBrdRefVoltage( int Card, int Module, double Voltage );
_75C3FUNC int CPCI75C3_DS_GetOnBrdRefVoltage( int Card, int Module, double *RefVoltage );
_75C3FUNC int CPCI75C3_DS_SetOnBrdRefVoltageWord( int Card, int Module, unsigned int Voltage );
_75C3FUNC int CPCI75C3_DS_GetOnBrdRefVoltageWord( int Card, int Module, unsigned int *RefVoltage );

/******      Compile Time            *****/
_75C3FUNC int CPCI75C3_DS_GetCompileTime( int Card, int Module, unsigned short *CompileTimeBuffer );

/* ################################################################################################# */
/*  For Internal Use Only                                                                            */
/*  Utility functions, do not need to export                                                         */
/* ################################################################################################# */
/******      Current Readings **Internal use only**   ******/
_75C3FUNC int CPCI75C3_DS_GetCurrentWord( int Card, int Module, int Channel, unsigned short *CurrentWord );
_75C3FUNC int CPCI75C3_DS_GetCurrentThresholdWord(int Card, int Module, int Channel, unsigned short *currentThreshold);
_75C3FUNC int CPCI75C3_DS_SetCurrentThresholdWord(int Card, int Module, int Channel, unsigned short currentThreshold);
_75C3FUNC int CPCI75C3_DS_GetCalDwellTime(int Card, int Module, int Channel, unsigned short *CalDwellTime);
_75C3FUNC int CPCI75C3_DS_GetModuleTemperature(int Card, int Module, unsigned short *Temperature);
_75C3FUNC int CPCI75C3_DS_BackGroundCalEnableWord(int Card, int Module, unsigned short *bCalEnable);

int CPCI75C3_DS_CheckCardModuleChannel(int Card, int Module, int Channel);

#ifdef __cplusplus
}
#endif

#endif
