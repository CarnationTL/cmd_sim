#include "sinusdata.h"

SinusData::SinusData(double amp, double time, double cycles) :
    QwtSyntheticPointData(D_PTS)

{
    _amp = amp;
    _time = time;
    _cycles = cycles;
    _feq = _cycles / _time;
}

double SinusData::y (double x) const {
    return _amp * sin(PI / 180.0 * (360.0 * _feq * x));
}
