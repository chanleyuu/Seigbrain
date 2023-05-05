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
#include <stdint.h>
#include <stdlib.h>
#include <vector>
//#include <opencv2/opencv.hpp>
/*
#include <ImageMagick-7/Magick++.h>
#include <ImageMagick-7/MagickCore/MagickCore.h>
#include <ImageMagick-7/MagickCore/quantum.h> */
#include "./include/stb/stb_image.h"
#include "network.h"
#include "my_math.h"
#include "intelligence.h"
#include <iostream>
#include <stdio.h>

//#include "layer.h"
//#include "neuron.h"

class imageprocesser {

private:
    //Magick::Image image_;
    char* format;
    
    int* labels;
    
    int width, height, bpp;
    
    double euler_;
    
    uint8_t* rgb_image;
    stbi_uc *image;

    std::vector<std::vector<double>> values_;
    
    char * directory_;
    
    double GetPixel(stbi_uc *image, size_t imageWidth, size_t x, size_t y, stbi_uc *r, stbi_uc *g, stbi_uc *b, stbi_uc *a);
    
    network* net_data;
    
    intelligence* blast_processor;
    /* {
        const stbi_uc *p = image + (4 * (y * imageWidth + x));
    *r = p[0];
    *g = p[1];
    *b = p[2];
    *a = p[3];
    
    double out =  10;
    return out;
    }*/;

public:
    imageprocesser(int size_x, int size_y); //constructor
    
    imageprocesser(char * directory, int size_x, int size_y, char * form); //constructor

    std::vector<double> importimage(const char imagepath[]);
    
    void load_image(std::string im);
    
    void load_image_batch(int start, int end, bool shuff = true);
    
    std::vector<double> process_image(const char imagepath[]);
    
    std::vector<double> get_correct_answers(int number);
    
    void set_model(network* net);
    
    void output_images(int start, int end);

    network* get_model();
    
    int get_result(std::vector<double> result);
    
    void save_model();
    
    void load_model();
    
    void load_data(int amount);
    
    void shuffle(std::vector< std::vector< double > > &array, int random, int next);
    
    void clean();
    
    void average_batches();
    
    void free_mem();
    /*{
    
    //Steps : Load image
    // Extract pixel values_
    // Put pixel values through a sigmoid function
    // Create layer
        
    //TO DO, set image as inputs for neural network 
    height = 100;
    width = 100;
    bpp = 4;
    
    std::vector<double> out;

    try {
        rgb_image = stbi_load(imagepath, &width, &height, &bpp, 3);
    }
    catch( std::exception &error_ )
    {
        std::cout << "ERROR!: " << error_.what() << std::endl;
    }
    
    for (int i = 0; i < 100; i++) {
        for (int e = 0; e <100; e++){
            
            int i = 18;
            int j = 1341;
            unsigned char* pixelOffset = rgb_image + (i + height * j) * bpp;
            unsigned char r = pixelOffset[0];
            unsigned char g = pixelOffset[1];
            unsigned char b = pixelOffset[2];
            unsigned char a = bpp >= 4 ? pixelOffset[3] : 0xff;
            long outer = long(r) + long(g) + long(b);
            
            
           // neuron n;
           // n.setbias(double(outer) / 630.0);
            out.push_back(double(outer) / 630.0);
        }
    } 

    
    //MagickCore::Quantum *pixels = image_.getPixels(0, 0, width, height);
    
    //for (int i = 0; i < width; i++){
      //for(int e = 0; e < height; e++){

        //unsigned offset = image_.channels() * (width * i + e);
      //  Magick::ColorGray pixcolor = pixels[width * i + e];
        //double pixcolor = (255.0 / pixels[offset + 0] / 10.0) +
        //(255.0 / pixels[offset + 1] / 10.0) +
        //(255.0 / pixels[offset + 2] / 10.0);
        //neuron value(i * e, pixcolor, 0);
        //out.addneuron(value);
      //}
    //} 

    return out; 
    } */;
};
