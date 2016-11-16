#include "repl_tools.hpp"

#define ever (;;)

int main()
{

	for ever {
		std::string buffer = godel::read_line("<-- ");

		if (buffer == ":q") {
			break;
		}

		std::cout << "-> " << buffer << std::endl << std::endl;
	}

	return 0;
}
