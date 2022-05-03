/*created by Cebastian Santiago 
* CS315 project 4
*/
#pragma once
#ifndef _Token_hpp
#define _Token_hpp
#include<string>

class Token{
public:
	/// @brief basic constructor
	Token();
	/// @brief Accepts a string as the token to parser by dephgraph
	/// @param in 
	Token(std::string in);

	/// @brief Accepts a char to be parser by the dephgraph
	/// @param c 
	Token(char c);
	
	/// @brief 
	/// @returns true if token is a colon 
	bool charcter();

	/// @brief 
	/// @returns true of input is some type of string
	bool input();

	/// @brief 
	/// @returns string token 
	std::string inputs();
	
	/// @brief 
	/// @returns char token
	char charcters();
	
	/// @brief end of file token
	void eof();
	
	/// @brief 
	/// @ returns eof  true ive we reached endoffile
	bool endofile();

	/// @brief prints the tokens
	void print();
private:
	/// @brief variables of the token class
	std::string _input;
	char _charcter;
	bool _isinput,_ischarcter ,_eof;
};
#endif // !_Token_hpp

