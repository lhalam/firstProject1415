#include "stdafx.h"
#include "Properties.h"
#include "../UI/Message.h"


Properties::Properties() :
	role(GUEST),
	id(0)
{
}

Properties::Properties(Access mrole, int mid) :
	role(mrole),
	id(mid)
{
}

Properties::Properties(const Properties& properties) :
	role(properties.role),
	id(properties.id)
{
}

ostream& operator<<(ostream& stream, const Properties& properties)
{
	stream << properties.role << " "
		<< properties.id;
	return stream;
}

istream& operator>>(istream& stream, Properties& properties)
{
	using std::cout;
	int intRole = 0;
	stream >> intRole;
	properties.role = Access(intRole);
	stream >> properties.id;
	return stream;
}

Access Properties::getRole()
{
	return role;
}

void Properties::setRole(Access newRole)
{
	role = newRole;
}

int Properties::getId()
{
	return id;
}

void Properties::setId(int mid)
{
	id = mid;
}
