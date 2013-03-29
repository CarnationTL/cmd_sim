/**
 *=========================================================================
 *
 * Copyright (c) 2011 North Atlantic Industries, Inc.  All Rights Reserved.
 *
 * Author: North Atlantic Industries, Inc.
 *
 * Project: CPCI75C3Dll
 *
 * SubSystem: 
 *
 * FileName: CPCI75C3.h
 *========================================================================*/
#ifndef _CPCI75C3_H
#define _CPCI75C3_H

#ifdef __ADSPBLACKFIN__
#include "naitypes.h"
#include "enailib.h"
#else
#include "nailib.h"
#include "NAIEthernet.h"
#endif

#include  "CPCI75C3_include.h"  

#ifdef __cplusplus
extern "C" {
#endif 

#define NAI_MAX_CARD                  20   /* Used for PCI Enumeration */
#define CPCI75C3_MAX_CARD             20
#define CPCI75C3_MAX_MODULE           3
#define PCI_MOD_MEM_SIZE              0x800
#define IP_ADDR_LEN                   15	
#define ONBOARD_ACCESS_MASK           0xFF000000

/* Module specific header files */
#include "CPCI75C3_1553.h"
#include "CPCI75C3_AD.h"
#include "CPCI75C3_AR.h"
#include "CPCI75C3_CAN.h"
#include "CPCI75C3_DA.h"
#include "CPCI75C3_DIF.h"
#include "CPCI75C3_DL.h"
#include "CPCI75C3_DS.h"
#include "CPCI75C3_DT.h"
#include "CPCI75C3_DSW.h"
#include "CPCI75C3_ENC.h"	
#include "CPCI75C3_LVDT.h"	
#include "CPCI75C3_PS.h"	
#include "CPCI75C3_REF.h"	
#include "CPCI75C3_RTD.h"	
#include "CPCI75C3_SD.h"	
#include "CPCI75C3_SERIAL.h"
#include "CPCI75C3_TTL.h"

/*  Device ID value for CPCI75C3 */
#define CPCI75C3_ID           0x7593
#define CPCI75C3_ID_NI        0x0001  /* National Instruments Driver is always reporting 1 for Model ID */

#define CPCI75C3_AD_MAX_CHAN          10
#define CPCI75C3_AD_KA_MAX_CHAN       4
#define CPCI75C3_DA_MAX_CHAN          10
#define CPCI75C3_RTD_MAX_CHAN         6
#define CPCI75C3_DT_MAX_CHAN          16
#define CPCI75C3_DT_KA_MAX_CHAN       28
#define CPCI75C3_DSW_MAX_CHAN         16
#define CPCI75C3_ENC_MAX_CHAN         4
#define CPCI75C3_TTL_MAX_CHAN         16
#define CPCI75C3_SER_MAX_CHAN         4
#define CPCI75C3_AR_MAX_CHAN          6
#define CPCI75C3_1553_MAX_CHAN        2
#define CPCI75C3_CAN_MAX_CHAN         4
#define CPCI75C3_SD_MAX_CHAN          4
#define CPCI75C3_DS_MAX_CHAN          3
#define CPCI75C3_LD_MAX_CHAN          4
#define CPCI75C3_DL_MAX_CHAN          3
#define CPCI75C3_SIG_MAX_CHAN         4
#define CPCI75C3_USB_MAX_CHAN         6 
#define CPCI75C3_DIF_MAX_CHAN         11

   /* Number of VCC banks on each Module.    */
#define CPCI75C3_DT_NUM_VCC_BANKS 4

/*
 * The following status values indicate success and
 * failure codes for the API functions.
 */

typedef enum {
 CPCI75C3_SUCCESS,
 CPCI75C3_CARD_NOT_FOUND,
 CPCI75C3_INVALID_CARD,
 CPCI75C3_INVALID_INTERFACEMODE,
 CPCI75C3_INVALID_REG_ADDR,
 CPCI75C3_INVALID_MODULE,
 CPCI75C3_INVALID_CHANNEL,
 CPCI75C3_INVALID_PARAMETER,
 CPCI75C3_INVALID_BREAK_FREQ,
 CPCI75C3_INVALID_VOLTAGE,
 CPCI75C3_INVALID_RANGE,
 CPCI75C3_INVALID_BANK,
 CPCI75C3_INVALID_OUTPUT_STATE,
 CPCI75C3_INVALID_IO_FORMAT,
 CPCI75C3_INVALID_CURRENT,
 CPCI75C3_INVALID_THRESHOLD,
 CPCI75C3_INVALID_DEBOUNCE_LSB,
 CPCI75C3_INVALID_DEBOUNCE_TIME,
 CPCI75C3_INVALID_CONFIG,
 CPCI75C3_INVALID_WIREMODE,
 CPCI75C3_INVALID_INTERRUPT_LEVEL,
 CPCI75C3_INVALID_INTERRUPT_VECTOR,
 CPCI75C3_INVALID_INTERRUPT_ENABLE,
 CPCI75C3_INVALID_FREQ,
 CPCI75C3_INVALID_VOLT,
 CPCI75C3_INVALID_RATIO,
 CPCI75C3_INVALID_ENCODER_RES,
 CPCI75C3_INVALID_COMMUTATION_POLES,
 CPCI75C3_INVALID_BANDWIDTH,
 CPCI75C3_INVALID_PHASE,
 CPCI75C3_INVALID_AMPLITUDE,
 CPCI75C3_INVALID_DC_OFFSET,
 CPCI75C3_INVALID_MODE,
 CPCI75C3_INVALID_PHASE_LOCK,
 CPCI75C3_INVALID_COMP_RESISTANCE,
 CPCI75C3_INVALID_POLARITY,
 CPCI75C3_INVALID_SLEW_RATE,
 CPCI75C3_D2_VERIFY_FAIL,
 CPCI75C3_WATCHDOG_ERROR,
 CPCI75C3_ENCODER_MODE_ERROR,
 CPCI75C3_COMMUTATION_MODE_ERROR,
 CPCI75C3_MEMORY_ALLOCATION,
 CPCI75C3_MEMORY_ADDRESS,
 CPCI75C3_ETHER_ERROR,
 CPCI75C3_INT_CONNECT_ERROR,
 CPCI75C3_ETHER_CANNOT_LOGON,
 CPCI75C3_INT_DISABLE_ERROR,
 CPCI75C3_INT_GET_VECTOR_ERROR,
 CPCI75C3_FIFO_FULL,
 CPCI75C3_NOT_COMPILED_IN,
 CPCI75C3_ETHER_CANNOT_LOGOFF,
 CPCI75C3_FIFO_EMPTY,
 CPCI75C3_MORE_DATA,
 CPCI75C3_INVALID_ANGLE,
 CPCI75C3_INVALID_RATE,
 CPCI75C3_UNKNOWN,
 CPCI75C3_INVALID_CONTEXT,
 CPCI75C3_FUNCTION_NOT_SUPPORTED,
 CPCI75C3_BOARD_NOT_READY,
 CPCI75C3_PARITY_ERROR,
 CPCI75C3_FRAMING_ERROR,
 CPCI75C3_PARITY_AND_FRAMING_ERROR,
 CPCI75C3_INVALID_POSITION,
 CPCI75C3_INVALID_SUBCHANNEL,
 CPCI75C3_TIMEOUT,
 CPCI75C3_INVALID_RTADDR,
 CPCI75C3_INVALID_SUBADDR,
 CPCI75C3_INVALID_RTRTCMD,
 CPCI75C3_LAST
} CPCI75C3_STATUS;

/*
 * These ASCII strings are useful for debugging but can take up
 * a lot of data space. They are optionally compiled in by way
 * of the macro shown.
 */


#define CPCI75C3_STRINGS {\
 "CPCI75C3_SUCCESS",\
 "CPCI75C3_CARD_NOT_FOUND",\
 "CPCI75C3_INVALID_CARD",\
 "CPCI75C3_INVALID_INTERFACEMODE",\
 "CPCI75C3_INVALID_REG_ADDR",\
 "CPCI75C3_INVALID_MODULE",\
 "CPCI75C3_INVALID_CHANNEL",\
 "CPCI75C3_INVALID_PARAMETER",\
 "CPCI75C3_INVALID_BREAK_FREQ",\
 "CPCI75C3_INVALID_VOLTAGE",\
 "CPCI75C3_INVALID_RANGE",\
 "CPCI75C3_INVALID_BANK",\
 "CPCI75C3_INVALID_OUTPUT_STATE",\
 "CPCI75C3_INVALID_IO_FORMAT",\
 "CPCI75C3_INVALID_CURRENT",\
 "CPCI75C3_INVALID_THRESHOLD",\
 "CPCI75C3_INVALID_DEBOUNCE_LSB",\
 "CPCI75C3_INVALID_DEBOUNCE_TIME",\
 "CPCI75C3_INVALID_CONFIG",\
 "CPCI75C3_INVALID_WIREMODE",\
 "CPCI75C3_INVALID_INTERRUPT_LEVEL",\
 "CPCI75C3_INVALID_INTERRUPT_VECTOR",\
 "CPCI75C3_INVALID_INTERRUPT_ENABLE",\
 "CPCI75C3_INVALID_FREQ",\
 "CPCI75C3_INVALID_VOLT",\
 "CPCI75C3_INVALID_RATIO",\
 "CPCI75C3_INVALID_ENCODER_RES",\
 "CPCI75C3_INVALID_COMMUTATION_POLES",\
 "CPCI75C3_INVALID_BANDWIDTH",\
 "CPCI75C3_INVALID_PHASE",\
 "CPCI75C3_INVALID_AMPLITUDE",\
 "CPCI75C3_INVALID_DC_OFFSET",\
 "CPCI75C3_INVALID_MODE",\
 "CPCI75C3_INVALID_PHASE_LOCK",\
 "CPCI75C3_INVALID_COMP_RESISTANCE",\
 "CPCI75C3_INVALID_POLARITY",\
 "CPCI75C3_INVALID_SLEW_RATE",\
 "CPCI75C3_D2_VERIFY_FAIL",\
 "CPCI75C3_WATCHDOG_ERROR",\
 "CPCI75C3_ENCODER_MODE_ERROR",\
 "CPCI75C3_COMMUTATION_MODE_ERROR",\
 "CPCI75C3_MEMORY_ALLOCATION",\
 "CPCI75C3_MEMORY_ADDRESS",\
 "CPCI75C3_ETHER_ERROR",\
 "CPCI75C3_INT_CONNECT_ERROR",\
 "CPCI75C3_ETHER_CANNOT_LOGON",\
 "CPCI75C3_INT_DISABLE_ERROR",\
 "CPCI75C3_INT_GET_VECTOR_ERROR",\
 "CPCI75C3_FIFO_FULL",\
 "CPCI75C3_NOT_COMPILED_IN",\
 "CPCI75C3_ETHER_CANNOT_LOGOFF",\
 "CPCI75C3_FIFO_EMPTY",\
 "CPCI75C3_MORE_DATA",\
 "CPCI75C3_INVALID_ANGLE",\
 "CPCI75C3_INVALID_RATE",\
 "CPCI75C3_UNKNOWN",\
 "CPCI75C3_INVALID_CONTEXT",\
 "CPCI75C3_FUNCTION_NOT_SUPPORTED",\
 "CPCI75C3_BOARD_NOT_READY",\
 "CPCI75C3_PARITY_ERROR",\
 "CPCI75C3_FRAMING_ERROR",\
 "CPCI75C3_PARITY_AND_FRAMING_ERROR",\
 "CPCI75C3_INVALID_POSITION",\
 "CPCI75C3_INVALID_SUBCHANNEL",\
 "CPCI75C3_TIMEOUT",\
 "CPCI75C3_INVALID_RTADDR",\
 "CPCI75C3_INVALID_SUBADDR",\
 "CPCI75C3_INVALID_RTRTCMD",\
 "CPCI75C3_LAST"\
}

#define BOARD_READY              0xAA55

/* common definitions for D/S and S/D */
#define VELOCITY_SCALE           190.73486328125 * 4095.0 / 32768.0
#define ANGLE_BIT16              0.0054931640625 
#define ANGLE_BIT17              0.00274658203125
#define ANGLE_BIT24              0.0000214576721191
#define ANGLE_BIT25              0.00001072883606
#define ANGLE_BIT32              0.0000000838190317

/* common definitions for DLV and LVDT */
#define LVDT_POSITION_BIT16      50.0/0x7FFF         
#define LVDT_POSITION_BIT32      50.0/0x7FFFFFFF
#define POSITION_BIT16           0.0000305176                   /* 2/65536 */
#define POSITION_BIT17           0.0000152588                   /* 2/131072 */
#define POSITION_BIT32           0.0000000004656612873077390    /* 2/2^32*/
#define D0_POS_SIGN              1/0x7FFF
 
/*
 * Note: ModuleID and Module Type is different. Module Type is a class of modules,
 * Say Module type A/D, now we have two kinds of Module for A/D, C1
 * (+/-10V A/D module) and C2(+/-40V A/D module).
 * See Spec for detailed descriptions for ModuleID
 */
/* Module IDs for CPCI75C3 Board, Encoded in 2 ASCII characters */

/* No module in the slot */
#define MODULE_ID_Z0           0x5A30

/* AD Modules */
#define MODULE_ID_C1           0x4331
#define MODULE_ID_C2           0x4332
#define MODULE_ID_C3           0x4333
#define MODULE_ID_C4           0x4334
#define MODULE_ID_CA           0x4341
#define MODULE_ID_CX           0x4358

/* DA Modules */
#define MODULE_ID_F1           0x4631
#define MODULE_ID_F2           0x4632
#define MODULE_ID_F3           0x4633
#define MODULE_ID_F4           0x4634
#define MODULE_ID_F5           0x4635
#define MODULE_ID_J3           0x4A33
#define MODULE_ID_J5           0x4A35
#define MODULE_ID_J6           0x4A36
#define MODULE_ID_J7           0x4A37
#define MODULE_ID_J8           0x4A38

/* RTD Modules */
#define MODULE_ID_G1           0x4731
#define MODULE_ID_G2           0x4732
#define MODULE_ID_G4           0x4734

/* DT (Discrete IO Module) */
#define MODULE_ID_K1           0x4B31
#define MODULE_ID_K2           0x4B32
#define MODULE_ID_K3           0x4B33
#define MODULE_ID_K4           0x4B34
#define MODULE_ID_K6           0x4B36
#define MODULE_ID_K9           0x4B39

/* DSW (Digital Switch Module) */
#define MODULE_ID_K7           0x4B37

/* ENC (Encoder Module) */
#define MODULE_ID_E7           0x4537

/* TTL (Digital IO Module) */
#define MODULE_ID_D1           0x4431
#define MODULE_ID_D7           0x4437

/*DIF (Differential Module) */
#define MODULE_ID_D2           0x4432
#define MODULE_ID_D8           0x4438

/* MUL Module */
#define MODULE_ID_T1           0x5431
#define MODULE_ID_T2           0x5432

/* SD Module */
#define MODULE_ID_R1           0x5231
#define MODULE_ID_R2           0x5232
#define MODULE_ID_R3           0x5233
#define MODULE_ID_R4           0x5234
#define MODULE_ID_R5           0x5235
#define MODULE_ID_R6           0x5236
#define MODULE_ID_R7           0x5237

#define MODULE_ID_S1           0x5331
#define MODULE_ID_S2           0x5332
#define MODULE_ID_S3           0x5333
#define MODULE_ID_S4           0x5334
#define MODULE_ID_S5           0x5335
#define MODULE_ID_S6           0x5336

#define MODULE_ID_SA           0x5341
#define MODULE_ID_SB           0x5342
#define MODULE_ID_SC           0x5343
#define MODULE_ID_SD           0x5344
#define MODULE_ID_SE           0x5345
#define MODULE_ID_SF           0x5346
#define MODULE_ID_SG           0x5347
#define MODULE_ID_SH           0x5348
#define MODULE_ID_SJ           0x534A
#define MODULE_ID_SX           0x5358

/* LD Module */
#define MODULE_ID_LB           0x4C42
#define MODULE_ID_LC           0x4C43
#define MODULE_ID_LD           0x4C44
#define MODULE_ID_LE           0x4C45
#define MODULE_ID_LF           0x4C46
#define MODULE_ID_LG           0x4C47
#define MODULE_ID_LX           0x4C58

/* PS Modules */
#define MODULE_ID_V1           0x5631
#define MODULE_ID_V2           0x5632

/* DS / DLV Modules */
#define MODULE_ID_10           0x3130  /* 2 ch  , SYN      , 2-28 Vll  , 2-115 VRef, 400-1KHz, 1.5 VA */
#define MODULE_ID_11           0x3131  /* 2 ch  , RSL      , 2-28 Vll  , 2-115 VRef, 400-1KHz, 1.5 VA */
#define MODULE_ID_12           0x3132  /* 2 ch  , PRG S/R  , 2-28 Vll  , 2-115 VRef, 400-1KHz, 1.5 VA */
#define MODULE_ID_13           0x3133  /* 2 ch  , SYN/RSL  , 2-28 Vll  , 2-115 VRef, 400-1KHz, 1.5 VA */
#define MODULE_ID_14           0x3134  /* 2 ch  , RSL/SYN  , 2-28 Vll  , 2-115 VRef, 400-1KHz, 1.5 VA */
#define MODULE_ID_15           0x3135  /* 2 ch  , SYN      , 2-28 Vll  , 2-115 VRef, 47-440Hz, 1.5 VA */
#define MODULE_ID_16           0x3136  /* 2 ch  , RSL      , 2-28 Vll  , 2-115 VRef, 47-440Hz, 1.5 VA */
#define MODULE_ID_17           0x3137  /* 2 ch  , PRG S/R  , 2-28 Vll  , 2-115 VRef, 47-440Hz, 1.5 VA */
#define MODULE_ID_18           0x3138  /* 2 ch  , SYN/RSL  , 2-28 Vll  , 2-115 VRef, 47-440Hz, 1.5 VA */
#define MODULE_ID_19           0x3139  /* 2 ch  , RSL/SYN  , 2-28 Vll  , 2-115 VRef, 47-440Hz, 1.5 VA */
#define MODULE_ID_1A           0x3141  /* 2 ch  , RSL      , 2-28 Vll  , 2-115 VRef, 1K-3KHz , 1.5 VA */
#define MODULE_ID_1B           0x3142  /* 2 ch  , RSL      , 2-28 Vll  , 2-115 VRef, 3K-5KHz , 1.5 VA */
#define MODULE_ID_1C           0x3143  /* 2 ch  , RSL      , 2-28 Vll  , 2-115 VRef, 5K-7KHz , 1.5 VA */
#define MODULE_ID_1D           0x3144  /* 2 ch  , RSL      , 2-28 Vll  , 2-115 VRef, 7K-10KHz, 1.5 VA */
#define MODULE_ID_1E           0x3145  /* 2 ch  , PRG S/DLV, 2-11.8 Vll, 2-115 VRef, 400-1KHz, 1.5 VA */
#define MODULE_ID_1F           0x3146  /* 2 ch  , SYN      , 2-11.8 Vll, 2-115 VRef, 47-400Hz, 1.5 VA */
#define MODULE_ID_1G           0x3147  /* 2 ch  , SYN      , 2-11.8 Vll, 2-115 VRef, 1K-3KHz , 1.5 VA */
#define MODULE_ID_1H           0x3148  /* 2 ch  , SYN      , 2-11.8 Vll, 2-115 VRef, 3K-5KHz , 1.5 VA */
#define MODULE_ID_1J           0x314A  /* 2 ch  , SYN      , 2-11.8 Vll, 2-115 VRef, 5K-7KHz , 1.5 VA */
#define MODULE_ID_1K           0x314B  /* 2 ch  , SYN      , 2-11.8 Vll, 2-115 VRef, 7K-10KHz, 1.5 VA */
#define MODULE_ID_1L           0x314C  /* 2 ch  , SYN      , 2-28 Vll  , 2-115 VRef, 1K-3KHz , 1.5 VA */
#define MODULE_ID_1M           0x314D  /* 2 ch  , SYN      , 2-28 Vll  , 2-115 VRef, 3K-5KHz , 1.5 VA */
#define MODULE_ID_1N           0x314E  /* 2 ch  , SYN      , 2-28 Vll  , 2-115 VRef, 5K-7KHz , 1.5 VA */
#define MODULE_ID_1P           0x3150  /* 2 ch  , SYN      , 2-28 Vll  , 2-115 VRef, 7K-10KHz, 1.5 VA */

#define MODULE_ID_20           0x3230  /* 2 ch  , SYN      , 90 Vll    , 2-115 VRef, 400-1KHz, 1.5 VA */
#define MODULE_ID_21           0x3231  /* 2 ch  , RSL      , 90 Vll    , 2-115 VRef, 400-1KHz, 1.5 VA */
#define MODULE_ID_22           0x3232  /* 2 ch  , PRG S/R  , 90 Vll    , 2-115 VRef, 400-1KHz, 1.5 VA */
#define MODULE_ID_23           0x3233  /* 2 ch  , SYN/RSL  , 90 Vll    , 2-115 VRef, 400-1KHz, 1.5 VA */
#define MODULE_ID_24           0x3234  /* 2 ch  , RSL/SYN  , 90 Vll    , 2-115 VRef, 400-1KHz, 1.5 VA */
#define MODULE_ID_25           0x3235  /* 2 ch  , SYN      , 90 Vll    , 2-115 VRef, 47-440Hz, 1.5 VA */
#define MODULE_ID_26           0x3236  /* 2 ch  , RSL      , 90 Vll    , 2-115 VRef, 47-440Hz, 1.5 VA */
#define MODULE_ID_27           0x3237  /* 2 ch  , PRG S/R  , 90 Vll    , 2-115 VRef, 47-440Hz, 1.5 VA */
#define MODULE_ID_28           0x3238  /* 2 ch  , SYN/RSL  , 90 Vll    , 2-115 VRef, 47-440Hz, 1.5 VA */
#define MODULE_ID_29           0x3239  /* 2 ch  , RSL/SYN  , 90 Vll    , 2-115 VRef, 47-440Hz, 1.5 VA */

#define MODULE_ID_30           0x3330  /* 1 ch  , SYN      , 11.8 Vll  , 2-115 VRef, 400-1KHz, 3.0 VA */
#define MODULE_ID_31           0x3331  /* 1 ch  , RSL      , 2-28 Vll  , 2-115 VRef, 400-1KHz, 3.0 VA */
#define MODULE_ID_35           0x3335  /* 1 ch  , SYN      , 11.8 Vll  , 2-115 VRef, 47-440Hz, 3.0 VA */
#define MODULE_ID_36           0x3336  /* 1 ch  , RSL      , 2-28 Vll  , 2-115 VRef, 47-440Hz, 3.0 VA */
#define MODULE_ID_3A           0x3341  /* 1 ch  , RSL      , 2-28 Vll  , 2-115 VRef, 1K-3KHz , 3.0 VA */
#define MODULE_ID_3B           0x3342  /* 1 ch  , RSL      , 2-28 Vll  , 2-115 VRef, 3K-5KHz , 3.0 VA */
#define MODULE_ID_3C           0x3343  /* 1 ch  , RSL      , 2-28 Vll  , 2-115 VRef, 5K-7KHz , 3.0 VA */
#define MODULE_ID_3D           0x3344  /* 1 ch  , RSL      , 2-28 Vll  , 2-115 VRef, 7K-20KHz, 3.0 VA */
#define MODULE_ID_3E           0x3345  /* 1 ch  , SYN      , 2-11.8 Vll, 2-115 VRef, 1K-3KHz , 3.0 VA */
#define MODULE_ID_3F           0x3346  /* 1 ch  , SYN      , 2-11.8 Vll, 2-115 VRef, 3K-5KHz , 3.0 VA */
#define MODULE_ID_3G           0x3347  /* 1 ch  , SYN      , 2-11.8 Vll, 2-115 VRef, 5K-7KHz , 3.0 VA */
#define MODULE_ID_3H           0x3348  /* 1 ch  , SYN      , 2-11.8 Vll, 2-115 VRef, 7K-10KHz, 3.0 VA */
#define MODULE_ID_3J           0x334A  /* 1 ch  , SYN      , 2-28 Vll  , 2-115 VRef, 1K-3KHz , 3.0 VA */
#define MODULE_ID_3K           0x334B  /* 1 ch  , SYN      , 2-28 Vll  , 2-115 VRef, 3K-5KHz , 3.0 VA */
#define MODULE_ID_3L           0x334C  /* 1 ch  , SYN      , 2-28 Vll  , 2-115 VRef, 5K-7KHz , 3.0 VA */
#define MODULE_ID_3M           0x334D  /* 1 ch  , SYN      , 2-28 Vll  , 2-115 VRef, 7K-10KHz, 3.0 VA */

#define MODULE_ID_40           0x3430  /* 1 ch  , SYN      , 90 Vll    , 2-115 VRef, 400-1KHz, 3.0 VA */
#define MODULE_ID_41           0x3431  /* 1 ch  , RSL      , 90 Vll    , 2-115 VRef, 400-1KHz, 3.0 VA */
#define MODULE_ID_45           0x3435  /* 1 ch  , SYN      , 90 Vll    , 2-115 VRef, 47-440Hz, 3.0 VA */
#define MODULE_ID_46           0x3436  /* 1 ch  , RSL      , 90 Vll    , 2-115 VRef, 47-440Hz, 3.0 VA */

#define MODULE_ID_50           0x3530  /* 2/4 ch, DLV      , 2-28 Vll  , 2-28 VRef , 400-1KHz, 1.5 VA */
#define MODULE_ID_51           0x3531  /* 2/4 ch, DLV      , 2-28 Vll  , 2-28 VRef , 47-440Hz, 1.5 VA */
#define MODULE_ID_52           0x3532  /* 2/4 ch, DLV      , 2-28 Vll  , 2-28 VRef , 1K-3KHz , 1.5 VA */
#define MODULE_ID_53           0x3533  /* 2/4 ch, DLV      , 2-28 Vll  , 2-28 VRef , 3K-5KHz , 1.5 VA */
#define MODULE_ID_54           0x3534  /* 2/4 ch, DLV      , 2-28 Vll  , 2-28 VRef , 5K-7KHz , 1.5 VA */
#define MODULE_ID_55           0x3535  /* 2/4 ch, DLV      , 2-28 Vll  , 2-28 VRef , 7K-10KHz, 1.5 VA */
#define MODULE_ID_5A           0x3541  /* 3/6 ch, DLV      , 2-28 Vll  , 2-115 VRef , 400-1KHz, 0.1 VA */
#define MODULE_ID_5B           0x3542  /* 3/6 ch, DLV      , 2-28 Vll  , 2-115 VRef , 47-440Hz, 0.1 VA */
#define MODULE_ID_5C           0x3543  /* 3/6 ch, DLV      , 2-28 Vll  , 2-115 VRef , 1K-3KHz, 0.1 VA */
#define MODULE_ID_5D           0x3544  /* 3/6 ch, DLV      , 2-28 Vll  , 2-115 VRef , 3K-5KHz, 0.1 VA */
#define MODULE_ID_5E           0x3545  /* 3/6 ch, DLV      , 2-28 Vll  , 2-115 VRef , 5K-7KHz, 0.1 VA */
#define MODULE_ID_5F           0x3546  /* 3/6 ch, DLV      , 2-28 Vll  , 2-115 VRef , 7K-10KHz, 0.1 VA */
#define MODULE_ID_5G           0x3547  /* 3/6 ch, DLV      , 2-11.8 Vll  , 2-115 VRef , 400-1KHz, 0.1 VA */
#define MODULE_ID_5H           0x3548  /* 3/6 ch, DLV      , 2-11.8 Vll  , 2-115 VRef , 47-440Hz, 0.1 VA */
#define MODULE_ID_5I           0x3549
#define MODULE_ID_5J           0x354A  /* 3/6 ch, DLV      , 2-11.8 Vll  , 2-115 VRef , 1K-3KHz, 0.1 VA */
#define MODULE_ID_5K           0x354B  /* 3/6 ch, DLV      , 2-11.8 Vll  , 2-115 VRef , 3K-5KHz, 0.1 VA */
#define MODULE_ID_5L           0x354C  /* 3/6 ch, DLV      , 2-11.8 Vll  , 2-115 VRef , 5K-7KHz, 0.1 VA */
#define MODULE_ID_5M           0x354D  /* 3/6 ch, DLV      , 2-11.8 Vll  , 2-115 VRef , 7K-10KHz, 0.1 VA */

#define MODULE_ID_60           0x3630  /* 3 ch  , SYN      , 2-11.8 Vll, 2-115 VRef, 400-1KHz, .25 VA */
#define MODULE_ID_61           0x3631  /* 3 ch  , RSL      , 2-11.8 Vll, 2-115 VRef, 400-1KHz, .25 VA */
#define MODULE_ID_62           0x3632  /* 3 ch  , RSL      , 2-28 Vll  , 2-115 VRef, 400-1KHz, .25 VA */
#define MODULE_ID_63           0x3633  /* 3 ch  , SYN      , 90 Vll    , 2-115 VRef, 400-1KHz, .25 VA */
#define MODULE_ID_64           0x3634  /* 3 ch  , RSL      , 90 Vll    , 2-115 VRef, 400-1KHz, .25 VA */
#define MODULE_ID_65           0x3635  /* 3 ch  , SYN      , 11.8 Vll  , 2-115 VRef, 47-440Hz, .25 VA */
#define MODULE_ID_66           0x3636  /* 3 ch  , RSL      , 2-11.8 Vll, 2-115 VRef, 47-440Hz, .25 VA */
#define MODULE_ID_67           0x3637  /* 3 ch  , RSL      , 2-28 Vll  , 2-115 VRef, 47-440Hz, .25 VA */
#define MODULE_ID_68           0x3638  /* 3 ch  , SYN      , 90 Vll    , 2-115 VRef, 47-440Hz, .25 VA */
#define MODULE_ID_69           0x3639  /* 3 ch  , RSL      , 90 Vll    , 2-115 VRef, 47-440Hz, .25 VA */
#define MODULE_ID_6A           0x3641  /* 3 ch  , RSL      , 2-11.8 Vll, 2-115 VRef, 1K-3KHz , .25 VA */
#define MODULE_ID_6B           0x3642  /* 3 ch  , RSL      , 2-11.8 Vll, 2-115 VRef, 3K-5KHz , .25 VA */
#define MODULE_ID_6C           0x3643  /* 3 ch  , RSL      , 2-11.8 Vll, 2-115 VRef, 5K-7KHz , .25 VA */
#define MODULE_ID_6D           0x3644  /* 3 ch  , RSL      , 2-11.8 Vll, 2-115 VRef, 7K-10KHz, .25 VA */
#define MODULE_ID_6E           0x3645  /* 3 ch  , RSL      , 2-28 Vll  , 2-115 VRef, 1K-3KHz , .25 VA */
#define MODULE_ID_6F           0x3646  /* 3 ch  , RSL      , 2-28 Vll  , 2-115 VRef, 3K-5KHz , .25 VA */
#define MODULE_ID_6G           0x3647  /* 3 ch  , RSL      , 2-28 Vll  , 2-115 VRef, 5K-7KHz , .25 VA */
#define MODULE_ID_6H           0x3648  /* 3 ch  , RSL      , 2-28 Vll  , 2-115 VRef, 7K-10KHz, .25 VA */
#define MODULE_ID_6J           0x364A  /* 3 ch  , SYN      , 2-11.8 Vll, 2-115 VRef, 1K-3KHz , .25 VA */
#define MODULE_ID_6K           0x364B  /* 3 ch  , SYN      , 2-11.8 Vll, 2-115 VRef, 3K-5KHz , .25 VA */
#define MODULE_ID_6L           0x364C  /* 3 ch  , SYN      , 2-11.8 Vll, 2-115 VRef, 5K-7KHz , .25 VA */
#define MODULE_ID_6M           0x364D  /* 3 ch  , SYN      , 2-11.8 Vll, 2-115 VRef, 7K-10KHz, .25 VA */
#define MODULE_ID_6N           0x364E  /* 3 ch  , SYN      , 2-28 Vll  , 2-115 VRef, 1K-3KHz , .25 VA */
#define MODULE_ID_6P           0x3650  /* 3 ch  , SYN      , 2-28 Vll  , 2-115 VRef, 3K-5KHz , .25 VA */
#define MODULE_ID_6Q           0x3651  /* 3 ch  , SYN      , 2-28 Vll  , 2-115 VRef, 5K-7KHz , .25 VA */
#define MODULE_ID_6R           0x3652  /* 3 ch  , SYN      , 2-28 Vll  , 2-115 VRef, 7K-10KHz, .25 VA */

#define MODULE_ID_70           0x3730  /* 1 ch  , SYN      , 2-11.8 Vll, 2-115 VRef, 400-1KHz, 1.2 VA */
#define MODULE_ID_71           0x3731  /* 1 ch  , RSL      , 2-11.8 Vll, 2-115 VRef, 400-1KHz, 1.2 VA */
#define MODULE_ID_72           0x3732  /* 1 ch  , RSL      , 2-28 Vll  , 2-115 VRef, 400-1KHz, 1.2 VA */
#define MODULE_ID_73           0x3733  /* 1 ch  , SYN      , 90 Vll    , 2-115 VRef, 400-1KHz, 1.2 VA */
#define MODULE_ID_74           0x3734  /* 1 ch  , RSL      , 90 Vll    , 2-115 VRef, 400-1KHz, 1.2 VA */
#define MODULE_ID_75           0x3735  /* 1 ch  , SYN      , 11.8 Vll  , 2-115 VRef, 47-440Hz, 1.2 VA */
#define MODULE_ID_76           0x3736  /* 1 ch  , RSL      , 2-11.8 Vll, 2-115 VRef, 47-440Hz, 1.2 VA */
#define MODULE_ID_77           0x3737  /* 1 ch  , RSL      , 2-28 Vll  , 2-115 VRef, 47-440Hz, 1.2 VA */
#define MODULE_ID_78           0x3738  /* 1 ch  , SYN      , 90 Vll    , 2-115 VRef, 47-440Hz, 1.2 VA */
#define MODULE_ID_79           0x3739  /* 1 ch  , RSL      , 90 Vll    , 2-115 VRef, 47-440Hz, 1.2 VA */
#define MODULE_ID_7A           0x3741  /* 1 ch  , RSL      , 2-11.8 Vll, 2-115 VRef, 1K-3KHz , 1.2 VA */
#define MODULE_ID_7B           0x3742  /* 1 ch  , RSL      , 2-11.8 Vll, 2-115 VRef, 3K-5KHz , 1.2 VA */
#define MODULE_ID_7C           0x3743  /* 1 ch  , RSL      , 2-11.8 Vll, 2-115 VRef, 5K-7KHz , 1.2 VA */
#define MODULE_ID_7D           0x3744  /* 1 ch  , RSL      , 2-11.8 Vll, 2-115 VRef, 7K-10KHz, 1.2 VA */
#define MODULE_ID_7E           0x3745  /* 1 ch  , RSL      , 2-28 Vll  , 2-115 VRef, 1K-3KHz , 1.2 VA */
#define MODULE_ID_7F           0x3746  /* 1 ch  , RSL      , 2-28 Vll  , 2-115 VRef, 3K-5KHz , 1.2 VA */
#define MODULE_ID_7G           0x3747  /* 1 ch  , RSL      , 2-28 Vll  , 2-115 VRef, 5K-7KHz , 1.2 VA */
#define MODULE_ID_7H           0x3748  /* 1 ch  , RSL      , 2-28 Vll  , 2-115 VRef, 7K-10KHz, 1.2 VA */

/* SIG Module */
#define MODULE_ID_E1           0x4531
#define MODULE_ID_E2           0x4532
#define MODULE_ID_ES           0x4553

/* REF Module */
#define MODULE_ID_W0           0x5730
#define MODULE_ID_W1           0x5731
#define MODULE_ID_W2           0x5732
#define MODULE_ID_W3           0x5733
#define MODULE_ID_W6           0x5736
#define MODULE_ID_W7           0x5737

/* Serial Module */
#define MODULE_ID_P8           0x5038  /* 4-channel serial module */

/* USB Module */
#define MODULE_ID_P9           0x5039  /* 6-channel USB module */

/* CAN Module */
#define MODULE_ID_P6           0x5036
#define MODULE_ID_PA           0x5041  /* with J1939 */

/* ARINC-429 Module */
#define MODULE_ID_A4           0x4134  /* 6-channel ARINC-429 module */

/* 1553 Module */
#define MODULE_ID_N7           0x4E37  /* 2-channel 1553 module */
#define MODULE_ID_N8           0x4E38  /* 2-channel 1553 module */
#define MODULE_ID_NA           0x4E41  /* 2-channel 1553 module */
#define MODULE_ID_NB           0x4E42  /* 2-channel 1553 module */

/* Multifunction Module */
#define MODULE_ID_Y2           0x5932  /* Y2 module is associated with 60KA */
#define MODULE_ID_KA           0x4B41

/* CPCI75C3 Special Code Spec Numbers */
#define NO_SPECIAL_SPEC        0x2020

/*
 * Since this library was designed to be re-entrant and to be 
 * use with multiple boards we define a context structure that
 * is passed as a parameter to each function.
 */

#ifndef WIN32 /* not WIN32, but VxWorks, Linux or LynxOS cases */
#define SOCKET int
#endif

typedef struct {
   unsigned long    BaseAddress;       /* Base Address for VxWorks */
   CPCI75C3_STATUS  LastStatus;        /* Saved Last Status */
   unsigned int     Card;              /* Card ID */
   int              Im;                /* Interface Mode */
   int              IsOpen;            /* Indicates if the Card handle has been opened. */
   SOCKET           Sfd;               /* Ethernet Socket File Descriptor */
   int             InUse;     
   HANDLE           Handle;            /* PCI/CPCI Windows access handle */
}   CPCI75C3_CTX, *PCPCI75C3_CTX;

/* Structure for mixed channel-type modules (CA,CX,...) */
typedef struct _CPCI75C3_ModuleDefItem
{
    unsigned short  usModuleNumber;
    unsigned short  usModuleType;
    unsigned short  ausChannelType[CPCI75C3_AD_MAX_CHAN];
    struct _CPCI75C3_ModuleDefItem  *pNextItem;
} CPCI75C3_ModuleDefItem;

/*
 *       External Variables.
 */
extern const double CPCI75C3_VERSION;
extern int CPCI75C3_ModuleType[CPCI75C3_MAX_CARD][CPCI75C3_MAX_MODULE];
extern unsigned short CPCI75C3_ModuleID[CPCI75C3_MAX_CARD][CPCI75C3_MAX_MODULE];
extern int CPCI75C3_ModuleAddr[CPCI75C3_MAX_MODULE];
extern int CPCI75C3_isThreeChanDLV[CPCI75C3_MAX_CARD][CPCI75C3_MAX_MODULE];
extern int CPCI75C3_DtMaxChan[CPCI75C3_MAX_CARD][CPCI75C3_MAX_MODULE];

/* Keeps track of the number of DSP modules on the 75C3.  Note, in the
   initial release of the 75C3 product line, the design supported 2 DSP
   modules.  The new product line supports 3 DSP modules.
   The API calls must support both product line configurations.
*/
extern int CPCI75C3_IsY2Y2orKA[CPCI75C3_MAX_CARD];

/*
 *        Register Maps.
 * Module Level Register Offsets calculated as:  
 *   Module Base Offset + REG Offset
 */


/* Each module has these registers */
#define CPCI75C3_REG_MOD_DES_VER                                      (0x03B4 << ADDR_SHIFT)
#define CPCI75C3_REG_MOD_DES_REV                                      (0x03B6 << ADDR_SHIFT)
#define CPCI75C3_REG_MOD_DSP_REV                                      (0x03B8 << ADDR_SHIFT)
#define CPCI75C3_REG_MOD_FPGA1_REV                                    (0x03BA << ADDR_SHIFT)
#define CPCI75C3_REG_MODULE_ID                                        (0x03BC << ADDR_SHIFT)
#define CPCI75C3_REG_SPECIAL_REV                                      (0x03BE << ADDR_SHIFT) /*Designation for special version of module*/
#define CPCI75C3_REG_COMPILE_TIME                                     (0x0390 << ADDR_SHIFT)

/* Board Level Registers */
#define CPCI75C3_REG_PART_NUMBER                                      (0x1800 << ADDR_SHIFT)
#define CPCI75C3_REG_SERIAL_NUMBER                                    (0x1802 << ADDR_SHIFT)
#define CPCI75C3_REG_DATE_CODE                                        (0x1804 << ADDR_SHIFT)
#define CPCI75C3_REG_REV_PCB                                          (0x1806 << ADDR_SHIFT)
#define CPCI75C3_REG_REV_PROCESSOR_1                                  (0x1808 << ADDR_SHIFT)
#define CPCI75C3_REG_REV_PCI_FPGA                                     (0x180A << ADDR_SHIFT)

#define CPCI75C3_REG_BOARD_READY                                      (0x180C << ADDR_SHIFT)
#define CPCI75C3_REG_WATCHDOG                                         (0x180E << ADDR_SHIFT)
#define CPCI75C3_REG_SOFTWARE_RESET                                   (0x1810 << ADDR_SHIFT)

#define CPCI75C3_DES_VER                                              (0x1818 << ADDR_SHIFT)

/* Card Name */
#define CPCI75C3_REG_PLATFORM                                         (0x181A << ADDR_SHIFT)
#define CPCI75C3_REG_MODEL                                            (0x181C << ADDR_SHIFT)
#define CPCI75C3_REG_GENERATION                                       (0x181E << ADDR_SHIFT)
#define CPCI75C3_REG_SPEC                                             (0x1820 << ADDR_SHIFT)

#define CPCI75C3_REG_INT_PRIORTY_LEVEL                                (0x1822 << ADDR_SHIFT)

/* For PCI/CPCI card only - Interrupt Handling */
#define CPCI75C3_REG_IRQ_STAT                                         (0x1A00 << ADDR_SHIFT)
#define CPCI75C3_REG_IRQ_CLEAR                                        (0x1A02 << ADDR_SHIFT)
#define CPCI75C3_REG_IRQ_VEC                                          (0x1A04 << ADDR_SHIFT)
/* End For PCI/CPCI card only - Interrupt Handling */

#define CPCI75C3_REG_IP_HI                                            (0x1824 << ADDR_SHIFT)
#define CPCI75C3_REG_IP_LO                                            (0x1826 << ADDR_SHIFT)

#define CPCI75C3_REG_SNET_MASK_HI                                     (0x1828 << ADDR_SHIFT)
#define CPCI75C3_REG_SNET_MASK_LO                                     (0x182A << ADDR_SHIFT)

#define CPCI75C3_REG_SNET_HI                                          (0x182C << ADDR_SHIFT)
#define CPCI75C3_REG_SNET_LO                                          (0x182E << ADDR_SHIFT)

#define CPCI75C3_REG_MAC_HI                                           (0x1830 << ADDR_SHIFT)
#define CPCI75C3_REG_MAC_MID                                          (0x1832 << ADDR_SHIFT)
#define CPCI75C3_REG_MAC_LO                                           (0x1834 << ADDR_SHIFT)

#define CPCI75C3_REG_TELNET_STATUS                                    (0x1836 << ADDR_SHIFT)
#define CPCI75C3_REG_MAC_STATUS                                       (0x1838 << ADDR_SHIFT)

/* The last register. For bounds checking. */
#define CPCI75C3_REG_LAST                                             CPCI75C3_REG_MAC_STATUS

/* Internal use. Do not publish */
#define CPCI75C3_REG_CAL_OFF                                          (0x0656 << ADDR_SHIFT)

/*
 * The CPCI75C3 board has Nine registers that can be read to
 * determine information about the hardware build and firmware.
 * We combine them into this structure. 
 */

typedef struct {
  unsigned short PartNumber;
  unsigned short SerialNumber;
  unsigned short DateCode;
  unsigned short PcbRev;
  unsigned short DspRev;
  unsigned short Dsp1Rev;
  unsigned short Dsp2Rev;
  unsigned short Dsp3Rev;
  unsigned short FpgaRev;
  unsigned short Fpga1Rev;
  unsigned short Fpga2Rev;
  unsigned short Fpga3Rev;
} CPCI75C3_CARD_INFO, *PCPCI75C3_CARD_INFO;


/* Some API functions use an enabled/disabled parameter. */
#define CPCI75C3_DISABLED                    0
#define CPCI75C3_ENABLED                     1

/* Some API functions use an Pass/Fail parameter. */
#define CPCI75C3_PASS                        0
#define CPCI75C3_FAIL                        1

/* Some API functions use an active/inactive parameter. */
#define CPCI75C3_INACTIVE                    0
#define CPCI75C3_ACTIVE                      1

/* Some API functions use a valid/invalid parameter. */
#define CPCI75C3_INVALID                     0
#define CPCI75C3_VALID                       1

#define CPCI75C3_STATUS_GOOD                 0
#define CPCI75C3_STATUS_BAD                  1

/* Some functions use a Pullup Pulldown parameter. */
#define CPCI75C3_PullDown                    0
#define CPCI75C3_PullUp                      1

/* Some API functions use a Input/Output format parameter. */
#define CPCI75C3_Input                       0
#define CPCI75C3_Output_LowSide_Switched     1
#define CPCI75C3_Output_HighSide_Switched    2
#define CPCI75C3_Output_Push_Pull            3

/* Some API functions use a Input/Output state parameter. */
#define CPCI75C3_Logic_Low                   0
#define CPCI75C3_Logic_High                  1

/* Number of bank on each DT Module for source/sink current. */
#define CPCI75C3_DT_MAX_BANK                 4
/* Number of channels per bank on DT Module for source/sink current. */
#define CPCI75C3_DT_CHAN_PER_BANK            4

#define CPCI75C3_LATCH_CMD                   2

/* Some API functions use an Encoder/Commutation parameter. */
#define CPCI75C3_ENCODER                     0
#define CPCI75C3_COMMUTATION                 1

/***********************************/
/******   Exported Functions  ******/
/***********************************/

/******   Device Control   ******/
_75C3FUNC int CPCI75C3_Open(int Card);
_75C3FUNC int CPCI75C3_Close(int Card);

#ifndef __ADSPBLACKFIN__
/******   Device Controls based on Physical Board Location   ******/
_75C3FUNC void CPCI75C3_Init(void);
_75C3FUNC int CPCI75C3_GetDevCnt(void);
_75C3FUNC int CPCI75C3_GetCardbyBusDev(unsigned int Bus, unsigned int Dev);
_75C3FUNC int CPCI75C3_OpenWithBusDev(unsigned int Bus, unsigned int Dev);
_75C3FUNC void CPCI75C3_GetBusDevInfoForCard(int Card, int *pDevID, int *pSlotNum, int *pBusNum, int *pDevNum, int *pFuncNum, int *pBaseAddr);

/******   Device Control for Ethernet Interface  ******/
_75C3FUNC int CPCI75C3_OpenWithInterfaceMode(int Card, int Mode, char* Ip, int Port);
_75C3FUNC int CPCI75C3_GetInterfaceMode(int Card, int* Mode, char* Ip, int* Port);
_75C3FUNC int CPCI75C3_SetCommMode(int Card, int Mode, char* Ip, int Port);
_75C3FUNC int CPCI75C3_GetCommMode(int Card, int* Mode);

/******   Multiple Board Controlled by One Ethernet Connection  ******/
_75C3FUNC int CPCI75C3_GetClientEthernetSocket(int Card, int *Socket);
_75C3FUNC int CPCI75C3_GetClientEthernetUDPServerAddr(int Card, struct nai_sockaddr_storage *ServerAddr);
_75C3FUNC int CPCI75C3_OpenWithEthernetTCPSocket(int Card, int Mode, char* Ip, int Port, int Socket);
_75C3FUNC int CPCI75C3_OpenWithEthernetUDPSocket(int Card, int Mode, char* Ip, int Port, int Socket, struct nai_sockaddr_storage ServerAddr);
#endif

/******   Board Level Functions   ******/
_75C3FUNC int CPCI75C3_SetDUTAddress(int Card, int DUTAddress);
_75C3FUNC int CPCI75C3_GetDUTAddress(int Card, int *DUTAddress);
_75C3FUNC int CPCI75C3_GetModuleBaseAddress(int Card, int Module, unsigned int *unModAddress);
_75C3FUNC int CPCI75C3_SetRegister(int Card, int Offset, int Data);
_75C3FUNC int CPCI75C3_GetRegister( int Card, int Offset);
_75C3FUNC int CPCI75C3_GetRegisterEx( int Card, int Offset, int *Data);
_75C3FUNC int CPCI75C3_SetMRegister(int Card, int Module, int Offset, int Data);
_75C3FUNC int CPCI75C3_GetMRegister(int Card, int Module, int Offset);
_75C3FUNC int CPCI75C3_GetMRegisterEx(int Card, int Module, int Offset, int *Data);
_75C3FUNC int CPCI75C3_ReadRegisterMultiple(int Card, int RegAddrs, unsigned short *DataBlock, int WordCount);
_75C3FUNC int CPCI75C3_WriteRegisterMultiple(int Card, int RegAddrs, unsigned short *DataBlock, int WordCount);
_75C3FUNC int CPCI75C3_WriteRegisterMultipleForUChar( int Card, int RegAddrs, unsigned char *DataBlock, int WordCount);
_75C3FUNC int CPCI75C3_ReadRegisterBlock(int Card, int RegAddrs, unsigned short *DataBlock, int WordCount);
_75C3FUNC int CPCI75C3_WriteRegisterBlock(int Card, int RegAddrs, unsigned short *DataBlock, int WordCount);

_75C3FUNC int CPCI75C3_GetBoardReady(int Card, unsigned short *BoardReady);
_75C3FUNC int CPCI75C3_GetDevID(int Card, unsigned int *DevID);
_75C3FUNC int CPCI75C3_GetCardInfo(int Card, PCPCI75C3_CARD_INFO CardInfo);
_75C3FUNC int CPCI75C3_GetDesignVersion(int Card, int *DesVer);
_75C3FUNC int CPCI75C3_GetDsp1Rev(int Card, int *Num);
_75C3FUNC int CPCI75C3_GetInterfaceFpgaRev(int Card, int *Num);
_75C3FUNC int CPCI75C3_GetPcbRev(int Card, int *Num);
_75C3FUNC int CPCI75C3_GetModuleDesignVer(int Card, int Module, unsigned short *DesignVer);
_75C3FUNC int CPCI75C3_GetModuleDesignRev(int Card, int Module, unsigned short *DesignRev);
_75C3FUNC int CPCI75C3_GetModuleDSPRev(int Card, int Module, unsigned short *DSPRev);
_75C3FUNC int CPCI75C3_GetModuleFPGA1Rev(int Card, int Module, unsigned short *FPGA1Rev);
_75C3FUNC int CPCI75C3_GetModuleID(int Card, int Module, unsigned short *ModuleID); 
_75C3FUNC int CPCI75C3_GetModuleType(int Card, int Module, int *ModType);
_75C3FUNC int CPCI75C3_GetModuleTypeAll(int Card);
_75C3FUNC int CPCI75C3_SoftwareReset(int Card);
_75C3FUNC int CPCI75C3_GetPartNumber(int Card, int *Num);
_75C3FUNC int CPCI75C3_GetSerialNumber(int Card, int *Num);
_75C3FUNC int CPCI75C3_GetDateCode(int Card, int *Num);
_75C3FUNC int CPCI75C3_GetSpecialSpec(int Card, unsigned short *Spec);
_75C3FUNC int CPCI75C3_GetModuleSpecRev(int Card, int Module, unsigned short *SpecRev);

/******  Board Level Test Modes  ******/
_75C3FUNC int CPCI75C3_SetWatchdog(int Card, unsigned short Watchdog);
_75C3FUNC int CPCI75C3_GetWatchdog(int Card, unsigned short *Watchdog);
_75C3FUNC int CPCI75C3_CheckWatchdog(int Card, unsigned short Watchdog);

/******   Software Control   ******/
/* Note the CPCI75C3_GetLastStatus() function is no longer supported. Status is returned as the
   return parameter for API functions in this SSK.
*/
_75C3FUNC int CPCI75C3_GetLastStatus(void);
_75C3FUNC int CPCI75C3_GetVersion(double *Version);
_75C3FUNC char* CPCI75C3_StatusString(int Status);

/******   Interrupt Control   ******/
_75C3FUNC int CPCI75C3_InterruptHook(int Card, void(*IntRoutine)(HANDLE hDevice, USHORT IntStatus));
_75C3FUNC int CPCI75C3_GetInterruptVectorInIrq(int Card, unsigned int *InterruptVector);

/*
  Note: Interrupt Levels pertain only to VME products. For non-VME products this
  register value has no effect on the interrupt operation.
*/
_75C3FUNC int CPCI75C3_GetInterruptLevel( int Card, int *InterruptLevel );
_75C3FUNC int CPCI75C3_SetInterruptLevel( int Card, int  InterruptLevel );


#ifndef __ADSPBLACKFIN__
/******   Ethernet Synchronization Functions   ******/
_75C3FUNC void CPCI75C3_Ether_ResetBusy_TCP(void);
_75C3FUNC void CPCI75C3_Ether_ResetBusy_UDP(void);
_75C3FUNC void CPCI75C3_Ether_WaitOnBusy(BOOL bWaitOnBusy);
_75C3FUNC int  CPCI75C3_EtherSetMsWait(int milliseconds);
_75C3FUNC int  CPCI75C3_EtherGetMsWait(void);

/******   Ethernet FIFO Functions   ******/
_75C3FUNC int  CPCI75C3_EtherReadFifo(int Card, unsigned int FifoDataAddr, unsigned int FifoCountAddr, int maxCount, unsigned short *DataBlock, int *countReceived, int *countLeft);
#endif

/*           INTERNAL USE ONLY                       */
void Allocate75C3CTXStructure(int Card);
void Free75C3CTXStructure(int Card);
PCPCI75C3_CTX CPCI75C3_GetCtxStructure(int Card);

int CPCI75C3_READREG_EX(int Card, int RegAddrs, unsigned short *Data);
unsigned short CPCI75C3_READREG(int Card, unsigned int RegAddrs);
int CPCI75C3_WRITEREG(int Card, unsigned int RegAddrs, unsigned short Data);
int CPCI75C3_READREG_MULTIPLE(int Card, int RegAddrs, unsigned short *DataBlock, int WordCount);
int CPCI75C3_READREG_MULTIPLE_MATCH( int Card, int RegAddrs, int RegAddrsCount, unsigned short *DataBlock, unsigned short LastWord, int MaxWordCount, BOOL bMask, int *CountReceived, int TimeoutMs );
int CPCI75C3_WRITEREG_MULTIPLE(int Card, int RegAddrs, unsigned short *DataBlock, int WordCount);
int CPCI75C3_WRITEREG_MULTIPLE_FOR_UCHAR(int Card, int RegAddrs, unsigned char *DataBlock, int WordCount);
int CPCI75C3_READREG_BLOCK(int Card, unsigned int RegAddrs, unsigned short *DataBlock, int WordCount);
int CPCI75C3_WRITEREG_BLOCK(int Card, unsigned int RegAddrs, unsigned short *DataBlock, int WordCount);
int CPCI75C3_CheckBoardReady(int Card);
int CPCI75C3_LibInit(void);
int CPCI75C3_AddItemToModuleDefList(int Card, int Module, unsigned short modID);
CPCI75C3_ModuleDefItem* CPCI75C3_GetModuleDefItem(int iCard, int iModule);

/* When sending 32-bit address Ethernet messages to registers on-board
   the address must be in VME address and or'ed with the ONBOARD_ACCESS_MASK value.
   The CPCI75C3_getOnBoardRegister() routine will adjust the RegAddrs value so that the address
   is the equivalent VME address.
*/
int CPCI75C3_getOnBoardRegister( int RegAddrs );


/* Internal Device Control */
#ifndef __ADSPBLACKFIN__
int CPCI75C3_Open_Ether(int Card, char* Ip, int Port);
int CPCI75C3_Open_Ether_UDP(int Card, char* Ip, int Port);
int CPCI75C3_Open_Pci(int Card);
#ifdef VXWORKS
int CPCI75C3_Open_PciVxWorks(int Card);
#endif

_75C3FUNC int CPCI75C3_SetCalOn(int Card);
_75C3FUNC int CPCI75C3_SetCalOff(int Card);
#endif

void CPCI75C3_Init(void);
_75C3FUNC void CPCI75C3_WaitUs(int microseconds);


#ifdef __cplusplus
}
#endif

#endif
