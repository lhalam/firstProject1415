#pragma once
#ifndef PROPERTIES_H_
#define PROPERTIES_H_

#include <iostream>
#include <string>

#include "../UI/Command.h"

using std::ostream;
using std::istream;
using std::string;

class Properties
{
public:
	Properties();
	Properties(Access, int);
	Properties(const Properties&);

	friend ostream& operator<<(ostream&, const Properties&);
	friend istream& operator>>(istream&, Properties&);
	Access getRole();
	void setRole(Access);
	int getId();
	void setId(int);

private:
	Access role;
	int id;
};

#endif /* PROPERTIES_H_ */
