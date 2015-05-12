# pragma once
#include "Electronics.h"

class Appliance : public Electronics
{
private:
        double height;
public:
	DLL Appliance();

	friend DLL istream& operator>>(istream& stream, Appliance& obj);
	friend DLL ostream& operator<<(ostream& stream, const Appliance& obj);

	virtual DLL void input();
	virtual DLL void output() const;

	virtual DLL List<pair<string, string>> metadata();

	virtual DLL void fill(string);

	DLL ~Appliance(){}
};
