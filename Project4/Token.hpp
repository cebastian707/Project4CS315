/*created by Cebastian Santiago 
* CS315 project 4
*/
#pragma once
#ifndef _Token_hpp
#define _Token_hpp
#include<string>

class Token{
public:
	Token();

private:
	/// @brief variables of the token class
	std::string _target, _prerequisties, _recipe;
	bool _istarget, _isprequisties, _isrecips;
};
#endif // !_Token_hpp

