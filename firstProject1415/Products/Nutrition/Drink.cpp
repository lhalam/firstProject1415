#include "Drink.h"

Drink::Drink() :
	Nutrition(), volume(0.0) {}

istream& operator>>(istream& stream, Drink& obj)
{
	getline(stream, obj.name);
	getline(stream, obj.manufacturer);
	stream >> obj.price >> obj.id;
	getline(stream, obj.manufacture_date);
	getline(stream, obj.expiration_date);
	getline(stream, obj.ingredients);
	stream >> obj.volume;
	return stream;
}

ostream& operator<<(ostream& stream, const Drink& obj)
{
	stream << "Name : \t" << obj.name
		<< "\nManufacturer : \t" << obj.manufacturer
		<< "\nPrice : \t" << obj.price
		<< "\nId : \t" << obj.id
		<< "\nManufacture date : \t" << obj.manufacture_date << "\nExpiration date : \t" << obj.expiration_date
		<< "\nIngredients : \t" << obj.ingredients << "\nVolume : \t" << obj.volume
		<< endl;
	return stream;
}