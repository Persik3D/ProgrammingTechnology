#include <iostream>
#include <string>
#include <variant> 
#include <cassert>
#include <algorithm>
#include <iomanip>
#include "Cell.h"
#include "Parser.h"
using namespace std;

vector<vector<Cell>> Table;
Parser pars = Parser(&Table);
int errors = 0;

string intToABC(int i, string cash = "") {
	int rem = i % 26;
	int whole = (i - rem) / 26;
	cash.push_back(rem + 64);
	return whole > 0 ? intToABC(whole, cash) : cash;
}

string IntToABC(int i) {
	string s = intToABC(++i);
	reverse(s.begin(), s.end());
	return s;
}

inline bool equally(char c) {
	return c == '=';
}

inline bool notEqually(char c) {
	return c != '=';
}

vector<string> split(const string& s) {
	typedef string::const_iterator iter;
	vector<string> ret;
	iter i = s.begin();
	while (i != s.end()) {
		i = find_if(i, s.end(), notEqually); 
		iter j = find_if(i, s.end(), equally); 
		if (i != s.end()) {
			ret.push_back(string(i, j)); 
			i = j; 
		}
	}
	return ret;
}

void printValue() {
	cout << left << setw(10) << setfill(' ') << "#";
	for (int i = 0; i < Table.size(); i++) {
		cout << left << setw(10) << setfill(' ') << IntToABC(i);
	}
	cout << endl;

	for (int i = 0; i < Table.size(); i++) {
		cout << left << setw(10) << setfill(' ') << i + 1;
		for (int j = 0; j < Table[i].size(); j++) {
			cout << left << setw(10) << setfill(' ') << Table[i][j];
		}
		cout << endl;
	}
}

void printFormule() {
	cout << left << setw(10) << setfill(' ') << "#";
	for (int i = 0; i < Table.size(); i++) {
		cout << left << setw(10) << setfill(' ') << IntToABC(i);
	}
	cout << endl;

	for (int i = 0; i < Table.size(); i++) {
		cout << left << setw(10) << setfill(' ') << i + 1;
		for (int j = 0; j < Table[i].size(); j++) {
			cout << left << setw(10) << setfill(' ') << Table[i][j].toString();
		}
		cout << endl;
	}
}

bool _test(string address, string command, int trueResult) {
	int i, j;
	Parser::parseA1(address, i, j);
	Table[i][j] = pars.parse(command);
	return Table[i][j].toInt() == trueResult;
}

void test(string address, string command, int trueResult) {
	if (!_test(address, command, trueResult)) {
		cout << address << command << " not = " << trueResult << endl;
		errors++;
	}
}

int main()
{
	for (int i = 0; i < 10; i++) {
		Table.push_back(vector<Cell>());	
		for (int j = 0; j < 10; j++) {
			Table[i].push_back(Cell(IntToABC(i) + to_string(j + 1)));
		}
	}

	printValue();
	printFormule();

	test("A1", "=15+30", 45);
	test("A1", "=5*10", 50);
	test("A1", "=5*10+30", 80);
	test("A1", "=15+5*10", 65);
	test("A1", "=15+10/2", 20);
	test("A1", "=A1", 20);
	test("A1", "=5", 5);
	test("A1", "=-5", -5);
	test("B1", "=A1", -5);
	test("B1", "=A1 + 15", 10);
	test("B1", "=A1-15*A1", 70);
	test("B1", "=A1-15*A1", 70);
	test("B2", "=A1-B1", -75);
	test("A2", "=A1+15", 10);
	test("C2", "=A1*A2-B2*B1", 5200);

	test("A1", "=10", 10);//проверка связей
	test("A2", "=A2", 25);
	test("B1", "=B1", -140);
	test("B2", "=B2", 150);
	test("C2", "=C2", 21250);

	cout << "Errors: " << errors << endl;

	string command = "";
	int i, j;
	for (;;) {
		command = "";
		i = 0; j = 0;

		cin >> command;
		if (command == "print") printValue();
		if (command == "printf") printFormule();
		auto s = split(command);

		if (s.size() != 2) {
			cout << "Wrong format, example: A1=B1+15" << endl;
			continue;
		}

		Parser::parseA1(s[0], i, j);
		Table[i][j] = pars.parse("=" + s[1]);
	}

	getchar();
	return 0;
}