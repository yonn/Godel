#include "repl_tools.hpp"
#include "engine.hpp"
#include "error.hpp"

#define ever (;;)

int main()
{

	auto engine = godel::Engine();
	std::string buffer;

	for ever {
		try {
			buffer = godel::read_line("<-- ");
			
			if (buffer == ":q") {
				break;
			}

			buffer = engine.eval(buffer);

			std::cout << "--> " << buffer << std::endl << std::endl;
			
		} catch (godel::ErrorException& e) {
		}
	}

	return 0;
}
