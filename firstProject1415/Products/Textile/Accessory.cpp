#include "Accessory.h"
#include "..\..\UI\Message.h"
#include "..\..\UI\Globals.h"


Accessory::Accessory() :
	Textile()
{
}

istream& operator>>(istream& stream, Accessory& obj)
{
	stream >> (Textile&)obj;
	return stream;
}

ostream& operator<<(ostream& stream, Accessory& obj)
{
	stream << (Textile&)obj;
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

List<pair<string, string>> Accessory::metadata()
{
	List<pair<string, string>> result = Textile::metadata();
	return result;
}

void Accessory::fill(string source)
{
	this->Textile::fill(source);
}
