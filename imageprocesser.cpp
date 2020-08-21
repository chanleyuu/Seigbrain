

#include "imageprocesser.h"

imageprocesser::imageprocesser()
{

}

layer imageprocesser::importimage(std::string imagepath)
{

    /*TO DO, set image as inputs for neural network */
    int height = 100;
    int width = 100;

    layer out;

    try {
        image_.read( imagepath );
    }
    catch( std::exception &error_ )
    {
        std::cout << "ERROR!: " << error_.what() << std::endl;
    }

    MagickCore::Quantum *pixels = image_.getPixels(0, 0, width, height);
    
    for (int i = 0; i < width; i++){
      for(int e = 0; e < height; e++){

        unsigned offset = image_.channels() * (width * i + e);
      //  Magick::ColorGray pixcolor = pixels[width * i + e];
        double pixcolor = (255.0 / pixels[offset + 0] / 10.0) +
        (255.0 / pixels[offset + 1] / 10.0) +
        (255.0 / pixels[offset + 2] / 10.0);
        neuron value(i * e, pixcolor, 0);
        out.addneuron(value);
      }
    }

    return out;
}
