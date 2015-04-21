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
	return read([](const User& user) { return true; });
}

List<User*> UserService::read(function<bool(const User&)> predicate)
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

User * UserService::getByLogin(string login, string password)
{
	ifstream stream("Users.txt");

	if (!stream.is_open())
	{
		throw exception("Cannot open file for reading.");
	}

	User *user = nullptr;
	bool isSuccessful = false;

	while (!stream.eof())
	{
		user = new User();
		stream >> *user;

		if (user->getLogin() == login && user->getPassword() == password)
		{
			isSuccessful = true;
			break;
		}
	}

	if (!isSuccessful)
	{
		user = nullptr;
	}

	stream.close();
	return user;
}

User* UserService::getById(int id)
{
	ifstream stream("Users.txt");
	if (!stream.is_open())
	{
		throw exception("Cannot open file for reading.");
	}

	User *user = nullptr;

	bool isSuccessful = false;
	while (!stream.eof())
	{
		user = new User();
		stream >> *user;

		if (user->getId() == id)
		{
			isSuccessful = true;
			break;
		}
	}

	if (!isSuccessful)
	{
		user = nullptr;
	}

	stream.close();
	return user;
}

void UserService::removeById(int id)
{
	removeByPredicate([id](const User& user) -> bool {	return id == user.getId(); });
}

void UserService::removeByPredicate(function<bool(const User&)> predicate)
{
	ifstream stream("Users.txt");
	if (!stream.is_open())
	{
		throw exception("Cannot open file for reading.");
	}

	ofstream temp("Temp.txt");

	if (!temp.is_open())
	{
		throw exception("Cannot open temporary file for writing.");
	}

	while (!stream.eof())
	{
		User *user = new User();
		stream >> *user;

		if (user->getId() != 0 && !predicate(*user))
		{
			temp << *user;
		}
	}

	temp.close();
	stream.close();

	remove("Users.txt");
	rename("Temp.txt", "Users.txt");
}
