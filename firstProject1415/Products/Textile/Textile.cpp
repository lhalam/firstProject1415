#include "Textile.h"
#include "..\..\UI\Message.h"

Textile::Textile() :
	Product(), 
	material("Unknown material"), 
	category(' '), 
	brand("No brand"), 
	collectionYear(0)
{
}

istream& operator>>(istream& stream, Textile& obj)
{
	stream >> Product(obj);
	getline(stream, obj.material);
	stream.get();
	stream >> obj.category;
	getline(stream, obj.manufacturer);
	stream.get();
	stream >> obj.collectionYear;
	return stream;
}

ostream& operator<<(ostream& stream, Textile& obj)
{
	stream << Product(obj)
		<< obj.material	<< endl
		<< obj.category << endl
		<< obj.brand << endl
		<< obj.collectionYear << endl;
	return stream;
}

void Textile::input()
{
	Product::input();
	
	string temp;

	cout << Message("Input material: ", CONTEXT_MSG);
	getline(cin, temp);
	if (ifValidString(temp))
	{
		this->material = temp;
	}
	temp.clear();

	cout << Message("Input category: ", CONTEXT_MSG);
	getline(cin, temp);
	if (ifValidString(temp))
	{
		this->category = temp[0];
	}
	temp.clear();
	
	cout << Message("Input brand: ", CONTEXT_MSG);
	getline(cin, temp);
	if (ifValidString(temp))
	{
		this->brand = temp;
	}
	temp.clear();

	cout << Message("Input collection year: ", CONTEXT_MSG);
	getline(cin, temp);
	if (ifValidString(temp))
	{
		this->collectionYear = stoi(temp);
	}
	temp.clear();
}

void Textile::output()
{
	Product::output();
	cout << Message("Material: " + this->material, INPUT_MSG);
	switch (this->category)
	{
	case 'm': cout << Message("Category: male", CONTEXT_MSG);
		break;
	case 'f': cout << Message("Category: female", CONTEXT_MSG);
		break;
	case 'b': cout << Message("Category: baby", CONTEXT_MSG);
		break;
	default:  cout << Message("Category: unknown", CONTEXT_MSG);
		break;
	}
	cout << Message("Brand: " + this->brand, CONTEXT_MSG)
		 << Message("Collection year:" + to_string(this->collectionYear), CONTEXT_MSG);
}

