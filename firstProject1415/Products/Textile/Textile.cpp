#include "Textile.h"

Textile::Textile() :
	Product(), material("Unknown material"), category(' '), brand("No brand"), collection_year(0){}

// overloading operators istream and ostream 
istream& operator>>(istream& stream, Textile& obj)
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
ostream& operator<<(ostream& stream, Textile& obj)
{
	stream << obj.name << endl
		<< obj.manufacturer	<< endl
		<< obj.price << endl
		<< obj.id << endl 
		<< obj.material	<< endl
		<< obj.category << endl
		<< obj.brand << endl
		<< obj.collection_year << endl;
	return stream;
}

void Textile::input()
{
	cout << "Name : \t";
	cin >> this->name;
	cout << "\nManufacturer : \t";
	cin >> this->manufacturer;
	cout << "\nPrice : \t";
	cin >> this->price;
	cout << "\nId : \t";
	cin >> this->id;
	cout << "\nMaterial : \t";
	cin >> this->material;
	cout << "\n Category : \t";
	cin >> this->category;
	cout << "\nBrand : \t";
	cin >> this->brand;
	cout << "\nCollection year : \t";
	cin >> this->collection_year << endl;
}
void Textile::output()
{
	cout << "Name : \t" << this->name
		<< "\nManufacturer : \t" << this->manufacturer
		<< "\nPrice : \t" << this->price
		<< "\nId : \t" << this->id
		<< "\nMaterial : \t" << this->material
		<< "\nFor : \t";
	switch (this->category)
	{
	case 'm': cout << "male";
		break;
	case 'f': cout << "fermale";
		break;
	case 'b': cout << "baby";
		break;
	default: cout << "unknown";
		break;
	}
	cout << "\nBrand : \t" << this->brand
		<< "\nCollection year : \t" << this->collection_year << endl;
}