# pragma once
#include "Electronics.h"

class PhoneAndTablet : public Electronics
{
private:
	int memoryCard;
public:
	DLL PhoneAndTablet();

	friend DLL istream& operator>>(istream& stream, PhoneAndTablet& obj);
	friend DLL ostream& operator<<(ostream& stream, const PhoneAndTablet& obj);

	int getMemoryCard() { return memoryCard; }

	void setMemoryCard(int memoryCard) { this->memoryCard = memoryCard; }

	virtual DLL void input();
	virtual DLL void output() const;

	virtual DLL List<pair<string, string>> metadata();

	virtual DLL void fill(string);

	DLL ~PhoneAndTablet() { }
};

