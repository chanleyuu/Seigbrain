/*
* layer.h
*
* Version information
* Author: Conall Hanley
* Date:22/01/2020
* Description: This file is the header file for the layer class and declares the class interface. 
*
* Copyright notice -
*/ 

#pragma once

#include <vector>

#include "neuron.h"

class layer
{
private:
    std::vector<neuron> neurons_;
    
    double sensetivity;
    double rate;
	double cost_;
    layer* nextLayer;
public:
    layer(layer* next = NULL); //default constructor
    
    std::vector<neuron> getneurons() const;
    void addneuron(neuron n);
    void removeneuron(int number);
    neuron getneuron(int number);
    int getsize();
    
    void conntectneurons(layer l);

	double getcost() const;
	void caluclatecost(layer correct);
    
    double getsensitivity() const;
    void calculatesensitivity(layer& lastgen);
    void nudge();
};
