# pragma once
#include "Electronics.h"

class PhoneAndTablet : public Electronics
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

	virtual  List<pair<string, string>> metadata()
	{
		List<pair<string, string>> result = Electronics::metadata();
		result.pushBack(make_pair("memorycard", to_string(memoryCard)));
		return result;
	}

	~PhoneAndTablet(){}
};

