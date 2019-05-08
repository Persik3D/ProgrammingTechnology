#pragma once
#include "Product.h"
class Product2x2 : public Product
{
public:
	Product2x2();
	~Product2x2();
protected:
	void init() override;
};

