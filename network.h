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
#include "layer.h"
#include "my_math.h"
#include <iostream>
//Diogenes Core
class network
{
private:
    double learningrate_;

    std::vector<layer> layers;
    std::vector<double> costs_;
    std::vector<double> desire_;
    std::vector<double> inputs_;
    layer outputlayer;
    double euler;
public:

    network(std::vector<double> inputs ,int outputsize, std::vector<double> desire);
    
    network(std::vector<double> inputs, double rate, int outputsize);

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
    
    std::vector<double> get_desire();
};
