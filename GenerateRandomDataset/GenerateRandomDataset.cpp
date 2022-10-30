#include "GenerateRandomDataset.h"
#include <cmath>                                // for round() function
#include <cstdlib>                              // for srand() function
#include <time.h>                               // for time() function

#define DEFAULT_DATASET_SIZE 20


Dataset::Dataset()
{
    // allocation of the space for storing the datas
    nb_data = DEFAULT_DATASET_SIZE;
    data_coordinates = new Point [nb_data];

    // generation of random coordonates for the datas
    uint8_t half_data = round(nb_data);
    srand(time(0));                                                 // change the random sequence of numbers
    float x1center; float x2center;

    // points whose state is false
    x1center = 2.1; x2center = 3.7;
    for (int i =0; i< half_data; i++)
    {
        data_coordinates[i].x1 = x1center + (rand()%10)/10;
        data_coordinates[i].x2 = x2center + (rand()%10)/10;
        data_coordinates[i].y = false;
    }

    // points whose state is true
    x1center = 4.1; x2center = 4.8;
    for (int i = half_data; i< nb_data; i++)
    {
        data_coordinates[i].x1 = x1center + (rand()%10)/10;
        data_coordinates[i].x2 = x2center + (rand()%10)/10;
        data_coordinates[i].y = true;
    }
}

Dataset::Dataset(uint8_t nb)
{
    
}

Dataset::~Dataset()
{
    delete[] data_coordinates;
}