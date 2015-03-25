#include "Footwear.h"

Footwear::Footwear() :
	Textile(), size(0), season(' '){}

istream& operator>>(istream& stream, Footwear& obj)
{
	getline(stream, obj.name);
	getline(stream, obj.manufacturer);
	stream >> obj.price >> obj.id;
	getline(stream, obj.material);
	stream >> obj.category;
	getline(stream, obj.manufacturer);
	stream >> obj.collection_year >> obj.size >> obj.season;
	return stream;
}
ostream& operator<<(ostream& stream, Footwear& obj)
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
		<< "\nSize : \t" << obj.size
		<< "\nSeason : \t";
	switch (obj.season)
	{
	case 'w': stream << "winter";
		break;
	case 's': stream << "summer";
		break;
	case 'a': stream << "autumn&spring";
		break;
	default: stream << "unknown";
	}
	stream << endl;
	return stream;
}