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
