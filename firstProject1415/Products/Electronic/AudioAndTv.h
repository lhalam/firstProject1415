# pragma once
#include "Electronic.h"

class AudioAndTv : public Electronic
{
private:
	double screen_size;
public:
	AudioAndTv() : Electronic(), screen_size(0.0) {}

	friend istream& operator>>(istream& stream, AudioAndTv& obj)
    {
        getline(stream, obj.category);
        stream >> obj.weight;
        stream.get();
        getline(stream, obj.model);
		stream >> obj.screen_size;
        return stream;
    }

	friend ostream& operator<<(ostream& stream, const AudioAndTv& obj)
    {
		stream << obj.category << ' ' << obj.weight << ' '<< obj.model << ' ' << obj.screen_size << endl;
        return stream;
    }

	~AudioAndTv(){}
};