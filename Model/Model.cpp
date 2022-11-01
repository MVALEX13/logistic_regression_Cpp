#include "Model.h"
#include <ctime>            // for time function
#include <cstdlib>          // for rand function
#include <cmath>
#include <fstream>

Model1::Model1() 
{
    (this->Theta0) = new float[nb_model_func];
    
    std::srand(std::time(0));
    for (int i = 0; i < nb_model_func; i++)
    {
        (this->Theta0)[i] = 1 + ( rand()%100 )/ 100.0;
    }

    this->decisions = nullptr ;
    this->data_nb = 0;
}

Model1::Model1(const Dataset& dataset) 
{
    this->Theta0    = new float[nb_model_func];
    this->data_nb   = dataset.GetDatasetSize();
    this->decisions = new Point[ this->data_nb ];

    for (uint16_t i = 0; i < this->data_nb ; i++)
    {
        (this->decisions)[i] = dataset.GetPoint(i);
    }
}

float Model1::Phi0(const Point& p) const { return 1.0; }

float Model1::Phi1(const Point& p) const { return p.GetX1(); }

float Model1::Phi2(const Point& p) const { return p.GetX2(); }

float Model1::sigmoid(const Point& p) const
{
    float linear_comb = this->Theta0[0]*Phi0(p) + this->Theta0[1]*Phi1(p) + this->Theta0[2]*Phi2(p);
    float h = 1.0 / (1.0 + exp(-linear_comb) );
    return h; 
}

void Model1::ComputeDecisions()
{
    float decision_i = 0;
    for (uint16_t i = 0; i < this->data_nb ; i++)
    {
        decision_i = sigmoid( this->GetPoint(i) );
        this->decisions[i].SetY( decision_i );
    }
}

Point& Model1::GetPoint( uint16_t point_index) const
{
    return this->decisions[point_index];
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

Model1::~Model1()
{
    delete[] Theta0;
    delete[] decisions;
}