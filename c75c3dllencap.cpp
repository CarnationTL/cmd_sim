#include "c75c3dllencap.h"

#if defined(Q_OS_WIN)

#define GET_FP(hdll, TYPE, STR, ret) do { \
    if(hdll != NULL) { \
     TYPE _tp = (TYPE)(GetProcAddress(hdll, STR)); \
     ret = _tp;\
    } \
}while(0)

#elif defined(Q_OS_LINUX)

#define GET_FP(hdll, TYPE, STR, ret) do { \
    if(hdll != 0) { \
    ret = 0; \
    ; \
    } \
}while(0)

#elif defined(Q_OS_DARWIN)

#define GET_FP(hdll, TYPE, STR, ret) do { \
    if(hdll != 0) { \
    ret = 0; \
    ; \
    } \
}while(0)

#endif





#if defined(Q_OS_WIN)
HINSTANCE C75C3DllEncap::hdll = NULL;
#elif defined(Q_OS_LINUX)
int C75C3DllEncap::hdll = 0;
#elif defined(Q_OS_DARWIN)
int C75C3DllEncap::hdll = 0;
#endif

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
FPTR_GET_DLCHPW_STA C75C3DllEncap::getDLPwStat() {
#if 0
    if(hdll != NULL) {
        return (FPTR_GET_CHPW_STA)GetProcAddress(hdll, FSTR_DL_GetPowerSupplyState);
    }
    return NULL;
#endif
    FPTR_GET_DLCHPW_STA _ret = NULL;
    GET_FP(hdll, FPTR_GET_DLCHPW_STA, FSTR_DL_GetPowerSupplyState, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}

FPTR_SET_DLCHPW_STA C75C3DllEncap::setDLPwStat() {
    FPTR_SET_DLCHPW_STA _ret = NULL;
    GET_FP(hdll, FPTR_SET_DLCHPW_STA, FSTR_DL_SetPowerSupplyState, _ret);
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

FPTR_SET_CHOP_STA C75C3DllEncap::setChOPStat() {
    FPTR_SET_CHOP_STA _ret = NULL;
    GET_FP(hdll, FPTR_SET_CHOP_STA, FSTR_DL_SetChanOutputState, _ret);
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

FPTR_GET_WIREMODE C75C3DllEncap::getWireMode() {
    FPTR_GET_WIREMODE _ret = NULL;
    GET_FP(hdll, FPTR_GET_WIREMODE, FSTR_DL_GetWireMode, _ret);
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

/**
  thresh hold..for input sig
*/
FPTR_SET_SIGLOSS_THOLD C75C3DllEncap::setSigLossTH() {
    FPTR_SET_SIGLOSS_THOLD _ret = NULL;
    GET_FP(hdll, FPTR_SET_SIGLOSS_THOLD, FSTR_DL_SetSigLossThreshold, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}

FPTR_GET_SIGLOSS_THOLD C75C3DllEncap::getSigLossTH() {
    FPTR_GET_SIGLOSS_THOLD _ret = NULL;
    GET_FP(hdll, FPTR_GET_SIGLOSS_THOLD, FSTR_DL_GetSigLossThreshold, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}

FPTR_SET_REFLOSS_THOLD C75C3DllEncap::setRefLossTH() {
    FPTR_SET_REFLOSS_THOLD _ret = NULL;
    GET_FP(hdll, FPTR_SET_REFLOSS_THOLD, FSTR_DL_SetRefLossThreshold, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}

FPTR_GET_REFLOSS_THOLD C75C3DllEncap::getRefLossTH() {
    FPTR_GET_REFLOSS_THOLD _ret = NULL;
    GET_FP(hdll, FPTR_GET_REFLOSS_THOLD, FSTR_DL_GetRefLossThreshold, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}

#if 0
/**
  this pw supply for ref model
*/
FPTR_SET_PW_SUPPLY C75C3DllEncap::setPWsupply() {
    FPTR_SET_PW_SUPPLY _ret = NULL;
    GET_FP(hdll, FPTR_SET_PW_SUPPLY, FSTR_DL_SetPowerSupplyState, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}

#endif

/**
  set the refmode feq and vol (NOT THE DL MODEL!!)
*/
FPTR_SET_REF_FEQ C75C3DllEncap::setRefFeq() {
    FPTR_SET_REF_FEQ _ret = NULL;
    GET_FP(hdll, FPTR_SET_REF_FEQ, FSTR_REF_SetRefFreq, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}

FPTR_GET_REF_FEQ C75C3DllEncap::getRefFeq() {
    FPTR_GET_REF_FEQ _ret = NULL;
    GET_FP(hdll, FPTR_GET_REF_FEQ, FSTR_REF_GetRefFreq, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}

FPTR_SET_REF_VOL C75C3DllEncap::setRefVol() {
    FPTR_SET_REF_VOL _ret = NULL;
    GET_FP(hdll, FPTR_SET_REF_VOL, FSTR_REF_SetRefVoltage, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}

FPTR_GET_REF_VOL C75C3DllEncap::getRefVol() {
    FPTR_GET_REF_VOL _ret = NULL;
    GET_FP(hdll, FPTR_GET_REF_VOL, FSTR_REF_GetRefVoltage, _ret);
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

/**
  PW supply enable.
*/
FPTR_GET_REF_PW_EN C75C3DllEncap::getPWenable() {
    FPTR_GET_REF_PW_EN _ret = NULL;
    GET_FP(hdll, FPTR_GET_REF_PW_EN, FSTR_REF_GetPowerSupplyEnable, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}

FPTR_SET_REF_PW_EN C75C3DllEncap::setPWenable() {
    FPTR_SET_REF_PW_EN _ret = NULL;
    GET_FP(hdll, FPTR_SET_REF_PW_EN, FSTR_REF_PowerSupplyEnable, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}


FPTR_GET_REF_CUR C75C3DllEncap::getRefCurrent() {
    FPTR_GET_REF_CUR _ret = NULL;
    GET_FP(hdll, FPTR_GET_REF_CUR, FSTR_REF_GetRefCurrent, _ret);
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

/**
  PLL sta sta
*/
FPTR_GET_PLL_STA C75C3DllEncap::getPllSTA() {
    FPTR_GET_PLL_STA _ret = NULL;
    GET_FP(hdll, FPTR_GET_PLL_STA, FSTR_DL_GetPLLStatus, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}

#if 0
/**
 Set PLL status...
*/
FPTR_SET_PLL_STA C75C3DllEncap::setPllSTA() {
    FPTR_SET_PLL_STA _ret = NULL;
    GET_FP(hdll, FPTR_SET_PLL_STA, FSTR_DL_SetPLLStatus, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}
#endif

/* EXP SET */
FPTR_SET_EXPREF_VOL C75C3DllEncap::setexpRefVol() {
	FPTR_SET_EXPREF_VOL _ret = NULL;
	GET_FP(hdll, FPTR_SET_EXPREF_VOL, FSTR_DL_SetExpRefVoltInput, _ret);
	if (_ret != NULL) {
		return _ret;
	}
	return NULL;
}

FPTR_GET_EXPREF_VOL C75C3DllEncap::getexpEefVol() {
	FPTR_GET_EXPREF_VOL _ret = NULL;
	GET_FP(hdll, FPTR_GET_EXPREF_VOL, FSTR_DL_GetExpRefVoltInput, _ret);
	if (_ret != NULL) {
		return _ret;
	}
	return NULL;
}

