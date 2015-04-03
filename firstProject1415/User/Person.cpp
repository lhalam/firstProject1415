#include "Person.h"

Person::Person(const Person& person) :
	name(person.name),
	surname(person.surname),
	birthday(person.birthday)
{
}

Person::~Person()
{
}

Person::Person() :
	name("noName"),
	surname("noSurname"),
	birthday()
{
}

Person::Person(string mname, string msurname, Date mbirthday) :
	name(mname),
	surname(msurname),
	birthday(mbirthday)
{
}
