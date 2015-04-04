#include "Product.h"

Product::Product():
	name("No name"), manufacturer("No manufacturer"), price(0.0), id(0) { }

string Product::getDetails()
{
	return "Name:\t" + this->name 
			+ "\nManufacturer:\t" + this->manufacturer 
			+ "\nPrice:\t" + to_string(this->price) 
			+ "\nID:\t" + to_string(this->id); 
}

istream& operator>>(istream& stream, Product& obj)
{
	getline(stream, obj.name);
	getline(stream, obj.manufacturer);
	stream >> obj.price >> obj.id;
	return stream;
}
ostream& operator<<(ostream& stream, const Product& obj)
{
	stream << obj.name << obj.manufacturer << obj.price << obj.id << endl;
	return stream;
}
