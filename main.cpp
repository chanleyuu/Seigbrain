#include <iostream>
#include <filesystem>
//#include <string>

#include "intelligence.h"
#include "layer.h"
#include "lib/include/imageprocesser.h"

int main(int argc, char **argv) {
    std::cout << "Hello, Time!" << std::endl;
    imageprocesser im;

    
    std::filesystem::path cwd = std::filesystem::current_path();
    //std::filesystem::__cxx11::path dou = new std::filesystem::__cxx11::path(cwd + "/data/number1.jpg") ;
    layer firstlayer(im.importimage(cwd.string().c_str() + *"/data/number1.jpg"));
    intelligence intel(firstlayer, 0.5);
    return 0;
}
