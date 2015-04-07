# pragma once
#include "Electronic.h"

class LaptopAndComputer : public Electronic
{
private:
	string firm;
public:
	LaptopAndComputer();

	friend istream& operator>>(istream& stream, LaptopAndComputer& obj)  { }
	friend ostream& operator<<(ostream& stream, const LaptopAndComputer& obj) { }

	virtual void input();
	virtual void output() const;

	~LaptopAndComputer(){}
};
