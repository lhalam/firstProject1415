#include "AudioAndTv.h"
#include "..\..\UI\Globals.h"
#include "..\..\UI\Message.h"
#include "..\..\UI\Globals.h"

AudioAndTv::AudioAndTv(): 
	Electronic(), 
	memoryCard(0) 
{
}

istream& operator>>(istream& stream, AudioAndTv& obj)
{
	stream >> (Electronic&)obj;
	stream >> obj.memoryCard;
	stream.get();
	return stream;
}

ostream& operator<<(ostream& stream, const AudioAndTv& obj)
{
	stream << (Electronic&)obj
		   << obj.memoryCard << endl;
	return stream;
}

void AudioAndTv::input()
{
	Electronic::input();

	cout << Message("Input memory card: ", CONTEXT_MSG);
	forInput(memoryCard, Message("Bad input. Try Again:", ALERT_MSG));
}

void AudioAndTv::output() const
{
	Electronic::output();
	cout << Message("Memory card: " + to_string(memoryCard), LOG_MSG);
}
