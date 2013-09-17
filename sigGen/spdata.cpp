#include "spdata.h"

SpData::SpData(double amp, double time) :
    QwtSyntheticPointData(D_PTS){
    _amp = amp;
    _time = time;
}

//need resize plot outside
double SpData::y(double x) const {
    return _amp;
}


