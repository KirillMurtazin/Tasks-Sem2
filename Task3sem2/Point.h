#pragma once
#include <cmath>

// Класс Point.
class Point 
{
private:
    double x;
    double y;
public:
    Point(double x = 0.0, double y = 0.0);
    double getX() const;
    double getY() const;
};
