/*created by Cebastian Santiago
* CS315 project 4
*/
#pragma once
#ifndef _Tokenizer_hpp
#define _Tokenizer_hpp
#include"Token.hpp"
#include<string>
#include<fstream>
class Tokenizer{
public:
	/// @brief intialize the Makefile to be open
	/// @param inputfile 
	explicit Tokenizer(const std::string& inputfile);
	/// @brief token function
	/// @returns tokens of the makefile
	Token gettoken();

private:
	/// @brief variables of the Tokenizer
	std::string inputFileName;
	std::fstream inputStream;
};
#endif // !Tokenizer_hpp

