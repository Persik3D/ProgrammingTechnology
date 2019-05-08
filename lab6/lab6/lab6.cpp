#include <iostream>
#include <ctime>
#include <string>
#include "StackMinMax.h"
#include "IndexOutOfRangeException.h"
#include "Exception.h"
using namespace std;

#define error(X) (Exception(string(X), string(__func__), __LINE__, string(__FILE__)));

int main()
{
	StackMinMax myStack;
	cout << "Size: " << myStack.Size() << endl;
	cout << "Empty: " << myStack.Empty() << endl;
	try {
		cout << "Top: " << myStack.Top() << endl;
	}
	catch (IndexOutOfRangeException error) {
		cout << "ERROR: " << error.what() << endl;
	}
	catch (int errorId) {
		cout << "ERROR ID: " << errorId << endl;

	}
	catch (Exception error) {
		cout << "ERROR: " << error.what() << endl;
	}
	catch (...) {
		cout << "UNKNOWN ERROR" << endl;
	}

	getchar();
	return 0;
}