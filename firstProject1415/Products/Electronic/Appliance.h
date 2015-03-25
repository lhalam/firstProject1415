# pragma once
#include "Electronic.h"

class Appliance : public Electronic
{
private:
	string type;
public:
	Appliance() : Electronic(), type(" ") {}

	friend istream& operator>>(istream& stream, Appliance& obj)
    {
        getline(stream, obj.category);
        stream >> obj.weight;
        stream.get();
        getline(stream, obj.model);
		getline(stream, obj.type);
        return stream;
    }

	friend ostream& operator<<(ostream& stream, Appliance& obj)
    {
		stream << obj.category << obj.weight << obj.model << obj.type;
        return stream;
    }

	~Appliance(){}
};