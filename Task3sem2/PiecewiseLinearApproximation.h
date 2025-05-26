#pragma once

#include <vector>
#include <iostream>
#include <initializer_list>
#include "Point.h"

/**
 * @brief Абстрактный базовый класс для кусочно-линейной аппроксимации функции.
 * Представляет функцию, заданную набором точек на плоскости.
 * Является абстрактным, так как метод calculateY является чисто виртуальным.
 */
class PiecewiseLinearApproximation
{
protected:
    std::vector<Point> points; ///< Коллекция точек, задающих функцию

public:
    /**
     * @brief Конструктор по умолчанию.
     * Создает пустую аппроксимацию.
     */
    PiecewiseLinearApproximation() = default;

    /**
     * @brief Конструктор, принимающий вектор точек.
     * @param points Вектор точек для инициализации аппроксимации.
     */
    PiecewiseLinearApproximation(const std::vector<Point>& points) : points(points) {}

    /**
     * @brief Конструктор, принимающий список инициализации точек.
     * @param points Список инициализации точек для инициализации аппроксимации.
     */
    PiecewiseLinearApproximation(std::initializer_list<Point> points) : points(points) {}

    /**
     * @brief Виртуальный деструктор.
     */
    virtual ~PiecewiseLinearApproximation() = default;

    /**
     * @brief Чисто виртуальный метод расчета ординаты по заданной абсциссе.
     * @param x Абсцисса, для которой нужно вычислить ординату.
     * @return Значение ординаты Y в точке X.
     * Этот метод должен быть реализован в производных классах.
     */
    virtual double calculateY(double x) const = 0;

    /**
     * @brief Метод добавления точки в коллекцию.
     * @param point Точка для добавления.
     */
    void addPoint(const Point& point);

    /**
     * @brief Метод чтения точек из входного потока. 
     * Читает пары координат (x, y) из потока до конца файла или ошибки.
     * @param is Входной поток.
     */
    void readPoints(std::istream& is);

    /**
     * @brief Получить все точки аппроксимации.
     * @return Константная ссылка на вектор точек.
     */
    const std::vector<Point>& getPoints() const;
}; 