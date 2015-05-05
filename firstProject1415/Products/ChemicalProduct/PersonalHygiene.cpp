#include "PersonalHygiene.h"
#include "..\..\UI\Message.h"
#include "..\..\UI\Globals.h"

PersonalHygiene::PersonalHygiene():
	ChemicalProduct()
{
}

istream& operator>>(istream& stream, PersonalHygiene& obj)
{
	stream >> (ChemicalProduct&)obj;
	return stream;
}
ostream& operator<<(ostream& stream, const PersonalHygiene& obj)
{
	stream << (ChemicalProduct&)obj;
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

List<pair<string, string>> PersonalHygiene::metadata()
{
	List<pair<string, string>> result = ChemicalProduct::metadata();
	return result;
}

void PersonalHygiene::fill(string source)
{
	this->ChemicalProduct::fill(source);
}