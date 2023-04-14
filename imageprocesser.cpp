#define STB_IMAGE_IMPLEMENTATION

#include "imageprocesser.h"
#include "intelligence.h"


imageprocesser::imageprocesser()
{
  std::vector<double> pixel_act;
  net_data =  new network(10000, 1.5, 10);
  net_data->addlayer(100);
  net_data->addlayer(100);
  net_data->addlayer(100);
  net_data->init_weights();
  
  euler_ = my_math_euler_num();
}

imageprocesser::imageprocesser(char * directory)
{
  
  directory_ = my_math_concat(directory, (char *) "/data");
  std::vector<double> pixel_act;
  net_data =  new network(10000, 1.5, 10);
  net_data->addlayer(100);
  net_data->addlayer(100);
  net_data->addlayer(100);
  net_data->init_weights();
  
  euler_ = my_math_euler_num();
}


double GetPixel(stbi_uc *image, size_t imageWidth, size_t x, size_t y, stbi_uc *r, stbi_uc *g, stbi_uc *b, stbi_uc *a) {
    const stbi_uc *p = image + (4 * (y * imageWidth + x));
    *r = p[0];
    *g = p[1];
    *b = p[2];
    *a = p[3];
    
    double out =  10;
    return out;
}

std::vector< double > imageprocesser::importimage(const char imagepath[])
{

    /*TO DO, set image as inputs for neural network */
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
    if (rgb_image) {
      for (int i = 0; i < 100; i++) {
          for (int e = 0; e <100; e++){
              
              //int h = 18;
              //int j = 1341;
              unsigned char* pixelOffset = rgb_image + (i + height * e) * bpp;
              unsigned char r = pixelOffset[0];
              unsigned char g = pixelOffset[1];
              unsigned char b = pixelOffset[2];
              unsigned char a = bpp >= 4 ? pixelOffset[3] : 0xff;
              long outer = long(r) + long(g) + long(b);
              
              
            // neuron n;
            // n.setbias(double(outer) / 630.0);
             // out.push_back(double(outer) / 630.0);
            outer = outer / 3;
            outer = 1.0 / (1.0 + powf(euler_, (-1.0 * outer)));
            out.push_back(outer);
          }
      }
    }
    else {
      std::cout << "Image not loaded!" << std::endl;
      return out;
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

void imageprocesser::load_image_batch(int start, int end)
{
  //Load data
  char * path = my_math_concat(directory_, (char *) "/number");
  printf("%s", path);
  double d = net_data->get_layers().at(0)->getneurons()->at(0).get_activation();
  printf("%f \n",d);
  for (int i = start; i < end; i++)
  {
    values_.push_back(importimage(my_math_concat(path, my_math_concat(my_math_toArray(i), (char *) ".jpg"))));
  }
  //Load labels
  //Labes are stored in a file called "correct_answers.txt"
  char * correct_file = my_math_concat(directory_, (char *) "/correct_answers.txt");
  std::vector<std::vector<double>> correct;
  
  FILE *fptr;
  fptr = fopen(correct_file,"r");
  
  if (fptr == NULL)
        {
          printf("Error!");
          exit(1); 
        }
  
  for (int i = start; i < end; i++) 
  {
        char str[20];
        int number;
        
        
        
        if (fscanf(fptr, "%s %d", str, &number) != EOF){
         correct.push_back(get_correct_answers(number));
        }
        
  }
  
  
  intelligence blast_processer(values_.at(0), net_data);
  blast_processer.train_examples(values_, correct);
}

//Converts a single digit integer into neuron activations to compare against outputs
std::vector<double> imageprocesser::get_correct_answers(int number)
{
  std::vector<double> out;
  switch (number){
    case 0:
      out.push_back(1.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      break;
    case 1:
      out.push_back(0.0);
      out.push_back(1.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      break;
    case 2:
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(1.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      break;
    case 3:
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(1.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      break;
    case 4:
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(1.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      break;
    case 5:
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(1.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      break;
    case 6:
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(1.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      break;
    case 7:
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(1.0);
      out.push_back(0.0);
      out.push_back(0.0);
      break;
    case 8:
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(1.0);
      out.push_back(0.0);
      break;
    case 9:
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(1.0);
      break;
    default :
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      out.push_back(0.0);
      break;
  }
  return out;
}



void imageprocesser::load_image(std::string im)
{
  //cv::Mat image = imread(im, cv::IMREAD_GRAYSCALE);
  
  /*for (int i = 0; i < ; i++) {
    for (int e = 0; e < (int) ; e++) {
      
    }
  } */
}

void imageprocesser::set_model(network* net)
{
  net_data = net;
}


network* imageprocesser::get_model()
{
  return net_data;
}

std::vector<double> imageprocesser::process_image(const char imagepath[])
{
  std::vector<double> image = importimage(imagepath);
  
  net_data->setfirstlayer(image);
  
  std::vector<double> out = net_data->produceoutput();
  
  return out;
}

void imageprocesser::output_images(int start, int end) {
  
  char * path = my_math_concat(directory_, (char *) "/number");
  
  for (int i = start; i < end; i++) {
    
    std::vector<double> in = importimage(my_math_concat(path, my_math_concat(my_math_toArray(i), (char *) ".jpg")));
    
    net_data->setfirstlayer(in);
    
    std::vector<double> out = net_data->produceoutput();
    
    printf("%d \n", get_result(out));
    /*
    for (int i = 0; i < out.size(); i++) {
     printf("%f \n", out[i]);
    } */
  }
}

int imageprocesser::get_result(std::vector<double> result)
{
  int out = 0;
  double largest = 0.0;
  for (int i = 0; i < result.size(); i++){
    if (largest < result.at(i)) {
        largest = result.at(i);
        out = i;
    }
  }
  return out;
}

