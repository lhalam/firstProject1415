#include "Nutrition.h"

Nutrition::Nutrition() :
	Product(), manufacture_date("01.01.1970"), expiration_date("01.01.1970"), ingredients("No ingredients") {}

istream& operator>>(istream& stream, Nutrition& obj)
{
	getline(stream, obj.name);
	getline(stream, obj.manufacturer);
	stream >> obj.price >> obj.id;
	getline(stream, obj.manufacture_date);
	getline(stream, obj.expiration_date);
	getline(stream, obj.ingredients);
	return stream;
}

ostream& operator<<(ostream& stream, const Nutrition& obj)
{
	stream << obj.name << endl
	<< obj.manufacturer << endl
	<< obj.price << endl
	<< obj.id << endl
	<< obj.manufacture_date << endl
	<< obj.expiration_date << endl
	<< obj.ingredients << endl;
	return stream;
}