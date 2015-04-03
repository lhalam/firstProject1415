#pragma once
#ifndef PROPERTIES_H_
#define PROPERTIES_H_

#include <iostream>
#include <string>

using std::ostream;
using std::istream;
using std::string;

class Properties
{
public:
	Properties();
	Properties(string, int);
	Properties(const Properties&);
	
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

#endif /* PROPERTIES_H_ */
