#include "Stock.h"
#include <iostream>
using namespace std;
Stock::~Stock()
{
	for (int i = 0; i < height; i++)
		delete[] stock[i];
	delete[] stock;
}

bool Stock::Add(Product &p) {
	for (int i = 0; i < height; i++) 
	{
		for (int j = 0; j < width; j++) 
		{
			if (checkAdd(p, i, j)) 
			{
				count++;
				for (int n = 0; n < p.get_height(); n++) //place product in stock
				{
					for (int m = 0; m < p.get_width(); m++)
					{
						p.set_id(count);
						stock[i + n][j + m] = p;
					}
				}
				return true;
			}
		}
	}
	return false;
}

bool Stock::checkAdd(Product p, int x, int y) {
	for (int i = 0; i < p.get_height(); i++) 
	{
		for (int j = 0; j < p.get_width(); j++)
		{
			if (stock[i + x][j + y].get_id() != -1) 
			{
				return false;
			}
		}
	}
	return true;
}



bool Stock::Remove(Product p) {
	if (p.get_id() == -1) return false;

	bool removed = false;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (stock[i][j].get_id() == p.get_id()) {
				stock[i][j] = Product();
				removed = true;
			}
		}
	}
	return removed;
}

bool Stock::IsExists(Product p) {
	if (p.get_id() == -1) return false;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (stock[i][j].get_id() == p.get_id()) {
				return true;
			}
		}
	}
	return false;
}

Point Stock::Find(Product p) {
	if (p.get_id() == -1) return Point{ -1, -1 };

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (stock[i][j].get_id() == p.get_id()) {
				return Point{ i, j };
			}
		}
	}
	return Point{ -1, -1 };
}

void Stock::Display() const
{
	for (unsigned int i = 0; i < height; i++)
	{
		for (unsigned int j = 0; j < width; j++)
		{
			cout.width(4);
			cout << stock[i][j].get_id();
		}
		cout << endl;
	}
}