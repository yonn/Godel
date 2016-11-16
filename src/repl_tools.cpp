#include "repl_tools.hpp"

namespace godel {

	std::string read_line(const char* prompt)
	{
		auto s = readline(prompt);

		std::string buffer(s);

		if (buffer != "") {
			add_history(s);
		}

		rl_free(s);
		
		return buffer;
	}

}
