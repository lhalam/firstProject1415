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

	string getName() const { return name; }
	string getSurname() const { return surname; }
	Date getBirthday() const { return birthday; }

protected:
	DLL Person();
	DLL Person(string, string, Date);

	string name;
	string surname;
	Date birthday;
};

#endif /* PERSON_H_ */
