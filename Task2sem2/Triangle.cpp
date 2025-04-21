#include "Triangle.h"
#include <cmath>

// Реализация конструктора Triangle
Triangle::Triangle(const Point& point1, const Point& point2, const Point& point3)
    : pointA(point1), pointB(point2), pointC(point3) {}


// Вычисление периметра
double Triangle::calculatePerimeter(const Triangle& triangle) const
{
    double sideAB = triangle.calculateSideLength(pointA, pointB);
    double sideBC = triangle.calculateSideLength(pointB, pointC);
    double sideCA = triangle.calculateSideLength(pointC, pointA);
    return (sideAB + sideBC + sideCA);
}

// Вычисление площади (формула Герона)
double Triangle::calculateArea(const Triangle& triangle) const
{
    double a = triangle.calculateSideLength(pointA, pointB);
    double b = triangle.calculateSideLength(pointB, pointC);
    double c = triangle.calculateSideLength(pointC, pointA);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

/**
   Вычисление длины стороны.
*/
double Triangle::calculateSideLength(const Point& point1, const Point& point2) const
{
    return sqrt(pow(point2.X - point1.X, 2) + pow(point2.Y - point1.Y, 2));
}

/**
   Проверка существования треугольника.
   Треугольник существует, если сумма любых двух его сторон больше третьей стороны.
*/
bool Triangle::isValid() const
{
    double a = calculateSideLength(pointA, pointB);
    double b = calculateSideLength(pointB, pointC);
    double c = calculateSideLength(pointC, pointA);
    
    return (a + b > c) && (b + c > a) && (c + a > b);
}