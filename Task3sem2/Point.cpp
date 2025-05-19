#include "Point.h"

/**
 * @brief Конструктор точки
 * @param x Координата X
 * @param y Координата Y
 */
Point::Point(double x, double y) : x(x), y(y) {}

/**
 * @brief Получить координату X
 * @return Значение X
 */
double Point::getX() const 
{
    return x;
}

/**
 * @brief Получить координату Y
 * @return Значение Y
 */
double Point::getY() const 
{
    return y;
}

/**
 * @brief Оператор сравнения на равенство
 * @param other Другая точка
 * @return true, если точки равны
 */
bool Point::operator==(const Point& other) const 
{
    return x == other.x && y == other.y;
}

/**
 * @brief Оператор сравнения на неравенство
 * @param other Другая точка
 * @return true, если точки не равны
 */
bool Point::operator!=(const Point& other) const 
{
    return !(*this == other);
}