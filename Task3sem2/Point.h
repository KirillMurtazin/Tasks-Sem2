#pragma once
#include <cmath>

#ifdef GEOMETRY_LIB_EXPORTS
#define GEOMETRY_API __declspec(dllexport)
#else
#define GEOMETRY_API __declspec(dllimport)
#endif

/**
 * @class Point
 * @brief Класс для представления точки на плоскости.
 */
class GEOMETRY_API Point
{
private:
    double x; ///< Координата X
    double y; ///< Координата Y
public:
    /**
     * @brief Конструктор точки
     * @param x Координата X
     * @param y Координата Y
     */
    Point(double x = 0.0, double y = 0.0);
    /**
     * @brief Получить координату X
     * @return Значение X
     */
    double getX() const;
    /**
     * @brief Получить координату Y
     * @return Значение Y
     */
    double getY() const;
    /**
     * @brief Оператор сравнения на равенство
     * @param other Другая точка
     * @return true, если точки равны
     */
    bool operator==(const Point& other) const;
    /**
     * @brief Оператор сравнения на неравенство
     * @param other Другая точка
     * @return true, если точки не равны
     */
    bool operator!=(const Point& other) const;
    // Получение точки
    // Point GetPoint() const;
};