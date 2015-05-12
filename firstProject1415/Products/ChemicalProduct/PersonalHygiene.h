#pragma once
#include "ChemicalProduct.h"

class PersonalHygiene : public ChemicalProduct
{
public:
	DLL PersonalHygiene();

	friend DLL istream& operator>>(istream& stream, PersonalHygiene& obj);
	friend DLL ostream& operator<< (ostream& stream, const PersonalHygiene& obj);

	//intput\output methods for command prompt 
	//in order to create new\modify existing product
	void DLL input();
	void DLL output() const;

	virtual DLL List<pair<string, string>> metadata();

	virtual DLL void fill(string source);

	DLL ~PersonalHygiene(){}
};

