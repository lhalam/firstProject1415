#include "UserService.h"
#include <fstream>
#include <exception>

using namespace std;

void UserService::save(const User& user)
{
	ofstream stream("Users.txt", ios_base::app);
	if (!stream.is_open())
	{
		throw exception("Cannot open file for writing.");
	}
	stream << user;
	stream.close();
}

List<User*> UserService::readAll()
{
	return read(alwaysTrue);
}

List<User*> UserService::read(bool (*predicate)(const User& user))
{
	ifstream stream("Users.txt");
	if (!stream.is_open())
	{
		throw exception("Cannot open file for reading.");
	}

	List<User*> list;

	while (!stream.eof())
	{
		User *user = new User();
		stream >> *user;
		if (predicate(*user))
		{
			list.pushBack(user);
		}
	}

	stream.close();

	return list;
}
