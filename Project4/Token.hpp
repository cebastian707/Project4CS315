/*created by Cebastian Santiago 
* CS315 project 4
*/
#pragma once
#ifndef _Token_hpp
#define _Token_hpp
#include<string>

class Token{
public:
	/// <summary>
	/// Accepts a string as the token to parser by dephgraph
	/// </summary>
	/// <param name="in"></param>
	Token(std::string in);
	/// <summary>
	///Accepts a char to be parser by the dephgraph
	/// </summary>
	/// <param name="c"></param>
	Token(char c);
	/// <summary>
	/// returns true if token is a colon
	/// </summary>
	/// <returns></returns>
	bool charcter();
	/// <summary>
	/// returns true of input is some type of string
	/// </summary>
	/// <returns></returns>
	bool input();
	/// <summary>
	/// returns string token
	/// </summary>
	/// <returns></returns>
	std::string inputs();
	/// <summary>
	/// retursn char token
	/// </summary>
	/// <returns></returns>
	char charcters();
	/// <summary>
	/// end of file token
	/// </summary>
	void eof();
	/// <summary>
	/// returns eof == true ive we reached endoffile
	/// </summary>
	/// <returns></returns>
	bool endofile();

	/// <summary>
	/// prints the tokens
	/// </summary>
	void print();
private:
	/// @brief variables of the token class
	std::string _input;
	char _charcter;
	bool _isinput,_ischarcter ,_eof;
};
#endif // !_Token_hpp

