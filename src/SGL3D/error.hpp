#include <iostream>


namespace sgl { namespace error {


void throwError(std::string text) {
	throw std::runtime_error(text);
}


}}