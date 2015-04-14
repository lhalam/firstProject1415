#include "Accessory.h"

Accessory::Accessory() :
	Textile()
{
}

// overloading operators istream and ostream 
istream& operator>>(istream& stream, Accessory& obj)
{
	stream >> Textile(obj);
	return stream;
}

ostream& operator<<(ostream& stream, Accessory& obj)
{
	stream << Textile(obj);
	return stream;
}

void Accessory::input()
{
	Textile::input();
}

void Accessory::output()
{
	Textile::output();
}
