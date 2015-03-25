#pragma once
#include "ChemicalProduct.h"

class Cosmetic : public ChemicalProduct
{
private:
	char organ; // for face - 'f'; for hands - 'h'; for body - 'b'.
public:
	Cosmetic();

	friend istream& operator>>(istream& stream, Cosmetic& obj);
	friend ostream& operator<<(ostream& stream, const Cosmetic& obj);

	~Cosmetic() {}
};

