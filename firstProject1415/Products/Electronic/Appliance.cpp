#include "Appliance.h"
#include "..\..\UI\Message.h"
#include "..\..\UI\Globals.h"

Appliance::Appliance():
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

	cout << Message("Input memory card: ", CONTEXT_MSG);
	forInput(memoryCard, Message("Bad input. Try Again:", ALERT_MSG));
}

void Appliance::output() const
{
	Electronic::output();
	cout << Message("Memory card: " + to_string(memoryCard), LOG_MSG);
}
