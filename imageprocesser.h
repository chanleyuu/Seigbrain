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

#define STB_IMAGE_IMPLEMENTATION

#include <fstream>
#include <string>
#include <stdint.h>
#include <stdlib.h>
/*
#include <ImageMagick-7/Magick++.h>
#include <ImageMagick-7/MagickCore/MagickCore.h>
#include <ImageMagick-7/MagickCore/quantum.h> */
#include <stb/stb_image.h>
#include <iostream>

//#include "layer.h"
//#include "neuron.h"

class imageprocesser {

private:
    //Magick::Image image_;
    
    int width, height, bpp;
    
    uint8_t* rgb_image;

    std::vector<double> values_;
    
    double GetPixel(stbi_uc *image, size_t imageWidth, size_t x, size_t y, stbi_uc *r, stbi_uc *g, stbi_uc *b, stbi_uc *a) ;

public:
    imageprocesser(); //constructor

    std::vector<double> importimage(const char imagepath[]);
};
