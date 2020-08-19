

#include "imageprocesser.h"

imageprocesser::imageprocesser()
{

}

void imageprocesser::importimage(std::string imagepath)
{

    /*TO DO, set image as inputs for neural network */
    try {
        image_.read( imagepath );
    }
    catch( std::exception &error_ )
    {
        std::cout << "ERROR!: " << error_.what() << std::endl;
    }
}
