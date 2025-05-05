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

    // Операторы сравнения
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;

    // Получение точки
    Point GetPoint() const;
};