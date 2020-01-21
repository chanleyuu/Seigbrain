#pragma once

#include <vector>

class neuron 
{
private:
    std::vector<int> condition_; //conditions
    bool fire_;
    int number_;
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
