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
	stream << "Name : \t" << obj.name
		<< "\nManufacturer : \t" << obj.manufacturer
		<< "\nPrice : \t" << obj.price
		<< "\nId : \t" << obj.id
		<< "\nVolume: \t" << obj.volume
		<< endl;
	return stream;
}