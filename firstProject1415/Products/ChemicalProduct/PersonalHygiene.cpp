#include "PersonalHygiene.h"

PersonalHygiene::PersonalHygiene() :
	ChemicalProduct(){}

istream& operator>>(istream& stream, PersonalHygiene& obj)
{
	getline(stream, obj.name);
	getline(stream, obj.manufacturer);
	stream >> obj.price >> obj.id;
	getline(stream, obj.manufacture_date);
	stream >> obj.volume;
	return stream;
}
ostream& operator<<(ostream& stream, const PersonalHygiene& obj)
{
	stream << obj.name << endl
		<< obj.manufacturer << endl
		<< obj.price << endl
		<< obj.id << endl
		<< obj.manufacture_date << endl
		<< obj.volume << endl;
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