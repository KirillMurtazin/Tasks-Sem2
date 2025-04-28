#pragma once
#include <cmath>

// Класс, представляющий точку в 2D пространстве
class Point
{
public:
    double X;
    double Y;

    Point(double xCoord = 0.0, double yCoord = 0.0);

    // Оператор равенства
    bool operator==(const Point& other) const {
        return (std::abs(X - other.X) < 1e-10) && (std::abs(Y - other.Y) < 1e-10);
    }

    // Оператор неравенства
    bool operator!=(const Point& other) const {
        return !(*this == other);
    }
};