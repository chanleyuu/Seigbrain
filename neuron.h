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
    int number_;
    int weightcount_ = 0;
    //std::vector<int> condition_; //conditions
    double activation_ = 0.0;
    double* weights_ = nullptr;
    double bias_;
    double delta_;
    const double* euler_; //Euler constant
    bool nobias = false;
 //   double output_;
public: 
    neuron(double* euler); //default constructor 
    
    neuron(int num, double bias, const double* euler); //custom constructor 
    
    ~neuron();//destructor
    
    double calculateoutput_sigmoid(std::vector<double>& inputs, double weights[], int weightcount);
    double calculateoutput_relu(std::vector<double>& inputs, double weights[], int weightcount);
  //  double getoutput() const;
    
    double* getweights() const;
    //void addweight();
    void setweights(std::vector<double> weights);
    void setweights(double weights[], int count);
    void addweights(double weights[]);
    void divideweights(int divisor);
    
    int get_weight_count();
    void clear_weights();
    
    double getbias() const;
    void setbias(double bias);
    void dividebias(int divisor);
    
    int getnumber() const;
    void setnumber(int num);
    
    double tranfer_derivitive();
    
    void set_activation(double act);
    double get_activation();
    
    void init_activation();
    void clear_activation();
    
    double get_delta();
    void set_delta(double delta);
    
};
