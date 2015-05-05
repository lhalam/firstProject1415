#include "Cosmetics.h"
#include "..\..\UI\Message.h"
#include "..\..\UI\Globals.h"

Cosmetics::Cosmetics():
	ChemicalProduct(),
	part_of_body(' ')
{
}

istream& operator>>(istream& stream, Cosmetics& obj)
{
	stream >> (ChemicalProduct&)obj;
	stream >> obj.part_of_body;
	stream.get();
	return stream;
}

ostream& operator<<(ostream& stream, const Cosmetics& obj)
{
	stream << (ChemicalProduct&)obj;
	stream 	<< obj.part_of_body 
			<< endl;
	return stream;
}

void Cosmetics::input()
{
	ChemicalProduct::input();

	cout << Message("Input part of body it is used for: ", CONTEXT_MSG);
	forInput(part_of_body, Message("Bad input. Try Again:", ALERT_MSG));
}

void Cosmetics::output() const
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

List<pair<string, string>> Cosmetics::metadata()
{
	List<pair<string, string>> result = ChemicalProduct::metadata();
	result.pushBack(make_pair("part_of_body", to_string(part_of_body)));
	return result;
}

void Cosmetics::fill(string source)
{
	this->ChemicalProduct::fill(source);
	int posStart = 0;
	int posEnd = source.find_first_of(',');
	string field = "";
	int i = 0;
	int k = 0;
	while (source[i] != '\n')
	{
		for (i = posStart; i < posEnd; i++)
		{
			field += source[i];
		}
		if(k == 6)
		{
			part_of_body = field[0];
		}
		field.clear();
		k++;
		posStart = posEnd + 1;
		posEnd = source.find_first_of(',', posStart);
		if (posEnd == string::npos) break;
	}
}
