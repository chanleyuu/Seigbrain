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
        return true;
    }
    
    return false;
}
