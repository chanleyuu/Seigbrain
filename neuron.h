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

class neuron 
{
private:
    int number_;
    //std::vector<int> condition_; //conditions
    double activation_threshhold;
    double weight_;
    double bias_;
 //   double output_;
public: 
    neuron(); //default constructor 
    
    neuron(int num, double weight, double bias); //custom constructor 
    
    double calculateoutput(std::vector<double>* check = NULL);
  //  double getoutput() const;
    
    double getweight() const;
    void setweight(int weight);
    
    double getbias() const;
    void setbias(int bias);
    
    int getnumber() const;
    void setnumber(int num);
};
