#ifndef MODEL_H
#define MODEL_H

#include <stdio.h>
#include "../GenerateRandomDataset/Point.h"
#include "../GenerateRandomDataset/GenerateRandomDataset.h"
#include <stdint.h>                            // for uint8_t

// Fonctions of the model Phi0(x1,x2) = 1; Phi1(x1,x2) = x1 ; Phi2(x1,x2) = x2
class Model1
{   
    // 3 functions model
    uint8_t const nb_model_func = 3;

    // initial guess of the model parameters
    float* Theta0;

    // points coordinates with the model decision in y 
    Point* decisions;
    uint16_t data_nb;

    public:
    // constructors & destructors
    Model1();
    Model1(const Dataset& dataset);
    ~Model1();

    // mathematical model
    float Phi0(const Point& p) const;
    float Phi1(const Point& p) const;
    float Phi2(const Point& p) const;
    float sigmoid(const Point& p) const;

    void ComputeDecisions();

    // tools
    Point& GetPoint( uint16_t point_index ) const;
    
};
#endif