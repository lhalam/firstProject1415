#include "Drink.h"

Drink::Drink() :
	Nutrition(), volume(0.0) {}

istream& operator>>(istream& stream, Drink& obj)
{
	getline(stream, obj.name);
	getline(stream, obj.manufacturer);
	stream >> obj.price >> obj.id;
	getline(stream, obj.manufacture_date);
	getline(stream, obj.expiration_date);
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
		<< obj.manufacture_date << endl
		<< obj.expiration_date << endl
		<< obj.ingredients << endl
		<< obj.volume << endl;
	return stream;
}

void Drink::input()
{
	Nutrition::input();
	cout << Message("Input volume: ", CONTEXT_MSG);
	cin >> this->volume;
}

void Drink::output() const
{
	Nutrition::output();
	cout << Message("Volume: " + to_string(this->volume), INPUT_MSG);
}