#include "Product.h"

Product::Product(): 
	name("No name"), manufacturer("No manufacturer"), price(0.0), id(0) { }

istream& operator>>(istream& stream, Product& obj)
{
	getline(stream, obj.name);
	getline(stream, obj.manufacturer);
	stream >> obj.price >> obj.id;
	return stream;
}
ostream& operator<<(ostream& stream, const Product& obj)
{
	stream << "Name : \t" << obj.name
		<< "\nManufacturer : \t" << obj.manufacturer
		<< "\nPrice : \t" << obj.price
		<< "\nId : \t" << obj.id
		<< endl;
	return stream;
}