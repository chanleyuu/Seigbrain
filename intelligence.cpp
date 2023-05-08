/*
* Intelligence.cpp
*
* Version information
* Author: Conall Hanley
* Date:19/06/2020
* Description: This file is the implementation file for the Intelligence class and defines (implements) the functions of the class
*
* This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include "intelligence.h"

intelligence::intelligence( network* model):  model_{ model }
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
  
 // std::vector<network> nets;
 /*
  network net( data[0], model_->getlearningrate(), model_->get_output_size());
  
  for (int e = 1; e < model_->get_layers().size(); e++){ //Skip the input layer which is first in the layer vector
        net.addlayer(model_->get_layers().at(e)->getneurons()->size());
  }
  net.init_weights();
  for(int e = 0; e < model_->get_layers().size(); e++) {
    for (int j = 0; j < model_->get_layers().at(e)->getneurons()->size(); j++) { */
        /*
        for (int z = 0; z < nets.at(i).get_layers().at(e)->getneurons()->at(j).get_weight_count(); z++) {
          //weightaverages.at(e).at(j).push_back( weightaverages.at(e).at(j).at(z) + nets.at(i).get_layers().at(e)->getneurons()->at(j).getweights()[z]);
        } */
    /*  net.get_layers().at(e)->getneurons()->at(j).setbias( model_->get_layers().at(e)->getneurons()->at(j).getbias());
      net.get_layers().at(e)->getneurons()->at(j).setweights(model_->get_layers().at(e)->getneurons()->at(j).getweights(), model_->get_layers().at(e)->getneurons()->at(j).get_weight_count());
    }
  } */
  
    
    
  std::vector<double> output;
  std::vector<double> c;
  double cost = 0.0;
  
  for (int i = 0; i < data.size(); i++) {
    
    
    model_->setfirstlayer(data[i]);
    /*
    for (int e = 0; e < net.get_layers().size(); e++){
      for (int j = 0; j < net.get_layers().at(e)->getneurons()->size(); j++){
        
        for (int z = 0; z < net.get_layers().at(i)->getneurons()->at(e).get_weight_count(); z++) {
          *net.get_layers().at(i)->getneurons()->at(e).getweights().getweights[z] = *model_.get_layers().at(i)->getneurons()->at(e).getweights().getweights[z];
        } 
        //printf("%d \n", j);
        net.get_layers().at(e)->getneurons()->at(j).setweights(model_->get_layers().at(e)->getneurons()->at(j).getweights(), model_->get_layers().at(e)->getneurons()->at(j).get_weight_count());
      }
    } */
    
    //net.produceoutput();
    model_->set_desire(correct.at(i));
    c = correct.at(i);
    
    //for (int e = 0; e < 10; e++){
      output = model_->produceoutput();
      model_->tunelayers();
      cost = model_->get_error();
   // }
    //output = model_->produceoutput();

    //}
    //nets.push_back(net);
  }
  
  //Calculate weight averages
  //std::vector<std::vector<std::vector<double>>> weightaverages;
  //std::vector<std::vector<double>> biasaverages;
  //Add all the weights and biases
  //Set the model to be the same as the
  /*
  for(int e = 0; e < nets.at(0).get_layers().size(); e++) {
      for (int j = 0; j < nets.at(0).get_layers().at(e)->getneurons()->size(); j++) {
        
        for (int z = 0; z < nets.at(i).get_layers().at(e)->getneurons()->at(j).get_weight_count(); z++) {
          //weightaverages.at(e).at(j).push_back( weightaverages.at(e).at(j).at(z) + nets.at(i).get_layers().at(e)->getneurons()->at(j).getweights()[z]);
        } 
        model_->get_layers().at(e)->getneurons()->at(j).setbias(nets.at(0).get_layers().at(e)->getneurons()->at(j).getbias());
        model_->get_layers().at(e)->getneurons()->at(j).setweights(nets.at(0).get_layers().at(e)->getneurons()->at(j).getweights(), nets.at(0).get_layers().at(e)->getneurons()->at(j).get_weight_count());
      }
    } */
  /*
  for (int i = 1; i < nets.size(); i++) {
    for(int e = 0; e < nets.at(i).get_layers().size(); e++) {
      for (int j = 0; j < nets.at(i).get_layers().at(e)->getneurons()->size(); j++) {
        
        for (int z = 0; z < nets.at(i).get_layers().at(e)->getneurons()->at(j).get_weight_count(); z++) {
          //weightaverages.at(e).at(j).push_back( weightaverages.at(e).at(j).at(z) + nets.at(i).get_layers().at(e)->getneurons()->at(j).getweights()[z]);
        } */ /*
        nets.at(0).get_layers().at(e)->getneurons()->at(j).setbias(nets.at(0).get_layers().at(e)->getneurons()->at(j).getbias() + nets.at(i).get_layers().at(e)->getneurons()->at(j).getbias());
        nets.at(0).get_layers().at(e)->getneurons()->at(j).addweights(nets.at(i).get_layers().at(e)->getneurons()->at(j).getweights());
      }
    }
  }
  
  
  //Divide the added values to get the avages
  for (int i = 0; i < nets.at(0).get_layers().size(); i++){
      for (int e = 0; e < nets.at(0).get_layers().at(i)->getneurons()->size(); e++){
        nets.at(0).get_layers().at(i)->getneurons()->at(e).dividebias(nets.size());
        nets.at(0).get_layers().at(i)->getneurons()->at(e).divideweights(nets.size());
      }
        
  }  */
  /*
  for(int e = 0; e < nets.at(0).get_layers().size(); e++) {
      for (int j = 0; j < nets.at(0).get_layers().at(e)->getneurons()->size(); j++) {
        
        
        model_->get_layers().at(e)->getneurons()->at(j).setbias(model_->get_layers().at(e)->getneurons()->at(j).getbias() + nets.at(0).get_layers().at(e)->getneurons()->at(j).getbias());
        model_->get_layers().at(e)->getneurons()->at(j).addweights(nets.at(0).get_layers().at(e)->getneurons()->at(j).getweights());
      }
    }
  
  for (int i = 0; i < model_->get_layers().size(); i++){
      for (int e = 0; e < model_->get_layers().at(i)->getneurons()->size(); e++){
        model_->get_layers().at(i)->getneurons()->at(e).dividebias(2);
        model_->get_layers().at(i)->getneurons()->at(e).divideweights(2);
      }
        
  }  */
  //batch_results.push_back(net);
  //Free network memory
  /*
  for (int i = 1; i < nets.size(); i++) {
     nets.at(i).free_network_mem();
  }
  nets.clear(); */
}

void intelligence::clean_outputs(std::vector<std::vector<double>> data)
{
  std::vector<double> output;
  std::vector<double> c;
  double cost = 0.0;
  std::vector<double> correct;
  
  for (int i = 0; i < 10; i++) {
  correct.push_back(0.0);
  }
  model_->set_desire(correct);
  
  for (int i = 0; i < 1000; i++) {
    
    
    model_->setfirstlayer(data[i]);
    
    c = correct;
    
    for (int e = 0; e < 10; e++){
      output = model_->produceoutput();
      model_->tunelayers();
      cost = model_->get_error();
    }
    //output = net.produceoutput();

    //}
    //nets.push_back(net);
  
  
  }
}


std::vector<double> intelligence::getinputs() const{
  return model_->getinputlayer().getactivations();
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

network* intelligence::get_model(){
  return model_;
}

void intelligence::set_model(network* model)
{
  model_ = model;
}

void intelligence::average_results()
{
  for (int i = 1; i < batch_results.size(); i++) {
    for(int e = 0; e < batch_results.at(i).get_layers().size(); e++) {
      for (int j = 0; j < batch_results.at(i).get_layers().at(e)->getneurons()->size(); j++) {
        /*
        for (int z = 0; z < nets.at(i).get_layers().at(e)->getneurons()->at(j).get_weight_count(); z++) {
          //weightaverages.at(e).at(j).push_back( weightaverages.at(e).at(j).at(z) + nets.at(i).get_layers().at(e)->getneurons()->at(j).getweights()[z]);
        } */
        batch_results.at(0).get_layers().at(e)->getneurons()->at(j).setbias( batch_results.at(0).get_layers().at(e)->getneurons()->at(j).getbias() + batch_results.at(i).get_layers().at(e)->getneurons()->at(j).getbias());
        batch_results.at(0).get_layers().at(e)->getneurons()->at(j).addweights(batch_results.at(i).get_layers().at(e)->getneurons()->at(j).getweights());
      }
    }
  }
  
  for (int i = 0; i < model_->get_layers().size(); i++){
      for (int e = 0; e < model_->get_layers().at(i)->getneurons()->size(); e++){
        batch_results.at(0).get_layers().at(i)->getneurons()->at(e).dividebias(batch_results.size());
        batch_results.at(0).get_layers().at(i)->getneurons()->at(e).divideweights(batch_results.size());
      }
        
  } 
  

    for(int e = 0; e < batch_results.at(0).get_layers().size(); e++) {
      for (int j = 0; j < batch_results.at(0).get_layers().at(e)->getneurons()->size(); j++) {
        /*
        for (int z = 0; z < nets.at(i).get_layers().at(e)->getneurons()->at(j).get_weight_count(); z++) {
          //weightaverages.at(e).at(j).push_back( weightaverages.at(e).at(j).at(z) + nets.at(i).get_layers().at(e)->getneurons()->at(j).getweights()[z]);
        } */
        model_->get_layers().at(e)->getneurons()->at(j).setbias( batch_results.at(0).get_layers().at(e)->getneurons()->at(j).getbias());
        model_->get_layers().at(e)->getneurons()->at(j).setweights(batch_results.at(0).get_layers().at(e)->getneurons()->at(j).getweights(), batch_results.at(0).get_layers().at(e)->getneurons()->at(j).get_weight_count());
      }
    }
  
  
  batch_results.clear();
  
}
