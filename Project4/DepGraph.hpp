#pragma once
#ifndef _DepGraph_hpp
#define _DepGraph_hpp
#include<iostream>
#include<cstring>
#include "MakeTree.hpp"
#include"Tokenizer.hpp"
#include"GraphNode.hpp"
#include"systemInterface.hpp"
class DepGraph {
public:
    /// @brief constructor for the class
    /// @param name 
    DepGraph(std::string name);
    /// @brief overloaded function
    void print();
    /// @brief parses the makefile
    void parseDepGraph();
    /// @brief runs the command make
    void runMake();
    /// @brief 
    /// @returns true if graph is a cyclic 
    bool isCyclic();
private:

    /// @brief itervaley loops through the 
    /// depented children and checks if the depended nodes 
    /// has a bigger timestamp then its children 
    /// @param make 
    void itervaleycheckdepentednotes(GraphNode* make);


    /// @brief prints items
    void print(GraphNode* root);
   
    /// @brief parse just one token at a time
    void parserhelper(Token& parser);

    /// @brief helper function
    /// @param make 
    void runmakehelper(GraphNode* make);
    
    /// @brief 
    /// @param mode 
    /// @return true if graph is has cyclic 
    bool isCyclic(GraphNode* mode);
    
    /// @brief private variables
    std::string _fileToMake, _targetToMake , _command;
    long* time;
    GraphNode* firstTarget;
    MakeTree* _tree;  // MakeTree implements a binary-search tree similar to BinSearchTree
    Tokenizer tokenizer;
    bool _skip ,_isupdated;
};
#endif