// #include <iostream>
#include <stdio.h>                                           
#include "GenerateRandomDataset/Point.h"
#include "GenerateRandomDataset/GenerateRandomDataset.h"

#include <vector>
/* #include "matplotlib-cpp-master/matplotlibcpp.h" */

int main(int argc, char *argv[])
{
    // Point class test
    Point A;
    printf("x = %f \ny = %f \n",A.x1,A.x2);

    // Dataset class test
    Dataset dataset_1(20);
    std::cout << dataset_1;

 
    // test writing in .dat file
    dataset_1.WriteDataInFile();
    system("gnuplot graph.p -persist");

    // test matplotlib-cpp
    std::vector<double> y = {1, 3, 2, 4};
A

    return 0;
}