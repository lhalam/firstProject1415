# pragma once
#include "Textile.h"

class Clothing : public Textile
{
private:
	char size;
	char season; // summer - 's'; winter - 'w'; autumn&spring - 'a'.
public:
	Clothing();

	friend istream& operator>>(istream& stream, Clothing& obj);
	friend ostream& operator<<(ostream& stream, Clothing& obj);

	char getSize() const { return this->size; }

	void setSize(char size) { this->size = size; }

	char getSeason() const { return this->season; }

	void setSeason(char season) { this->season = season; }

	virtual void input();
	virtual void output();

	virtual  List<pair<string, string>> metadata()
	{
		List<pair<string, string>> result = Textile::metadata();
		result.pushBack(make_pair("size", to_string(size)));
		result.pushBack(make_pair("season", to_string(season)));
		return result;
	}

	~Clothing(){}
};
