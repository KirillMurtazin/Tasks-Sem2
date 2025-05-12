#include "Triangle.h"
#include <cmath>

// Вспомогательная функция для расчета длины стороны
static double calculateSideLength(const Point& p1, const Point& p2) {
    return std::sqrt(std::pow(p2.getX() - p1.getX(), 2) + std::pow(p2.getY() - p1.getY(), 2));
}

// Реализация конструктора Triangle
Triangle::Triangle(const Point& point1, const Point& point2, const Point& point3)
    : pointA(point1), pointB(point2), pointC(point3)
{
    // Проверяем, что все точки разные
    if (point1 == point2 || point1 == point3 || point2 == point3) {
        throw InvalidTriangleException("Ошибка: точки не должны совпадать");
    }
    // Вычисляем длины сторон
    a = calculateSideLength(pointB, pointC); // BC
    b = calculateSideLength(pointA, pointC); // AC
    c = calculateSideLength(pointA, pointB); // AB
    // Проверяем существование треугольника
    if (!isValid()) {
        throw InvalidTriangleException("Ошибка: треугольник с такими точками не существует");
    }
}

// Вычисление периметра
// Теперь не принимает аргумент
double Triangle::calculatePerimeter() const
{
    return a + b + c;
}

// Вычисление площади (формула Герона)
double Triangle::calculateArea() const
{
    double s = (a + b + c) / 2;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

// Проверка существования треугольника
bool Triangle::isValid() const
{
    return (a + b > c) && (b + c > a) && (c + a > b);
}