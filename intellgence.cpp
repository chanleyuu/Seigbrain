/*
* intelligence.cpp
*
* Version information
* Author: Conall Hanley
* Date:22/01/2020
* Description: This file is the implementation file file for the intellegence class and declares the class interface. 
*
* This class manages the various generations of networks in order to train them
* Copyright notice -
*/ 

#include "intelligence.h"

intelligence::intelligence(layer firstlayer){
    gen.push_back(firstlayer);
}

void intelligence::train()
{
    
}
