#include "pch.h"

TEST(TestCaseName, TestName) 
{
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

#include <gtest/gtest.h>
#include <sstream>
#include "../Task3sem2/Point.h"
#include "../Task3sem2/Segment.h"

// Tests for Point class
TEST(PointTest, DefaultConstructor) 
{
    Point p;
    EXPECT_DOUBLE_EQ(p.getX(), 0.0);
    EXPECT_DOUBLE_EQ(p.getY(), 0.0);
}

TEST(PointTest, ParameterizedConstructor) 
{
    Point p(3.5, -2.1);
    EXPECT_DOUBLE_EQ(p.getX(), 3.5);
    EXPECT_DOUBLE_EQ(p.getY(), -2.1);
}

// Tests for Segment class
TEST(SegmentTest, Constructor) 
{
    Point p1(1, 2);
    Point p2(4, 6);
    Segment seg(p1, p2);

    EXPECT_DOUBLE_EQ(seg.calculateY(2.5), 4.0);
}

TEST(SegmentTest, CalculateY) 
{
    // Inclined segment
    Segment seg1(Point(0, 0), Point(2, 2));
    EXPECT_DOUBLE_EQ(seg1.calculateY(1), 1.0);

    // Horizontal segment
    Segment seg2(Point(2, 5), Point(6, 5));
    EXPECT_DOUBLE_EQ(seg2.calculateY(4), 5.0);

    // Vertical segment
    Segment seg3(Point(3, 0), Point(3, 4));
    EXPECT_DOUBLE_EQ(seg3.calculateY(3), 2.0);
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
    // Point at segment start
    Segment seg1(Point(0, 0), Point(2, 2));
    EXPECT_DOUBLE_EQ(seg1.calculateY(0), 0.0);

    // Point at segment end
    EXPECT_DOUBLE_EQ(seg1.calculateY(2), 2.0);

    // Point outside segment (left)
    EXPECT_THROW(seg1.calculateY(-1), std::invalid_argument);

    // Point outside segment (right)
    EXPECT_THROW(seg1.calculateY(3), std::invalid_argument);
}

int main(int argc, char** argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 