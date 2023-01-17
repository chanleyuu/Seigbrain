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
    inline static std::vector<neuron> neurons_;
    
    inline static double sensetivity;
    inline static double rate;
    inline static double cost_;
    inline static const double* euler_;
public:
    layer();//default constructor ;No initialazation for euler constant pointer
    layer(const double* euler); 
    layer(std::vector<double> inputs, const double* euler); //constructor for base layer
    
    std::vector<neuron> getneurons() const;
    void addneuron(neuron n);
    void removeneuron(int number);
    void setnuerons(std::vector<neuron> inputs);
    neuron getneuron(int number);
    int getsize();
    
    std::vector<double> getactivations();
    std::vector<double> getweights();
    void conntectneurons(layer l);

	double getcost() const;
    void feedforward(layer prev);
	void caluclatecost(layer correct);
    
    double getsensitivity() const;
    void calculatesensitivity(layer& lastgen);
    void nudge(); 
};
