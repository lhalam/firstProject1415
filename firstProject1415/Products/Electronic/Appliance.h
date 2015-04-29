# pragma once
#include "Electronic.h"

class Appliance : public Electronic
{
private:
	int memoryCard;
public:
	Appliance();

	friend istream& operator>>(istream& stream, Appliance& obj);
	friend ostream& operator<<(ostream& stream, const Appliance& obj);

	virtual void input();
	virtual void output() const;
	virtual  List<pair<string, string>> metadata()
	{
		List<pair<string, string>> result = Electronic::metadata();
		result.pushBack(make_pair("memorycard", to_string(memoryCard)));
		return result;
	}

	~Appliance(){}
};
