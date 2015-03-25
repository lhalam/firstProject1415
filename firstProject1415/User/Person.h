#pragma once

#include <string>

#include "Date.h"

using std::string;

class Person
{
public:
	Person(const Person& person) :
		name(person.name),
		surname(person.surname),
		birthday(person.birthday)
	{
	}
	virtual ~Person() { }

	// Protected field need to access to 'name', 'surname', 'birthday' 
	//in class Properties in functions'(setInfo, getInfo) realization
protected:
	Person() :
		name("noName"),
		surname("noSurname"),
		birthday()
	{
	}
	Person(string mname, string msurname, Date mbirthday) :
		name(mname),
		surname(msurname),
		birthday(mbirthday)
	{
	}
	string name;
	string surname;
	Date birthday;
};