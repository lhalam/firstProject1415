#include "Product.h"
#include "..\UI\Message.h"

bool ifValidString(string str)
{
	if(str[0] == ' ' || str[0] == '\t'|| str[0] == '\n'|| 
	   str[0] == '\0'|| str[0] == '\a'|| str[0] == '.' || 
	   str[0] == ',' || str[0] == ':' || str[0] == ';' || 
	   str[0] == '`' || str[0] == '&' || str[0] == '@' )
	{
		return false;
	}
	return true;
}

Product::Product():
	name("No name"), 
	manufacturer("No manufacturer"), 
	price(0.0), 
	id(0) 
{
}

Product::~Product()
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
	cout << Message("Name: " + this->name, CONTEXT_MSG)
		 << Message("Manufacturer: " + this->manufacturer, CONTEXT_MSG)
		 << Message("Price: " + to_string(this->price), CONTEXT_MSG)
		 << Message("ID: " + to_string(this->id), CONTEXT_MSG);
}

bool Product::operator==(const Product& prod) const
{
	return this->id == prod.id;
}

bool Product::operator!=(const Product& prod) const
{
	return this->id != prod.id;
}

istream& operator>>(istream& stream, Product& obj)
{
	getline(stream, obj.name);
	getline(stream, obj.manufacturer);
	stream >> obj.price;
	stream.get();
	stream >> obj.id;
	stream.get();
	return stream;
}

ostream& operator<<(ostream& stream, const Product& obj)
{
	stream << obj.name << '\n' 
		   << obj.manufacturer << '\n' 
		   << obj.price << '\n' 
		   << obj.id << endl;
	return stream;
}
