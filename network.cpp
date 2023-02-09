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

//#include <iostream>
#include "network.h"

network::network(std::vector<double>& inputs, double rate, int outputsize): learningrate_{ rate }
{
    
    
    outputlayer->setsensitivity(0.3);
    //layers.push_back(base);

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
    
    //euler = my_math_euler_num();
    for (int i = 0; i < inputs.size(); i++){
        inputs_.push_back(inputs.at(i));
    }
    //static layer last(&euler);
    layer* first = new layer(inputs_, &euler);
    first->setsensitivity(0.6);
    double one = outputlayer->getsensitivity();
    double two = first->getsensitivity();
    layers.push_back(first);
    delete first;
    //outputlayer = last;
    for (int i = 0; i < outputsize; i++) {
        neuron n( i, 0.0, &euler);
        outputlayer->addneuron(n);
    }
    one = 1 + two;
    first->setsensitivity(one);
    //init_weights();
}

network::~network()
{
    //delete layers;
    for (int i = 0; i < layers.size(); i++) {
        delete layers.at(i);
    }
}


int network::think()
{
    int n = layers.size() - 1;
    /*
    hiddenlayer1.conntectneurons(baselayer);
    hiddenlayer2.conntectneurons(hiddenlayer1);
    outputlayer.conntectneurons(hiddenlayer2);
 
    
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
    */
    return 1;
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
    //Start by back propagating the dirst layer
    for (int i = 0; i < outputlayer->getsize(); i++){
        costs_.push_back (0.5 * pow(outputlayer->getneuron(i).get_activation() - desire_[i], 2));
    }
    
    for (int i = layers.size(); i < 1; i--) {
        tunelayer(layers.at(i - 1), layers.at(i));
    }
}


//Adjust weights based on cost of the function
//Back propagate
void network::tunelayer(layer* L, layer* pastlayer)
{
    double cost = 0.0;
    
    
    for (int i = 0; i < L->getneurons().size(); i++)
	{
        for (int j = 0; j < pastlayer->getneurons().at(i).getweights().size(); j++) {
            cost += (pastlayer->getneurons().at(j).getweights()[i] * pastlayer->getneurons().at(j).get_delta());
        }
        costs_.push_back(cost);
	}
	
	for (int i = 0; i < L->getneurons().size(); i++)
	{
        L->getneurons().at(i).set_delta(costs_[i] *  L->getneurons().at(i).tranfer_derivitive());
    }
}

//Adding a layer will clear all weights
void network::addlayer(int size) {
    
    layer* newlayer = new layer(&euler);
    //neuron c( 1, 0.0, &euler);
    //newlayer.getneurons().resize(size);
    /*newlayer.getneurons().erase(newlayer.getneurons().begin(), newlayer.getneurons().end()); */
    for (int i = 0; i < size; i++) {
        neuron n( i, 0.0, &euler);
        newlayer->getneurons().push_back( n);
    } 
    //fill(newlayer.getneurons().begin(), newlayer.getneurons().end(), c);
     
    layers.push_back(newlayer);
   // init_weights();
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
    int n = layers.size();
    for (int i = 1; i < n; i++){
        
        
        for (int j = 0; j < layers.at(i)->getneurons().size(); j++) {
            std::vector<double> weights;
            std::vector<double> activations;
            for (int k = 0; k < layers.at(i - 1)->getsize(); k++) {
                weights.push_back(layers.at(i - 1)->getneuron(k).getweights()[j]);
                activations.push_back(layers.at(i - 1)->getneuron(k).get_activation());
            }
            layers.at(i)->getneuron(j).calculateoutput(weights, activations);
        }
    }

    for (int i = 0; i < outputlayer->getsize(); i++){
        std::vector<double> weights;
        std::vector<double> activations;
        for (int j = 0; j < layers.at(n - 1)->getsize(); j++) {
                weights.push_back(layers.at(i - 1)->getneuron(j).getweights()[i]);
                activations.push_back(layers.at(i - 1)->getneuron(j).get_activation());
        }
        out.push_back(outputlayer->getneuron(i).calculateoutput(weights, activations));
    }

  //certainty = outputlayer.getcost();
  //out.push_back(guess);
  //out.push_back(certainty);
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
  return *layers.at(0);
}

void network::feed() 
{
    for (int i = 1; i < layers.size() - 1; i++)
    {
        layers.at(i)->feedforward(*layers.at(i + 1));
    }
    layers.at(layers.size())->feedforward(*outputlayer);
}

//Adds one weight for every node in the next layer
void network::init_weights()
{
    for (int i = 0; i < layers.size(); i++)
    {
            //If we are at the last hidden layer, we need to generate weights for the final layer
            if (i == layers.size() - 1)
            {
                for (int j = 0; j < layers.at(i)->getneurons().size(); j++)
                {
                    layers.at(i)->getneurons().at(j).clear_weights();
                    std::vector<double> weights;
                    for (int e = 0; e < outputlayer->getneurons().size(); e++) 
                    {
                        //layers->at(i).getneurons().at(j).addweight();
                        weights.push_back(1.0);
                    }
                    layers.at(i)->getneurons().at(j).setweights(weights);
                }
            }
            else {
                for (int e = 0; e < layers.at(i)->getneurons().size(); e++)
                {
                    layers.at(i)->getneurons().at(e).clear_weights();
                    std::vector<double> weights;
                    for (int j = 0; j < layers.at(i + 1)->getneurons().size(); j++ ) {
                        //layers->at(i).getneurons().at(e).addweight();
                        weights.push_back(1.0);
                    }
                    layers.at(i)->getneurons().at(e).setweights(weights);
                    
                }
            }
    }
}

void network::set_desire(std::vector<double> desire)
{
    desire_ = desire;
}

