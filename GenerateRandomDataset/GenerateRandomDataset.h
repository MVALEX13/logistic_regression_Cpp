// bonne pratique pour éviter les doubles déclarations et les conflits
#ifndef GENERATERANDOMDATASET_H
#define GENERATERANDOMDATASET_H

#include <stdio.h>
#include <stdint.h>
#include "Point.h"
#include <iostream>                         // for iostream object

class Dataset
{
    
        uint8_t nb_data;
        Point* data_coordinates;

    public:
        Dataset(uint8_t nb = 20);
        ~Dataset();

        // std::ostream& flux                 correspond au flux usuellement utilisé lorsque l'on fait cout <<
        // std::ostream& operator<<           correspond au nouveau flux capable d'afficher une variable de type Dataset
        friend std::ostream& operator<< (std::ostream& flux, Dataset const& d);
  
};

#endif