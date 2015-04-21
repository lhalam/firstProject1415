#include "Appliance.h"
#include "..\..\UI\Message.h"

Appliance::Appliance() :
	Electronic(),
	memoryCard(0)
{
}

istream& operator>>(istream& stream, Appliance& obj)
{
	stream >> (Electronic&)obj;
	stream >> obj.memoryCard;
	return stream;
}

ostream& operator<<(ostream& stream, const Appliance& obj)
{
	stream << (Electronic&)obj
		   << obj.memoryCard << endl;
	return stream;
}

void Appliance::input()
{
	Electronic::input();
	string temp;

	cout << Message("Input memory card: ", CONTEXT_MSG);
	getline(cin, temp);
	if(ifValidString(temp))
	{
		this->memoryCard = stoi(temp);
	}
	temp.clear();
}

void Appliance::output() const
{
	Electronic::output();
	cout << Message("Memory card: " + to_string(memoryCard), LOG_MSG);
}
