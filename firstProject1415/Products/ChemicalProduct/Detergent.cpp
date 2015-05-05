#include "Detergent.h"
#include "..\..\UI\Message.h"
#include "..\..\UI\Globals.h"


Detergent::Detergent():
	ChemicalProduct()
{
}

istream& operator>>(istream& stream, Detergent& obj)
{
	stream >> (ChemicalProduct&)obj;
	return stream;
}
ostream& operator<<(ostream& stream, const Detergent& obj)
{
	stream << (ChemicalProduct&)obj;
	return stream;
}

void Detergent::input()
{
	ChemicalProduct::input();
}

void Detergent::output() const
{
	ChemicalProduct::output();
}