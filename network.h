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
#include <iostream>
//Diogenes Core
class network
{
private:
    double learningrate_;

    std::vector<layer> layers;
    layer outputlayer;
public:

    network(layer base, double rate, int outputsize);

    double getlearningrate() const;
    void setlearningrate(double rate);

    std::vector<double> produceoutput();

    int think();

    double calculatecost();
    
    void addlayer(int size);

    void tunelayers();

    void tunelayer(layer& L, layer& pastlayer);

    void readdata();


    void setfirstlayer(layer lay);

    layer getinputlayer() const;
};
