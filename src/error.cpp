#include "error.hpp"

namespace godel {

	void error(const char* fmt, ...)
	{
		std::va_list args;
		va_start(args, fmt);

		std::fprintf(stderr, "Fatal Error: \n");
		std::vfprintf(stderr, fmt, args);
		std::fprintf(stderr, "\n\n");

		va_end(args);

		throw ErrorException();
	}
	
}
