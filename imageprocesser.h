/*
* imageprocesser.h
*
* Version information
* Author: Conall Hanley
* Date:22/01/2020
* Description: This file is the header file for the network imageprocesser and declares the class interface.
* This class is responsible for creating a layer out of
* This class processes images and turns it into data for the neural network
* Copyright notice -
*/

#pragma once

#include <fstream>
#include <string>
#include <ImageMagick-7/Magick++.h>
#include <ImageMagick-7/MagickCore.h>
#include <iostream>

#include "layer.h"
#include "neuron.h"

class imageprocesser {

private:
    Magick::Image image_;

    layer imagelayer_;

public:
    imageprocesser(); //constructor

    layer importimage(std::string imagepath);
};
