#pragma once
#include <cmath>
#include <limits>

// Класс, представляющий точку в 2D пространстве
class Point
{
private:
    double X;
    double Y;
public:
    Point(double xCoord = 0.0, double yCoord = 0.0);
    double getX() const { return X; }
    double getY() const { return Y; }
    // Оператор равенства
    bool operator==(const Point& other) const {
        return (std::abs(X - other.X) < std::numeric_limits<double>::epsilon()) && 
               (std::abs(Y - other.Y) < std::numeric_limits<double>::epsilon());
    }
    // Оператор неравенства
    bool operator!=(const Point& other) const {
        return (std::abs(X - other.X) >= std::numeric_limits<double>::epsilon()) ||
               (std::abs(Y - other.Y) >= std::numeric_limits<double>::epsilon());
    }
};