#include "tridata.h"

TriData::TriData(double amp, double time) :
    QwtSyntheticPointData(D_PTS)
{
    _amp = amp;
    _time = time;
    _feq = 1.0 / _time;
}

double TriData::y(double x) const {
    double	phase_i = fmod((360.0 * _feq * x), 360.0);
    double	percentPeriod = phase_i / 360.0;
    double	dat = _amp * 4.0 * percentPeriod;

    if(percentPeriod <= 0.25)
    {
        return dat;
    }
    else if(percentPeriod <= 0.75)
    {
        return (2.0 * _amp - dat);
    }
    else
    {
        return (dat - 4.0 * _amp);
    }
}

