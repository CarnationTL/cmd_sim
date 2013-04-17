#ifndef C75C3FUNCP_H
#define C75C3FUNCP_H
/**
  the func pointer of 75c3dll
**/


typedef int(* FPTR_OPEN)(int);
typedef int(* FPTR_CLOSE)(int);

typedef void(* FPTR_INIT)(void);
typedef int(* FPTR_GET_DEVCNT)(void);
typedef int(* FPTR_GET_BRDREADY)(int, unsigned short);

typedef int(* FPTR_GET_ACU_POS)(int, int, int, double);
typedef int(* FPTR_SET_CH_POS)(int, int, int, double*);

typedef int(* FPTR_GET_ACT_CHS)(int, int, int, unsigned short*);
typedef int(* FPTR_SET_ACT_CHS)(int, int, int, unsigned short);

typedef int(* FPTR_GET_BIT_STA)(int, int, int, unsigned short*);

typedef int(* FPTR_GET_DLCHPW_STA)(int, int, int, unsigned short*);
typedef int(* FPTR_SET_DLCHPW_STA)(int, int, int, unsigned short);

typedef int(* FPTR_GET_CHOP_STA)(int, int, int, unsigned short*);
typedef int(* FPTR_SET_CHOP_STA)(int, int, int, unsigned short);

typedef int(* FPTR_GET_PLL_STA)(int, int, int, unsigned short*);
typedef int(* FPTR_SET_PLL_STA)(int, int, int, unsigned short);

typedef int(* FPTR_GET_CH_POS)(int, int, int, int, double*);

typedef int(* FPTR_GET_OB_REFEQ)(int, int, unsigned int*);
typedef int(* FPTR_SET_OB_REFEQ)(int, int, unsigned int);
typedef int(* FPTR_GET_OB_REFVOL)(int, int, double*);
typedef int(* FPTR_SET_OB_REFVOL)(int, int, double);

typedef int(* FPTR_SET_WIREMODE)(int, int, int, unsigned short);
typedef int(* FPTR_GET_WIREMODE)(int, int, int, unsigned short*);

typedef int(* FPTR_SET_VLL_OPTMOD)(int, int, int, unsigned short);
typedef int(* FPTR_GET_VLL_OPTMOD)(int, int, int, unsigned short*);

typedef int(* FPTR_SET_REFLOSS_THOLD)(int, int, int, double);
typedef int(* FPTR_GET_REFLOSS_THOLD)(int, int, int, double*);
typedef int(* FPTR_SET_SIGLOSS_THOLD)(int, int, int, double);
typedef int(* FPTR_GET_SIGLOSS_THOLD)(int, int, int, double*);

typedef int(* FPTR_SET_REF_VOL)(int, int, double);     //set card ref not model..
typedef int(* FPTR_GET_REF_VOL)(int, int, double*);
typedef int(* FPTR_SET_REF_FEQ)(int, int, unsigned int);
typedef int(* FPTR_GET_REF_FEQ)(int, int, unsigned int*);


typedef int(* FPTR_GET_REF_PW_EN)(int, int, unsigned short*);
typedef int(* FPTR_SET_REF_PW_EN)(int, int, unsigned short);

typedef int(* FPTR_GET_REF_CUR)(int, int, int*);

//#define FSTR_REF_GetRefFreq                  "_CPCI75C3_REF_GetRefFreq@12"
//#define FSTR_REF_GetRefFreqWord              "_CPCI75C3_REF_GetRefFreqWord@12"
//#define FSTR_REF_GetRefOverCurrent           "_CPCI75C3_REF_GetRefOverCurrent@12"
//#define FSTR_REF_GetRefTemperature           "_CPCI75C3_REF_GetRefTemperature@12"
//#define FSTR_REF_GetRefVoltage               "_CPCI75C3_REF_GetRefVoltage@12"
//#define FSTR_REF_GetRefVoltageWord           "_CPCI75C3_REF_GetRefVoltageWord@12"
//#define FSTR_REF_PowerSupplyEnable           "_CPCI75C3_REF_PowerSupplyEnable@12"
//#define FSTR_REF_SetRefFreq                  "_CPCI75C3_REF_SetRefFreq@12"
//#define FSTR_REF_SetRefFreqWord              "_CPCI75C3_REF_SetRefFreqWord@12"
//#define FSTR_REF_SetRefVoltage               "_CPCI75C3_REF_SetRefVoltage@16"
//#define FSTR_REF_SetRefVoltageWord           "_CPCI75C3_REF_SetRefVoltageWord@12"
//#
#endif // C75C3FUNCP_H
