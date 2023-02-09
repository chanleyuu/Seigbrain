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
    //imageprocesser im;
    
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
    
   /* char[count] loc = link.;
    std::filesystem::__cxx11::path dou = new std::filesystem::__cxx11::path(cwd + "/data/number1.jpg") ;
    layer firstlayer(im.importimage("/home/aquadoff/projects/Seigbrain/data/number1.jpg")); */
    std::vector<double> firstlayer;
    firstlayer.push_back(0.5232);
    firstlayer.push_back(0.3123);
    firstlayer.push_back(0.8673);
    firstlayer.push_back(0.1232);
    firstlayer.push_back(0.432);
    firstlayer.push_back(0.5632);
    firstlayer.push_back(0.76532);
    firstlayer.push_back(0.9232);

    std::vector<double> correct;//Correct output
    correct.push_back(0);
    correct.push_back(0);
    correct.push_back(3);    
    correct.push_back(0);
    correct.push_back(0);
    correct.push_back(0);
    correct.push_back(0);
    correct.push_back(0);
    correct.push_back(0);
    
    //intelligence starthere(firstlayer, 0.3412, 9);
    network thenetwork(firstlayer, 0.5,  9);
//    starthere.getnetworks().push_back(thenetwork);
    thenetwork.addlayer(20);
    thenetwork.addlayer(20);
    //starthere.getnetworks()[0].feed();
    thenetwork.init_weights();
    
    std::vector<double> outs =  thenetwork.produceoutput();
    thenetwork.set_desire(correct);
    thenetwork.tunelayers();
    
    for (int i = 0; i < outs.size(); i++) {
      std::cout << outs[i] << std::endl;
    }
    
    std::cout << "---------------------" << std::endl;
    
    outs = thenetwork.produceoutput();
    
    for (int i = 0; i < outs.size(); i++) {
      std::cout << outs[i] << std::endl;
    }
    
    return 0;
}
