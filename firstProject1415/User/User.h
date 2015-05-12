#pragma once
#ifndef USER_H_
#define USER_H_

#include <iostream>
#include <string>

#include "Person.h"
#include "../UI/Command.h"

using std::ostream;
using std::istream;
using std::string;

class User : public Person
{
public:
	DLL User();
	DLL User(string, string, Date, string, string, string, Access, int);
	DLL User(const User&);
	DLL ~User();

	// for writing to file
	friend DLL ostream& operator<<(ostream&, const User&);
	// for reading from file
	friend DLL istream& operator>>(istream&, User&);
	void DLL input(); // for console use
	void DLL print(); // for console use
	void DLL changePassword(string);
	void DLL changeEmail(string);
	int DLL getId() const;
	Access DLL getRole() const;
	string DLL getLogin() const;
	string DLL getPassword() const;
	string DLL getEmail() const;
	void DLL setRole(Access);

private:
	string login;
	string password;
	string email;
	Access role;
	int id;
};

#endif /* USER_H_ */
