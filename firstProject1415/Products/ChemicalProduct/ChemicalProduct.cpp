#include "ChemicalProduct.h"
#include "..\..\UI\Message.h"
#include "..\..\UI\Globals.h"

ChemicalProduct::ChemicalProduct():
	Product(),
	manufactureDate("00.00.0000"), 
	volume(0.0) 
{
}

istream& operator>>(istream& stream, ChemicalProduct& obj)
{
	stream >> (Product&)obj;
	getline(stream, obj.manufactureDate);
	stream >> obj.volume;
	stream.get();
	return stream;
}

ostream& operator<<(ostream& stream, const ChemicalProduct& obj)
{
	stream << (Product&)obj
	<< obj.manufactureDate << endl
	<< obj.volume << endl;
	return stream;
}

void ChemicalProduct::input()
{
	Product::input();
	
	cout << Message("Input manufactureDate: ", CONTEXT_MSG);
	getline(cin, manufactureDate);
	while(!ifValidString(manufactureDate))
	{
		cout << Message("Bad input. Try Again:", ALERT_MSG);
		getline(cin, manufactureDate);
	}

	cout << Message("Input volume: ", CONTEXT_MSG);
	forInput(volume, Message("Bad input. Try Again:", ALERT_MSG));
}

void ChemicalProduct::output() const
{
	Product::output();
	cout << Message("Manufacture date: " + this->manufactureDate, LOG_MSG);
	cout << Message("Volume: " + to_string(this->volume), LOG_MSG);
}
