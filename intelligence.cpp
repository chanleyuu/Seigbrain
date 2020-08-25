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

intelligence::intelligence(layer inlayer, double learningrate): inputlayer{ inlayer }{

    network net(inlayer);
    gen.push_back(net);
}

void intelligence::train()
{
    network currentgen;


}

layer intelligence::getinputlayer() const{
  return inputlayer;
}

void intelligence::setinputlayer(layer l){
  l = inputlayer;
}

int intelligence::getgeneration() const {
  return generation_;
}

void intelligence::setgeneration(int gen) {
  generation_ = gen;
}
