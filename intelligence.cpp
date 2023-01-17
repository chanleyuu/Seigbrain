/*
* Intelligence.cpp
*
* Version information
* Author: Conall Hanley
* Date:19/06/2020
* Description: This file is the implementation file for the Intelligence class and defines (implements) the functions of the class
*
* Copyright notice -
*/

#include "intelligence.h"

intelligence::intelligence(std::vector<double>& inputs, double rate, int outputsize): inputs_{ inputs }, learningrate{ rate }{

    network net(inputs, learningrate, outputsize);
    gen.push_back(net);
    generation_++;
}

void intelligence::train()
{
    inputs_ = gen[generation_].getinputlayer().getactivations();
    network currentgen(inputs_, learningrate, outputsizes[generation_]);

    currentgen.think();
    currentgen.tunelayers();
    gen.push_back(currentgen);
    generation_++;
}

std::vector<double> intelligence::getinputs() const{
  return gen.at(generation_).getinputlayer().getactivations();
}

void intelligence::setinputs(std::vector<double> l){
  inputs_ = l;
}

int intelligence::getgeneration() const {
  return generation_;
}

void intelligence::setgeneration(int generation) {
  generation_ = generation;
}

std::vector<network> intelligence::getnetworks(){
  return gen;
}
