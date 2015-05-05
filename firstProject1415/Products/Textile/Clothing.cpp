#include "Clothing.h"
#include "..\..\UI\Message.h"
#include "..\..\UI\Globals.h"


Clothing::Clothing() :
	Textile(),
	size(' '),
	season(' ')
{
}

istream& operator>>(istream& stream, Clothing& obj)
{
	stream >> (Textile&)obj >> obj.size >> obj.season;
	stream.get();
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

	cout << Message("Input size: ", CONTEXT_MSG);
	forInput(size, Message("Bad input. Try Again:", ALERT_MSG));
	
	cout << Message("Input season: ", CONTEXT_MSG);
	forInput(season, Message("Bad input. Try Again:", ALERT_MSG));
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
