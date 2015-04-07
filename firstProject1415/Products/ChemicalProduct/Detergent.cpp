#include "Detergent.h"

Detergent::Detergent() :
	ChemicalProduct(){}

istream& operator>>(istream& stream, Detergent& obj)
{
	getline(stream, obj.name);
	getline(stream, obj.manufacturer);
	stream >> obj.price >> obj.id;
	getline(stream, obj.manufacture_date);
	stream >> obj.volume;
	return stream;
}
ostream& operator<<(ostream& stream, const Detergent& obj)
{
	stream << obj.name << endl
		<< obj.manufacturer << endl
		<< obj.price << endl
		<< obj.id << endl
		<< obj.manufacture_date << endl
		<< obj.volume << endl;
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