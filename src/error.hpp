#ifndef GODEL_ERROR_HPP
#define GODEL_ERROR_HPP

#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <exception>

namespace godel {

	/**
	 * standard exception thrown by error.
	 * Only REPL is allowed to catch.
	 */
	class ErrorException: public std::exception {
	public:

		virtual const char* what() const throw()
		{
			return "";
		}
		
	};

	/**
	 * error prints it's arguments to standard error, than throws
	 * an exception to be caught by the REPL.
	 * Once error is called the current execution path finishes and the REPL
	 * returns to it's resting state.
	 *
	 * Call error like calling all 'printf' style functions
	 */
	void error(const char* fmt, ...);
	
}

#endif /*GODEL_ERROR_HPP*/
