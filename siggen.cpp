#include "siggen.h"

SigGen::SigGen(QObject *parent) :
    QObject(parent) {
}


/* Sin */
int SineGen::genData(Sig &para) {
    Sine *p = NULL;
    p = dynamic_cast <Sine*> (&para);
    if(p != NULL) {
        p->Amp();
        p->Feq();
    }
    /* gen sin data */
    return 0;
}

QList<double> SineGen::Data() const {
    return _data;
}


/* Tri */
int TriGen::genData(Sig &para) {
    Tri *p = dynamic_cast <Tri*>(&para);
    if(p != NULL) {
        p->Amp();
        p->Feq();
    }
    return 0;
}

QList<double> TriGen::Data() const {
    return _data;
}

/* Saw */
int SawGen::genData(Sig &para) {
    Saw *p = dynamic_cast <Saw*>(&para);
    if(p != NULL) {
        p->Amp();
        p->Feq();
    }
    return 0;
}

QList<double> SawGen::Data() const {
    return _data;
}

/* Sp */
int SpGen::genData(Sig &para) {
    Sp *p = dynamic_cast <Sp*>(&para);
    if(p != NULL) {
        p->Amp();                               /* sp class only have value set. */
    }
    return 0;
}

QList<double> SpGen::Data() const {
    return _data;
}

/* Square */
int SquareGen::genData(Sig &para) {
    Square *p = dynamic_cast <Square*>(&para);
    if(p != NULL) {
        p->Amp();
        p->Feq();
        p->Duty();
    }
    return 0;
}

QList<double> SquareGen::Data() const {
    return _data;
}
