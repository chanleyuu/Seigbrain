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
    
  /*  std::vector<double> moredata;
    moredata.push_back(0.632);
    moredata.push_back(0.8123);
    moredata.push_back(0.3673);
    moredata.push_back(0.2232);
    moredata.push_back(0.3432);
    moredata.push_back(0.532);
    moredata.push_back(0.86532);
    moredata.push_back(0.0232);

    std::vector<double> moredata2;
    moredata2.push_back(0.732);
    moredata2.push_back(0.91423423);
    moredata2.push_back(0.2342373);
    moredata2.push_back(0.6421232);
    moredata2.push_back(0.93432);
    moredata2.push_back(0.2147532);
    moredata2.push_back(0.3386532);
    moredata2.push_back(0.640232);
    
    std::vector<double> moredata3;
    moredata3.push_back(0.32);
    moredata3.push_back(0.14564);
    moredata3.push_back(0.2342373);
    moredata3.push_back(0.921232);
    moredata3.push_back(0.473432);
    moredata3.push_back(0.32147532);
    moredata3.push_back(0.63332);
    moredata3.push_back(0.740232); */
    
    
    std::vector<double> correct;//Correct output
    correct.push_back(0.0);//Need to reject correct answers that are not the same size as the ouput layer
    correct.push_back(0.0);
    correct.push_back(1.0);    
    correct.push_back(0.0);
    correct.push_back(0.0);
    correct.push_back(0.0);
    correct.push_back(0.0);
    correct.push_back(0.0);
    correct.push_back(0.0);
    
   /* std::vector<double> correct2;//Correct output
    correct2.push_back(0.0);//Need to reject correct answers that are not the same size as the ouput layer
    correct2.push_back(0.0);
    correct2.push_back(0.0);    
    correct2.push_back(0.0);
    correct2.push_back(1.0);
    correct2.push_back(0.0);
    correct2.push_back(0.0);
    correct2.push_back(0.0);
    correct2.push_back(0.0);
    
    std::vector<double> correct3;//Correct output
    correct3.push_back(0.0);//Need to reject correct answers that are not the same size as the ouput layer
    correct3.push_back(1.0);
    correct3.push_back(0.0);    
    correct3.push_back(0.0);
    correct3.push_back(0.0);
    correct3.push_back(0.0);
    correct3.push_back(0.0);
    correct3.push_back(0.0);
    correct3.push_back(0.0);
    
    std::vector<double> correct4;//Correct output
    correct4.push_back(1.0);//Need to reject correct answers that are not the same size as the ouput layer
    correct4.push_back(0.0);
    correct4.push_back(0.0);    
    correct4.push_back(0.0);
    correct4.push_back(0.0);
    correct4.push_back(0.0);
    correct4.push_back(0.0);
    correct4.push_back(0.0);
    correct4.push_back(0.0); */
    
    network thenetwork(firstlayer, 1.5,  9);
    //intelligence starthere(firstlayer, thenetwork);
//    starthere.getnetworks().push_back(thenetwork);
    thenetwork.addlayer(20);
    thenetwork.addlayer(20);
    //starthere.getnetworks()[0].feed();
    thenetwork.init_weights();
    
    std::vector<double> outs =  thenetwork.produceoutput();
    thenetwork.set_desire(correct);
    
    for (int i = 0; i < outs.size(); i++) {
      std::cout << std::setprecision(8) << outs[i] << std::endl;
    }
    
    std::cout << "---------------------" << std::endl;
    
    thenetwork.tunelayers();
    
    outs = thenetwork.produceoutput();
    
    for (int i = 0; i < outs.size(); i++) {
      std::cout << std::setprecision(8) << outs[i] << std::endl;
    }
    
    std::cout << "---------------------" << std::endl;
    
    for (int i = 0; i < 10000; i++){
      thenetwork.produceoutput();
      thenetwork.tunelayers();
    }
    
    outs = thenetwork.produceoutput();
    
    for (int i = 0; i < outs.size(); i++) {
      std::cout << std::setprecision(8) << outs[i] << std::endl;
    }
    
    return 0;
}
