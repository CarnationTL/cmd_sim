#ifndef SIGDATA_H
#define SIGDATA_H

#include <QObject>

//#include <Qwt/qwt_plot_curve.h>
//#include <Qwt/qwt_symbol.h>
//#include <Qwt/qwt_plot_marker.h>
//#include <Qwt/qwt_painter.h>
//#include <Qwt/qwt_plot_grid.h>

#include <Qwt/qwt_point_data.h>
#include <Qwt/qwt_series_data.h>
#include <Qwt/qwt_plot.h>
#define D_PTS 256

class SinusData: public QwtSyntheticPointData
{
public:
    SinusData(double amp, double time):
        QwtSyntheticPointData( D_PTS )
    {
        _amp = amp;
        _feq = 1.0 / time;
    }
    virtual double y( double x ) const
    {
        return _amp * sin(PI / 180.0 * (360.0 * _feq * x));
        //return (_amp * qSin( x ));
    }
private:
    double _amp;
    double _feq;
};


class TriData: public QwtSyntheticPointData
{
public:
    TriData(double amp, double time):
        QwtSyntheticPointData( D_PTS )
    {
        _amp = amp;
        _feq = 1.0 / time;
    }
    virtual double y( double x ) const {
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
private:
    double _amp;
    double _feq;
};

class SawData: public QwtSyntheticPointData
{
public:
    SawData(double amp, double time):
        QwtSyntheticPointData( D_PTS )
    {
        _amp = amp;
        _feq = 1.0 / time;
    }
    virtual double y( double x ) const {
#if 1
        double t = 0;
        double *phase = &t;
        double	phase_i = fmod((*phase + 360.0 * _feq * x), 360.0);
		double	percentPeriod = phase_i / 360.0;
        double	dat = _amp * 2.0 * percentPeriod;
        return (percentPeriod <= 0.5 ? dat : dat - 2.0 * _amp);
#endif
    }
private:
    double _amp;
    double _feq;
};


class SquData: public QwtSyntheticPointData
{
public:
    SquData(double amp, double duc, double time):
        QwtSyntheticPointData( D_PTS ) {
        _amp = amp;
        _dutyc = duc;
        _feq = 1.0 / time;
    }
    virtual double y( double x ) const {
        double	phase_i = fmod((360.0 * _feq * x), 360.0);
        //set the dutyCycle of Square wave
        return (phase_i / 360.0 <= _dutyc / 100.0 ? _amp: -_amp);
       // *phase = fmod(*phase + frequency * 360.0 * numElements, 360.0);
    }
private:
    double _amp;
    double _dutyc;
    double _feq;
};

class CurveDataN
{
public:
    CurveDataN(int size) {
        _t_size = size;
    }
    ~CurveDataN() {

    }

    void appendP(double x, double y) {
        _points << QPointF(x, y);
    }
    QPolygonF getpts() {
        return _points;
    }

    QPolygonF genWriteData() {
        QPolygonF ret;
        if(_t_size > 0) {
            int pcnt = _points.count ();
           // double stpval = _t_size / (double)pcnt;
            double stpval = 0.0;// = (double)pcnt / (double)_t_size;
            double segcnt = (double)_t_size / (double)pcnt;
            double bs = 0.0;
            double s = 0;
            double pdx = 0.0;
            QPointF pre;
            QPointF nxt;
            double k = 0.0;
            double shift;
            double dx = 0.0, dy = 0.0;

            for(int i = 0, j = 1; i < pcnt; i++, j++) {
                //Gen points
                if(i != pcnt - 1) {
                    pre = _points.at (i);
                    nxt = _points.at (j);
                } else {
                    //last
                    pre = _points.at (pcnt - 2);
                    nxt = _points.at (pcnt - 1);
                }
                dx = nxt.x () - pre.x ();
                dy = nxt.y () - pre.y ();
                if(dx != 0.0) {
                    k = dy / dx;
                    shift = nxt.y () - k * nxt.x ();
                    bs += segcnt;
                    stpval = dx / segcnt;
                    pdx += dx;
                    for(; s < pdx ; s+=stpval) {
                        ret << QPointF(s, k * s + shift);
                    }
                }

            }
            return ret;
        }
        ret.clear ();
        return ret;
    }
    double getYRgn() {
        int len = _points.count ();
        double ymax = _points.at (0).y ();
        double ymin = _points.at (0).y ();
        for(int i = 1; i < len; i++) {
            if(ymax <= _points.at (i).y ()) {
                ymax = _points.at (i).y ();
            }
            if(ymin >= _points.at (i).y ()) {
                ymin = _points.at (i).y ();
            }
        }
        ymax = fabs (ymax);
        ymin = fabs (ymin);
        if(ymax > ymin) {
            return ymax;
        } else {
            return ymin;
        }
    }
    double getXRgn() {
        int len = _points.count ();
        double xmax = _points.at (0).x ();
        for(int i = 0; i < len; i++) {
            if(xmax <= _points.at (i).x ()) {
                xmax = _points.at (i).x ();
            }
        }
        return xmax;
    }
    void clear() {
        _points.clear ();
    }

    void delSpcPts(QPointF p) {
        for(int i = 0; i < _points.count (); i++) {
            if(p == _points.at (i)) {
                _points.remove (i);
                break;
            }
        }
    }

    QPolygonF findpoint(QPointF point) {
        int i = 0;
        QPolygonF ret;
        for(; i < _points.count (); i++) {
            if(point == _points.at (i)) {
                break;
            }
        }
        //not the last one
        if(i < _points.count ()) {
            ret << _points.at (i);
            if(i != _points.count () - 1) {
                ret << _points.at (i + 1);
            } else {
                if(i == 0) {
                    ret.clear ();
                    ret << _points.at (0);
                    ret << _points.at (0);
                } else {
                    ret.clear ();
                    ret << _points.at (_points.count () - 2);
                    ret << _points.at (_points.count () - 1);
                }
            }
        }
        return ret;
    }
private:
    QVector <QPointF> ret;
    QPolygonF _points;
    int _t_size;
};







class SigData : public QObject
{
    Q_OBJECT
public:
    enum {SINE, SAW, TRI, SQU, CUS };
    explicit SigData(QObject *parent = 0);

    ~SigData();
    int sigTypes() const;
    void setSigTypes(int sigTypes);

    SinusData sin() const;
    void setSin(const SinusData &sin);

    void genDataFrame(int type);
signals:

public slots:
private:
    int _sigTypes;
    QwtSyntheticPointData *data;
    CurveDataN *pcurv;
    //SinusData _sin;
    //TriData _tri;
    //SawData _saw;
    //SquData _squ;
    //CurveDataN _cus;
};

#endif // SIGDATA_H
