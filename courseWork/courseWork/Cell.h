#pragma once
#include <string>
#include <vector>
#include <variant>

using namespace std;


class Cell
{
public:
	Cell();
	Cell(string name);
	Cell(char act, Cell *v1, Cell *v2);
	Cell(char act, Cell &v1, Cell &v2);
	Cell(int v0);
	~Cell();

	Cell operator + (Cell &v2);
	Cell operator + (int v2);

	Cell operator - (Cell &v2);
	Cell operator - (int v2);

	Cell operator * (Cell &v2);
	Cell operator * (int v2);

	Cell operator / (Cell &v2);
	Cell operator / (int v2);

	Cell operator = (const Cell &c);
	Cell operator = (int c);

	/*operator bool();
	operator int();
	operator string();*/

	friend ostream& operator << (ostream &s, Cell &c);

	bool isEmpty();
	int toInt();
	string toString();

private:
	string name;
	char act = '\0';
	int v0 = 0;
	Cell *v1 = nullptr;
	Cell *v2 = nullptr;
};