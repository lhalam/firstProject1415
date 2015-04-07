#pragma once
#include "ChemicalProduct.h"

class Detergent : public ChemicalProduct
{
public:
	Detergent();

	friend istream& operator>>(istream& stream, Detergent& obj);
	friend ostream& operator<< (ostream& stream, const Detergent& obj);

	//intput\output methods for command prompt 
	//in order to create new\modify existing product
	void input();
	void output() const;

	~Detergent() { }
};

