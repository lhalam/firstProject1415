#include "Properties.h"

Properties::Properties() :
	role("norole"),
	id(0)
{
}

Properties::Properties(string mrole, int mid) :
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
	cout << "role : ";
	stream >> properties.role;
	cout << "id : ";
	stream >> properties.id;
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
