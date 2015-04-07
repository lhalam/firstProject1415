#include "Clothing.h"

Clothing::Clothing() :
	Textile(), size(' '), season(' '){}

istream& operator>>(istream& stream, Clothing& obj)
{
	getline(stream, obj.name);
	getline(stream, obj.manufacturer);
	stream >> obj.price >> obj.id;
	getline(stream, obj.material);
	stream >> obj.category;
	getline(stream, obj.manufacturer);
	stream >> obj.collection_year >> obj.size >> obj.season;
	return stream;
}

ostream& operator<<(ostream& stream, Clothing& obj)
{
	stream << obj.name << endl
		<< obj.manufacturer << endl
		<< obj.price << endl
		<< obj.id << endl
		<< obj.material << endl
		<< obj.category << endl
		<< obj.brand << endl
		<< obj.collection_year << endl
		<< obj.size << endl
		<< obj.season << endl;
	return stream;
}

void Clothing::input()
{
	Textile::input();
	string temp;

	cout << Message("Input size: ", CONTEXT_MSG);
	getline(cin, temp);
	if(ifValidString(temp))
	{
		this->material = abs(stoi(temp));
	}
	temp.clear();

	cout << Message("Input season: ", CONTEXT_MSG);
	getline(cin, temp);
	if(ifValidString(temp))
	{
		this->material = temp[0];
	}
	temp.clear();
}
void Clothing::output()
{
	Textile::output();
	cout << "\nSize : \t" << this->size
		<< "\nSeason : \t";
	switch (this->season)
	{
	case 'w': cout << "winter";
		break;
	case 's': cout << "summer";
		break;
	case 'a': cout << "autumn&spring";
		break;
	default: cout << "unknown";
	}
}