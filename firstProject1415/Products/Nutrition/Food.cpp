#include "Food.h"

Food::Food() :
	Nutrition(), GMO_content(' ') {}

istream& operator>>(istream& stream, Food& obj)
{
	getline(stream, obj.name);
	getline(stream, obj.manufacturer);
	stream >> obj.price >> obj.id;
	getline(stream, obj.manufacture_date);
	getline(stream, obj.expiration_date);
	getline(stream, obj.ingredients);
	stream >> obj.GMO_content;
	return stream;
}

ostream& operator<<(ostream& stream, const Food& obj)
{
	stream << obj.name << endl
		<< obj.manufacturer << endl
		<< obj.price << endl
		<< obj.id << endl
		<< obj.manufacture_date << endl
		<< obj.expiration_date << endl
		<< obj.ingredients << endl
		<< obj.GMO_content << endl;
	return stream;
}

void Food::input()
{
	Nutrition::input();
	cout << Message("input GMO: ", CONTEXT_MSG);
	cin >> this->GMO_content;
}

void Food::output() const
{
	Nutrition::output();
	cout << Message("GMO: " + this->GMO_content, INPUT_MSG);
}