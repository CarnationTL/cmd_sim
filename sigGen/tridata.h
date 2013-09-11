#ifndef TRIDATA_H
#define TRIDATA_H

#include <Qwt/qwt_point_data.h>


#define PI 3.1415927
#define D_PTS 256
class TriData : public QwtSyntheticPointData
{
public:
    TriData(double amp, double time, double cycles);
    virtual double y (double x) const;
private:
    double _amp;
    double _time;
    double _feq;
    double _cycles;
};

#endif // TRIDATA_H
