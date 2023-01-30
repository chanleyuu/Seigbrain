/*
* network.h
*
* Version information
* Author: Conall Hanley
* Date:22/01/2020
* Description: This file is the header file for the network class and declares the class interface.
*
* Copyright notice -
*/


#pragma once

#include <vector>
//#include "layer.h"
#include <iostream>
#include "my_math.h"
#include "layer.h"
//Diogenes Core
class network
{
private:
    double learningrate_;

    //Contains input layer and all hidden layers
    std::vector<layer>* layers = new std::vector<layer>();
    std::vector<double> costs_;
    std::vector<double> desire_;
    std::vector<double> inputs_;
    const double euler = my_math_euler_num();
    layer* outputlayer = new layer(&euler);
public:

    network(std::vector<double>& inputs ,int outputsize, std::vector<double> desire);
    
    network(std::vector<double>& inputs, double rate, int outputsize);

    double getlearningrate() const;
    void setlearningrate(double rate);

    std::vector<double> produceoutput();

    int think();

    double calculatecost();
    
    void addlayer(int size);

    void tunelayers();

    void tunelayer(layer& L, layer& pastlayer);

    void readdata();

    void add_inputs();
    
    void setfirstlayer(layer lay);

    layer getinputlayer() const;
    
    void set_desire(std::vector<double> desire);
    
    void init_weights();
    
    void feed();
    
    std::vector<double> get_desire();
};
