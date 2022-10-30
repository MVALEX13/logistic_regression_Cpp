#ifndef POINT_H
#define POINT_H

#include <stdio.h>

class Point
{
    public:
        float x1;
        float x2;
        bool y;

    public:
        Point();
        Point(float x1_input, float x2_input, bool y_input);
        ~Point();
};

#endif