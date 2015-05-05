#include "Textile.h"
#include "..\..\UI\Message.h"
#include "..\..\UI\Globals.h"

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
	stream >> (Product&)obj;
	getline(stream, obj.material);
	stream >> obj.category;
	stream.get();
	getline(stream, obj.manufacturer);
	stream >> obj.collectionYear;
	stream.get();
	return stream;
}

ostream& operator<<(ostream& stream, Textile& obj)
{
	stream << (Product&)obj
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
	getline(cin, material);
	while(!ifValidString(material))
	{
		cout << Message("Bad input. Try Again:", ALERT_MSG);
		getline(cin, material);
	}

	cout << Message("Input category: ", CONTEXT_MSG);
	forInput(category, Message("Bad input. Try Again:", ALERT_MSG));
	
	cout << Message("Input brand: ", CONTEXT_MSG);
	getline(cin, brand);
	while(!ifValidString(brand))
	{
		cout << Message("Bad input. Try Again:", ALERT_MSG);
		getline(cin, brand);
	}

	cout << Message("Input collection year: ", CONTEXT_MSG);
	forInput(collectionYear, Message("Bad input. Try Again:", ALERT_MSG));
}

void Textile::output()
{
	Product::output();
	cout << Message("Material: " + this->material, LOG_MSG);
	switch (this->category)
	{
		case 'm': cout << Message("Category: male", LOG_MSG);
			break;
		case 'f': cout << Message("Category: female", LOG_MSG);
			break;
		case 'b': cout << Message("Category: baby", LOG_MSG);
			break;
		default:  cout << Message("Category: unknown", LOG_MSG);
			break;
	}
	cout << Message("Brand: " + this->brand, LOG_MSG)
		 << Message("Collection year:" + to_string(this->collectionYear), LOG_MSG);
}

List<pair<string, string>> Textile::metadata()
{
	List<pair<string, string>> result = Product::metadata();
	result.pushBack(make_pair("material", material));
	result.pushBack(make_pair("category", to_string(category)));
	result.pushBack(make_pair("brand", brand));
	result.pushBack(make_pair("collectionYear", to_string(collectionYear)));
	return result;
}

void Textile::fill(string source)
{
	this->Product::fill(source);
	int posStart = 0;
	int posEnd = source.find_first_of(',');
	string field = "";
	int k = 0;
	int i = 0;
	while (source[i] != '\n')
	{
		for (i = posStart; i < posEnd; i++)
		{
			field += source;
		}
		switch (k)
		{
		case 4: material = field;
			break;
		case 5: category = field[0];
			break;
		case 6: brand = field;
			break;
		case 7: collectionYear = stoi(field);
			break;
		default:
			break;
		}
		field.clear();
		k++;
		posStart = posEnd + 1;
		posEnd = source.find(',', posStart);
		if (posEnd == string::npos)	break;
	}
}