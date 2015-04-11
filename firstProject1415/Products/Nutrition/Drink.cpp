#include "Drink.h"

Drink::Drink() :
	Nutrition(), volume(0.0) {}

istream& operator>>(istream& stream, Drink& obj)
{
	getline(stream, obj.name);
	getline(stream, obj.manufacturer);
	stream >> obj.price >> obj.id;
	getline(stream, obj.manufactureDate);
	getline(stream, obj.expirationDate);
	getline(stream, obj.ingredients);
	stream >> obj.volume;
	return stream;
}

ostream& operator<<(ostream& stream, const Drink& obj)
{
	stream << obj.name << endl
		<< obj.manufacturer << endl
		<< obj.price << endl
		<< obj.id << endl
		<< obj.manufactureDate << endl
		<< obj.expirationDate << endl
		<< obj.ingredients << endl
		<< obj.volume << endl;
	return stream;
}

void Drink::input()
{
	Nutrition::input();
	string temp;

	cout << Message("Input GMO content: ", CONTEXT_MSG);
	getline(cin, temp);
	if (ifValidString(temp))
	{
		this->volume = stod(temp);
	}
	temp.clear();
}

void Drink::output() const
{
	Nutrition::output();
	cout << Message("Volume: " + to_string(this->volume), INPUT_MSG);
}