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

	~Footwear(){}
};