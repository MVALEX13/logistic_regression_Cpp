#include "GenerateRandomDataset.h"
#include <cmath>                                // for round() function
#include <cstdlib>                              // for srand() function
#include <time.h>                               // for time() function
#include <fstream>


Dataset::Dataset(uint8_t nb)
{
    // allocation of the space for storing the datas
    nb_data = nb;
    data_coordinates = new Point[nb_data];

    // generation of random coordonates for the datas
    uint8_t half_data = round(nb_data/2);
    std::printf("half_rand = %d \n",half_data);
    srand(time(0));                                                 // change the random sequence of numbers
    float x1center; float x2center;

    // points whose state is false
    x1center = 2.1; x2center = 3.7;
    for (int i =0; i< half_data; i++)
    {
        data_coordinates[i].x1 = x1center + (rand()%10)/10.0;
        data_coordinates[i].x2 = x2center + (rand()%10)/10.0;
        data_coordinates[i].y = false;
    }

    // points whose state is true
    x1center = 4.1; x2center = 4.8;
    for (int i = half_data; i< nb_data; i++)
    {
        data_coordinates[i].x1 = x1center + (rand()%10)/10.0;
        data_coordinates[i].x2 = x2center + (rand()%10)/10.0;
        data_coordinates[i].y = true;
    }
}

void Dataset::WriteDataInFile()
{
    std::fstream f;
    f.open("Dataset.dat",std::ios::out);
    f << " # x1" << "\t" << "x2" << "\t" << "y" << std::endl;
    
    for (int i = 0; i<nb_data ; i ++)
    {
        f << this->data_coordinates[i].x1 << "\t"
          << this->data_coordinates[i].x2 << "\t"
          << this->data_coordinates[i].y  << std::endl;
    }
    f.close();
}

std::ostream& operator<< (std::ostream& flux, Dataset const& d)
{
    for (int i = 0; i< (d.nb_data); i++)
    {
        flux << "point["<<i<<"] = ("<< d.data_coordinates[i].x1 << "," << d.data_coordinates[i].x2 <<") y = "<<d.data_coordinates[i].y << " \n";
    }
    return flux;
}


Dataset::~Dataset()
{
    delete[] data_coordinates;
    std::printf("\nThe destructor of Dataset has been called \n");
}