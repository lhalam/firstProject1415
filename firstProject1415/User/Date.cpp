#include "Date.h"

Date::Date() :
	day(0),
	month(0),
	year(0)
{
}

Date::Date(int mday, int mmonth, int myear) :
	day(mday),
	month(mmonth),
	year(myear)
{
}

Date::Date(const Date& date) :
	day(date.day),
	month(date.month),
	year(date.year)
{
}

ostream& operator<<(ostream& stream, const Date& date)
{
	stream << date.day << " "
		<< date.month << " "
		<< date.year;
	return stream;
}

istream& operator>>(istream& stream, Date& date)
{
	stream >> date.day
		>> date.month
		>> date.year;
	return stream;
}
