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

neuron::neuron(double* euler)
{
    number_ = 0;
    activation_ = 0.0;
    weightcount_ = 0;
    bias_ = 0.0;
    euler_ = euler;
}

neuron::neuron(int num, double bias, const double * euler)
{
    number_ = num;
    bias_ = bias;
    euler_ = euler;
}

neuron::~neuron()
{
    //delete weights_;
}


//the vector check is the previous layer's outputs
double neuron::calculateoutput( std::vector<double>& inputs, double weights[])
{
    double activation = 0.0;
    for (int i = 0; i < weightcount_; i++) {
        activation += (weights_[i] * inputs.at(i));
    }
    activation += bias_;
    activation = 1.0 / (1.0 +  pow(*euler_, -1.0 * activation_));
    //delete weights;
    //delete inputs;
    activation_ = activation;
    return activation;
}

double* neuron::getweights() const 
{
    /*
    std::vector<double> out;
    for (int i = 0; i < sizeof(weights_); i++){
        out.push_back(weights_[i]);
    } */
    return weights_;
}

void neuron::setweights(std::vector<double> weights) 
{
    //weights_->at(index) = weight;
    weightcount_ = weights.size();
    weights_ = new double[weights.size()];
    for (int i = 0; i < weights.size(); i++) {
            weights_[i] = weights.at(i);
    }
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

/*
void neuron::addweight()
{
    weights_->push_back(0.0);
} */

int neuron::get_weight_count()
{
    return sizeof(*weights_);
}

void neuron::clear_weights()
{
    //weights_->clear();
    //After clearing weights neuron should not be used until new weights are generated
    delete[] weights_;
    weights_ = nullptr;
    //weights_ = new double[];
}
