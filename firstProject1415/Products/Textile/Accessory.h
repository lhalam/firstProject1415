# pragma once
#include "Textile.h"

class Accessory: public Textile
{
public:
	Accessory();

	friend istream& operator>>(istream& stream, Accessory& obj);
	friend ostream& operator<<(ostream& stream, Accessory& obj);
	~Accessory(){}
};