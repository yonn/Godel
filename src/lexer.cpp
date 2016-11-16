#include "lexer.hpp"

namespace godel {

	std::string Token::str() const
	{
		const char* Token_str[] = { "Numeric Literal",
					    "Identifier",
					    "Symbol" };
		std::ostringstream s;
		s << "Token [ " << Token_str[(int)this->kind] << ": " << this->token << " ]";
		return s.str();
	}

	static bool is_token(const std::string& s);
	static bool is_number_token(const std::string& s);
	static bool is_symbol_token(const std::string& s);
	static bool is_identifier_token(const std::string& s);

	static bool is_whitespace(const char c);
	static bool is_number(const char c);
	static bool is_letter(const char c);

	static Token make_token(const std::string& s);

	std::vector<Token> tokenize(const std::string& line)
	{
		std::vector<Token> tokens;

		std::string curr;
		
		auto end = std::find(std::cbegin(line), std::cend(line), '#');
		for (auto it = std::cbegin(line); it != end; ++it) {
			if (not is_token(curr + *it)) {
				if (curr != "") {
					tokens.push_back(make_token(curr));
				}
				curr = "";
				if (not is_whitespace(*it)) {
					curr += *it;
				}
			} else {
				curr += *it;
			}
		}

		if (curr != "") {
			tokens.push_back(make_token(curr));
		}

		return tokens;
	}

	static bool is_token(const std::string& s)
	{
		if (is_whitespace(*(std::cend(s) - 1))) {
			return false;
		} else if (is_number_token(s)) {
			return true;
		} else if (is_symbol_token(s)) {
			return true;
		} else {
			return is_identifier_token(s);
		}
	}


	static bool is_number_token(const std::string& s)
	{
		bool period = false;

		for (const char c: s) {
			if (c == '.' and not period) {
				period = true;
				continue;	
			} else if (not is_number(c) and not (c == '_')) {
				return false;
			}
		}
		return true;
	}
		
	static bool is_symbol_token(const std::string& s)
	{
		std::set<std::string> symbols = { "(", ")",
		                                  "+", "-",
						  "*", "/" };
		return (symbols.count(s) == 1);
	}
	
	static bool is_identifier_token(const std::string& s)
	{
		const auto first = std::cbegin(s);
		if (not is_letter(*first) and not (*first == '_')) return false;
		for (const char c: s) {
			if (not is_letter(c) and not is_number(c) and not (c == '_')) {
				return false;
			}
		}
		return true;
	}

	static bool is_whitespace(const char c)
	{
		return (c == ' '  or
		        c == '\t' or
			c == '\n');
	}

	static bool is_number(const char c)
	{
		return (c >= '0' and c <= '9');
	}

	static bool is_letter(const char c)
	{
		return ((c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z'));
	}

	static Token make_token(const std::string& s)
	{
		auto t = Token();
		t.token = s;
		
		if (is_identifier_token(s)) {
			t.kind = Token::Identifier;
		} else if (is_number_token(s)) {
			t.kind = Token::NumLiteral;
		} else if (is_symbol_token(s)) {
			t.kind = Token::Symbol;
		} else {
			error("Unknown token `%s'`", s.c_str());
		}

		return t;
	}
}
