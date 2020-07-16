/*
* intelligence.h
*
* Version information
* Author: Conall Hanley
* Date:22/01/2020
* Description: This file is the header file for the intellegence class and declares the class interface. 
*
* This class manages the various generations of networks in order to train them
* Copyright notice -
*/ 


#pragma once

#include <vector>
#include "network.h"

//This class houses the Diogenes Core(s)
class intelligence
{
private:
    vector<network> gen;
public:
    intelligence(layer firstlayer);
    
    void addnetwork();
    void train();
}
