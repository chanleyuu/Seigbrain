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
#include <iostream>

#include "neuron.h"

class layer
{
private:
    std::vector<neuron>* neurons_ = nullptr;
    
    double sensetivity;
    double rate;
    double cost_;
    const double* euler_;
public:
    layer();//default constructor ;No initialazation for euler constant pointer
    layer(const double* euler); 
    layer(std::vector<double> inputs, const double* euler); //constructor for base layer
    
    ~layer(); //destructor
    
    std::vector<neuron>* getneurons() const;
    void addneuron(neuron n);
    void removeneuron(int number);
    void setnuerons(std::vector<neuron> inputs);
    //neuron getneuron(int number);
    long getsize();
    
    std::vector<double> getactivations();
    std::vector<double> getweights();
    void conntectneurons(layer l);

	double getcost() const;
    void feedforward(layer prev);
	void caluclatecost(layer correct);
    
    double getsensitivity() const;
    void setsensitivity(double sense);
    void calculatesensitivity(layer& lastgen);
    void init_vector();
    void delete_vector();
    void nudge(); 
    void copyweights(layer copyfrom, int nextlayersize);
};
