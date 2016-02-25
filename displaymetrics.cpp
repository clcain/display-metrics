#include "displaymetrics.h"
#include "ui_displaymetrics.h"

DisplayMetrics::DisplayMetrics(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DisplayMetrics)
{
    ui->setupUi(this);
    calc = DisplayMetricsCalculator();
    updateValues();
}

DisplayMetrics::~DisplayMetrics()
{
    delete ui;
}

void DisplayMetrics::enterDiagonal()
{
    calc.setDiagonalLength(ui->DiagonalLengthLineEdit->text().toDouble());
    updateValues();
}

void DisplayMetrics::enterWidth()
{
    calc.setPixelsX(ui->PixelXLineEdit->text().toDouble());
    updateValues();
}

void DisplayMetrics::enterHeight()
{
    calc.setPixelsY(ui->PixelYLineEdit->text().toDouble());
    updateValues();
}

void DisplayMetrics::enterBPC()
{
    calc.setColorDepth(ui->BPCLineEdit->text().toDouble());
    updateValues();
}

void DisplayMetrics::updateValues()
{
    if (calc.getTotalColors() != 0)
    {
        ui->TotalColorsDisplay->display(QString::number(calc.getTotalColors(), 'g', 5));
    }
    else
    {
        ui->TotalColorsDisplay->display("");
    }

    if (calc.getScalingPercentage() != 0)
    {
        ui->ScalingPercentageDisplay->display(QString::number(calc.getScalingPercentage(), 'g', 5));
    }
    else
    {
        ui->ScalingPercentageDisplay->display("");
    }

    if (calc.getTotalPixels() != 0)
    {
        ui->TotalPixelsDisplay->display(QString::number(calc.getTotalPixels(), 'g', 5));
    }
    else
    {
        ui->TotalPixelsDisplay->display("");
    }

    if (calc.getWidth() != 0)
    {
        ui->WidthDisplay->display(QString::number(calc.getWidth(), 'g', 5));
    }
    else
    {
        ui->WidthDisplay->display("");
    }

    if (calc.getHeight() != 0)
    {
        ui->HeightDisplay->display(QString::number(calc.getHeight(), 'g', 5));
    }
    else
    {
        ui->HeightDisplay->display("");
    }

    if (calc.getAspectRatio() != 0)
    {
        ui->AspectRatioDisplay->display(QString::number(calc.getAspectRatio(), 'g', 5));
    }
    else
    {
        ui->AspectRatioDisplay->display("");
    }

    if (calc.getScreenArea() != 0)
    {
        ui->ScreenAreaDisplay->display(QString::number(calc.getScreenArea(), 'g', 5));
    }
    else
    {
        ui->ScreenAreaDisplay->display("");
    }

    if (calc.getPPI() != 0)
    {
        ui->PPIDisplay->display(QString::number(calc.getPPI(), 'g', 5));
    }
    else
    {
        ui->PPIDisplay->display("");
    }
}
