#define STB_IMAGE_IMPLEMENTATION

#include "imageprocesser.h"
#include "intelligence.h"


imageprocesser::imageprocesser(int size_x, int size_y)
{
  format = (char *)".jpg";
  height = size_x;
  width = size_y;
  std::vector<double> pixel_act;
  net_data =  new network(height * width, 0.5, 10);
  net_data->addlayer(10);
  net_data->addlayer(30);
  net_data->addlayer(10);
  net_data->init_weights();
  
  intelligence* blast =  new intelligence( net_data);
  
  blast_processor = blast;
  euler_ = my_math_euler_num();
}

imageprocesser::imageprocesser(char * directory, int size_x, int size_y, char * form)
{
  
  format = form;
  height = size_x;
  width = size_y;
  directory_ = my_math_concat(directory, (char *) "/data");
  std::vector<double> pixel_act;
  net_data =  new network(height * width, 0.5, 10);
  net_data->addlayer(100);
  net_data->addlayer(30);
  net_data->addlayer(10);
  net_data->init_weights();
  
  intelligence* blast =  new intelligence( net_data);
  
  blast_processor = blast;
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
    //height = 100;
    //width = 100;
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
      for (int i = 0; i < height; i++) {
          for (int e = 0; e < width; e++){
              
              //int h = 18;
              //int j = 1341;
              unsigned char* pixelOffset = rgb_image + (i + height * e) * bpp;
              unsigned char r = pixelOffset[0];
              unsigned char g = pixelOffset[1];
              unsigned char b = pixelOffset[2];
              unsigned char a = bpp >= 4 ? pixelOffset[3] : 0xff;
              double outer = double(r) + double(g) + double(b);
              
              
            // neuron n;
            // n.setbias(double(outer) / 630.0);
             // out.push_back(double(outer) / 630.0);
            //outer = outer / 3;
            outer = 1.0 / (1.0 + ( 1 / powf(euler_, outer)));
            if (outer == 1.0) {
                outer = outer - 0.0001;
            }
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

void imageprocesser::load_image_batch(int start, int end, bool shuff)
{
  //Load data
  char * path = my_math_concat(directory_, (char *) "/number");
  //printf("%s", path);
  double d = net_data->get_layers().at(0)->getneurons()->at(0).get_activation();
  //printf("%f \n",d);
  for (int i = start; i <= end; i++)
  {
    values_.push_back(importimage(my_math_concat(path, my_math_concat(my_math_toArray(i), format))));
  }
  //Load labels
  //Labes are stored in a file called "correct_answers.txt"
  char * correct_file = my_math_concat(directory_, (char *) "/correct_answers.txt");
  std::vector<std::vector<double>> correct;
  
  /*
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
        
  } */
  
  for (int i = start; i <= end; i++) {
    correct.push_back(get_correct_answers(labels[i]));
  }
  if (shuff == true) {
    srand((unsigned) time(NULL));
    int r = rand();
    shuffle(correct, r, 1);
    shuffle(values_, r, 1);
  }
  blast_processor->train_examples(values_, correct);
  //blast_processer.average_results();
  values_.clear();
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
  
  for (int i = start; i <= end; i++) {
    
    std::vector<double> in = importimage(my_math_concat(path, my_math_concat(my_math_toArray(i), format)));
    
    net_data->setfirstlayer(in);
    net_data->set_desire(get_correct_answers(labels[i]));
    
    std::vector<double> out = net_data->produceoutput();
    
    printf("%d %d \n", get_result(out), labels[i]);
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

void imageprocesser::save_model()
{
   FILE *fptr;

  // Open a file in writing mode
  fptr = fopen(my_math_concat(directory_, (char *) "/weights.dat"), "w");

  for (int i = 0; i < net_data->get_layers().size(); i++) {
    int n = net_data->get_layers().at(i)->getneurons()->size();
    int n2 = net_data->get_layers().at(i)->getneurons()->at(0).get_weight_count();
    // "<" character means new layer. The first number is the amount of nuerons and the second one the amount of weights per neuron
    fprintf(fptr, "< %d %d \n", n, n2);
    for (int e = 0; e < net_data->get_layers().at(i)->getneurons()->size(); e++) {
      fprintf(fptr, "%f ", net_data->get_layers().at(i)->getneurons()->at(e).getbias());
      for (int f = 0; f < net_data->get_layers().at(i)->getneurons()->at(e).get_weight_count(); f++) {
          fprintf(fptr, " %f ", net_data->get_layers().at(i)->getneurons()->at(e).getweights()[f]);
      }
      fprintf(fptr, " \n");
    }
    fprintf(fptr, "> \n");
  }
}

void imageprocesser::load_model()
{
  network* new_net = new network();
  std::vector<layer *> layers;
  
  
  FILE *fptr;
  fptr = fopen(my_math_concat(directory_, (char *) "/weights.dat"),"r");
  
  char islayer;
  int layersize;
  int weightcount;
  while (fscanf(fptr, "%s %d %d", &islayer, &layersize, &weightcount) != EOF) {
      if (islayer == '<') {

        layer * new_layer = new layer(&euler_);
        new_layer->init_vector();
        char start[2];
        start[0] = '%';
        start[1] = 'f';
        char * str = my_math_concat(start, start);
        for (int i = 0; i < layersize; i++){
          for (int e = 1; e < weightcount; e++) {
            str = my_math_concat(str, start);
          }
       }
      }
  }
}

void imageprocesser::load_labels(int amount)
{
  labels = (int*) malloc(amount * sizeof(int));
  
  char * correct_file = my_math_concat(directory_, (char *) "/correct_answers.txt");
  
  FILE *fptr;
  fptr = fopen(correct_file,"r");
  
  if (fptr == NULL)
        {
          printf("Error!");
          exit(1); 
        }
  
  for (int i = 1; i <= amount; i++) 
  {
        char str[20];
        int number;
        
        
        
        if (fscanf(fptr, "%s %d", str, &number) != EOF){
         //correct.push_back(get_correct_answers(number));
          labels[i] = number;
        }
        
  }
}

void imageprocesser::shuffle(std::vector<std::vector<double>> &array,int random, int next) 
{
  srand(random);
  int n = array.size();
  if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i+= next) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          for (int e = 0; e < next; e++) {
            if (j + next < n) { 
              std::vector<double> t = array[j + e];
              array[j + e] = array[i + e];
              array[i + e] = t;
            }
          }
        }
    }
}

void imageprocesser::average_batches()
{
  blast_processor->average_results();
}

void imageprocesser::free_mem()
{
  net_data->free_network_mem();
  delete net_data;
  delete blast_processor;
}
