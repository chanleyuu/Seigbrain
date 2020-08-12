/*
* imageprocesser.h
*
* Version information
* Author: Conall Hanley
* Date:22/01/2020
* Description: This file is the header file for the network imageprocesser and declares the class interface. 
* This class is responsible for creating a layer out of 
* Copyright notice -
*/ 

#pragma once

#include <fstream>
#include <ImageMagick-7/Magick++.h>
#include <iostream>

#include "layer"

class imageprocesser {
    
private:
    layer imagelayer
public:
    imageprocesser(); //constructor
    
    void importimage();
};
