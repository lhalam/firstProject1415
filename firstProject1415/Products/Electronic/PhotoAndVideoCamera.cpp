#include "PhotoAndVideoCamera.h"
#include "..\..\UI\Message.h"

PhotoAndVideoCamera::PhotoAndVideoCamera() :
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
	string temp;

	cout << Message("Input megapixels: ", CONTEXT_MSG);
	getline(cin, temp);
	if(ifValidString(temp))
	{
		this->megapixels = stod(temp);
	}
	temp.clear();
}

void PhotoAndVideoCamera::output() const
{
	Electronic::output();
	cout << Message("Megapixels: " + to_string(megapixels), LOG_MSG);
}
