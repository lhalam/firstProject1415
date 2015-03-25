#pragma once
#include "ChemicalProduct.h"

class PersonalHygiene : public ChemicalProduct
{
public:
	PersonalHygiene();

	friend istream& operator>>(istream& stream, PersonalHygiene& obj);
	friend ostream& operator<< (ostream& stream, const PersonalHygiene& obj);

	~PersonalHygiene(){}
};

