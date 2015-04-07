#pragma once
#ifndef USER_H_
#define USER_H_

#include <iostream>
#include <string>

#include "Person.h"
#include "Properties.h"
#include "../UI/Command.h"

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
	int getId();
	Access getRole();
	string getLogin();
	string getPassword();
	string getEmail();

private:
	string login;
	string password;
	string email;
	Properties* properties;
};

#endif /* USER_H_ */
