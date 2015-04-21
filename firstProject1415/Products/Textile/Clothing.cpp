#include "Clothing.h"
#include "..\..\UI\Message.h"

Clothing::Clothing() :
	Textile(),
	size(' '),
	season(' ')
{
}

istream& operator>>(istream& stream, Clothing& obj)
{
	stream >> (Textile&)obj >> obj.size >> obj.season;
	return stream;
}

ostream& operator<<(ostream& stream, Clothing& obj)
{
	stream << (Textile&)obj
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
	if (ifValidString(temp))
	{
		this->size = temp[0];
	}
	temp.clear();

	cout << Message("Input season: ", CONTEXT_MSG);
	getline(cin, temp);
	if (ifValidString(temp))
	{
		this->season = temp[0];
	}
	temp.clear();
}

void Clothing::output()
{
	Textile::output();
	cout << Message("Size:" + this->size, LOG_MSG);
	switch (this->season)
	{
		case 'w': cout << Message("Season: winter", LOG_MSG);
			break;
		case 's': cout << Message("Season: summer", LOG_MSG);
			break;
		case 'a': cout << Message("Season: autumn&spring", LOG_MSG);
			break;
		default: cout << Message("Season: unknown", LOG_MSG);
	}
}
