#include "GenerateRandomDataset.h"
#include <cmath>                                // for round() function
#include <fstream>
#include <random>
#include <stdint.h>


Dataset::Dataset(uint16_t nb)
{
    // allocation of the space for storing the datas
    this->nb_data = nb;
    data_coordinates = new Point[nb_data];

    // generation of random coordonates for the datas
    uint16_t half_data = round( (this->nb_data)/2 );
    std::printf("half_rand = %d \n",half_data);

    // points whose state is false
 
    std::default_random_engine generator;
    std::normal_distribution<float> distributionX1(4.0,0.6);

    for (int i =0; i< half_data; i++)
    {   
        data_coordinates[i].SetX1( distributionX1(generator) ) ;
        data_coordinates[i].SetX2( distributionX1(generator) ) ;
        data_coordinates[i].SetY( 0.0 ) ;
    }

    std::normal_distribution<double> distributionX2(7.0,0.8);

    // points whose state is true
    for (int i = half_data; i< this->nb_data; i++)
    {
        data_coordinates[i].SetX1( distributionX2(generator) ) ;
        data_coordinates[i].SetX2( distributionX2(generator) ) ;
        data_coordinates[i].SetY( 1.0 ) ;
    }
}

void Dataset::WriteDataInFile()
{
    std::fstream f;
    f.open("Dataset.dat",std::ios::out);
    f << " # x1" << "\t" << "x2" << "\t" << "y" << std::endl;
    
    for (int i = 0; i<nb_data ; i ++)
    {
        f << this->data_coordinates[i].GetX1() << "\t"
          << this->data_coordinates[i].GetX2() << "\t"
          << this->data_coordinates[i].GetY()  << std::endl;
    }
    f.close();
}

uint16_t Dataset::GetDatasetSize() const
{
    return (this->nb_data) ;
}

Point& Dataset::GetPoint(uint16_t point_index) const
{
    return this->data_coordinates[point_index];
}

std::ostream& operator<< (std::ostream& flux, Dataset const& d)
{
    for (int i = 0; i< (d.nb_data); i++)
    {
        flux << "point["<<i<<"] = ("
             << d.data_coordinates[i].GetX1() << "," 
             << d.data_coordinates[i].GetX2() <<") y = "
             <<d.data_coordinates[i].GetY() << " \n";
    }
    return flux;
}


Dataset::~Dataset()
{
    delete[] data_coordinates;
    std::printf("\nThe destructor of Dataset has been called \n");
}