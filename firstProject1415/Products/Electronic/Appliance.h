# pragma once
#include "Electronic.h"

class Appliance : public Electronic
{
private:
	int memory_card;
public:
	Appliance();

	friend istream& operator>>(istream& stream, Appliance& obj);
	friend ostream& operator<<(ostream& stream, const Appliance& obj);

	virtual void input();
	virtual void output() const;

	~Appliance(){}
};
