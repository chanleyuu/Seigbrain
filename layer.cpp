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
    for (int i = 0; i > lneurons.size(); i++) 
    {
        weights.push_back(lneurons[i].getweight());
    }
    
    for (int i = 0; i < neurons_.size(); i++)
    {
        neurons_[i].calculateoutput(weights); 
    }
}

double layer::getsensitivity() const
{
    return sensetivity;
}


//Layer takes the previous values as an input
void layer::calculatesensitivity(layer lastgen)
{
    double out;
    for (int i = 0; i < this->neurons_.size(); i++) {
       double changeweight = neurons_[i].getweight() - lastgen.getneuron(i).getweight();
       double changebias = neurons_[i].getbias() - lastgen.getneuron(i).getbias();
       out *= changeweight / changebias;
    }
}


double layer::getcost() const
{
    return cost_;
}

void layer::caluclatecost()
{
    int n = neurons_.size();
    double avg = 0.0;
    for (int i = 0; i < n; i++) {
       avg += neurons_[i].getweight();
    }
    
    avg = avg / (double) n;
    cost_ = 1.0 - avg;
}


