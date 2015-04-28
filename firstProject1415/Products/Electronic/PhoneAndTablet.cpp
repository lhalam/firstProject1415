#include "PhoneAndTablet.h"
#include "..\..\UI\Globals.h"
#include "..\..\UI\Message.h"
#include "..\..\UI\Globals.h"

PhoneAndTablet::PhoneAndTablet():
	Electronic(),
	memoryCard(0)
{
}

istream& operator>>(istream& stream, PhoneAndTablet& obj)
{
	stream >> (Electronic&)obj
		   >> obj.memoryCard;
	stream.get();
	return stream;
}

ostream& operator<<(ostream& stream, const PhoneAndTablet& obj)
{
	stream << (Electronic&)obj
		   << obj.memoryCard << endl;
	return stream;
}

void PhoneAndTablet::input()
{
	Electronic::input();

	cout << Message("Input memory card: ", CONTEXT_MSG);
	forInput(memoryCard, Message("Bad input. Try Again:", ALERT_MSG));
}

void PhoneAndTablet::output() const
{
	Electronic::output();
	cout << Message("Memory card: " + to_string(memoryCard), LOG_MSG);
}
