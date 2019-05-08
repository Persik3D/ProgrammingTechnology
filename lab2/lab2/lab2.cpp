#include <iostream>
#include "Point.h"
#include "Product.h"
#include "Product1x1.h"
#include "Product1x2.h"
#include "Product2x2.h"
#include "Stock.h"
using namespace std;

int main()
{	
	Stock stock(5, 5);

	Product p1 = Product1x2();
	stock.Add(p1);
	Product p2 = Product2x2();
	stock.Add(p2);
	Product p3 = Product1x2();
	stock.Add(p3);
	Product p4 = Product1x2();
	stock.Add(p4);
	Product p5 = Product1x2();
	stock.Add(p5);
	Product p6 = Product2x2();
	stock.Add(p6);
	Product p7 = Product1x2();
	stock.Add(p7);
	stock.Display();

	stock.Remove(p2);
	cout << endl << "Removed p2:" << endl;
	stock.Display();

	cout << endl << "Removed p6: x=" << stock.Find(p6).x << " y=" << stock.Find(p6).y;

	getchar();
	return 0;
}