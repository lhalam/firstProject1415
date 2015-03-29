#include "Accessory.h"

Accessory::Accessory() :
	Textile(){}

istream& operator>>(istream& stream, Accessory& obj)
{
	getline(stream, obj.name);
	getline(stream, obj.manufacturer);
	stream >> obj.price >> obj.id;
	getline(stream, obj.material);
	stream >> obj.category;
	getline(stream, obj.manufacturer);
	stream >> obj.collection_year;
	return stream;
}
ostream& operator<<(ostream& stream, Accessory& obj)
{
	stream << "Name : \t" << obj.name
		<< "\nManufacturer : \t" << obj.manufacturer
		<< "\nPrice : \t" << obj.price
		<< "\nId : \t" << obj.id
		<< "\nMaterial : \t" << obj.material
		<< "\nFor : \t";
	switch (obj.category)
	{
	case 'm': stream << "male";
		break;
	case 'f': stream << "fermale";
		break;
	case 'b': stream << "baby";
		break;
	default: stream << "unknown";
		break;
	}
	stream << "\nBrand : \t" << obj.brand
		<< "\nCollection year : \t" << obj.collection_year
		<< endl;
	return stream;
}