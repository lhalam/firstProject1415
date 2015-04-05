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
	cout << "\n Size : \t";
	cin >> this->size;
	cout << "\n Season : \t";
	cin >> this->season;
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