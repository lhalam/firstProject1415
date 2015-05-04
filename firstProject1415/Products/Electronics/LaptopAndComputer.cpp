#include "LaptopAndComputer.h"
#include "..\..\UI\Globals.h"
#include "..\..\UI\Message.h"


LaptopAndComputer::LaptopAndComputer(): 
	Electronics(),
	firm(" ")
{
}

istream& operator>>(istream& stream, LaptopAndComputer& obj)
{
	stream >> (Electronics&)obj;
	getline(stream, obj.firm);
	return stream;
}

ostream& operator<<(ostream& stream, const LaptopAndComputer& obj)
{
	stream << (Electronics&)obj
		   << obj.firm << endl;
	return stream;
}


void LaptopAndComputer::input()
{
	Electronics::input();

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
	Electronics::output();
	cout << Message("Firm: " + firm, LOG_MSG);
}
