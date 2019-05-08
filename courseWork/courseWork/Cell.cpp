#include "Cell.h"
#include <cassert>
#include <typeinfo>

Cell::Cell()
{
}

Cell::Cell(string name)
{
	this->name = name;
}

Cell::Cell(char act, Cell * v1, Cell * v2)
{
	this->act = act;
	this->v1 = v1;
	this->v2 = v2;
}

Cell::Cell(char act, Cell & v1, Cell & v2)
{
	this->act = act;
	this->v1 = &v1;
	this->v2 = &v2;
}

Cell::Cell(int v0)
{
	this->act = '=';
	this->v0 = v0;
}

Cell::~Cell()
{
}

Cell Cell::operator+(Cell &v2)
{
	Cell ret = Cell();
	ret.v1 = this;
	ret.act = '+';
	ret.v2 = &v2;
	return ret;
}

Cell Cell::operator+(int v2)
{
	Cell ret = Cell();
	ret.v1 = this;
	ret.act = '+';
	ret.v2 = new Cell(v2);
	return ret;
}

Cell Cell::operator-(Cell &v2)
{
	Cell ret = Cell();
	ret.v1 = this;
	ret.act = '-';
	ret.v2 = &v2;
	return ret;
}

Cell Cell::operator-(int v2)
{
	Cell ret = Cell();
	ret.v1 = this;
	ret.act = '-';
	ret.v2 = new Cell(v2);
	return ret;
}

Cell Cell::operator*(Cell &v2)
{
	Cell ret = Cell();
	ret.v1 = this;
	ret.act = '*';
	ret.v2 = &v2;
	return ret;
}

Cell Cell::operator*(int v2)
{
	Cell ret = Cell();
	ret.v1 = this;
	ret.act = '*';
	ret.v2 = new Cell(v2);
	return ret;
}

Cell Cell::operator/(Cell &v2)
{
	Cell ret = Cell();
	ret.v1 = this;
	ret.act = '/';
	ret.v2 = &v2;
	return ret;
}

Cell Cell::operator/(int v2)
{
	Cell ret = Cell();
	ret.v1 = this;
	ret.act = '/';
	ret.v2 = new Cell(v2);
	return ret;
}

Cell Cell::operator=(const Cell &c)
{
	if (&c != this) {
		if (c.name == "") {
			act = c.act;
			v0 = c.v0;
			v1 = c.v1;
			v2 = c.v2;
		}
		else {
			act = '#';
			v1 = const_cast<Cell*>(&c);
		}
	}
	if (name == "" && name != c.name) {
		name = c.name;
	}
	return *this;
}

Cell Cell::operator=(int c)
{
	this->act = '=';
	this->v0 = c;
	this->v1 = NULL;
	this->v2 = NULL;
	return *this;
}

//Cell::operator bool()
//{
//	return v1 != NULL && v2 != NULL;
//}
//
//Cell::operator int()
//{
//	switch (act)
//	{
//	case '=':
//		return v0;
//	case '#':
//		return v1->toInt();
//	case '+':
//		return (int)v1 + (int)v2;
//	case '-':
//		return (int)v1 - (int)v2;
//	case '*':
//		return (int)v1 * (int)v2;
//	case '/':
//		return (int)v1 / (int)v2;
//	}
//}
//
//Cell::operator string()
//{
//	if (act == '=') return to_string(v0);
//	if (act == '#') return v1->toString();
//	return (v1->name == "" ? v1->toString() : v1->name)
//		+ act
//		+ (v2->name == "" ? v2->toString() : v2->name);
//}

ostream & operator<<(ostream & s, Cell & c)
{
	s << c.toInt();
	return s;
}


bool Cell::isEmpty()
{
	return act == '\0';
}

int Cell::toInt()
{
	switch (act)
	{
	case '\0':
		return 0;
	case '=':
		return v0;
	case '#':
		return v1->toInt();
	case '+':
		return v1->toInt() + v2->toInt();
	case '-':
		return v1->toInt() - v2->toInt();
	case '*':
		return v1->toInt() * v2->toInt();
	case '/':
		return v1->toInt() / v2->toInt();
	}
}

string Cell::toString()
{
	if (act == '\0') return "";
	if (act == '=') return to_string(v0);
	if (act == '#') return v1->name;
	return (v1->name == "" ? v1->toString() : v1->name)
		+ act
		+ (v2->name == "" ? v2->toString() : v2->name);
}

