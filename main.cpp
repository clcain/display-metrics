#include "displaymetrics.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DisplayMetrics w;
    w.show();

    return a.exec();
}
