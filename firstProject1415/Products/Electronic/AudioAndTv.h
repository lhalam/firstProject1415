# pragma once
#include "Electronic.h"

class AudioAndTv : public Electronic
{
private:
	int memory_card;
public:
	AudioAndTv();

	friend istream& operator>>(istream& stream, AudioAndTv& obj) { }
	friend ostream& operator<<(ostream& stream, const AudioAndTv& obj) { }

	virtual void input();
	virtual void output() const;

	~AudioAndTv(){}
};
