#include "squdata.h"

SquData::SquData(double amp, double time, double dutyc) :
    QwtSyntheticPointData(100)
{
    _amp = amp;
    _time = time;
    _dutyc = dutyc;
    _feq = 1.0 / _time;
}


double SquData::y(double x) const {
    double	phase_i = fmod((360.0 * _feq * x), 360.0);
    //set the dutyCycle of Square wave
    return (phase_i / 360.0 <= _dutyc / 100.0 ? _amp: -_amp);
}

