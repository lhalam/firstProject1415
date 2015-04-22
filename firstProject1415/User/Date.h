#pragma once
#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <string>

using std::ostream;
using std::istream;
using std::string;

class Date
{
public:
	Date();
	Date(int, int, int);
	Date(const Date&);

	friend ostream& operator<<(ostream&, const Date&);
	friend istream& operator>>(istream&, Date&);

	string toString();

private:
	int day;
	int month;
	int year;
};

#endif /* DATE_H_ */
