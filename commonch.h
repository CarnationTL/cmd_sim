#ifndef COMMONCH_H
#define COMMONCH_H

#include <QObject>
#include <QString>
#include "c75c3funcp.h"
#include "C75C3Expls.h"
class CommonCh : public QObject
{
    Q_OBJECT
public:
    explicit CommonCh(QObject *parent = 0);
    explicit CommonCh(int chno, QString chname, QObject *parent = 0);
    int chno() const;
    void setChno(int chno);

    QString chname() const;
    void setChname(const QString &chname);

private:
    int _chno;
    QString _chname;
signals:
    
public slots:
    
};

#endif // COMMONCH_H
