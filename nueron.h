#pragma once

#include <vector>

class neuron {
private:
    std::vector<int> condition_; //conditions
    bool fire_;
public: 
    neuron(); //default constructor 
    
    bool isfireing();
    
    bool getfire() const;
    void setfire(bool fire);
    
    std::vector<int> getcondition() const;
    void setcondition(std::vector<int> condition); 
};
