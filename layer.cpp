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

