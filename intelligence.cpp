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

intelligence::intelligence(std::vector<double>& inputs,  network model): inputs_{ inputs },  model_{ model }
{

    //network net(inputs, learningrate, outputsize);
    //gen->push_back(net);
    //generation_++;
}

intelligence::~intelligence()
{
  //delete gen;
}


void intelligence::train_examples(std::vector<std::vector<double>> data, std::vector<std::vector<double>> correct)
{
  /*
    inputs_ = gen->at(generation_).getinputlayer().getactivations();
    network currentgen(inputs_, learningrate, outputsizes[generation_]);

    currentgen.think();
    currentgen.tunelayers();
    gen->push_back(currentgen);
    generation_++; */
  
  std::vector<network> nets;
  
  
  for (int i = 0; i < data.size(); i++) {
    network net( data[i], model_.getlearningrate(), model_.get_output_size());
    for (int e = 0; e < model_.get_layers().size(); e++){
        net.addlayer(model_.get_layers().at(e)->getneurons()->size());
    }
    net.init_weights();
    
    for (int i = 0; i < net.get_layers().size(); i++){
      for (int e = 0; e < net.get_layers().at(i)->getneurons()->size(); e++){
        /*
        for (int z = 0; z < net.get_layers().at(i)->getneurons()->at(e).get_weight_count(); z++) {
          *net.get_layers().at(i)->getneurons()->at(e).getweights().getweights[z] = *model_.get_layers().at(i)->getneurons()->at(e).getweights().getweights[z];
        } */
        net.get_layers().at(i)->getneurons()->at(e).setweights(model_.get_layers().at(i)->getneurons()->at(e).getweights(), model_.get_layers().at(i)->getneurons()->at(e).get_weight_count());
      }
    }
    
    net.set_desire(correct.at(i));
    net.produceoutput();
    net.tunelayers();
    nets.push_back(net);
  }
  
  //Calculate weight averages
  //std::vector<std::vector<std::vector<double>>> weightaverages;
  //std::vector<std::vector<double>> biasaverages;
  //Add all the weights and biases
  for (int i = 0; i < nets.size(); i++) {
    for(int e = 0; e < nets.at(i).get_layers().size(); e++) {
      for (int j = 0; j < nets.at(i).get_layers().at(e)->getneurons()->size(); j++) {
        /*
        for (int z = 0; z < nets.at(i).get_layers().at(e)->getneurons()->at(j).get_weight_count(); z++) {
          //weightaverages.at(e).at(j).push_back( weightaverages.at(e).at(j).at(z) + nets.at(i).get_layers().at(e)->getneurons()->at(j).getweights()[z]);
        } */
        model_.get_layers().at(e)->getneurons()->at(j).setbias(model_.get_layers().at(e)->getneurons()->at(j).getbias() + nets.at(i).get_layers().at(e)->getneurons()->at(j).getbias());
        model_.get_layers().at(e)->getneurons()->at(j).addweights(nets.at(i).get_layers().at(e)->getneurons()->at(j).getweights());
      }
    }
  }
  
  
  //Divide the added values to get the avages
  for (int i = 0; i < model_.get_layers().size(); i++){
      for (int e = 0; e < model_.get_layers().at(i)->getneurons()->size(); e++){
        model_.get_layers().at(i)->getneurons()->at(e).dividebias(nets.size());
        model_.get_layers().at(i)->getneurons()->at(e).divideweights(nets.size());
      }
        
  }   
  
  //Free network memory
  for (int i = 0; i < nets.size(); i++) {
      nets.at(i).free_network_mem();
  }
    
}

std::vector<double> intelligence::getinputs() const{
  return model_.getinputlayer().getactivations();
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

network intelligence::get_model(){
  return model_;
}
