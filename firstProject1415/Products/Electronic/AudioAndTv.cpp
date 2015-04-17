#include "AudioAndTv.h"
#include "..\..\UI\Message.h"

AudioAndTv::AudioAndTv() : 
	Electronic(), 
	memoryCard(0) 
{
}

istream& operator>>(istream& stream, AudioAndTv& obj)
{
	stream >> Electronic(obj);
	stream >> obj.memoryCard;
	return stream;
}

ostream& operator<<(ostream& stream, const AudioAndTv& obj)
{
	stream << Electronic(obj)
		   << obj.memoryCard << endl;
	return stream;
}

void AudioAndTv::input()
{
	Electronic::input();
	string temp;

	cout << Message("Input memory card: ", CONTEXT_MSG);
	getline(cin, temp);
	if(ifValidString(temp))
	{
		this->memoryCard = stoi(temp);
	}
	temp.clear();
}

void AudioAndTv::output() const
{
	Electronic::output();
	cout << Message("Memory card: " + to_string(memoryCard), CONTEXT_MSG);
}
