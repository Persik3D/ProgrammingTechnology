#pragma once
#include "Exception.h"
#include <string>

class IndexOutOfRangeException :
	public Exception
{
public:
	IndexOutOfRangeException(string _function, string _class, int _line, string _file) : Exception("Index out of range.", _function, _class, _line, _file) {};
	IndexOutOfRangeException(const char* _function, const char* _class, int _line, const char* _file) : Exception("Index out of range.", _function, _class, _line, _file) {};
	~IndexOutOfRangeException();
};

