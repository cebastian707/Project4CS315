#pragma once
#ifndef _DepGraph_hpp
#define _DepGraph_hpp
#include<iostream>
#include<cstring>
#include "MakeTree.hpp"
#include"Tokenizer.hpp"
class DepGraph {
public:
    /// @brief constructor for the class
    /// @param name 
    DepGraph(std::string name);
    /// @brief prints items
    void print();
    /// @brief parses the makefile
    void parseDepGraph();
    /// @brief runs the command make
    void runMake();
    /// @brief 
    /// @returns true if graph is a cyclic 
    bool isCyclic();
private:
    /// @brief 
    /// @param mode 
    /// @return true if graph is a cyclic 
    bool isCyclic(GraphNode* mode);
    /// @brief private variables
    std::string _fileToMake, _targetToMake;
    GraphNode* firstTarget;
    MakeTree* _tree;  // MakeTree implements a binary-search tree similar to BinSearchTree
    Tokenizer tokenizer;
};
#endif