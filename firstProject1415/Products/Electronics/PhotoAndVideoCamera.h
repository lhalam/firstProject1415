# pragma once
#include "Electronics.h"

class PhotoAndVideoCamera : public Electronics
{
private:
	double megapixels;
public:
	DLL PhotoAndVideoCamera();

	friend DLL istream& operator>>(istream& stream, PhotoAndVideoCamera& obj);
	friend DLL ostream& operator<<(ostream& stream, const PhotoAndVideoCamera& obj);

	double getMegapixels() { return megapixels; }

	void setMegapixels(double megapixels) { this->megapixels = megapixels; }

	virtual DLL void input();
	virtual DLL void output() const;

	virtual DLL List<pair<string, string>> metadata();

	virtual DLL void fill(string);

	DLL ~PhotoAndVideoCamera() { }
};

