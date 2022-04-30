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
	explicit Tokenizer(const std::string& inputfile);
	Token gettoken();

private:
	std::string inputFileName;
	std::fstream inputStream;
};
#endif // !Tokenizer_hpp

