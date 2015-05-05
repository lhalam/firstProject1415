#include "PhoneAndTablet.h"
#include "..\..\UI\Globals.h"
#include "..\..\UI\Message.h"
#include "..\..\UI\Globals.h"


PhoneAndTablet::PhoneAndTablet():
	Electronics(),
	memoryCard(0)
{
}

istream& operator>>(istream& stream, PhoneAndTablet& obj)
{
	stream >> (Electronics&)obj
		   >> obj.memoryCard;
	stream.get();
	return stream;
}

ostream& operator<<(ostream& stream, const PhoneAndTablet& obj)
{
	stream << (Electronics&)obj
		   << obj.memoryCard << endl;
	return stream;
}

void PhoneAndTablet::input()
{
	Electronics::input();

	cout << Message("Input memory card: ", CONTEXT_MSG);
	forInput(memoryCard, Message("Bad input. Try Again:", ALERT_MSG));
}

void PhoneAndTablet::output() const
{
	Electronics::output();
	cout << Message("Memory card: " + to_string(memoryCard), LOG_MSG);
}

List<pair<string, string>> PhoneAndTablet::metadata()
{
	List<pair<string, string>> result = Electronics::metadata();
	result.pushBack(make_pair("memorycard", to_string(memoryCard)));
	return result;
}

void PhoneAndTablet::fill(string source)
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
			memoryCard = stoi(field);
		}
		field.clear();
		k++;
		posStart = posEnd + 1;
		posEnd = source.find_first_of(',', posStart);
		if (posEnd == string::npos) break;
	}
}
