#pragma once
#include "ChemicalProduct.h"

class PersonalHygiene : public ChemicalProduct
{
public:
	PersonalHygiene();

	friend istream& operator>>(istream& stream, PersonalHygiene& obj);
	friend ostream& operator<< (ostream& stream, const PersonalHygiene& obj);

	//intput\output methods for command prompt 
	//in order to create new\modify existing product
	void input();
	void output() const;

	virtual  List<pair<string, string>> metadata();

	virtual void fill(string source);

	~PersonalHygiene(){}
};

