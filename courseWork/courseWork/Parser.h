#pragma once
#include "Cell.h"
#include <vector>
using namespace std;

class Parser {
public:
	explicit Parser(vector<vector<Cell>> *table) : table(table){}
	Cell& parse(const string input);
	static void parseA1(string str, int& I, int& J);

private:
	string parse_token();
	Cell* find(string addr);
	Cell* parse_simple_expression();
	Cell* parse_binary_expression(int min_priority);

	string input;
	int n = 0;
	vector<vector<Cell>>* table;
};

