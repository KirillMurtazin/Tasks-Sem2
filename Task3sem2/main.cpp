#include <iostream>
#include "Segment.h"
#include <locale.h>

/**
 * @brief Считывает точку с консоли
 * @param prompt Подсказка для пользователя
 * @return Введённая точка
 */
Point GetPoint(const std::string& prompt);

/**
 * @brief Считывает координату с консоли
 * @param prompt Подсказка для пользователя
 * @return Введённая координата
 */
double getCoordinate(const std::string& prompt);

/**
 * @brief Главная функция программы
 *
 * Последовательно:
 * 1. Считывает две точки и создаёт отрезок
 * 2. Выводит отрезок
 * 3. Считывает x и вычисляет y на отрезке
 * 4. Сдвигает отрезок и выводит результат
 * 5. Создаёт вертикальный отрезок и проверяет вычисление y
 * @return Код завершения
 */
int main()
{
    setlocale(LC_ALL, "RU");
    double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;

    // Ввод координат первой точки
    Point p1 = GetPoint("первой");
    Point p2 = GetPoint("второй");

    // Создание отрезка
    Segment seg(p1, p2);
    std::cout << "Создан отрезок: " << seg << std::endl;

    // Ввод x для расчета ординаты
    double x = getCoordinate("Введите x для расчета ординаты: ");

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
    x = getCoordinate("Введите x для проверки вертикального отрезка: ");
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

/**
 * @brief Считывает точку с консоли
 * @param prompt Подсказка для пользователя
 * @return Введённая точка
 */
Point GetPoint(const std::string& prompt) 
{
    double x = 0.0, y = 0.0;
    std::cout << "Введите координаты " << prompt << " точки (x y): ";
    std::cin >> x >> y;
    return Point(x, y);
}

/**
 * @brief Считывает координату с консоли
 * @param prompt Подсказка для пользователя
 * @return Введённая координата
 */
double getCoordinate(const std::string& prompt) 
{
    double x = 0.0;
    std::cout << prompt;
    std::cin >> x;
    return x;
}