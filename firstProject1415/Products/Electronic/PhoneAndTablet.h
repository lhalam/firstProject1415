# pragma once
#include "Electronic.h"

class PhoneAndTablet : public Electronic
{
private:
	int memoryCard;
public:
	PhoneAndTablet();

	friend istream& operator>>(istream& stream, PhoneAndTablet& obj);
	friend ostream& operator<<(ostream& stream, const PhoneAndTablet& obj);

	int getMemoryCard() { return memoryCard; }

	void setMemoryCard(int memoryCard) { this->memoryCard = memoryCard; }

	virtual void input();
	virtual void output() const;

	~PhoneAndTablet(){}
};

