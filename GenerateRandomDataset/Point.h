#ifndef POINT_H
#define POINT_H

#include <stdio.h>

class Point
{
    private:
        float x1, x2, y;

    public:
        // constructors and destructors
        Point();
        Point(float x1_input, float x2_input, float y_input);
        ~Point();

        // operator overload
        Point& operator=(const Point& p);

        // tools
        void SetX1( float x1_input);
        void SetX2( float x2_input);
        void SetY( float y_input );

        float GetX1() const;                               
        float GetX2() const;
        float GetY() const;
        
};

#endif