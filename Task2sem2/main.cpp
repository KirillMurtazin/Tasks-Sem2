#include <iostream>
#include <locale.h>
#include "Triangle.h"
#include "Point.h"

// Объявления функций
Point getPoint(const char* pointName);
Triangle getTriangle();

int main()
{
    setlocale(LC_ALL, "RU");

    try {
        Triangle triangle = getTriangle();
        double perimeter = triangle.calculatePerimeter();
        double area = triangle.calculateArea();
        std::cout << "Периметр треугольника: " << perimeter << std::endl;
        std::cout << "Площадь треугольника: " << area << std::endl;
    } catch (const InvalidTriangleException& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}


Point getPoint(const char* pointName) {
    double x = 0.0, y = 0.0;
    std::cout << "Введите координаты точки " << pointName << " (x y): ";
    std::cin >> x >> y;
    return Point(x, y);
}

Triangle getTriangle() {
    // Получаем три точки для треугольника
    Point A = getPoint("A");
    Point B = getPoint("B");
    Point C = getPoint("C");
    // Создаем треугольник (проверка валидности происходит в конструкторе)
    return Triangle(A, B, C);
}