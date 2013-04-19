#ifndef COMPLETER_H
#define COMPLETER_H

#include <QObject>
#include <QCompleter>
#include <QStringList>
class Completer : public QObject
{
    Q_OBJECT
public:
    explicit Completer(QObject *parent = 0);
signals:
    
public slots:
public:
    int addWordList(QString word);
    int delWordList(QString word);
    int clearWordList();
    int updateCompeleter();
    int attchCompeleter(QStringList &_wStringlist);
private:
    QStringList _wordlist;
    QCompleter _wcompleter;
};

#endif // COMPLETER_H
