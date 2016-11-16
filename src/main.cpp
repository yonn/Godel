#include "repl_tools.hpp"
#include "lexer.hpp"

#define ever (;;)

int main()
{

	for ever {
		std::string buffer = godel::read_line("<-- ");

		if (buffer == ":q") {
			break;
		}

		auto tokens = godel::tokenize(buffer);

		std::cout << "{";

		for (const auto& token: tokens) {
			std::cout << '\t' << token.str() << std::endl;
		}

		std::cout << "}" << std::endl << std::endl;

		//std::cout << "-> " << buffer << std::endl << std::endl;
	}

	return 0;
}
