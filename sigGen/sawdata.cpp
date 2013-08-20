#include "sawdata.h"

SawData::SawData(double amp, double time) :
    QwtSyntheticPointData(D_PTS)

{
    _amp = amp;
    _time = time;
    _feq = 1.0 / _time;
}


double SawData::y (double x) const {
    double t = 0;
    double *phase = &t;
    double	phase_i = fmod((*phase + 360.0 * _feq * x), 360.0);
    double	percentPeriod = phase_i / 360.0;
    double	dat = _amp * 2.0 * percentPeriod;
    return (percentPeriod <= 0.5 ? dat : dat - 2.0 * _amp);
}

