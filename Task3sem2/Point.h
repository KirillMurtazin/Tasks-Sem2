#pragma once
#include <cmath>
#include "geometry_defines.h"

// Класс Point.
class GEOMETRY_API Point
{
private:

    double x;
    double y;
public:

    Point(double x = 0.0, double y = 0.0);
    double getX() const;
    double getY() const;

    // Операторы сравнения
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;

    // Операторы сдвига
    Point operator<<(double shift) const; // Сдвиг влево (уменьшение X и Y)
    Point operator>>(double shift) const; // Сдвиг вправо (увеличение X и Y)

};