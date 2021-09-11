#ifndef INDEXOUTOFBOUNDS_HPP
#define INDEXOUTOFBOUNDS_HPP
#include "RuntimeException.hpp"
class IndexOutOfBounds: public RuntimeException {
	public:
	IndexOutOfBounds(const string&err):RuntimeException(err)
	{}
	
};



#endif
