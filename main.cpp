#include <iostream>
#include <filesystem>
//#include <string>

#include "intelligence.h"
//#include "layer.h"
#include "imageprocesser.h"
#include <sstream>
#include <unistd.h>

int main(int argc, char **argv) {
    std::cout << "Hello, Time!" << std::endl;
    imageprocesser im;
    
    unsigned int bufferSize = 512;
    std::vector<char> buffer(bufferSize + 1);

    // Get the process ID.
  int pid = getpid();

  // Construct a path to the symbolic link pointing to the process executable.
  // This is at /proc/<pid>/exe on Linux systems (we hope).
  std::ostringstream oss;
  oss << "/proc/" << pid << "/exe";
  std::string link = oss.str();

  // Read the contents of the link.
  int count = readlink(link.c_str(), &buffer[0], bufferSize);
  if(count == -1) throw std::runtime_error("Could not read symbolic link");
  buffer[count] = '\0';

    
    std::filesystem::path cwd = std::filesystem::current_path();
    
   // char[count] loc = link.;
    //std::filesystem::__cxx11::path dou = new std::filesystem::__cxx11::path(cwd + "/data/number1.jpg") ;
    layer firstlayer(im.importimage("/home/aquadoff/projects/Seigbrain/data/number1.jpg"));
    intelligence intel(firstlayer, 0.5);
    
    return 0;
}
