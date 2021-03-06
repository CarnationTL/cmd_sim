#ifndef C75C3DLLENCAP_H
#define C75C3DLLENCAP_H

#include <qglobal.h>
#if defined(Q_OS_WIN)
#include <Windows.h>
#endif


#include "C75C3Expls.h"
#include <QString>
#include "c75c3funcp.h"


class C75C3DllEncap
{
private:
    C75C3DllEncap();
    ~C75C3DllEncap();
    static C75C3DllEncap * C75C3;
#if defined(Q_OS_WIN)
    static HINSTANCE hdll;
#elif defined(Q_OS_LINUX)
    static int hdll;
#elif defined(Q_OS_MACX)
    static int hdll;
#endif

public:
    static C75C3DllEncap *getInst() {
        static C75C3DllEncap instC75;
        return &instC75;
    }

#if defined(Q_OS_WIN)

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
#elif defined(Q_OS_LINUX)
    int loadDll() {
        hdll = 0;
        return 0;
    }

#elif defined(Q_OS_DARWIN)
    int loadDll() {
        hdll = 0;
        return 0;
    }
#endif





    bool isloaded() {
#if defined(Q_OS_WIN)
        if(hdll != NULL) {
            return true;
        } else
            return false;
#elif defined(Q_OS_LINUX)
        if(hdll != 0) {
            return true;
        } else
            return false;
#elif defined(Q_OS_DARWIN)
        if(hdll != 0) {
            return true;
        } else
            return false;
#endif
     
    }

    FPTR_INIT initbrd();
    FPTR_OPEN getOpen();
    FPTR_OPEN getOpenMacro();
    FPTR_CLOSE getClose();
    FPTR_GET_DEVCNT getDevcnt();
    FPTR_GET_BRDREADY getBrdReady();
    FPTR_GET_CH_POS getChPos();
    FPTR_SET_CH_POS setChPos();
    FPTR_GET_ACU_POS getChAcuPos();
    FPTR_GET_DLCHPW_STA getDLPwStat();
    FPTR_SET_DLCHPW_STA setDLPwStat();

    FPTR_GET_CHOP_STA getChOPStat();
    FPTR_SET_CHOP_STA setChOPStat();

    FPTR_GET_OB_REFEQ getOBRefeq();
    FPTR_SET_OB_REFEQ setOBRefeq();
    FPTR_GET_OB_REFVOL getOBRefVol();
    FPTR_SET_OB_REFVOL setOBRefVol();

    FPTR_SET_WIREMODE setWireMode();
    FPTR_GET_WIREMODE getWireMode();

    FPTR_SET_VLL_OPTMOD setVllOptMode();
    FPTR_GET_VLL_OPTMOD getVllOptMode();

    FPTR_SET_SIGLOSS_THOLD setSigLossTH();
    FPTR_GET_SIGLOSS_THOLD getSigLossTH();
    FPTR_SET_REFLOSS_THOLD setRefLossTH();
    FPTR_GET_REFLOSS_THOLD getRefLossTH();


    FPTR_SET_REF_FEQ setRefFeq();
    FPTR_GET_REF_FEQ getRefFeq();
    FPTR_SET_REF_VOL setRefVol();
    FPTR_GET_REF_VOL getRefVol();

    FPTR_GET_ACT_CHS getActChs();
    FPTR_SET_ACT_CHS setActChs();

    FPTR_GET_REF_PW_EN getPWenable();
    FPTR_SET_REF_PW_EN setPWenable();

    FPTR_GET_REF_CUR getRefCurrent();
    FPTR_GET_BIT_STA getBIT();   //bit for dl model

    FPTR_GET_PLL_STA getPllSTA();
    FPTR_SET_PLL_STA setPllSTA();

	FPTR_SET_EXPREF_VOL setexpRefVol();
	FPTR_GET_EXPREF_VOL getexpEefVol();
};

#endif // C75C3DLLENCAP_H
