#pragma once
#ifndef PERSON_H_
#define PERSON_H_

#include <string>

#include "Date.h"

using std::string;

class Person
{
public:
	Person(const Person&);
	virtual ~Person();

protected:
	DLL Person();
	DLL Person(string, string, Date);

	string name;
	string surname;
	Date birthday;
};

#endif /* PERSON_H_ */
