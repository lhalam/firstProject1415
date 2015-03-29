#pragma once

#include <iostream>
#include <string>

using std::ostream;
using std::istream;
using std::string;

class Properties
{
public:
	Properties() :
		role("norole"),
		id(0)
	{
	}
	Properties(string mrole, int mid) :
		role(mrole),
		id(mid)
	{
	}
	Properties(const Properties& properties) :
		role(properties.role),
		id(properties.id)
	{
	}
	friend ostream& operator<<(ostream&, const Properties&);
	friend istream& operator>>(istream&, Properties&);
	string getRole();
	void setRole(string);
	int getId();
	void setId(int);

private:
	string role;
	int id;
};