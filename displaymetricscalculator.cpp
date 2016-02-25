#include "displaymetricscalculator.h"

#include "QTextStream"
QTextStream cout(stdout);

void DisplayMetricsCalculator::debug()
{
    cout << m_PixelsX  << " "
    << m_PixelsY  << " "
    << m_TotalPixels  << " "
    << m_DiagonalLength  << " "
    << m_DiagonalAngle  << " "
    << m_Height  << " "
    << m_Width  << " "
    << m_AspectRatio  << " "
    << m_ScreenArea  << " "
    << m_ColorDepth  << " "
    << m_TotalColors  << " "
    << m_PPI  << " "
    << m_ScalingPercentage  << " "
    << dimensionsComplete() << " "
    << endl;
}

qreal DisplayMetricsCalculator::getPixelsX()
{
    return m_PixelsX;
}

qreal DisplayMetricsCalculator::getPixelsY()
{
    return m_PixelsY;
}

qreal DisplayMetricsCalculator::getTotalPixels()
{
    return m_TotalPixels;
}

qreal DisplayMetricsCalculator::getDiagonalLength()
{
    return m_DiagonalLength;
}

qreal DisplayMetricsCalculator::getHeight()
{
    return m_Height;
}

qreal DisplayMetricsCalculator::getWidth()
{
    return m_Width;
}

qreal DisplayMetricsCalculator::getAspectRatio()
{
    return m_AspectRatio;
}

qreal DisplayMetricsCalculator::getScreenArea()
{
    return m_ScreenArea;
}

qreal DisplayMetricsCalculator::getColorDepth()
{
    return m_ColorDepth;
}

qreal DisplayMetricsCalculator::getTotalColors()
{
    return m_TotalColors;
}

qreal DisplayMetricsCalculator::getPPI()
{
    return m_PPI;
}

qreal DisplayMetricsCalculator::getScalingPercentage()
{
    return m_ScalingPercentage;
}

bool DisplayMetricsCalculator::dimensionsComplete()
{
    return m_PixelsX != 0 && m_PixelsY != 0 && m_DiagonalLength != 0;
}

void DisplayMetricsCalculator::setPixelsX(qreal pixels)
{
    m_PixelsX = pixels;
    if (dimensionsComplete())
    {
        calculateDimensions();
    }
        debug();
}

void DisplayMetricsCalculator::setPixelsY(qreal pixels)
{
    m_PixelsY = pixels;
    if (dimensionsComplete())
    {
        calculateDimensions();
    }
        debug();
}

void DisplayMetricsCalculator::setDiagonalLength(qreal diagonal)
{
    m_DiagonalLength = diagonal;
    if (dimensionsComplete())
    {
        calculateDimensions();
    }
        debug();
}

void DisplayMetricsCalculator::setColorDepth(qreal bits)
{
    m_ColorDepth = bits;
    m_TotalColors = qPow(qPow(2, bits), 3);
    debug();
}

void DisplayMetricsCalculator::calculateDimensions()
{
    m_TotalPixels = m_PixelsX * m_PixelsY;
    m_AspectRatio = m_PixelsX / m_PixelsY;
    m_DiagonalAngle = qAtan(m_PixelsY / m_PixelsX);
    m_Width = m_DiagonalLength * qCos(m_DiagonalAngle);
    m_Height = m_DiagonalLength * qSin(m_DiagonalAngle);
    m_ScreenArea = m_Width * m_Height;
    m_PPI = qSqrt(m_TotalPixels / m_ScreenArea);
    m_ScalingPercentage = m_PPI / 96 * 100;
}
