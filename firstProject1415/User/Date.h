#pragma once

#include <iostream>

using std::ostream;
using std::istream;

class Date
{
public:
	Date() : day(0), month(0), year(0) { }
	Date(int mday, int mmonth, int myear) : day(mday), month(mmonth), year(myear) { }
	Date(const Date& date) : day(date.day), month(date.month), year(date.year) { }
	friend ostream& operator<<(ostream&, const Date&);
	friend istream& operator>>(istream&, Date&);

private:
	int day;
	int month;
	int year;
};