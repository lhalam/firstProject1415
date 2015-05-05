# pragma once
#include "Textile.h"

class Accessory: public Textile
{
public:
	Accessory();

	friend istream& operator>>(istream& stream, Accessory& obj);
	friend ostream& operator<<(ostream& stream, Accessory& obj);

	virtual void input();
	virtual void output();

	virtual  List<pair<string, string>> metadata();

	virtual void fill(string source);

	~Accessory(){}
};
