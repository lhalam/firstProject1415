#include "Drink.h"
#include "../../UI/UI.h"


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

List<pair<string, string>> Drink::metadata()
{
	List<pair<string, string>> result = Nutrition::metadata();
	result.pushBack(make_pair("volume", to_string(volume)));
	return result;
}

void Drink::fill(string source)
{
	this->Nutrition::fill(source);
	int posStart = 0;
	int posEnd = source.find_first_of(',');
	string field = "";
	int i = 0, k = 0;
	while (source[i] != '\n')
	{
		for (i = posStart; i < posEnd; i++)
		{
			field += source[i];
		}
		if (k == 7)
		{
			volume = stod(field);
		}
		field.clear();
		k++;
		posStart = posEnd + 1;
		posEnd = source.find_first_of(',', posStart);
		if (posEnd == string::npos) break;
	}
}
