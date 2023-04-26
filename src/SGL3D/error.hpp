#ifndef ERROR_CALL
#define ERROR_CALL

#include <stdexcept>

namespace sgl { namespace error {



void throwError(std::string text) {
	throw std::runtime_error(text);
}


}}
#endif