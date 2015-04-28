#include "PhotoAndVideoCamera.h"
#include "..\..\UI\Message.h"
#include "..\..\UI\Globals.h"

PhotoAndVideoCamera::PhotoAndVideoCamera():
	Electronic(),
	megapixels(0.0)
{
}

istream& operator>>(istream& stream, PhotoAndVideoCamera& obj)
{
	stream >> (Electronic&)obj
		   >> obj.megapixels;
	stream.get();
	return stream;
}

ostream& operator<<(ostream& stream, const PhotoAndVideoCamera& obj)
{
	stream << (Electronic&)obj
		   << obj.megapixels << endl;
	return stream;
}

void PhotoAndVideoCamera::input()
{
	Electronic::input();

	cout << Message("Input megapixels: ", CONTEXT_MSG);
	forInput(megapixels, Message("Bad input. Try Again:", ALERT_MSG));
}

void PhotoAndVideoCamera::output() const
{
	Electronic::output();
	cout << Message("Megapixels: " + to_string(megapixels), LOG_MSG);
}
