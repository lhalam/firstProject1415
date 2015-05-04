#include "Appliance.h"
#include "..\..\UI\Message.h"
#include "..\..\UI\Globals.h"

Appliance::Appliance():
	Electronics(),
	height(0.0)
{
}

istream& operator>>(istream& stream, Appliance& obj)
{
	stream >> (Electronics&)obj;
	stream >> obj.height;
	return stream;
}

ostream& operator<<(ostream& stream, const Appliance& obj)
{
	stream << (Electronics&)obj
		   << obj.height << endl;
	return stream;
}

void Appliance::input()
{
	Electronics::input();

	cout << Message("Height: ", CONTEXT_MSG);
	forInput(height, Message("Bad input. Try Again:", ALERT_MSG));
}

void Appliance::output() const
{
	Electronics::output();
	cout << Message("Height: " + to_string(height), LOG_MSG);
}

List<pair<string, string>> Appliance::metadata()
{
	List<pair<string, string>> result = Electronics::metadata();
	result.pushBack(make_pair("height", to_string(height)));
	return result;
}

void Appliance::fill(string source)
{
	this->Electronics::fill(source);
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
		if(k == 7)
		{
			weight = stod(field);
		}
		field.clear();
		k++;
		posStart = posEnd + 1;
		posEnd = source.find_first_of(',', posStart);
		if (posEnd == string::npos) break;
	}
}
