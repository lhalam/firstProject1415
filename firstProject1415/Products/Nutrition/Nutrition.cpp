#include "Nutrition.h"

Nutrition::Nutrition():
	Product(),
	manufactureDate("01.01.1970"),
	expirationDate("01.01.1970"),
	ingredients("No ingredients")
{
}

Nutrition::~Nutrition()
{
}

istream& operator>>(istream& stream, Nutrition& obj)
{
	stream >> Product(obj);
	getline(stream, obj.manufactureDate);
	cin.get();
	getline(stream, obj.expirationDate);
	cin.get();
	getline(stream, obj.ingredients);
	cin.get();
	return stream;
}

ostream& operator<<(ostream& stream, const Nutrition& obj)
{
	stream << Product(obj) << endl
		   << obj.manufactureDate << endl
		   << obj.expirationDate << endl
		   << obj.ingredients << endl;
	return stream;
}

void Nutrition::input()
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

	cout << Message("Input expiration date: ", CONTEXT_MSG);
	getline(cin, temp);
	if (ifValidString(temp))
	{
		this->expirationDate = temp;
	}
	temp.clear();

	cout << Message("Input ingredients: ", CONTEXT_MSG);
	getline(cin, temp);
	if (ifValidString(temp))
	{
		this->ingredients = temp;
	}
	temp.clear();
}

void Nutrition::output() const
{
	Product::output();
	cout << Message("Manufacture date: " + this->manufactureDate, INPUT_MSG) << endl
		 << Message("Expiration date: " + this->expirationDate, INPUT_MSG) << endl
		 << Message("Ingredients: " + this->ingredients, INPUT_MSG) << endl;
}