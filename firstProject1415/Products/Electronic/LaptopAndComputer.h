# pragma once
#include "Electronic.h"

class LaptopAndComputer : public Electronic
{
private:
	string firm;
public:
	LaptopAndComputer() : Electronic(), firm(" ") {}

	friend istream& operator>>(istream& stream, LaptopAndComputer& obj)
    {
        getline(stream, obj.category);
        stream >> obj.weight;
        stream.get();
        getline(stream, obj.model);
		getline(stream, obj.firm);
        return stream;
    }

	friend ostream& operator<<(ostream& stream, const LaptopAndComputer& obj)
    {
		stream << obj.category << ' ' << obj.weight << ' '<< obj.model << ' ' << obj.firm << endl;
        return stream;
    }

	~LaptopAndComputer(){}
};