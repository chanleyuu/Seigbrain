

#include "imageprocesser.h"

imageprocesser::imageprocesser()
{
    
}

void imageprocesser::importimage()
{
    Magick::Image image;
    
    /*TO DO, set image as inputs for neural network */
    try {
        image.read( "./data/number1.jpg" );
    }
    catch( std::exception &error_ )
    {
        std::cout << "ERROR!: " << error_.what() << std::endl;
    }
}
