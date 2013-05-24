#include "siggen.h"

SigGen::SigGen(QObject *parent) :
    QObject(parent) {
}


/* Sin */
int SineGen::genData(SigPara &para) {
    SinePara *p = new SinePara(1, 2);
#if 0
    SinePara *p = NULL;
    p = dynamic_cast <SinePara*> (&para);
    if(p != NULL) {
        p->createSigPara(1, 2);
    }
#endif
    return 0;
}

QList<double> SineGen::Data() const {
    return _data;
}


/* Tri */
int TriGen::genData(SigPara &para) {
    return 0;
}

QList<double> TriGen::Data() const {
    return _data;
}

/* Saw */
int SawGen::genData(SigPara &para) {
    return 0;
}

QList<double> SawGen::Data() const {
    return _data;
}

/* Sp */
int SpGen::genData(SigPara &para) {
    return 0;
}

QList<double> SpGen::Data() const {
    return _data;
}

/* Square */
int SquareGen::genData(SigPara &para) {
    return 0;
}

QList<double> SquareGen::Data() const {
    return _data;
}
