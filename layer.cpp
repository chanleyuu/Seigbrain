/*
* layer.cpp
*
* Version information
* Author: Conall Hanley
* Date:22/01/2020
* Description: This file is the implementation file for the layer class and defines (implements) the functions of the class
*
* Copyright notice -
*/

#include "layer.h"

//double layer::sensetivity;

layer::layer()
{
}


layer::layer(const double* euler)
{
    euler_ = euler;
}

layer::layer(std::vector<double> inputs, const double* euler)
{
    euler_ = euler;
   
    for (int i = 0; i < inputs.size(); i++)
    {
        neuron newinput(i, 0.0, euler);
        newinput.set_activation(inputs.at(i));
        //neurons_.reserve(sizeof(newinput) + (neurons_.size()* sizeof(newinput)));
        //this->addneuron(newinput);
        neurons_->push_back(newinput);
    }
    
}

//Can't allow memory leaks 
layer::~layer()
{
    //delete neurons_;
}


std::vector<neuron>* layer::getneurons() const
{
    return neurons_;
}

void layer::addneuron(neuron n)
{
    this->neurons_->push_back(n);
}

void layer::removeneuron(int number)
{
    for (int i = 0; i < neurons_->size(); i++) {
        if (neurons_->at(i).getnumber() == number) {
            neurons_->erase(neurons_->begin() + i);
        }
    }
}

neuron layer::getneuron(int number)
{

    if (neurons_->at(number).getnumber() == number) {
        return neurons_->at(number);
    }
    return neurons_->at(number);
}

void layer::setnuerons(std::vector<neuron> inputs) 
{
    for (int i = 0; i < this->neurons_->size(); i++){
        this->neurons_->at(i) = inputs[i];
    }
}

void layer::conntectneurons(layer l)
{
    std::vector<neuron> lneurons = *l.getneurons();
    std::vector<double> weights;
    for (int i = 0; i > lneurons.size(); i++)
    {
       // weights.push_back(lneurons[i].getweight());
    }

    for (int i = 0; i < neurons_->size(); i++)
    {
        //neurons_[i].calculateoutput(&weights);
    }
}

double layer::getsensitivity() const
{
    return sensetivity;
}


//Layer takes the previous values as an input
void layer::calculatesensitivity(layer& lastgen)
{

    double Y = 1;
    double Yprime = 1;
    double out;
    for (int i = 0; i < this->neurons_->size(); i++) {
       //double changeweight = neurons_[i].getweight() - lastgen.getneuron(i).getweight();
       double changebias = this->neurons_->at(i).getbias() - lastgen.getneuron(i).getbias();
      // Y *= changeweight / changebias;
    }

    for (int i = 0; i < this->neurons_->size(); i++) {
      // double changeweight = neurons_[i].getweight() - lastgen.getneuron(i).getweight();
       double changebias = neurons_->at(i).getbias() - lastgen.getneuron(i).getbias();
     //  Yprime *= (changeweight / changebias * changebias) * -1;
    }

    out = Y - Yprime;
    if (out < 0){
        out *= -1;
    }

    sensetivity = out;
}


double layer::getcost() const
{
    return cost_;
}

void layer::caluclatecost(layer correct)
{
    int n = this->neurons_->size();
    double avg = 0.0;
    for (int i = 0; i < n; i++) {
    //   avg += (neurons_[i].getweight() - correct.getneuron(i).getweight()) * (neurons_[i].getweight() - correct.getneuron(i).getweight());
    }

    avg = avg / (double) n;
    cost_ = 1.0 - avg;
}

void layer::nudge()
{
    int n = this->neurons_->size();
    //Only enter loop if there is a next layer
    
    /*
    for (int i = 0; i < n; i++){
        //I think the answer is to add the learning rate if the neuron is higher and subtract if lower
        if (nextLayer->getneuron(i).getweight() > this->getneuron(i).getweight()){    
            this->getneuron(i).setbias(this->getneuron(i).getbias() + rate); //If connected neuron is firing, this one will be more likly to fire
        }
        else {
            this->getneuron(i).setbias(this->getneuron(i).getbias() - rate); //subtract if not firing
        }
        
    } */
    
}

std::vector<double> layer::getactivations()
{
    std::vector<double> out;
    
    for (int i = 0; i < this->neurons_->size(); i++) {
        out.push_back(this->neurons_->at(i).get_activation());
    }
    
    return out;
}


int layer::getsize() {
    return this->neurons_->size();
}

//gets weights for a particular node
std::vector<double> layer::getweights()
{
    std::vector<double> out;
    
    for (int i = 0; i < this->neurons_->size(); i++) {
        
        for (int e = 0; e < sizeof(*neurons_->at(i).getweights()); e++) {
            out.push_back(neurons_->at(i).getweights()[e]);
        }
    } 
    
    return out;
}

void layer::feedforward(layer prev) {
    std::vector<double> weights = prev.getweights();
    std::vector<double> activations = prev.getactivations();
    
    for (int i = 0; i < neurons_->size(); i++) {
        neurons_->at(i).calculateoutput( activations);
    }
}

void layer::setsensitivity(double sense) 
{
    sensetivity = sense;
}
