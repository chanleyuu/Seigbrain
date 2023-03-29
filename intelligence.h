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
//#include "layer.h"
#include "network.h"

//This class houses the Diogenes Core(s)
class intelligence
{
private:
    int generation_;
    std::vector<double> inputs_;
    //std::vector<network>* gen = new std::vector<network>;
    network* model_;
    double learningrate;
    std::vector<int> outputsizes;
public:
    intelligence(std::vector<double>& inputs, network* model); //constructor
    ~intelligence();//destructor
    
    void addnetwork();
    void train_examples(std::vector<std::vector<double>> data, std::vector<std::vector<double>> correct);
    void setinputs(std::vector<double> l);

    std::vector<double> getinputs() const;

    int getgeneration() const;
    void setgeneration(int generation);
    std::vector<double> get_current_outputs();
    network* get_model();
    
    void set_model(network* model);
};
