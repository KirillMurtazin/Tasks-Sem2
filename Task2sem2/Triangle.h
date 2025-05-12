#pragma once
#include <cmath>
#include <stdexcept>
#include "Point.h"

class InvalidTriangleException : public std::runtime_error {
public:
    InvalidTriangleException(const char* message) : std::runtime_error(message) {}
};

class Triangle
{
private:
    Point pointA; // Первая вершина треугольника
    Point pointB; // Вторая вершина треугольника
    Point pointC; // Третья вершина треугольника
    double a; // Сторона BC
    double b; // Сторона AC
    double c; // Сторона AB
    // Проверка существования треугольника (внутренняя функция)
    bool isValid() const;
public:
    // Конструктор для создания треугольника по трем точкам
    Triangle(const Point& point1, const Point& point2, const Point& point3);

    // Геттеры для длин сторон
    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }

    // Функция для расчета периметра треугольника
    double calculatePerimeter() const;

    // Функция для расчета площади треугольника
    double calculateArea() const;

    // Вспомогательная функция для расчета длины стороны по координатам двух точек
    double calculateSideLength(const Point& point1, const Point& point2) const;
};