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
typedef int(* FPTR_GET_ACT_CHS)(int, int, int, unsigned short*);
typedef int(* FPTR_GET_BIT_STA)(int, int, int, unsigned short*);
typedef int(* FPTR_GET_CHPW_STA)(int, int, int, unsigned short*);
typedef int(* FPTR_GET_CHOP_STA)(int, int, int, unsigned short*);
typedef int(* FPTR_GET_PLL_STA)(int, int, int, unsigned short*);
typedef int(* FPTR_GET_CH_POS)(int, int, int, int, double*);
typedef int(* FPTR_GET_OB_REFEQ)(int, int, unsigned int*);
typedef int(* FPTR_SET_WIREMODE)(int, int, int, unsigned short);
typedef int(* FPTR_SET_VLL_OPTMOD)(int, int, int, unsigned short);
typedef int(* FPTR_SET_REF_THOLD)(int, int, int, double);

#endif // C75C3FUNCP_H
