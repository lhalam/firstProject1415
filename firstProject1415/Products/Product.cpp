#include "Product.h"

Product::Product():
	name("No name"), manufacturer("No manufacturer"), price(0.0), id(0) 
	{ 
	}

void Product::input()
{
	string temp;

	cout << Message("Input name: ", CONTEXT_MSG);
	getline(cin, temp);
	if(ifValidString(temp))
	{
		this->name = temp;
	}
	temp.clear();

	cout << Message("Input manufacturer: ", CONTEXT_MSG);
	getline(cin, temp);
	if(ifValidString(temp))
	{
		this->manufacturer = temp;
	}
	temp.clear();

	cout << Message("Input price: ", CONTEXT_MSG);
	getline(cin, temp);
	if(ifValidString(temp))
	{
		this->price = stod(temp);
	}
	temp.clear();

	cout << Message("Input id: ", CONTEXT_MSG);
	getline(cin, temp);
	if(ifValidString(temp))
	{
		this->id = stoi(temp);
	}
	temp.clear();
}

void Product::output() const
{
	cout << Message("Name: " + this->name, INPUT_MSG);
	cout << Message("Manufacturer: " + this->manufacturer, INPUT_MSG);
	cout << Message("Price: " + to_string(this->price), INPUT_MSG);
	cout << Message("ID: " + to_string(this->id), INPUT_MSG);
}


istream& operator>>(istream& stream, Product& obj)
{
	getline(stream, obj.name);
	getline(stream, obj.manufacturer);
	stream >> obj.price >> obj.id;
	return stream;
}
ostream& operator<<(ostream& stream, const Product& obj)
{
	stream << obj.name << '\n' << obj.manufacturer << '\n' << obj.price << '\n' << obj.id << endl;
	return stream;
}
