#include "Exception.h"

Exception::Exception(
	string msg, 
	string _function, 
	string _class,
	int _line,
	string _file)
{
	error_message = msg;
	error_function = _function;
	error_class = _class;
	error_line = _line;
	error_file = _file;
}

Exception::Exception(
	const char * msg, 
	const char * _function, 
	const char * _class,
	int _line,
	const char * _file)
{
	error_message = msg;
	error_function = _function;
	error_class = _class;
	error_line = _line;
	error_file = _file;
}

Exception::~Exception()
{
}

string Exception::what()
{
	return (error_message + " in " 
		+ error_function + " in "
		+ to_string(error_line) + " line in "
		+ error_class + " in "
		+ error_file).c_str();
}