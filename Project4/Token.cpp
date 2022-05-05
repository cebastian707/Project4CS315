/*created by Cebastian Santiago
* CS315 project 4
*/
#include<string>
#include<iostream>
#include"Token.hpp"

Token::Token(){
	_input = "";
	_charcter = '\0';
	_ischarcter = false;
	_isinput = false;
	_eof = false;
}

Token::Token(std::string in){
	_input = in;
	_isinput = true;
	_charcter = '\0';
	_ischarcter = false;
	_eof = false;
}

Token::Token(char c){
	_charcter = c;
	_ischarcter = true;
	_input = "";
	_isinput = false;
	_eof = false;
}

bool Token::charcter(){
	return _ischarcter;
}

bool Token::input(){
	return _isinput;
}

std::string Token::inputs(){
	return _input;
}

char Token::charcters(){
	return _charcter;
}

void Token::eof(){
	_eof = true;
}

bool Token::endofile(){
	return _eof;
}

void Token::print(){
	if (input()){
		std::cout << inputs() << std::endl;
	}
	else if (charcter()){
		std::cout << charcters() << std::endl;
	}

	else if(endofile()){
		std::cout << "EOF" << std::endl;
	}

	else{
		std::cout << "Unknow Token" << std::endl;
	}

}

bool Token::iscolon(){
	if (_charcter == ':') {
		return true;
	}
	return false;
}

bool Token::istab(){
	if (_charcter == '\t') {
		return true;
	}
	return false;
}
