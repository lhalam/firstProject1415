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
	stream << obj.name << endl
		<< obj.manufacturer << endl
		<< obj.price << endl
		<< obj.id << endl
		<< obj.manufacture_date << endl
		<< obj.volume << endl
		<< obj.part_of_body << endl;
	return stream;
}

void Cosmetic::input()
{
	ChemicalProduct::input();
	string temp;

	cout << Message("Input part of body it is used for: ", CONTEXT_MSG);
	getline(cin, temp);
	if (ifValidString(temp))
	{
		this->part_of_body = temp[0];
	}
	temp.clear();
}

void Cosmetic::output() const
{
	ChemicalProduct::output();
	cout << Message("Part of body: " + this->part_of_body, INPUT_MSG);
}