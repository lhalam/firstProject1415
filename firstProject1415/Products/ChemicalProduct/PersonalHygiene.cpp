#include "PersonalHygiene.h"

PersonalHygiene::PersonalHygiene() :
	ChemicalProduct()
	{
	}

istream& operator>>(istream& stream, PersonalHygiene& obj)
{
	stream >> ChemicalProduct(obj);
	return stream;
}
ostream& operator<<(ostream& stream, const PersonalHygiene& obj)
{
	stream << ChemicalProduct(obj);
	return stream;
}

void PersonalHygiene::input()
{
	ChemicalProduct::input();
}

void PersonalHygiene::output() const
{
	ChemicalProduct::output();
}