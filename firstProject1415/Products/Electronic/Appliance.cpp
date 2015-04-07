#include "Appliance.h"

Appliance::Appliance() : Electronic(), memory_card(0) {}

istream& operator>>(istream& stream, Appliance& obj)
{
	getline(stream, obj.category);
	stream >> obj.weight;
	stream.get();
	getline(stream, obj.model);
	stream >> obj.memory_card;
	stream.get();
	return stream;
}

ostream& operator<<(ostream& stream, const Appliance& obj)
{
	stream << obj.category << endl
		<< obj.weight << endl
		<< obj.model << endl
		<< obj.memory_card << endl;
	return stream;
}

void Appliance::input()
{
	Electronic::input();
	cout << Message("Input memory card: ", CONTEXT_MSG);
	cin >> memory_card;
	cin.get();
}

void Appliance::output() const
{
	Electronic::output();
	cout << Message("Memory card: " + to_string(memory_card), INPUT_MSG);
}
