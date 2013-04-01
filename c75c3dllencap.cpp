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
