#ifndef MODEL_H
#define MODEL_H

#include <stdio.h>
#include "../GenerateRandomDataset/Point.h"
#include "../GenerateRandomDataset/GenerateRandomDataset.h"
#include <stdint.h>                                             // for uint8_t
#include "eigen3/Eigen/Core"                                    // for VectorXd  
#include <fstream>                                              // file flux creation  

// Fonctions of the model Phi0(x1,x2) = 1; Phi1(x1,x2) = x1 ; Phi2(x1,x2) = x2
class Model1
{   
    // 3 functions model
    uint8_t const nb_model_func = 3;                // nb of functions uses to construct the model

    // initial guess of the model parameters
    Eigen::VectorXd Theta = Eigen::VectorXd(3);     // vector of parameters to optimize

    // points coordinates with the model decision in y 
    Point* data;                                    // data from the dataset
    uint16_t data_nb;                               // nb of data
    float* decisions;                               // vector of decisions according to the model for each data point
    Eigen::VectorXd Grad = Eigen::VectorXd(3);      // gradient ( in the class outside of a method the attribute might be declared that way)
    float alpha;                                    // descent step for gradient algo
    std::fstream f_results;                         // file in which all the results will be witten for plotting
    float cost;
    int nb_it;

    public:
    // constructors & destructors
    Model1();
    Model1(const Dataset& dataset, int nb_int_input);
    ~Model1();

    // mathematical model
    float Phi0(const Point& p) const;
    float Phi1(const Point& p) const;
    float Phi2(const Point& p) const;
    float sigmoid(const Point& p) const;

    void ComputeDecisions();

    // tools
    Point& GetPoint( uint16_t point_index ) const;
    void CreatePythonPlotScript() const;
    Eigen::VectorXd GetTheta() const;

    // unused method 
    void CreateGNUplotScript() const;
    
};
#endif