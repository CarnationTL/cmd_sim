#include "c75c3dllencap.h"


HINSTANCE C75C3DllEncap::hdll = NULL;
C75C3DllEncap::C75C3DllEncap() {

}

C75C3DllEncap::~C75C3DllEncap() {

}


FPTR_OPEN C75C3DllEncap::getOpen() {
    if(hdll != NULL) {
        FPTR_OPEN ptrs = (FPTR_OPEN)(GetProcAddress(hdll, FSTR_Open));
		if(ptrs != NULL) {
			return (FPTR_OPEN)(GetProcAddress(hdll, FSTR_Open));
		}
    }
	return NULL;
}


FPTR_CLOSE C75C3DllEncap::getClose() {
    if(hdll != NULL) {
        return (FPTR_CLOSE)(GetProcAddress(hdll, FSTR_Close));
    }
    return NULL;
}

/**
  get pos
*/
FPTR_GET_CH_POS C75C3DllEncap::getChPos() {
   if(hdll != NULL) {
       return (FPTR_GET_CH_POS)GetProcAddress(hdll, FSTR_DL_GetPosition);
   }
   return NULL;
}

