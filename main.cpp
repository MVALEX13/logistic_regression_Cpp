// #include <iostream>
#include <stdio.h>                                           
#include "GenerateRandomDataset/Point.h"
#include "GenerateRandomDataset/GenerateRandomDataset.h"

int main(int argc, char *argv[])
{
    // Point class test
    Point A;
    printf("x = %f \ny = %f \n",A.x1,A.x2);

    // Dataset class test
    Dataset dataset_1(20);
    std::cout << dataset_1;

    return 0;
}