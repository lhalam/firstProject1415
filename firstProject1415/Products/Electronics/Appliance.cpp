#include "Appliance.h"
#include "..\..\UI\Message.h"
#include "..\..\UI\Globals.h"

Appliance::Appliance():
	Electronics(),
	height(0.0)
{
}

istream& operator>>(istream& stream, Appliance& obj)
{
	stream >> (Electronics&)obj;
	stream >> obj.height;
	return stream;
}

ostream& operator<<(ostream& stream, const Appliance& obj)
{
	stream << (Electronics&)obj
		   << obj.height << endl;
	return stream;
}

void Appliance::input()
{
	Electronics::input();

	cout << Message("Height: ", CONTEXT_MSG);
	forInput(height, Message("Bad input. Try Again:", ALERT_MSG));
}

void Appliance::output() const
{
	Electronics::output();
	cout << Message("Height: " + to_string(height), LOG_MSG);
}
