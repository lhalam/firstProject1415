#include "Footwear.h"
#include "..\..\UI\Message.h"

Footwear::Footwear() :
	Textile(),
	size(0), 
	season(' ')
{
}

istream& operator>>(istream& stream, Footwear& obj)
{
	stream >> Textile(obj) >> obj.size >> obj.season;
	return stream;
}

ostream& operator<<(ostream& stream, Footwear& obj)
{
	stream << Textile(obj)
	 	   << obj.size << endl
		   << obj.season << endl;
	return stream;
}

void Footwear::input()
{
	Textile::input();

	string temp;

	cout << Message("Input size: ", CONTEXT_MSG);
	getline(cin, temp);
	if (ifValidString(temp))
	{
		this->size = stoi(temp);
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

void Footwear::output()
{
	Textile::output();
	cout << Message("Size:" + to_string(this->size), CONTEXT_MSG);
	switch (this->season)
	{
	case 'w': cout << Message("Season: winter", CONTEXT_MSG);
		break;
	case 's': cout << Message("Season: summer", CONTEXT_MSG);
		break;
	case 'a': cout << Message("Season: autumn&spring", CONTEXT_MSG);
		break;
	default:  cout << Message("Season: unknown", CONTEXT_MSG);
	}
}
