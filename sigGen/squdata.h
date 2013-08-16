#ifndef SQUDATA_H
#define SQUDATA_H
#include <Qwt/qwt_point_data.h>
class SquData : public QwtSyntheticPointData
{
public:
    SquData(double amp, double time, double dutyc);
private:
    double _amp;
    double _time;
    double _dutyc;
};

#endif // SQUDATA_H
