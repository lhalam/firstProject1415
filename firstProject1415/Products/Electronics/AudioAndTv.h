# pragma once
#include "Electronics.h"

class AudioAndTv : public Electronics
{
private:
	double screenSize;
public:
	DLL AudioAndTv();

	friend DLL istream& operator>>(istream& stream, AudioAndTv& obj);
	friend DLL ostream& operator<<(ostream& stream, const AudioAndTv& obj);

	virtual DLL void input();
	virtual DLL void output() const;

	virtual DLL List<pair<string, string>> metadata();

	virtual DLL void fill(string);

	DLL ~AudioAndTv(){}
};
