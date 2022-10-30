// #include <iostream>
#include <stdio.h>                                           
#include "GenerateRandomDataset/Point.h"
#include "GenerateRandomDataset/GenerateRandomDataset.h"
#include <stdint.h>

/* #include <vector>
#include "matplotlib-cpp-master/matplotlibcpp.h" */

int main(int argc, char *argv[])
{
    // Point class test
    Point A;
    printf("x = %f \ny = %f \n",A.x1,A.x2);

    // Dataset class test
    Dataset* dataset_ptr = new Dataset( uint16_t(300) );
    std::cout << (*dataset_ptr);

 
    // test writing in .dat file
    dataset_ptr->WriteDataInFile();
    system("gnuplot graph.p -persist");

    // test matplotlib-cpp
/*     std::vector<double> y = {1, 3, 2, 4};
    matplotlibcpp::plot(y);
    matplotlibcpp::savefig("minimal.pdf"); */


    return 0;
}