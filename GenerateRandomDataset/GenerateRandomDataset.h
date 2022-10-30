// bonne pratique pour éviter les doubles déclarations et les conflits
#ifndef GENERATERANDOMDATASET_H
#define GENERATERANDOMDATASET_H

#include <stdio.h>
#include <stdint.h>
#include "Point.h"

class Dataset
{
    private:
        uint8_t nb_data;
        Point* data_coordinates;

    public:
        Dataset();
        Dataset(uint8_t nb);
        ~Dataset();
        void DispayData();
};

#endif