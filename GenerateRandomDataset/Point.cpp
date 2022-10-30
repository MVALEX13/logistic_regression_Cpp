#include "Point.h"
#include <iostream>

Point::Point() : x1(0), x2(0), y(0)
{
    // nothing to do
}

Point::Point(float x1_input, float x2_input, bool y_input): x1(x1_input), x2(x2_input),y(y_input)
{
    // nothing to do
}

Point::~Point()
{
    // nothing to do
    std::printf("the destructor of point has been called \n");
}