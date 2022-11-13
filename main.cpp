// #include <iostream>
#include <stdio.h>                                           
#include "GenerateRandomDataset/Point.h"
#include "GenerateRandomDataset/GenerateRandomDataset.h"
#include <stdint.h>                                               // for uintX_t type
#include "Model/Model.h"

#include <fstream>

/* #include <vector>
#include "matplotlib-cpp-master/matplotlibcpp.h" */


int main(int argc, char *argv[])
{
    // Point class test
    Point A;

    // Dataset class test
    Dataset* dataset_ptr = new Dataset( uint16_t(500) );
    //std::cout << (*dataset_ptr);

 
    // test writing in .dat file
    dataset_ptr->WriteDataInFile();
    
    // test Model1
    int nb_it = 2000;
    Model1 M( *dataset_ptr , nb_it);
    // M.CreateGNUplotScript();


    for (int i = 0; i < 1 ; i++)
    {
        for(int j = 0; j < nb_it; j ++ )
        {
            // std::cout << "epoch : " << 200*i+j << "\t\t";
            M.ComputeDecisions();
        }
    }

    system("python3 plot_results.py");

    // M.ComputeDecisions();
    //M.CreatePythonPlotScript();
    //system("python3 graph.py");

    return 0;
}
