#pragma once
#include <deque>
using namespace std;

class StackMinMax 
{
public:
	StackMinMax();
	~StackMinMax();
	int Min();
	int Max();
	void Push(int value);
	void Pop();
	bool Empty();
	int Size();
	int Top();

private:
	deque<int> c;
};

