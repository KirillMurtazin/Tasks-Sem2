#pragma once
#include <cmath>
#include "Point.h"

class Triangle
{
private:
    Point pointA; // Первая вершина треугольника
    Point pointB; // Вторая вершина треугольника
    Point pointC; // Третья вершина треугольника

public:
    // Конструктор для создания треугольника по трем точкам
    Triangle(const Point& point1, const Point& point2, const Point& point3);

    // Функция для расчета периметра треугольника
    double calculatePerimeter(const Triangle& triangle) const;


    // Функция для расчета площади треугольника
    double calculateArea(const Triangle& triangle) const;

    // Вспомогательная функция для расчета длины стороны по координатам двух точек
    double calculateSideLength(const Point& point1, const Point& point2) const;

};