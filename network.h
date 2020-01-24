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

#include <vector>

#include "layer.h"

class network 
{
private:
    std::vector<layer> layers;
public:
    
    void train();
};
