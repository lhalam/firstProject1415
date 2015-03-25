#include "Date.h"

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