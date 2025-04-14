#include <iostream>
#include <locale.h>
#include "Triangle.h"
#include "Point.h"

int main()
{
    setlocale(LC_ALL, "RU");

    // Создаем три точки для треугольника
    Point A(0.0, 0.0);
    Point B(3.0, 0.0);
    Point C(0.0, 4.0);

    // Создаем треугольник
    Triangle triangle(A, B, C);

    // Вычисляем периметр и площадь
    double perimeter = triangle.calculatePerimeter(triangle);
    double area = triangle.calculateArea(triangle);

    // Выводим результаты
    std::cout << "Периметр треугольника: " << perimeter << std::endl;
    std::cout << "Площадь треугольника: " << area << std::endl;

    return 0;
}