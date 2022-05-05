#pragma once
#ifndef _TreeNode_hpp
#define _TreeNode_hpp
#include<iostream>
#include<string>
#include"GraphNode.hpp"

class TreeNode {
public:
    /// @brief construct for the class
    /// @param nNode 
    TreeNode(GraphNode* nNode);
    /// @brief left child of the tree
    /// @returns left child 
    TreeNode* left();      // getter
    /// @brief sets leftptr equal to leftsubtree
    /// @param leftPtr 
    void left(TreeNode* leftPtr);  // setter
    /// @brief right child of the tree
    /// @returns right child 
    TreeNode* right();
    /// @brief sets rightptr equal to rightsubtree
    /// @param rightPtr 
    void right(TreeNode* rightPtr);
    /// @brief prints the makenode
    void print();   // print the value of this node
    /// @returns makeNode 
    GraphNode* graphNode();
private:
    /// @brief private variables for TreeNode Class
    GraphNode* makeNode;
    TreeNode* leftSubtree, * rightSubtree;
};

#endif