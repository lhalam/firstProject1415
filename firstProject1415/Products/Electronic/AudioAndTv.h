# pragma once
#include "Electronic.h"

class AudioAndTv : public Electronic
{
private:
	double screenSize;
public:
	AudioAndTv();

	friend istream& operator>>(istream& stream, AudioAndTv& obj);
	friend ostream& operator<<(ostream& stream, const AudioAndTv& obj);

	virtual void input();
	virtual void output() const;
	virtual  List<pair<string, string>> metadata()
	{
		List<pair<string, string>> result = Electronic::metadata();
		result.pushBack(make_pair("screenSize", to_string(screenSize)));
		return result;
	}

	~AudioAndTv(){}
};
