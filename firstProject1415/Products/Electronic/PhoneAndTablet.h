# pragma once
#include "Electronic.h"

class PhoneAndTablet : public Electronic
{
private:
	int memory_card;
public:
	PhoneAndTablet();

	friend istream& operator>>(istream& stream, PhoneAndTablet& obj);
	friend ostream& operator<<(ostream& stream, const PhoneAndTablet& obj);

	virtual void input();
	virtual void output() const;

	~PhoneAndTablet(){}
};
