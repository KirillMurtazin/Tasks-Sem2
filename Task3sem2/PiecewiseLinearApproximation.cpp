#include "PiecewiseLinearApproximation.h"
#include <algorithm>

void PiecewiseLinearApproximation::addPoint(const Point& point)
{
    points.push_back(point);
    // Опционально: сортировка точек по абсциссе для удобства
    std::sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.getX() < b.getX();
    });
}

void PiecewiseLinearApproximation::readPoints(std::istream& is)
{
    double x, y;
    while (is >> x >> y)
    {
        points.push_back(Point(x, y));
    }
    // Опционально: сортировка точек по абсциссе после чтения
     std::sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.getX() < b.getX();
    });
}

const std::vector<Point>& PiecewiseLinearApproximation::getPoints() const
{
    return points;
} 