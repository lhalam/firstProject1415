#include "Food.h"

Food::Food() :
	Nutrition(), GMO_content(0) {}

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
	string temp;

	cout << Message("Input GMO content: ", CONTEXT_MSG);
	getline(cin, temp);
	if (ifValidString(temp))
	{
		if (stoi(temp) == 0)
			this->GMO_content = false;
		else if (stoi(temp) == 1)
			this->GMO_content = true;
	}
	temp.clear();
}

void Food::output() const
{
	Nutrition::output();
	cout << Message("GMO: " + this->GMO_content, INPUT_MSG);
}