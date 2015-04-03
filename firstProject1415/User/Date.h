#pragma once
#ifndef DATE_H_
#define DATE_H_

#include <iostream>

using std::ostream;
using std::istream;

class Date
{
public:
	Date();
	Date(int, int, int);
	Date(const Date&);

	friend ostream& operator<<(ostream&, const Date&);
	friend istream& operator>>(istream&, Date&);

private:
	int day;
	int month;
	int year;
};

#endif /* DATE_H_ */
