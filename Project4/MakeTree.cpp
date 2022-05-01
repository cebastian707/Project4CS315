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
	if (tNode == nullptr && nNode == nullptr)
		return new TreeNode(nNode);
	
	return nullptr;
}

void MakeTree::print(TreeNode* root){
	if (root == nullptr)
		return;
	print(root->left());
	std::cout << root->graphNode() << std::endl;
	print(root->right());
}
