#ifndef GODEL_ENGINE_HPP
#define GODEL_ENGINE_HPP

#include <string>

#include "ast.hpp"
#include "lexer.hpp"
#include "error.hpp"

namespace godel {

	/**
	 * Objects of type `Engine` act as self contained interpreters for Godel code
	 * The engine is responsible for parsing, running, and cleaning up a program
	 */
	class Engine {
	public:
		/**
		 * Construct a Parser
		 */
		Engine();

		std::string eval(const std::string& line);

		/**
		 * Force a full garbage collection run
		 */
		void gc();
	};

}

#endif /*GODEL_ENGINE_HPP*/
