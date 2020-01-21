#pragma once

#include <vector>
#include <algorithm> 

class neuron 
{
private:
    int number_;
    std::vector<int> condition_; //conditions
    bool fire_;
public: 
    neuron(); //default constructor 
    
    neuron(int num, std::vector<int> cond); //custom constructor 
    
    bool isfireing(std::vector<int> check);
    
    bool getfire() const;
    void setfire(bool fire);
    
    std::vector<int> getcondition() const;
    void setcondition(std::vector<int> condition); 
    
    int getnumber() const;
    void setnumber(int num);
};
