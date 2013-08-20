#ifndef SQUDATA_H
#define SQUDATA_H
#include <Qwt/qwt_point_data.h>

#define PI 3.1415927
#define D_PTS 256

class SquData : public QwtSyntheticPointData
{
public:
    SquData(double amp, double time, double dutyc);
    virtual double y( double x ) const;
private:
    double _amp;
    double _time;
    double _dutyc;
    double _feq;
};

#endif // SQUDATA_H
