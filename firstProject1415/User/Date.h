#pragma once
#ifndef DATE_H_
#define DATE_H_

#ifndef DLL_IMPORT
#define DLL __declspec(dllexport)
#else
#define DLL __declspec(dllimport)
#endif

#include <iostream>
#include <string>

using std::ostream;
using std::istream;
using std::string;

class Date
{
public:
	DLL Date();
	DLL Date(int, int, int);
	DLL Date(const Date&);

	friend DLL ostream& operator<<(ostream&, const Date&);
	friend DLL istream& operator>>(istream&, Date&);

	DLL string toString();

private:
	int day;
	int month;
	int year;
};

#endif /* DATE_H_ */
