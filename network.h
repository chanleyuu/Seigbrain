/*
* network.h
*
* Version information
* Author: Conall Hanley
* Date:22/01/2020
* Description: This file is the header file for the network class and declares the class interface. 
*
* Copyright notice -
*/ 


#pragma once

//#include <vector>



#include "layer.h"
//Diogenes Core
class network 
{
private:
    double learningrate;
    
    layer baselayer;
    layer hiddenlayer1;
    layer hiddenlayer2;
    layer outputlayer;
public:
    
    network(layer base);
    
    double getlearningrate() const;
    void setlearningrate(double rate);
    
    int produceoutput();
    
    int think();
    
    double calculatecost();
    
    void train();
    
    void tunelayer(layer& L, layer& pastlayer);
    
    void readdata();
    
    
    void setfirstlayer(layer lay);
};
