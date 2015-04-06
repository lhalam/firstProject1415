#include "Product.h"

Product::Product():
	name("No name"), manufacturer("No manufacturer"), price(0.0), id(0) 
	{ 
	}

void Product::Input()
{
	/*
		still yet no valid input checking included
		possible option:
		char answer;
		cout << "Message("Do you want to create new / modify existing product? (y/n)", ALERT_MSG);
		cin >> answer;
		switch(answer)
		{
			case 'y':
			case 'Y':
				int _id;
				cout << Message("Input ID: ", INPUT_MSG);
				cin >> _id;
				// Searching database for product . . .
				//  * found existing product -> modify values
				//  * not found existing     -> create new one
		}
		*/
	
	cout << Message("Input name: ", CONTEXT_MSG);
	getline(cin, this->name);
	cout << Message("Input manufacturer: ", CONTEXT_MSG);
	getline(cin, this->manufacturer);
	cout << Message("Input price: ", CONTEXT_MSG);
	cin >> this->price;
	cout << Message("Input id: ", CONTEXT_MSG);
	cin >> this->id;
}

void Product::Output() const
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
