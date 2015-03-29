# pragma once
#include "Electronic.h"

class PhotoAndVideoCamera : public Electronic
{
private:
	double megapixels;
public:
	PhotoAndVideoCamera() : Electronic(), megapixels(0.0) {}

	friend istream& operator>>(istream& stream, PhotoAndVideoCamera& obj)
    {
        getline(stream, obj.category);
        stream >> obj.weight;
        stream.get();
        getline(stream, obj.model);
		stream >> obj.megapixels;
        stream.get();
        return stream;
    }

	friend ostream& operator<<(ostream& stream, const PhotoAndVideoCamera& obj)
    {
		stream << obj.category << ' ' << obj.weight << ' '<< obj.model << ' ' << obj.megapixels << endl;
        return stream;
    }

	~PhotoAndVideoCamera(){}
};