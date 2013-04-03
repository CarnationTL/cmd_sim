#ifndef APDAPTER_H
#define APDAPTER_H
#include <QObject>

class Apdapter : public QObject
{
    Q_OBJECT
public:
    explicit Apdapter(QObject *parent = 0);
    explicit Apdapter(double max_phyval,
                      double min_phyval, QObject *parent = 0);
    double maxPhyval() const;
    void setMaxPhyval(double maxPhyval);

    double minPhyval() const;
    void setMinPhyval(double minPhyval);

    double minElcval() const;
    void setMinElcval(double minElcval);


    double maxElcval() const;
    void setMaxElcval(double maxElcval);


signals:
    
public slots:

private:
    double _maxPhyval;
    double _minPhyval;
    double _minElcval;
    double _maxElcval;
};

#endif // APDAPTER_H
