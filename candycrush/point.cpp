#include "point.h"

Point::Point()
{
      points=0;
}

Point::~Point()
{

}

void Point::backZero()
{
    points=0;
}
void Point::changePoint(int a)
{
    points+=a;

}
int Point::get()
{
    return points;
}

