#ifndef DISPLAYMETRICSCALCULATOR_H
#define DISPLAYMETRICSCALCULATOR_H

#include <stdexcept>
#include <qmath.h>

class DisplayMetricsCalculator
{
public:
    // automatically updates all relevant fields if possible
    void setPixelsX(qreal pixels);
    void setPixelsY(qreal pixels);
    void setDiagonalLength(qreal diagonal);
    void setColorDepth(qreal bits);

    // will return 0 if there is insufficient data
    qreal getPixelsX();
    qreal getPixelsY();
    qreal getTotalPixels();
    qreal getDiagonalLength();
    qreal getDiagonalAngle();
    qreal getHeight();
    qreal getWidth();
    qreal getAspectRatio();
    qreal getScreenArea();
    qreal getColorDepth();
    qreal getTotalColors();
    qreal getPPI();
    qreal getScalingPercentage();

private:
    // fields
    qreal m_PixelsX;
    qreal m_PixelsY;
    qreal m_TotalPixels;
    qreal m_DiagonalLength;
    qreal m_DiagonalAngle;
    qreal m_Height;
    qreal m_Width;
    qreal m_AspectRatio;
    qreal m_ScreenArea;
    qreal m_ColorDepth;
    qreal m_TotalColors;
    qreal m_PPI;
    qreal m_ScalingPercentage;

    // internal functions
    inline bool dimensionsComplete();
    void calculateDimensions();
    void debug();
};

#endif // DISPLAYMETRICSCALCULATOR_H
