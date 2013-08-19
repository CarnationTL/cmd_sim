#ifndef TRIDATA_H
#define TRIDATA_H

#include <Qwt/qwt_point_data.h>
class TriData : public QwtSyntheticPointData
{
public:
    TriData(double amp, double time);
    virtual double y (double x) const;
private:
    double _amp;
    double _time;
    double _feq;
};

#endif // TRIDATA_H
