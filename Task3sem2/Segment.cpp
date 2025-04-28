#include "Segment.h"
#include <stdexcept>

Segment::Segment(const Point& start, const Point& end) : start(start), end(end) {}

double Segment::calculateY(double x) const 
{
    double x1 = start.getX();
    double y1 = start.getY();
    double x2 = end.getX();
    double y2 = end.getY();

    if (x1 == x2) 
    {
        if (x == x1) 
        {
            return (y1 + y2) / 2.0;
        }
        else {
            throw std::invalid_argument("x находится не на вертикальном сегменте");
        }
    }

    double slope = (y2 - y1) / (x2 - x1);
    return y1 + slope * (x - x1);
}

Segment Segment::operator<<(double shift) const 
{
    Point newStart(start.getX() - shift, start.getY());
    Point newEnd(end.getX() - shift, end.getY());
    return Segment(newStart, newEnd);
}

Segment Segment::readFrom(std::istream& is) 
{
    double x1, y1, x2, y2;
    is >> x1 >> y1 >> x2 >> y2;
    return Segment(Point(x1, y1), Point(x2, y2));
}

std::ostream& operator<<(std::ostream& os, const Segment& segment) 
{
    os << "Segment из (" << segment.start.getX() << ", " << segment.start.getY()
        << ") to (" << segment.end.getX() << ", " << segment.end.getY() << ")";
    return os;
}