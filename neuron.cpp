/*
* neuron.cpp
*
* Version information
* Author: Conall Hanley
* Date:19/01/2020
* Description: This file is the implementation file for the Neuron class and defines (implements) the functions of the class
*
* Copyright notice -
*/ 

#include "neuron.h"

neuron::neuron() : number_{ 1 } 
{
    
}

neuron::neuron(int num, double weight, double bias) : number_{ num }, weight_{ weight }, bias_{ bias }
{
    
}

double neuron::getoutput(std::vector<double> check)
{
    double avg = 0.0;
    int n = check.size();
    for (int i = 0; i < n; i++) {
        avg += check[i];
    }
    avg = avg / (double) n;
    return avg + bias_;
}


double neuron::getweight() const 
{
    return weight_;
}

int neuron::getnumber() const
{
    return number_;
}

void neuron::setnumber(int num)
{
    number_ = num;
}
