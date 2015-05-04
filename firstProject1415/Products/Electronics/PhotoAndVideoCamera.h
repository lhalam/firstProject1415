# pragma once
#include "Electronics.h"

class PhotoAndVideoCamera : public Electronics
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

	virtual  List<pair<string, string>> metadata();

	virtual void fill(string);

	~PhotoAndVideoCamera(){}
};

