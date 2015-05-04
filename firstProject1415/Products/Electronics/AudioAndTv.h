# pragma once
#include "Electronics.h"

class AudioAndTv : public Electronics
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
		List<pair<string, string>> result = Electronics::metadata();
		result.pushBack(make_pair("screenSize", to_string(screenSize)));
		return result;
	}

	virtual  List<pair<string, string>> metadata();

	virtual void fill(string);

	~AudioAndTv(){}
};
