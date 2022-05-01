#include"GraphNode.hpp"

std::string GraphNode::getName(){
	return _name;
}

void GraphNode::setName(std::string name){
	_name = name;
}

void GraphNode::setTimestamp(int ts){
	_timestamp = ts;
}

int GraphNode::getTimestamp(){
	return _timestamp;
}

std::vector<GraphNode*>* GraphNode::dependentNodes(){
	return _listOfDependentNodes;
}

void GraphNode::setCommand(std::string cmnd){
	_command = cmnd;
}

std::string GraphNode::getCommand(){
	return _command;
}

void GraphNode::addDependentNode(GraphNode* child){
	_listOfDependentNodes->push_back(child);
}

bool GraphNode::onPath(){
	return _onPath;
}

void GraphNode::onPath(bool v){
	_onPath = v;
}

bool GraphNode::wasMade(){
	return _wasMade;
}

void GraphNode::wasMade(bool v){
	_wasMade = v;
}

bool GraphNode::isATarget(){
	return _isATarget;
}

void GraphNode::isATarget(bool v){
	_isATarget = v;
}

int GraphNode::numDependentNodes(){
	return _listOfDependentNodes->size()-1;
}

void GraphNode::print(){
	std::cout << _name << std::endl;
}
