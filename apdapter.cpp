#include "apdapter.h"
#include <qmath.h>
#include <cmddefs.h>
Apdapter::Apdapter(QObject *parent) :
    QObject(parent)
{
}

Apdapter::Apdapter(double max_phyval, double min_phyval, QObject *parent)
    :_maxPhyval(max_phyval), _minPhyval(min_phyval), QObject(parent) {

}

double Apdapter::maxPhyval() const {
    return _maxPhyval;
}

void Apdapter::setMaxPhyval(double maxPhyval) {
    _maxPhyval = maxPhyval;
}



double Apdapter::minPhyval() const {
    return _minPhyval;
}

void Apdapter::setMinPhyval(double minPhyval) {
    _minPhyval = minPhyval;
}


double Apdapter::minElcval() const {
    return _minElcval;
}

void Apdapter::setMinElcval(double minElcval) {
    _minElcval = minElcval;
}

double Apdapter::maxElcval() const {
    return _maxElcval;
}

void Apdapter::setMaxElcval(double maxElcval) {
    _maxElcval = maxElcval;
}


/**
   convertion..
*/
double Apdapter::genStepval() {
    double rangePval = qFabs(_maxPhyval) + qFabs(_minPhyval);
    double rangeEval = qFabs(_maxElcval) + qFabs(_minElcval);
    if(rangePval <= 0 || rangeEval <= 0) {
        return (double)EXE_FAIL;
    } else {
        return (double)(rangeEval / rangePval);
    }
    return (double)EXE_FAIL;
}
