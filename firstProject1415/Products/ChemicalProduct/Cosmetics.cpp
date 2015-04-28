#include "Cosmetics.h"
#include "..\..\UI\Message.h"

Cosmetic::Cosmetic() :
	ChemicalProduct(),
	part_of_body(' ')
	{
	}

istream& operator>>(istream& stream, Cosmetic& obj)
{
	stream >> (ChemicalProduct&)obj;
	stream >> obj.part_of_body;
	stream.get();
	return stream;
}

ostream& operator<<(ostream& stream, const Cosmetic& obj)
{
	stream << (ChemicalProduct&)obj;
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

	switch (this->part_of_body)
	{
		case 'f':
			cout << Message(string("Part of body: face"), LOG_MSG);
			break;
		case 'h':
			cout << Message(string("Part of body: hands"), LOG_MSG);
			break;
		case 'b':
			cout << Message(string("Part of body: body"), LOG_MSG);
			break;
	}
}