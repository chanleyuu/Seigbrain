

#include "imageprocesser.h"

imageprocesser::imageprocesser()
{

}

void GetPixel(stbi_uc *image, size_t imageWidth, size_t x, size_t y, stbi_uc *r, stbi_uc *g, stbi_uc *b, stbi_uc *a) {
    const stbi_uc *p = image + (4 * (y * imageWidth + x));
    *r = p[0];
    *g = p[1];
    *b = p[2];
    *a = p[3];
}

layer imageprocesser::importimage(const char imagepath[])
{

    /*TO DO, set image as inputs for neural network */
    height = 100;
    width = 100;

    layer out;

    try {
        rgb_image = stbi_load(imagepath, &width, &height, &bpp, 3);
    }
    catch( std::exception &error_ )
    {
        std::cout << "ERROR!: " << error_.what() << std::endl;
    }
    

    /*
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
    } */

    return out;
}
