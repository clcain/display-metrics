#ifndef DISPLAYMETRICS_H
#define DISPLAYMETRICS_H

#include <QMainWindow>
#include "displaymetricscalculator.h"

namespace Ui {
class DisplayMetrics;
}

class DisplayMetrics : public QMainWindow
{
    Q_OBJECT

public:
    explicit DisplayMetrics(QWidget *parent = 0);
    ~DisplayMetrics();

private slots:
    void enterDiagonal();
    void enterWidth();
    void enterHeight();
    void enterBPC();
    void updateValues();

private:
    Ui::DisplayMetrics *ui;
    DisplayMetricsCalculator calc;

};

#endif // DISPLAYMETRICS_H
