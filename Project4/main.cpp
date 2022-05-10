#include<iostream>
#include<cstdlib>
#include<fstream>
#include "DepGraph.hpp"

int main(int argc, const char* argv[]){
    std::ifstream inputstream;

    if (argc != 2) {
        std::cout << "usage: " << argv[1] << " name-of-a-makefile\n";
        exit(1);
    }
    inputstream.open(argv[1], std::ios::in);    // open for reading

    if (!inputstream.is_open()) {
        std::cout << "Unable to open " << argv[1] << ". Terminating...";
        exit(2);
    }
    inputstream.close();

    
    // creates a Reader and build the dependency graph using the tokens that it returns.
    DepGraph* make = new DepGraph(argv[1]);
    make->parseDepGraph();
    //make->print();
    if (make->isCyclic()) {
        std::cerr << "Input graph has cycles.\n";
        exit(1);
    }
    make->runMake();
   
    return 0;
}
//exit(2) couldnt open file
//exit(1) not enough arguments