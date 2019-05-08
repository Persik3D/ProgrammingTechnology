#pragma once
#include "Product.h"
class Product1x1 : public Product
{
public:
	Product1x1();
	~Product1x1();
protected:
	void init() override;
};

