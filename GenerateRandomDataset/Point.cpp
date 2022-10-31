#include "Point.h"
#include <iostream>

Point::Point() : x1(0), x2(0), y(0)
{
    // nothing to do
}

Point::Point(float x1_input, float x2_input, float y_input): x1(x1_input), x2(x2_input),y(y_input)
{
    // nothing to do
}

// return a Point element in case we invoke a triple assignment a = b = c which leads to a = b.operator=(c) -- this way in works
 Point& Point::operator=(const Point& p)
{
    this->x1 = p.x1;
    this->x2 = p.x2;
    this->y = p.y;
    return *this;
}
void Point::SetX1 (float x1_input)    { this->x1 = x1_input; }
void Point::SetX2 (float x2_input)    { this->x2 = x2_input; }
void Point::SetY( float y_input)      { this->y = y_input; }

float Point::GetX1() const            { return this->x1; }
float Point::GetX2() const            { return this->x2; }
float Point::GetY() const             { return this->y;  }


Point::~Point()
{
    // nothing to do
    // std::printf("the destructor of point has been called \n");
}