#ifndef GODEL_REPL_TOOLS_HPP
#define GODEL_REPL_TOOLS_HPP

#include <string>
#include <iostream>

#include <readline/readline.h>
#include <readline/history.h>

namespace godel {

	std::string read_line(const char* prompt);

}

#endif /*GODEL_REPL_TOOLS_HPP*/
