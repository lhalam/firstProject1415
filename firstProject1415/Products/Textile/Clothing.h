# pragma once
#include "Textile.h"

class Clothing : public Textile
{
private:
	char size;
	char season; // summer - 's'; winter - 'w'; autumn & spring - 'a'.
public:
	DLL Clothing();

	friend DLL istream& operator>>(istream& stream, Clothing& obj);
	friend DLL ostream& operator<<(ostream& stream, Clothing& obj);

	char getSize() const { return this->size; }

	void setSize(char size) { this->size = size; }

	char getSeason() const { return this->season; }

	void setSeason(char season) { this->season = season; }

	virtual DLL void input();
	virtual DLL void output();

	virtual DLL List<pair<string, string>> metadata();

	virtual DLL void fill(string source);

	~Clothing() { }
};
