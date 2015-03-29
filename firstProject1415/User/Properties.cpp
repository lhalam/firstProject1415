#include "Properties.h"

ostream& operator<<(ostream& stream, const Properties& properties)
{
	stream << properties.role << " "
		<< properties.id;
	return stream;
}

istream& operator>>(istream& stream, Properties& properties)
{
	stream >> properties.role
		>> properties.id;
	return stream;
}

string Properties::getRole()
{
	return role;
}

void Properties::setRole(string newRole)
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