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
	stream << "Name : \t" << obj.name
		<< "\nManufacturer : \t" << obj.manufacturer
		<< "\nPrice : \t" << obj.price
		<< "\nId : \t" << obj.id
		<< "\nManufacture date : \t" << obj.manufacture_date << "\nExpiration date : \t" << obj.expiration_date
		<< "\nIngredients : \t" << obj.ingredients
		<< endl;
	return stream;
}