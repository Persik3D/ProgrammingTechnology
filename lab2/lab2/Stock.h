#include "Product.h"
#include "Point.h"
#pragma once
class Stock
{
private:
	int height, width;
	int count = 0;
	Product **stock;

	bool checkAdd(Product p, int x, int y);
	void create()
	{
		stock = new Product*[height];
		for (int i = 0; i < height; i++)
			stock[i] = new Product[width];
	}
public:
	Stock() : height(100), width(100) { create(); }
	Stock(int x, int y) : height(x), width(y) { create(); }
	~Stock();

	bool Add(Product &p);
	bool Remove(Product p);
	bool IsExists(Product p);
	Point Find(Product p);
	void Display() const;
};