#pragma once
#include "Point.h"
#include <iostream>

/**
 * @file Segment.h
 * @brief Заголовочный файл класса Segment
 * @author Ваше имя
 * @version 1.0
 */

/**
 * @class Segment
 * @brief Класс для представления отрезка на плоскости
 * Класс Segment представляет отрезок на двумерной плоскости,
 * заданный двумя точками (начало и конец). Поддерживает операции
 * с отрезками, включая вычисление координат, сдвиг и ввод/вывод.
 */
class GEOMETRY_API Segment
{
private:
    Point start; ///< Начальная точка отрезка
    Point end;   ///< Конечная точка отрезка

public:
    /**
     * @brief Конструктор отрезка
     * @param start Начальная точка отрезка
     * @param end Конечная точка отрезка
     * @throw std::invalid_argument если начальная и конечная точки совпадают
     */
    Segment(const Point& start, const Point& end);

    /**
     * @brief Вычисляет ординату Y по заданной абсциссе X на отрезке
     * @param x Абсцисса точки на отрезке
     * @return Ордината Y соответствующей точки
     * @throw std::invalid_argument если x находится вне отрезка
     */
    double calculateY(double x) const;

    /**
     * @brief Оператор сдвига отрезка по оси X
     * @param shift Величина сдвига
     * @return Новый отрезок, сдвинутый на указанную величину
     */
    Segment operator<<(double shift) const;

    /**
     * @brief Считывает отрезок из входного потока
     * @param is Входной поток для чтения
     * @return Считанный отрезок
     * @throw std::runtime_error при ошибке чтения
     */
    static Segment readFrom(std::istream& is);

    /**
     * @brief Оператор вывода отрезка в поток
     * @param os Выходной поток
     * @param segment Отрезок для вывода
     * @return Ссылка на выходной поток
     */
    friend std::ostream& operator<<(std::ostream& os, const Segment& segment);
};