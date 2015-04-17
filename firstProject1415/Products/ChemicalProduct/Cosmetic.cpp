#include "Cosmetic.h"
#include "..\..\UI\Message.h"

Cosmetic::Cosmetic() :
	ChemicalProduct(),
	part_of_body(' ')
	{
	}

istream& operator>>(istream& stream, Cosmetic& obj)
{
	stream  >> ChemicalProduct(obj);
	stream  >> obj.part_of_body;
	return stream;
}

ostream& operator<<(ostream& stream, const Cosmetic& obj)
{
	stream  << ChemicalProduct(obj);
	stream 	<< obj.part_of_body 
			<< endl;
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
	cout << Message("Part of body: " + this->part_of_body, CONTEXT_MSG);
}