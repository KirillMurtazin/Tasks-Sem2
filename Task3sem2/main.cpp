#include <iostream>
#include "Segment.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "RU");
    double x1, y1, x2, y2;

    // Ввод координат первой точки
    Point p1 = GetPoint("первой");
    Point p2 = GetPoint("второй");

    // Создание отрезка
    Segment seg(p1, p2);
    std::cout << "Создан отрезок: " << seg << std::endl;

    // Ввод x для расчета ординаты
    double x;
    std::cout << "Введите x для расчета ординаты: ";
    std::cin >> x;

    // Расчет ординаты
    try
    {
        double y = seg.calculateY(x);
        std::cout << "Y при x=" << x << ": " << y << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    // Ввод величины сдвига
    double shift;
    std::cout << "Введите величину сдвига отрезка: ";
    std::cin >> shift;

    // Сдвиг отрезка
    Segment shifted = seg << shift;
    std::cout << "Сдвинутый отрезок: " << shifted << std::endl;

    // Создание вертикального отрезка
    std::cout << "\nСоздание вертикального отрезка" << std::endl;
    std::cout << "Введите координаты первой точки (x1 y1): ";
    std::cin >> x1 >> y1;
    Point p3(x1, y1);

    std::cout << "Введите координаты второй точки (x2 y2): ";
    std::cin >> x2 >> y2;
    Point p4(x2, y2);

    Segment vertical(p3, p4);
    std::cout << "Создан вертикальный отрезок: " << vertical << std::endl;

    // Проверка вертикального отрезка
    std::cout << "Введите x для проверки вертикального отрезка: ";
    std::cin >> x;
    try
    {
        std::cout << "Y при x=" << x << ": " << vertical.calculateY(x) << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}