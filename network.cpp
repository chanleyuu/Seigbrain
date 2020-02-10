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

int network::think()
{
    hiddenlayer1.conntectneurons(baselayer);
    hiddenlayer2.conntectneurons(hiddenlayer1);
    outputlayer.conntectneurons(hiddenlayer2);
    
    double highnum = 0.0;
    int out = 0;
    std::vector<neuron> outneurons = outputlayer.getneurons();
    for (int i = 0; i < outneurons.size(); i++) 
	{
        if (outneurons[i].getweight() > highnum) 
        {
            highnum = outneurons[i].getweight();
            out = outneurons[i].getnumber();
        }
        
    }
    return out;
}

void network::train()
{
	for (int i = 0; i < hiddenlayer1.getneurons().size(); i++) 
	{
		double oldcost = hiddenlayer1.getcost();
        double upcost = 0.0;
        double downcost = 0.0;
		think();
        while (oldcost > (double) i / 10) {
            
        }
        
	}

}
