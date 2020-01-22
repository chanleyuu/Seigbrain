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

neuron::neuron() : number_{ 1 } 
{
    
}

neuron::neuron(int num, std::vector<int> cond) : number_{ num }, condition_{ cond } 
{
    
}

bool neuron::isfireing(std::vector<int> check)
{
   
    std::vector<int>::iterator it;
    it = std::search (check.begin(), check.end(), condition_.begin(), condition_.end());
        
        
    if (it!=check.end()) {
        fire_ = true;
        return true;
    }
    
    fire_ = false;
    return false;
}


bool neuron::getfire() const 
{
    return fire_;
}

std::vector<int> neuron::getcondition() const
{
    return condition_;
}

void neuron::setcondition(std::vector<int> condition)
{
    condition_ = condition;
}

int neuron::getnumber() const
{
    return number_;
}
