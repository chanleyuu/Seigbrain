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

neuron::neuron(double* euler) : number_{ 1 } , bias_{ 0.0 }, euler_{ euler }
{
    
}

neuron::neuron(int num, double bias, const double * euler) : number_{ num },  bias_{ bias }, euler_{ euler }
{
    
}

//the vector check is the previous layer's outputs
double neuron::calculateoutput(std::vector<double>* weights, std::vector<double>* inputs)
{
    
    for (int i = 0; i < weights->size(); i++) {
        activation_ += (weights->at(i) * inputs->at(i));
    }
    activation_ += bias_;
    activation_ = 1.0 / (1.0 +  pow(*euler_, -1.0 * activation_));
    delete weights;
    delete inputs;
    return activation_;
}


std::vector<double> neuron::getweights() const 
{
    return weights_;
}

void neuron::setweight(int index, double weight) 
{
    weights_[index] = weight;
}

double neuron::getbias() const 
{
    return bias_;
}

void neuron::setbias(double bias)
{
    bias_ = bias;
}

int neuron::getnumber() const
{
    return number_;
}

void neuron::setnumber(int num)
{
    number_ = num;
}

void neuron::set_activation(double act)
{
    activation_ = act;
}

double neuron::get_activation()
{
    return activation_;
}

double neuron::get_delta()
{
    return delta_;
}

void neuron::set_delta(double delta)
{
    delta_ = delta;
}

double neuron::tranfer_derivitive()
{
    return activation_ * (1.0 - activation_);
}

void neuron::addweight()
{
    weights_.push_back(0.0);
}
