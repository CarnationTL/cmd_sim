/*+++

Copyright (c) 2008 North Atlantic Industries,

File Name: CPCI75C3_REF.h

Description:	Header file to the PCI76C2 - W* (W0-W3) Reference Modules 
					This was written in ANSI 'C' for 32-bit integers.

Author: Kenny Cheung

History:

Date:  5-8-2008				File Created

---*/
#ifndef _REF_MOD_H
#define _REF_MOD_H

#include "CPCI75C3_include.h"

#define REG_VOLT_BIT_RES_MULT		100.0	/*each bit is 0.01 volt*/
#define MAX_REF_VOLT             115.0 /*this is default max*/
#define MIN_REF_VOLT             0.0 /*this is default max*/
#define MAX_W0_REF_VOLT				115.0	/*115V*/
#define MIN_W0_REF_VOLT				2.0	/*2V*/	
#define MAX_W1_REF_VOLT				115.0	/*115V*/
#define MIN_W1_REF_VOLT				2.0	/*2V*/	
#define MAX_W2_REF_VOLT				28.0	/*28V*/
#define MIN_W2_REF_VOLT				2.0	/*2V*/	
#define MAX_W3_REF_VOLT				115.0	/*115V*/
#define MIN_W3_REF_VOLT				28.0	/*28V*/	
#define MAX_REF_VOLT_REG_VAL	   (unsigned int)(MAX_REF_VOLT*REG_VOLT_BIT_RES_MULT)
#define MAX_W0_REF_VOLT_REG_VAL	(unsigned int)(MAX_W0_REF_VOLT*REG_VOLT_BIT_RES_MULT)	
#define MAX_W1_REF_VOLT_REG_VAL	(unsigned int)(MAX_W1_REF_VOLT*REG_VOLT_BIT_RES_MULT)	
#define MAX_W2_REF_VOLT_REG_VAL	(unsigned int)(MAX_W2_REF_VOLT*REG_VOLT_BIT_RES_MULT)	
#define MAX_W3_REF_VOLT_REG_VAL	(unsigned int)(MAX_W3_REF_VOLT*REG_VOLT_BIT_RES_MULT)	
#define MIN_REF_VOLT_REG_VAL	   (unsigned int)(MIN_REF_VOLT*REG_VOLT_BIT_RES_MULT)
#define MIN_W0_REF_VOLT_REG_VAL	(unsigned int)(MIN_W0_REF_VOLT*REG_VOLT_BIT_RES_MULT)	
#define MIN_W1_REF_VOLT_REG_VAL	(unsigned int)(MIN_W1_REF_VOLT*REG_VOLT_BIT_RES_MULT)	
#define MIN_W2_REF_VOLT_REG_VAL	(unsigned int)(MIN_W2_REF_VOLT*REG_VOLT_BIT_RES_MULT)	
#define MIN_W3_REF_VOLT_REG_VAL	(unsigned int)(MIN_W3_REF_VOLT*REG_VOLT_BIT_RES_MULT)	

#define MAX_REF_FREQ					10000	/*10KHz*/
#define MIN_REF_FREQ					47	/*47Hz*/
#define REG_FREQ_BIT_RES_MULT		100	/*each bit is 0.01 Hz*/
#define MAX_REF_FREQ_REG_VAL		MAX_REF_FREQ*REG_FREQ_BIT_RES_MULT /*Reg value of 10KHz*/
#define MIN_REF_FREQ_REG_VAL		MIN_REF_FREQ*REG_FREQ_BIT_RES_MULT /*Reg Value of 400Hz*/
/*Reference Frequency is the same for all W* modules so far*/
#define MAX_W0_REF_FREQ				MAX_REF_FREQ
#define MIN_W0_REF_FREQ				MIN_REF_FREQ	
#define MAX_W1_REF_FREQ				MAX_REF_FREQ
#define MIN_W1_REF_FREQ				MIN_REF_FREQ
#define MAX_W2_REF_FREQ				MAX_REF_FREQ
#define MIN_W2_REF_FREQ				MIN_REF_FREQ
#define MAX_W3_REF_FREQ				MAX_REF_FREQ
#define MIN_W3_REF_FREQ				MIN_REF_FREQ

/**************************/
/* REF Module Registers   */
/**************************/
#define CPCI75C3_REG_REF_POW_SUP_EN                     (0x0E0 << ADDR_SHIFT) /* This is the power supply enable 1=enable, 0=disable*/
#define CPCI75C3_REG_REF_CAL_EN                         (0x0E2 << ADDR_SHIFT) /* Enable DC Calibration*/
#define CPCI75C3_REG_REF_FREQUENCY_LOW                  (0x100 << ADDR_SHIFT) /* THIS REALLY IS THE ON BOARD OSCILLATOR */
#define CPCI75C3_REG_REF_FREQUENCY_HI                   (0x102 << ADDR_SHIFT) /* THIS REALLY IS THE ON BOARD OSCILLATOR */
#define CPCI75C3_REG_REF_VOLTAGE_LOW                    (0x104 << ADDR_SHIFT) /* THIS REALLY IS THE ON BOARD OSCILLATOR */
#define CPCI75C3_REG_REF_VOLTAGE_HI                     (0x106 << ADDR_SHIFT) /* THIS REALLY IS THE ON BOARD OSCILLATOR */
#define CPCI75C3_REG_REF_TEMPERATURE                    (0x10C << ADDR_SHIFT) /* reference temperature */
#define CPCI75C3_REG_REF_CURRENT                        (0x10E << ADDR_SHIFT) /* output current */
#define CPCI75C3_REG_REF_OVERCURRENT                    (0x110 << ADDR_SHIFT) /* overcurrent status */
/**********************************************************************************************************/
/*these are specific to DS's reference sub module*/
#define CPCI75C3_DS_REG_REF_FREQUENCY_LOW               (0x19C << ADDR_SHIFT) /* THIS REALLY IS THE ON BOARD OSCILLATOR */
#define CPCI75C3_DS_REG_REF_FREQUENCY_HI                (0x19E << ADDR_SHIFT) /* THIS REALLY IS THE ON BOARD OSCILLATOR */
#define CPCI75C3_DS_REG_REF_VOLTAGE_LOW                 (0x198 << ADDR_SHIFT) /* THIS REALLY IS THE ON BOARD OSCILLATOR */
#define CPCI75C3_DS_REG_REF_VOLTAGE_HI                  (0x19A << ADDR_SHIFT) /* THIS REALLY IS THE ON BOARD OSCILLATOR */

#define CPCI75C3_DL_REG_REF_FREQUENCY_LOW               (0x19C << ADDR_SHIFT) /* THIS REALLY IS THE ON BOARD OSCILLATOR */
#define CPCI75C3_DL_REG_REF_FREQUENCY_HI                (0x19E << ADDR_SHIFT) /* THIS REALLY IS THE ON BOARD OSCILLATOR */
#define CPCI75C3_DL_REG_REF_VOLTAGE_LOW                 (0x198 << ADDR_SHIFT) /* THIS REALLY IS THE ON BOARD OSCILLATOR */
#define CPCI75C3_DL_REG_REF_VOLTAGE_HI                  (0x19A << ADDR_SHIFT) /* THIS REALLY IS THE ON BOARD OSCILLATOR */
/**********************************************************************************************************/
#define CPCI75C3_REG_REF_DPRAM_OFFSETCOR_BASEADDR       (0x202 << ADDR_SHIFT) /* Get the dsp's internal dc offset correction array address through this register here*/
#define CPCI75C3_REG_REF_DPRAM_GAINCOR_BASEADDR         (0x206 << ADDR_SHIFT) /* Get the dsp's internal gain correction array address through this register here*/
#define CPCI75C3_REG_REF_DPRAM_LOCATION                 (0x392 << ADDR_SHIFT) /* Put dsp's internal address to be accessed in this register*/
#define CPCI75C3_REG_REF_DPRAM_DATA                     (0x396 << ADDR_SHIFT) /* DPRAM's data location to read/write */
#define CPCI75C3_REG_REF_DPRAM_ACCESS_MODE              (0x390 << ADDR_SHIFT) /* DPRAM access mode register*/

#define DPRAM_32BIT_ACCESS_MODE_MASK                   0x2232 /* 32-BIT access mode to the DSP's DPRAM*/



#ifdef __cplusplus
extern "C" {
#endif 
/******   Optional Reference Supply Control  ******/
_75C3FUNC int CPCI75C3_REF_SetRefFreq( int Card, int Module, unsigned int Frequency );
_75C3FUNC int CPCI75C3_REF_SetRefFreqWord( int Card, int Module, unsigned int Frequency );
_75C3FUNC int CPCI75C3_REF_GetRefFreq( int Card, int Module, unsigned int *RefFreq );
_75C3FUNC int CPCI75C3_REF_GetRefFreqWord( int Card, int Module, unsigned int *RefFreq );
_75C3FUNC int CPCI75C3_REF_SetRefVoltage( int Card, int Module, double Voltage );
_75C3FUNC int CPCI75C3_REF_SetRefVoltageWord( int Card, int Module, unsigned int Voltage );
_75C3FUNC int CPCI75C3_REF_GetRefVoltage( int Card, int Module, double *RefVoltage );
_75C3FUNC int CPCI75C3_REF_GetRefVoltageWord( int Card, int Module, unsigned int *RefVoltage);
_75C3FUNC int CPCI75C3_REF_PowerSupplyEnable( int Card, int Module, unsigned short Enable);
_75C3FUNC int CPCI75C3_REF_GetPowerSupplyEnable( int Card, int Module, unsigned short *Enable);
_75C3FUNC int CPCI75C3_REF_GetRefTemperature( int Card, int Module, int *RefTemperature );
_75C3FUNC int CPCI75C3_REF_GetRefCurrent( int Card, int Module, int *RefCurrent );
_75C3FUNC int CPCI75C3_REF_GetRefOverCurrent( int Card, int Module, BOOL *RefOverCurrent );
/*internal use only */
_75C3FUNC int CPCI75C3_REF_DCCal_Enable( int Card, int Module, unsigned short Enable);
#ifdef __cplusplus
}
#endif
/*internal library function*/
int CPCI75C3_REF_CheckCardModule(int Card, int Module);
#endif
