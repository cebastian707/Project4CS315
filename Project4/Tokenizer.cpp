#include<iostream>
#include<string>
#include"Tokenizer.hpp"

Tokenizer::Tokenizer(const std::string& inputfile) :inputFileName{ inputfile } {
	inputStream.open(inputfile, std::ios::in);
}

Token Tokenizer::gettoken() {
	if (!inputStream.is_open()) {
		std::cout << "Input stream in Tokenizer::getToken is not open. Terminating...\n";
		exit(4);
	}

	char c;
	std::string target = "";

		inputStream >> std::noskipws >> c;
		
		if (inputStream.eof()) {
			Token token;
			token.eof();
			return token;
		}

		else if (isalpha(c)) {
			target.push_back(c);
			while (inputStream >> std::noskipws >> c) {
				if (c == '\n' || c == ':') {
					inputStream.putback(c);
					break;
				}
				target.push_back(c);
			}
			Token token(target);
			return token;
		}

		else{
			Token token(c);
			return token;
		}

	
	
	

}
//exit(4) file not open