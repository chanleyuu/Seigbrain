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
    int generation_;
    layer inputlayer;
    std::vector<network> gen;
    double learningrate;
public:
    intelligence(layer inlayer, double rate); //constructor

    void addnetwork();
    void train();
    void setinputlayer(layer l);

    layer getinputlayer() const;

    int getgeneration() const;
    void setgeneration(int gen);
};
