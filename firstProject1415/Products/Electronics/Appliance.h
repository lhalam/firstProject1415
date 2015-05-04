# pragma once
#include "Electronics.h"

class Appliance : public Electronics
{
private:
        double height;
public:
	Appliance();

	friend istream& operator>>(istream& stream, Appliance& obj);
	friend ostream& operator<<(ostream& stream, const Appliance& obj);

	virtual void input();
	virtual void output() const;
	virtual  List<pair<string, string>> metadata()
	{
		List<pair<string, string>> result = Electronics::metadata();
		result.pushBack(make_pair("height", to_string(height)));
		return result;
	}

	virtual  List<pair<string, string>> metadata();

	virtual void fill(string);

	~Appliance(){}
};
