# pragma once
# include "Textile.h"

class Footwear : public Textile
{
protected:
	unsigned size;
	char season; // summer - 's'; winter - 'w'; autumn&spring - 'a'.
public:
	Footwear();

	friend istream& operator>>(istream& stream, Footwear& obj);
	friend ostream& operator<<(ostream& stream, Footwear& obj);

	unsigned getSize() const { return this->size; }

	void setSize(unsigned size) { this->size = size; }

	char getSeason() const { return this->season; }

	void setSeason(char season) { this->season = season; }

	virtual void input();
	virtual void output();

	virtual  List<pair<string, string>> metadata()
	{
		List<pair<string, string>> result = Product::metadata();
		result.pushBack(make_pair("size", to_string(size)));
		result.pushBack(make_pair("season", to_string(season)));
		return result;
	}

	~Footwear(){}
};
