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
	User(string, string, Date, string, string, string, Access, int);
	User(const User&);
	~User();

	// for writing to file
	friend ostream& operator<<(ostream&, const User&);
	// for reading from file
	friend istream& operator>>(istream&, User&);
	void input(); // for console use
	void print(); // for console use
	void changePassword(string);
	void changeEmail(string);
	int getId() const;
	Access getRole() const;
	string getLogin() const;
	string getPassword() const;
	string getEmail() const;
	void setRole(Access);

private:
	string login;
	string password;
	string email;
	Properties* properties;
	Access role;
	int id;

	//createAdmin() must change the role of the user
	friend Result createAdmin();
};

#endif /* USER_H_ */
