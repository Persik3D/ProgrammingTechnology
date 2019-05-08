#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix::~Matrix()
{
	for (unsigned int z = 0; z < m; z++)
		delete[] matr[z];
	delete[] matr;
}

void Matrix::create()
{
	matr = new int*[m];
	for (int z = 0; z < m; z++)
		matr[z] = new int[n];
}

bool Matrix::validate(unsigned int x, unsigned int y) const {
	return x < m && y < n;
}

int& Matrix::Element(unsigned int i, unsigned int j) const
{
	if (validate(i, j))
		return matr[i][j];
	else
		cout << "Error: 1";
}

int& Matrix::operator() (unsigned int i, unsigned int j) const
{
	if (validate(i, j))
		return matr[i][j];
	else
		cout << "Error: 1";
}

void Matrix::Multiply(int x)
{
	for (unsigned int i = 0; i < m; i++)
		for (unsigned int j = 0; j < n; j++)
			matr[i][j] *= x;
}

void Matrix::Add(int x)
{
	for (unsigned int i = 0; i < m; i++)
		for (unsigned int j = 0; j < n; j++)
			matr[i][j] += x;
}

void Matrix::Sub(int x)
{
	for (unsigned int i = 0; i < m; i++)
		for (unsigned int j = 0; j < n; j++)
			matr[i][j] -= x;
}

void Matrix::Display() const
{
	for (unsigned int i = 0; i < m; i++)
	{
		for (unsigned int j = 0; j < n; j++)
		{
			cout.width(4);
			cout << matr[i][j];
		}
		cout << endl;
	}
}