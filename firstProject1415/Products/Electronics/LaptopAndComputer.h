# pragma once
#include "Electronics.h"

class LaptopAndComputer : public Electronics
{
private:
	string firm;
public:
	LaptopAndComputer();

	friend istream& operator>>(istream& stream, LaptopAndComputer& obj);
	friend ostream& operator<<(ostream& stream, const LaptopAndComputer& obj);

	string getFirm () { return firm; }

	void setFirm (string firm) { this->firm = firm; }

	virtual void input();
	virtual void output() const;

	virtual  List<pair<string, string>> metadata()
	{
		List<pair<string, string>> result = Electronics::metadata();
		result.pushBack(make_pair("firm", firm));
		return result;
	}

	virtual  List<pair<string, string>> metadata();

	virtual void fill(string);
	
	~LaptopAndComputer(){}
};
