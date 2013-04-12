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


FPTR_GET_CHPW_STA C75C3DllEncap::getPwStat() {
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


FPTR_GET_CHOP_STA C75C3DllEncap::getChOPStat() {
    FPTR_GET_CHOP_STA _ret;
    GET_FP(hdll, FPTR_GET_CHOP_STA, FSTR_DL_GetChanOutputState, _ret);
    if(_ret != NULL) {
        return _ret;
    }
    return NULL;
}

