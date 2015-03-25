#include "Food.h"

Food::Food() :
	Nutrition(), GMO_content(' ') {}

istream& operator>>(istream& stream, Food& obj)
{
	getline(stream, obj.name);
	getline(stream, obj.manufacturer);
	stream >> obj.price >> obj.id;
	getline(stream, obj.manufacture_date);
	getline(stream, obj.expiration_date);
	getline(stream, obj.ingredients);
	stream >> obj.GMO_content;
	return stream;
}

ostream& operator<<(ostream& stream, const Food& obj)
{
	stream << "Name : \t" << obj.name
		<< "\nManufacturer : \t" << obj.manufacturer
		<< "\nPrice : \t" << obj.price
		<< "\nId : \t" << obj.id
		<< "\nManufacture date : \t" << obj.manufacture_date << "\nExpiration date : \t" << obj.expiration_date
		<< "\nIngredients : \t" << obj.ingredients << "\nGMO: \t" << obj.GMO_content
		<< endl;
	return stream;
}