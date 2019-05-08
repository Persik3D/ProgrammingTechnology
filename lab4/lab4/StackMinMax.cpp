#include "StackMinMax.h"

StackMinMax::StackMinMax() 
{
}

StackMinMax::~StackMinMax() 
{
}

int StackMinMax::Min()
{
	if (Empty()) throw 1;
	int min = c[0];
	for (int i = 1; i < c.size(); ++i)
		if (min > c[i]) min = c[i];
	return min;
}

int StackMinMax::Max()
{
	if (Empty()) throw 1;
	int max = c[0];
	for (int i = 1; i < c.size(); ++i)
		if (max < c[i]) max = c[i];
	return max;
}

void StackMinMax::Push(int value)
{
	c.push_back(value);
}

void StackMinMax::Pop()
{
	if (Empty()) throw 1;
	return c.pop_back();
}

bool StackMinMax::Empty()
{
	return c.empty();
}

int StackMinMax::Size()
{
	return c.size();
}

int StackMinMax::Top()
{
	if (Empty()) throw 1;
	return c.back();
}


