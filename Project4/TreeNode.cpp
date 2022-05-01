#include<iostream>
#include"TreeNode.hpp"

TreeNode::TreeNode(GraphNode* nNode){
	leftSubtree = nullptr;
	rightSubtree = nullptr;
	makeNode = nNode;
}

TreeNode* TreeNode::left(){
	return leftSubtree;
}

void TreeNode::left(TreeNode* leftPtr){
	this->leftSubtree = leftPtr;
}

TreeNode* TreeNode::right(){
	return rightSubtree;
}

void TreeNode::right(TreeNode* rightPtr){
	this->rightSubtree = rightPtr;
}

void TreeNode::print(){
	 makeNode->print();
}

GraphNode* TreeNode::graphNode(){
	return makeNode;
}
