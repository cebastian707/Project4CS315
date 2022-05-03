#include "DepGraph.hpp"

DepGraph::DepGraph(std::string name) :tokenizer{ name }, _tree{new MakeTree}, firstTarget{nullptr} {

}

void DepGraph::print(){
}

void DepGraph::parseDepGraph(){

	   
}

void DepGraph::runMake(){
}

bool DepGraph::isCyclic(){
	return isCyclic(firstTarget);
}

bool DepGraph::isCyclic(GraphNode* mode){
	return false;
}
