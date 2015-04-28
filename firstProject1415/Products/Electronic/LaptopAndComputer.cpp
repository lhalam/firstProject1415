#include "LaptopAndComputer.h"
#include "..\..\UI\Globals.h"
#include "..\..\UI\Message.h"
#include "..\..\UI\Globals.h"

LaptopAndComputer::LaptopAndComputer(): 
	Electronic(),
	firm(" ")
{
}

istream& operator>>(istream& stream, LaptopAndComputer& obj)
{
	stream >> (Electronic&)obj;
	getline(stream, obj.firm);
	return stream;
}

ostream& operator<<(ostream& stream, const LaptopAndComputer& obj)
{
	stream << (Electronic&)obj
		   << obj.firm << endl;
	return stream;
}


void LaptopAndComputer::input()
{
	Electronic::input();

	cout << Message("Input firm: ", CONTEXT_MSG);
	getline(cin, firm);
	while (!ifValidString(firm))
	{
		cout << Message("Bad input. Try Again:", ALERT_MSG);
		getline(cin, firm);
	}
}

void LaptopAndComputer::output() const
{
	Electronic::output();
	cout << Message("Firm: " + firm, LOG_MSG);
}
