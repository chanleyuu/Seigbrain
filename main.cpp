#include <iostream>
#include <filesystem>
//#include <string>

#include "intelligence.h"
#include "layer.h"
#include "imageprocesser.h"

int main(int argc, char **argv) {
    std::cout << "Hello, Time!" << std::endl;
    imageprocesser im;

    std::filesystem::path cwd = std::filesystem::current_path()
    layer firstlayer = im.importimage(cwd + "/data/number1.jpg");
    intelligence intel(firstlayer);
    return 0;
}
