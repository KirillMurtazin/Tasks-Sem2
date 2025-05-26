/**
 * @file Point.cpp
 * @brief Реализация класса Point
 * @author Ваше имя
 * @version 1.0
 */

#include "Point.h"
#include <cmath>
#include <limits>

/**
 * @brief Конструктор точки
 * @param x Координата X (по умолчанию 0.0)
 * @param y Координата Y (по умолчанию 0.0)
 * Создает точку с заданными координатами. Если координаты не указаны,
 * создается точка в начале координат (0, 0).
 */
Point::Point(double x, double y) : x(x), y(y) {}

/**
 * @brief Получить координату X
 * @return Значение координаты X
 * Возвращает значение координаты X точки.
 */
double Point::getX() const 
{
    return x;
}

/**
 * @brief Получить координату Y
 * @return Значение координаты Y
 * Возвращает значение координаты Y точки.
 */
double Point::getY() const 
{
    return y;
}

/**
 * @brief Оператор сравнения на равенство
 * @param other Другая точка для сравнения
 * @return true, если точки равны (имеют одинаковые координаты)
 * Сравнивает координаты текущей точки с координатами другой точки.
 * Точки считаются равными, если их координаты X и Y совпадают с учетом погрешности.
 */
bool Point::operator==(const Point& other) const 
{
    return std::abs(x - other.x) < std::numeric_limits<double>::epsilon() && std::abs(y - other.y) < std::numeric_limits<double>::epsilon();
}

/**
 * @brief Оператор сравнения на неравенство
 * @param other Другая точка для сравнения
 * @return true, если точки не равны (имеют разные координаты)
 * Сравнивает координаты текущей точки с координатами другой точки.
 * Точки считаются неравными, если хотя бы одна из координат отличается.
 */
bool Point::operator!=(const Point& other) const 
{
    return !(*this == other);
}

/**
 * @brief Оператор сдвига влево
 * @param shift Величина сдвига
 * @return Новая точка, сдвинутая на указанную величину влево (уменьшение X и Y)
 * Создает новую точку, сдвинутую на указанную величину по осям X и Y.
 */
Point Point::operator<<(double shift) const
{
    return Point(x - shift, y - shift);
}

/**
 * @brief Оператор сдвига вправо
 * @param shift Величина сдвига
 * @return Новая точка, сдвинутая на указанную величину вправо (увеличение X и Y)
 * Создает новую точку, сдвинутую на указанную величину по осям X и Y.
 */
Point Point::operator>>(double shift) const
{
    return Point(x + shift, y + shift);
}