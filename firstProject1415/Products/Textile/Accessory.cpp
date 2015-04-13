#include "Accessory.h"

Accessory::Accessory() :
	Textile()
{
}

// overloading operators istream and ostream 
istream& operator>>(istream& stream, Accessory& obj)
{
	getline(stream, obj.name);
	getline(stream, obj.manufacturer);
	stream >> obj.price >> obj.id;
	getline(stream, obj.material);
	stream >> obj.category;
	getline(stream, obj.manufacturer);
	stream >> obj.collectionYear;
	return stream;
}

ostream& operator<<(ostream& stream, Accessory& obj)
{
	stream << obj.name << endl
		<< obj.manufacturer << endl
		<< obj.price << endl
		<< obj.id << endl
		<< obj.material << endl
		<< obj.category << endl
		<< obj.brand << endl
		<< obj.collectionYear << endl;
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
