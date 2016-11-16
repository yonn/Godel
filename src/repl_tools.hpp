#ifndef GODEL_REPL_TOOLS_HPP
#define GODEL_REPL_TOOLS_HPP

#include <string>
#include <iostream>

#include <readline/readline.h>
#include <readline/history.h>

namespace godel {

	/**
	 * read_line returns a std::string, with the line that 
	 * was read, without the new-line character ('\n')
	 *
	 * prompt: string literal of the prompt to be printed out 
	 */
	std::string read_line(const char* prompt);

}

#endif /*GODEL_REPL_TOOLS_HPP*/
