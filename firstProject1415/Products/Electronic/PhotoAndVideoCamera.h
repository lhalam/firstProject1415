# pragma once
#include "Electronic.h"

class PhotoAndVideoCamera : public Electronic
{
private:
	double megapixels;
public:
	PhotoAndVideoCamera();

	friend istream& operator>>(istream& stream, PhotoAndVideoCamera& obj);
	friend ostream& operator<<(ostream& stream, const PhotoAndVideoCamera& obj);

	double getMegapixels() { return megapixels; }

	void setMegapixels(double megapixels) { this->megapixels = megapixels; }

	virtual void input();
	virtual void output() const;

	virtual  List<pair<string, string>> metadata()
	{
		List<pair<string, string>> result = Electronic::metadata();
		result.pushBack(make_pair("megapixels", to_string(megapixels)));
		return result;
	}

	~PhotoAndVideoCamera(){}
};

