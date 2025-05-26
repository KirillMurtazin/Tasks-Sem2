/**
 * @file Segment.cpp
 * @brief Реализация класса Segment
 * @author Ваше имя
 * @version 1.0
 */

#include "Segment.h"
#include <stdexcept>
#include <limits>

/**
 * @brief Конструктор отрезка
 * @param start Начальная точка отрезка
 * @param end Конечная точка отрезка
 * @throw std::invalid_argument если начальная и конечная точки совпадают
 * 
 * Создает отрезок с заданными начальной и конечной точками.
 * Если точки совпадают, выбрасывает исключение.
 */
Segment::Segment(const Point& start, const Point& end) 
{
    if (start == end)
    {
        throw std::invalid_argument("Начальная и конечная точки совпадают");
    }
    // Инициализация базового класса с точками отрезка
    points = {start, end};
}

/**
 * @brief Вычисляет ординату Y по заданной абсциссе X на отрезке
 * @param x Абсцисса точки на отрезке
 * @return Ордината Y соответствующей точки
 * @throw std::invalid_argument если x находится вне отрезка
 * 
 * Вычисляет значение Y для заданного X на отрезке, используя
 * линейную интерполяцию между начальной и конечной точками.
 * Если X находится вне отрезка, выбрасывает исключение.
 */
double Segment::calculateY(double x) const
{
    // Используем точки из базового класса
    double x1 = points[0].getX();
    double y1 = points[0].getY();
    double x2 = points[1].getX();
    double y2 = points[1].getY();
    
    if (std::abs(x1 - x2) < std::numeric_limits<double>::epsilon())
    {
        if (std::abs(x - x1) < std::numeric_limits<double>::epsilon())
        {
            return (y1 + y2) / 2.0;
        }
        else
        {
            throw std::invalid_argument("x находится не на вертикальном сегменте");
        }
    }

    double slope = (y2 - y1) / (x2 - x1);
    return y1 + slope * (x - x1);
}

/**
 * @brief Оператор сдвига отрезка по оси X
 * @param shift Величина сдвига
 * @return Новый отрезок, сдвинутый на указанную величину
 * 
 * Создает новый отрезок, сдвинутый на указанную величину по оси X.
 * Начальная и конечная точки сдвигаются на одинаковое расстояние.
 */
Segment Segment::operator<<(double shift) const
{
    // Используем точки из базового класса
    Point newStart = points[0] << shift;
    Point newEnd = points[1] << shift;
    return Segment(newStart, newEnd);
}

/**
 * @brief Считывает отрезок из входного потока
 * @param is Входной поток для чтения
 * @return Считанный отрезок
 * @throw std::runtime_error при ошибке чтения
 * 
 * Считывает координаты начальной и конечной точек отрезка
 * из входного потока в формате "x1 y1 x2 y2".
 */
Segment Segment::readFrom(std::istream& is)
{
    double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    if (!(is >> x1 >> y1 >> x2 >> y2)) {
        throw std::runtime_error("Ошибка чтения отрезка из потока");
    }
    // Создаем сегмент, который инициализирует базовый класс
    return Segment(Point(x1, y1), Point(x2, y2));
}

/**
 * @brief Оператор вывода отрезка в поток
 * @param os Выходной поток
 * @param segment Отрезок для вывода
 * @return Ссылка на выходной поток
 * 
 * Выводит отрезок в поток в формате "Segment from (x1, y1) to (x2, y2)".
 */
std::ostream& operator<<(std::ostream& os, const Segment& segment)
{
    // Используем точки из базового класса
    os << "Segment from (" << segment.points[0].getX() << ", " << segment.points[0].getY()
        << ") to (" << segment.points[1].getX() << ", " << segment.points[1].getY() << ")";
    return os;
}