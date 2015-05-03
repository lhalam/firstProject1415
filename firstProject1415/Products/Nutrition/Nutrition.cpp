#include "Nutrition.h"
#include "../../UI/UI.h"

Nutrition::Nutrition():
	Product(),
	manufactureDate("00.00.0000"),
	expirationDate("00.00.0000"),
	ingredients("No ingredients")
{
}

Nutrition::~Nutrition()
{
}

istream& operator>>(istream& stream, Nutrition& obj)
{
	stream >> (Product&)obj;
	getline(stream, obj.manufactureDate);
	getline(stream, obj.expirationDate);
	getline(stream, obj.ingredients);
	return stream;
}

ostream& operator<<(ostream& stream, const Nutrition& obj)
{
	stream << (Product&)obj
		   << obj.manufactureDate << endl
		   << obj.expirationDate << endl
		   << obj.ingredients << endl;
	return stream;
}

void Nutrition::input()
{
	Product::input();

	cout << Message("Input manufacture date: ", CONTEXT_MSG);
	getline(cin, manufactureDate);
	while(!ifValidString(manufactureDate))
	{
		cout << Message("Bad input. Try Again:", ALERT_MSG);
		getline(cin, manufactureDate);
	}

	cout << Message("Input expiration date: ", CONTEXT_MSG);
	getline(cin, expirationDate);
	while(!ifValidString(expirationDate))
	{
		cout << Message("Bad input. Try Again:", ALERT_MSG);
		getline(cin, expirationDate);
	}

	cout << Message("Input ingredients: ", CONTEXT_MSG);
	getline(cin, ingredients);
	while(!ifValidString(ingredients))
	{
		cout << Message("Bad input. Try Again:", ALERT_MSG);
		getline(cin, ingredients);
	}
}

void Nutrition::output() const
{
	Product::output();
	cout << Message("Manufacture date: " + this->manufactureDate, LOG_MSG)
		 << Message("Expiration date: " + this->expirationDate, LOG_MSG)
		 << Message("Ingredients: " + this->ingredients, LOG_MSG);
}

List<pair<string, string>> Nutrition::metadata()
{
	List<pair<string, string>> result = Product::metadata();
	result.pushBack(make_pair("manufactureDate", manufactureDate));
	result.pushBack(make_pair("expirationDate", expirationDate));
	result.pushBack(make_pair("ingredients", ingredients));
	return result;
}

void Nutrition::fill(string source)
{
	this->Product::fill(source);
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
		case 4: manufactureDate = field;
			break;
		case 5: expirationDate = field;
			break;
		case 6: ingredients = field;
			break;
		}
		field.clear();
		k++;
		posStart = posEnd + 1;
		posEnd = source.find_first_of(',', posStart);
		if (posEnd == string::npos) break;
	}
}