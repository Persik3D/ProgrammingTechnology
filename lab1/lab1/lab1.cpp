#include <iostream>
#include "Matrix.h" 
using namespace std;

int main()
{
	Matrix M(5, 5);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			M(i, j) = i + j;
	}

	M.Display();

	cout << endl << "After multiply by 5:" << endl;
	M.Multiply(5);
	M.Display();

	cout << endl << "After addition by 5:" << endl;
	M.Add(5);
	M.Display();

	cout << endl << "After subtraction by 8:" << endl;
	M.Sub(8);
	M.Display();

	getchar();
	return 0;
}