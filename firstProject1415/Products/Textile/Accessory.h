# pragma once
#include "Textile.h"

class Accessory: public Textile
{
public:
	DLL Accessory();

	friend DLL istream& operator>>(istream& stream, Accessory& obj);
	friend DLL ostream& operator<<(ostream& stream, Accessory& obj);

	virtual DLL void input();
	virtual DLL void output();

	virtual DLL List<pair<string, string>> metadata();

	virtual DLL void fill(string source);

	~Accessory() { }
};
