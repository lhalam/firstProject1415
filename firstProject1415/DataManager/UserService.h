#pragma once
#include "../User/User.h"
#include "../List/List.h"
#include <functional>
#include <exception>
#include <fstream>
#include <cstdio>

using std::function;

//Represents a service for reading and writing user info from/into a file
class UserService
{
public:
	//Saves user info into a file
	void save(const User& user);

	//Calls read(always true)
	List<User*> readAll();

	//Returns a list of users that match a predicate
	List<User*> read(function<bool(const User&)> predicate);

	//Returns a user with a given login and password
	//Returns nulltpr if there is no such user
	User *getByLogin(string login, string password);

	//Removes the user with a given id
	void removeById(int id);
};
