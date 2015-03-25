# pragma once
#include "Electronic.h"

class PhoneAndTablet : public Electronic
{
private:
	int memory_card;
public:
	PhoneAndTablet() : Electronic(), memory_card(0) {}

	friend istream& operator>>(istream& stream, PhoneAndTablet& obj)
    {
        getline(stream, obj.category);
        stream >> obj.weight;
        stream.get();
        getline(stream, obj.model);
		stream >> obj.memory_card;
        return stream;
    }

	friend ostream& operator<<(ostream& stream, const PhoneAndTablet& obj)
    {
		stream << obj.category << ' ' << obj.weight << ' '<< obj.model << ' ' << obj.memory_card << endl;
        return stream;
    }

	~PhoneAndTablet(){}
};