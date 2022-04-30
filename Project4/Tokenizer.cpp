#include<iostream>
#include<string>
#include"Tokenizer.hpp"

Tokenizer::Tokenizer(const std::string& inputfile) :inputFileName{ inputfile } {
	inputStream.open(inputfile, std::ios::in);
}

Token Tokenizer::gettoken(){
	if (!inputStream.is_open()) {
		std::cout << "Input stream in Tokenizer::getToken is not open. Terminating...\n";
		exit(4);
	}

	char c;
	std::string get = "";
	
	while (inputStream  >> c){
		
		if (c == ':'){

		}
		get.push_back(c);
	}
	




}
//exit(4) file not open