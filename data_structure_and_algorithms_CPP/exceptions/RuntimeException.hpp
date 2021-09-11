//Page 121:
//I just followed author's implementation of the concrete base exception class.

#ifndef RUNTIMEEXCEPTION_HPP
#define RUNTIMEEXCEPTION_HPP
#include<iostream>
using std::string;

class RuntimeException {
private:
	string errorMsg;
public:
	RuntimeException(const string& err):errorMsg(err) {}
	string getMessage() const {return errorMsg;}

};
#endif
