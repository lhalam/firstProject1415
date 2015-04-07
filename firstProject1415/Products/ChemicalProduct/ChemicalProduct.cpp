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
	stream << obj.name << endl
		<< obj.manufacturer << endl
		<< obj.price << endl
		<< obj.id << endl
		<< obj.manufacture_date << endl
		<< obj.volume << endl;
	return stream;
}

void ChemicalProduct::input()
{
	Product::input();
	string temp;

	cout << Message("Input manufacture date: ", CONTEXT_MSG);
	getline(cin, temp);
	if (ifValidString(temp))
	{
		this->manufacture_date = temp;
	}
	temp.clear();

	cout << Message("Input volume: ", CONTEXT_MSG);
	getline(cin, temp);
	if (ifValidString(temp))
	{
		this->volume = stod(temp);
	}
	temp.clear();
}

void ChemicalProduct::output() const
{
	Product::output();
	cout << Message("Manufacture date: " + this->manufacture_date, INPUT_MSG);
	cout << Message("Volume: " + to_string(this->volume), INPUT_MSG);
}