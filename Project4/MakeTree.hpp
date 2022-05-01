#pragma once
#ifndef _MakeTree_hpp
#define _MakeTree_hpp
#include<iostream>
#include<string>
#include "TreeNode.hpp"

class MakeTree {
public:
    /// @brief contruct for the class
    MakeTree();
    /// @brief inserts elements to make bst and inserts elements to the graph
    /// @param nNode 
    void insert(GraphNode* nNode) { _root = insert(_root, nNode); }
    /// @brief goes through bst and returns the graphNode
    /// @param name 
    /// @returns GraphNode ??? 
    GraphNode* find(std::string name);
    /// @brief prints the tree using in-order traversal
    void print() { print(_root); }   // print the tree using in-order traversal
    /// @brief gets the root
    /// @returns root 
    TreeNode* getRoot() { return _root; }
private:
    /// @brief inserts elements into the graph node and bst
    /// @param tNode 
    /// @param nNode 
    /// @returns the inserted elements into treenode and graph  
    TreeNode* insert(TreeNode* tNode, GraphNode* nNode);
    /// @brief print the tree using in-order traversal
    /// @param root 
    void print(TreeNode* root);
    /// @brief private variable for the MakeTree class
    TreeNode* _root;
};
#endif