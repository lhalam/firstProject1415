#include "PhoneAndTablet.h"

PhoneAndTablet::PhoneAndTablet() : Electronic(), memoryCard(0) {}

istream& operator>>(istream& stream, PhoneAndTablet& obj)
{
	getline(stream, obj.category);
	stream >> obj.weight;
	stream.get();
	getline(stream, obj.model);
	stream >> obj.memoryCard;
	stream.get();
	return stream;
}

ostream& operator<<(ostream& stream, const PhoneAndTablet& obj)
{
	stream << obj.category << endl 
		   << obj.weight << endl 
		   << obj.model << endl 
		   << obj.memoryCard << endl;
	return stream;
}

void PhoneAndTablet::input()
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

void PhoneAndTablet::output() const
{
	Electronic::output();
	cout << Message("Memory card: " + to_string(memoryCard), INPUT_MSG);
}
