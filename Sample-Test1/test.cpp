#include <gtest/gtest.h>
#include <sstream>
#include "../Task3sem2/Point.h"
#include "../Task3sem2/Segment.h"

// Тесты класса Point
TEST(PointTest, DefaultConstructor)
{
    // Проверка конструктора по умолчанию
    Point p;
    EXPECT_DOUBLE_EQ(p.getX(), 0.0);
    EXPECT_DOUBLE_EQ(p.getY(), 0.0);
}

TEST(PointTest, ParameterizedConstructor)
{
    // Проверка параметризованного конструктора
    Point p(3.5, -2.1);
    EXPECT_DOUBLE_EQ(p.getX(), 3.5);
    EXPECT_DOUBLE_EQ(p.getY(), -2.1);
}

TEST(PointTest, GetPoint)
{
    Point p1(2.0, 3.0);
    Point p2 = p1.GetPoint();

    // Проверяем, что полученная точка идентична исходной
    EXPECT_TRUE(p1 == p2);
    EXPECT_DOUBLE_EQ(p2.getX(), 2.0);
    EXPECT_DOUBLE_EQ(p2.getY(), 3.0);

    // Проверяем, что это разные объекты
    EXPECT_NE(&p1, &p2);
}

TEST(PointTest, EqualityOperators)
{
    Point p1(1.0, 2.0);
    Point p2(1.0, 2.0);
    Point p3(2.0, 1.0);

    // Проверка на равенство
    EXPECT_TRUE(p1 == p2);
    EXPECT_TRUE(p2 == p1);
    EXPECT_FALSE(p2 == p3);

    // Тестовое неравенство
    EXPECT_TRUE(p1 != p3);
    EXPECT_TRUE(p3 != p1);
    EXPECT_FALSE(p1 != p1);

    // Тест с разными координатами
    Point p4(1.0, 3.0);
    Point p5(3.0, 2.0);
    EXPECT_TRUE(p1 != p4);
    EXPECT_TRUE(p1 != p5);
}

// Тесты для класса Segment
TEST(SegmentTest, Constructor)
{
    // Проверка конструктора и вычисления Y
    Point p1(1, 2);
    Point p2(4, 6);
    Segment seg(p1, p2);
    EXPECT_DOUBLE_EQ(seg.calculateY(2.5), 4.0);
}

TEST(SegmentTest, ConstructorWithCoincidingPoints)
{
    // Проверка исключения при совпадающих точках
    Point p(2.0, 3.0);
    EXPECT_THROW(Segment(p, p), std::invalid_argument);
}

TEST(SegmentTest, CalculateY)
{
    // Наклонный сегмент
    Segment seg1(Point(0, 0), Point(2, 2));
    EXPECT_DOUBLE_EQ(seg1.calculateY(1), 1.0);

    // Горизонтальный сегмент
    Segment seg2(Point(2, 5), Point(6, 5));
    EXPECT_DOUBLE_EQ(seg2.calculateY(4), 5.0);

    // Вертикальный сегмент
    Segment seg3(Point(3, 0), Point(3, 4));
    EXPECT_DOUBLE_EQ(seg3.calculateY(3), 2.0);
}

TEST(SegmentTest, PointSegment)
{
    // Отрезок с совпадающими точками
    Point p(2.0, 3.0);
    Segment seg(p, p);

    // Тест в точке
    EXPECT_DOUBLE_EQ(seg.calculateY(2.0), 3.0);

    // Тест за пределами точки
    EXPECT_THROW(seg.calculateY(1.0), std::invalid_argument);
    EXPECT_THROW(seg.calculateY(3.0), std::invalid_argument);
}

TEST(SegmentTest, VerticalSegmentExceptions)
{
    Segment seg(Point(3, 0), Point(3, 4));
    EXPECT_THROW(seg.calculateY(5), std::invalid_argument);
    EXPECT_THROW(seg.calculateY(2), std::invalid_argument);
}

TEST(SegmentTest, ShiftOperator)
{
    Segment original(Point(0, 0), Point(2, 2));
    Segment shifted = original << 1.0;

    EXPECT_DOUBLE_EQ(shifted.calculateY(-1), -1);
    EXPECT_DOUBLE_EQ(shifted.calculateY(0), 0);
    EXPECT_DOUBLE_EQ(shifted.calculateY(1), 1);
}

TEST(SegmentTest, ReadFromStream)
{
    std::stringstream ss("1.5 2.5 3.5 4.5");
    Segment seg = Segment::readFrom(ss);

    EXPECT_DOUBLE_EQ(seg.calculateY(2.5), 3.5);
}

TEST(SegmentTest, OutputOperator)
{
    Segment seg(Point(1, 2), Point(3, 4));
    std::stringstream ss;
    ss << seg;
    std::string expected = "Segment from (1, 2) to (3, 4)";
    EXPECT_EQ(ss.str(), expected);
}

TEST(SegmentTest, EdgeCases)
{
    // Точка в начале сегмента
    Segment seg1(Point(0, 0), Point(2, 2));
    EXPECT_DOUBLE_EQ(seg1.calculateY(0), 0.0);

    // Точка на конце сегмента
    EXPECT_DOUBLE_EQ(seg1.calculateY(2), 2.0);

    // Точка снаружи сегмента (слева)
    EXPECT_THROW(seg1.calculateY(-1), std::invalid_argument);

    // Точка снаружи сегмента (справа)
    EXPECT_THROW(seg1.calculateY(3), std::invalid_argument);
}

// Основная функция для запуска всех тестов
int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}