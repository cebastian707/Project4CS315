#include "MakeTree.hpp"

MakeTree::MakeTree(){
	_root = nullptr;
}

GraphNode* MakeTree::find(std::string name){
	TreeNode* temp = _root;

	while (temp != nullptr){
		if (temp->graphNode()->getName() == name) {
			return temp->graphNode();
		
		}

		if (temp->graphNode()->getName() > name){
			temp = temp->right();
		}

		else{
			temp = temp->left();
		}
	}
	return nullptr;
}

TreeNode* MakeTree::insert(TreeNode* tNode, GraphNode* nNode){
	if (tNode == nullptr)
		return new TreeNode(nNode);
	if (tNode->graphNode()->getName() < nNode->getName())
		tNode->right(insert(tNode->right(), nNode));
	else
		tNode->left(insert(tNode->left(), nNode));
	return tNode;
}

void MakeTree::print(TreeNode* root){
	if (root == nullptr)
		return;
	print(root->left());
	root->graphNode()->print();
	print(root->right());
}