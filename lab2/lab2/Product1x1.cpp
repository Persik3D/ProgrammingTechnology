#include "Product1x1.h"
#include <iostream>


Product1x1::Product1x1()
{
	init();
}


Product1x1::~Product1x1()
{
}

void Product1x1::init() {
	set_height(1);
	set_width(1);
}