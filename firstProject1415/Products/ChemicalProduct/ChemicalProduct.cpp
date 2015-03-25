#include "ChemicalProduct.h"

ChemicalProduct::ChemicalProduct() :
	Product(), manufacture_date("01.01.1970"), volume(0.0) {}

istream& operator>>(istream& stream, ChemicalProduct& obj)
{
	getline(stream, obj.name);
	getline(stream, obj.manufacturer);
	stream >> obj.price >> obj.id;
	getline(stream, obj.manufacture_date);
	stream >> obj.volume;
	return stream;
}
ostream& operator<<(ostream& stream, const ChemicalProduct& obj)
{
	stream << "Name : \t" << obj.name
		<< "\nManufacturer : \t" << obj.manufacturer
		<< "\nPrice : \t" << obj.price
		<< "\nId : \t" << obj.id
		<< "\nVolume: \t" << obj.volume
		<< endl;
	return stream;
}