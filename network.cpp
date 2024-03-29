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


//This constructor will populate the input layer based on the size of the input vector
network::network(std::vector<double>& inputs, double rate, int outputsize): learningrate_{ rate }
{
    
    
    outputlayer->setsensitivity(0.3);
    outputlayer->init_vector();
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
    //first->init_vector();
    first->setsensitivity(0.6);
    double one = outputlayer->getsensitivity();
    double two = first->getsensitivity();
    layers.push_back(first);
    //delete first;
    //outputlayer = last;
    for (int i = 0; i < outputsize; i++) {
        neuron n( i, 0.0, &euler);
        outputlayer->addneuron(n);
    }
    one = 1 + two;
    first->setsensitivity(one);
    //init_weights();
}

//This constructor takes a fourth parameter and populates the input layer based on that 
network::network(int inputsize, double rate, int outputsize): learningrate_{ rate }
{
    
    
    outputlayer->setsensitivity(0.3);
    outputlayer->init_vector();
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
    for (int i = 0; i < inputsize; i++){
        inputs_.push_back(0.0);
    }
    //static layer last(&euler);
    layer* first = new layer(inputs_, &euler);
    //first->init_vector();
    first->setsensitivity(0.6);
    double one = outputlayer->getsensitivity();
    double two = first->getsensitivity();
    layers.push_back(first);
    //delete first;
    //outputlayer = last;
    for (int i = 0; i < outputsize; i++) {
        neuron n( i, 0.0, &euler);
        outputlayer->addneuron(n);
    }
    one = 1 + two;
    first->setsensitivity(one);
    //init_weights();
}

network::network()
{
    
} 

network::~network()
{
    
}

void network::free_network_mem()
{
    //delete layers;
    for (int i = 0; i < layers.size(); i++) {
        for (int e = 0; e < layers.at(i)->getneurons()->size(); e++) {
            layers.at(i)->getneurons()->at(e).clear_weights();
        }
        //delete layers.at(i)->getneurons();
        layers.at(i)->delete_vector();
        delete layers.at(i);
    }
    for (int e = 0; e < outputlayer->getneurons()->size(); e++) {
            outputlayer->getneurons()->at(e).clear_weights();
    }
    delete outputlayer;
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
    //for (int i = 0; i < outputlayer->getsize(); i++){
    //    costs_.push_back (0.5 * pow(outputlayer->getneuron(i).get_activation() - desire_[i], 2));
    //}
    
    std::vector<double> pass = tunelayer(layers.at(layers.size() - 1), outputlayer, desire_);
    skip_error = true;
    for (int i = layers.size() - 1; i > 0; i--) {
        pass = tunelayer(layers.at(i - 1), layers.at(i), pass);
    }
    skip_error = false;
    step++;
}


//Adjust weights based on cost of the function
//Back propagate
std::vector<double> network::tunelayer(layer* L, layer* pastlayer,  std::vector<double> desire)
{
    //Total cost 
    double cost = 0.0;
    //Smooting variables
    
    //double velocity = 0.0;
    //double m = 0.0;
    //double v = 0.0;
    //double mt = 0.0;
    //double vt = 0.0;
    double beta1 = 0.9;
    double beta2 = 0.999; 
    std::vector<double> new_desire;
    std::vector<std::vector<double>> weights;
    //std::vector<double> costs;
    
    //Neuron's error is first calculated
    for (int i = 0; i < pastlayer->getneurons()->size(); i++)
	{
        //total cost of the layer will be calculated first
        if (skip_error == false) {
        cost += ((desire[i] - pastlayer->getneurons()->at(i).get_activation()) * (desire[i] - pastlayer->getneurons()->at(i).get_activation())) / 2;
            //cost += my_math_error(pastlayer->getneurons()->at(i).get_activation(), desire[i]);
        }
         //Error is calculated corisponding for every weight
        //for (int j = 0; j < pastlayer->getneurons().at(i).getweights().size(); j++) {
            //cost += (pastlayer->getneurons().at(j).getweights()[i] * pastlayer->getneurons().at(j).get_delta());
        //}
        //costs.push_back(cost);
        //cost = 0.0;
        double error_deriv = 0.0;
        double act_deriv = 0.0;
        //double act_deriv = pastlayer->getneurons()->at(i).get_activation() * (1.0 - pastlayer->getneurons()->at(i).get_activation() );
        //double act_deriv = my_math_relu_deriv(pastlayer->getneurons()->at(i).get_activation());
        if (skip_error == false) {
            act_deriv = pastlayer->getneurons()->at(i).get_activation() * (1.0 - pastlayer->getneurons()->at(i).get_activation() );
            error_deriv = (desire[i] - pastlayer->getneurons()->at(i).get_activation()) * -1.0 * act_deriv;
            //error_deriv = my_math_error_deriv(pastlayer->getneurons()->at(i).get_activation(), desire[i]);
        }
        else {
            act_deriv = my_math_relu_deriv(pastlayer->getneurons()->at(i).get_activation());
            //error_deriv = (desire[i] - pastlayer->getneurons()->at(i).get_activation()) * -1.0 * act_deriv;
            error_deriv = desire[i] * act_deriv;
        }
        /*
            m = (beta1 * m) + (1 - beta1) *  error_deriv;
            v = (beta2 * v) + (1 - beta2) * ( error_deriv *  error_deriv);
            mt = m / (1.0 - powf64(beta1, 1 + (double) step)); 
            vt = v / (1.0 - powf64(beta2, 1 + (double) step)); */
            //velocity =  (pastlayer->getneurons()->at(i).getbias()  - (learningrate_ * mt)) / (sqrt(vt) + 0.00000001); 
            pastlayer->getneurons()->at(i).setbias(pastlayer->getneurons()->at(i).getbias() - (error_deriv * learningrate_  ));
            //pastlayer->getneurons()->at(i).setbias((pastlayer->getneurons()->at(i).getbias()  - (learningrate_ * mt)) / (sqrt(vt) + 0.00000001));
	}
	
	for (int i = 0; i < L->getneurons()->size(); i++)
	{
        std::vector<double> neuronweights;
        for (int e = 0; e < pastlayer->getneurons()->size(); e++)
        {
            double act_deriv = 0.0;
            double cost_deriv = 0.0;
            if (skip_error == false) {
                cost_deriv = -1.0 * (desire.at(e) - pastlayer->getneurons()->at(e).get_activation());
                act_deriv = pastlayer->getneurons()->at(e).get_activation() * (1.0 - pastlayer->getneurons()->at(e).get_activation() );
                //cost_deriv = my_math_error_deriv(pastlayer->getneurons()->at(i).get_activation(), desire[i]);
            }
            else {
               cost_deriv = desire.at(e); 
               //cost_deriv = -1.0 * (desire.at(e) - pastlayer->getneurons()->at(e).get_activation());
               act_deriv = my_math_relu_deriv(pastlayer->getneurons()->at(e).get_activation());
            }
            //double act_deriv = pastlayer->getneurons()->at(e).get_activation() * (1.0 - pastlayer->getneurons()->at(e).get_activation() );
            //double act_deriv = my_math_relu_deriv(pastlayer->getneurons()->at(i).get_activation());
            double weight_error = L->getneurons()->at(i).get_activation() * act_deriv * cost_deriv;
            
            pastlayer->getneurons()->at(e).set_first_moment( (beta1 * pastlayer->getneurons()->at(e).get_first_moment()) + (1 - beta1) * weight_error);
            pastlayer->getneurons()->at(e).set_second_moment( (beta2 * pastlayer->getneurons()->at(e).get_second_moment()) + (1 - beta2) * (weight_error * weight_error));
            double mt = pastlayer->getneurons()->at(e).get_first_moment() / (1.0 - powf64(beta1, 1 + (double) step)); 
            double vt = pastlayer->getneurons()->at(e).get_second_moment() / (1.0 - powf64(beta2, 1 + (double) step));
            //velocity =  (L->getneurons()->at(i).getweights()[e] - (learningrate_ * mt)) / (sqrt(vt) + 0.00000001); 
            
            //neuronweights.push_back(L->getneurons()->at(i).getweights()[e] - (velocity  /* * learningrate_  */ ));
            neuronweights.push_back((L->getneurons()->at(i).getweights()[e] - ((learningrate_ * mt)) / (sqrt(vt) + 0.00000001)));
        }
       /* m = 0;
        v = 0;
        mt = 0;
        vt = 0; 
        velocity = 0; */
        weights.push_back(neuronweights);
        
    }
	
	
    for (int i = 0; i < L->getneurons()->size(); i++)
    {
        double new_target = 0.0;
        for (int e = 0; e < pastlayer->getneurons()->size(); e++)
        {
            double act_deriv = 0.0;
            double error_deriv = 0.0;
            //double act_deriv = pastlayer->getneurons()->at(e).get_activation() * (1.0 - pastlayer->getneurons()->at(e).get_activation() );
            //double act_deriv = my_math_relu_deriv(pastlayer->getneurons()->at(i).get_activation());
            if (skip_error == false) {
                act_deriv = pastlayer->getneurons()->at(e).get_activation() * (1.0 - pastlayer->getneurons()->at(e).get_activation() );
                error_deriv = (desire[e] - pastlayer->getneurons()->at(e).get_activation()) * -1.0 * act_deriv;
                //error_deriv = my_math_error_deriv(pastlayer->getneurons()->at(i).get_activation(), desire[i]);
            }
            else {
                act_deriv = my_math_relu_deriv(pastlayer->getneurons()->at(e).get_activation());
                //error_deriv = desire[e] * act_deriv;
                error_deriv = (desire[e] - pastlayer->getneurons()->at(e).get_activation()) * -1.0 * act_deriv;
            }
            new_target += error_deriv * L->getneurons()->at(i).getweights()[e] ;
        }
        new_desire.push_back(new_target);
        //new_desire.push_back(act_deriv);
    }
    
    for (int i = 0; i < L->getneurons()->size(); i++)
	{
        L->getneurons()->at(i).clear_weights();
        L->getneurons()->at(i).setweights(weights.at(i));
    }
	/*
     * 
	for (int i = 0; i < L->getneurons().size(); i++)
	{
        //L->getneurons().at(i).set_delta(costs[i] *  L->getneurons().at(i).tranfer_derivitive());
        std::vector<double> weights;
        for (int j = 0; j < L->getneurons().at(i).getweights().size(); j++ ) {
            weights.push_back(L->getneurons().at(i).getweights().at(j) - (L->getneurons().at(i).get_delta() * learningrate_));
        }
        L->getneurons().at(i).clear_weights();
        L->getneurons().at(i).setweights(weights);
        weights.clear();
    } */
    if (skip_error == false) {
        error_ = cost;
    }
    return new_desire;
}

/*
void network::hiddentune(layer* L, layer* pastlayer, layer* realpastlayer)
{
    for (int e = 0; e < outputlayer->getneurons().size(); e++)
    {
        double act_deriv = outputlayer->getneurons().at(e).get_activation() * (1.0 - outputlayer->getneurons().at(e).get_activation() );
        double error_deriv = 2.0 * (0.5 * (desire_[e] - outputlayer->getneurons().at(e).get_activation())) * -1 * act_deriv;
        
        for (int g = 0; g < pastlayer->getneurons().at(e).getweights().size(); g++){
            
        }
        
        double weight_error = error_deriv;
    }
} */

//Adding a layer will clear all weights
void network::addlayer(int size) {
    
    layer* newlayer = new layer(&euler);
    newlayer->init_vector();
    //neuron c( 1, 0.0, &euler);
    //newlayer.getneurons().resize(size);
    /*newlayer.getneurons().erase(newlayer.getneurons().begin(), newlayer.getneurons().end()); */
    for (int i = 0; i < size; i++) {
        neuron n( i, 0.0, &euler);
        newlayer->addneuron(n);
    } 
    //fill(newlayer.getneurons().begin(), newlayer.getneurons().end(), c);
     
    layers.push_back(newlayer);
   // init_weights();
}

//This funtion outputs a vector,
//the first value is the output the second is the cost
std::vector<double> network::produceoutput()
{
  //double guess;//The AI's best guess
  //double certainty;//how sure the AI is
  std::vector<double> in;
  std::vector<double> out;
  
    if (layers.size() < 2) {
            std::cout << "model must have two or more layers to produce output!" << std::endl;
            return out;
    }
    int n = layers.size();
    for (int i = 1; i < n; i++){
        
        
        for (int j = 0; j < layers.at(i)->getneurons()->size(); j++) {
            //std::vector<double> weights;
            std::vector<double> activations;
            long num2 = layers.at(i - 1)->getsize();
            double weights[num2];
            for (int k = 0; k < num2; k++) {
                //weights.push_back(layers.at(i - 1)->getneuron(k).getweights()[j]);
                weights[k] = layers.at(i - 1)->getneurons()->at(k).getweights()[j];
                activations.push_back(layers.at(i - 1)->getneurons()->at(k).get_activation());
            }
            layers.at(i)->getneurons()->at(j).set_activation(layers.at(i)->getneurons()->at(j).calculateoutput_relu( activations, weights, layers.at(i - 1)->getsize()));
        }
    }

    for (int i = 0; i < outputlayer->getsize(); i++){
        //std::vector<double> weights;
        std::vector<double> activations;
        long num2 = layers.at(n - 1)->getsize();
        double weights[num2];
        for (int j = 0; j < num2; j++) {
                //weights.push_back(layers.at(i - 1)->getneuron(j).getweights()[i]);
                weights[j] = layers.at(n - 1)->getneurons()->at(j).getweights()[i];
                activations.push_back(layers.at(n - 1)->getneurons()->at(j).get_activation());
        }
        double act = outputlayer->getneurons()->at(i).calculateoutput_sigmoid( activations, weights, num2);
        if (act >= 1) {
            act = 1 -  (0.01 *learningrate_);
        } 
        else if (act <= 0 || isnan(act)) {
            act = 0.0001 * learningrate_;
        }
        outputlayer->getneurons()->at(i).set_activation(act);
        double output = outputlayer->getneurons()->at(i).get_activation();
        out.push_back(output);
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
                for (int j = 0; j < layers.at(i)->getneurons()->size(); j++)
                {
                    if (layers.at(i)->getneurons()->at(j).getweights() != nullptr ) {
                        layers.at(i)->getneurons()->at(j).clear_weights();
                    }
                    std::vector<double> weights;
                    for (int e = 0; e < outputlayer->getneurons()->size(); e++) 
                    {
                        //layers->at(i).getneurons().at(j).addweight();
                        weights.push_back(learningrate_);
                    }
                    layers.at(i)->getneurons()->at(j).setweights(weights);
                }
            }
            else {
                for (int e = 0; e < layers.at(i)->getneurons()->size(); e++)
                {
                    if (layers.at(i)->getneurons()->at(e).getweights() != nullptr ) {
                        layers.at(i)->getneurons()->at(e).clear_weights();
                    }
                    std::vector<double> weights;
                    for (int j = 0; j < layers.at(i + 1)->getneurons()->size(); j++ ) {
                        //layers->at(i).getneurons().at(e).addweight();
                        weights.push_back(learningrate_);
                    }
                    layers.at(i)->getneurons()->at(e).setweights(weights);
                    
                }
            }
    }
}

void network::set_desire(std::vector<double> desire)
{
    if (desire.size() > desire_.size()){
        
    }
    desire_ = desire;
}

double network::get_error() 
{
    return error_;
}

int network::get_output_size()
{
    return outputlayer->getneurons()->size();
}

std::vector<double> network::getinputs()
{
    return inputs_;
}


std::vector<layer*> network::get_layers()
{
    return layers;
}

void network::setfirstlayer(std::vector<double> inputs)
{
    //layer* l = new layer(inputs, &euler);
    //l->copyweights(*layers.at(0), layers.at(1)->getneurons()->size());
    //layers.at(0)->delete_vector();
    //delete layers.at(0);
    //layers.at(0) = l;
    //this->init_weights();
    if (this->layers.at(0)->getneurons()->size() <= inputs.size()) {
        for (int i = 0; i < this->layers.at(0)->getneurons()->size(); i++) {
            this->layers.at(0)->getneurons()->at(i).set_activation(inputs[i]);
        }
    }
    else {
        printf("Input vector is too short!!!! \n");
    }
    
}

long network::get_step()
{
    return step;
}

void network::set_step(long s)
{
   step = s; 
}
