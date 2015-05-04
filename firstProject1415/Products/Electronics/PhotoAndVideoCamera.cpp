#include "PhotoAndVideoCamera.h"
#include "..\..\UI\Message.h"
#include "..\..\UI\Globals.h"

PhotoAndVideoCamera::PhotoAndVideoCamera():
	Electronics(),
	megapixels(0.0)
{
}

istream& operator>>(istream& stream, PhotoAndVideoCamera& obj)
{
	stream >> (Electronics&)obj
		   >> obj.megapixels;
	stream.get();
	return stream;
}

ostream& operator<<(ostream& stream, const PhotoAndVideoCamera& obj)
{
	stream << (Electronics&)obj
		   << obj.megapixels << endl;
	return stream;
}

void PhotoAndVideoCamera::input()
{
	Electronics::input();

	cout << Message("Input megapixels: ", CONTEXT_MSG);
	forInput(megapixels, Message("Bad input. Try Again:", ALERT_MSG));
}

void PhotoAndVideoCamera::output() const
{
	Electronics::output();
	cout << Message("Megapixels: " + to_string(megapixels), LOG_MSG);
}

List<pair<string, string>> PhotoAndVideoCamera::metadata()
{
	List<pair<string, string>> result = Electronics::metadata();
	result.pushBack(make_pair("megapixels", to_string(megapixels)));
	return result;
}

void PhotoAndVideoCamera::fill(string source)
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
			megapixels = stod(field);
		}
		field.clear();
		k++;
		posStart = posEnd + 1;
		posEnd = source.find_first_of(',', posStart);
		if (posEnd == string::npos) break;
	}
}
