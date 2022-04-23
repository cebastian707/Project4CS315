#pragma once
#ifndef _DepGraph_hpp
#define _DepGraph_hpp
#include<iostream>
#include<cstring>
#include "MakeTree.hpp"

class DepGraph {
public:
    DepGraph(std::string name);
    void print();
    void parseDepGraph();
    void runMake();
    bool isCyclic();
private:
    bool isCyclic(GraphNode*);
    std::string _fileToMake, _targetToMake;
    GraphNode* firstTarget;
    MakeTree* _tree;  // MakeTree implements a binary-search tree similar to BinSearchTree
};

#endif