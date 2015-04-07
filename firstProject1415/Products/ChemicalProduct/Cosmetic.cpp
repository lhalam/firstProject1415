#include "Cosmetic.h"

Cosmetic::Cosmetic() :
	ChemicalProduct(), part_of_body(' '){}

istream& operator>>(istream& stream, Cosmetic& obj)
{
	getline(stream, obj.name);
	getline(stream, obj.manufacturer);
	stream >> obj.price >> obj.id;
	getline(stream, obj.manufacture_date);
	stream >> obj.volume >> obj.part_of_body;
	return stream;
}
ostream& operator<<(ostream& stream, const Cosmetic& obj)
{
	stream << "Name : \t" << obj.name
		<< "\nManufacturer : \t" << obj.manufacturer
		<< "\nPrice : \t" << obj.price
		<< "\nId : \t" << obj.id
		<< "\nVolume: \t" << obj.volume
		<< "\nFor: \t";
	switch (obj.part_of_body)
	{
	case 'f': stream << "face";
		break;
	case 'h': stream << "hands";
		break;
	case 'b': stream << "body";
		break;
	default: stream << "unknown";
		break;
	}
		stream << endl;
	return stream;
}
