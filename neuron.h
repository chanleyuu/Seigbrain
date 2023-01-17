/*
* neuron.h
*
* Version information
* Author: Conall Hanley
* Date:19/01/2020
* Description: This file is the header file for the neuron class and declares the class interface. 
*
* Copyright notice -
*/ 

#pragma once

#include <vector>
#include <algorithm> 
#include <math.h>
#include <CL/opencl.hpp>
#include "my_math.h"


class neuron 
{
private:
    inline static int number_;
    //std::vector<int> condition_; //conditions
    inline static double activation_;
    inline static std::vector<double> weights_;
    inline static double bias_;
    inline static double delta_;
    inline static const double* euler_; //Euler constant
 //   double output_;
public: 
    neuron(double* euler); //default constructor 
    
    neuron(int num, double bias, const double* euler); //custom constructor 
    
    double calculateoutput(std::vector<double>& weights, std::vector<double>& inputs);
  //  double getoutput() const;
    
    std::vector<double> getweights() const;
    void addweight();
    void setweight(int index,double weight);
    int get_weight_count();
    void clear_weights();
    
    double getbias() const;
    void setbias(double bias);
    
    int getnumber() const;
    void setnumber(int num);
    
    double tranfer_derivitive();
    
    void set_activation(double act);
    double get_activation();
    
    double get_delta();
    void set_delta(double delta);
    
};
