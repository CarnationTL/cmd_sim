#include "c75c3dllencap.h"

#define GET_FP(hdll, TYPE, STR, ret) do { \
    if(hdll != NULL) { \
     TYPE _tp = (TYPE)(GetProcAddress(hdll, STR)); \
     ret = _tp;\
    } \
}while(0)

HINSTANCE C75C3DllEncap::hdll = NULL;
C75C3DllEncap::C75C3DllEncap() {

}

C75C3DllEncap::~C75C3DllEncap() {

}

/**
  init the dll res
*/
FPTR_INIT C75C3DllEncap::initbrd() {
    FPTR_INIT _ret = NULL;
    GET_FP(hdll, FPTR_INIT, FSTR_Init, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}


FPTR_OPEN C75C3DllEncap::getOpen() {
#if 0
    if(hdll != NULL) {
        FPTR_OPEN ptrs = (FPTR_OPEN)(GetProcAddress(hdll, FSTR_Open));
		if(ptrs != NULL) {
			return (FPTR_OPEN)(GetProcAddress(hdll, FSTR_Open));
		}
    }
	return NULL;
#endif
    FPTR_OPEN get_ret;
    GET_FP(hdll, FPTR_OPEN, FSTR_Open, get_ret);
    if(get_ret != NULL) {
        return get_ret;
    }
    return NULL;
}

FPTR_OPEN C75C3DllEncap::getOpenMacro() {
    FPTR_OPEN get_ret;
    GET_FP(hdll, FPTR_OPEN, FSTR_Open, get_ret);
    if(get_ret != NULL) {
        return get_ret;
    }
    return NULL;
}


FPTR_CLOSE C75C3DllEncap::getClose() {
#if 0
    if(hdll != NULL) {
        return (FPTR_CLOSE)(GetProcAddress(hdll, FSTR_Close));
    }
    return NULL;
#endif
    FPTR_CLOSE _ret = NULL;
    GET_FP(hdll, FPTR_CLOSE, FSTR_Close, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}

FPTR_GET_DEVCNT C75C3DllEncap::getDevcnt() {
    FPTR_GET_DEVCNT _ret = NULL;
    GET_FP(hdll, FPTR_GET_DEVCNT, FSTR_GetDevCnt, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}


/**
  for every brd...
*/
FPTR_GET_BRDREADY C75C3DllEncap::getBrdReady() {
    FPTR_GET_BRDREADY _ret = NULL;
    GET_FP(hdll, FPTR_GET_BRDREADY, FSTR_GetBoardReady, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}

/**
  get pos
*/
FPTR_GET_CH_POS C75C3DllEncap::getChPos() {
#if 0
   if(hdll != NULL) {
       return (FPTR_GET_CH_POS)GetProcAddress(hdll, FSTR_DL_GetPosition);
   }
   return NULL;
#endif
   FPTR_GET_CH_POS _ret = NULL;
   GET_FP(hdll, FPTR_GET_CH_POS, FSTR_DL_GetPosition, _ret);
   if(_ret != NULL) {
       return _ret;
   }
   return NULL;
}

FPTR_SET_CH_POS C75C3DllEncap::setChPos() {
    FPTR_SET_CH_POS _ret = NULL;
    GET_FP(hdll, FPTR_SET_CH_POS, FSTR_DL_SetPosition, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}

/**
  acu pos for bk use
*/
FPTR_GET_ACU_POS C75C3DllEncap::getChAcuPos() {
    FPTR_GET_ACU_POS _ret = NULL;
    GET_FP(hdll, FPTR_GET_ACU_POS, FSTR_DL_GetAccumPosition, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}

/**
  the pw status for DL model this is fake one ^V^
*/
FPTR_GET_CHPW_STA C75C3DllEncap::getDLPwStat() {
#if 0
    if(hdll != NULL) {
        return (FPTR_GET_CHPW_STA)GetProcAddress(hdll, FSTR_DL_GetPowerSupplyState);
    }
    return NULL;
#endif
    FPTR_GET_CHPW_STA _ret = NULL;
    GET_FP(hdll, FPTR_GET_CHPW_STA, FSTR_DL_GetPowerSupplyState, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}

/**
  indicate the ch output or not..
*/
FPTR_GET_CHOP_STA C75C3DllEncap::getChOPStat() {
    FPTR_GET_CHOP_STA _ret = NULL;
    GET_FP(hdll, FPTR_GET_CHOP_STA, FSTR_DL_GetChanOutputState, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}

FPTR_GET_OB_REFEQ C75C3DllEncap::getOBRefeq() {
    FPTR_GET_OB_REFEQ _ret = NULL;
    GET_FP(hdll, FPTR_GET_OB_REFEQ, FSTR_DL_GetOnBrdRefFreq, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}

FPTR_SET_OB_REFEQ C75C3DllEncap::setOBRefeq() {
    FPTR_SET_OB_REFEQ _ret = NULL;
    GET_FP(hdll, FPTR_SET_OB_REFEQ, FSTR_DL_SetOnBrdRefFreq, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}

FPTR_GET_OB_REFVOL C75C3DllEncap::getOBRefVol() {
    FPTR_GET_OB_REFVOL _ret = NULL;
    GET_FP(hdll, FPTR_GET_OB_REFVOL, FSTR_DL_GetOnBrdRefVoltage, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}


FPTR_SET_OB_REFVOL C75C3DllEncap::setOBRefVol() {
    FPTR_SET_OB_REFVOL _ret = NULL;
    GET_FP(hdll, FPTR_SET_OB_REFVOL, FSTR_DL_SetOnBrdRefVoltage, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}

/**
  four or two.
*/
FPTR_SET_WIREMODE C75C3DllEncap::setWireMode() {
    FPTR_SET_WIREMODE _ret = NULL;
    GET_FP(hdll, FPTR_SET_WIREMODE, FSTR_DL_SetWireMode, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}


/**
  the vll mode relate with warp pw line
*/
FPTR_SET_VLL_OPTMOD C75C3DllEncap::setVllOptMode() {
    FPTR_SET_VLL_OPTMOD _ret = NULL;
    GET_FP(hdll, FPTR_SET_VLL_OPTMOD, FSTR_DL_SetVllOutputMode, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}

FPTR_GET_VLL_OPTMOD C75C3DllEncap::getVllOptMode() {
    FPTR_GET_VLL_OPTMOD _ret = NULL;
    GET_FP(hdll, FPTR_GET_VLL_OPTMOD, FSTR_DL_GetVllOutputMode, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}


FPTR_GET_ACT_CHS C75C3DllEncap::getActChs() {
    FPTR_GET_ACT_CHS _ret = NULL;
    GET_FP(hdll, FPTR_GET_ACT_CHS, FSTR_DL_GetActiveChannel, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}

FPTR_SET_ACT_CHS C75C3DllEncap::setActChs() {
    FPTR_SET_ACT_CHS _ret = NULL;
    GET_FP(hdll, FPTR_SET_ACT_CHS, FSTR_DL_SetActiveChannel, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}

FPTR_GET_BIT_STA C75C3DllEncap::getBIT() {
    FPTR_GET_BIT_STA _ret = NULL;
    GET_FP(hdll, FPTR_GET_BIT_STA, FSTR_DL_GetBITStatus, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}
