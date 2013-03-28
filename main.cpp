#include "cmdsimmw.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CMDSimMW w;
    w.show();
    
    return a.exec();
}
