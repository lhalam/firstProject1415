#pragma once

#include <iostream>
#include <string>

#include "Person.h"
#include "Properties.h"

using std::ostream;
using std::istream;
using std::string;

class User : public Person
{
public:
	User();
	User(string, string, Date, string, string, string, Properties*);
	User(const User&);
	~User();
	friend ostream& operator<<(ostream&, const User&);
	friend istream& operator>>(istream&, User&);
	void changePassword(string);
	void changeEmail(string);
	void changeRole(string);

private:
	string login;
	string password;
	string email;
	Properties* properties;
};