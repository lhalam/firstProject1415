#include "Appliance.h"
#include "..\..\UI\Message.h"
#include "..\..\UI\Globals.h"

Appliance::Appliance():
	Electronic(),
	height(0.0)
{
}

istream& operator>>(istream& stream, Appliance& obj)
{
	stream >> (Electronic&)obj;
	stream >> obj.height;
	return stream;
}

ostream& operator<<(ostream& stream, const Appliance& obj)
{
	stream << (Electronic&)obj
		   << obj.height << endl;
	return stream;
}

void Appliance::input()
{
	Electronic::input();

	cout << Message("Height: ", CONTEXT_MSG);
	forInput(height, Message("Bad input. Try Again:", ALERT_MSG));
}

void Appliance::output() const
{
	Electronic::output();
	cout << Message("Height: " + to_string(height), LOG_MSG);
}
