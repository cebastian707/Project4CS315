#include "DepGraph.hpp"
#include<iostream>

DepGraph::DepGraph(std::string name) :tokenizer{ name }, _tree{ new MakeTree() }, firstTarget{ nullptr }, _skip{ false }, time{ new long },_isupdated{ true }{
}


void DepGraph::print(GraphNode* root){
	if (root == nullptr)
		return;
	root->print();
	std::cout << std::endl;
	for (size_t i = 0; i < root->numDependentNodes(); i++){
		root->dependentNodes()->at(i)->print();
	}
	/*
	std::cout << root->getName() << "->" << std::endl;
	for (size_t i = 0; i < root->numDependentNodes(); i++) {
		print(root->dependentNodes()->at(i));
	}
	*/
}

void DepGraph::print(){
	print(firstTarget);
}

void DepGraph::parseDepGraph(){
	Token token;
	while (!token.endofile()){
		parserhelper(token);
		token = tokenizer.gettoken();
	
	}
	firstTarget = _tree->getRoot()->graphNode();
}

void DepGraph::runMake(){
	runmakehelper(firstTarget);

	//this variable if ever changed form true to false
	//means only one thing that the make file is not up to date
	if (_isupdated){
		std::cout << "makefile is up to date " << firstTarget->getName() << std::endl;
	}
}

bool DepGraph::isCyclic(){
	return isCyclic(firstTarget);
}

void DepGraph::parserhelper(Token& target){
	//get the first token we excepted to be a target file
	if (!_skip) {
		target = tokenizer.gettoken();
	}
	//know check if the target file is already in the maketree
	GraphNode* target_files = _tree->find(target.inputs());

	//check if this is a null pointer if it is 
	//that means we havent seen that specific filename and add it to the nodenames and insert in the tree
	if (!target_files){
		target_files = new GraphNode(target.inputs());
		_tree->insert(target_files);
		target_files->isATarget(true);


		//now lets check for a colon
		target = tokenizer.gettoken();

		if (!target.iscolon()){
			std::cout << "We excepted a colon" << std::endl;
			exit(4);
		}

		//we are know reading the dependcy filenames 
		target = tokenizer.gettoken();

		//this while loop reads all the dependcy files name
		while (!target.istab()){
			//check if this file is in the make tree
			GraphNode* depenendcy_files = _tree->find(target.inputs());

			//if we havent seen this depenendcy file added to the tree
			//and create a node
			if (!depenendcy_files){
				depenendcy_files = new GraphNode(target.inputs());
				_tree->insert(depenendcy_files);
				target_files->addDependentNode(depenendcy_files);
				target = tokenizer.gettoken();
			}

			//if we already seen it just make it the child node of the dependcy
			//of the current target file
			else if (depenendcy_files){
				target_files->addDependentNode(depenendcy_files);
				target = tokenizer.gettoken();
			}

		}
		//read the command for this specfic target file
		target = tokenizer.gettoken();
		target_files->setCommand(target.inputs());
		_skip = true;
	}

	//if we've already seen the target file 
	//lets go get its dependcy files
	else if(target_files) {
		target_files->isATarget(true);
		//now lets check for a colon
		target = tokenizer.gettoken();

		if (!target.iscolon()) {
			std::cout << "We excepted a colon" << std::endl;
			exit(4);
		}

		target = tokenizer.gettoken();

		//this while loop reads all the dependcy files name
		while (!target.istab()){
			GraphNode* dp_files = _tree->find(target.inputs());

			//if we havent seen these dependcy files 
			//go ahead and make a new node and insert them into  
			if (!dp_files){
				dp_files = new GraphNode(target.inputs());
				_tree->insert(dp_files);
				target_files->addDependentNode(dp_files);
				target = tokenizer.gettoken();
			}

			//if we already seen it just make it a child depepdent 
			//an then get a new token
			else if(dp_files){
				target_files->addDependentNode(dp_files);
				target = tokenizer.gettoken();
			}
		}

		//read the command for this specfic target file
		target = tokenizer.gettoken();
		target_files->setCommand(target.inputs());
		_skip = true;
	}

}
                                                                  
void DepGraph::runmakehelper(GraphNode* make){
	//1.check if the node exists by searching through the tree
	GraphNode* doesnt_exist = _tree->find(make->getName());
	
	//2.if this is a null pointer tell the user 
	//the file he provided doesnt exist 
	if (!doesnt_exist){
		std::cout << "The file does not exist " << make->getName() << std::endl;
		exit(4);
	}
	
	    
	//3.set the timestamp for every node
	_targetToMake = make->getName();
	timestamp(_targetToMake.c_str(), time);
	make->setTimestamp(*time);

	//4.if not a target start setting the time stamp of the leaf nodes
	if (!make->isATarget()){
		//5.then we know its a leaf node and exist 
		timestamp(_targetToMake.c_str(), time);
		make->setTimestamp(*time);
	}
	

	//6.loop through the graph recursivly 
	for (size_t i = 0; i < make->numDependentNodes(); i++) {
		runmakehelper(make->dependentNodes()->at(i));
	}

	//7.check if node is a target
	if (make->isATarget()) {
		//8.set the timestamp
		_targetToMake = make->getName();
		timestamp(_targetToMake.c_str(), time);
		make->setTimestamp(*time);

		//9.loop through its depended notes and 
		//compare if any of the depended nodes are bigger
		//run the command bottoms up on the way coming back
		for (size_t i = 0; i < make->numDependentNodes(); i++) {
				if (make->getTimestamp() < make->dependentNodes()->at(i)->getTimestamp()){
					_command = make->getCommand();
					executeCommand(_command.c_str());
					timestamp(_targetToMake.c_str(), time);
					make->setTimestamp(*time);
					_isupdated = false;
				}
		}

	}

}


bool DepGraph::isCyclic(GraphNode* mode){
	//check if the node onpath is set to tree then that means we would have to 
	//already seen that node
	//1.Base Case should never be reached
	if (mode->onPath())
		return true;

	//2.Set onPath to true
	//set the node onpath to true
	mode->onPath(true);

	//3.recurisvly get its children
	for (size_t i = 0; i < mode->numDependentNodes(); i++) {
		bool iscycle = isCyclic(mode->dependentNodes()->at(i));

		//5.whatever we return form the stack means two things
		//if iscycle returns true that means we have a cycle just return that
		//else loop through the rest of the graph
		if (iscycle)
			return iscycle;
	}

	//4.once we had a leaf node start setting them(nodes) to false 
	mode->onPath(false);
	return false;
}
//exit(4) no colon found in makefile or file doesnt exist