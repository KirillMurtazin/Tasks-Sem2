#pragma once
#include "Point.h"
#include <iostream>

/**
 * @class Segment
 * @brief Класс для представления отрезка на плоскости.
 */
class GEOMETRY_API Segment
{
private:
    Point start; ///< Начальная точка отрезка
    Point end;   ///< Конечная точка отрезка
public:
    /**
     * @brief Конструктор отрезка
     * @param start Начальная точка
     * @param end Конечная точка
     */
    Segment(const Point& start, const Point& end);
    /**
     * @brief Вычисляет ординату Y по заданной абсциссе X на отрезке
     * @param x Абсцисса
     * @return Ордината Y
     */
    double calculateY(double x) const;
    /**
     * @brief Оператор сдвига отрезка по оси X
     * @param shift Величина сдвига
     * @return Новый сдвинутый отрезок
     */
    Segment operator<<(double shift) const;
    /**
     * @brief Считывает отрезок из входного потока
     * @param is Входной поток
     * @return Считанный отрезок
     */
    static Segment readFrom(std::istream& is);
    /**
     * @brief Оператор вывода отрезка в поток
     * @param os Выходной поток
     * @param segment Отрезок
     * @return Ссылка на поток
     */
    friend std::ostream& operator<<(std::ostream& os, const Segment& segment);
};