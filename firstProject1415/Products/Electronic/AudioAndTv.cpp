#include "AudioAndTv.h"
#include "..\..\UI\Globals.h"
#include "..\..\UI\Message.h"
#include "..\..\UI\Globals.h"

AudioAndTv::AudioAndTv(): 
	Electronic(), 
	screenSize(0.0) 
{
}

istream& operator>>(istream& stream, AudioAndTv& obj)
{
	stream >> (Electronic&)obj;
	stream >> obj.screenSize;
	stream.get();
	return stream;
}

ostream& operator<<(ostream& stream, const AudioAndTv& obj)
{
	stream << (Electronic&)obj
		   << obj.screenSize << endl;
	return stream;
}

void AudioAndTv::input()
{
	Electronic::input();

	cout << Message("Input screen size: ", CONTEXT_MSG);
	forInput(screenSize, Message("Bad input. Try Again:", ALERT_MSG));
}

void AudioAndTv::output() const
{
	Electronic::output();
	cout << Message("Screen size: " + to_string(screenSize), LOG_MSG);
}
