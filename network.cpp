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

#include <iostream>
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
	tunelayer(hiddenlayer1);
	tunelayer(hiddenlayer2);
}

void network::tunelayer(layer& L)
{
    for (int i = 0; i < L.getneurons().size(); i++) 
	{
        
        double sensitivty = L.getsensitivity();
		double targetcost = 1.0 - ((double)i + 1.0) / ((double) L.getneurons().size());
		double oldcost = L.getcost();
        double upcost = 0.0;
        double downcost = 0.0;
		think();
        while (oldcost > targetcost) {
            double oldweight = L.getneurons()[i].getweight();
            double currweight = oldweight;
            for (int i = 0; i < 100; i++) {
                L.getneurons()[i].setweight(currweight + 0.01);
                upcost = L.getcost();
                L.getneurons()[i].setweight(currweight - 0.01);
                downcost = L.getcost();
                if (upcost > downcost && oldcost > downcost) {
                L.getneurons()[i].setweight(currweight + 0.01);
                }
                else 
                {
                L.getneurons()[i].setweight(currweight - 0.01);
                }
            }
            
        }
        
	}
}


void network::importimage()
{
    Magick::Image image;
    
    /*TO DO, set image as inputs for neural network */
    try {
        image.read( "./data/number1.jpg" );
    }
    catch( std::exception &error_ )
    {
        std::cout << "ERROR!: " << error_.what() << std::endl;
    }
}


int network::produceoutput()
{
    
}

double network::getlearningrate()
{
    return learningrate;
}

void network::setlearningrate(double rate)
{
    rate = learningrate;
}

