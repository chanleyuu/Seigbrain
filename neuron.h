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
    double weight_;
    double bias_;
public: 
    neuron(); //default constructor 
    
    neuron(int num, double weight, double bias); //custom constructor 
    
    double getoutput(std::vector<double> check);
    
    double getweight() const;
    
    std::vector<int> getcondition() const;
    void setcondition(std::vector<int> condition); 
    
    int getnumber() const;
    void setnumber(int num);
};
