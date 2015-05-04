#include "AudioAndTv.h"
#include "..\..\UI\Globals.h"
#include "..\..\UI\Message.h"
#include "..\..\UI\Globals.h"

AudioAndTv::AudioAndTv(): 
	Electronics(), 
	screenSize(0.0) 
{
}

istream& operator>>(istream& stream, AudioAndTv& obj)
{
	stream >> (Electronics&)obj;
	stream >> obj.screenSize;
	stream.get();
	return stream;
}

ostream& operator<<(ostream& stream, const AudioAndTv& obj)
{
	stream << (Electronics&)obj
		   << obj.screenSize << endl;
	return stream;
}

void AudioAndTv::input()
{
	Electronics::input();

	cout << Message("Input screen size: ", CONTEXT_MSG);
	forInput(screenSize, Message("Bad input. Try Again:", ALERT_MSG));
}

void AudioAndTv::output() const
{
	Electronics::output();
	cout << Message("Screen size: " + to_string(screenSize), LOG_MSG);
}

List<pair<string, string>> AudioAndTv::metadata()
{
	List<pair<string, string>> result = Electronics::metadata();
	result.pushBack(make_pair("screenSize", to_string(screenSize)));
	return result;
}

void AudioAndTv::fill(string source)
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
			screenSize = stod(field);
		}
		field.clear();
		k++;
		posStart = posEnd + 1;
		posEnd = source.find_first_of(',', posStart);
		if (posEnd == string::npos) break;
	}
}
