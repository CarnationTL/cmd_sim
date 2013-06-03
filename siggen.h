#ifndef SIGGEN_H
#define SIGGEN_H

#include <QObject>
#include <QVector>
#include <QList>
#include <QMap>
#include <cmddefs.h>
#include <sigpara.h>

//class Sig;
//class SinePara;
//class SigPara;

class SigGen : public QObject {
    Q_OBJECT
    public:
        explicit SigGen(QObject *parent = 0);
        virtual int genData(Sig &para) = 0;
        virtual QList <double> Data() const = 0;
    protected:
        QList <double> _data;
};

class SineGen : public SigGen {
    Q_OBJECT
    public:
    explicit SineGen(QObject *parent = 0) : SigGen(parent) {
    }
    int genData(Sig &para);
    QList <double> Data() const;
};


class TriGen : public SigGen {
    Q_OBJECT
    public:
    explicit TriGen(QObject *parent = 0) : SigGen(parent) {
    }
    int genData(Sig &para);
    QList <double> Data() const;
};

class SawGen : public SigGen {
    Q_OBJECT
    public:
    explicit SawGen(QObject *parent = 0) : SigGen(parent) {
    }
    int genData(Sig &para);
    QList <double> Data() const;
};


class SpGen : public SigGen {
    Q_OBJECT
    public:
    explicit SpGen(QObject *parent = 0) : SigGen(parent) {
    }
    int genData(Sig &para);
    QList <double> Data() const;
};

class SquareGen : public SigGen {
    Q_OBJECT
    public:
    explicit SquareGen(QObject *parent = 0) : SigGen(parent) {
    }
    int genData(Sig &para);
    QList <double> Data() const;
};

#endif // SIGGEN_H
