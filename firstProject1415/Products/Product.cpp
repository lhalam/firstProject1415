#include "Product.h"
#include "../UI/UI.h"


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
	cout << Message("Input name: ", CONTEXT_MSG);
	getline(cin, name);
	if(!ifValidString(name))
	{
		cout << Message("Bad input. Try Again:", ALERT_MSG);
		getline(cin, name);
	}
	
	cout << Message("Input manufacturer: ", CONTEXT_MSG);
	getline(cin, manufacturer);
	if(!ifValidString(manufacturer))
	{
		cout << Message("Bad input. Try Again:", ALERT_MSG);
		getline(cin, manufacturer);
	}

	cout << Message("Input price: ", CONTEXT_MSG);
	forInput(price, Message("Bad input. Try Again:", ALERT_MSG));

	cout << Message("Input id: ", CONTEXT_MSG);
	forInput(id, Message("Bad input. Try Again:", ALERT_MSG));
}

void Product::output() const
{
	cout << Message("Name: " + this->name, LOG_MSG)
		 << Message("Manufacturer: " + this->manufacturer, LOG_MSG)
		 << Message("Price: " + to_string(this->price), LOG_MSG)
		 << Message("ID: " + to_string(this->id), LOG_MSG);
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

List<pair<string, string>> Product::metadata()
{
	List<pair<string, string>> result;
	result.pushBack(make_pair("name", name));
	result.pushBack(make_pair("manufacturer", manufacturer));
	result.pushBack(make_pair("price", to_string(price)));
	result.pushBack(make_pair("id", to_string(id)));
	return result;
}

void Product::fill(string source)
{
	int posStart = 0;
	int posEnd = source.find_first_of(',');
	string field = "";
	int i = 0, k = 0;
	while (source[i] != '\n')
	{
		for (i = posStart; i < posEnd; i++)
		{
			field += source[i];
		}
		switch (k)
		{
		case 0: name = field;
			break;
		case 1: manufacturer = field;
			break;
		case 2: price = stod(field);
			break;
		case 3: id = stoul(field);
			break;
		}
		field.clear();
		k++;
		posStart = posEnd + 1;
		posEnd = source.find_first_of(',', posStart);
		if (posEnd == string::npos) break;
	}
}