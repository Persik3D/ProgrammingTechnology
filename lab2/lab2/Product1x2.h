#pragma once
#include "Product.h"
class Product1x2 : public Product
{
public:
	Product1x2();
	~Product1x2();
protected:
	void init() override;
};

