/*+++

Copyright (c) 2008 North Atlantic Industries,

File Name:

 CPCI75C3_DT.h

Description:

 Include file to the CPCI75C3 - Discrete I/O Interface.
 This file includes the API interfaces for the K6(16-channel) and 
 special KA(28-channel) Discrete IO Modules.
 The channel assignment for the KA module is as follows:
 Chan 1-12   Output Channels
 Chan 13-16  I/O Channels
 Chan 17-28  Inputs Channels

 This was written in ANSI 'C' for 32-bit integers.

Author: 
Date:  
History:

---*/

#ifndef _CPCI75C3_DT_H
#define _CPCI75C3_DT_H

#include "CPCI75C3_include.h"               

#ifdef __cplusplus
extern "C" {
#endif 

/************************/
/* DT Module Registers  */
/************************/
#define CPCI75C3_REG_DT_WRITE_OUTPUT                                  (0x000 << ADDR_SHIFT)
#define CPCI75C3_REG_DT_READ_IO                                       (0x002 << ADDR_SHIFT)

#define CPCI75C3_REG_DT_MAX_HIGH_THRESHOLD_ADD {\
 (0x004 << ADDR_SHIFT), (0x00E << ADDR_SHIFT), (0x018 << ADDR_SHIFT), (0x022 << ADDR_SHIFT),\
 (0x02C << ADDR_SHIFT), (0x036 << ADDR_SHIFT), (0x040 << ADDR_SHIFT), (0x04A << ADDR_SHIFT),\
 (0x054 << ADDR_SHIFT), (0x05E << ADDR_SHIFT), (0x068 << ADDR_SHIFT), (0x072 << ADDR_SHIFT),\
 (0x07C << ADDR_SHIFT), (0x086 << ADDR_SHIFT), (0x090 << ADDR_SHIFT), (0x09A << ADDR_SHIFT) \
}

#define CPCI75C3_REG_DT_UPPER_THRESHOLD_ADD {\
 (0x006 << ADDR_SHIFT), (0x010 << ADDR_SHIFT), (0x01A << ADDR_SHIFT), (0x024 << ADDR_SHIFT),\
 (0x02E << ADDR_SHIFT), (0x038 << ADDR_SHIFT), (0x042 << ADDR_SHIFT), (0x04C << ADDR_SHIFT),\
 (0x056 << ADDR_SHIFT), (0x060 << ADDR_SHIFT), (0x06A << ADDR_SHIFT), (0x074 << ADDR_SHIFT),\
 (0x07E << ADDR_SHIFT), (0x088 << ADDR_SHIFT), (0x092 << ADDR_SHIFT), (0x09C << ADDR_SHIFT) \
}

#define CPCI75C3_REG_DT_LOWER_THRESHOLD_ADD {\
 (0x008 << ADDR_SHIFT), (0x012 << ADDR_SHIFT), (0x01C << ADDR_SHIFT), (0x026 << ADDR_SHIFT),\
 (0x030 << ADDR_SHIFT), (0x03A << ADDR_SHIFT), (0x044 << ADDR_SHIFT), (0x04E << ADDR_SHIFT),\
 (0x058 << ADDR_SHIFT), (0x062 << ADDR_SHIFT), (0x06C << ADDR_SHIFT), (0x076 << ADDR_SHIFT),\
 (0x080 << ADDR_SHIFT), (0x08A << ADDR_SHIFT), (0x094 << ADDR_SHIFT), (0x09E << ADDR_SHIFT) \
}

#define CPCI75C3_REG_DT_MIN_LOW_THRESHOLD_ADD {\
 (0x00A << ADDR_SHIFT), (0x014 << ADDR_SHIFT), (0x01E << ADDR_SHIFT), (0x028 << ADDR_SHIFT),\
 (0x032 << ADDR_SHIFT), (0x03C << ADDR_SHIFT), (0x046 << ADDR_SHIFT), (0x050 << ADDR_SHIFT),\
 (0x05A << ADDR_SHIFT), (0x064 << ADDR_SHIFT), (0x06E << ADDR_SHIFT), (0x078 << ADDR_SHIFT),\
 (0x082 << ADDR_SHIFT), (0x08C << ADDR_SHIFT), (0x096 << ADDR_SHIFT), (0x0A0 << ADDR_SHIFT) \
}

#define CPCI75C3_REG_DT_DEBOUNCE_TIME_ADD {\
 (0x00C << ADDR_SHIFT), (0x016 << ADDR_SHIFT), (0x020 << ADDR_SHIFT), (0x02A << ADDR_SHIFT),\
 (0x034 << ADDR_SHIFT), (0x03E << ADDR_SHIFT), (0x048 << ADDR_SHIFT), (0x052 << ADDR_SHIFT),\
 (0x05C << ADDR_SHIFT), (0x066 << ADDR_SHIFT), (0x070 << ADDR_SHIFT), (0x07A << ADDR_SHIFT),\
 (0x084 << ADDR_SHIFT), (0x08E << ADDR_SHIFT), (0x098 << ADDR_SHIFT), (0x0A2 << ADDR_SHIFT) \
}

#define CPCI75C3_REG_DT_KA_PWM_TIMER_PERIOD_ADD {\
 (0x040 << CPCI75C3_ADDR_SHIFT), (0x042 << CPCI75C3_ADDR_SHIFT), (0x044 << CPCI75C3_ADDR_SHIFT), (0x046 << CPCI75C3_ADDR_SHIFT),\
 (0x048 << CPCI75C3_ADDR_SHIFT), (0x04A << CPCI75C3_ADDR_SHIFT), (0x04C << CPCI75C3_ADDR_SHIFT), (0x04E << CPCI75C3_ADDR_SHIFT),\
 (0x050 << CPCI75C3_ADDR_SHIFT), (0x052 << CPCI75C3_ADDR_SHIFT), (0x054 << CPCI75C3_ADDR_SHIFT), (0x056 << CPCI75C3_ADDR_SHIFT),\
 (0x058 << CPCI75C3_ADDR_SHIFT), (0x05A << CPCI75C3_ADDR_SHIFT), (0x05C << CPCI75C3_ADDR_SHIFT), (0x05E << CPCI75C3_ADDR_SHIFT)\
}

#define CPCI75C3_REG_DT_KA_PWM_TIMER_PULSE_WIDTH_ADD {\
 (0x060 << CPCI75C3_ADDR_SHIFT), (0x062 << CPCI75C3_ADDR_SHIFT), (0x064 << CPCI75C3_ADDR_SHIFT), (0x066 << CPCI75C3_ADDR_SHIFT),\
 (0x068 << CPCI75C3_ADDR_SHIFT), (0x06A << CPCI75C3_ADDR_SHIFT), (0x06C << CPCI75C3_ADDR_SHIFT), (0x06E << CPCI75C3_ADDR_SHIFT),\
 (0x070 << CPCI75C3_ADDR_SHIFT), (0x072 << CPCI75C3_ADDR_SHIFT), (0x074 << CPCI75C3_ADDR_SHIFT), (0x076 << CPCI75C3_ADDR_SHIFT),\
 (0x078 << CPCI75C3_ADDR_SHIFT), (0x07A << CPCI75C3_ADDR_SHIFT), (0x07C << CPCI75C3_ADDR_SHIFT), (0x07E << CPCI75C3_ADDR_SHIFT)\
}

#define CPCI75C3_REG_DT_KA_PWM_TIMER_POLARITY_ADD {\
 (0x080 << CPCI75C3_ADDR_SHIFT), (0x082 << CPCI75C3_ADDR_SHIFT), (0x084 << CPCI75C3_ADDR_SHIFT), (0x086 << CPCI75C3_ADDR_SHIFT),\
 (0x088 << CPCI75C3_ADDR_SHIFT), (0x08A << CPCI75C3_ADDR_SHIFT), (0x08C << CPCI75C3_ADDR_SHIFT), (0x08E << CPCI75C3_ADDR_SHIFT),\
 (0x090 << CPCI75C3_ADDR_SHIFT), (0x092 << CPCI75C3_ADDR_SHIFT), (0x094 << CPCI75C3_ADDR_SHIFT), (0x096 << CPCI75C3_ADDR_SHIFT),\
 (0x098 << CPCI75C3_ADDR_SHIFT), (0x09A << CPCI75C3_ADDR_SHIFT), (0x09C << CPCI75C3_ADDR_SHIFT), (0x09E << CPCI75C3_ADDR_SHIFT)\
}

#define CPCI75C3_REG_DT_KA_PWM_TIMER_MODE_SEL_ADD                    (0x0E0 << CPCI75C3_ADDR_SHIFT)
#define CPCI75C3_REG_DT_KA_PWM_TIMER_MODE_ENABLE_ADD                 (0x0E2 << CPCI75C3_ADDR_SHIFT)


#define CPCI75C3_REG_DT_INPUT_OUTPUT_FORMAT_ADD {\
 (0x0A4 << ADDR_SHIFT), (0x0A6 << ADDR_SHIFT)\
}

#define CPCI75C3_REG_DT_SOURCE_SINK_CURRENT_ADD {\
 (0x0A8 << ADDR_SHIFT), (0x0AA << ADDR_SHIFT), (0x0AC << ADDR_SHIFT), (0x0AE << ADDR_SHIFT)\
}

#define CPCI75C3_REG_DT_PULL_UP_DOWN_CONFIG                           (0x0B0 << ADDR_SHIFT)
#define CPCI75C3_REG_DT_CURRENT_SHARE_CONFIG                          (0x0B2 << ADDR_SHIFT)

#define CPCI75C3_REG_DT_VCC_VALUE_ADD {\
 (0x0B4 << ADDR_SHIFT), (0x0B6 << ADDR_SHIFT), (0x0B8 << ADDR_SHIFT),(0x0BA << ADDR_SHIFT)\
}

#define CPCI75C3_REG_DT_RESET_OVER_CURRENT                            (0x0BC << ADDR_SHIFT)

/*Register offsets for current measurement cal factors, new K6- used for updating calibration factors for channel current measurements*/
#define CPCI75C3_REG_DT_CURRENT_CAL_CHANNEL                           (0x180 << ADDR_SHIFT)
#define CPCI75C3_REG_DT_CURRENT_CAL_OFFSET                            (0x182 << ADDR_SHIFT)
#define CPCI75C3_REG_DT_CURRENT_CAL_SOURCEGAIN                        (0x184 << ADDR_SHIFT) /*For source drive gain cal factor*/
#define CPCI75C3_REG_DT_CURRENT_CAL_SINKGAIN                          (0x186 << ADDR_SHIFT) /*For sink  drive gain cal factor*/
/*Register offsets for voltage measurement cal factors, new K6- used for updating calibration factors for channel voltage measurements*/
#define CPCI75C3_REG_DT_VOLTAGE_CAL_CHANNEL                           (0x3A8 << ADDR_SHIFT)
#define CPCI75C3_REG_DT_VOLTAGE_CAL_OFFSET                            (0x3AE << ADDR_SHIFT)
#define CPCI75C3_REG_DT_VOLTAGE_CAL_GAIN                              (0x3B2 << ADDR_SHIFT)/*For gain cal factor*/

/*Register offsets for new K6- These registers will be the input voltage measurements*/
#define CPCI75C3_REG_DT_VOLTAGERDG_ADD {\
 (0x140 << ADDR_SHIFT), (0x142 << ADDR_SHIFT), (0x144 << ADDR_SHIFT), (0x146 << ADDR_SHIFT),\
 (0x148 << ADDR_SHIFT), (0x14A << ADDR_SHIFT), (0x14C << ADDR_SHIFT), (0x14E << ADDR_SHIFT),\
 (0x150 << ADDR_SHIFT), (0x152 << ADDR_SHIFT), (0x154 << ADDR_SHIFT), (0x156 << ADDR_SHIFT),\
 (0x158 << ADDR_SHIFT), (0x15A << ADDR_SHIFT), (0x15C << ADDR_SHIFT), (0x15E << ADDR_SHIFT) \
}

/*Register offsets for new K6- These registers will be the output current measurements*/
#define CPCI75C3_REG_DT_CURRENTRDG_ADD {\
 (0x160 << ADDR_SHIFT), (0x162 << ADDR_SHIFT), (0x164 << ADDR_SHIFT), (0x166 << ADDR_SHIFT),\
 (0x168 << ADDR_SHIFT), (0x16A << ADDR_SHIFT), (0x16C << ADDR_SHIFT), (0x16E << ADDR_SHIFT),\
 (0x170 << ADDR_SHIFT), (0x172 << ADDR_SHIFT), (0x174 << ADDR_SHIFT), (0x176 << ADDR_SHIFT),\
 (0x178 << ADDR_SHIFT), (0x17A << ADDR_SHIFT), (0x17C << ADDR_SHIFT), (0x17E << ADDR_SHIFT) \
}

#define CPCI75C3_REG_DT_BIT_STATUS                                    (0x0D0 << ADDR_SHIFT)

#define CPCI75C3_REG_DT_OVER_CURRENT_STATUS                           (0x0D4 << ADDR_SHIFT)
#define CPCI75C3_REG_DT_MAX_HI_THRESHOLD_STATUS                       (0x0D6 << ADDR_SHIFT)
#define CPCI75C3_REG_DT_MIN_LOW_THRESHOLD_STATUS                      (0x0D8 << ADDR_SHIFT)
#define CPCI75C3_REG_DT_MID_RANGE_FAULT_STATUS                        (0x0DA << ADDR_SHIFT)
#define CPCI75C3_REG_DT_LOW_HI_TRANSITION_STATUS                      (0x0DC << ADDR_SHIFT)
#define CPCI75C3_REG_DT_HI_LOW_TRANSITION_STATUS                      (0x0DE << ADDR_SHIFT)

#define CPCI75C3_REG_DT_BIT_INT_ENAB                                  (0x0E8 << ADDR_SHIFT)

#define CPCI75C3_REG_DT_OVER_CURRENT_INT_ENAB                         (0x0EC << ADDR_SHIFT)
#define CPCI75C3_REG_DT_MAX_HI_THRESHOLD_INT_ENAB                     (0x0EE << ADDR_SHIFT)
#define CPCI75C3_REG_DT_MIN_LOW_THRESHOLD_INT_ENAB                    (0x0F0 << ADDR_SHIFT)
#define CPCI75C3_REG_DT_MID_RANGE_FAULT_INT_ENAB                      (0x0F2 << ADDR_SHIFT)
#define CPCI75C3_REG_DT_LOW_HI_TRANSITION_INT_ENAB                    (0x0F4 << ADDR_SHIFT)
#define CPCI75C3_REG_DT_HI_LOW_TRANSITION_INT_ENAB                    (0x0F6 << ADDR_SHIFT)

#define CPCI75C3_REG_DT_INT_VECTOR_BIT                                (0x3E0 << ADDR_SHIFT)
#define CPCI75C3_REG_DT_INT_VECTOR_MAX_HI_THRESHOLD                   (0x3E2 << ADDR_SHIFT)
#define CPCI75C3_REG_DT_INT_VECTOR_MIN_LOW_THRESHOLD                  (0x3E4 << ADDR_SHIFT)
#define CPCI75C3_REG_DT_INT_VECTOR_MID_RANGE_THRESHOLD                (0x3E6 << ADDR_SHIFT)
#define CPCI75C3_REG_DT_INT_VECTOR_OVERCURRENT                        (0x3C2 << ADDR_SHIFT)
#define CPCI75C3_REG_DT_INT_VECTOR_LOW_HI_TRANSITION                  (0x3C4 << ADDR_SHIFT)
#define CPCI75C3_REG_DT_INT_VECTOR_HI_LOW_TRANSITION                  (0x3C6 << ADDR_SHIFT)

#define CPCI75C3_DT_DESIGN_VERSION                                    (0x3B4 << ADDR_SHIFT)
#define CPCI75C3_DT_DESIGN_REVISION                                   (0x3B6 << ADDR_SHIFT)

/*Note: registers below are for modules currently in development; not listed in user memory map */
#define CPCI75C3_DT_CURRENT_CHANNEL_REGISTER                          (0x168 << ADDR_SHIFT)
#define CPCI75C3_DT_CURRENTGAIN_LO_SIDE_CAL_FACTOR                    (0x16A << ADDR_SHIFT)
#define CPCI75C3_DT_CURRENTGAIN_HI_SIDE_CAL_FACTOR                    (0x16C << ADDR_SHIFT)
#define CPCI75C3_DT_CURRENT_READ_REGISTER                             (0x16E << ADDR_SHIFT)                   

/************************************************/
/* DT Module Registers (specific to KA module)  */
/*   PCI addressing only; ADDR_SHIFT not used   */
/************************************************/

#define CPCI75C3_REG_DT_KA_WRITE_OUTPUT_CHAN                          0x440
#define CPCI75C3_REG_DT_KA_READ_OUTPUT_CHAN                           0x444
#define CPCI75C3_REG_DT_KA_READ_INPUT_CHAN                            0x448

#define CPCI75C3_REG_DT_KA_MAX_HIGH_THRESHOLD_ADD {\
 0x458, 0x46C, 0x480, 0x494, 0x4A8, 0x4BC, 0x4D0, 0x4E4,\
 0x4F8, 0x50C, 0x520, 0x534, 0x548, 0x55C, 0x570, 0x584,\
 0x598, 0x5AC, 0x5C0, 0x5D4, 0x5E8, 0x5FC, 0x610, 0x624,\
 0x638, 0x64C, 0x660, 0x674 \
}

#define CPCI75C3_REG_DT_KA_UPPER_THRESHOLD_ADD {\
 0x45C, 0x470, 0x484, 0x498, 0x4AC, 0x4C0, 0x4D4, 0x4E8,\
 0x4FC, 0x510, 0x524, 0x538, 0x54C, 0x560, 0x574, 0x588,\
 0x59C, 0x5B0, 0x5C4, 0x5D8, 0x5EC, 0x600, 0x614, 0x628,\
 0x63C, 0x650, 0x664, 0x678 \
}

#define CPCI75C3_REG_DT_KA_LOWER_THRESHOLD_ADD {\
 0x460, 0x474, 0x488, 0x49C, 0x4B0, 0x4C4, 0x4D8, 0x4EC,\
 0x500, 0x514, 0x528, 0x53C, 0x550, 0x564, 0x578, 0x58C,\
 0x5A0, 0x5B4, 0x5C8, 0x5DC, 0x5F0, 0x604, 0x618, 0x62C,\
 0x640, 0x654, 0x668, 0x67C \
}

#define CPCI75C3_REG_DT_KA_MIN_LOW_THRESHOLD_ADD {\
 0x464, 0x478, 0x48C, 0x4A0, 0x4B4, 0x4C8, 0x4DC, 0x4F0,\
 0x504, 0x518, 0x52C, 0x540, 0x554, 0x568, 0x57C, 0x590,\
 0x5A4, 0x5B8, 0x5CC, 0x5E0, 0x5F4, 0x608, 0x61C, 0x630,\
 0x644, 0x658, 0x66C, 0x680 \
}

#define CPCI75C3_REG_DT_KA_DEBOUNCE_TIME_ADD {\
 0x468, 0x47C, 0x490, 0x4A4, 0x4B8, 0x4CC, 0x4E0, 0x4F4,\
 0x508, 0x51C, 0x530, 0x544, 0x558, 0x56C, 0x580, 0x594,\
 0x5A8, 0x5BC, 0x5D0, 0x5E4, 0x5F8, 0x60C, 0x620, 0x634,\
 0x648, 0x65C, 0x670, 0x684 \
}

#define CPCI75C3_REG_DT_KA_INPUT_OUTPUT_FORMAT_ADD                   {0x450}

#define CPCI75C3_REG_DT_KA_RESET_OVER_CURRENT                        0x688

#define CPCI75C3_REG_DT_KA_OUTPUT_BIT_STATUS                         0x6AC
#define CPCI75C3_REG_DT_KA_INPUT_BIT_STATUS                          0x6B0

#define CPCI75C3_REG_DT_KA_OUTPUT_OVER_CURRENT_STATUS                0x6A8

#define CPCI75C3_REG_DT_KA_OUTPUT_MAX_HI_THRESHOLD_STATUS            0x6B4
#define CPCI75C3_REG_DT_KA_INPUT_MAX_HI_THRESHOLD_STATUS             0x6B8

#define CPCI75C3_REG_DT_KA_OUTPUT_MIN_LOW_THRESHOLD_STATUS           0x6BC
#define CPCI75C3_REG_DT_KA_INPUT_MIN_LOW_THRESHOLD_STATUS            0x6C0

#define CPCI75C3_REG_DT_KA_OUTPUT_MID_RANGE_FAULT_STATUS             0x6C4
#define CPCI75C3_REG_DT_KA_INPUT_MID_RANGE_FAULT_STATUS              0x6C8

#define CPCI75C3_REG_DT_KA_OUTPUT_LOW_HI_TRANSITION_STATUS           0x6CC
#define CPCI75C3_REG_DT_KA_INPUT_LOW_HI_TRANSITION_STATUS            0x6D0

#define CPCI75C3_REG_DT_KA_OUTPUT_HI_LOW_TRANSITION_STATUS           0x6D4
#define CPCI75C3_REG_DT_KA_INPUT_HI_LOW_TRANSITION_STATUS            0x6D8

#define CPCI75C3_REG_DT_KA_OUTPUT_BIT_INT_ENAB                       0x354
#define CPCI75C3_REG_DT_KA_INPUT_BIT_INT_ENAB                        0x358

#define CPCI75C3_REG_DT_KA_OUTPUT_OVER_CURRENT_INT_ENAB              0x350

#define CPCI75C3_REG_DT_KA_OUTPUT_MAX_HI_THRESHOLD_INT_ENAB          0x35C
#define CPCI75C3_REG_DT_KA_INPUT_MAX_HI_THRESHOLD_INT_ENAB           0x360

#define CPCI75C3_REG_DT_KA_OUTPUT_MIN_LOW_THRESHOLD_INT_ENAB         0x364
#define CPCI75C3_REG_DT_KA_INPUT_MIN_LOW_THRESHOLD_INT_ENAB          0x368

#define CPCI75C3_REG_DT_KA_OUTPUT_MID_RANGE_FAULT_INT_ENAB           0x36C
#define CPCI75C3_REG_DT_KA_INPUT_MID_RANGE_FAULT_INT_ENAB            0x370

#define CPCI75C3_REG_DT_KA_OUTPUT_LOW_HI_TRANSITION_INT_ENAB         0x374
#define CPCI75C3_REG_DT_KA_INPUT_LOW_HI_TRANSITION_INT_ENAB          0x378

#define CPCI75C3_REG_DT_KA_OUTPUT_HI_LOW_TRANSITION_INT_ENAB         0x37C
#define CPCI75C3_REG_DT_KA_INPUT_HI_LOW_TRANSITION_INT_ENAB          0x380

#define CPCI75C3_REG_DT_KA_OUTPUT_INT_VECTOR_BIT                     0x7D0
#define CPCI75C3_REG_DT_KA_INPUT_INT_VECTOR_BIT                      0x7D4

#define CPCI75C3_REG_DT_KA_OUTPUT_INT_VECTOR_MAX_HI_THRESHOLD        0x7D8
#define CPCI75C3_REG_DT_KA_INPUT_INT_VECTOR_MAX_HI_THRESHOLD         0x7DC

#define CPCI75C3_REG_DT_KA_OUTPUT_INT_VECTOR_MIN_LO_THRESHOLD        0x7E0
#define CPCI75C3_REG_DT_KA_INPUT_INT_VECTOR_MIN_LO_THRESHOLD         0x7E4

#define CPCI75C3_REG_DT_KA_OUTPUT_INT_VECTOR_MID_RANGE_THRESHOLD     0x7E8
#define CPCI75C3_REG_DT_KA_INPUT_INT_VECTOR_MID_RANGE_THRESHOLD      0x7EC

#define CPCI75C3_REG_DT_KA_OUTPUT_INT_VECTOR_OVERCURRENT             0x784

#define CPCI75C3_REG_DT_KA_OUTPUT_INT_VECTOR_LO_HI_TRANSITION        0x788
#define CPCI75C3_REG_DT_KA_INPUT_INT_VECTOR_LO_HI_TRANSITION         0x78C

#define CPCI75C3_REG_DT_KA_OUTPUT_INT_VECTOR_HI_LO_TRANSITION        0x790
#define CPCI75C3_REG_DT_KA_INPUT_INT_VECTOR_HI_LO_TRANSITION         0x794


/* DT PWM Timer (specific to KA module) */
#define CPCI75C3_DT_PWM_TIMER_PERIOD_RANGE_MIN  0x0002
#define CPCI75C3_DT_PWM_TIMER_PERIOD_RANGE_MAX  0xFFFF

static const double CPCI75C3_DT_KA_TIMER_PER_LSB = 0.001;	/* Millisecond (1 us) */
static const double CPCI75C3_DT_KA_TIMER_PER_MIN = 0.002;   /* Milliseconds */
static const double CPCI75C3_DT_KA_TIMER_PER_MAX = 65.535;	/* Milliseconds */

static const double CPCI75C3_DT_KA_PULSE_WIDTH_LSB = 0.001; /* Millisecond (1 us) */
static const double CPCI75C3_DT_KA_PULSE_WIDTH_MIN = 0.001;   /* Milliseconds */
static const double CPCI75C3_DT_KA_PULSE_WIDTH_MAX = 65.534;	/* Milliseconds */





/*******************************************/
/******   All DT Specific Functions   ******/
/*******************************************/
/******   DT VCC Bank Count   ******/
_75C3FUNC int CPCI75C3_DT_GetNumVCCBanks( int Card, int Module, int *NumVCCBanks);
/******   DT Channel Count   ******/
_75C3FUNC int CPCI75C3_DT_GetMaxChan( unsigned short ModuleID, int *MaxChan );

/******   DT Input and Output State   ******/
_75C3FUNC int CPCI75C3_DT_SetOutputState( int Card, int Module, int Channel, unsigned short OutputState );
_75C3FUNC int CPCI75C3_DT_GetOutputState( int Card, int Module, int Channel, unsigned short *OutputState );
_75C3FUNC int CPCI75C3_DT_SetOutputStateWord( int Card, int Module, unsigned short OutputState );
_75C3FUNC int CPCI75C3_DT_GetOutputStateWord( int Card, int Module, unsigned short *OutputState );
_75C3FUNC int CPCI75C3_DT_GetInputState( int Card, int Module, int Channel, unsigned short *InputState );
_75C3FUNC int CPCI75C3_DT_GetInputStateWord( int Card, int Module, unsigned short *InputState );
/******   DT Thresholds   ******/
_75C3FUNC int CPCI75C3_DT_SetMaxHiThreshold( int Card, int Module, int Channel, double MaxHiThreshold );
_75C3FUNC int CPCI75C3_DT_GetMaxHiThreshold( int Card, int Module, int Channel, double *MaxHiThreshold );
_75C3FUNC int CPCI75C3_DT_SetUpperThreshold( int Card, int Module, int Channel, double UpperThreshold );
_75C3FUNC int CPCI75C3_DT_GetUpperThreshold( int Card, int Module, int Channel, double *UpperThreshold );
_75C3FUNC int CPCI75C3_DT_SetLowerThreshold( int Card, int Module, int Channel, double LowerThreshold );
_75C3FUNC int CPCI75C3_DT_GetLowerThreshold( int Card, int Module, int Channel, double *LowerThreshold );
_75C3FUNC int CPCI75C3_DT_SetMinLowThreshold( int Card, int Module, int Channel, double MinLowThreshold );
_75C3FUNC int CPCI75C3_DT_GetMinLowThreshold( int Card, int Module, int Channel, double *MinLowThreshold );

/******   DT Debounce Time   ******/
_75C3FUNC int CPCI75C3_DT_SetDebounceTime( int Card, int Module, int Channel, double DebounceTime );
_75C3FUNC int CPCI75C3_DT_GetDebounceTime( int Card, int Module, int Channel, double *DebounceTime );

/******   DT IO Format   ******/
_75C3FUNC int CPCI75C3_DT_SetIOFormat( int Card, int Module, int Channel, unsigned short Format );
_75C3FUNC int CPCI75C3_DT_SetIOFormatWord1( int Card, int Module, unsigned short Format );
_75C3FUNC int CPCI75C3_DT_SetIOFormatWord2( int Card, int Module, unsigned short Format );
_75C3FUNC int CPCI75C3_DT_GetIOFormat( int Card, int Module, int Channel, unsigned short *Format );
_75C3FUNC int CPCI75C3_DT_GetIOFormatWord1( int Card, int Module, unsigned short *Format );
_75C3FUNC int CPCI75C3_DT_GetIOFormatWord2( int Card, int Module, unsigned short *Format );

/******   DT OverCurrent Reset   ******/
_75C3FUNC int CPCI75C3_DT_ResetOverCurrent( int Card,int Module );

/******   DT Status Information   ******/
/****** Note, calling these functions will unlatch the status register for all channels *****/
/****** To get the status of all channels call the following functions:                 *****/
/*
K6 Modules:
_75C3FUNC int CPCI75C3_DT_GetBITStatusWord( int Card, int Module, unsigned short *BITStatusWord );
_75C3FUNC int CPCI75C3_DT_GetOverCurrentStatusWord( int Card, int Module, unsigned short *OverCurrentStatusWord );
_75C3FUNC int CPCI75C3_DT_GetMaxHiThresholdStatusWord( int Card, int Module, unsigned short *MaxHiThresholdStatusWord );
_75C3FUNC int CPCI75C3_DT_GetMinLowThresholdStatusWord( int Card, int Module, unsigned short *MinLowThresholdStatusWord );
_75C3FUNC int CPCI75C3_DT_GetMidRangeFaultStatusWord( int Card, int Module, unsigned short *MidRangeFaultStatusWord );
_75C3FUNC int CPCI75C3_DT_GetLowHiTransStatusWord( int Card, int Module, unsigned short *LowHiTransStatusWord );
_75C3FUNC int CPCI75C3_DT_GetHiLowTransStatusWord( int Card, int Module, unsigned short *HiLowTransStatusWord );
KA Modules:
_75C3FUNC int CPCI75C3_DT_GetBITStatusInputWord( int Card, int Module, unsigned short *BITStatusWord );
_75C3FUNC int CPCI75C3_DT_GetBITStatusOutputWord( int Card, int Module, unsigned short *BITStatusWord );
_75C3FUNC int CPCI75C3_DT_GetOverCurrentStatusOutputWord( int Card, int Module, unsigned short *OverCurrentStatusWord );
_75C3FUNC int CPCI75C3_DT_GetMaxHiThresholdStatusInputWord( int Card, int Module, unsigned short *MaxHiThresholdStatusWord );
_75C3FUNC int CPCI75C3_DT_GetMaxHiThresholdStatusOutputWord( int Card, int Module, unsigned short *MaxHiThresholdStatusWord );
_75C3FUNC int CPCI75C3_DT_GetMinLowThresholdStatusInputWord( int Card, int Module, unsigned short *MinLowThresholdStatusWord );
_75C3FUNC int CPCI75C3_DT_GetMinLowThresholdStatusOutputWord( int Card, int Module, unsigned short *MinLowThresholdStatusWord );
_75C3FUNC int CPCI75C3_DT_GetMidRangeFaultStatusInputWord( int Card, int Module, unsigned short *MidRangeFaultStatusWord );
_75C3FUNC int CPCI75C3_DT_GetMidRangeFaultStatusOutputWord( int Card, int Module, unsigned short *MidRangeFaultStatusWord );
_75C3FUNC int CPCI75C3_DT_GetLowHiTransStatusInputWord( int Card, int Module, unsigned short *LowHiTransStatusWord );
_75C3FUNC int CPCI75C3_DT_GetLowHiTransStatusOutputWord( int Card, int Module, unsigned short *LowHiTransStatusWord );
_75C3FUNC int CPCI75C3_DT_GetHiLowTransStatusInputWord( int Card, int Module, unsigned short *HiLowTransStatusWord );
_75C3FUNC int CPCI75C3_DT_GetHiLowTransStatusOutputWord( int Card, int Module, unsigned short *HiLowTransStatusWord );
*/
_75C3FUNC int CPCI75C3_DT_GetBITStatus( int Card, int Module, int Channel, unsigned short *BITStatus );
_75C3FUNC int CPCI75C3_DT_GetOverCurrentStatus( int Card, int Module, int Channel, unsigned short *OverCurrentStatus );
_75C3FUNC int CPCI75C3_DT_GetMaxHiThresholdStatus( int Card, int Module, int Channel, unsigned short *MaxHiThresholdStatus );
_75C3FUNC int CPCI75C3_DT_GetMinLowThresholdStatus( int Card, int Module, int Channel, unsigned short *MinLowThresholdStatus );
_75C3FUNC int CPCI75C3_DT_GetMidRangeFaultStatus( int Card, int Module, int Channel, unsigned short *MidRangeFaultStatus );
_75C3FUNC int CPCI75C3_DT_GetLowHiTransStatus( int Card, int Module, int Channel, unsigned short *LowHiTransStatus );
_75C3FUNC int CPCI75C3_DT_GetHiLowTransStatus( int Card, int Module,  int Channel, unsigned short *HiLowTransStatus );

/******   DT Interrupt Enable   ******/
_75C3FUNC int CPCI75C3_DT_SetBITIntEnable( int Card, int Module,  int Channel, unsigned short BITIntEnable );
_75C3FUNC int CPCI75C3_DT_GetBITIntEnable( int Card, int Module,  int Channel, unsigned short *BITIntEnable );
_75C3FUNC int CPCI75C3_DT_SetOverCurrentIntEnable( int Card, int Module, int Channel, unsigned short OverCurrentIntEnable );
_75C3FUNC int CPCI75C3_DT_GetOverCurrentIntEnable( int Card, int Module, int Channel, unsigned short *OverCurrentIntEnable );
_75C3FUNC int CPCI75C3_DT_SetMaxHiThresholdIntEnable( int Card, int Module, int Channel, unsigned short MaxHiThresholdIntEnable );
_75C3FUNC int CPCI75C3_DT_GetMaxHiThresholdIntEnable( int Card, int Module, int Channel, unsigned short *MaxHiThresholdIntEnable );
_75C3FUNC int CPCI75C3_DT_SetMaxHiThresholdIntEnableOutputWord( int Card, int Module, unsigned short MaxHiThresholdIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetMinLowThresholdIntEnable( int Card, int Module, int Channel, unsigned short MinLowThresholdIntEnable );
_75C3FUNC int CPCI75C3_DT_GetMinLowThresholdIntEnable( int Card, int Module, int Channel, unsigned short *MinLowThresholdIntEnable );
_75C3FUNC int CPCI75C3_DT_SetMidRangeFaultIntEnable( int Card, int Module, int Channel, unsigned short MidRangeFaultIntEnable );
_75C3FUNC int CPCI75C3_DT_GetMidRangeFaultIntEnable( int Card, int Module, int Channel, unsigned short *MidRangeFaultIntEnable );
_75C3FUNC int CPCI75C3_DT_SetLowHiTransIntEnable( int Card, int Module, int Channel, unsigned short LowHiTransIntEnable );
_75C3FUNC int CPCI75C3_DT_GetLowHiTransIntEnable( int Card, int Module, int Channel, unsigned short *LowHiTransIntEnable );
_75C3FUNC int CPCI75C3_DT_SetHiLowTransIntEnable( int Card, int Module, int Channel, unsigned short HiLowTransIntEnable );
_75C3FUNC int CPCI75C3_DT_GetHiLowTransIntEnable( int Card, int Module, int Channel, unsigned short *HiLowTransIntEnable );


/*************************************************/
/******   K6 Module DT Specific Functions   ******/
/*************************************************/
/******   DT Input and Output State   ******/
_75C3FUNC int CPCI75C3_DT_SetOutputStateWord( int Card, int Module, unsigned short OutputStateWord );
_75C3FUNC int CPCI75C3_DT_GetOutputStateWord( int Card, int Module, unsigned short *OutputStateWord );
_75C3FUNC int CPCI75C3_DT_GetInputStateWord( int Card, int Module, unsigned short *InputStateWord );

/******   DT Source Sink Current   ******/
_75C3FUNC int CPCI75C3_DT_SetSourceSinkCurrent( int Card, int Module, int Channel, double Current );
_75C3FUNC int CPCI75C3_DT_SetSourceSinkCurrentBank( int Card, int Module, int Bank, double Current );
_75C3FUNC int CPCI75C3_DT_GetSourceSinkCurrent( int Card, int Module, int Channel, double *Current );
_75C3FUNC int CPCI75C3_DT_GetSourceSinkCurrentBank( int Card, int Module, int Bank, double *Current );

/******   DT Pull-up and Pull-Down   ******/
_75C3FUNC int CPCI75C3_DT_SetPullUpDownConfig( int Card, int Module, int Channel, unsigned short Config );
_75C3FUNC int CPCI75C3_DT_GetPullUpDownConfig( int Card, int Module, int Channel, unsigned short *Config );
_75C3FUNC int CPCI75C3_DT_SetPullUpDownConfigWord( int Card, int Module, unsigned short ConfigWord );
_75C3FUNC int CPCI75C3_DT_GetPullUpDownConfigWord( int Card, int Module, unsigned short *ConfigWord );

/******   DT VCC Voltage   ******/
         
_75C3FUNC int CPCI75C3_DT_GetVccVoltage( int Card, int Module, int Channel, double *Voltage );

_75C3FUNC int CPCI75C3_DT_GetCurrentShareConfig( int Card, int Module, int Bank, unsigned short *Config );
_75C3FUNC int CPCI75C3_DT_SetCurrentShareConfigWord( int Card, int Module, unsigned short ConfigWord );
_75C3FUNC int CPCI75C3_DT_GetCurrentShareConfigWord( int Card, int Module, unsigned short *ConfigWord );
_75C3FUNC int CPCI75C3_DT_GetVoltageRdg( int Card, int Module, int Channel, double *Voltage );
_75C3FUNC int CPCI75C3_DT_GetCurrentRdg( int Card, int Module, int Channel, double *Current );
_75C3FUNC int CPCI75C3_DT_GetVoltageRdgWord( int Card, int Module, int Channel, unsigned short *VoltageWord );
_75C3FUNC int CPCI75C3_DT_GetCurrentRdgWord( int Card, int Module, int Channel, unsigned short *CurrentWord );
_75C3FUNC int CPCI75C3_DT_GetVccVoltageBankWord( int Card, int Module, int Bank, unsigned short *Voltage );

/******   DT Status Information   ******/
_75C3FUNC int CPCI75C3_DT_GetBITStatusWord( int Card, int Module, unsigned short *BITStatusWord );
_75C3FUNC int CPCI75C3_DT_GetOverCurrentStatusWord( int Card, int Module, unsigned short *OverCurrentStatusWord );
_75C3FUNC int CPCI75C3_DT_GetMaxHiThresholdStatusWord( int Card, int Module, unsigned short *MaxHiThresholdStatusWord );
_75C3FUNC int CPCI75C3_DT_GetMinLowThresholdStatusWord( int Card, int Module, unsigned short *MinLowThresholdStatusWord );
_75C3FUNC int CPCI75C3_DT_GetMidRangeFaultStatusWord( int Card, int Module, unsigned short *MidRangeFaultStatusWord );
_75C3FUNC int CPCI75C3_DT_GetLowHiTransStatusWord( int Card, int Module, unsigned short *LowHiTransStatusWord );
_75C3FUNC int CPCI75C3_DT_GetHiLowTransStatusWord( int Card, int Module, unsigned short *HiLowTransStatusWord );

/******   DT Interrupt Enable   ******/
_75C3FUNC int CPCI75C3_DT_SetBITIntEnableWord( int Card, int Module, unsigned short BITIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetBITIntEnableWord( int Card, int Module, unsigned short *BITIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetOverCurrentIntEnableWord( int Card, int Module, unsigned short OverCurrentIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetOverCurrentIntEnableWord( int Card, int Module, unsigned short *OverCurrentIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetMaxHiThresholdIntEnableWord( int Card, int Module, unsigned short MaxHiThresholdIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetMaxHiThresholdIntEnableWord( int Card, int Module, unsigned short *MaxHiThresholdIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetMinLowThresholdIntEnableWord( int Card, int Module, unsigned short MinLowThresholdIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetMinLowThresholdIntEnableWord( int Card, int Module, unsigned short *MinLowThresholdIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetMidRangeFaultIntEnableWord( int Card, int Module, unsigned short MidRangeFaultIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetMidRangeFaultIntEnableWord( int Card, int Module, unsigned short *MidRangeFaultIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetLowHiTransIntEnableWord( int Card, int Module, unsigned short LowHiTransIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetLowHiTransIntEnableWord( int Card, int Module, unsigned short *LowHiTransIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetHiLowTransIntEnableWord( int Card, int Module, unsigned short HiLowTransIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetHiLowTransIntEnableWord( int Card, int Module, unsigned short *HiLowTransIntEnableWord );

/******   DT Interrupt Vector   ******/
_75C3FUNC int CPCI75C3_DT_GetBITInterruptVector( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DT_SetBITInterruptVector( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetOverCurrentInterruptVector( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DT_SetOverCurrentInterruptVector( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetMaxHiThresholdInterruptVector( int Card, int Module, int *InterruptVector);
_75C3FUNC int CPCI75C3_DT_SetMaxHiThresholdInterruptVector( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetMinLoThresholdInterruptVector( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DT_SetMinLoThresholdInterruptVector( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetMidRangeInterruptVector( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DT_SetMidRangeInterruptVector( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetLoHiInterruptVector( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DT_SetLoHiInterruptVector( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetHiLoInterruptVector( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DT_SetHiLoInterruptVector( int Card, int Module, int InterruptVector );

/*************************************************/
/******   KA Module DT Specific Functions   ******/
/*************************************************/
/******   DT Input and Output State   ******/
_75C3FUNC int CPCI75C3_DT_SetOutputStateOutputWord( int Card, int Module, unsigned short OutputStateWord );
_75C3FUNC int CPCI75C3_DT_GetOutputStateOutputWord( int Card, int Module, unsigned short *OutputStateWord );
_75C3FUNC int CPCI75C3_DT_SetOutputStateIOWord( int Card, int Module, unsigned short OutputStateWord );
_75C3FUNC int CPCI75C3_DT_GetOutputStateIOWord( int Card, int Module, unsigned short *OutputStateWord );
_75C3FUNC int CPCI75C3_DT_GetInputStateInputWord( int Card, int Module, unsigned short *InputStateWord );
_75C3FUNC int CPCI75C3_DT_GetInputStateOutputWord( int Card, int Module, unsigned short *InputStateWord );
_75C3FUNC int CPCI75C3_DT_GetInputStateIOWord( int Card, int Module, unsigned short *InputStateWord );

/******   DT Status Information   ******/
/****** Note, the Output channels and IO channels for the KA module share the same register *****/
/****** Calling these functions ___StatusOutputWord() and __StatusIOWord() returns data     *****/
/****** the same register.                                                                  *****/
_75C3FUNC int CPCI75C3_DT_GetBITStatusInputWord( int Card, int Module, unsigned short *BITStatusWord );
_75C3FUNC int CPCI75C3_DT_GetBITStatusOutputWord( int Card, int Module, unsigned short *BITStatusWord );
_75C3FUNC int CPCI75C3_DT_GetBITStatusIOWord( int Card, int Module, unsigned short *BITStatusWord );
_75C3FUNC int CPCI75C3_DT_GetOverCurrentStatusOutputWord( int Card, int Module, unsigned short *OverCurrentStatusWord );
_75C3FUNC int CPCI75C3_DT_GetOverCurrentStatusIOWord( int Card, int Module, unsigned short *OverCurrentStatusWord );
_75C3FUNC int CPCI75C3_DT_GetMaxHiThresholdStatusInputWord( int Card, int Module, unsigned short *MaxHiThresholdStatusWord );
_75C3FUNC int CPCI75C3_DT_GetMaxHiThresholdStatusOutputWord( int Card, int Module, unsigned short *MaxHiThresholdStatusWord );
_75C3FUNC int CPCI75C3_DT_GetMaxHiThresholdStatusIOWord( int Card, int Module, unsigned short *MaxHiThresholdStatusWord );
_75C3FUNC int CPCI75C3_DT_GetMinLowThresholdStatusInputWord( int Card, int Module, unsigned short *MinLowThresholdStatusWord );
_75C3FUNC int CPCI75C3_DT_GetMinLowThresholdStatusOutputWord( int Card, int Module, unsigned short *MinLowThresholdStatusWord );
_75C3FUNC int CPCI75C3_DT_GetMinLowThresholdStatusIOWord( int Card, int Module, unsigned short *MinLowThresholdStatusWord );
_75C3FUNC int CPCI75C3_DT_GetMidRangeFaultStatusInputWord( int Card, int Module, unsigned short *MidRangeFaultStatusWord );
_75C3FUNC int CPCI75C3_DT_GetMidRangeFaultStatusOutputWord( int Card, int Module, unsigned short *MidRangeFaultStatusWord );
_75C3FUNC int CPCI75C3_DT_GetMidRangeFaultStatusIOWord( int Card, int Module, unsigned short *MidRangeFaultStatusWord );
_75C3FUNC int CPCI75C3_DT_GetLowHiTransStatusInputWord( int Card, int Module, unsigned short *LowHiTransStatusWord );
_75C3FUNC int CPCI75C3_DT_GetLowHiTransStatusOutputWord( int Card, int Module, unsigned short *LowHiTransStatusWord );
_75C3FUNC int CPCI75C3_DT_GetLowHiTransStatusIOWord( int Card, int Module, unsigned short *LowHiTransStatusWord );
_75C3FUNC int CPCI75C3_DT_GetHiLowTransStatusInputWord( int Card, int Module, unsigned short *HiLowTransStatusWord );
_75C3FUNC int CPCI75C3_DT_GetHiLowTransStatusOutputWord( int Card, int Module, unsigned short *HiLowTransStatusWord );
_75C3FUNC int CPCI75C3_DT_GetHiLowTransStatusIOWord( int Card, int Module, unsigned short *HiLowTransStatusWord );

/******   DT Interrupt Enable   ******/
_75C3FUNC int CPCI75C3_DT_SetBITIntEnableInputWord( int Card, int Module, unsigned short BITIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetBITIntEnableInputWord( int Card, int Module, unsigned short *BITIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetBITIntEnableOutputWord( int Card, int Module, unsigned short BITIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetBITIntEnableOutputWord( int Card, int Module, unsigned short *BITIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetBITIntEnableIOWord( int Card, int Module, unsigned short BITIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetBITIntEnableIOWord( int Card, int Module, unsigned short *BITIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetOverCurrentIntEnableOutputWord( int Card, int Module, unsigned short OverCurrentIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetOverCurrentIntEnableOutputWord( int Card, int Module, unsigned short *OverCurrentIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetOverCurrentIntEnableIOWord( int Card, int Module, unsigned short OverCurrentIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetOverCurrentIntEnableIOWord( int Card, int Module, unsigned short *OverCurrentIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetMaxHiThresholdIntEnableInputWord( int Card, int Module, unsigned short MaxHiThresholdIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetMaxHiThresholdIntEnableInputWord( int Card, int Module, unsigned short *MaxHiThresholdIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetMaxHiThresholdIntEnableOutputWord( int Card, int Module, unsigned short *MaxHiThresholdIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetMaxHiThresholdIntEnableIOWord( int Card, int Module, unsigned short MaxHiThresholdIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetMaxHiThresholdIntEnableIOWord( int Card, int Module, unsigned short *MaxHiThresholdIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetMinLowThresholdIntEnableInputWord( int Card, int Module, unsigned short MinLowThresholdIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetMinLowThresholdIntEnableInputWord( int Card, int Module, unsigned short *MinLowThresholdIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetMinLowThresholdIntEnableOutputWord( int Card, int Module, unsigned short MinLowThresholdIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetMinLowThresholdIntEnableOutputWord( int Card, int Module, unsigned short *MinLowThresholdIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetMinLowThresholdIntEnableIOWord( int Card, int Module, unsigned short MinLowThresholdIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetMinLowThresholdIntEnableIOWord( int Card, int Module, unsigned short *MinLowThresholdIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetMidRangeFaultIntEnableInputWord( int Card, int Module, unsigned short MidRangeFaultIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetMidRangeFaultIntEnableInputWord( int Card, int Module, unsigned short *MidRangeFaultIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetMidRangeFaultIntEnableOutputWord( int Card, int Module, unsigned short MidRangeFaultIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetMidRangeFaultIntEnableOutputWord( int Card, int Module, unsigned short *MidRangeFaultIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetMidRangeFaultIntEnableIOWord( int Card, int Module, unsigned short MidRangeFaultIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetMidRangeFaultIntEnableIOWord( int Card, int Module, unsigned short *MidRangeFaultIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetLowHiTransIntEnableInputWord( int Card, int Module, unsigned short LowHiTransIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetLowHiTransIntEnableInputWord( int Card, int Module, unsigned short *LowHiTransIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetLowHiTransIntEnableOutputWord( int Card, int Module, unsigned short LowHiTransIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetLowHiTransIntEnableOutputWord( int Card, int Module, unsigned short *LowHiTransIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetLowHiTransIntEnableIOWord( int Card, int Module, unsigned short LowHiTransIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetLowHiTransIntEnableIOWord( int Card, int Module, unsigned short *LowHiTransIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetHiLowTransIntEnableInputWord( int Card, int Module, unsigned short HiLowTransIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetHiLowTransIntEnableInputWord( int Card, int Module, unsigned short *HiLowTransIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetHiLowTransIntEnableOutputWord( int Card, int Module, unsigned short HiLowTransIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetHiLowTransIntEnableOutputWord( int Card, int Module, unsigned short *HiLowTransIntEnableWord );
_75C3FUNC int CPCI75C3_DT_SetHiLowTransIntEnableIOWord( int Card, int Module, unsigned short HiLowTransIntEnableWord );
_75C3FUNC int CPCI75C3_DT_GetHiLowTransIntEnableIOWord( int Card, int Module, unsigned short *HiLowTransIntEnableWord );

/******   DT Interrupt Vector   ******/
_75C3FUNC int CPCI75C3_DT_SetBITInterruptVectorInput( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetBITInterruptVectorInput( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DT_SetBITInterruptVectorOutput( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetBITInterruptVectorOutput( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DT_SetBITInterruptVectorIO( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetBITInterruptVectorIO( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DT_SetOverCurrentInterruptVectorOutput( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetOverCurrentInterruptVectorOutput( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DT_SetOverCurrentInterruptVectorIO( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetOverCurrentInterruptVectorIO( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DT_SetMaxHiThresholdInterruptVectorInput( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetMaxHiThresholdInterruptVectorInput( int Card, int Module, int *InterruptVector);
_75C3FUNC int CPCI75C3_DT_SetMaxHiThresholdInterruptVectorOutput( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetMaxHiThresholdInterruptVectorOutput( int Card, int Module, int *InterruptVector);
_75C3FUNC int CPCI75C3_DT_SetMaxHiThresholdInterruptVectorIO( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetMaxHiThresholdInterruptVectorIO( int Card, int Module, int *InterruptVector);
_75C3FUNC int CPCI75C3_DT_SetMinLoThresholdInterruptVectorInput( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetMinLoThresholdInterruptVectorInput( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DT_SetMinLoThresholdInterruptVectorOutput( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetMinLoThresholdInterruptVectorOutput( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DT_SetMinLoThresholdInterruptVectorIO( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetMinLoThresholdInterruptVectorIO( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DT_SetMidRangeInterruptVectorInput( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetMidRangeInterruptVectorInput( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DT_SetMidRangeInterruptVectorOutput( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetMidRangeInterruptVectorOutput( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DT_SetMidRangeInterruptVectorIO( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetMidRangeInterruptVectorIO( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DT_SetLoHiInterruptVectorInput( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetLoHiInterruptVectorInput( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DT_SetLoHiInterruptVectorOutput( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetLoHiInterruptVectorOutput( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DT_SetLoHiInterruptVectorIO( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetLoHiInterruptVectorIO( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DT_SetHiLoInterruptVectorInput( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetHiLoInterruptVectorInput( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DT_SetHiLoInterruptVectorOutput( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetHiLoInterruptVectorOutput( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DT_SetHiLoInterruptVectorIO( int Card, int Module, int InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetHiLoInterruptVectorIO( int Card, int Module, int *InterruptVector );
_75C3FUNC int CPCI75C3_DT_GetDesignVersion( int Card, int Module, unsigned short *Version );
_75C3FUNC int CPCI75C3_DT_GetDesignRevision( int Card, int Module, unsigned short *Revision );
_75C3FUNC int CPCI75C3_DT_SetVoltageCalFactors(int Card, int Module, int Channel, short Offset, unsigned short Gain);
_75C3FUNC int CPCI75C3_DT_SetCalFactors( int Card, int Module, int Channel, short Offset, unsigned short SourceGain, unsigned short SinkGain);
_75C3FUNC int CPCI75C3_IsKAOutputChannel( int Channel );
_75C3FUNC int CPCI75C3_IsKAInputChannel( int Channel );


/******   DT PWM/Timer  ******/
_75C3FUNC int CPCI75C3_DT_SetPWMTimerPeriod( int Card, int Module, int Channel, double Period );
_75C3FUNC int CPCI75C3_DT_GetPWMTimerPeriod( int Card, int Module, int Channel, double *Period );
_75C3FUNC int CPCI75C3_DT_SetPWMTimerPeriodWord( int Card, int Module, int Channel, unsigned short PeriodWord );
_75C3FUNC int CPCI75C3_DT_GetPWMTimerPeriodWord( int Card, int Module, int Channel, unsigned short *PeriodWord );

_75C3FUNC int CPCI75C3_DT_SetPWMTimerPulseWidth( int Card, int Module, int Channel, double PulseWidth );
_75C3FUNC int CPCI75C3_DT_GetPWMTimerPulseWidth( int Card, int Module, int Channel, double *PulseWidth );
_75C3FUNC int CPCI75C3_DT_SetPWMTimerPulseWidthWord( int Card, int Module, int Channel, unsigned short PulseWidthWord );
_75C3FUNC int CPCI75C3_DT_GetPWMTimerPulseWidthWord( int Card, int Module, int Channel, unsigned short *PulseWidthWord );

_75C3FUNC int CPCI75C3_DT_SetPWMTimerPolarity( int Card, int Module, int Channel, unsigned short Polarity );
_75C3FUNC int CPCI75C3_DT_GetPWMTimerPolarity( int Card, int Module, int Channel, unsigned short *Polarity );
_75C3FUNC int CPCI75C3_DT_SetPWMTimerPolarityWord( int Card, int Module, int Channel, unsigned short PolarityWord );
_75C3FUNC int CPCI75C3_DT_GetPWMTimerPolarityWord( int Card, int Module, int Channel, unsigned short *PolarityWord );

_75C3FUNC int CPCI75C3_DT_SetPWMTimerModeSel( int Card, int Module, int Channel, unsigned short ModeSel );
_75C3FUNC int CPCI75C3_DT_GetPWMTimerModeSel( int Card, int Module, int Channel, unsigned short *ModeSel );
_75C3FUNC int CPCI75C3_DT_SetPWMTimerModeSelWord( int Card, int Module, unsigned short ModeSelWord );
_75C3FUNC int CPCI75C3_DT_GetPWMTimerModeSelWord( int Card, int Module, unsigned short *ModeSelWord );

_75C3FUNC int CPCI75C3_DT_SetPWMTimerEnable( int Card, int Module, int Channel, unsigned short Enable );
_75C3FUNC int CPCI75C3_DT_GetPWMTimerEnable( int Card, int Module, int Channel, unsigned short *Enable );
_75C3FUNC int CPCI75C3_DT_SetPWMTimerEnableWord( int Card, int Module, unsigned short EnableWord );
_75C3FUNC int CPCI75C3_DT_GetPWMTimerEnableWord( int Card, int Module, unsigned short *EnableWord );



/*DT Word operations*/
_75C3FUNC int CPCI75C3_DT_SetMinLowThresholdWord( int Card, int Module, int Channel, unsigned short ThresholdWord );
_75C3FUNC int CPCI75C3_DT_GetMinLowThresholdWord( int Card, int Module, int Channel, unsigned short *ThresholdWord );
_75C3FUNC int CPCI75C3_DT_SetSourceSinkCurrentBankWord( int Card, int Module, int Bank, unsigned short CurrentWord );
_75C3FUNC int CPCI75C3_DT_SetLowerThresholdWord( int Card, int Module, int Channel, unsigned short ThresholdWord );
_75C3FUNC int CPCI75C3_DT_GetLowerThresholdWord( int Card, int Module, int Channel, unsigned short *ThresholdWord );
_75C3FUNC int CPCI75C3_DT_SetUpperThresholdWord( int Card, int Module, int Channel, unsigned short ThresholdWord );
_75C3FUNC int CPCI75C3_DT_GetUpperThresholdWord( int Card, int Module, int Channel, unsigned short *ThresholdWord );
_75C3FUNC int CPCI75C3_DT_SetMaxHiThresholdWord( int Card, int Module, int Channel, unsigned short ThresholdWord );
_75C3FUNC int CPCI75C3_DT_GetMaxHiThresholdWord( int Card, int Module, int Channel, unsigned short *ThresholdWord );
_75C3FUNC int CPCI75C3_DT_GetSourceSinkCurrentBankWord( int Card, int Module, int Bank, unsigned short *CurrentWord );

/****** Status Word Reads ******/
_75C3FUNC int CPCI75C3_DT_GetBITStatusChanGroupWord( int Card, int Module, int Channel, unsigned short *BITStatusWord );
_75C3FUNC int CPCI75C3_DT_GetOverCurrentStatusChanGroupWord( int Card, int Module, int Channel, unsigned short *OverCurrentStatusWord );
_75C3FUNC int CPCI75C3_DT_GetMaxHiThresholdStatusChanGroupWord( int Card, int Module, int Channel, unsigned short *MaxHiThresholdStatusWord );
_75C3FUNC int CPCI75C3_DT_GetMinLowThresholdStatusChanGroupWord( int Card, int Module, int Channel, unsigned short *MinLowThresholdStatusWord );
_75C3FUNC int CPCI75C3_DT_GetMidRangeFaultStatusChanGroupWord( int Card, int Module, int Channel, unsigned short *MidRangeFaultStatusWord );
_75C3FUNC int CPCI75C3_DT_GetLowHiTransStatusChanGroupWord( int Card, int Module, int Channel, unsigned short *LowHiTransStatusWord );
_75C3FUNC int CPCI75C3_DT_GetHiLowTransStatusChanGroupWord( int Card, int Module, int Channel, unsigned short *HiLowTransStatusWord );

/****  Internal Functions *************/
int CPCI75C3_GetIndexBase4( int Channel );
int CPCI75C3_IsKAIOChannel( int Channel );
void CPCI75C3_Init_DTMaxChan( int Card );
int CPCI75C3_DT_CheckCardModuleChannel(int Card, int Module, int Channel);



#ifdef __cplusplus
}
#endif

#endif

