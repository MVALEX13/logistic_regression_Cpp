#include "Model.h"
#include <ctime>                // for time function
#include <cstdlib>              // for rand function
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include "eigen3/Eigen/Core"    // for MatrixX

Model1::Model1() 
{   
    std::srand(std::time(0));
    for (int i = 0; i < nb_model_func; i++)
    {
        (this->Theta)(i) = 2 + ( rand()%100 )/ 20.0;
    }

    this->data = nullptr ;
    this->data_nb = 0;
    this->cost = 0.0;
    this->alpha = 0.01;

    // opening in writing mode and writing the column names
    this->f_results.open("results.txt", std::ios::out);
    for (int i = 0; i < nb_model_func; i++)
    {
        std::string col_name = "Theta" + std::to_string(i);
        this->f_results << col_name << '\t';
    }
    this->f_results << "cost" << '\t'
                    << this->nb_it << std::endl;
    this->f_results.close();

}

Model1::Model1(const Dataset& dataset, int nb_it_input) 
{   
    std::srand(std::time(0));
    for (int i = 0; i < nb_model_func; i++)
    {
        (this->Theta)(i) = 2 + ( rand()%100 )/ 100.0;
    }

    this->data_nb   = dataset.GetDatasetSize();
    this->data = new Point[ this->data_nb ];
    this->decisions = new float[ this->data_nb ];
    this->alpha = 0.01;
    this->cost = 0.0;
    this->nb_it = nb_it_input;

    for (uint16_t i = 0; i < this->data_nb ; i++)
    {
        (this->data)[i] = dataset.GetPoint(i);
        (this->decisions)[i] = sigmoid( this->GetPoint(i) );                                       
    }


    // opening in writing mode and writing the column names
    this->f_results.open("results.txt", std::ios::out);
    for (int i = 0; i < nb_model_func; i++)
    {
        std::string col_name = "Theta" + std::to_string(i);
        this->f_results << col_name << '\t';
    }
    this->f_results << "cost" << '\t'
                    << this->nb_it << std::endl;
    this->f_results.close();


}

float Model1::Phi0(const Point& p) const { return 1.0; }

float Model1::Phi1(const Point& p) const { return p.GetX1(); }

float Model1::Phi2(const Point& p) const { return p.GetX2(); }

float Model1::sigmoid(const Point& p) const
{
    float linear_comb = this->Theta(0)*Phi0(p) + this->Theta(1)*Phi1(p) + this->Theta(2)*Phi2(p);
    float h = 1.0 / (1.0 + exp(-linear_comb) );
    return h; 
}

void Model1::ComputeDecisions()
{
                                      
    // creating matrix containing the model functions evaluated at each point
    Eigen::MatrixXd X( this->data_nb , this->nb_model_func );
    for ( uint16_t i = 0 ; i < this->data_nb ; i++ )
    {
        X(i,0) = Model1::Phi0( this->GetPoint(i) );
        X(i,1) = Model1::Phi1( this->GetPoint(i) );
        X(i,2) = Model1::Phi2( this->GetPoint(i) );
    }

    // creating the decisions vector h and a vector y to store the true output of the point
    Eigen::VectorXd h( this->data_nb );
    Eigen::VectorXd y( this->data_nb );
    for ( uint16_t i = 0 ; i < this->data_nb ; i++ )
    {
        h(i) = Model1::sigmoid( this->GetPoint(i) );
        y(i) = this->GetPoint(i).GetY();
    }

    // computing the Gradient
    this->Grad = X.transpose()*(h - y);

    // one step of gradient descent algo
    this->Theta = (this->Theta)-(this->alpha)*(this->Grad)/(this->Grad).norm();

    // std::cout << "Theta : " << (this->Theta)(0) << '\t' << (this->Theta)(1) << '\t' << (this->Theta)(2) << "\t\t"; 
    // std::cout << "Grad : " << (this->Grad)(0) << '\t' << (this->Grad)(1) << '\t' << (this->Grad)(2) << std::endl;


    // computing the new decisions
    for (uint16_t i = 0; i < this->data_nb ; i++)
    {
        (this->decisions)[i] = sigmoid( this->GetPoint(i) );                                       
    }

    // cost compuation
    this->cost = 0;
    for (int i =0; i < this->data_nb; i++)
    {
        this->cost += -y(i)*log( h(i) ) - ( 1 - y(i) )*log( 1 - h(i) );
    }

    // we add lines to the already existing data txt file
    f_results.open("results.txt", std::ios::app);
    for (int i = 0; i < nb_model_func; i++)
    {
        this->f_results << Theta(i) << '\t';
    }
    this->f_results << cost << std::endl;
    this->f_results.close();
}


Point& Model1::GetPoint( uint16_t point_index) const
{
    return this->data[point_index];
}

void Model1::CreatePythonPlotScript() const
{
    std::fstream f;
    f.open("DecisionFunction.py",std::ios::out);
    if (!f)
        std::cout << "no .py file created " << std::endl;
    
    f<< "import numpy as np "                               << std::endl
     << "def func(x1,x2):"                                  << std::endl
     << "\t" << "return (" << Theta(0) <<"*1 + " << Theta(1) << "*x1 + " << Theta(2) <<"*x2)" << std::endl;

     f.close();

     std::cout << "alpha : " << this->alpha << std::endl;

}



void Model1::CreateGNUplotScript() const
{
    std::fstream f;
    f.open("graph.p",std::ios::out);
    if (!f)
        std::cout << "no GNUplot file created " << std::endl;
    
    f<< "set title 'data'"                                 << std::endl
     << "set xlabel 'x1'"                                  << std::endl
     << "set ylabel 'x2'"                                  << std::endl
     << "set xrange [2.0:10.0]"                            << std::endl
     << "set yrange [2.0:10.0]"                            << std::endl
     << "set grid"                                         << std::endl
     << "set palette rgb 33,13,10"                         << std::endl
     << "plot 'Dataset.dat' using 1:2:3 ls 7 ps 2 palette" << std::endl
     << "set contour base"                                 << std::endl
     << "set cntrparam level incremental -3, 0.5, 3"       << std::endl
     << "set cntrparam levels 15"                          << std::endl
     << "f(x,y) = x+y"                                     << std::endl
     << "set isosample 250, 250"                           << std::endl
     << "replot f(x,y)"                                    << std::endl
     << "set contour base"                                 << std::endl;
     
    f.close();    
}

Eigen::VectorXd Model1::GetTheta() const { return Theta; }

Model1::~Model1()
{
    // just in case even though the Eigen::vector hasn't been alocated dynamically
    Theta.resize(0);
    Grad.resize(0);

    // closing the file containing the theta evolution data
    f_results.close();

    delete[] data;
}