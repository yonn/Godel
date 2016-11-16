#ifndef GODEL_LEXER_HPP
#define GODEL_LEXER_HPP

#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>

namespace godel {

	/**
	 * Token: struct to represent a token
	 */
	struct Token {

		std::string token;

		/**
		 * enum representing the different kinds of tokens
		 */
		enum {
			NumLiteral,
			Identifier,
			Symbol
		} kind;

		/**
		 * str returns a std::string representing the token 
		 */
		std::string str() const;
		
	};

	/**
	 * tokenize accepts a std::string containing the current line,
	 * and constructs a std::vector of the Tokens in the line 
	 */
	std::vector<Token> tokenize(const std::string& line); 

}

#endif /*GODEL_LEXER_HPP*/
