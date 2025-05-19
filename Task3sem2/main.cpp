#include <iostream>
#include "Point.h"
#include "Segment.h"
#include <stdexcept>
#include <locale.h>

/**
 * @brief Получает координаты точки от пользователя
 * @param pointName Название точки для вывода в запросе
 * @return Созданная точка с введенными координатами
 * 
 * Запрашивает у пользователя координаты X и Y для точки
 * и создает объект Point с введенными значениями.
 */
Point GetPoint(const std::string& pointName) {
    double x, y;
    std::cout << "Введите координаты " << pointName << " точки (x y): ";
    std::cin >> x >> y;
    return Point(x, y);
}

/**
 * Выводит запрос пользователю и считывает числовое значение.
 * Используется для получения координат и других числовых параметров.
 */
double getCoordinate(const std::string& prompt) {
    double value;
    std::cout << prompt;
    std::cin >> value;
    return value;
}

/**
 * @brief Демонстрирует работу с точками
 * 
 * Создает несколько точек и демонстрирует операции сравнения.
 * Показывает работу операторов == и != для класса Point.
 */
void demonstratePoints() {
    std::cout << "\nДемонстрация работы с точками:\n";
    
    Point p1(1, 2);
    Point p2(1, 2);
    Point p3(2, 1);
    
    std::cout << "Точка p1: (" << p1.getX() << ", " << p1.getY() << ")\n";
    std::cout << "Точка p2: (" << p2.getX() << ", " << p2.getY() << ")\n";
    std::cout << "Точка p3: (" << p3.getX() << ", " << p3.getY() << ")\n";
    
    std::cout << "p1 == p2: " << (p1 == p2) << "\n";
    std::cout << "p1 == p3: " << (p1 == p3) << "\n";
    std::cout << "p1 != p3: " << (p1 != p3) << "\n";
}

/**
 * @brief Демонстрирует работу с отрезками
 * 
 * Создает отрезок и демонстрирует различные операции с ним:
 * - Вычисление Y-координаты для заданного X
 * - Сдвиг отрезка
 * - Чтение отрезка из потока
 */
void demonstrateSegments() {
    std::cout << "\nДемонстрация работы с отрезками:\n";
    
    try {
        Point p1(0, 0);
        Point p2(2, 2);
        Segment seg(p1, p2);
        
        std::cout << "Отрезок: " << seg << "\n";
        
        // Вычисление Y для различных X
        std::cout << "Y при X = 0.5: " << seg.calculateY(0.5) << "\n";
        std::cout << "Y при X = 1.0: " << seg.calculateY(1.0) << "\n";
        std::cout << "Y при X = 1.5: " << seg.calculateY(1.5) << "\n";
        
        // Сдвиг отрезка
        Segment shifted = seg << 1.0;
        std::cout << "Сдвинутый отрезок: " << shifted << "\n";
        
        // Чтение отрезка из потока
        std::cout << "\nВведите координаты отрезка (x1 y1 x2 y2): ";
        Segment readSeg = Segment::readFrom(std::cin);
        std::cout << "Считанный отрезок: " << readSeg << "\n";
        
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << "\n";
    }
}

/**
 * @brief Создает и демонстрирует работу с отрезком
 * @param segmentName Название отрезка для вывода
 * @return true если операция выполнена успешно, false при ошибке
 * 
 * Создает отрезок по введенным координатам и демонстрирует
 * операции с ним: вычисление Y-координаты и сдвиг.
 */
bool demonstrateSegment(const std::string& segmentName) {
    try {
        std::cout << "\nСоздание " << segmentName << ":\n";
        Point p1 = GetPoint("первой точки");
        Point p2 = GetPoint("второй точки");
        
        Segment seg(p1, p2);
        std::cout << "Создан отрезок: " << seg << std::endl;

        // Вычисление Y для заданного X
        double x = getCoordinate("Введите x для расчета ординаты: ");
        try {
            double y = seg.calculateY(x);
            std::cout << "Y при x=" << x << ": " << y << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cerr << "Ошибка при вычислении Y: " << e.what() << std::endl;
        }

        // Сдвиг отрезка
        double shift = getCoordinate("Введите величину сдвига отрезка: ");
        Segment shifted = seg << shift;
        std::cout << "Сдвинутый отрезок: " << shifted << std::endl;
        
        return true;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка при создании отрезка: " << e.what() << std::endl;
        return false;
    }
}

/**
 * @brief Главная функция программы
 * @return 0 при успешном завершении, 1 при ошибке
 * 
 * Основная функция программы, которая демонстрирует работу с классами
 * Point и Segment. Включает:
 * - Создание точек и отрезков
 * - Вычисление координат на отрезке
 * - Сдвиг отрезков
 * - Обработку исключений
 * 
 * @throw std::exception при критических ошибках
 */
int main() {
    try {
        // Установка русской локали для корректного вывода
        setlocale(LC_ALL, "RU");

        // Демонстрация работы с точками
        demonstratePoints();

        // Демонстрация работы с отрезками
        demonstrateSegments();

        // Интерактивная работа с отрезками
        if (!demonstrateSegment("обычного отрезка")) {
            return 1;
        }

        // Создание вертикального отрезка
        if (!demonstrateSegment("вертикального отрезка")) {
            return 1;
        }

    } catch (const std::exception& e) {
        std::cerr << "Критическая ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}