#include "ChemicalProduct.h"
#include "..\..\UI\Message.h"

ChemicalProduct::ChemicalProduct() :
	Product(),
	manufactureDate("01.01.1970"), 
	volume(0.0) 
	{
	}

istream& operator>>(istream& stream, ChemicalProduct& obj)
{
	stream >> Product(obj);
	getline(stream, obj.manufactureDate);
	cin.get();
	stream >> obj.volume;
	return stream;
}

ostream& operator<<(ostream& stream, const ChemicalProduct& obj)
{
	stream << Product(obj)
	<< obj.manufactureDate << endl
	<< obj.volume << endl;
	return stream;
}

void ChemicalProduct::input()
{
	Product::input();
	string temp;

	cout << Message("Input manufacture date: ", CONTEXT_MSG);
	getline(cin, temp);
	if (ifValidString(temp))
	{
		this->manufactureDate = temp;
	}
	temp.clear();

	cout << Message("Input volume: ", CONTEXT_MSG);
	getline(cin, temp);
	if (ifValidString(temp))
	{
		this->volume = stod(temp);
	}
	temp.clear();
}

void ChemicalProduct::output() const
{
	Product::output();
	cout << Message("Manufacture date: " + this->manufactureDate, CONTEXT_MSG);
	cout << Message("Volume: " + to_string(this->volume), CONTEXT_MSG);
}