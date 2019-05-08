#include "Product.h"

void Product::set_id(int id)
{
	this->id = id;
}

int Product::get_id() const
{
	return id;
}

void Product::set_height(unsigned int height)
{
	this->height = height;
}

void Product::set_width(unsigned int width)
{
	this->width = width;
}

int Product::get_height()
{
	return height;
}

int Product::get_width()
{
	return width;
}
