/*
* network.cpp
*
* Version information
* Author: Conall Hanley
* Date:22/01/2020
* Description: This file is the implementation file for the network class and defines (implements) the functions of the class
* This class defines a specific model.
* TODO Allow it to generate various models.
*
* Copyright notice -
*/

#include <iostream>
#include "network.h"

network::network(layer base, double rate, int outputsize): learningrate_{ rate }
{

    layers.push_back(base);

    /*
    for (int i = 0; i < 32; i++) {
        neuron nuer( i, 0.0, 0.0);
        hiddenlayer1.addneuron(nuer);
    }

    for (int i = 0; i < 32; i++) {
        neuron nuer( i, 0.0, 0.0);
        hiddenlayer2.addneuron(nuer);
    }
    */
    for (int i = 0; i < outputsize; i++) {
        neuron nuer( i, 0.0, 0.0);
        outputlayer.addneuron(nuer);
    }
}

int network::think()
{
    int n = layers.size() - 1;
    /*
    hiddenlayer1.conntectneurons(baselayer);
    hiddenlayer2.conntectneurons(hiddenlayer1);
    outputlayer.conntectneurons(hiddenlayer2);
 */
    
    for (int i = 0; i < layers.size(); i++) {
        
    }
    double highnum = 0.0;
    int out = 0;
    std::vector<neuron> outneurons = layers[n].getneurons();
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

void network::tunelayers()
{
    /*
	tunelayer(hiddenlayer1, baselayer);
	tunelayer(hiddenlayer2, hiddenlayer1);
	*/
    if (layers.size() < 2) {
            std::cout << "model must have two or more layers to tune!" << std::endl;
            return;
    }
    for (int i = 0; i < layers.size() - 1; i++) {
        tunelayer(layers[i + 1], layers[i]);
    }
}


//Adjust weights based on cost of the function
void network::tunelayer(layer& L, layer& pastlayer)
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
                L.getneurons()[i].setweight(currweight + learningrate_);
                upcost = L.getcost();
                L.getneurons()[i].setweight(currweight - learningrate_);
                downcost = L.getcost();
                if (upcost > downcost && oldcost > downcost) {
                L.getneurons()[i].setweight(currweight + learningrate_);
                }
                else
                {
                L.getneurons()[i].setweight(currweight - learningrate_);
                }
            }

        }

	}
}

void network::addlayer(int size) {
    
    layer newlayer;
    
    for (int i = 0; i < size; i++) {
        neuron nuer( i, 0.0, 0.0);
        newlayer.addneuron(nuer);
    }
    
    layers.push_back(newlayer);
}

//This funtion outputs a vector,
//the first value is the output the second is the cost
std::vector<double> network::produceoutput()
{
  double guess;//The AI's best guess
  double certainty;//how sure the AI is
  std::vector<double> in;
  std::vector<double> out;
  
    if (layers.size() < 2) {
            std::cout << "model must have two or more layers to produce output!" << std::endl;
            return out;
    }
    
    for (int i = 0; i < layers[1].getsize(); i++){
        in.push_back(layers[1].getneuron(i).calculateoutput());
    }

  double highscore = 0.0;
  for (int i = 0; i < outputlayer.getsize(); i++){
    if (outputlayer.getneuron(i).calculateoutput(&in) > highscore) {
        guess = i + 1.0;
    }
  }

  certainty = outputlayer.getcost();
  out.push_back(guess);
  out.push_back(certainty);
  return out;
}

double network::getlearningrate() const
{
    return learningrate_;
}

void network::setlearningrate(double rate)
{
    rate = learningrate_;
}

layer network::getinputlayer() const
{
  return layers[0];
}
