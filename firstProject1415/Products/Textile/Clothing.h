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

	~Clothing(){}
};