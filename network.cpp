/*
* network.cpp
*
* Version information
* Author: Conall Hanley
* Date:22/01/2020
* Description: This file is the implementation file for the network class and defines (implements) the functions of the class
*
* Copyright notice -
*/ 

#include "network.h"

network::network()
{
    for (int i = 0; i < 10000; i++) {
        neuron nuer( i, 0.0, 0.0);
        baselayer.addneuron(nuer);
    }
        
    for (int i = 0; i < 32; i++) {
        neuron nuer( i, 0.0, 0.0);
        hiddenlayer1.addneuron(nuer);
    }
    
    for (int i = 0; i < 32; i++) {
        neuron nuer( i, 0.0, 0.0);
        hiddenlayer2.addneuron(nuer);
    }
    
    for (int i = 0; i < 8; i++) {
        neuron nuer( i, 0.0, 0.0);
        outputlayer.addneuron(nuer);
    }
}

double network::think()
{
    hiddenlayer1.conntectneurons(baselayer);
    hiddenlayer2.conntectneurons(hiddenlayer1);
    outputlayer.conntectneurons(hiddenlayer2);
    
    
}
