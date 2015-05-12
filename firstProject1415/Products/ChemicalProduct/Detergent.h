#pragma once
#include "ChemicalProduct.h"

class Detergent : public ChemicalProduct
{
public:
	DLL Detergent();

	friend DLL istream& operator>>(istream& stream, Detergent& obj);
	friend DLL ostream& operator<< (ostream& stream, const Detergent& obj);

	//intput\output methods for command prompt 
	//in order to create new\modify existing product
	void DLL input();
	void DLL output() const;

	virtual DLL List<pair<string, string>> metadata();

	virtual DLL void fill(string source);

	DLL ~Detergent() { }
};

