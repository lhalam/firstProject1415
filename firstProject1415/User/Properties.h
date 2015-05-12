#pragma once
#ifndef PROPERTIES_H_
#define PROPERTIES_H_

#include <iostream>
#include <string>
#include <exception>

#include "../UI/Command.h"

using std::ostream;
using std::istream;
using std::string;

class Properties
{
public:
	DLL Properties();
	DLL Properties(Access, int);
	DLL Properties(const Properties&);

	friend DLL ostream& operator<<(ostream&, const Properties&);
	friend DLL istream& operator>>(istream&, Properties&);
	DLL Access getRole();
	DLL void setRole(Access);
	DLL int getId();
	DLL void setId(int);

private:
	Access role;
	int id;
};

#endif /* PROPERTIES_H_ */
