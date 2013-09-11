#include "curvedatan.h"
#include <qmath.h>

CurveDataN::CurveDataN(int size) {
    _t_size = size;
    _points << QPointF(0.0, 0.0);
    _points.clear();
}

void CurveDataN::appendP(double x, double y) {
    _points << QPointF(x, y);
}

QPolygonF CurveDataN::getpts() {
    return _points;
}


QPolygonF CurveDataN::genWriteData() {
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


double CurveDataN::getYRgn() {

    int len = _points.count ();
    if(len == 0.0) {
        return 0.0;
    }
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

double CurveDataN::getXRgn() {
    int len = _points.count ();
    if(len == 0) {
        return 0.0;
    }
    double xmax = _points.at (0).x ();
    for(int i = 0; i < len; i++) {
        if(xmax <= _points.at (i).x ()) {
            xmax = _points.at (i).x ();
        }
    }
        return xmax;
}


void CurveDataN::clear() {
    _points.clear ();
}

void CurveDataN::delSpcPts(QPointF p) {
    for(int i = 0; i < _points.count (); i++) {
        if(p == _points.at (i)) {
            _points.remove (i);
            break;
        }
    }
}

QPolygonF CurveDataN::findpoint(QPointF point) {
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
