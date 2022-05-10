#include<iostream>
#include<string>
#include"Tokenizer.hpp"

Tokenizer::Tokenizer(const std::string& inputfile) :inputFileName{ inputfile } {
	inputStream.open(inputfile, std::ios::in);
	pervious = '\0';
}

Token Tokenizer::gettoken() {
	if (!inputStream.is_open()) {
		std::cout << "Input stream in Tokenizer::getToken is not open. Terminating...\n";
		exit(4);
	}

	char c;
	std::string target = "";



	if (pervious == '\t') {
		while (inputStream >> std::noskipws >> c){
			if (c == '\n') {
				inputStream.putback(c);
				break;
			}
			target.push_back(c);
		}
		pervious = '\0';
		Token token(target);
		return token;
	}


	while (inputStream >> std::noskipws >> c){
		if (inputStream.eof()) {
			Token token;
			token.eof();
			return token;
		}

		else if (c == ':' || c == '\t') {
			Token token(c);
			pervious = c;
			return token;
		}

		else if (c == '\n' || isspace(c)) {
			continue;
		}


		else if (isalpha(c)) {
			target.push_back(c);
			while (inputStream>>std::noskipws >> c){
				if (c == '\n' || c ==':' || isspace(c)) {
					inputStream.putback(c);
					break;
				}
				target.push_back(c);
			}
			Token token(target);
			return token;
		}
	}

	if (inputStream.eof()) {
		Token token;
		token.eof();
		return token;
	}
		
		Token token;
		token.eof();
		return token;

}
//exit(4) file not open