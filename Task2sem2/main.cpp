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
    while (true) {
        // Получаем три точки для треугольника
        Point A = getPoint("A");
        Point B = getPoint("B");
        Point C = getPoint("C");

        // Проверяем, что все точки разные
        if (A == B || A == C || B == C) {
            std::cout << "Ошибка: точки не должны совпадать. Пожалуйста, введите координаты заново.\n";
            continue;
        }

        // Создаем временный треугольник для проверки
        Triangle tempTriangle(A, B, C);

        // Проверяем существование треугольника
        if (!tempTriangle.isValid()) {
            std::cout << "Ошибка: треугольник с такими точками не существует. Пожалуйста, введите координаты заново.\n";
            continue;
        }

        // Если все проверки пройдены, возвращаем треугольник
        return tempTriangle;
    }
}

int main()
{
    setlocale(LC_ALL, "RU");

    // Получаем треугольник от пользователя
    Triangle triangle = getTriangle();

    // Вычисляем периметр и площадь
    double perimeter = triangle.calculatePerimeter(triangle);
    double area = triangle.calculateArea(triangle);

    // Выводим результаты
    std::cout << "Периметр треугольника: " << perimeter << std::endl;
    std::cout << "Площадь треугольника: " << area << std::endl;

    return 0;
}