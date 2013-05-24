#ifndef SIGPARA_H
#define SIGPARA_H

#include <QObject>
#include <cmddefs.h>

class Sig : public QObject {
    Q_OBJECT
    public:
        explicit Sig(QObject *parent = 0) : QObject(parent) {

        }
        Sig(double amp, double feq) : _amp(amp), _feq(feq) {

        }
        ~Sig() {

        }
        double  Amp() const {
            return _amp;
        }
        double Feq() const {
            return _feq;
        }
        void setAmp(double amp) {
            _amp = amp;
        }
        void setFeq(double feq) {
            _feq = feq;
        }
    protected:
        double _amp;
        double _feq;
}; /* -----  end of class Sig  ----- */



class Sine : public Sig {
    Q_OBJECT
    public:
        Sine (double amp, double feq) : Sig(amp, feq) {

        }
        Sine ( const Sine &other ) : Sig(other.Amp(), other.Feq() ){
            _amp = other.Amp();
            _feq = other.Feq();
        }
        ~Sine ();
        Sine& operator = ( const Sine &other ) {
            _amp = other.Amp();
            _feq = other.Feq();
        }
}; /* -----  end of class Sine  ----- */




class Tri : public Sig {
    Q_OBJECT
    public:
        Tri (double amp, double feq) : Sig(amp, feq) {

        }
        Tri ( const Tri &other ) : Sig(other.Amp(), other.Feq()){
            _amp = other.Amp();
            _feq = other.Feq();
        }
        ~Tri () {
        }

        Tri& operator = ( const Tri &other ) {
            _amp = other.Amp();
            _feq = other.Feq();
        }
}; /* -----  end of class Tri  ----- */


class Sp : public Sig {
    Q_OBJECT
    public:
        
        Sp (double value) {
            value = _value;
        }
        Sp ( const Sp &other ) {
            _value = other.Value();
        }
        ~Sp () {
        }
       
        double Value() const {
            return _value;
        }
        void setval(double val) {
            _value = val;
        }
        Sp& operator = ( const Sp &other ) {
            _value = other.Value();
        }
    private:
        double _value;
}; /* -----  end of class Sp  ----- */


class Square : public Sig {
    Q_OBJECT
    public:
      
        Square (double amp, double feq, double duty) : Sig(amp, feq), _duty(duty) {

        }
        Square ( const Square &other ) {
            _amp = other.Amp();
            _feq = other.Feq();
            _duty = other.Duty();
        }
        ~Square () {
        }

        Square& operator = ( const Square &other ) {
            _amp = other.Amp();
            _feq = other.Feq();
            _duty = other.Duty();
        }
        double Duty() const {
            return _duty;
        }
        void setDuty(double _val) {
            _duty = _val;
        }
    private:
        double _duty;
}; /* -----  end of class Square  ----- */



class Saw : public Sig {
    Q_OBJECT
    public:
        
        Saw (double amp, double feq) : Sig(amp, feq)  {
        }
        Saw ( const Saw &other ) {
            _amp = other.Amp();
            _feq = other.Feq();
        }
        ~Saw () {
        }

        Saw& operator = ( const Saw &other ) {
            _amp = other.Amp();
            _feq = other.Feq();
        }
}; /* -----  end of class Saw  ----- */


class SigPara : public QObject
{
    Q_OBJECT
    public:
        explicit SigPara(QObject *parent = 0) : QObject(parent) {
        }
        virtual Sig* createSigPara(double amp, ...) = 0;
};

class SinePara : public SigPara {
    Q_OBJECT
    public:
        explicit SinePara(QObject *parent = 0) : SigPara(parent) {
        }
        Sig* createSigPara(double amp, double feq) {
            return new Sine(amp, feq);
        }
};

class TriPara : public SigPara {
    Q_OBJECT
    public:
        explicit TriPara(QObject *parent = 0) : SigPara(parent) {
        }
        Sig* createSigPara(double amp, double feq) {
            return new Tri(amp, feq);
        }
};

class SawPara : public SigPara {
    Q_OBJECT
    public:
        explicit SawPara(QObject *parent = 0) : SigPara(parent) {
        }
        Sig* createSigPara(double amp, double feq) {
            return new Saw(amp, feq);
        }
};


class SquarePara : public SigPara {
    Q_OBJECT
    public:
        explicit SquarePara(QObject *parent = 0) : SigPara(parent) {
        }
        Sig* createSigPara(double amp, double feq, double duty) {
            return new Square(amp, feq, duty);
        }
};

class SpPara : public SigPara {
    Q_OBJECT
    public:
        explicit SpPara(QObject *parent = 0) : SigPara(parent) {
        }
        Sig* createSigPara(double value) {
            return new Sp(value);
        }
};

#endif // SIGPARA_H
