#pragma once
class Matrix
{
public:
	explicit Matrix() : m(5), n(5) { create(); }
	explicit Matrix(unsigned int i) : m(i), n(i) { create(); }
	explicit Matrix(unsigned int i, unsigned int j) : m(i), n(j) { create(); }
	virtual ~Matrix();

	int& Element(unsigned int i, unsigned int j) const;
	int& operator() (unsigned int i, unsigned int j) const;
	void Multiply(int x);
	void Add(int x);
	void Sub(int x);
	void Display() const;

private:
	int **matr;
	unsigned int m;
	unsigned int n;

	void create();
	bool validate(unsigned int x, unsigned int y) const;
};