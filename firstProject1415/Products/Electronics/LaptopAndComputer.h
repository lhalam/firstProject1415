# pragma once
#include "Electronics.h"

class LaptopAndComputer : public Electronics
{
private:
	string firm;
public:
	DLL LaptopAndComputer();

	friend DLL istream& operator>>(istream& stream, LaptopAndComputer& obj);
	friend DLL ostream& operator<<(ostream& stream, const LaptopAndComputer& obj);

	string getFirm() { return firm; }

	void setFirm(string firm) { this->firm = firm; }

	virtual DLL void input();
	virtual DLL void output() const;

	virtual DLL List<pair<string, string>> metadata();

	virtual DLL void fill(string);
	
	DLL ~LaptopAndComputer() { }
};
