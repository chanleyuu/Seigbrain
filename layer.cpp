/*
* layer.cpp
*
* Version information
* Author: Conall Hanley
* Date:22/01/2020
* Description: This file is the implementation file for the layer class and defines (implements) the functions of the class
*
* Copyright notice -
*/ 

#include "layer.h"

layer::layer()
{
    
}

std::vector<neuron> layer::getneurons() const
{
    return neurons_;
}

void layer::addneuron(neuron n)
{
    neurons_.push_back(n);
}

void layer::removeneuron(int number)
{
    for (int i = 0; i < neurons_.size(); i++) {
        if (neurons_[i].getnumber() == number) {
            neurons_.erase(neurons_.begin() + i);
        }
    }
}

neuron layer::getneuron(int number)
{
   for (int i = 0; i < neurons_.size(); i++) {
        if (neurons_[i].getnumber() == number) {
            return neurons_[i];
        }
    } 
    return neurons_[0];
}

void layer::conntectneurons(layer l)
{
    std::vector<neuron> lneurons = l.getneurons();
    std::vector<double> weights;
    for (int i = 0; i > l.size(); i++) 
    {
        
    }
}



