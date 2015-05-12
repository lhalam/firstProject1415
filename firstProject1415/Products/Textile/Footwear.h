# pragma once
# include "Textile.h"

class Footwear : public Textile
{
protected:
	unsigned size;
	char season; // summer - 's'; winter - 'w'; autumn & spring - 'a'.
public:
	DLL Footwear();

	friend DLL istream& operator>>(istream& stream, Footwear& obj);
	friend DLL ostream& operator<<(ostream& stream, Footwear& obj);

	unsigned getSize() const { return this->size; }

	void setSize(unsigned size) { this->size = size; }

	char getSeason() const { return this->season; }

	void setSeason(char season) { this->season = season; }

	virtual DLL void input();
	virtual DLL void output();

	virtual DLL List<pair<string, string>> metadata();

	virtual DLL void fill(string source);

	~Footwear() { }
};
