// #include <iostream>
#include <stdio.h>                                           
#include "GenerateRandomDataset/Point.h"
#include "GenerateRandomDataset/GenerateRandomDataset.h"
#include <stdint.h>                                               // for uintX_t type

/* #include <vector>
#include "matplotlib-cpp-master/matplotlibcpp.h" */


int main(int argc, char *argv[])
{
    // Point class test
    Point A;
    printf("x = %f \ny = %f \n",A.GetX1(),A.GetX2());

    // Dataset class test
    Dataset* dataset_ptr = new Dataset( uint16_t(300) );
    std::cout << (*dataset_ptr);

 
    // test writing in .dat file
    dataset_ptr->WriteDataInFile();
    system("gnuplot graph.p -persist");

    return 0;
}
