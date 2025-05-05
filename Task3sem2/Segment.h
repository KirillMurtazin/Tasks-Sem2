#pragma once
#include "Point.h"
#include <iostream>

class Segment
{
private:
    Point start;
    Point end;
public:
    Segment(const Point& start, const Point& end);
    double calculateY(double x) const;
    Segment operator<<(double shift) const;
    static Segment readFrom(std::istream& is);
    friend std::ostream& operator<<(std::ostream& os, const Segment& segment);
};