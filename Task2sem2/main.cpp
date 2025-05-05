#include <iostream>
#include <locale.h>
#include "Triangle.h"
#include "Point.h"

Point getPoint(const char* pointName) {
    double x, y;
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

int main()
{
    setlocale(LC_ALL, "RU");

    try {
        // Получаем треугольник от пользователя
        Triangle triangle = getTriangle();

        // Вычисляем периметр и площадь
        double perimeter = triangle.calculatePerimeter(triangle);
        double area = triangle.calculateArea(triangle);

        // Выводим результаты
        std::cout << "Периметр треугольника: " << perimeter << std::endl;
        std::cout << "Площадь треугольника: " << area << std::endl;
    }
    catch (const InvalidTriangleException& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}