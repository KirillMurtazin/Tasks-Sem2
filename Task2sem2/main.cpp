#include <iostream>
#include <locale.h>
#include "Triangle.h"
#include "Point.h"

int main()
{
    setlocale(LC_ALL, "RU");

    double x1, y1, x2, y2, x3, y3;

    // Ввод координат первой точки
    std::cout << "Введите координаты первой точки (x1 y1): ";
    std::cin >> x1 >> y1;

    // Ввод координат второй точки
    std::cout << "Введите координаты второй точки (x2 y2): ";
    std::cin >> x2 >> y2;

    // Ввод координат третьей точки
    std::cout << "Введите координаты третьей точки (x3 y3): ";
    std::cin >> x3 >> y3;

    // Создаем три точки для треугольника
    Point A(x1, y1);
    Point B(x2, y2);
    Point C(x3, y3);

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