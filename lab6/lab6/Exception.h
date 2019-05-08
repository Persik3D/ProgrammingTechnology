#pragma once
#include <exception>
#include <string>
using namespace std;

class Exception {
public:
	Exception(string msg, string _function, string _class, int _line, string _file);
	Exception(const char* msg, const char* _function, const char* _class, int _line, const char* _file);

	virtual ~Exception();

	virtual string what();

protected:
	string error_message;
	string error_function;
	string error_class;
	int error_line;
	string error_file;
};