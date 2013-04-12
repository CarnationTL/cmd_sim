#ifndef C75C3DLLENCAP_H
#define C75C3DLLENCAP_H
#include <Windows.h>
#include "C75C3Expls.h"
#include <QString>
#include "c75c3funcp.h"


class C75C3DllEncap
{
private:
    C75C3DllEncap();
    ~C75C3DllEncap();
    static C75C3DllEncap * C75C3;
    static HINSTANCE hdll;
public:
    static C75C3DllEncap *getInst() {
		static C75C3DllEncap instC75;
		return &instC75;
	}
    int loadDll() {
        if(hdll == NULL) {
#ifdef QT_NO_DEBUG
            LPCWSTR strR = L"CPCI75C3Dll";
            hdll = LoadLibrary(strR);
#else
			//not dis...
            LPCWSTR strD = L"CPCI75C3Dll";
            hdll = LoadLibrary(strD);
#endif
            return 0;
        }
        return 1;
    }
    bool isloaded() {
        if(hdll != NULL) {
            return true;
        } else
            return false;
    }
    FPTR_OPEN getOpen();
    FPTR_CLOSE getClose();
    FPTR_GET_CH_POS getChPos();
    FPTR_GET_CHPW_STA getPwStat();
};

#endif // C75C3DLLENCAP_H
