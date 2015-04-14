# pragma once
#include "Electronic.h"

class AudioAndTv : public Electronic
{
private:
	int memoryCard;
public:
	AudioAndTv();

	friend istream& operator>>(istream& stream, AudioAndTv& obj);
	friend ostream& operator<<(ostream& stream, const AudioAndTv& obj);

	virtual void input();
	virtual void output() const;

	~AudioAndTv(){}
};
