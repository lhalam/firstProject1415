#include "Drink.h"
#include "..\..\UI\Message.h"
#include "..\..\UI\Globals.h"

Drink::Drink():
	Nutrition(),
	volume(0.0)
{
}

istream& operator>>(istream& stream, Drink& obj)
{
	stream >> (Nutrition&)obj
		   >> obj.volume;
	stream.get();
	return stream;
}

ostream& operator<<(ostream& stream, const Drink& obj)
{
	stream << (Nutrition&)obj
		   << obj.volume << endl;
	return stream;
}

void Drink::input()
{
	Nutrition::input();
	
	cout << Message("Input volume: ", CONTEXT_MSG);
	forInput(volume, Message("Bad input. Try Again:", ALERT_MSG));
}

void Drink::output() const
{
	Nutrition::output();
	cout << Message("Volume: " + to_string(this->volume), LOG_MSG);
}
