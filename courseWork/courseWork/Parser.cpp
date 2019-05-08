#include "Parser.h"
#include <math.h>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <cstring>
#include <stdexcept>

using namespace std;

string Parser::parse_token() {
	while (isspace(input[n])) ++n;

	if (isdigit(input[n])) {
		string number;
		while (isdigit(input[n]) || input[n] == '.') number.push_back(input[n++]);
		return number;
	}
	
	if (isalpha(input[n])) {
		string addr;
		while (isalpha(input[n]) || isdigit(input[n])) addr.push_back(input[n++]);
		return addr;
	}

	char tokens[] = { '+', '-', '*', '/' };
	for (auto& t : tokens) {
		if (input[n] == t) {
			n++;
			return string(1, t);
		}
	}
	return "";
}

void Parser::parseA1(string addr, int& I, int& J)
{
	string num, str;
	for (string::size_type i = 0; i < addr.size(); ++i) {
		if (isdigit(addr[i]))
			num.push_back(addr[i]);

		if (isalpha(addr[i]))
			str.push_back(addr[i]);
	}

	int result = 0;
	for (int i = str.size() - 1; i >= 0; i--) {

		result += (str[i] - 64) * pow(26, str.size() - i - 1);
	}

	I = result - 1;
	J = stoi(num) - 1;
}

Cell* Parser::find(string addr)
{
	int i, j;
	parseA1(addr, i, j);
	return &(*table)[i][j];
}

Cell* Parser::parse_simple_expression() {
	auto token = parse_token();
	if (token.empty()) throw runtime_error("Invalid input");

	if (isdigit(token[0]))
		return new Cell(stoi(token));

	if (isalpha(token[0]))
		return find(token);

	n--;
	return new Cell(0);
}

int get_priority(const string& binary_op) {
	if (binary_op == "+") return 1;
	if (binary_op == "-") return 1;
	if (binary_op == "*") return 2;
	if (binary_op == "/") return 2;
	return 0;
}

Cell* Parser::parse_binary_expression(int min_priority) {
	auto left = parse_simple_expression();

	for (;;) {
		auto op = parse_token();
		auto priority = get_priority(op);
		if (priority <= min_priority) {
			n -= op.size();
			return left;
		}

		auto right = parse_binary_expression(priority);
		left = new Cell(op[0], left, right);
	}
}

Cell& Parser::parse(const string in) {
	input = in;
	n = 0;
	if (input[n] != '=') throw runtime_error("Invalid input");
	++n;
	return *parse_binary_expression(0);
}