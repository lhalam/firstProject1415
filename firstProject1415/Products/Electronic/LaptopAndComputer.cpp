#include "LaptopAndComputer.h"

LaptopAndComputer::LaptopAndComputer() : Electronic(), firm(" ") {}

istream& operator>>(istream& stream, LaptopAndComputer& obj)
{
	getline(stream, obj.category);
	stream >> obj.weight;
	stream.get();
	getline(stream, obj.model);
	getline(stream, obj.firm);
	return stream;
}

ostream& operator<<(ostream& stream, const LaptopAndComputer& obj)
{
	stream << obj.category << endl
	       << obj.weight << endl
	       << obj.model << endl
	       << obj.firm << endl;
	return stream;
}


void LaptopAndComputer::input()
{
	Electronic::input();
	string temp;

	cout << Message("Input firm: ", CONTEXT_MSG);
	getline(cin, temp);
	if(ifValidString(temp))
	{
		this->firm = temp;
	}
	temp.clear();
}

void LaptopAndComputer::output() const
{
	Electronic::output();
	cout << Message("Firm: " + firm, INPUT_MSG);
}
