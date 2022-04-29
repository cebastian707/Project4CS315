#include<iostream>
#include<cstdlib>
#include<fstream>
#include "DepGraph.hpp"

int main(int argc, const char* argv[]){
    std::ifstream inputstream;

    if (argc != 2) {
        std::cout << "usage: " << argv[0] << " name-of-a-makefile\n";
        exit(1);
    }




    inputstream.open(argv[0], std::ios::in);    // open for reading

    if (!inputstream.is_open()) {
        std::cout << "Unable to open " << argv[0] << ". Terminating...";
        exit(2);
    }

    // creates a Reader and build the dependency graph using the tokens that it returns.
    
    /*DepGraph* make = new DepGraph(argv[1]);
    make->parseDepGraph();
    if (make->isCyclic()) {
        std::cerr << "Input graph has cycles.\n";
        exit(1);
    }
    make->runMake();
    */
    return 0;
}
//exit(2) couldnt open file
//exit(1) not enough arguments