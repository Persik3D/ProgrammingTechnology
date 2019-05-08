#include <iostream>
#include "StackMinMax.h"
#include <stack>
#include <string>
using namespace std;

int main()
{
	StackMinMax myStack;

	cout << "Size: " << myStack.Size() << endl;
	cout << "Empty: " << myStack.Empty() << endl;
	try {
		cout << "Top: " << myStack.Top() << endl;
	}
	catch (int error) {
		cout << "ERROR: " << error << endl; 
	}

	try {
		cout << "Min: " << myStack.Min() << endl;
	}
	catch (int error) { 
		cout << "ERROR: " << error << endl; 
	}

	try {
		cout << "Max: " << myStack.Max() << endl;
	}
	catch (int error) { 
		cout << "ERROR: " << error << endl; 
	}

	myStack.Push(15);
	myStack.Push(5);
	myStack.Push(234);
	myStack.Push(52);
	myStack.Push(-1234);
	myStack.Push(123423);
	myStack.Push(0);

	cout << "After added elements to stack:" << endl;
	cout << "Size: " << myStack.Size() << endl;
	cout << "Empty: " << myStack.Empty() << endl;
	cout << "Top: " << myStack.Top() << endl;
	cout << "Min: " << myStack.Min() << endl;
	cout << "Max: " << myStack.Max() << endl;

	myStack.Pop();
	cout << "Pop!" << endl;
	cout << "Size: " << myStack.Size() << endl;
	cout << "Top: " << myStack.Top() << endl;



	getchar();
	return 0;
}