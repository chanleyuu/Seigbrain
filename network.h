/*
* network.h
*
* Version information
* Author: Conall Hanley
* Date:22/01/2020
* Description: This file is the header file for the network class and declares the class interface.
*
* This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#pragma once

#include <vector>
//#include "layer.h"
#include <iostream>
#include <math.h>
#include "my_math.h"
#include "layer.h"
//Diogenes Core
class network
{
private:
    double learningrate_;

    //Contains input layer and all hidden layers
    std::vector<layer*> layers;
    std::vector<double> costs_;
    std::vector<double> desire_;
    std::vector<double> inputs_;
    double error_;
    const double euler = my_math_euler_num();
    layer* outputlayer = new layer(&euler);
public:
    

    network(std::vector<double>& inputs, double rate, int outputsize);
    
    network(int inputsize, double rate, int outputsize);
    
    //network();
    
    network(std::vector<double>& inputs ,int outputsize, std::vector<double> desire);

    ~network();//Destructor
    
    void free_network_mem();
    
    double getlearningrate() const;
    void setlearningrate(double rate);

    std::vector<double> produceoutput();

    int think();

    double calculatecost();
    
    void addlayer(int size);

    void tunelayers();

    std::vector<double> tunelayer(layer* L, layer* pastlayer, std::vector<double> desire);

    //void hiddentune(layer* L, layer* pastlayer);
    
    void readdata();

    void add_inputs();
    
    void setfirstlayer(std::vector<double> inputs);

    layer getinputlayer() const;
    
    void set_desire(std::vector<double> desire);
    
    void init_weights();
    
    void feed();
    
    std::vector<double> get_desire();
    
    double get_error();
    
    int get_output_size();
    
    std::vector<layer*> get_layers(); 
    
    std::vector<double> getinputs();
};
