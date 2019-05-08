#pragma once
#include <iostream>

class Product
{
public:
	Product() = default;
	void set_id(int id);
	int get_id() const;
	int get_height();
	int get_width();
	virtual ~Product() { };

protected:
	virtual void init() { };
	void set_height(unsigned int height);
	void set_width(unsigned int width);

private:
	int height, width;
	int id = -1;
};