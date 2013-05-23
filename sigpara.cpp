#include "sigpara.h"
#include <qmath.h>
SigPara::SigPara(QObject *parent) :
    QObject(parent) {
}

int SigPara::createSigPara(int type) {
    switch ( type ) {
        case T_SINE:

            break;

        case T_SAW:	
            break;

        case T_TRI:	
            break;

        case T_SQUARE:	
            break;

        case T_SP:	
            break;
        default:	
            break;
    }				/* -----  end switch  ----- */
}



